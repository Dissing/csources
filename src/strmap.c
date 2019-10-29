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
typedef struct StrMap StrMap;
typedef struct StrMap {
  char **keys;
  u32 *values;
  u64 size;
  u64 load;
} StrMap;

StrMap *strmap_create(u64 size) {
  StrMap *map = malloc(sizeof(StrMap));

  map->size = size;
  map->load = 0;
  map->keys = malloc((size * 8));
  map->values = malloc((size * 4));
  u32 i = 0;

  while ((i < size)) {
    map->keys[i] = 0;
    map->values[i] = null;
    i = (i + 1);
  }
  return map;
}

u32 strmap_hash(char *s) {
  u32 hash = 5381;

  i32 c = *s;

  while ((c != 0)) {
    hash = (((hash << 5) + hash) + c);
    s = (s + 1);
    c = *s;
  }
  if ((hash != null)) {
    return hash;
  } else {
    return 1;
  };
}

void strmap_insert(StrMap *map, char *key, u32 value) {
  u32 h = (strmap_hash(key) % map->size);

  if (((map->load + 1) >= map->size)) {
    printf("Hashmap of size %lu is full!\n", map->size);
    exit(-1);
  };
  while (true) {
    if (((map->keys[h] != null) && !strcmp(map->keys[h], key))) {
      map->values[h] = value;
      break;
    } else {
      if ((map->keys[h] == null)) {
        map->keys[h] = key;
        map->values[h] = value;
        map->load = (map->load + 1);
        break;
      } else {
        h = ((h + 1) % map->size);
      };
    };
  }
}

u32 strmap_lookup(StrMap *map, char *key) {
  u32 h = (strmap_hash(key) % map->size);

  while (true) {
    if ((map->keys[h] == null)) {
      return null;
    };
    if (!strcmp(map->keys[h], key)) {
      return map->values[h];
    };
    h = ((h + 1) % map->size);
  }
}

void strmap_destroy(StrMap *map) {
  free(map->keys);
  free(map->values);
  free(map);
}
