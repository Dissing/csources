// Prelude
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef float f32;
typedef double f64;
#define null 0ul
typedef struct ParsingContext ParsingContext;
#line 1 "src/parser.z"
typedef struct ParsingContext {
  u64 current_token;
  Token *tokens;
  u64 num_tokens;
  SourceMap *source_map;
  Session *sess;
  CompilationUnit *unit;
  u32 next_owner;
  u32 current_owner;
} ParsingContext;

#line 12 "src/parser.z"
bool is_done_parsing(ParsingContext *ctx) {
#line 13 "src/parser.z"
  return (ctx->num_tokens == ctx->current_token);
}

#line 16 "src/parser.z"
bool accept(ParsingContext *ctx, TokenKind token) {
#line 17 "src/parser.z"
#line 17 "src/parser.z"
  Token tok = ctx->tokens[ctx->current_token];

#line 18 "src/parser.z"
  if ((!is_done_parsing(ctx) && (tok.kind == token))) {
#line 19 "src/parser.z"
    ctx->current_token = (ctx->current_token + 1);
#line 20 "src/parser.z"
    return true;
  };
#line 22 "src/parser.z"
  return false;
}

#line 25 "src/parser.z"
bool can_accept(ParsingContext *ctx, TokenKind token) {
#line 26 "src/parser.z"
#line 26 "src/parser.z"
  Token tok = ctx->tokens[ctx->current_token];

#line 27 "src/parser.z"
  if ((!is_done_parsing(ctx) && (tok.kind == token))) {
#line 28 "src/parser.z"
    return true;
  };
#line 30 "src/parser.z"
  return false;
}

#line 33 "src/parser.z"
Token look_ahead(ParsingContext *ctx, u64 offset) {
#line 34 "src/parser.z"
  if ((ctx->current_token == ctx->num_tokens)) {
#line 35 "src/parser.z"
#line 35 "src/parser.z"
    Token eof_tok;

#line 36 "src/parser.z"
    eof_tok.kind = EOF;
#line 37 "src/parser.z"
    return eof_tok;
  } else {
#line 38 "src/parser.z"
    return ctx->tokens[(ctx->current_token + offset)];
  };
}

#line 41 "src/parser.z"
Token consume(ParsingContext *ctx) {
#line 42 "src/parser.z"
  ctx->current_token = (ctx->current_token + 1);
#line 43 "src/parser.z"
  return ctx->tokens[(ctx->current_token - 1)];
}

#line 46 "src/parser.z"
Token expect(ParsingContext *ctx, TokenKind kind) {
#line 47 "src/parser.z"
#line 47 "src/parser.z"
  Token tok = consume(ctx);

#line 48 "src/parser.z"
  if ((tok.kind == kind)) {
#line 49 "src/parser.z"
    return tok;
  } else {
#line 51 "src/parser.z"
    emit_error(ctx->source_map, tok.span, "Expect failed!");
#line 52 "src/parser.z"
    abort();
  };
}

#line 56 "src/parser.z"
u32 span_start(ParsingContext *ctx) {
#line 57 "src/parser.z"
  return ctx->tokens[ctx->current_token].span.from;
}

#line 60 "src/parser.z"
u32 span_end(ParsingContext *ctx) {
#line 61 "src/parser.z"
  return ctx->tokens[(ctx->current_token - 1)].span.to;
}

#line 64 "src/parser.z"
Ident parse_identifier(ParsingContext *ctx) {
#line 66 "src/parser.z"
#line 66 "src/parser.z"
  Token tok = consume(ctx);

#line 68 "src/parser.z"
  if ((tok.kind != TokenKind_Identifier)) {
#line 68 "src/parser.z"
    emit_error(ctx->source_map, tok.span, "Invalid identifier");
  };
#line 70 "src/parser.z"
#line 70 "src/parser.z"
  Ident ident;

#line 71 "src/parser.z"
  ident.name = tok.lexeme;
#line 72 "src/parser.z"
  return ident;
}

#line 75 "src/parser.z"
Path parse_path(ParsingContext *ctx) {
#line 76 "src/parser.z"
#line 76 "src/parser.z"
  Path path;

#line 77 "src/parser.z"
  path.segments = malloc((8 * 4));
#line 78 "src/parser.z"
  path.num_segments = 0;
#line 80 "src/parser.z"
  while (true) {
#line 81 "src/parser.z"
    path.segments[path.num_segments] = parse_identifier(ctx);
#line 82 "src/parser.z"
    path.num_segments = (path.num_segments + 1);
#line 83 "src/parser.z"
    if (!accept(ctx, TokenKind_ColonColon)) {
#line 83 "src/parser.z"
      break;
    };
  };
#line 85 "src/parser.z"
  return path;
}

#line 88 "src/parser.z"
Expr *parse_path_expr(ParsingContext *ctx) {
#line 89 "src/parser.z"
#line 89 "src/parser.z"
  Expr *expr = malloc(sizeof(Expr));

#line 90 "src/parser.z"
  expr->kind = ExprKind_Path;
#line 91 "src/parser.z"
  expr->node.path = parse_path(ctx);
#line 92 "src/parser.z"
  return expr;
}

#line 95 "src/parser.z"
Type *parse_type(ParsingContext *ctx) {
#line 96 "src/parser.z"
#line 96 "src/parser.z"
  TypeKindNode node;

#line 97 "src/parser.z"
#line 97 "src/parser.z"
  TypeKind kind;

#line 99 "src/parser.z"
#line 99 "src/parser.z"
  Token token = consume(ctx);

#line 100 "src/parser.z"
  if ((token.kind == TokenKind_Identifier)) {
#line 101 "src/parser.z"
    kind = TypeKind_Path;
#line 102 "src/parser.z"
    node.path = token.lexeme;
  } else {
#line 103 "src/parser.z"
    if ((token.kind == TokenKind_Star)) {
#line 104 "src/parser.z"
      kind = TypeKind_Ptr;
#line 105 "src/parser.z"
      node.ptr = parse_type(ctx);
    } else {
#line 107 "src/parser.z"
      emit_error(ctx->source_map, token.span, "Expected type");
    };
  };
#line 109 "src/parser.z"
#line 109 "src/parser.z"
  Type *type = malloc(sizeof(Type));

#line 110 "src/parser.z"
  type->kind = kind;
#line 111 "src/parser.z"
  type->node = node;
#line 113 "src/parser.z"
  return type;
}

#line 116 "src/parser.z"
BinaryOperatorKind convert_token_to_binary_operator(TokenKind tok) {
#line 117 "src/parser.z"
  if ((tok == TokenKind_Plus)) {
#line 117 "src/parser.z"
    return BinaryOperatorKind_Addition;
  } else {
#line 118 "src/parser.z"
    if ((tok == TokenKind_Minus)) {
#line 118 "src/parser.z"
      return BinaryOperatorKind_Subtraction;
    } else {
#line 119 "src/parser.z"
      if ((tok == TokenKind_Star)) {
#line 119 "src/parser.z"
        return BinaryOperatorKind_Product;
      } else {
#line 120 "src/parser.z"
        if ((tok == TokenKind_Slash)) {
#line 120 "src/parser.z"
          return BinaryOperatorKind_Division;
        } else {
#line 121 "src/parser.z"
          if ((tok == TokenKind_Percent)) {
#line 121 "src/parser.z"
            return BinaryOperatorKind_Modulus;
          } else {
#line 122 "src/parser.z"
            if ((tok == TokenKind_Less)) {
#line 122 "src/parser.z"
              return BinaryOperatorKind_Less;
            } else {
#line 123 "src/parser.z"
              if ((tok == TokenKind_LessEqual)) {
#line 123 "src/parser.z"
                return BinaryOperatorKind_LessEq;
              } else {
#line 124 "src/parser.z"
                if ((tok == TokenKind_Greater)) {
#line 124 "src/parser.z"
                  return BinaryOperatorKind_Greater;
                } else {
#line 125 "src/parser.z"
                  if ((tok == TokenKind_GreaterEqual)) {
#line 125 "src/parser.z"
                    return BinaryOperatorKind_GreaterEq;
                  } else {
#line 126 "src/parser.z"
                    if ((tok == TokenKind_EqualEqual)) {
#line 126 "src/parser.z"
                      return BinaryOperatorKind_Equality;
                    } else {
#line 127 "src/parser.z"
                      if ((tok == TokenKind_BangEqual)) {
#line 127 "src/parser.z"
                        return BinaryOperatorKind_NotEq;
                      } else {
#line 128 "src/parser.z"
                        if ((tok == TokenKind_AndAnd)) {
#line 128 "src/parser.z"
                          return BinaryOperatorKind_And;
                        } else {
#line 129 "src/parser.z"
                          if ((tok == TokenKind_OrOr)) {
#line 129 "src/parser.z"
                            return BinaryOperatorKind_Or;
                          } else {
#line 130 "src/parser.z"
                            if ((tok == TokenKind_And)) {
#line 130 "src/parser.z"
                              return BinaryOperatorKind_BAnd;
                            } else {
#line 131 "src/parser.z"
                              if ((tok == TokenKind_Or)) {
#line 131 "src/parser.z"
                                return BinaryOperatorKind_BOr;
                              } else {
#line 132 "src/parser.z"
                                if ((tok == TokenKind_Hat)) {
#line 132 "src/parser.z"
                                  return BinaryOperatorKind_Xor;
                                } else {
#line 133 "src/parser.z"
                                  if ((tok == TokenKind_LessLess)) {
#line 133 "src/parser.z"
                                    return BinaryOperatorKind_LeftShift;
                                  } else {
#line 134 "src/parser.z"
                                    if ((tok == TokenKind_GreaterGreater)) {
#line 134 "src/parser.z"
                                      return BinaryOperatorKind_RightShift;
                                    } else {
#line 135 "src/parser.z"
                                      return BinaryOperatorKind_Invalid;
                                    };
                                  };
                                };
                              };
                            };
                          };
                        };
                      };
                    };
                  };
                };
              };
            };
          };
        };
      };
    };
  };
}

#line 138 "src/parser.z"
u32 get_binary_operator_precedence(BinaryOperatorKind op) {
#line 139 "src/parser.z"
  if ((op == BinaryOperatorKind_Product)) {
#line 139 "src/parser.z"
    return 10;
  } else {
#line 140 "src/parser.z"
    if ((op == BinaryOperatorKind_Division)) {
#line 140 "src/parser.z"
      return 10;
    } else {
#line 141 "src/parser.z"
      if ((op == BinaryOperatorKind_Modulus)) {
#line 141 "src/parser.z"
        return 10;
      } else {
#line 142 "src/parser.z"
        if ((op == BinaryOperatorKind_Addition)) {
#line 142 "src/parser.z"
          return 9;
        } else {
#line 143 "src/parser.z"
          if ((op == BinaryOperatorKind_Subtraction)) {
#line 143 "src/parser.z"
            return 9;
          } else {
#line 144 "src/parser.z"
            if ((op == BinaryOperatorKind_LeftShift)) {
#line 144 "src/parser.z"
              return 8;
            } else {
#line 145 "src/parser.z"
              if ((op == BinaryOperatorKind_RightShift)) {
#line 145 "src/parser.z"
                return 8;
              } else {
#line 146 "src/parser.z"
                if ((op == BinaryOperatorKind_BAnd)) {
#line 146 "src/parser.z"
                  return 7;
                } else {
#line 147 "src/parser.z"
                  if ((op == BinaryOperatorKind_Xor)) {
#line 147 "src/parser.z"
                    return 6;
                  } else {
#line 148 "src/parser.z"
                    if ((op == BinaryOperatorKind_BOr)) {
#line 148 "src/parser.z"
                      return 5;
                    } else {
#line 149 "src/parser.z"
                      if ((op == BinaryOperatorKind_Less)) {
#line 149 "src/parser.z"
                        return 4;
                      } else {
#line 150 "src/parser.z"
                        if ((op == BinaryOperatorKind_LessEq)) {
#line 150 "src/parser.z"
                          return 4;
                        } else {
#line 151 "src/parser.z"
                          if ((op == BinaryOperatorKind_Greater)) {
#line 151 "src/parser.z"
                            return 4;
                          } else {
#line 152 "src/parser.z"
                            if ((op == BinaryOperatorKind_GreaterEq)) {
#line 152 "src/parser.z"
                              return 4;
                            } else {
#line 153 "src/parser.z"
                              if ((op == BinaryOperatorKind_Equality)) {
#line 153 "src/parser.z"
                                return 4;
                              } else {
#line 154 "src/parser.z"
                                if ((op == BinaryOperatorKind_NotEq)) {
#line 154 "src/parser.z"
                                  return 4;
                                } else {
#line 155 "src/parser.z"
                                  if ((op == BinaryOperatorKind_And)) {
#line 155 "src/parser.z"
                                    return 3;
                                  } else {
#line 156 "src/parser.z"
                                    if ((op == BinaryOperatorKind_Or)) {
#line 156 "src/parser.z"
                                      return 2;
                                    } else {
#line 157 "src/parser.z"
                                      return 0;
                                    };
                                  };
                                };
                              };
                            };
                          };
                        };
                      };
                    };
                  };
                };
              };
            };
          };
        };
      };
    };
  };
}

#line 160 "src/parser.z"
u32 get_current_precedence(ParsingContext *ctx) {
#line 162 "src/parser.z"
  if ((ctx->num_tokens <= ctx->current_token)) {
#line 163 "src/parser.z"
    return 0;
  } else {
#line 165 "src/parser.z"
#line 165 "src/parser.z"
    Token tok = ctx->tokens[ctx->current_token];

#line 166 "src/parser.z"
#line 166 "src/parser.z"
    u32 op_precedence = get_binary_operator_precedence(
        convert_token_to_binary_operator(tok.kind));

#line 167 "src/parser.z"
    if ((op_precedence > 0)) {
#line 167 "src/parser.z"
      return op_precedence;
    } else {
#line 168 "src/parser.z"
      if ((tok.kind == TokenKind_Dot)) {
#line 168 "src/parser.z"
        return 13;
      } else {
#line 169 "src/parser.z"
        if (((tok.kind == TokenKind_LeftBracket) ||
             (tok.kind == TokenKind_LeftParen))) {
#line 169 "src/parser.z"
          return 12;
        } else {
#line 170 "src/parser.z"
          return 0;
        };
      };
    };
  };
}

#line 174 "src/parser.z"
Expr *parse_expression(ParsingContext *ctx, u32 precedence);

#line 176 "src/parser.z"
Expr *parse_integer_literal(ParsingContext *ctx) {
#line 178 "src/parser.z"
#line 178 "src/parser.z"
  Token tok = expect(ctx, TokenKind_Integer);

#line 180 "src/parser.z"
#line 180 "src/parser.z"
  Expr *expr = malloc(sizeof(Expr));

#line 181 "src/parser.z"
  expr->kind = ExprKind_Literal;
#line 182 "src/parser.z"
  expr->node.lit.kind = LiteralKind_Int;
#line 184 "src/parser.z"
#line 184 "src/parser.z"
  Session *sess = ctx->sess;

#line 185 "src/parser.z"
  expr->node.lit.value.integer = atol(get_str(&sess->interner, tok.lexeme));
#line 186 "src/parser.z"
  return expr;
}

#line 189 "src/parser.z"
Expr *parse_float_literal(ParsingContext *ctx) {
#line 191 "src/parser.z"
#line 191 "src/parser.z"
  Token tok = expect(ctx, TokenKind_Float);

#line 193 "src/parser.z"
#line 193 "src/parser.z"
  Expr *expr = malloc(sizeof(Expr));

#line 194 "src/parser.z"
  expr->kind = ExprKind_Literal;
#line 195 "src/parser.z"
  expr->node.lit.kind = LiteralKind_Float;
#line 197 "src/parser.z"
#line 197 "src/parser.z"
  Session *sess = ctx->sess;

#line 198 "src/parser.z"
  expr->node.lit.value.floating = atof(get_str(&sess->interner, tok.lexeme));
#line 199 "src/parser.z"
  return expr;
}

#line 202 "src/parser.z"
Expr *parse_char_literal(ParsingContext *ctx) {
#line 204 "src/parser.z"
#line 204 "src/parser.z"
  Token tok = expect(ctx, TokenKind_Char);

#line 206 "src/parser.z"
#line 206 "src/parser.z"
  Expr *expr = malloc(sizeof(Expr));

#line 207 "src/parser.z"
  expr->kind = ExprKind_Literal;
#line 208 "src/parser.z"
  expr->node.lit.kind = LiteralKind_Char;
#line 210 "src/parser.z"
#line 210 "src/parser.z"
  Session *sess = ctx->sess;

#line 211 "src/parser.z"
#line 211 "src/parser.z"
  char *s = get_str(&sess->interner, tok.lexeme);

#line 213 "src/parser.z"
#line 213 "src/parser.z"
  u32 len = strlen(s);

#line 214 "src/parser.z"
  if (((len == 2) && (s[0] == '\\'))) {
#line 215 "src/parser.z"
#line 215 "src/parser.z"
    char c;

#line 216 "src/parser.z"
    if ((s[1] == 'n')) {
#line 216 "src/parser.z"
      c = '\n';
    } else {
#line 217 "src/parser.z"
      if ((s[1] == 't')) {
#line 217 "src/parser.z"
        c = '\t';
      } else {
#line 218 "src/parser.z"
        if ((s[1] == 'r')) {
#line 218 "src/parser.z"
          c = '\r';
        } else {
#line 219 "src/parser.z"
          if ((s[1] == '\\')) {
#line 219 "src/parser.z"
            c = '\\';
          } else {
#line 220 "src/parser.z"
            if ((s[1] == '\'')) {
#line 220 "src/parser.z"
              c = '\'';
            } else {
#line 221 "src/parser.z"
              emit_error(ctx->source_map, tok.span, "Unknown escape sequence");
            };
          };
        };
      };
    };
#line 222 "src/parser.z"
    expr->node.lit.value.ch = c;
  } else {
#line 223 "src/parser.z"
    if ((len == 1)) {
#line 224 "src/parser.z"
      expr->node.lit.value.ch = s[0];
    } else {
#line 226 "src/parser.z"
      emit_error(ctx->source_map, tok.span, "Invalid char literal");
    };
  };
#line 228 "src/parser.z"
  return expr;
}

#line 231 "src/parser.z"
Expr *parse_string_literal(ParsingContext *ctx) {
#line 233 "src/parser.z"
#line 233 "src/parser.z"
  Token tok = expect(ctx, TokenKind_String);

#line 235 "src/parser.z"
#line 235 "src/parser.z"
  Expr *expr = malloc(sizeof(Expr));

#line 236 "src/parser.z"
  expr->kind = ExprKind_Literal;
#line 237 "src/parser.z"
  expr->node.lit.kind = LiteralKind_Str;
#line 239 "src/parser.z"
  expr->node.lit.value.str = tok.lexeme;
#line 240 "src/parser.z"
  return expr;
}

#line 243 "src/parser.z"
Expr *parse_bool_literal(ParsingContext *ctx) {
#line 245 "src/parser.z"
#line 245 "src/parser.z"
  Token tok = consume(ctx);

#line 247 "src/parser.z"
#line 247 "src/parser.z"
  Expr *expr = malloc(sizeof(Expr));

#line 248 "src/parser.z"
  expr->kind = ExprKind_Literal;
#line 249 "src/parser.z"
  expr->node.lit.kind = LiteralKind_Bool;
#line 250 "src/parser.z"
  expr->node.lit.value.boolean = (tok.kind == TokenKind_True);
#line 251 "src/parser.z"
  return expr;
}

#line 254 "src/parser.z"
Expr *parse_call(ParsingContext *ctx, Expr *left) {
#line 256 "src/parser.z"
#line 256 "src/parser.z"
  Expr *result = malloc(sizeof(Expr));

#line 257 "src/parser.z"
  result->kind = ExprKind_Call;
#line 258 "src/parser.z"
  result->node.call.func = left;
#line 259 "src/parser.z"
  result->node.call.args = malloc((8 * 16));
#line 260 "src/parser.z"
  result->node.call.num_args = 0;
#line 262 "src/parser.z"
  if (!accept(ctx, TokenKind_RightParen)) {
#line 263 "src/parser.z"
    while (true) {
#line 264 "src/parser.z"
#line 264 "src/parser.z"
      Expr *expr = parse_expression(ctx, 0);

#line 265 "src/parser.z"
      result->node.call.args[result->node.call.num_args] = expr;
#line 266 "src/parser.z"
      result->node.call.num_args = (result->node.call.num_args + 1);
#line 267 "src/parser.z"
      if (!accept(ctx, TokenKind_Comma)) {
#line 267 "src/parser.z"
        break;
      };
    };
#line 269 "src/parser.z"
    expect(ctx, TokenKind_RightParen);
  };
#line 272 "src/parser.z"
  return result;
}

#line 276 "src/parser.z"
Expr *parse_prefix_operator(ParsingContext *ctx) {
#line 277 "src/parser.z"
#line 277 "src/parser.z"
  Expr *expr = malloc(sizeof(Expr));

#line 278 "src/parser.z"
  expr->kind = ExprKind_Unary;
#line 280 "src/parser.z"
#line 280 "src/parser.z"
  Token tok = consume(ctx);

#line 282 "src/parser.z"
  if ((tok.kind == TokenKind_Minus)) {
#line 282 "src/parser.z"
    expr->node.unary.op = UnaryOperatorKind_Negation;
  } else {
#line 283 "src/parser.z"
    if ((tok.kind == TokenKind_Bang)) {
#line 283 "src/parser.z"
      expr->node.unary.op = UnaryOperatorKind_Complement;
    } else {
#line 284 "src/parser.z"
      if ((tok.kind == TokenKind_And)) {
#line 284 "src/parser.z"
        expr->node.unary.op = UnaryOperatorKind_Refer;
      } else {
#line 285 "src/parser.z"
        if ((tok.kind == TokenKind_Star)) {
#line 285 "src/parser.z"
          expr->node.unary.op = UnaryOperatorKind_Deref;
        } else {
#line 286 "src/parser.z"
          emit_error(ctx->source_map, tok.span, "Invalid prefix operator");
        };
      };
    };
  };
#line 288 "src/parser.z"
  expr->node.unary.inner = parse_expression(ctx, 11);
#line 290 "src/parser.z"
  return expr;
}

#line 293 "src/parser.z"
Expr *parse_binary_operator(ParsingContext *ctx, Expr *left,
                            BinaryOperatorKind operator) {
#line 294 "src/parser.z"
#line 294 "src/parser.z"
  u32 precedence = get_binary_operator_precedence(operator);

#line 295 "src/parser.z"
#line 295 "src/parser.z"
  Expr *right = parse_expression(ctx, precedence);

#line 297 "src/parser.z"
#line 297 "src/parser.z"
  Expr *expr = malloc(sizeof(Expr));

#line 298 "src/parser.z"
  expr->kind = ExprKind_Binary;
#line 299 "src/parser.z"
  expr->node.binary.op = operator;
#line 300 "src/parser.z"
  expr->node.binary.left = left;
#line 301 "src/parser.z"
  expr->node.binary.right = right;
#line 303 "src/parser.z"
  return expr;
}

#line 306 "src/parser.z"
Expr *parse_field_access(ParsingContext *ctx, Expr *left) {
#line 307 "src/parser.z"
#line 307 "src/parser.z"
  Expr *expr = malloc(sizeof(Expr));

#line 308 "src/parser.z"
  expr->kind = ExprKind_Field;
#line 309 "src/parser.z"
  expr->node.field.ident = parse_identifier(ctx);
#line 310 "src/parser.z"
  expr->node.field.strct = left;
#line 312 "src/parser.z"
  return expr;
}

#line 315 "src/parser.z"
Expr *parse_indexing(ParsingContext *ctx, Expr *left) {
#line 317 "src/parser.z"
#line 317 "src/parser.z"
  Expr *expr = malloc(sizeof(Expr));

#line 318 "src/parser.z"
  expr->kind = ExprKind_Indexing;
#line 319 "src/parser.z"
  expr->node.indexing.index = parse_expression(ctx, 0);
#line 320 "src/parser.z"
  expr->node.indexing.array = left;
#line 322 "src/parser.z"
  expect(ctx, TokenKind_RightBracket);
#line 324 "src/parser.z"
  return expr;
}

#line 327 "src/parser.z"
Expr *parse_infix_operator(ParsingContext *ctx, Expr *left, Token tok) {
#line 329 "src/parser.z"
  if ((tok.kind == TokenKind_LeftParen)) {
#line 329 "src/parser.z"
    return parse_call(ctx, left);
  };
#line 330 "src/parser.z"
  if ((tok.kind == TokenKind_Dot)) {
#line 330 "src/parser.z"
    return parse_field_access(ctx, left);
  };
#line 331 "src/parser.z"
  if ((tok.kind == TokenKind_LeftBracket)) {
#line 331 "src/parser.z"
    return parse_indexing(ctx, left);
  };
#line 333 "src/parser.z"
#line 333 "src/parser.z"
  BinaryOperatorKind op = convert_token_to_binary_operator(tok.kind);

#line 334 "src/parser.z"
  if ((op != BinaryOperatorKind_Invalid)) {
#line 335 "src/parser.z"
    return parse_binary_operator(ctx, left, op);
  } else {
#line 337 "src/parser.z"
    emit_error(ctx->source_map, tok.span, "Unsupported infix operator");
  };
#line 338 "src/parser.z"
  return null;
}

#line 341 "src/parser.z"
Stmt *parse_stmt(ParsingContext *ctx);

#line 342 "src/parser.z"
Block *parse_block(ParsingContext *ctx) {
#line 344 "src/parser.z"
#line 344 "src/parser.z"
  Block *block = malloc(sizeof(Block));

#line 345 "src/parser.z"
  block->stmts = malloc((8 * 128));
#line 346 "src/parser.z"
  block->num_stmts = 0;
#line 347 "src/parser.z"
  block->span.from = span_start(ctx);
#line 349 "src/parser.z"
#line 349 "src/parser.z"
  Token next = look_ahead(ctx, 0);

#line 350 "src/parser.z"
  if ((next.kind == TokenKind_LeftCurly)) {
#line 351 "src/parser.z"
    expect(ctx, TokenKind_LeftCurly);
#line 352 "src/parser.z"
#line 352 "src/parser.z"
    u32 i = 0;

#line 353 "src/parser.z"
    while (!accept(ctx, TokenKind_RightCurly)) {
#line 354 "src/parser.z"
      block->stmts[i] = parse_stmt(ctx);
#line 355 "src/parser.z"
      block->num_stmts = (block->num_stmts + 1);
#line 356 "src/parser.z"
      i = (i + 1);
    };
  } else {
#line 359 "src/parser.z"
    block->stmts[0] = parse_stmt(ctx);
#line 360 "src/parser.z"
    block->num_stmts = 1;
  };
#line 362 "src/parser.z"
  block->span.to = span_end(ctx);
#line 364 "src/parser.z"
  return block;
}

#line 367 "src/parser.z"
Expr *parse_block_expr(ParsingContext *ctx) {
#line 368 "src/parser.z"
#line 368 "src/parser.z"
  Expr *expr = malloc(sizeof(Expr));

#line 369 "src/parser.z"
  expr->kind = ExprKind_Block;
#line 370 "src/parser.z"
  expr->node.block = parse_block(ctx);
#line 371 "src/parser.z"
  return expr;
}

#line 374 "src/parser.z"
Expr *parse_if(ParsingContext *ctx) {
#line 376 "src/parser.z"
  expect(ctx, TokenKind_If);
#line 378 "src/parser.z"
#line 378 "src/parser.z"
  Expr *expr = malloc(sizeof(Expr));

#line 379 "src/parser.z"
  expr->kind = ExprKind_Conditional;
#line 380 "src/parser.z"
  expr->node.conditional.condition = parse_expression(ctx, 0);
#line 381 "src/parser.z"
  expr->node.conditional.then = parse_block_expr(ctx);
#line 383 "src/parser.z"
  if (accept(ctx, TokenKind_Else)) {
#line 384 "src/parser.z"
    expr->node.conditional.otherwise = parse_block_expr(ctx);
  } else {
#line 386 "src/parser.z"
    expr->node.conditional.otherwise = null;
  };
#line 389 "src/parser.z"
  return expr;
}

#line 392 "src/parser.z"
Expr *parse_while(ParsingContext *ctx) {
#line 393 "src/parser.z"
  expect(ctx, TokenKind_While);
#line 395 "src/parser.z"
#line 395 "src/parser.z"
  Expr *expr = malloc(sizeof(Expr));

#line 396 "src/parser.z"
  expr->kind = ExprKind_While;
#line 397 "src/parser.z"
  expr->node.whl.condition = parse_expression(ctx, 0);
#line 398 "src/parser.z"
  expr->node.whl.body = parse_block_expr(ctx);
#line 400 "src/parser.z"
  return expr;
}

#line 403 "src/parser.z"
Expr *parse_expression(ParsingContext *ctx, u32 precedence) {
#line 404 "src/parser.z"
#line 404 "src/parser.z"
  Token tok = look_ahead(ctx, 0);

#line 405 "src/parser.z"
#line 405 "src/parser.z"
  Span span;

#line 406 "src/parser.z"
  span.from = span_start(ctx);
#line 408 "src/parser.z"
#line 408 "src/parser.z"
  Expr *left;

#line 410 "src/parser.z"
  if ((tok.kind == TokenKind_Identifier)) {
#line 410 "src/parser.z"
    left = parse_path_expr(ctx);
  } else {
#line 411 "src/parser.z"
    if ((tok.kind == TokenKind_Integer)) {
#line 411 "src/parser.z"
      left = parse_integer_literal(ctx);
    } else {
#line 412 "src/parser.z"
      if ((tok.kind == TokenKind_Char)) {
#line 412 "src/parser.z"
        left = parse_char_literal(ctx);
      } else {
#line 413 "src/parser.z"
        if ((tok.kind == TokenKind_String)) {
#line 413 "src/parser.z"
          left = parse_string_literal(ctx);
        } else {
#line 414 "src/parser.z"
          if ((tok.kind == TokenKind_Float)) {
#line 414 "src/parser.z"
            left = parse_float_literal(ctx);
          } else {
#line 415 "src/parser.z"
            if (((tok.kind == TokenKind_False) ||
                 (tok.kind == TokenKind_True))) {
#line 415 "src/parser.z"
              left = parse_bool_literal(ctx);
            } else {
#line 416 "src/parser.z"
              if (((((tok.kind == TokenKind_Minus) ||
                     (tok.kind == TokenKind_Bang)) ||
                    (tok.kind == TokenKind_And)) ||
                   (tok.kind == TokenKind_Star))) {
#line 417 "src/parser.z"
                left = parse_prefix_operator(ctx);
              } else {
#line 418 "src/parser.z"
                if ((tok.kind == TokenKind_If)) {
#line 418 "src/parser.z"
                  left = parse_if(ctx);
                } else {
#line 419 "src/parser.z"
                  if ((tok.kind == TokenKind_While)) {
#line 419 "src/parser.z"
                    left = parse_while(ctx);
                  } else {
#line 420 "src/parser.z"
                    if ((tok.kind == TokenKind_LeftParen)) {
#line 421 "src/parser.z"
                      expect(ctx, TokenKind_LeftParen);
#line 422 "src/parser.z"
                      left = parse_expression(ctx, 0);
#line 423 "src/parser.z"
                      expect(ctx, TokenKind_RightParen);
                    } else {
#line 425 "src/parser.z"
                      if ((tok.kind == TokenKind_LeftCurly)) {
#line 425 "src/parser.z"
                        left = parse_block_expr(ctx);
                      } else {
#line 426 "src/parser.z"
                        emit_error(ctx->source_map, tok.span,
                                   "Invalid expression prefix");
                      };
                    };
                  };
                };
              };
            };
          };
        };
      };
    };
  };
#line 428 "src/parser.z"
  while ((precedence < get_current_precedence(ctx))) {
#line 429 "src/parser.z"
#line 429 "src/parser.z"
    Token next_tok = consume(ctx);

#line 430 "src/parser.z"
    left = parse_infix_operator(ctx, left, next_tok);
  };
#line 432 "src/parser.z"
  span.to = span_end(ctx);
#line 433 "src/parser.z"
  left->span = span;
#line 435 "src/parser.z"
  return left;
}

#line 438 "src/parser.z"
NodeId parse_item(ParsingContext *ctx);

#line 440 "src/parser.z"
Stmt *parse_stmt(ParsingContext *ctx) {
#line 442 "src/parser.z"
#line 442 "src/parser.z"
  Stmt *stmt = malloc(sizeof(Stmt));

#line 443 "src/parser.z"
  stmt->span.from = span_start(ctx);
#line 445 "src/parser.z"
#line 445 "src/parser.z"
  Token tok = look_ahead(ctx, 0);

#line 446 "src/parser.z"
  if (accept(ctx, TokenKind_Break)) {
#line 447 "src/parser.z"
    stmt->kind = StmtKind_Break;
  } else {
#line 448 "src/parser.z"
    if (accept(ctx, TokenKind_Continue)) {
#line 449 "src/parser.z"
      stmt->kind = StmtKind_Continue;
    } else {
#line 450 "src/parser.z"
      if (accept(ctx, TokenKind_Return)) {
#line 451 "src/parser.z"
        stmt->kind = StmtKind_Return;
#line 452 "src/parser.z"
        stmt->node._return = parse_expression(ctx, 0);
      } else {
#line 453 "src/parser.z"
        if (accept(ctx, TokenKind_Defer)) {
#line 454 "src/parser.z"
          stmt->kind = StmtKind_Defer;
#line 455 "src/parser.z"
          stmt->node._defer = parse_expression(ctx, 0);
        } else {
#line 456 "src/parser.z"
          if (accept(ctx, TokenKind_Semicolon)) {
#line 457 "src/parser.z"
            stmt->kind = StmtKind_Empty;
          } else {
#line 458 "src/parser.z"
            if (((tok.kind == TokenKind_Var) || (tok.kind == TokenKind_Val))) {
#line 459 "src/parser.z"
              stmt->kind = StmtKind_Item;
#line 460 "src/parser.z"
              stmt->node.item = parse_item(ctx);
            } else {
#line 462 "src/parser.z"
#line 462 "src/parser.z"
              Expr *left = parse_expression(ctx, 0);

#line 463 "src/parser.z"
#line 463 "src/parser.z"
              Token next = look_ahead(ctx, 0);

#line 465 "src/parser.z"
              if ((next.kind == TokenKind_Equal)) {
#line 466 "src/parser.z"
                stmt->kind = StmtKind_Assignment;
#line 467 "src/parser.z"
                stmt->node.assignment.left = left;
#line 468 "src/parser.z"
                expect(ctx, TokenKind_Equal);
#line 469 "src/parser.z"
                stmt->node.assignment.right = parse_expression(ctx, 0);
              } else {
#line 471 "src/parser.z"
                stmt->kind = StmtKind_Expr;
#line 472 "src/parser.z"
                stmt->node.expr = left;
              };
            };
          };
        };
      };
    };
  };
#line 476 "src/parser.z"
  accept(ctx, TokenKind_Semicolon);
#line 477 "src/parser.z"
  stmt->span.to = span_end(ctx);
#line 479 "src/parser.z"
  return stmt;
}

#line 482 "src/parser.z"
Generics parse_generics(ParsingContext *ctx) {
#line 483 "src/parser.z"
  expect(ctx, TokenKind_Less);
#line 484 "src/parser.z"
#line 484 "src/parser.z"
  Generics generics;

#line 485 "src/parser.z"
  generics.parameters = malloc((4 * sizeof(GenericParam)));
#line 486 "src/parser.z"
  generics.num_parameters = 0;
#line 488 "src/parser.z"
  while (!accept(ctx, TokenKind_Greater)) {
#line 489 "src/parser.z"
    generics.parameters[generics.num_parameters].ident = parse_identifier(ctx);
#line 491 "src/parser.z"
    accept(ctx, TokenKind_Comma);
#line 492 "src/parser.z"
    generics.num_parameters = (generics.num_parameters + 1);
  };
#line 494 "src/parser.z"
  return generics;
}

#line 497 "src/parser.z"
NodeId parse_body(ParsingContext *ctx, NodeId owner) {
#line 498 "src/parser.z"
#line 498 "src/parser.z"
  NodeId id;

#line 499 "src/parser.z"
#line 499 "src/parser.z"
  Body *body = unit_create_body(ctx->unit, owner, &id);

#line 501 "src/parser.z"
  body->value = parse_expression(ctx, 0);
#line 503 "src/parser.z"
  return id;
}

#line 506 "src/parser.z"
void parse_variable_decl(ParsingContext *ctx, Item *item) {
#line 508 "src/parser.z"
#line 508 "src/parser.z"
  Token keyword = consume(ctx);

#line 509 "src/parser.z"
  if ((keyword.kind == TokenKind_Val)) {
#line 509 "src/parser.z"
    item->kind = ItemKind_Const;
  } else {
#line 510 "src/parser.z"
    if ((keyword.kind == TokenKind_Var)) {
#line 510 "src/parser.z"
      item->kind = ItemKind_Variable;
    } else {
#line 511 "src/parser.z"
      abort();
    };
  };
#line 513 "src/parser.z"
  item->ident = parse_identifier(ctx);
#line 514 "src/parser.z"
  expect(ctx, TokenKind_Colon);
#line 515 "src/parser.z"
  item->node.variable.ty = parse_type(ctx);
#line 517 "src/parser.z"
  if (accept(ctx, TokenKind_Equal)) {
#line 517 "src/parser.z"
    item->node.variable.body = parse_body(ctx, item->id);
  } else {
#line 518 "src/parser.z"
    item->node.variable.body.owner = null;
  };
}

#line 521 "src/parser.z"
void parse_compound_decl(ParsingContext *ctx, Item *item) {
#line 523 "src/parser.z"
  if (accept(ctx, TokenKind_Struct)) {
#line 523 "src/parser.z"
    item->kind = ItemKind_Struct;
  } else {
#line 524 "src/parser.z"
    if (accept(ctx, TokenKind_Union)) {
#line 524 "src/parser.z"
      item->kind = ItemKind_Union;
    } else {
#line 525 "src/parser.z"
      abort();
    };
  };
#line 527 "src/parser.z"
  item->ident = parse_identifier(ctx);
#line 529 "src/parser.z"
  if (can_accept(ctx, TokenKind_Less)) {
#line 529 "src/parser.z"
    item->node.compound.generics = parse_generics(ctx);
  } else {
#line 530 "src/parser.z"
    item->node.compound.generics.num_parameters = 0;
  };
#line 532 "src/parser.z"
  expect(ctx, TokenKind_LeftCurly);
#line 534 "src/parser.z"
  item->node.compound.fields = malloc((sizeof(CompoundField) * 16));
#line 535 "src/parser.z"
  item->node.compound.num_fields = 0;
#line 537 "src/parser.z"
  while (!accept(ctx, TokenKind_RightCurly)) {
#line 538 "src/parser.z"
#line 538 "src/parser.z"
    Token token = consume(ctx);

#line 539 "src/parser.z"
    if ((token.kind != TokenKind_Identifier)) {
#line 539 "src/parser.z"
      emit_error(ctx->source_map, token.span, "Expected field identifier");
    };
#line 541 "src/parser.z"
    item->node.compound.fields[item->node.compound.num_fields].ident.name =
        token.lexeme;
#line 542 "src/parser.z"
    expect(ctx, TokenKind_Colon);
#line 544 "src/parser.z"
#line 544 "src/parser.z"
    Type *type = parse_type(ctx);

#line 545 "src/parser.z"
    item->node.compound.fields[item->node.compound.num_fields].ty = type;
#line 546 "src/parser.z"
    item->node.compound.num_fields = (item->node.compound.num_fields + 1);
#line 547 "src/parser.z"
    expect(ctx, TokenKind_Comma);
  };
}

#line 552 "src/parser.z"
void parse_enum_decl(ParsingContext *ctx, Item *item) {
#line 554 "src/parser.z"
  expect(ctx, TokenKind_Enum);
#line 555 "src/parser.z"
  item->kind = ItemKind_Enum;
#line 557 "src/parser.z"
  item->ident = parse_identifier(ctx);
#line 559 "src/parser.z"
  expect(ctx, TokenKind_LeftCurly);
#line 561 "src/parser.z"
  item->node._enum.variants = malloc((sizeof(EnumVariant) * 128));
#line 562 "src/parser.z"
  item->node._enum.num_variants = 0;
#line 564 "src/parser.z"
  while (!accept(ctx, TokenKind_RightCurly)) {
#line 565 "src/parser.z"
    item->node._enum.variants[item->node._enum.num_variants].ident =
        parse_identifier(ctx);
#line 566 "src/parser.z"
    item->node._enum.num_variants = (item->node._enum.num_variants + 1);
#line 567 "src/parser.z"
    expect(ctx, TokenKind_Comma);
  };
}

#line 571 "src/parser.z"
FunctionHeader parse_function_header(ParsingContext *ctx) {
#line 572 "src/parser.z"
#line 572 "src/parser.z"
  FunctionHeader header;

#line 574 "src/parser.z"
  header.parameters = malloc((sizeof(FunctionParameter) * 16));
#line 575 "src/parser.z"
  header.num_parameters = 0;
#line 577 "src/parser.z"
  if (can_accept(ctx, TokenKind_Less)) {
#line 577 "src/parser.z"
    header.generics = parse_generics(ctx);
  } else {
#line 578 "src/parser.z"
    header.generics.num_parameters = 0;
  };
#line 580 "src/parser.z"
  expect(ctx, TokenKind_LeftParen);
#line 582 "src/parser.z"
  while (!accept(ctx, TokenKind_RightParen)) {
#line 584 "src/parser.z"
    header.parameters[header.num_parameters].ident = parse_identifier(ctx);
#line 586 "src/parser.z"
    expect(ctx, TokenKind_Colon);
#line 587 "src/parser.z"
#line 587 "src/parser.z"
    Type *type = parse_type(ctx);

#line 588 "src/parser.z"
    header.parameters[header.num_parameters].ty = type;
#line 589 "src/parser.z"
    header.num_parameters = (header.num_parameters + 1);
#line 591 "src/parser.z"
    accept(ctx, TokenKind_Comma);
  };
#line 594 "src/parser.z"
  if (accept(ctx, TokenKind_Arrow)) {
#line 594 "src/parser.z"
    header.output = parse_type(ctx);
  } else {
#line 597 "src/parser.z"
#line 597 "src/parser.z"
    Type *output = malloc(sizeof(Type));

#line 598 "src/parser.z"
    output->kind = TypeKind_Unit;
#line 599 "src/parser.z"
    header.output = output;
  };
#line 602 "src/parser.z"
  return header;
}

#line 605 "src/parser.z"
void parse_function_decl(ParsingContext *ctx, Item *item) {
#line 606 "src/parser.z"
  expect(ctx, TokenKind_Fn);
#line 608 "src/parser.z"
  item->ident = parse_identifier(ctx);
#line 609 "src/parser.z"
  item->kind = ItemKind_Function;
#line 611 "src/parser.z"
  item->node.function.header = parse_function_header(ctx);
#line 613 "src/parser.z"
  if ((look_ahead(ctx, 0).kind == TokenKind_LeftCurly)) {
#line 613 "src/parser.z"
    item->node.function.body = parse_body(ctx, item->id);
  } else {
#line 614 "src/parser.z"
    item->node.function.body.owner = null;
  };
}

#line 617 "src/parser.z"
void parse_use(ParsingContext *ctx, Item *item) {
#line 618 "src/parser.z"
  expect(ctx, TokenKind_Use);
#line 620 "src/parser.z"
  item->kind = ItemKind_Use;
#line 621 "src/parser.z"
  item->node._use.path = parse_path(ctx);
#line 623 "src/parser.z"
  accept(ctx, TokenKind_Semicolon);
}

#line 626 "src/parser.z"
Mod parse_mod_inner(ParsingContext *ctx);

#line 627 "src/parser.z"
Mod parse_mod_external(Session *sess, CompilationUnit *unit, char *path);

#line 629 "src/parser.z"
void parse_mod(ParsingContext *ctx, Item *item) {
#line 630 "src/parser.z"
  expect(ctx, TokenKind_Mod);
#line 632 "src/parser.z"
  item->ident = parse_identifier(ctx);
#line 633 "src/parser.z"
  item->kind = ItemKind_Mod;
#line 635 "src/parser.z"
  if (accept(ctx, TokenKind_LeftCurly)) {
#line 635 "src/parser.z"
    item->node.module = parse_mod_inner(ctx);
  } else {
#line 637 "src/parser.z"
#line 637 "src/parser.z"
    Session *sess = ctx->sess;

#line 638 "src/parser.z"
#line 638 "src/parser.z"
    char *path = get_str(&sess->interner, item->ident.name);

#line 639 "src/parser.z"
    item->node.module = parse_mod_external(ctx->sess, ctx->unit, path);
  };
}

#line 644 "src/parser.z"
NodeId parse_item(ParsingContext *ctx) {
#line 645 "src/parser.z"
#line 645 "src/parser.z"
  Token tok = look_ahead(ctx, 0);

#line 647 "src/parser.z"
#line 647 "src/parser.z"
  NodeId id;

#line 648 "src/parser.z"
#line 648 "src/parser.z"
  Item *item = unit_create_item(ctx->unit, &id);

#line 649 "src/parser.z"
  item->span.from = span_start(ctx);
#line 651 "src/parser.z"
  if ((tok.kind == TokenKind_Fn)) {
#line 651 "src/parser.z"
    parse_function_decl(ctx, item);
  } else {
#line 652 "src/parser.z"
    if (((tok.kind == TokenKind_Struct) || (tok.kind == TokenKind_Union))) {
#line 652 "src/parser.z"
      parse_compound_decl(ctx, item);
    } else {
#line 653 "src/parser.z"
      if ((tok.kind == TokenKind_Enum)) {
#line 653 "src/parser.z"
        parse_enum_decl(ctx, item);
      } else {
#line 654 "src/parser.z"
        if (((tok.kind == TokenKind_Var) || (tok.kind == TokenKind_Val))) {
#line 654 "src/parser.z"
          parse_variable_decl(ctx, item);
        } else {
#line 655 "src/parser.z"
          if ((tok.kind == TokenKind_Use)) {
#line 655 "src/parser.z"
            parse_use(ctx, item);
          } else {
#line 656 "src/parser.z"
            if ((tok.kind == TokenKind_Mod)) {
#line 656 "src/parser.z"
              parse_mod(ctx, item);
            } else {
#line 657 "src/parser.z"
              emit_error(ctx->source_map, tok.span,
                         "Unexpected token on top-level");
            };
          };
        };
      };
    };
  };
#line 659 "src/parser.z"
  accept(ctx, TokenKind_Semicolon);
#line 661 "src/parser.z"
  item->span.to = span_end(ctx);
#line 662 "src/parser.z"
  return id;
}

#line 665 "src/parser.z"
Mod parse_mod_inner(ParsingContext *ctx) {
#line 666 "src/parser.z"
#line 666 "src/parser.z"
  Mod module;

#line 667 "src/parser.z"
  module.span.from = span_start(ctx);
#line 668 "src/parser.z"
  module.items = malloc((sizeof(NodeId) * 2048));
#line 669 "src/parser.z"
  module.num_items = 0;
#line 671 "src/parser.z"
  while ((!accept(ctx, TokenKind_RightCurly) && !is_done_parsing(ctx))) {
#line 672 "src/parser.z"
    module.items[module.num_items] = parse_item(ctx);
#line 673 "src/parser.z"
    module.num_items = (module.num_items + 1);
  };
#line 676 "src/parser.z"
  module.span.to = span_end(ctx);
#line 678 "src/parser.z"
  return module;
}

#line 681 "src/parser.z"
Mod parse_mod_external(Session *sess, CompilationUnit *unit, char *path) {
#line 683 "src/parser.z"
#line 683 "src/parser.z"
  SourceFile *source_file =
      source_map_new_file(&sess->source, sess->root_path, path);

#line 685 "src/parser.z"
#line 685 "src/parser.z"
  Token *tokens;

#line 686 "src/parser.z"
#line 686 "src/parser.z"
  u32 num_tokens;

#line 687 "src/parser.z"
  lex(sess, source_file, &tokens, &num_tokens);
#line 689 "src/parser.z"
#line 689 "src/parser.z"
  ParsingContext ctx;

#line 690 "src/parser.z"
  ctx.current_token = 0;
#line 691 "src/parser.z"
  ctx.tokens = tokens;
#line 692 "src/parser.z"
  ctx.num_tokens = num_tokens;
#line 693 "src/parser.z"
  ctx.source_map = &sess->source;
#line 694 "src/parser.z"
  ctx.sess = sess;
#line 695 "src/parser.z"
  ctx.unit = unit;
#line 697 "src/parser.z"
#line 697 "src/parser.z"
  Mod module = parse_mod_inner(&ctx);

#line 699 "src/parser.z"
  return module;
}

#line 702 "src/parser.z"
CompilationUnit parse(Session *sess, char *root_module_name) {
#line 704 "src/parser.z"
#line 704 "src/parser.z"
  CompilationUnit unit;

#line 706 "src/parser.z"
  unit.body_map = intmap_create(2048);
#line 707 "src/parser.z"
  unit.bodies = malloc((sizeof(Body) * 2048));
#line 708 "src/parser.z"
  unit.num_bodies = 1;
#line 710 "src/parser.z"
  unit.item_map = intmap_create(2048);
#line 711 "src/parser.z"
  unit.items = malloc((sizeof(Item) * 2048));
#line 712 "src/parser.z"
  unit.num_items = 1;
#line 714 "src/parser.z"
  unit.module = parse_mod_external(sess, &unit, root_module_name);
#line 716 "src/parser.z"
  return unit;
}
