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
void load_file_content(char *path, char **ptr, u64 *length) {
  FILE *fp = fopen(path, "rb");

  fseek(fp, 0, SEEK_END);
  *length = ftell(fp);
  rewind(fp);
  *ptr = malloc(*length);
  fread(*ptr, 1, *length, fp);
  fclose(fp);
}

int main(int argc, char **argv) {
  if ((argc != 3)) {
    printf("Usage: compiler INPUT OUTPUT\n");
    abort();
  };
  char *content;

  u64 length;

  load_file_content(argv[1], &content, &length);
  Token *tokens;

  u32 num_tokens;

  lex(content, length, &tokens, &num_tokens);
  u32 num_ast_items;

  AstItem **ast_items = parse(tokens, num_tokens, &num_ast_items);

  u32 num_items;

  Item **items = lower(ast_items, num_ast_items, &num_items);

  generate(items, num_items, argv[2]);
  return 0;
}
