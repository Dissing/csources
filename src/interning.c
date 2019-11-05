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
typedef struct Sid Sid;
#line 2 "src/interning.z"
typedef struct Sid {
  u32 x;
} Sid;

typedef struct Interner Interner;
#line 6 "src/interning.z"
typedef struct Interner {
  StrMap *str_lookup;
  char **sid_lookup;
  u32 next_sid;
} Interner;

#line 12 "src/interning.z"
Interner interner_create() {
#line 13 "src/interning.z"
#line 13 "src/interning.z"
  Interner interner;

#line 14 "src/interning.z"
  interner.str_lookup = strmap_create(2048);
#line 15 "src/interning.z"
  interner.sid_lookup = calloc(8, 2048);
#line 16 "src/interning.z"
  interner.next_sid = 1;
#line 17 "src/interning.z"
  return interner;
}

#line 21 "src/interning.z"
Sid intern(Interner *self, char *string) {
#line 22 "src/interning.z"
#line 22 "src/interning.z"
  Sid sid;

#line 23 "src/interning.z"
  sid.x = strmap_lookup(self->str_lookup, string);
#line 24 "src/interning.z"
  if ((sid.x == 0)) {
#line 26 "src/interning.z"
    sid.x = self->next_sid;
#line 27 "src/interning.z"
    self->next_sid = (self->next_sid + 1);
#line 29 "src/interning.z"
#line 29 "src/interning.z"
    u64 len = (strlen(string) + 1);

#line 30 "src/interning.z"
#line 30 "src/interning.z"
    char *copy = malloc(len);

#line 31 "src/interning.z"
    memcpy(copy, string, len);
#line 32 "src/interning.z"
    self->sid_lookup[sid.x] = copy;
#line 34 "src/interning.z"
    strmap_insert(self->str_lookup, copy, sid.x);
  };
#line 36 "src/interning.z"
  return sid;
}

#line 39 "src/interning.z"
char *get_str(Interner *self, Sid sid) {
#line 40 "src/interning.z"
  return self->sid_lookup[sid.x];
}
