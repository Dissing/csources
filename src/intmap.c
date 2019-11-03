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
typedef struct IntMap IntMap;
typedef struct IntMap {
u64 * keys;
u64 * values;
u64 size;
u64 load;
} IntMap;


IntMap *  intmap_create(u64  size) {
IntMap * map = malloc(sizeof(IntMap) ) ;

map->size = size;
map->load = 0;
map->keys = malloc((size* 8)) ;
map->values = malloc((size* 8)) ;
u32 i = 0;

while ( (i< size))
{
map->keys[i] = 0;
map->values[i] = null;
i = (i+ 1);
}
return map;
}

u64  intmap_hash(u64  k) {
if ((k!= null)){
return k;
}
else {
return 1;
}
;
}

void  intmap_reset(IntMap *  map) {
map->load = 0;
memset(map->keys,0,(sizeof(map->size) * 8)) ;
memset(map->values,0,(sizeof(map->size) * 8)) ;
}

void  intmap_insert(IntMap *  map, u64  key, u64  value) {
u64 h = (intmap_hash(key) % map->size);

if (((map->load+ 1)>= map->size)){
printf("Hashmap of size %lu is full!\n",map->size) ;
exit(-1) ;
}
;
while ( true)
{
if ((map->keys[h]== key)){
map->values[h] = value;
break;
}
else {
if ((map->keys[h]== null)){
map->keys[h] = key;
map->values[h] = value;
map->load = (map->load+ 1);
break;
}
else {
h = ((h+ 1)% map->size);
}
;
}
;
}
}

u64  intmap_lookup(IntMap *  map, u64  key) {
u64 h = (intmap_hash(key) % map->size);

while ( true)
{
if ((map->keys[h]== null)){
return null;
}
;
if ((map->keys[h]== key)){
return map->values[h];
}
;
h = ((h+ 1)% map->size);
}
}

void  intmap_destroy(IntMap *  map) {
free(map->keys) ;
free(map->values) ;
free(map) ;
}

