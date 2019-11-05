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
#line 1 "src/types.z"
typedef enum IntegerSize {
  IntegerSize_I8,
  IntegerSize_I16,
  IntegerSize_I32,
  IntegerSize_I64,
  IntegerSize_Int_Arch,
  IntegerSize_Int_Unspecified,
} IntegerSize;

#line 10 "src/types.z"
typedef enum FloatingSize {
  FloatingSize_F32,
  FloatingSize_F64,
  FloatingSize_Float_Unspecified,
} FloatingSize;

#line 16 "src/types.z"
typedef enum PrimitiveTypeKind {
  PrimitiveTypeKind_Void,
  PrimitiveTypeKind_Signed,
  PrimitiveTypeKind_Unsigned,
  PrimitiveTypeKind_Floating,
  PrimitiveTypeKind_Char,
  PrimitiveTypeKind_Str,
} PrimitiveTypeKind;
