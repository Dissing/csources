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
typedef enum IntegerSize {
_IntegerSize_I8,
_IntegerSize_I16,
_IntegerSize_I32,
_IntegerSize_I64,
_IntegerSize_Int_Arch,
_IntegerSize_Int_Unspecified,
} IntegerSize;


typedef enum FloatingSize {
_FloatingSize_F32,
_FloatingSize_F64,
_FloatingSize_Float_Unspecified,
} FloatingSize;


typedef enum PrimitiveTypeKind {
_PrimitiveTypeKind_Void,
_PrimitiveTypeKind_Signed,
_PrimitiveTypeKind_Unsigned,
_PrimitiveTypeKind_Floating,
_PrimitiveTypeKind_Char,
_PrimitiveTypeKind_Str,
} PrimitiveTypeKind;


