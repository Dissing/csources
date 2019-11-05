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
typedef struct LexingContext LexingContext;
#line 1 "src/lexer.z"
typedef struct LexingContext {
  u32 start;
  u32 current;
  u32 line;
  u32 file_span_offset;
  SourceFile *source;
  Token *tokens;
  u32 current_token_idx;
  Session *sess;
  char *lexeme_buffer;
} LexingContext;

#line 13 "src/lexer.z"
bool is_alphabetic(char c) {
#line 14 "src/lexer.z"
  return (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')));
}

#line 17 "src/lexer.z"
bool is_digit(char c) {
#line 18 "src/lexer.z"
  return ((c >= '0') && (c <= '9'));
}

#line 21 "src/lexer.z"
bool is_alphanumeric(char c) {
#line 22 "src/lexer.z"
  return (is_alphabetic(c) || is_digit(c));
}

#line 25 "src/lexer.z"
bool is_done_lexing(LexingContext *ctx) {
#line 26 "src/lexer.z"
#line 26 "src/lexer.z"
  SourceFile *source = ctx->source;

#line 27 "src/lexer.z"
  return (ctx->current >= source->length);
}

#line 30 "src/lexer.z"
char peek_token(LexingContext *ctx, u32 offset) {
#line 31 "src/lexer.z"
  if (is_done_lexing(ctx)) {
#line 31 "src/lexer.z"
    return 0;
  };
#line 32 "src/lexer.z"
#line 32 "src/lexer.z"
  SourceFile *source = ctx->source;

#line 33 "src/lexer.z"
  return source->content[(ctx->current + offset)];
}

#line 36 "src/lexer.z"
char advance(LexingContext *ctx) {
#line 37 "src/lexer.z"
  ctx->current = (ctx->current + 1);
#line 38 "src/lexer.z"
#line 38 "src/lexer.z"
  SourceFile *source = ctx->source;

#line 39 "src/lexer.z"
  return source->content[(ctx->current - 1)];
}

#line 42 "src/lexer.z"
void add_token(LexingContext *ctx, TokenKind kind, Sid lexeme) {
#line 43 "src/lexer.z"
#line 43 "src/lexer.z"
  Token token;

#line 44 "src/lexer.z"
  token.kind = kind;
#line 45 "src/lexer.z"
  token.lexeme = lexeme;
#line 46 "src/lexer.z"
  token.span.from = (ctx->start + ctx->file_span_offset);
#line 47 "src/lexer.z"
  token.span.to = (ctx->current + ctx->file_span_offset);
#line 48 "src/lexer.z"
  ctx->tokens[ctx->current_token_idx] = token;
#line 49 "src/lexer.z"
  ctx->current_token_idx = (ctx->current_token_idx + 1);
}

#line 52 "src/lexer.z"
void add_simple_token(LexingContext *ctx, TokenKind kind) {
#line 53 "src/lexer.z"
#line 53 "src/lexer.z"
  Sid null_sid;

#line 54 "src/lexer.z"
  null_sid.x = 0;
#line 55 "src/lexer.z"
  add_token(ctx, kind, null_sid);
}

#line 58 "src/lexer.z"
void add_lookahead_conditional_token(LexingContext *ctx, char expect,
                                     TokenKind first, TokenKind second) {
#line 59 "src/lexer.z"
#line 59 "src/lexer.z"
  TokenKind kind;

#line 60 "src/lexer.z"
  if ((peek_token(ctx, 0) == expect)) {
#line 61 "src/lexer.z"
    advance(ctx);
#line 62 "src/lexer.z"
    kind = first;
  } else {
#line 64 "src/lexer.z"
    kind = second;
  };
#line 66 "src/lexer.z"
#line 66 "src/lexer.z"
  Sid null_sid;

#line 67 "src/lexer.z"
  null_sid.x = 0;
#line 68 "src/lexer.z"
  add_token(ctx, kind, null_sid);
}

#line 71 "src/lexer.z"
void read_newline(LexingContext *ctx) {
#line 72 "src/lexer.z"
  source_file_newline(ctx->source, ctx->start);
}

#line 75 "src/lexer.z"
Sid get_lexeme(LexingContext *ctx, u32 start_offset, u32 end_offset) {
#line 76 "src/lexer.z"
#line 76 "src/lexer.z"
  u32 str_len = (ctx->current - ((ctx->start + start_offset) + end_offset));

#line 77 "src/lexer.z"
#line 77 "src/lexer.z"
  SourceFile *source = ctx->source;

#line 78 "src/lexer.z"
  memcpy(ctx->lexeme_buffer, &source->content[(ctx->start + start_offset)],
         str_len);
#line 79 "src/lexer.z"
  ctx->lexeme_buffer[str_len] = 0;
#line 80 "src/lexer.z"
#line 80 "src/lexer.z"
  Session *sess = ctx->sess;

#line 81 "src/lexer.z"
#line 81 "src/lexer.z"
  Sid sid = intern(&sess->interner, ctx->lexeme_buffer);

#line 83 "src/lexer.z"
  return sid;
}

#line 86 "src/lexer.z"
void single_line_comment(LexingContext *ctx) {
#line 87 "src/lexer.z"
  while (((peek_token(ctx, 0) != '\n') && !is_done_lexing(ctx))) {
#line 87 "src/lexer.z"
    advance(ctx);
  };
}

#line 90 "src/lexer.z"
TokenKind is_keyword(char *s) {
#line 93 "src/lexer.z"
  if (!strcmp(s, "break")) {
#line 93 "src/lexer.z"
    return TokenKind_Break;
  };
#line 94 "src/lexer.z"
  if (!strcmp(s, "continue")) {
#line 94 "src/lexer.z"
    return TokenKind_Continue;
  };
#line 95 "src/lexer.z"
  if (!strcmp(s, "const")) {
#line 95 "src/lexer.z"
    return TokenKind_Continue;
  };
#line 96 "src/lexer.z"
  if (!strcmp(s, "defer")) {
#line 96 "src/lexer.z"
    return TokenKind_Defer;
  };
#line 97 "src/lexer.z"
  if (!strcmp(s, "enum")) {
#line 97 "src/lexer.z"
    return TokenKind_Enum;
  };
#line 98 "src/lexer.z"
  if (!strcmp(s, "else")) {
#line 98 "src/lexer.z"
    return TokenKind_Else;
  };
#line 99 "src/lexer.z"
  if (!strcmp(s, "false")) {
#line 99 "src/lexer.z"
    return TokenKind_False;
  };
#line 100 "src/lexer.z"
  if (!strcmp(s, "fn")) {
#line 100 "src/lexer.z"
    return TokenKind_Fn;
  };
#line 101 "src/lexer.z"
  if (!strcmp(s, "for")) {
#line 101 "src/lexer.z"
    return TokenKind_For;
  };
#line 102 "src/lexer.z"
  if (!strcmp(s, "if")) {
#line 102 "src/lexer.z"
    return TokenKind_If;
  };
#line 103 "src/lexer.z"
  if (!strcmp(s, "mod")) {
#line 103 "src/lexer.z"
    return TokenKind_Mod;
  };
#line 104 "src/lexer.z"
  if (!strcmp(s, "return")) {
#line 104 "src/lexer.z"
    return TokenKind_Return;
  };
#line 105 "src/lexer.z"
  if (!strcmp(s, "struct")) {
#line 105 "src/lexer.z"
    return TokenKind_Struct;
  };
#line 106 "src/lexer.z"
  if (!strcmp(s, "true")) {
#line 106 "src/lexer.z"
    return TokenKind_True;
  };
#line 107 "src/lexer.z"
  if (!strcmp(s, "union")) {
#line 107 "src/lexer.z"
    return TokenKind_Union;
  };
#line 108 "src/lexer.z"
  if (!strcmp(s, "use")) {
#line 108 "src/lexer.z"
    return TokenKind_Use;
  };
#line 109 "src/lexer.z"
  if (!strcmp(s, "var")) {
#line 109 "src/lexer.z"
    return TokenKind_Var;
  };
#line 110 "src/lexer.z"
  if (!strcmp(s, "val")) {
#line 110 "src/lexer.z"
    return TokenKind_Val;
  };
#line 111 "src/lexer.z"
  if (!strcmp(s, "while")) {
#line 111 "src/lexer.z"
    return TokenKind_While;
  };
#line 112 "src/lexer.z"
  return TokenKind_Invalid;
}

#line 115 "src/lexer.z"
void lex_char(LexingContext *ctx) {
#line 117 "src/lexer.z"
#line 117 "src/lexer.z"
  SourceFile *source = ctx->source;

#line 118 "src/lexer.z"
#line 118 "src/lexer.z"
  u32 start_line = (source->num_lines + 1);

#line 120 "src/lexer.z"
  while ((((peek_token(ctx, 0) != '\'') ||
           ((peek_token(ctx, -1) == '\\') && (peek_token(ctx, -2) != '\\'))) &&
          !is_done_lexing(ctx))) {
#line 121 "src/lexer.z"
#line 121 "src/lexer.z"
    char c = advance(ctx);

#line 122 "src/lexer.z"
    if ((c == '\n')) {
#line 122 "src/lexer.z"
      read_newline(ctx);
    };
  };
#line 125 "src/lexer.z"
  if (is_done_lexing(ctx)) {
#line 126 "src/lexer.z"
    printf("Unterminated char starting on line %u\n", start_line);
#line 127 "src/lexer.z"
    abort();
  };
#line 131 "src/lexer.z"
  advance(ctx);
#line 133 "src/lexer.z"
  add_token(ctx, TokenKind_Char, get_lexeme(ctx, 1, 1));
}

#line 136 "src/lexer.z"
void lex_string(LexingContext *ctx) {
#line 138 "src/lexer.z"
#line 138 "src/lexer.z"
  SourceFile *source = ctx->source;

#line 140 "src/lexer.z"
#line 140 "src/lexer.z"
  u32 start_line = (source->num_lines + 1);

#line 142 "src/lexer.z"
  while ((((peek_token(ctx, 0) != '"') ||
           ((peek_token(ctx, -1) == '\\') && (peek_token(ctx, -2) != '\\'))) &&
          !is_done_lexing(ctx))) {
#line 143 "src/lexer.z"
#line 143 "src/lexer.z"
    char c = advance(ctx);

#line 144 "src/lexer.z"
    if ((c == '\n')) {
#line 144 "src/lexer.z"
      read_newline(ctx);
    };
  };
#line 147 "src/lexer.z"
  if (is_done_lexing(ctx)) {
#line 148 "src/lexer.z"
    printf("Unterminated string starting on line %u\n", start_line);
#line 149 "src/lexer.z"
    abort();
  };
#line 153 "src/lexer.z"
  advance(ctx);
#line 155 "src/lexer.z"
  add_token(ctx, TokenKind_String, get_lexeme(ctx, 1, 1));
}

#line 158 "src/lexer.z"
void lex_number(LexingContext *ctx) {
#line 160 "src/lexer.z"
  while (is_digit(peek_token(ctx, 0))) {
#line 160 "src/lexer.z"
    advance(ctx);
  };
#line 161 "src/lexer.z"
#line 161 "src/lexer.z"
  bool dot_encountered = false;

#line 162 "src/lexer.z"
  if (((peek_token(ctx, 0) == '.') && is_digit(peek_token(ctx, 1)))) {
#line 163 "src/lexer.z"
    dot_encountered = true;
#line 164 "src/lexer.z"
    advance(ctx);
#line 165 "src/lexer.z"
    while (is_digit(peek_token(ctx, 0))) {
#line 165 "src/lexer.z"
      advance(ctx);
    };
  };
#line 168 "src/lexer.z"
#line 168 "src/lexer.z"
  TokenKind t;

#line 169 "src/lexer.z"
  if (dot_encountered) {
#line 169 "src/lexer.z"
    t = TokenKind_Float;
  } else {
#line 170 "src/lexer.z"
    t = TokenKind_Integer;
  };
#line 172 "src/lexer.z"
  add_token(ctx, t, get_lexeme(ctx, 0, 0));
}

#line 175 "src/lexer.z"
void lex_identifier(LexingContext *ctx) {
#line 176 "src/lexer.z"
  while ((is_alphanumeric(peek_token(ctx, 0)) || (peek_token(ctx, 0) == '_'))) {
#line 176 "src/lexer.z"
    advance(ctx);
  };
#line 178 "src/lexer.z"
#line 178 "src/lexer.z"
  Sid lexeme = get_lexeme(ctx, 0, 0);

#line 180 "src/lexer.z"
#line 180 "src/lexer.z"
  Session *sess = ctx->sess;

#line 181 "src/lexer.z"
#line 181 "src/lexer.z"
  char *lexeme_str = get_str(&sess->interner, lexeme);

#line 182 "src/lexer.z"
#line 182 "src/lexer.z"
  TokenKind keyword = is_keyword(lexeme_str);

#line 183 "src/lexer.z"
  if ((keyword != TokenKind_Invalid)) {
#line 183 "src/lexer.z"
    add_simple_token(ctx, keyword);
  } else {
#line 184 "src/lexer.z"
    add_token(ctx, TokenKind_Identifier, lexeme);
  };
}

#line 187 "src/lexer.z"
void scan_token(LexingContext *ctx) {
#line 188 "src/lexer.z"
#line 188 "src/lexer.z"
  char c = advance(ctx);

#line 192 "src/lexer.z"
  if ((c == '(')) {
#line 192 "src/lexer.z"
    add_simple_token(ctx, TokenKind_LeftParen);
  } else {
#line 193 "src/lexer.z"
    if ((c == ')')) {
#line 193 "src/lexer.z"
      add_simple_token(ctx, TokenKind_RightParen);
    } else {
#line 194 "src/lexer.z"
      if ((c == '[')) {
#line 194 "src/lexer.z"
        add_simple_token(ctx, TokenKind_LeftBracket);
      } else {
#line 195 "src/lexer.z"
        if ((c == ']')) {
#line 195 "src/lexer.z"
          add_simple_token(ctx, TokenKind_RightBracket);
        } else {
#line 196 "src/lexer.z"
          if ((c == '{')) {
#line 196 "src/lexer.z"
            add_simple_token(ctx, TokenKind_LeftCurly);
          } else {
#line 197 "src/lexer.z"
            if ((c == '}')) {
#line 197 "src/lexer.z"
              add_simple_token(ctx, TokenKind_RightCurly);
            } else {
#line 198 "src/lexer.z"
              if ((c == '+')) {
#line 198 "src/lexer.z"
                add_simple_token(ctx, TokenKind_Plus);
              } else {
#line 199 "src/lexer.z"
                if ((c == '*')) {
#line 199 "src/lexer.z"
                  add_simple_token(ctx, TokenKind_Star);
                } else {
#line 200 "src/lexer.z"
                  if ((c == '%')) {
#line 200 "src/lexer.z"
                    add_simple_token(ctx, TokenKind_Percent);
                  } else {
#line 201 "src/lexer.z"
                    if ((c == '^')) {
#line 201 "src/lexer.z"
                      add_simple_token(ctx, TokenKind_Hat);
                    } else {
#line 202 "src/lexer.z"
                      if ((c == ';')) {
#line 202 "src/lexer.z"
                        add_simple_token(ctx, TokenKind_Semicolon);
                      } else {
#line 203 "src/lexer.z"
                        if ((c == '.')) {
#line 203 "src/lexer.z"
                          add_simple_token(ctx, TokenKind_Dot);
                        } else {
#line 204 "src/lexer.z"
                          if ((c == ',')) {
#line 204 "src/lexer.z"
                            add_simple_token(ctx, TokenKind_Comma);
                          } else {
#line 205 "src/lexer.z"
                            if ((c == '-')) {
#line 205 "src/lexer.z"
                              add_lookahead_conditional_token(
                                  ctx, '>', TokenKind_Arrow, TokenKind_Minus);
                            } else {
#line 206 "src/lexer.z"
                              if ((c == ':')) {
#line 206 "src/lexer.z"
                                add_lookahead_conditional_token(
                                    ctx, ':', TokenKind_ColonColon,
                                    TokenKind_Colon);
                              } else {
#line 207 "src/lexer.z"
                                if ((c == '=')) {
#line 207 "src/lexer.z"
                                  add_lookahead_conditional_token(
                                      ctx, '=', TokenKind_EqualEqual,
                                      TokenKind_Equal);
                                } else {
#line 208 "src/lexer.z"
                                  if ((c == '!')) {
#line 208 "src/lexer.z"
                                    add_lookahead_conditional_token(
                                        ctx, '=', TokenKind_BangEqual,
                                        TokenKind_Bang);
                                  } else {
#line 209 "src/lexer.z"
                                    if ((c == '&')) {
#line 209 "src/lexer.z"
                                      add_lookahead_conditional_token(
                                          ctx, '&', TokenKind_AndAnd,
                                          TokenKind_And);
                                    } else {
#line 210 "src/lexer.z"
                                      if ((c == '|')) {
#line 210 "src/lexer.z"
                                        add_lookahead_conditional_token(
                                            ctx, '|', TokenKind_OrOr,
                                            TokenKind_Or);
                                      } else {
#line 211 "src/lexer.z"
                                        if ((c == '<')) {
#line 212 "src/lexer.z"
#line 212 "src/lexer.z"
                                          char n1 = peek_token(ctx, 0);

#line 213 "src/lexer.z"
                                          if ((n1 == '<')) {
#line 213 "src/lexer.z"
                                            advance(ctx);
#line 213 "src/lexer.z"
                                            add_simple_token(
                                                ctx, TokenKind_LessLess);
                                          } else {
#line 214 "src/lexer.z"
                                            if ((n1 == '=')) {
#line 214 "src/lexer.z"
                                              advance(ctx);
#line 214 "src/lexer.z"
                                              add_simple_token(
                                                  ctx, TokenKind_LessEqual);
                                            } else {
#line 215 "src/lexer.z"
                                              add_simple_token(ctx,
                                                               TokenKind_Less);
                                            };
                                          };
                                        } else {
#line 217 "src/lexer.z"
                                          if ((c == '>')) {
#line 218 "src/lexer.z"
#line 218 "src/lexer.z"
                                            char n2 = peek_token(ctx, 0);

#line 219 "src/lexer.z"
                                            if ((n2 == '>')) {
#line 219 "src/lexer.z"
                                              advance(ctx);
#line 219 "src/lexer.z"
                                              add_simple_token(
                                                  ctx,
                                                  TokenKind_GreaterGreater);
                                            } else {
#line 220 "src/lexer.z"
                                              if ((n2 == '=')) {
#line 220 "src/lexer.z"
                                                advance(ctx);
#line 220 "src/lexer.z"
                                                add_simple_token(
                                                    ctx,
                                                    TokenKind_GreaterEqual);
                                              } else {
#line 221 "src/lexer.z"
                                                add_simple_token(
                                                    ctx, TokenKind_Greater);
                                              };
                                            };
                                          } else {
#line 223 "src/lexer.z"
                                            if ((c == '/')) {
#line 224 "src/lexer.z"
                                              if ((peek_token(ctx, 0) == '/')) {
#line 224 "src/lexer.z"
                                                single_line_comment(ctx);
                                              } else {
#line 225 "src/lexer.z"
                                                add_simple_token(
                                                    ctx, TokenKind_Slash);
                                              };
                                            } else {
#line 227 "src/lexer.z"
                                              if ((((c == ' ') ||
                                                    (c == '\t')) ||
                                                   (c == '\r'))) {
                                              } else {
#line 228 "src/lexer.z"
                                                if ((c == '\n')) {
#line 228 "src/lexer.z"
                                                  read_newline(ctx);
                                                } else {
#line 229 "src/lexer.z"
                                                  if ((c == '"')) {
#line 229 "src/lexer.z"
                                                    lex_string(ctx);
                                                  } else {
#line 230 "src/lexer.z"
                                                    if ((c == '\'')) {
#line 230 "src/lexer.z"
                                                      lex_char(ctx);
                                                    } else {
#line 232 "src/lexer.z"
                                                      if (is_digit(c)) {
#line 232 "src/lexer.z"
                                                        lex_number(ctx);
                                                      } else {
#line 233 "src/lexer.z"
                                                        if ((is_alphabetic(c) ||
                                                             (c == '_'))) {
#line 233 "src/lexer.z"
                                                          lex_identifier(ctx);
                                                        } else {
#line 235 "src/lexer.z"
#line 235 "src/lexer.z"
                                                          SourceFile *source =
                                                              ctx->source;

#line 236 "src/lexer.z"
                                                          printf(
                                                              "Unexpected "
                                                              "character %c = "
                                                              "%d on line %u\n",
                                                              c, c,
                                                              source
                                                                  ->num_lines);
#line 237 "src/lexer.z"
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
  };
}

#line 242 "src/lexer.z"
void lex(Session *sess, SourceFile *source, Token **tokens, u32 *num_tokens) {
#line 244 "src/lexer.z"
#line 244 "src/lexer.z"
  LexingContext *ctx = malloc(sizeof(LexingContext));

#line 245 "src/lexer.z"
  ctx->source = source;
#line 246 "src/lexer.z"
  ctx->file_span_offset = source->start;
#line 247 "src/lexer.z"
  ctx->start = 0;
#line 248 "src/lexer.z"
  ctx->current = 0;
#line 249 "src/lexer.z"
  ctx->tokens = malloc((sizeof(Token) * 10000));
#line 250 "src/lexer.z"
  ctx->current_token_idx = 0;
#line 251 "src/lexer.z"
  ctx->sess = sess;
#line 253 "src/lexer.z"
  ctx->lexeme_buffer = malloc(1024);
#line 255 "src/lexer.z"
  while (!is_done_lexing(ctx)) {
#line 256 "src/lexer.z"
    ctx->start = ctx->current;
#line 257 "src/lexer.z"
    scan_token(ctx);
  };
#line 260 "src/lexer.z"
  source_file_done(source, ctx->current);
#line 262 "src/lexer.z"
  if ((ctx->current_token_idx > 10000)) {
#line 263 "src/lexer.z"
    printf("Lexer token overflow: %u!\n", ctx->current_token_idx);
#line 264 "src/lexer.z"
    abort();
  };
#line 267 "src/lexer.z"
  *tokens = ctx->tokens;
#line 268 "src/lexer.z"
  *num_tokens = ctx->current_token_idx;
}
