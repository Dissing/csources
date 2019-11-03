//Prelude
#include <stdint.h>
#include <stdbool.h>
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
typedef enum TokenKind {
_TokenKind_Invalid,
_TokenKind_Identifier,
_TokenKind_EOF,
_TokenKind_Break,
_TokenKind_Const,
_TokenKind_Continue,
_TokenKind_Defer,
_TokenKind_Enum,
_TokenKind_Else,
_TokenKind_Fn,
_TokenKind_For,
_TokenKind_If,
_TokenKind_Mod,
_TokenKind_Return,
_TokenKind_Static,
_TokenKind_Struct,
_TokenKind_Union,
_TokenKind_Use,
_TokenKind_Var,
_TokenKind_Val,
_TokenKind_While,
_TokenKind_Plus,
_TokenKind_Minus,
_TokenKind_Star,
_TokenKind_Slash,
_TokenKind_Percent,
_TokenKind_LessLess,
_TokenKind_GreaterGreater,
_TokenKind_And,
_TokenKind_AndAnd,
_TokenKind_Or,
_TokenKind_OrOr,
_TokenKind_Hat,
_TokenKind_Equal,
_TokenKind_Bang,
_TokenKind_BangEqual,
_TokenKind_EqualEqual,
_TokenKind_Less,
_TokenKind_Greater,
_TokenKind_LessEqual,
_TokenKind_GreaterEqual,
_TokenKind_LeftParen,
_TokenKind_RightParen,
_TokenKind_LeftBracket,
_TokenKind_RightBracket,
_TokenKind_LeftCurly,
_TokenKind_RightCurly,
_TokenKind_Comma,
_TokenKind_Dot,
_TokenKind_Colon,
_TokenKind_ColonColon,
_TokenKind_Semicolon,
_TokenKind_Arrow,
_TokenKind_Integer,
_TokenKind_Float,
_TokenKind_Char,
_TokenKind_String,
_TokenKind_True,
_TokenKind_False,
} TokenKind;


typedef struct Token Token;
typedef struct Token {
TokenKind kind;
Span span;
Sid lexeme;
} Token;


