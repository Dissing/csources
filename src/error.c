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
#line 2 "src/error.z"
void emit_error(SourceMap *m, Span span, char *msg) {
#line 3 "src/error.z"
  printf("error: %s\n", msg);
#line 4 "src/error.z"
  source_snippet(m, span);
#line 5 "src/error.z"
  abort();
}
