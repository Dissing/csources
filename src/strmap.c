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
#line 2 "src/strmap.z"
typedef struct StrMap {
  char **keys;
  u32 *values;
  u64 size;
  u64 load;
} StrMap;

#line 9 "src/strmap.z"
StrMap *strmap_create(u64 size) {
#line 10 "src/strmap.z"
#line 10 "src/strmap.z"
  StrMap *map = malloc(sizeof(StrMap));

#line 12 "src/strmap.z"
  map->size = size;
#line 13 "src/strmap.z"
  map->load = 0;
#line 14 "src/strmap.z"
  map->keys = malloc((size * 8));
#line 15 "src/strmap.z"
  map->values = malloc((size * 4));
#line 17 "src/strmap.z"
#line 17 "src/strmap.z"
  u32 i = 0;

#line 18 "src/strmap.z"
  while ((i < size)) {
#line 19 "src/strmap.z"
    map->keys[i] = 0;
#line 20 "src/strmap.z"
    map->values[i] = null;
#line 21 "src/strmap.z"
    i = (i + 1);
  };
#line 24 "src/strmap.z"
  return map;
}

#line 27 "src/strmap.z"
u32 strmap_hash(char *s) {
#line 28 "src/strmap.z"
#line 28 "src/strmap.z"
  u32 hash = 5381;

#line 29 "src/strmap.z"
#line 29 "src/strmap.z"
  i32 c = *s;

#line 30 "src/strmap.z"
  while ((c != 0)) {
#line 31 "src/strmap.z"
    hash = (((hash << 5) + hash) + c);
#line 32 "src/strmap.z"
    s = (s + 1);
#line 33 "src/strmap.z"
    c = *s;
  };
#line 35 "src/strmap.z"
  if ((hash != null)) {
#line 35 "src/strmap.z"
    return hash;
  } else {
#line 36 "src/strmap.z"
    return 1;
  };
}

#line 39 "src/strmap.z"
void strmap_insert(StrMap *map, char *key, u32 value) {
#line 40 "src/strmap.z"
#line 40 "src/strmap.z"
  u32 h = (strmap_hash(key) % map->size);

#line 41 "src/strmap.z"
  if (((map->load + 1) >= map->size)) {
#line 42 "src/strmap.z"
    printf("Hashmap of size %lu is full!\n", map->size);
#line 43 "src/strmap.z"
    exit(-1);
  };
#line 45 "src/strmap.z"
  while (true) {
#line 46 "src/strmap.z"
    if (((map->keys[h] != null) && !strcmp(map->keys[h], key))) {
#line 47 "src/strmap.z"
      map->values[h] = value;
#line 48 "src/strmap.z"
      break;
    } else {
#line 49 "src/strmap.z"
      if ((map->keys[h] == null)) {
#line 50 "src/strmap.z"
        map->keys[h] = key;
#line 51 "src/strmap.z"
        map->values[h] = value;
#line 52 "src/strmap.z"
        map->load = (map->load + 1);
#line 53 "src/strmap.z"
        break;
      } else {
#line 55 "src/strmap.z"
        h = ((h + 1) % map->size);
      };
    };
  };
}

#line 60 "src/strmap.z"
u32 strmap_lookup(StrMap *map, char *key) {
#line 61 "src/strmap.z"
#line 61 "src/strmap.z"
  u32 h = (strmap_hash(key) % map->size);

#line 62 "src/strmap.z"
  while (true) {
#line 63 "src/strmap.z"
    if ((map->keys[h] == null)) {
#line 63 "src/strmap.z"
      return null;
    };
#line 64 "src/strmap.z"
    if (!strcmp(map->keys[h], key)) {
#line 65 "src/strmap.z"
      return map->values[h];
    };
#line 67 "src/strmap.z"
    h = ((h + 1) % map->size);
  };
}

#line 71 "src/strmap.z"
void strmap_destroy(StrMap *map) {
#line 72 "src/strmap.z"
  free(map->keys);
#line 73 "src/strmap.z"
  free(map->values);
#line 74 "src/strmap.z"
  free(map);
}
