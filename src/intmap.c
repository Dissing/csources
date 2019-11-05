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
typedef struct IntMap IntMap;
#line 2 "src/intmap.z"
typedef struct IntMap {
  u64 *keys;
  u64 *values;
  u64 size;
  u64 load;
} IntMap;

#line 9 "src/intmap.z"
IntMap *intmap_create(u64 size) {
#line 10 "src/intmap.z"
#line 10 "src/intmap.z"
  IntMap *map = malloc(sizeof(IntMap));

#line 12 "src/intmap.z"
  map->size = size;
#line 13 "src/intmap.z"
  map->load = 0;
#line 14 "src/intmap.z"
  map->keys = malloc((size * 8));
#line 15 "src/intmap.z"
  map->values = malloc((size * 8));
#line 17 "src/intmap.z"
#line 17 "src/intmap.z"
  u32 i = 0;

#line 18 "src/intmap.z"
  while ((i < size)) {
#line 19 "src/intmap.z"
    map->keys[i] = 0;
#line 20 "src/intmap.z"
    map->values[i] = null;
#line 21 "src/intmap.z"
    i = (i + 1);
  };
#line 24 "src/intmap.z"
  return map;
}

#line 27 "src/intmap.z"
u64 intmap_hash(u64 k) {
#line 28 "src/intmap.z"
  if ((k != null)) {
#line 28 "src/intmap.z"
    return k;
  } else {
#line 29 "src/intmap.z"
    return 1;
  };
}

#line 32 "src/intmap.z"
void intmap_reset(IntMap *map) {
#line 33 "src/intmap.z"
  map->load = 0;
#line 34 "src/intmap.z"
  memset(map->keys, 0, (sizeof(map->size) * 8));
#line 35 "src/intmap.z"
  memset(map->values, 0, (sizeof(map->size) * 8));
}

#line 38 "src/intmap.z"
void intmap_insert(IntMap *map, u64 key, u64 value) {
#line 39 "src/intmap.z"
#line 39 "src/intmap.z"
  u64 h = (intmap_hash(key) % map->size);

#line 40 "src/intmap.z"
  if (((map->load + 1) >= map->size)) {
#line 41 "src/intmap.z"
    printf("Hashmap of size %lu is full!\n", map->size);
#line 42 "src/intmap.z"
    exit(-1);
  };
#line 44 "src/intmap.z"
  while (true) {
#line 45 "src/intmap.z"
    if ((map->keys[h] == key)) {
#line 46 "src/intmap.z"
      map->values[h] = value;
#line 47 "src/intmap.z"
      break;
    } else {
#line 48 "src/intmap.z"
      if ((map->keys[h] == null)) {
#line 49 "src/intmap.z"
        map->keys[h] = key;
#line 50 "src/intmap.z"
        map->values[h] = value;
#line 51 "src/intmap.z"
        map->load = (map->load + 1);
#line 52 "src/intmap.z"
        break;
      } else {
#line 54 "src/intmap.z"
        h = ((h + 1) % map->size);
      };
    };
  };
}

#line 59 "src/intmap.z"
u64 intmap_lookup(IntMap *map, u64 key) {
#line 60 "src/intmap.z"
#line 60 "src/intmap.z"
  u64 h = (intmap_hash(key) % map->size);

#line 61 "src/intmap.z"
  while (true) {
#line 62 "src/intmap.z"
    if ((map->keys[h] == null)) {
#line 62 "src/intmap.z"
      return null;
    };
#line 63 "src/intmap.z"
    if ((map->keys[h] == key)) {
#line 64 "src/intmap.z"
      return map->values[h];
    };
#line 66 "src/intmap.z"
    h = ((h + 1) % map->size);
  };
}

#line 70 "src/intmap.z"
void intmap_destroy(IntMap *map) {
#line 71 "src/intmap.z"
  free(map->keys);
#line 72 "src/intmap.z"
  free(map->values);
#line 73 "src/intmap.z"
  free(map);
}
