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
#line 1 "src/main.z"
char *basename(char *path);

#line 2 "src/main.z"
char *dirname(char *path);

#line 4 "src/main.z"
int main(int argc, char **argv) {
#line 5 "src/main.z"
  if ((argc != 3)) {
#line 6 "src/main.z"
    printf("Usage: compiler INPUT OUTPUT\n");
#line 7 "src/main.z"
    abort();
  };
#line 10 "src/main.z"
#line 10 "src/main.z"
  Session sess;

#line 13 "src/main.z"
  sess.interner = interner_create();
#line 14 "src/main.z"
  sess.source = source_map_create();
#line 15 "src/main.z"
#line 15 "src/main.z"
  char *root_module = basename(argv[1]);

#line 16 "src/main.z"
  sess.root_path = dirname(argv[1]);
#line 18 "src/main.z"
#line 18 "src/main.z"
  CompilationUnit unit = parse(&sess, root_module);

#line 20 "src/main.z"
  resolve(&sess, &unit);
#line 22 "src/main.z"
  generate(&sess, unit, argv[2]);
#line 24 "src/main.z"
  return 0;
}
