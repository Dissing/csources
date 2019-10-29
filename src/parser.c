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
typedef struct ParsingContext {
  u64 current_token;
  Token *tokens;
  u64 num_tokens;
} ParsingContext;

bool is_done_parsing(ParsingContext *ctx) {
  return (ctx->num_tokens == ctx->current_token);
}

bool accept(ParsingContext *ctx, TokenKind token) {
  Token tok = ctx->tokens[ctx->current_token];

  if ((!is_done_parsing(ctx) && (tok.kind == token))) {
    ctx->current_token = (ctx->current_token + 1);
    return true;
  };
  return false;
}

bool expect(ParsingContext *ctx, TokenKind token) {
  if (accept(ctx, token)) {
    return true;
  } else {
    Token tok = ctx->tokens[ctx->current_token];

    printf("Expected %d but got %d on line %d\n", token, tok.kind,
           tok.position);
    abort();
  };
}

Token look_ahead(ParsingContext *ctx, u64 offset) {
  if ((ctx->current_token == ctx->num_tokens)) {
    Token eof_tok;

    eof_tok.kind = EOF;
    return eof_tok;
  } else {
    return ctx->tokens[(ctx->current_token + offset)];
  };
}

Token consume(ParsingContext *ctx) {
  ctx->current_token = (ctx->current_token + 1);
  return ctx->tokens[(ctx->current_token - 1)];
}

AstPath parse_path(ParsingContext *ctx, Token tok) {
  AstPath path;

  path.segments = malloc((8 * 4));
  path.num_segments = 0;
  while (true) {
    if ((tok.kind != _TokenKind_Identifier)) {
      printf("Expected identifier in path but got %u on line %u\n", tok.kind,
             tok.position);
      abort();
    };
    path.num_segments = (path.num_segments + 1);
    path.segments[(path.num_segments - 1)] = tok.lexeme;
    if (!accept(ctx, _TokenKind_ColonColon)) {
      break;
    };
    tok = consume(ctx);
  }
  return path;
}

AstType *parse_type(ParsingContext *ctx) {
  AstTypeNode node;

  AstTypeKind kind;

  Token token = consume(ctx);

  if ((token.kind == _TokenKind_Identifier)) {
    kind = _AstTypeKind_Path;
    node.path = token.lexeme;
  } else {
    if ((token.kind == _TokenKind_Star)) {
      kind = _AstTypeKind_Ptr;
      node.ptr = parse_type(ctx);
    } else {
      printf("Expected type but got %d on line %d", token.kind, token.position);
      abort();
    };
  };
  AstType *type = malloc(sizeof(AstType));

  type->kind = kind;
  type->node = node;
  return type;
}

BinaryOperatorKind convert_token_to_binary_operator(TokenKind tok) {
  if ((tok == _TokenKind_Plus)) {
    return _BinaryOperatorKind_Addition;
  } else {
    if ((tok == _TokenKind_Minus)) {
      return _BinaryOperatorKind_Subtraction;
    } else {
      if ((tok == _TokenKind_Star)) {
        return _BinaryOperatorKind_Product;
      } else {
        if ((tok == _TokenKind_Slash)) {
          return _BinaryOperatorKind_Division;
        } else {
          if ((tok == _TokenKind_Percent)) {
            return _BinaryOperatorKind_Modulus;
          } else {
            if ((tok == _TokenKind_Less)) {
              return _BinaryOperatorKind_Less;
            } else {
              if ((tok == _TokenKind_LessEqual)) {
                return _BinaryOperatorKind_LessEq;
              } else {
                if ((tok == _TokenKind_Greater)) {
                  return _BinaryOperatorKind_Greater;
                } else {
                  if ((tok == _TokenKind_GreaterEqual)) {
                    return _BinaryOperatorKind_GreaterEq;
                  } else {
                    if ((tok == _TokenKind_EqualEqual)) {
                      return _BinaryOperatorKind_Equality;
                    } else {
                      if ((tok == _TokenKind_BangEqual)) {
                        return _BinaryOperatorKind_NotEq;
                      } else {
                        if ((tok == _TokenKind_AndAnd)) {
                          return _BinaryOperatorKind_And;
                        } else {
                          if ((tok == _TokenKind_OrOr)) {
                            return _BinaryOperatorKind_Or;
                          } else {
                            if ((tok == _TokenKind_And)) {
                              return _BinaryOperatorKind_BAnd;
                            } else {
                              if ((tok == _TokenKind_Or)) {
                                return _BinaryOperatorKind_BOr;
                              } else {
                                if ((tok == _TokenKind_Hat)) {
                                  return _BinaryOperatorKind_Xor;
                                } else {
                                  if ((tok == _TokenKind_LessLess)) {
                                    return _BinaryOperatorKind_LeftShift;
                                  } else {
                                    if ((tok == _TokenKind_GreaterGreater)) {
                                      return _BinaryOperatorKind_RightShift;
                                    } else {
                                      return _BinaryOperatorKind_Invalid;
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

u32 get_binary_operator_precedence(BinaryOperatorKind op) {
  if ((op == _BinaryOperatorKind_Product)) {
    return 10;
  } else {
    if ((op == _BinaryOperatorKind_Division)) {
      return 10;
    } else {
      if ((op == _BinaryOperatorKind_Modulus)) {
        return 10;
      } else {
        if ((op == _BinaryOperatorKind_Addition)) {
          return 9;
        } else {
          if ((op == _BinaryOperatorKind_Subtraction)) {
            return 9;
          } else {
            if ((op == _BinaryOperatorKind_LeftShift)) {
              return 8;
            } else {
              if ((op == _BinaryOperatorKind_RightShift)) {
                return 8;
              } else {
                if ((op == _BinaryOperatorKind_BAnd)) {
                  return 7;
                } else {
                  if ((op == _BinaryOperatorKind_Xor)) {
                    return 6;
                  } else {
                    if ((op == _BinaryOperatorKind_BOr)) {
                      return 5;
                    } else {
                      if ((op == _BinaryOperatorKind_Less)) {
                        return 4;
                      } else {
                        if ((op == _BinaryOperatorKind_LessEq)) {
                          return 4;
                        } else {
                          if ((op == _BinaryOperatorKind_Greater)) {
                            return 4;
                          } else {
                            if ((op == _BinaryOperatorKind_GreaterEq)) {
                              return 4;
                            } else {
                              if ((op == _BinaryOperatorKind_Equality)) {
                                return 4;
                              } else {
                                if ((op == _BinaryOperatorKind_NotEq)) {
                                  return 4;
                                } else {
                                  if ((op == _BinaryOperatorKind_And)) {
                                    return 3;
                                  } else {
                                    if ((op == _BinaryOperatorKind_Or)) {
                                      return 2;
                                    } else {
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

u32 get_current_precedence(ParsingContext *ctx) {
  if ((ctx->num_tokens <= ctx->current_token)) {
    return 0;
  } else {
    Token tok = ctx->tokens[ctx->current_token];

    u32 op_precedence = get_binary_operator_precedence(
        convert_token_to_binary_operator(tok.kind));

    if ((op_precedence > 0)) {
      return op_precedence;
    } else {
      if ((tok.kind == _TokenKind_Dot)) {
        return 13;
      } else {
        if (((tok.kind == _TokenKind_LeftBracket) ||
             (tok.kind == _TokenKind_LeftParen))) {
          return 12;
        } else {
          return 0;
        };
      };
    };
  };
}

AstExpr *parse_expression(ParsingContext *ctx, u32 precedence);

AstExpr *parse_integer_literal(ParsingContext *ctx, Token tok) {
  AstExpr *expr = malloc(sizeof(AstExpr));

  expr->kind = _AstExprKind_Literal;
  expr->node.literal.kind = _LiteralKind_Int;
  expr->node.literal.value.integer = atoi(tok.lexeme);
  return expr;
}

AstExpr *parse_float_literal(ParsingContext *ctx, Token tok) {
  AstExpr *expr = malloc(sizeof(AstExpr));

  expr->kind = _AstExprKind_Literal;
  expr->node.literal.kind = _LiteralKind_Float;
  expr->node.literal.value.floating = atof(tok.lexeme);
  return expr;
}

AstExpr *parse_char_literal(ParsingContext *ctx, Token tok) {
  AstExpr *expr = malloc(sizeof(AstExpr));

  expr->kind = _AstExprKind_Literal;
  expr->node.literal.kind = _LiteralKind_Char;
  u32 len = strlen(tok.lexeme);

  if (((len == 2) && (tok.lexeme[0] == '\\'))) {
    char c;

    if ((tok.lexeme[1] == 'n')) {
      c = '\n';
    } else {
      if ((tok.lexeme[1] == 't')) {
        c = '\t';
      } else {
        if ((tok.lexeme[1] == 'r')) {
          c = '\r';
        } else {
          if ((tok.lexeme[1] == '\\')) {
            c = '\\';
          } else {
            if ((tok.lexeme[1] == '\'')) {
              c = '\'';
            } else {
              printf("Unknown escape sequence %s on line %u\n", tok.lexeme,
                     tok.position);
              abort();
            };
          };
        };
      };
    };
    expr->node.literal.value.ch = c;
  } else {
    if ((len == 1)) {
      expr->node.literal.value.ch = tok.lexeme[0];
    } else {
      printf("Unknown char literal %s on line %u\n", tok.lexeme, tok.position);
      abort();
    };
  };
  return expr;
}

AstExpr *parse_string_literal(ParsingContext *ctx, Token tok) {
  AstExpr *expr = malloc(sizeof(AstExpr));

  expr->kind = _AstExprKind_Literal;
  expr->node.literal.kind = _LiteralKind_Str;
  expr->node.literal.value.str = tok.lexeme;
  return expr;
}

AstExpr *parse_bool_literal(ParsingContext *ctx, Token tok) {
  AstExpr *expr = malloc(sizeof(AstExpr));

  expr->kind = _AstExprKind_Literal;
  expr->node.literal.kind = _LiteralKind_Bool;
  expr->node.literal.value.boolean = (tok.kind == _TokenKind_True);
  return expr;
}

AstExpr *parse_identifier(ParsingContext *ctx, Token tok) {
  AstExpr *expr = malloc(sizeof(AstExpr));

  expr->kind = _AstExprKind_Identifier;
  expr->node.identifier = tok.lexeme;
  return expr;
}

AstExpr *parse_call(ParsingContext *ctx, AstExpr *left) {
  AstExpr *result = malloc(sizeof(AstExpr));

  result->kind = _AstExprKind_Call;
  result->node.call.func = left;
  result->node.call.args = malloc((8 * 16));
  result->node.call.num_args = 0;
  if (!accept(ctx, _TokenKind_RightParen)) {
    while (true) {
      AstExpr *expr = parse_expression(ctx, 0);

      result->node.call.args[result->node.call.num_args] = expr;
      result->node.call.num_args = (result->node.call.num_args + 1);
      if (!accept(ctx, _TokenKind_Comma)) {
        break;
      };
    }
    expect(ctx, _TokenKind_RightParen);
  };
  return result;
}

AstExpr *parse_prefix_operator(ParsingContext *ctx, Token tok) {
  AstExpr *expr = malloc(sizeof(AstExpr));

  expr->kind = _AstExprKind_Unary;
  if ((tok.kind == _TokenKind_Minus)) {
    expr->node.unary.operator= _UnaryOperatorKind_Negation;
  };
  if ((tok.kind == _TokenKind_Bang)) {
    expr->node.unary.operator= _UnaryOperatorKind_Complement;
  };
  if ((tok.kind == _TokenKind_And)) {
    expr->node.unary.operator= _UnaryOperatorKind_Refer;
  };
  if ((tok.kind == _TokenKind_Star)) {
    expr->node.unary.operator= _UnaryOperatorKind_Deref;
  };
  expr->node.unary.inner = parse_expression(ctx, 11);
  return expr;
}

AstExpr *parse_binary_operator(ParsingContext *ctx, AstExpr *left,
                               BinaryOperatorKind operator) {
  u32 precedence = get_binary_operator_precedence(operator);

  AstExpr *right = parse_expression(ctx, precedence);

  AstExpr *expr = malloc(sizeof(AstExpr));

  expr->kind = _AstExprKind_Binary;
  expr->node.binary.operator= operator;
  expr->node.binary.left = left;
  expr->node.binary.right = right;
  return expr;
}

AstExpr *parse_field_access(ParsingContext *ctx, AstExpr *left) {
  Token field_token = consume(ctx);

  if ((field_token.kind != _TokenKind_Identifier)) {
    printf("Token %d on line %d is not a valid field\n", field_token.kind,
           field_token.position);
    abort();
  };
  AstExpr *expr = malloc(sizeof(AstExpr));

  expr->kind = _AstExprKind_Field;
  expr->node.field.field_name = field_token.lexeme;
  expr->node.field.strct = left;
  return expr;
}

AstExpr *parse_indexing(ParsingContext *ctx, AstExpr *left) {
  AstExpr *expr = malloc(sizeof(AstExpr));

  expr->kind = _AstExprKind_Indexing;
  expr->node.index.index = parse_expression(ctx, 0);
  expr->node.index.array = left;
  expect(ctx, _TokenKind_RightBracket);
  return expr;
}

AstExpr *parse_infix_operator(ParsingContext *ctx, AstExpr *left, Token tok) {
  if ((tok.kind == _TokenKind_LeftParen)) {
    return parse_call(ctx, left);
  };
  if ((tok.kind == _TokenKind_Dot)) {
    return parse_field_access(ctx, left);
  };
  if ((tok.kind == _TokenKind_LeftBracket)) {
    return parse_indexing(ctx, left);
  };
  BinaryOperatorKind op = convert_token_to_binary_operator(tok.kind);

  if ((op != _BinaryOperatorKind_Invalid)) {
    return parse_binary_operator(ctx, left, op);
  } else {
    printf("Unsupported infix operator: %d on line %d\n", tok.kind,
           tok.position);
    abort();
  };
}

AstBlock *parse_block(ParsingContext *ctx);

AstExpr *parse_if(ParsingContext *ctx) {
  AstExpr *expr = malloc(sizeof(AstExpr));

  expr->kind = _AstExprKind_Conditional;
  expr->node.conditional.condition = parse_expression(ctx, 0);
  expr->node.conditional.then = parse_block(ctx);
  if (accept(ctx, _TokenKind_Else)) {
    expr->node.conditional.otherwise = parse_block(ctx);
  } else {
    expr->node.conditional.otherwise = null;
  };
  return expr;
}

AstExpr *parse_expression(ParsingContext *ctx, u32 precedence) {
  Token tok = consume(ctx);

  Token next = look_ahead(ctx, 0);

  AstExpr *left;

  if ((tok.kind == _TokenKind_Identifier)) {
    if ((next.kind == _TokenKind_ColonColon)) {
      left = malloc(sizeof(AstExpr));
      left->kind = _AstExprKind_Path;
      left->node.path = parse_path(ctx, tok);
    } else {
      left = parse_identifier(ctx, tok);
    };
  } else {
    if ((tok.kind == _TokenKind_Integer)) {
      left = parse_integer_literal(ctx, tok);
    } else {
      if ((tok.kind == _TokenKind_Char)) {
        left = parse_char_literal(ctx, tok);
      } else {
        if ((tok.kind == _TokenKind_String)) {
          left = parse_string_literal(ctx, tok);
        } else {
          if ((tok.kind == _TokenKind_Float)) {
            left = parse_float_literal(ctx, tok);
          } else {
            if (((tok.kind == _TokenKind_False) ||
                 (tok.kind == _TokenKind_True))) {
              left = parse_bool_literal(ctx, tok);
            } else {
              if (((((tok.kind == _TokenKind_Minus) ||
                     (tok.kind == _TokenKind_Bang)) ||
                    (tok.kind == _TokenKind_And)) ||
                   (tok.kind == _TokenKind_Star))) {
                left = parse_prefix_operator(ctx, tok);
              } else {
                if ((tok.kind == _TokenKind_If)) {
                  left = parse_if(ctx);
                } else {
                  if ((tok.kind == _TokenKind_LeftParen)) {
                    left = parse_expression(ctx, 0);
                    expect(ctx, _TokenKind_RightParen);
                  } else {
                    printf("%d is not a valid expression prefix on line %d\n",
                           tok.kind, tok.position);
                    abort();
                  };
                };
              };
            };
          };
        };
      };
    };
  };
  while ((precedence < get_current_precedence(ctx))) {
    Token next_tok = consume(ctx);

    left = parse_infix_operator(ctx, left, next_tok);
  }
  return left;
}

AstStmt *parse_stmt(ParsingContext *ctx);

AstBlock *parse_block(ParsingContext *ctx) {
  AstBlock *block = malloc(sizeof(AstBlock));

  block->stmts = malloc((8 * 128));
  block->num_stmts = 0;
  Token next = look_ahead(ctx, 0);

  if ((next.kind == _TokenKind_LeftCurly)) {
    expect(ctx, _TokenKind_LeftCurly);
    u32 i = 0;

    while (!accept(ctx, _TokenKind_RightCurly)) {
      block->stmts[i] = parse_stmt(ctx);
      block->num_stmts = (block->num_stmts + 1);
      i = (i + 1);
    }
  } else {
    block->stmts[0] = parse_stmt(ctx);
    block->num_stmts = 1;
  };
  return block;
}

AstItem *parse_item(ParsingContext *ctx);

AstStmt *parse_stmt(ParsingContext *ctx) {
  AstStmt *stmt = malloc(sizeof(AstStmt));

  Token tok = look_ahead(ctx, 0);

  if (accept(ctx, _TokenKind_Break)) {
    stmt->kind = _AstStmtKind_Break;
  } else {
    if (accept(ctx, _TokenKind_Continue)) {
      stmt->kind = _AstStmtKind_Continue;
    } else {
      if (accept(ctx, _TokenKind_Return)) {
        stmt->kind = _AstStmtKind_Return;
        stmt->node._return = parse_expression(ctx, 0);
      } else {
        if (accept(ctx, _TokenKind_Defer)) {
          stmt->kind = _AstStmtKind_Defer;
          stmt->node._defer = parse_expression(ctx, 0);
        } else {
          if (accept(ctx, _TokenKind_While)) {
            stmt->kind = _AstStmtKind_While;
            stmt->node._while.condition = parse_expression(ctx, 0);
            stmt->node._while.body = parse_block(ctx);
          } else {
            if (accept(ctx, _TokenKind_Semicolon)) {
              stmt->kind = _AstStmtKind_Empty;
            } else {
              if (((tok.kind == _TokenKind_Var) ||
                   (tok.kind == _TokenKind_Val))) {
                stmt->kind = _AstStmtKind_Item;
                stmt->node.item = parse_item(ctx);
              } else {
                AstExpr *left = parse_expression(ctx, 0);

                Token next = look_ahead(ctx, 0);

                if ((next.kind == _TokenKind_Equal)) {
                  stmt->kind = _AstStmtKind_Assignment;
                  stmt->node.assignment.left = left;
                  expect(ctx, _TokenKind_Equal);
                  stmt->node.assignment.right = parse_expression(ctx, 0);
                } else {
                  stmt->kind = _AstStmtKind_Expr;
                  stmt->node.expr = left;
                };
              };
            };
          };
        };
      };
    };
  };
  accept(ctx, _TokenKind_Semicolon);
  return stmt;
}

AstItem *parse_variable_decl(ParsingContext *ctx) {
  AstItem *item = malloc(sizeof(AstItem));

  Token keyword = consume(ctx);

  if ((keyword.kind == _TokenKind_Val)) {
    item->kind = _AstItemKind_Const;
  } else {
    if ((keyword.kind == _TokenKind_Var)) {
      item->kind = _AstItemKind_Variable;
    } else {
      abort();
    };
  };
  Token identifier = consume(ctx);

  item->name = identifier.lexeme;
  expect(ctx, _TokenKind_Colon);
  item->node.variable.type = parse_type(ctx);
  if (accept(ctx, _TokenKind_Equal)) {
    item->node.variable.value = parse_expression(ctx, 0);
  } else {
    item->node.variable.value = null;
  };
  return item;
}

AstItem *parse_compound_decl(ParsingContext *ctx) {
  AstItem *item = malloc(sizeof(AstItem));

  if (accept(ctx, _TokenKind_Struct)) {
    item->kind = _AstItemKind_Struct;
  } else {
    if (accept(ctx, _TokenKind_Union)) {
      item->kind = _AstItemKind_Union;
    } else {
      abort();
    };
  };
  Token identifier = consume(ctx);

  item->name = identifier.lexeme;
  expect(ctx, _TokenKind_LeftCurly);
  item->node.compound_type.field_names = malloc((8 * 16));
  item->node.compound_type.field_types = malloc((8 * 16));
  item->node.compound_type.num_fields = 0;
  while (!accept(ctx, _TokenKind_RightCurly)) {
    Token token = consume(ctx);

    if ((token.kind != _TokenKind_Identifier)) {
      printf("Expected field identifier on line %d but got %d\n",
             token.position, token.kind);
      abort();
    };
    item->node.compound_type.field_names[item->node.compound_type.num_fields] =
        token.lexeme;
    expect(ctx, _TokenKind_Colon);
    AstType *type = parse_type(ctx);

    item->node.compound_type.field_types[item->node.compound_type.num_fields] =
        type;
    item->node.compound_type.num_fields =
        (item->node.compound_type.num_fields + 1);
    expect(ctx, _TokenKind_Comma);
  }
  return item;
}

AstItem *parse_enum_decl(ParsingContext *ctx) {
  AstItem *item = malloc(sizeof(AstItem));

  expect(ctx, _TokenKind_Enum);
  item->kind = _AstItemKind_Enum;
  Token identifier = consume(ctx);

  item->name = identifier.lexeme;
  expect(ctx, _TokenKind_LeftCurly);
  item->node._enum.field_names = malloc((8 * 128));
  item->node._enum.num_fields = 0;
  while (!accept(ctx, _TokenKind_RightCurly)) {
    Token token = consume(ctx);

    if ((token.kind != _TokenKind_Identifier)) {
      printf("Expected enum variant identifier on line %d but got %d\n",
             token.position, token.kind);
      abort();
    };
    item->node._enum.field_names[item->node._enum.num_fields] = token.lexeme;
    item->node._enum.num_fields = (item->node._enum.num_fields + 1);
    expect(ctx, _TokenKind_Comma);
  }
  return item;
}

FunctionSignature parse_signature(ParsingContext *ctx) {
  FunctionSignature sig;

  sig.parameter_names = malloc((8 * 16));
  sig.parameter_types = malloc((8 * 16));
  sig.num_parameters = 0;
  expect(ctx, _TokenKind_LeftParen);
  while (!accept(ctx, _TokenKind_RightParen)) {
    Token name = consume(ctx);

    if ((name.kind != _TokenKind_Identifier)) {
      printf("Unexpected token %d in function signature on line %d\n",
             name.kind, name.position);
      abort();
    };
    expect(ctx, _TokenKind_Colon);
    AstType *type = parse_type(ctx);

    sig.parameter_names[sig.num_parameters] = name.lexeme;
    sig.parameter_types[sig.num_parameters] = type;
    sig.num_parameters = (sig.num_parameters + 1);
    accept(ctx, _TokenKind_Comma);
  }
  if (accept(ctx, _TokenKind_Arrow)) {
    sig.output_type = parse_type(ctx);
  } else {
    AstType *output_type = malloc(sizeof(AstType));

    output_type->kind = _AstTypeKind_Unit;
    sig.output_type = output_type;
  };
  return sig;
}

AstItem *parse_function_decl(ParsingContext *ctx) {
  AstItem *item = malloc(sizeof(AstItem));

  expect(ctx, _TokenKind_Fn);
  Token identifier = consume(ctx);

  item->name = identifier.lexeme;
  item->kind = _AstItemKind_Function;
  item->node.function.signature = parse_signature(ctx);
  if ((look_ahead(ctx, 0).kind == _TokenKind_LeftCurly)) {
    item->node.function.block = parse_block(ctx);
  } else {
    item->node.function.block = null;
  };
  return item;
}

AstItem *parse_item(ParsingContext *ctx) {
  Token tok = look_ahead(ctx, 0);

  AstItem *item = malloc(sizeof(AstItem));

  if ((tok.kind == _TokenKind_Fn)) {
    item = parse_function_decl(ctx);
  } else {
    if (((tok.kind == _TokenKind_Struct) || (tok.kind == _TokenKind_Union))) {
      item = parse_compound_decl(ctx);
    } else {
      if ((tok.kind == _TokenKind_Enum)) {
        item = parse_enum_decl(ctx);
      } else {
        if (((tok.kind == _TokenKind_Var) || (tok.kind == _TokenKind_Val))) {
          item = parse_variable_decl(ctx);
        } else {
          printf("Unexpected token %d on top-level on line %u\n", tok.kind,
                 tok.position);
          abort();
        };
      };
    };
  };
  accept(ctx, _TokenKind_Semicolon);
  return item;
}

AstItem **parse(Token *tokens, u32 num_tokens, u32 *num_items) {
  AstItem **items = malloc((8 * 2048));

  *num_items = 0;
  ParsingContext ctx;

  ctx.current_token = 0;
  ctx.tokens = tokens;
  ctx.num_tokens = num_tokens;
  while (!is_done_parsing(&ctx)) {
    items[*num_items] = parse_item(&ctx);
    *num_items = (*num_items + 1);
  }
  return items;
}
