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
typedef struct LexingContext {
  u64 start;
  u64 current;
  u64 line;
  char *source;
  u64 source_len;
  Token *tokens;
  u64 current_token_idx;
} LexingContext;

bool is_alphabetic(char c) {
  return (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')));
}

bool is_digit(char c) { return ((c >= '0') && (c <= '9')); }

bool is_alphanumeric(char c) { return (is_alphabetic(c) || is_digit(c)); }

bool is_done_lexing(LexingContext *ctx) {
  return (ctx->current >= ctx->source_len);
}

char peek_token(LexingContext *ctx, u64 offset) {
  if (is_done_lexing(ctx)) {
    return 0;
  };
  return ctx->source[(ctx->current + offset)];
}

char advance(LexingContext *ctx) {
  ctx->current = (ctx->current + 1);
  return ctx->source[(ctx->current - 1)];
}

void add_simple_token(LexingContext *ctx, TokenKind token_kind) {
  Token token;

  token.kind = token_kind;
  token.lexeme = null;
  token.position = ctx->line;
  ctx->tokens[ctx->current_token_idx] = token;
  ctx->current_token_idx = (ctx->current_token_idx + 1);
}

void add_lookahead_conditional_token(LexingContext *ctx, char expect,
                                     TokenKind first, TokenKind second) {
  Token token;

  token.lexeme = null;
  token.position = ctx->line;
  if ((peek_token(ctx, 0) == expect)) {
    advance(ctx);
    token.kind = first;
  } else {
    token.kind = second;
  };
  ctx->tokens[ctx->current_token_idx] = token;
  ctx->current_token_idx = (ctx->current_token_idx + 1);
}

char *get_lexeme(LexingContext *ctx, u32 start_offset, u32 end_offset) {
  u64 str_len = (ctx->current - ((ctx->start + start_offset) + end_offset));

  char *str = malloc((str_len + 1));

  memcpy(str, &ctx->source[(ctx->start + start_offset)], str_len);
  str[str_len] = 0;
  return str;
}

void add_lexeme_token(LexingContext *ctx, char *lexeme, TokenKind token_kind) {
  Token token;

  token.kind = token_kind;
  token.lexeme = lexeme;
  token.position = ctx->line;
  ctx->tokens[ctx->current_token_idx] = token;
  ctx->current_token_idx = (ctx->current_token_idx + 1);
}

void single_line_comment(LexingContext *ctx) {
  while (((peek_token(ctx, 0) != '\n') && !is_done_lexing(ctx))) {
    advance(ctx);
  }
}

TokenKind is_keyword(char *s) {
  if (!strcmp(s, "break")) {
    return _TokenKind_Break;
  };
  if (!strcmp(s, "continue")) {
    return _TokenKind_Continue;
  };
  if (!strcmp(s, "const")) {
    return _TokenKind_Continue;
  };
  if (!strcmp(s, "defer")) {
    return _TokenKind_Defer;
  };
  if (!strcmp(s, "enum")) {
    return _TokenKind_Enum;
  };
  if (!strcmp(s, "else")) {
    return _TokenKind_Else;
  };
  if (!strcmp(s, "false")) {
    return _TokenKind_False;
  };
  if (!strcmp(s, "fn")) {
    return _TokenKind_Fn;
  };
  if (!strcmp(s, "for")) {
    return _TokenKind_For;
  };
  if (!strcmp(s, "if")) {
    return _TokenKind_If;
  };
  if (!strcmp(s, "return")) {
    return _TokenKind_Return;
  };
  if (!strcmp(s, "struct")) {
    return _TokenKind_Struct;
  };
  if (!strcmp(s, "true")) {
    return _TokenKind_True;
  };
  if (!strcmp(s, "union")) {
    return _TokenKind_Union;
  };
  if (!strcmp(s, "var")) {
    return _TokenKind_Var;
  };
  if (!strcmp(s, "val")) {
    return _TokenKind_Val;
  };
  if (!strcmp(s, "while")) {
    return _TokenKind_While;
  };
  return _TokenKind_Invalid;
}

void lex_char(LexingContext *ctx) {
  u64 start_line = ctx->line;

  while ((((peek_token(ctx, 0) != '\'') ||
           ((peek_token(ctx, -1) == '\\') && (peek_token(ctx, -2) != '\\'))) &&
          !is_done_lexing(ctx))) {
    if ((peek_token(ctx, 0) == '\n')) {
      ctx->line = (ctx->line + 1);
    };
    advance(ctx);
  }
  if (is_done_lexing(ctx)) {
    printf("Unterminated char starting on line %lu", start_line);
    abort();
  };
  advance(ctx);
  char *lexeme = get_lexeme(ctx, 1, 1);

  add_lexeme_token(ctx, lexeme, _TokenKind_Char);
}

void lex_string(LexingContext *ctx) {
  u64 start_line = ctx->line;

  while ((((peek_token(ctx, 0) != '"') ||
           ((peek_token(ctx, -1) == '\\') && (peek_token(ctx, -2) != '\\'))) &&
          !is_done_lexing(ctx))) {
    if ((peek_token(ctx, 0) == '\n')) {
      ctx->line = (ctx->line + 1);
    };
    advance(ctx);
  }
  if (is_done_lexing(ctx)) {
    printf("Unterminated string starting on line %lu", start_line);
    abort();
  };
  advance(ctx);
  char *lexeme = get_lexeme(ctx, 1, 1);

  add_lexeme_token(ctx, lexeme, _TokenKind_String);
}

void lex_number(LexingContext *ctx) {
  while (is_digit(peek_token(ctx, 0))) {
    advance(ctx);
  }
  bool dot_encountered = false;

  if (((peek_token(ctx, 0) == '.') && is_digit(peek_token(ctx, 1)))) {
    dot_encountered = true;
    advance(ctx);
    while (is_digit(peek_token(ctx, 0))) {
      advance(ctx);
    }
  };
  char *lexeme = get_lexeme(ctx, 0, 0);

  TokenKind t;

  if (dot_encountered) {
    t = _TokenKind_Float;
  } else {
    t = _TokenKind_Integer;
  };
  add_lexeme_token(ctx, lexeme, t);
}

void lex_identifier(LexingContext *ctx) {
  while ((is_alphanumeric(peek_token(ctx, 0)) || (peek_token(ctx, 0) == '_'))) {
    advance(ctx);
  }
  char *lexeme = get_lexeme(ctx, 0, 0);

  TokenKind keyword = is_keyword(lexeme);

  if ((keyword != _TokenKind_Invalid)) {
    add_simple_token(ctx, keyword);
  } else {
    add_lexeme_token(ctx, lexeme, _TokenKind_Identifier);
  };
}

void scan_token(LexingContext *ctx) {
  char c = advance(ctx);

  if ((c == '(')) {
    add_simple_token(ctx, _TokenKind_LeftParen);
  } else {
    if ((c == ')')) {
      add_simple_token(ctx, _TokenKind_RightParen);
    } else {
      if ((c == '[')) {
        add_simple_token(ctx, _TokenKind_LeftBracket);
      } else {
        if ((c == ']')) {
          add_simple_token(ctx, _TokenKind_RightBracket);
        } else {
          if ((c == '{')) {
            add_simple_token(ctx, _TokenKind_LeftCurly);
          } else {
            if ((c == '}')) {
              add_simple_token(ctx, _TokenKind_RightCurly);
            } else {
              if ((c == '+')) {
                add_simple_token(ctx, _TokenKind_Plus);
              } else {
                if ((c == '*')) {
                  add_simple_token(ctx, _TokenKind_Star);
                } else {
                  if ((c == '%')) {
                    add_simple_token(ctx, _TokenKind_Percent);
                  } else {
                    if ((c == '^')) {
                      add_simple_token(ctx, _TokenKind_Hat);
                    } else {
                      if ((c == ';')) {
                        add_simple_token(ctx, _TokenKind_Semicolon);
                      } else {
                        if ((c == '.')) {
                          add_simple_token(ctx, _TokenKind_Dot);
                        } else {
                          if ((c == ',')) {
                            add_simple_token(ctx, _TokenKind_Comma);
                          } else {
                            if ((c == '-')) {
                              add_lookahead_conditional_token(
                                  ctx, '>', _TokenKind_Arrow, _TokenKind_Minus);
                            } else {
                              if ((c == ':')) {
                                add_lookahead_conditional_token(
                                    ctx, ':', _TokenKind_ColonColon,
                                    _TokenKind_Colon);
                              } else {
                                if ((c == '=')) {
                                  add_lookahead_conditional_token(
                                      ctx, '=', _TokenKind_EqualEqual,
                                      _TokenKind_Equal);
                                } else {
                                  if ((c == '!')) {
                                    add_lookahead_conditional_token(
                                        ctx, '=', _TokenKind_BangEqual,
                                        _TokenKind_Bang);
                                  } else {
                                    if ((c == '&')) {
                                      add_lookahead_conditional_token(
                                          ctx, '&', _TokenKind_AndAnd,
                                          _TokenKind_And);
                                    } else {
                                      if ((c == '|')) {
                                        add_lookahead_conditional_token(
                                            ctx, '|', _TokenKind_OrOr,
                                            _TokenKind_Or);
                                      } else {
                                        if ((c == '<')) {
                                          char n1 = peek_token(ctx, 0);

                                          if ((n1 == '<')) {
                                            advance(ctx);
                                            add_simple_token(
                                                ctx, _TokenKind_LessLess);
                                          } else {
                                            if ((n1 == '=')) {
                                              advance(ctx);
                                              add_simple_token(
                                                  ctx, _TokenKind_LessEqual);
                                            } else {
                                              add_simple_token(ctx,
                                                               _TokenKind_Less);
                                            };
                                          };
                                        } else {
                                          if ((c == '>')) {
                                            char n2 = peek_token(ctx, 0);

                                            if ((n2 == '>')) {
                                              advance(ctx);
                                              add_simple_token(
                                                  ctx,
                                                  _TokenKind_GreaterGreater);
                                            } else {
                                              if ((n2 == '=')) {
                                                advance(ctx);
                                                add_simple_token(
                                                    ctx,
                                                    _TokenKind_GreaterEqual);
                                              } else {
                                                add_simple_token(
                                                    ctx, _TokenKind_Greater);
                                              };
                                            };
                                          } else {
                                            if ((c == '/')) {
                                              if ((peek_token(ctx, 0) == '/')) {
                                                single_line_comment(ctx);
                                              } else {
                                                add_simple_token(
                                                    ctx, _TokenKind_Slash);
                                              };
                                            } else {
                                              if ((((c == ' ') ||
                                                    (c == '\t')) ||
                                                   (c == '\r'))) {
                                              } else {
                                                if ((c == '\n')) {
                                                  ctx->line = (ctx->line + 1);
                                                } else {
                                                  if ((c == '"')) {
                                                    lex_string(ctx);
                                                  } else {
                                                    if ((c == '\'')) {
                                                      lex_char(ctx);
                                                    } else {
                                                      if (is_digit(c)) {
                                                        lex_number(ctx);
                                                      } else {
                                                        if ((is_alphabetic(c) ||
                                                             (c == '_'))) {
                                                          lex_identifier(ctx);
                                                        } else {
                                                          printf("Unexpected "
                                                                 "character %c "
                                                                 "= %d on line "
                                                                 "%lu\n",
                                                                 c, c,
                                                                 ctx->line);
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

void lex(char *source, u64 source_len, Token **tokens, u32 *num_tokens) {
  LexingContext *ctx = malloc(sizeof(LexingContext));

  ctx->source = source;
  ctx->source_len = source_len;
  ctx->start = 0;
  ctx->current = 0;
  ctx->line = 1;
  ctx->tokens = malloc((sizeof(Token) * 5000));
  ctx->current_token_idx = 0;
  while (!is_done_lexing(ctx)) {
    ctx->start = ctx->current;
    scan_token(ctx);
  }
  if ((ctx->current_token_idx > 5000)) {
    printf("Lexer token overflow: %lu!\n", ctx->current_token_idx);
    abort();
  };
  *tokens = ctx->tokens;
  *num_tokens = ctx->current_token_idx;
}
