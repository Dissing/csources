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
#line 3 "src/tokens.z"
typedef enum TokenKind {
  TokenKind_Invalid,
  TokenKind_Identifier,
  TokenKind_EOF,
  TokenKind_Break,
  TokenKind_Const,
  TokenKind_Continue,
  TokenKind_Defer,
  TokenKind_Enum,
  TokenKind_Else,
  TokenKind_Fn,
  TokenKind_For,
  TokenKind_If,
  TokenKind_Mod,
  TokenKind_Return,
  TokenKind_Static,
  TokenKind_Struct,
  TokenKind_Union,
  TokenKind_Use,
  TokenKind_Var,
  TokenKind_Val,
  TokenKind_While,
  TokenKind_Plus,
  TokenKind_Minus,
  TokenKind_Star,
  TokenKind_Slash,
  TokenKind_Percent,
  TokenKind_LessLess,
  TokenKind_GreaterGreater,
  TokenKind_And,
  TokenKind_AndAnd,
  TokenKind_Or,
  TokenKind_OrOr,
  TokenKind_Hat,
  TokenKind_Equal,
  TokenKind_Bang,
  TokenKind_BangEqual,
  TokenKind_EqualEqual,
  TokenKind_Less,
  TokenKind_Greater,
  TokenKind_LessEqual,
  TokenKind_GreaterEqual,
  TokenKind_LeftParen,
  TokenKind_RightParen,
  TokenKind_LeftBracket,
  TokenKind_RightBracket,
  TokenKind_LeftCurly,
  TokenKind_RightCurly,
  TokenKind_Comma,
  TokenKind_Dot,
  TokenKind_Colon,
  TokenKind_ColonColon,
  TokenKind_Semicolon,
  TokenKind_Arrow,
  TokenKind_Integer,
  TokenKind_Float,
  TokenKind_Char,
  TokenKind_String,
  TokenKind_True,
  TokenKind_False,
} TokenKind;

typedef struct Token Token;
#line 69 "src/tokens.z"
typedef struct Token {
  TokenKind kind;
  Span span;
  Sid lexeme;
} Token;
