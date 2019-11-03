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
typedef struct Sid Sid;
typedef struct Sid {
u32 x;
} Sid;


typedef struct Interner Interner;
typedef struct Interner {
StrMap * str_lookup;
char * * sid_lookup;
u32 next_sid;
} Interner;


Interner  interner_create() {
Interner interner ;

interner.str_lookup = strmap_create(2048) ;
interner.sid_lookup = calloc(8,2048) ;
interner.next_sid = 1;
return interner;
}

Sid  intern(Interner *  self, char *  string) {
Sid sid ;

sid.x = strmap_lookup(self->str_lookup,string) ;
if ((sid.x== 0)){
sid.x = self->next_sid;
self->next_sid = (self->next_sid+ 1);
u64 len = (strlen(string) + 1);

char * copy = malloc(len) ;

memcpy(copy,string,len) ;
self->sid_lookup[sid.x] = copy;
strmap_insert(self->str_lookup,copy,sid.x) ;
}
;
return sid;
}

char *  get_str(Interner *  self, Sid  sid) {
return self->sid_lookup[sid.x];
}

