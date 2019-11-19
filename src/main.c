//Prelude
#include <stdint.h>
#include <stdbool.h>
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
typedef const char constchar;
typedef const void constvoid;
#line 2 "src/cstd.z"
void*  malloc(u64 size) ;

#line 3 "src/cstd.z"
void*  calloc(u64 size, u64 count) ;

#line 4 "src/cstd.z"
void  free(void*  ptr) ;

#line 6 "src/cstd.z"
void*  memset(void*  dest, i32 ch, u64 size) ;

#line 7 "src/cstd.z"
void*  memcpy(void*  dest, constvoid*  src, u64 size) ;

#line 8 "src/cstd.z"
i32 strcmp(constchar*  lhs, constchar*  rhs) ;

#line 9 "src/cstd.z"
u64 strlen(constchar*  str) ;

#line 10 "src/cstd.z"
char*  strtok(char*  str, constchar*  delim) ;

#line 12 "src/cstd.z"
f64 atof(constchar*  str) ;

#line 13 "src/cstd.z"
i64 atol(constchar*  str) ;

#line 15 "src/cstd.z"
void  abort() ;

#line 16 "src/cstd.z"
void  exit(i32 status) ;

typedef struct _ZN4main4cstd4FILEE _ZN4main4cstd4FILEE;
#line 18 "src/cstd.z"

#line 20 "src/cstd.z"
_ZN4main4cstd4FILEE*  fopen(constchar*  filename, constchar*  mode) ;

#line 21 "src/cstd.z"
i32 fclose(_ZN4main4cstd4FILEE*  stream) ;

#line 23 "src/cstd.z"
u64 fread(void*  buffer, u64 size, u64 count, _ZN4main4cstd4FILEE*  stream) ;

#line 24 "src/cstd.z"
u64 fwrite(constvoid*  buffer, u64 size, u64 count, _ZN4main4cstd4FILEE*  stream) ;

#line 26 "src/cstd.z"
i32 fseek(_ZN4main4cstd4FILEE*  stream, i64 offset, i32 origin) ;

#line 27 "src/cstd.z"
void  rewind(_ZN4main4cstd4FILEE*  stream) ;

#line 28 "src/cstd.z"
i64 ftell(_ZN4main4cstd4FILEE*  stream) ;

#line 30 "src/cstd.z"
i32 _ZN4main4cstd8SEEK_SETE= 0;

#line 31 "src/cstd.z"
i32 _ZN4main4cstd8SEEK_CURE= 1;

#line 32 "src/cstd.z"
i32 _ZN4main4cstd8SEEK_ENDE= 2;

#line 34 "src/cstd.z"
i32 printf(constchar*  format, ...) ;

#line 35 "src/cstd.z"
i32 fprintf(_ZN4main4cstd4FILEE*  stream, constchar*  format, ...) ;

#line 36 "src/cstd.z"
i32 sprintf(char*  buffer, constchar*  format, ...) ;

#line 38 "src/cstd.z"
void*  _ZN4main4cstd4nullE= 0;

#line 39 "src/cstd.z"
i32 _ZN4main4cstd3EOFE= -1;



typedef struct _ZN4main6intmap6IntMapE _ZN4main6intmap6IntMapE;
#line 4 "src/intmap.z"
typedef struct _ZN4main6intmap6IntMapE {
u64*  keys;
u64*  values;
u64 size;
u64 load;
} _ZN4main6intmap6IntMapE;


#line 11 "src/intmap.z"
_ZN4main6intmap6IntMapE*  _ZN4main6intmap13intmap_createE(u64 size) {
#line 12 "src/intmap.z"
_ZN4main6intmap6IntMapE*  map = malloc(sizeof(_ZN4main6intmap6IntMapE)) ;
;
#line 14 "src/intmap.z"
map->size = size;
;
#line 15 "src/intmap.z"
map->load = 0;
;
#line 16 "src/intmap.z"
map->keys = malloc((size* 8)) ;
;
#line 17 "src/intmap.z"
map->values = malloc((size* 8)) ;
;
#line 19 "src/intmap.z"
u32 i = 0;
;
#line 20 "src/intmap.z"
while ( (i< size))
{
#line 21 "src/intmap.z"
map->keys[i] = 0;
;
#line 22 "src/intmap.z"
map->values[i] = 0;
;
#line 23 "src/intmap.z"
i = (i+ 1);
;
}
;
#line 26 "src/intmap.z"
return map;
;
}

#line 29 "src/intmap.z"
u64 _ZN4main6intmap11intmap_hashE(u64 k) {
#line 30 "src/intmap.z"
if ((k!= 0)){
#line 30 "src/intmap.z"
return k;
;
}
else {
#line 31 "src/intmap.z"
return 1;
;
}
;
}

#line 34 "src/intmap.z"
void  _ZN4main6intmap12intmap_resetE(_ZN4main6intmap6IntMapE*  map) {
#line 35 "src/intmap.z"
map->load = 0;
;
#line 36 "src/intmap.z"
memset(map->keys,0,(sizeof(map->size)* 8)) ;
#line 37 "src/intmap.z"
memset(map->values,0,(sizeof(map->size)* 8)) ;
}

#line 40 "src/intmap.z"
void  _ZN4main6intmap13intmap_insertE(_ZN4main6intmap6IntMapE*  map, u64 key, u64 value) {
#line 41 "src/intmap.z"
u64 h = (_ZN4main6intmap11intmap_hashE(key) % map->size);
;
#line 42 "src/intmap.z"
if (((map->load+ 1)>= map->size)){
#line 43 "src/intmap.z"
printf("Hashmap of size %lu is full!\n",map->size) ;
#line 44 "src/intmap.z"
exit(-1) ;
}
;
#line 46 "src/intmap.z"
while ( true)
{
#line 47 "src/intmap.z"
if ((map->keys[h]== key)){
#line 48 "src/intmap.z"
map->values[h] = value;
;
#line 49 "src/intmap.z"
break;
;
}
else {
#line 50 "src/intmap.z"
if ((map->keys[h]== 0)){
#line 51 "src/intmap.z"
map->keys[h] = key;
;
#line 52 "src/intmap.z"
map->values[h] = value;
;
#line 53 "src/intmap.z"
map->load = (map->load+ 1);
;
#line 54 "src/intmap.z"
break;
;
}
else {
#line 56 "src/intmap.z"
h = ((h+ 1)% map->size);
;
}
;
}
;
}
;
}

#line 61 "src/intmap.z"
u64 _ZN4main6intmap13intmap_lookupE(_ZN4main6intmap6IntMapE*  map, u64 key) {
#line 62 "src/intmap.z"
u64 h = (_ZN4main6intmap11intmap_hashE(key) % map->size);
;
#line 63 "src/intmap.z"
while ( true)
{
#line 64 "src/intmap.z"
if ((map->keys[h]== 0)){
#line 64 "src/intmap.z"
return 0;
;
}
;
#line 65 "src/intmap.z"
if ((map->keys[h]== key)){
#line 66 "src/intmap.z"
return map->values[h];
;
}
;
#line 68 "src/intmap.z"
h = ((h+ 1)% map->size);
;
}
;
}

#line 72 "src/intmap.z"
void  _ZN4main6intmap14intmap_destroyE(_ZN4main6intmap6IntMapE*  map) {
#line 73 "src/intmap.z"
free(map->keys) ;
#line 74 "src/intmap.z"
free(map->values) ;
#line 75 "src/intmap.z"
free(map) ;
}



typedef struct _ZN4main6strmap6StrMapE _ZN4main6strmap6StrMapE;
#line 4 "src/strmap.z"
typedef struct _ZN4main6strmap6StrMapE {
char* *  keys;
u32*  values;
u64 size;
u64 load;
} _ZN4main6strmap6StrMapE;


#line 11 "src/strmap.z"
_ZN4main6strmap6StrMapE*  _ZN4main6strmap13strmap_createE(u64 size) {
#line 12 "src/strmap.z"
_ZN4main6strmap6StrMapE*  map = malloc(sizeof(_ZN4main6strmap6StrMapE)) ;
;
#line 14 "src/strmap.z"
map->size = size;
;
#line 15 "src/strmap.z"
map->load = 0;
;
#line 16 "src/strmap.z"
map->keys = malloc((size* 8)) ;
;
#line 17 "src/strmap.z"
map->values = malloc((size* 4)) ;
;
#line 19 "src/strmap.z"
u32 i = 0;
;
#line 20 "src/strmap.z"
while ( (i< size))
{
#line 21 "src/strmap.z"
map->keys[i] = 0;
;
#line 22 "src/strmap.z"
map->values[i] = 0;
;
#line 23 "src/strmap.z"
i = (i+ 1);
;
}
;
#line 26 "src/strmap.z"
return map;
;
}

#line 29 "src/strmap.z"
u32 _ZN4main6strmap11strmap_hashE(char*  s) {
#line 30 "src/strmap.z"
u32 hash = 5381;
;
#line 31 "src/strmap.z"
i32 c = *s;
;
#line 32 "src/strmap.z"
while ( (c!= 0))
{
#line 33 "src/strmap.z"
hash = (((hash<< 5)+ hash)+ c);
;
#line 34 "src/strmap.z"
s = (s+ 1);
;
#line 35 "src/strmap.z"
c = *s;
;
}
;
#line 37 "src/strmap.z"
if ((hash!= 0)){
#line 37 "src/strmap.z"
return hash;
;
}
else {
#line 38 "src/strmap.z"
return 1;
;
}
;
}

#line 41 "src/strmap.z"
void  _ZN4main6strmap13strmap_insertE(_ZN4main6strmap6StrMapE*  map, char*  key, u32 value) {
#line 42 "src/strmap.z"
u32 h = (_ZN4main6strmap11strmap_hashE(key) % map->size);
;
#line 43 "src/strmap.z"
if (((map->load+ 1)>= map->size)){
#line 44 "src/strmap.z"
printf("Hashmap of size %lu is full!\n",map->size) ;
#line 45 "src/strmap.z"
exit(-1) ;
}
;
#line 47 "src/strmap.z"
while ( true)
{
#line 48 "src/strmap.z"
if (((map->keys[h]!= 0)&& !strcmp(map->keys[h],key) )){
#line 49 "src/strmap.z"
map->values[h] = value;
;
#line 50 "src/strmap.z"
break;
;
}
else {
#line 51 "src/strmap.z"
if ((map->keys[h]== 0)){
#line 52 "src/strmap.z"
map->keys[h] = key;
;
#line 53 "src/strmap.z"
map->values[h] = value;
;
#line 54 "src/strmap.z"
map->load = (map->load+ 1);
;
#line 55 "src/strmap.z"
break;
;
}
else {
#line 57 "src/strmap.z"
h = ((h+ 1)% map->size);
;
}
;
}
;
}
;
}

#line 62 "src/strmap.z"
u32 _ZN4main6strmap13strmap_lookupE(_ZN4main6strmap6StrMapE*  map, char*  key) {
#line 63 "src/strmap.z"
u32 h = (_ZN4main6strmap11strmap_hashE(key) % map->size);
;
#line 64 "src/strmap.z"
while ( true)
{
#line 65 "src/strmap.z"
if ((map->keys[h]== 0)){
#line 65 "src/strmap.z"
return 0;
;
}
;
#line 66 "src/strmap.z"
if (!strcmp(map->keys[h],key) ){
#line 67 "src/strmap.z"
return map->values[h];
;
}
;
#line 69 "src/strmap.z"
h = ((h+ 1)% map->size);
;
}
;
}

#line 73 "src/strmap.z"
void  _ZN4main6strmap14strmap_destroyE(_ZN4main6strmap6StrMapE*  map) {
#line 74 "src/strmap.z"
free(map->keys) ;
#line 75 "src/strmap.z"
free(map->values) ;
#line 76 "src/strmap.z"
free(map) ;
}



typedef struct _ZN4main10source_map4SpanE _ZN4main10source_map4SpanE;
#line 3 "src/source_map.z"
typedef struct _ZN4main10source_map4SpanE {
u32 from;
u32 to;
} _ZN4main10source_map4SpanE;


typedef struct _ZN4main10source_map10SourceFileE _ZN4main10source_map10SourceFileE;
#line 8 "src/source_map.z"
typedef struct _ZN4main10source_map10SourceFileE {
char*  name;
char*  content;
u32 length;
u32 start;
u32 end;
u32*  lines;
u32 num_lines;
} _ZN4main10source_map10SourceFileE;


typedef struct _ZN4main10source_map9SourceMapE _ZN4main10source_map9SourceMapE;
#line 18 "src/source_map.z"
typedef struct _ZN4main10source_map9SourceMapE {
_ZN4main10source_map10SourceFileE*  files;
u32 num_files;
u32*  file_starts;
} _ZN4main10source_map9SourceMapE;


#line 24 "src/source_map.z"
_ZN4main10source_map9SourceMapE _ZN4main10source_map17source_map_createE() {
#line 25 "src/source_map.z"
_ZN4main10source_map9SourceMapE map ;
;
#line 26 "src/source_map.z"
map.files = calloc(sizeof(_ZN4main10source_map10SourceFileE),64) ;
;
#line 27 "src/source_map.z"
map.num_files = 0;
;
#line 28 "src/source_map.z"
map.file_starts = calloc(sizeof(u32),64) ;
;
#line 30 "src/source_map.z"
return map;
;
}

#line 33 "src/source_map.z"
void  _ZN4main10source_map17load_file_contentE(_ZN4main10source_map10SourceFileE*  file) {
#line 34 "src/source_map.z"
_ZN4main4cstd4FILEE*  fp = fopen(file->name,"rb") ;
;
#line 35 "src/source_map.z"
fseek(fp,0,_ZN4main4cstd8SEEK_ENDE) ;
#line 36 "src/source_map.z"
file->length = ftell(fp) ;
;
#line 37 "src/source_map.z"
rewind(fp) ;
#line 38 "src/source_map.z"
file->content = malloc(file->length) ;
;
#line 39 "src/source_map.z"
fread(file->content,1,file->length,fp) ;
#line 40 "src/source_map.z"
fclose(fp) ;
}

#line 43 "src/source_map.z"
_ZN4main10source_map10SourceFileE*  _ZN4main10source_map19source_map_new_fileE(_ZN4main10source_map9SourceMapE*  self, char*  path, char*  filename) {
#line 44 "src/source_map.z"
_ZN4main10source_map10SourceFileE*  file = &self->files[self->num_files];
;
#line 45 "src/source_map.z"
self->num_files = (self->num_files+ 1);
;
#line 47 "src/source_map.z"
u32 needed_length = ((strlen(path) + strlen(filename) )+ 4);
;
#line 49 "src/source_map.z"
char*  name_buffer = malloc(needed_length) ;
;
#line 51 "src/source_map.z"
sprintf(name_buffer,"%s/%s.z",path,filename) ;
#line 53 "src/source_map.z"
file->name = name_buffer;
;
#line 54 "src/source_map.z"
file->lines = calloc(sizeof(u32),4096) ;
;
#line 55 "src/source_map.z"
file->num_lines = 1;
;
#line 57 "src/source_map.z"
if ((self->num_files> 1)){
#line 57 "src/source_map.z"
file->start = self->files[(self->num_files- 2)].end;
;
}
else {
#line 58 "src/source_map.z"
file->start = 0;
;
}
;
#line 60 "src/source_map.z"
self->file_starts[(self->num_files- 1)] = file->start;
;
#line 62 "src/source_map.z"
_ZN4main10source_map17load_file_contentE(file) ;
#line 64 "src/source_map.z"
return file;
;
}

#line 67 "src/source_map.z"
void  _ZN4main10source_map19source_file_newlineE(_ZN4main10source_map10SourceFileE*  self, u32 position) {
#line 68 "src/source_map.z"
self->lines[self->num_lines] = (self->start+ position);
;
#line 69 "src/source_map.z"
self->num_lines = (self->num_lines+ 1);
;
}

#line 72 "src/source_map.z"
void  _ZN4main10source_map16source_file_doneE(_ZN4main10source_map10SourceFileE*  self, u32 length) {
#line 73 "src/source_map.z"
self->end = (self->start+ length);
;
}

#line 76 "src/source_map.z"
_ZN4main10source_map10SourceFileE*  _ZN4main10source_map15source_map_infoE(_ZN4main10source_map9SourceMapE*  m, _ZN4main10source_map4SpanE span, u32*  first, u32*  last) {
#line 77 "src/source_map.z"
u32 i = 0;
;
#line 78 "src/source_map.z"
_ZN4main10source_map10SourceFileE*  file = 0;
;
#line 79 "src/source_map.z"
while ( (i< m->num_files))
{
#line 80 "src/source_map.z"
if ((m->file_starts[i]> span.from)){
#line 80 "src/source_map.z"
break;
;
}
;
#line 81 "src/source_map.z"
file = &m->files[i];
;
#line 82 "src/source_map.z"
i = (i+ 1);
;
}
;
#line 85 "src/source_map.z"
if (!file){
#line 85 "src/source_map.z"
abort() ;
}
;
#line 87 "src/source_map.z"
i = 0;
;
#line 88 "src/source_map.z"
while ( (i< file->num_lines))
{
#line 89 "src/source_map.z"
if ((file->lines[i]<= span.from)){
#line 90 "src/source_map.z"
*first = i;
;
}
else {
#line 92 "src/source_map.z"
break;
;
}
;
#line 93 "src/source_map.z"
i = (i+ 1);
;
}
;
#line 95 "src/source_map.z"
i = (i- 1);
;
#line 96 "src/source_map.z"
while ( (i< file->num_lines))
{
#line 97 "src/source_map.z"
if ((file->lines[i]<= span.to)){
#line 98 "src/source_map.z"
*last = i;
;
}
else {
#line 100 "src/source_map.z"
break;
;
}
;
#line 101 "src/source_map.z"
i = (i+ 1);
;
}
;
#line 104 "src/source_map.z"
return file;
;
}

#line 107 "src/source_map.z"
void  _ZN4main10source_map19emit_line_directiveE(_ZN4main4cstd4FILEE*  fp, _ZN4main10source_map9SourceMapE*  m, _ZN4main10source_map4SpanE span) {
#line 108 "src/source_map.z"
u32 line_first ;
;
#line 109 "src/source_map.z"
u32 line_end ;
;
#line 111 "src/source_map.z"
_ZN4main10source_map10SourceFileE*  file = _ZN4main10source_map15source_map_infoE(m,span,&line_first,&line_end) ;
;
#line 113 "src/source_map.z"
fprintf(fp,"#line %u \"%s\"\n",(line_first+ 1),file->name) ;
}

#line 116 "src/source_map.z"
void  _ZN4main10source_map14source_snippetE(_ZN4main10source_map9SourceMapE*  m, _ZN4main10source_map4SpanE span) {
#line 118 "src/source_map.z"
u32 line_first ;
;
#line 119 "src/source_map.z"
u32 line_last ;
;
#line 121 "src/source_map.z"
_ZN4main10source_map10SourceFileE*  file = _ZN4main10source_map15source_map_infoE(m,span,&line_first,&line_last) ;
;
#line 123 "src/source_map.z"
printf("%s:%u\n",file->name,(line_first+ 1)) ;
#line 125 "src/source_map.z"
char*  buffer = malloc(1024) ;
;
#line 126 "src/source_map.z"
u32 i = line_first;
;
#line 127 "src/source_map.z"
while ( (i<= line_last))
{
#line 128 "src/source_map.z"
u32 line_start = file->lines[i];
;
#line 129 "src/source_map.z"
u32 line_end = file->lines[(i+ 1)];
;
#line 130 "src/source_map.z"
u32 length = (line_end- line_start);
;
#line 131 "src/source_map.z"
memcpy(buffer,&file->content[((line_start+ 1)- file->start)],length) ;
#line 132 "src/source_map.z"
buffer[(length+ 1)] = 0;
;
#line 133 "src/source_map.z"
printf("%s\n",buffer) ;
#line 134 "src/source_map.z"
i = (i+ 1);
;
}
;
}




#line 4 "src/error.z"
void  _ZN4main5error10emit_errorE(_ZN4main10source_map9SourceMapE*  m, _ZN4main10source_map4SpanE span, char*  msg) {
#line 5 "src/error.z"
printf("error: %s\n",msg) ;
#line 6 "src/error.z"
_ZN4main10source_map14source_snippetE(m,span) ;
#line 7 "src/error.z"
abort() ;
}

#line 11 "src/error.z"
void  _ZN4main5error12emit_warningE(_ZN4main10source_map9SourceMapE*  m, _ZN4main10source_map4SpanE span, char*  msg) {
#line 12 "src/error.z"
printf("warning: %s\n",msg) ;
#line 13 "src/error.z"
_ZN4main10source_map14source_snippetE(m,span) ;
}




typedef struct _ZN4main9interning3SidE _ZN4main9interning3SidE;
#line 4 "src/interning.z"
typedef struct _ZN4main9interning3SidE {
u32 x;
} _ZN4main9interning3SidE;


typedef struct _ZN4main9interning8InternerE _ZN4main9interning8InternerE;
#line 8 "src/interning.z"
typedef struct _ZN4main9interning8InternerE {
_ZN4main6strmap6StrMapE*  str_lookup;
char* *  sid_lookup;
u32 next_sid;
} _ZN4main9interning8InternerE;


#line 14 "src/interning.z"
_ZN4main9interning8InternerE _ZN4main9interning15interner_createE() {
#line 15 "src/interning.z"
_ZN4main9interning8InternerE interner ;
;
#line 16 "src/interning.z"
interner.str_lookup = _ZN4main6strmap13strmap_createE(2048) ;
;
#line 17 "src/interning.z"
interner.sid_lookup = calloc(8,2048) ;
;
#line 18 "src/interning.z"
interner.next_sid = 1;
;
#line 19 "src/interning.z"
return interner;
;
}

#line 23 "src/interning.z"
_ZN4main9interning3SidE _ZN4main9interning6internE(_ZN4main9interning8InternerE*  self, char*  string) {
#line 24 "src/interning.z"
_ZN4main9interning3SidE sid ;
;
#line 25 "src/interning.z"
sid.x = _ZN4main6strmap13strmap_lookupE(self->str_lookup,string) ;
;
#line 26 "src/interning.z"
if ((sid.x== 0)){
#line 28 "src/interning.z"
sid.x = self->next_sid;
;
#line 29 "src/interning.z"
self->next_sid = (self->next_sid+ 1);
;
#line 31 "src/interning.z"
u64 len = (strlen(string) + 1);
;
#line 32 "src/interning.z"
char*  copy = malloc(len) ;
;
#line 33 "src/interning.z"
memcpy(copy,string,len) ;
#line 34 "src/interning.z"
self->sid_lookup[sid.x] = copy;
;
#line 36 "src/interning.z"
_ZN4main6strmap13strmap_insertE(self->str_lookup,copy,sid.x) ;
}
;
#line 38 "src/interning.z"
return sid;
;
}

#line 41 "src/interning.z"
char*  _ZN4main9interning7get_strE(_ZN4main9interning8InternerE*  self, _ZN4main9interning3SidE sid) {
#line 42 "src/interning.z"
return self->sid_lookup[sid.x];
;
}




typedef struct _ZN4main7session7SessionE _ZN4main7session7SessionE;
#line 5 "src/session.z"
typedef struct _ZN4main7session7SessionE {
_ZN4main9interning8InternerE interner;
_ZN4main10source_map9SourceMapE source;
char*  root_path;
} _ZN4main7session7SessionE;





#line 5 "src/tokens.z"
typedef enum _ZN4main6tokens9TokenKindE {
TokenKind_Invalid,
TokenKind_Identifier,
TokenKind_EOF,
TokenKind_Break,
TokenKind_Const,
TokenKind_Continue,
TokenKind_Defer,
TokenKind_Enum,
TokenKind_Else,
TokenKind_Extern,
TokenKind_Fn,
TokenKind_For,
TokenKind_If,
TokenKind_Mod,
TokenKind_Return,
TokenKind_Static,
TokenKind_Struct,
TokenKind_Sizeof,
TokenKind_Union,
TokenKind_Use,
TokenKind_Var,
TokenKind_Val,
TokenKind_While,
TokenKind_Plus,
TokenKind_Minus,
TokenKind_Star,
TokenKind_Slash,
TokenKind_Percent,
TokenKind_LessLess,
TokenKind_GreaterGreater,
TokenKind_And,
TokenKind_AndAnd,
TokenKind_Or,
TokenKind_OrOr,
TokenKind_Hat,
TokenKind_Equal,
TokenKind_Bang,
TokenKind_BangEqual,
TokenKind_EqualEqual,
TokenKind_Less,
TokenKind_Greater,
TokenKind_LessEqual,
TokenKind_GreaterEqual,
TokenKind_LeftParen,
TokenKind_RightParen,
TokenKind_LeftBracket,
TokenKind_RightBracket,
TokenKind_LeftCurly,
TokenKind_RightCurly,
TokenKind_Comma,
TokenKind_Dot,
TokenKind_Colon,
TokenKind_ColonColon,
TokenKind_Semicolon,
TokenKind_Arrow,
TokenKind_Ellipsis,
TokenKind_Integer,
TokenKind_Float,
TokenKind_Char,
TokenKind_String,
TokenKind_True,
TokenKind_False,
} _ZN4main6tokens9TokenKindE;


typedef struct _ZN4main6tokens5TokenE _ZN4main6tokens5TokenE;
#line 74 "src/tokens.z"
typedef struct _ZN4main6tokens5TokenE {
_ZN4main6tokens9TokenKindE kind;
_ZN4main10source_map4SpanE span;
_ZN4main9interning3SidE lexeme;
} _ZN4main6tokens5TokenE;








typedef struct _ZN4main5lexer13LexingContextE _ZN4main5lexer13LexingContextE;
#line 8 "src/lexer.z"
typedef struct _ZN4main5lexer13LexingContextE {
u32 start;
u32 current;
u32 line;
u32 file_span_offset;
_ZN4main10source_map10SourceFileE*  source;
_ZN4main6tokens5TokenE*  tokens;
u32 current_token_idx;
_ZN4main7session7SessionE*  sess;
char*  lexeme_buffer;
} _ZN4main5lexer13LexingContextE;


#line 20 "src/lexer.z"
bool _ZN4main5lexer13is_alphabeticE(char c) {
#line 21 "src/lexer.z"
return (((c>= 'A')&& (c<= 'Z'))|| ((c>= 'a')&& (c<= 'z')));
;
}

#line 24 "src/lexer.z"
bool _ZN4main5lexer8is_digitE(char c) {
#line 25 "src/lexer.z"
return ((c>= '0')&& (c<= '9'));
;
}

#line 28 "src/lexer.z"
bool _ZN4main5lexer15is_alphanumericE(char c) {
#line 29 "src/lexer.z"
return (_ZN4main5lexer13is_alphabeticE(c) || _ZN4main5lexer8is_digitE(c) );
;
}

#line 32 "src/lexer.z"
bool _ZN4main5lexer14is_done_lexingE(_ZN4main5lexer13LexingContextE*  ctx) {
#line 33 "src/lexer.z"
_ZN4main10source_map10SourceFileE*  source = ctx->source;
;
#line 34 "src/lexer.z"
return (ctx->current>= source->length);
;
}

#line 37 "src/lexer.z"
char _ZN4main5lexer10peek_tokenE(_ZN4main5lexer13LexingContextE*  ctx, u32 offset) {
#line 38 "src/lexer.z"
if (_ZN4main5lexer14is_done_lexingE(ctx) ){
#line 38 "src/lexer.z"
return 0;
;
}
;
#line 39 "src/lexer.z"
_ZN4main10source_map10SourceFileE*  source = ctx->source;
;
#line 40 "src/lexer.z"
return source->content[(ctx->current+ offset)];
;
}

#line 43 "src/lexer.z"
char _ZN4main5lexer7advanceE(_ZN4main5lexer13LexingContextE*  ctx) {
#line 44 "src/lexer.z"
ctx->current = (ctx->current+ 1);
;
#line 45 "src/lexer.z"
_ZN4main10source_map10SourceFileE*  source = ctx->source;
;
#line 46 "src/lexer.z"
return source->content[(ctx->current- 1)];
;
}

#line 49 "src/lexer.z"
void  _ZN4main5lexer9add_tokenE(_ZN4main5lexer13LexingContextE*  ctx, _ZN4main6tokens9TokenKindE kind, _ZN4main9interning3SidE lexeme) {
#line 50 "src/lexer.z"
_ZN4main6tokens5TokenE token ;
;
#line 51 "src/lexer.z"
token.kind = kind;
;
#line 52 "src/lexer.z"
token.lexeme = lexeme;
;
#line 53 "src/lexer.z"
token.span.from = (ctx->start+ ctx->file_span_offset);
;
#line 54 "src/lexer.z"
token.span.to = (ctx->current+ ctx->file_span_offset);
;
#line 55 "src/lexer.z"
ctx->tokens[ctx->current_token_idx] = token;
;
#line 56 "src/lexer.z"
ctx->current_token_idx = (ctx->current_token_idx+ 1);
;
}

#line 59 "src/lexer.z"
void  _ZN4main5lexer16add_simple_tokenE(_ZN4main5lexer13LexingContextE*  ctx, _ZN4main6tokens9TokenKindE kind) {
#line 60 "src/lexer.z"
_ZN4main9interning3SidE null_sid ;
;
#line 61 "src/lexer.z"
null_sid.x = 0;
;
#line 62 "src/lexer.z"
_ZN4main5lexer9add_tokenE(ctx,kind,null_sid) ;
}

#line 65 "src/lexer.z"
void  _ZN4main5lexer31add_lookahead_conditional_tokenE(_ZN4main5lexer13LexingContextE*  ctx, char expect, _ZN4main6tokens9TokenKindE first, _ZN4main6tokens9TokenKindE second) {
#line 66 "src/lexer.z"
_ZN4main6tokens9TokenKindE kind ;
;
#line 67 "src/lexer.z"
if ((_ZN4main5lexer10peek_tokenE(ctx,0) == expect)){
#line 68 "src/lexer.z"
_ZN4main5lexer7advanceE(ctx) ;
#line 69 "src/lexer.z"
kind = first;
;
}
else {
#line 71 "src/lexer.z"
kind = second;
;
}
;
#line 73 "src/lexer.z"
_ZN4main9interning3SidE null_sid ;
;
#line 74 "src/lexer.z"
null_sid.x = 0;
;
#line 75 "src/lexer.z"
_ZN4main5lexer9add_tokenE(ctx,kind,null_sid) ;
}

#line 78 "src/lexer.z"
void  _ZN4main5lexer12read_newlineE(_ZN4main5lexer13LexingContextE*  ctx) {
#line 79 "src/lexer.z"
_ZN4main10source_map19source_file_newlineE(ctx->source,ctx->start) ;
}

#line 82 "src/lexer.z"
_ZN4main9interning3SidE _ZN4main5lexer10get_lexemeE(_ZN4main5lexer13LexingContextE*  ctx, u32 start_offset, u32 end_offset) {
#line 83 "src/lexer.z"
u32 str_len = (ctx->current- ((ctx->start+ start_offset)+ end_offset));
;
#line 84 "src/lexer.z"
_ZN4main10source_map10SourceFileE*  source = ctx->source;
;
#line 85 "src/lexer.z"
memcpy(ctx->lexeme_buffer,&source->content[(ctx->start+ start_offset)],str_len) ;
#line 86 "src/lexer.z"
ctx->lexeme_buffer[str_len] = 0;
;
#line 87 "src/lexer.z"
_ZN4main7session7SessionE*  sess = ctx->sess;
;
#line 88 "src/lexer.z"
_ZN4main9interning3SidE sid = _ZN4main9interning6internE(&sess->interner,ctx->lexeme_buffer) ;
;
#line 90 "src/lexer.z"
return sid;
;
}

#line 93 "src/lexer.z"
void  _ZN4main5lexer19single_line_commentE(_ZN4main5lexer13LexingContextE*  ctx) {
#line 94 "src/lexer.z"
while ( ((_ZN4main5lexer10peek_tokenE(ctx,0) != '\n')&& !_ZN4main5lexer14is_done_lexingE(ctx) ))
{
#line 94 "src/lexer.z"
_ZN4main5lexer7advanceE(ctx) ;
}
;
}

#line 97 "src/lexer.z"
_ZN4main6tokens9TokenKindE _ZN4main5lexer10is_keywordE(char*  s) {
#line 100 "src/lexer.z"
if (!strcmp(s,"break") ){
#line 100 "src/lexer.z"
return TokenKind_Break;
;
}
;
#line 101 "src/lexer.z"
if (!strcmp(s,"continue") ){
#line 101 "src/lexer.z"
return TokenKind_Continue;
;
}
;
#line 102 "src/lexer.z"
if (!strcmp(s,"const") ){
#line 102 "src/lexer.z"
return TokenKind_Continue;
;
}
;
#line 103 "src/lexer.z"
if (!strcmp(s,"defer") ){
#line 103 "src/lexer.z"
return TokenKind_Defer;
;
}
;
#line 104 "src/lexer.z"
if (!strcmp(s,"enum") ){
#line 104 "src/lexer.z"
return TokenKind_Enum;
;
}
;
#line 105 "src/lexer.z"
if (!strcmp(s,"extern") ){
#line 105 "src/lexer.z"
return TokenKind_Extern;
;
}
;
#line 106 "src/lexer.z"
if (!strcmp(s,"else") ){
#line 106 "src/lexer.z"
return TokenKind_Else;
;
}
;
#line 107 "src/lexer.z"
if (!strcmp(s,"false") ){
#line 107 "src/lexer.z"
return TokenKind_False;
;
}
;
#line 108 "src/lexer.z"
if (!strcmp(s,"fn") ){
#line 108 "src/lexer.z"
return TokenKind_Fn;
;
}
;
#line 109 "src/lexer.z"
if (!strcmp(s,"for") ){
#line 109 "src/lexer.z"
return TokenKind_For;
;
}
;
#line 110 "src/lexer.z"
if (!strcmp(s,"if") ){
#line 110 "src/lexer.z"
return TokenKind_If;
;
}
;
#line 111 "src/lexer.z"
if (!strcmp(s,"mod") ){
#line 111 "src/lexer.z"
return TokenKind_Mod;
;
}
;
#line 112 "src/lexer.z"
if (!strcmp(s,"return") ){
#line 112 "src/lexer.z"
return TokenKind_Return;
;
}
;
#line 113 "src/lexer.z"
if (!strcmp(s,"struct") ){
#line 113 "src/lexer.z"
return TokenKind_Struct;
;
}
;
#line 114 "src/lexer.z"
if (!strcmp(s,"sizeof") ){
#line 114 "src/lexer.z"
return TokenKind_Sizeof;
;
}
;
#line 115 "src/lexer.z"
if (!strcmp(s,"true") ){
#line 115 "src/lexer.z"
return TokenKind_True;
;
}
;
#line 116 "src/lexer.z"
if (!strcmp(s,"union") ){
#line 116 "src/lexer.z"
return TokenKind_Union;
;
}
;
#line 117 "src/lexer.z"
if (!strcmp(s,"use") ){
#line 117 "src/lexer.z"
return TokenKind_Use;
;
}
;
#line 118 "src/lexer.z"
if (!strcmp(s,"var") ){
#line 118 "src/lexer.z"
return TokenKind_Var;
;
}
;
#line 119 "src/lexer.z"
if (!strcmp(s,"val") ){
#line 119 "src/lexer.z"
return TokenKind_Val;
;
}
;
#line 120 "src/lexer.z"
if (!strcmp(s,"while") ){
#line 120 "src/lexer.z"
return TokenKind_While;
;
}
;
#line 121 "src/lexer.z"
return TokenKind_Invalid;
;
}

#line 124 "src/lexer.z"
void  _ZN4main5lexer8lex_charE(_ZN4main5lexer13LexingContextE*  ctx) {
#line 126 "src/lexer.z"
_ZN4main10source_map10SourceFileE*  source = ctx->source;
;
#line 127 "src/lexer.z"
u32 start_line = (source->num_lines+ 1);
;
#line 129 "src/lexer.z"
while ( (((_ZN4main5lexer10peek_tokenE(ctx,0) != '\'')|| ((_ZN4main5lexer10peek_tokenE(ctx,-1) == '\\')&& (_ZN4main5lexer10peek_tokenE(ctx,-2) != '\\')))&& !_ZN4main5lexer14is_done_lexingE(ctx) ))
{
#line 130 "src/lexer.z"
char c = _ZN4main5lexer7advanceE(ctx) ;
;
#line 131 "src/lexer.z"
if ((c== '\n')){
#line 131 "src/lexer.z"
_ZN4main5lexer12read_newlineE(ctx) ;
}
;
}
;
#line 134 "src/lexer.z"
if (_ZN4main5lexer14is_done_lexingE(ctx) ){
#line 135 "src/lexer.z"
printf("Unterminated char starting on line %u\n",start_line) ;
#line 136 "src/lexer.z"
abort() ;
}
;
#line 140 "src/lexer.z"
_ZN4main5lexer7advanceE(ctx) ;
#line 142 "src/lexer.z"
_ZN4main5lexer9add_tokenE(ctx,TokenKind_Char,_ZN4main5lexer10get_lexemeE(ctx,1,1) ) ;
}

#line 145 "src/lexer.z"
void  _ZN4main5lexer10lex_stringE(_ZN4main5lexer13LexingContextE*  ctx) {
#line 147 "src/lexer.z"
_ZN4main10source_map10SourceFileE*  source = ctx->source;
;
#line 149 "src/lexer.z"
u32 start_line = (source->num_lines+ 1);
;
#line 151 "src/lexer.z"
while ( (((_ZN4main5lexer10peek_tokenE(ctx,0) != '"')|| ((_ZN4main5lexer10peek_tokenE(ctx,-1) == '\\')&& (_ZN4main5lexer10peek_tokenE(ctx,-2) != '\\')))&& !_ZN4main5lexer14is_done_lexingE(ctx) ))
{
#line 152 "src/lexer.z"
char c = _ZN4main5lexer7advanceE(ctx) ;
;
#line 153 "src/lexer.z"
if ((c== '\n')){
#line 153 "src/lexer.z"
_ZN4main5lexer12read_newlineE(ctx) ;
}
;
}
;
#line 156 "src/lexer.z"
if (_ZN4main5lexer14is_done_lexingE(ctx) ){
#line 157 "src/lexer.z"
printf("Unterminated string starting on line %u\n",start_line) ;
#line 158 "src/lexer.z"
abort() ;
}
;
#line 162 "src/lexer.z"
_ZN4main5lexer7advanceE(ctx) ;
#line 164 "src/lexer.z"
_ZN4main5lexer9add_tokenE(ctx,TokenKind_String,_ZN4main5lexer10get_lexemeE(ctx,1,1) ) ;
}

#line 167 "src/lexer.z"
void  _ZN4main5lexer10lex_numberE(_ZN4main5lexer13LexingContextE*  ctx) {
#line 169 "src/lexer.z"
while ( _ZN4main5lexer8is_digitE(_ZN4main5lexer10peek_tokenE(ctx,0) ) )
{
#line 169 "src/lexer.z"
_ZN4main5lexer7advanceE(ctx) ;
}
;
#line 170 "src/lexer.z"
bool dot_encountered = false;
;
#line 171 "src/lexer.z"
if (((_ZN4main5lexer10peek_tokenE(ctx,0) == '.')&& _ZN4main5lexer8is_digitE(_ZN4main5lexer10peek_tokenE(ctx,1) ) )){
#line 172 "src/lexer.z"
dot_encountered = true;
;
#line 173 "src/lexer.z"
_ZN4main5lexer7advanceE(ctx) ;
#line 174 "src/lexer.z"
while ( _ZN4main5lexer8is_digitE(_ZN4main5lexer10peek_tokenE(ctx,0) ) )
{
#line 174 "src/lexer.z"
_ZN4main5lexer7advanceE(ctx) ;
}
;
}
;
#line 177 "src/lexer.z"
_ZN4main6tokens9TokenKindE t ;
;
#line 178 "src/lexer.z"
if (dot_encountered){
#line 178 "src/lexer.z"
t = TokenKind_Float;
;
}
else {
#line 179 "src/lexer.z"
t = TokenKind_Integer;
;
}
;
#line 181 "src/lexer.z"
_ZN4main5lexer9add_tokenE(ctx,t,_ZN4main5lexer10get_lexemeE(ctx,0,0) ) ;
}

#line 184 "src/lexer.z"
void  _ZN4main5lexer14lex_identifierE(_ZN4main5lexer13LexingContextE*  ctx) {
#line 185 "src/lexer.z"
while ( (_ZN4main5lexer15is_alphanumericE(_ZN4main5lexer10peek_tokenE(ctx,0) ) || (_ZN4main5lexer10peek_tokenE(ctx,0) == '_')))
{
#line 185 "src/lexer.z"
_ZN4main5lexer7advanceE(ctx) ;
}
;
#line 187 "src/lexer.z"
_ZN4main9interning3SidE lexeme = _ZN4main5lexer10get_lexemeE(ctx,0,0) ;
;
#line 189 "src/lexer.z"
_ZN4main7session7SessionE*  sess = ctx->sess;
;
#line 190 "src/lexer.z"
char*  lexeme_str = _ZN4main9interning7get_strE(&sess->interner,lexeme) ;
;
#line 191 "src/lexer.z"
_ZN4main6tokens9TokenKindE keyword = _ZN4main5lexer10is_keywordE(lexeme_str) ;
;
#line 192 "src/lexer.z"
if ((keyword!= TokenKind_Invalid)){
#line 192 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,keyword) ;
}
else {
#line 193 "src/lexer.z"
_ZN4main5lexer9add_tokenE(ctx,TokenKind_Identifier,lexeme) ;
}
;
}

#line 196 "src/lexer.z"
void  _ZN4main5lexer10scan_tokenE(_ZN4main5lexer13LexingContextE*  ctx) {
#line 197 "src/lexer.z"
char c = _ZN4main5lexer7advanceE(ctx) ;
;
#line 201 "src/lexer.z"
if ((c== '(')){
#line 201 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_LeftParen) ;
}
else {
#line 202 "src/lexer.z"
if ((c== ')')){
#line 202 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_RightParen) ;
}
else {
#line 203 "src/lexer.z"
if ((c== '[')){
#line 203 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_LeftBracket) ;
}
else {
#line 204 "src/lexer.z"
if ((c== ']')){
#line 204 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_RightBracket) ;
}
else {
#line 205 "src/lexer.z"
if ((c== '{')){
#line 205 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_LeftCurly) ;
}
else {
#line 206 "src/lexer.z"
if ((c== '}')){
#line 206 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_RightCurly) ;
}
else {
#line 207 "src/lexer.z"
if ((c== '+')){
#line 207 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_Plus) ;
}
else {
#line 208 "src/lexer.z"
if ((c== '*')){
#line 208 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_Star) ;
}
else {
#line 209 "src/lexer.z"
if ((c== '%')){
#line 209 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_Percent) ;
}
else {
#line 210 "src/lexer.z"
if ((c== '^')){
#line 210 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_Hat) ;
}
else {
#line 211 "src/lexer.z"
if ((c== ';')){
#line 211 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_Semicolon) ;
}
else {
#line 212 "src/lexer.z"
if ((c== ',')){
#line 212 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_Comma) ;
}
else {
#line 213 "src/lexer.z"
if ((c== '-')){
#line 213 "src/lexer.z"
_ZN4main5lexer31add_lookahead_conditional_tokenE(ctx,'>',TokenKind_Arrow,TokenKind_Minus) ;
}
else {
#line 214 "src/lexer.z"
if ((c== ':')){
#line 214 "src/lexer.z"
_ZN4main5lexer31add_lookahead_conditional_tokenE(ctx,':',TokenKind_ColonColon,TokenKind_Colon) ;
}
else {
#line 215 "src/lexer.z"
if ((c== '=')){
#line 215 "src/lexer.z"
_ZN4main5lexer31add_lookahead_conditional_tokenE(ctx,'=',TokenKind_EqualEqual,TokenKind_Equal) ;
}
else {
#line 216 "src/lexer.z"
if ((c== '!')){
#line 216 "src/lexer.z"
_ZN4main5lexer31add_lookahead_conditional_tokenE(ctx,'=',TokenKind_BangEqual,TokenKind_Bang) ;
}
else {
#line 217 "src/lexer.z"
if ((c== '&')){
#line 217 "src/lexer.z"
_ZN4main5lexer31add_lookahead_conditional_tokenE(ctx,'&',TokenKind_AndAnd,TokenKind_And) ;
}
else {
#line 218 "src/lexer.z"
if ((c== '|')){
#line 218 "src/lexer.z"
_ZN4main5lexer31add_lookahead_conditional_tokenE(ctx,'|',TokenKind_OrOr,TokenKind_Or) ;
}
else {
#line 219 "src/lexer.z"
if ((c== '.')){
#line 220 "src/lexer.z"
if (((_ZN4main5lexer10peek_tokenE(ctx,0) == '.')&& (_ZN4main5lexer10peek_tokenE(ctx,1) == '.'))){
#line 221 "src/lexer.z"
_ZN4main5lexer7advanceE(ctx) ;
#line 221 "src/lexer.z"
_ZN4main5lexer7advanceE(ctx) ;
#line 222 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_Ellipsis) ;
}
else {
#line 224 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_Dot) ;
}
;
}
else {
#line 226 "src/lexer.z"
if ((c== '<')){
#line 227 "src/lexer.z"
char n1 = _ZN4main5lexer10peek_tokenE(ctx,0) ;
;
#line 228 "src/lexer.z"
if ((n1== '<')){
#line 228 "src/lexer.z"
_ZN4main5lexer7advanceE(ctx) ;
#line 228 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_LessLess) ;
}
else {
#line 229 "src/lexer.z"
if ((n1== '=')){
#line 229 "src/lexer.z"
_ZN4main5lexer7advanceE(ctx) ;
#line 229 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_LessEqual) ;
}
else {
#line 230 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_Less) ;
}
;
}
;
}
else {
#line 232 "src/lexer.z"
if ((c== '>')){
#line 233 "src/lexer.z"
char n2 = _ZN4main5lexer10peek_tokenE(ctx,0) ;
;
#line 234 "src/lexer.z"
if ((n2== '>')){
#line 234 "src/lexer.z"
_ZN4main5lexer7advanceE(ctx) ;
#line 234 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_GreaterGreater) ;
}
else {
#line 235 "src/lexer.z"
if ((n2== '=')){
#line 235 "src/lexer.z"
_ZN4main5lexer7advanceE(ctx) ;
#line 235 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_GreaterEqual) ;
}
else {
#line 236 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_Greater) ;
}
;
}
;
}
else {
#line 238 "src/lexer.z"
if ((c== '/')){
#line 239 "src/lexer.z"
if ((_ZN4main5lexer10peek_tokenE(ctx,0) == '/')){
#line 239 "src/lexer.z"
_ZN4main5lexer19single_line_commentE(ctx) ;
}
else {
#line 240 "src/lexer.z"
_ZN4main5lexer16add_simple_tokenE(ctx,TokenKind_Slash) ;
}
;
}
else {
#line 242 "src/lexer.z"
if ((((c== ' ')|| (c== '\t'))|| (c== '\r'))){
}
else {
#line 243 "src/lexer.z"
if ((c== '\n')){
#line 243 "src/lexer.z"
_ZN4main5lexer12read_newlineE(ctx) ;
}
else {
#line 244 "src/lexer.z"
if ((c== '"')){
#line 244 "src/lexer.z"
_ZN4main5lexer10lex_stringE(ctx) ;
}
else {
#line 245 "src/lexer.z"
if ((c== '\'')){
#line 245 "src/lexer.z"
_ZN4main5lexer8lex_charE(ctx) ;
}
else {
#line 247 "src/lexer.z"
if (_ZN4main5lexer8is_digitE(c) ){
#line 247 "src/lexer.z"
_ZN4main5lexer10lex_numberE(ctx) ;
}
else {
#line 248 "src/lexer.z"
if ((_ZN4main5lexer13is_alphabeticE(c) || (c== '_'))){
#line 248 "src/lexer.z"
_ZN4main5lexer14lex_identifierE(ctx) ;
}
else {
#line 250 "src/lexer.z"
_ZN4main10source_map10SourceFileE*  source = ctx->source;
;
#line 251 "src/lexer.z"
printf("Unexpected character %c = %d on line %u\n",c,c,source->num_lines) ;
#line 252 "src/lexer.z"
abort() ;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}

#line 257 "src/lexer.z"
_ZN4main6tokens5TokenE*  _ZN4main5lexer3lexE(_ZN4main7session7SessionE*  sess, _ZN4main10source_map10SourceFileE*  source, u32*  num_tokens) {
#line 259 "src/lexer.z"
_ZN4main5lexer13LexingContextE*  ctx = malloc(sizeof(_ZN4main5lexer13LexingContextE)) ;
;
#line 260 "src/lexer.z"
ctx->source = source;
;
#line 261 "src/lexer.z"
ctx->file_span_offset = source->start;
;
#line 262 "src/lexer.z"
ctx->start = 0;
;
#line 263 "src/lexer.z"
ctx->current = 0;
;
#line 264 "src/lexer.z"
ctx->tokens = malloc((sizeof(_ZN4main6tokens5TokenE)* 10000)) ;
;
#line 265 "src/lexer.z"
ctx->current_token_idx = 0;
;
#line 266 "src/lexer.z"
ctx->sess = sess;
;
#line 268 "src/lexer.z"
ctx->lexeme_buffer = malloc(1024) ;
;
#line 270 "src/lexer.z"
while ( !_ZN4main5lexer14is_done_lexingE(ctx) )
{
#line 271 "src/lexer.z"
ctx->start = ctx->current;
;
#line 272 "src/lexer.z"
_ZN4main5lexer10scan_tokenE(ctx) ;
}
;
#line 275 "src/lexer.z"
_ZN4main10source_map16source_file_doneE(source,ctx->current) ;
#line 277 "src/lexer.z"
if ((ctx->current_token_idx> 10000)){
#line 278 "src/lexer.z"
printf("Lexer token overflow: %u!\n",ctx->current_token_idx) ;
#line 279 "src/lexer.z"
abort() ;
}
;
#line 282 "src/lexer.z"
*num_tokens = ctx->current_token_idx;
;
#line 283 "src/lexer.z"
return ctx->tokens;
;
}







typedef struct _ZN4main3ast7AstTypeE _ZN4main3ast7AstTypeE;
#line 7 "src/ast.z"

typedef struct _ZN4main3ast4ExprE _ZN4main3ast4ExprE;
#line 8 "src/ast.z"

typedef struct _ZN4main3ast5BlockE _ZN4main3ast5BlockE;
#line 9 "src/ast.z"

typedef struct _ZN4main3ast4ItemE _ZN4main3ast4ItemE;
#line 10 "src/ast.z"

typedef struct _ZN4main3ast5IdentE _ZN4main3ast5IdentE;
#line 12 "src/ast.z"
typedef struct _ZN4main3ast5IdentE {
_ZN4main9interning3SidE name;
_ZN4main10source_map4SpanE span;
} _ZN4main3ast5IdentE;


#line 17 "src/ast.z"
typedef enum _ZN4main3ast11IntegerSizeE {
IntegerSize_I8,
IntegerSize_I16,
IntegerSize_I32,
IntegerSize_I64,
IntegerSize_Int_Arch,
IntegerSize_Int_Unspecified,
} _ZN4main3ast11IntegerSizeE;


#line 26 "src/ast.z"
typedef enum _ZN4main3ast12FloatingSizeE {
FloatingSize_F32,
FloatingSize_F64,
FloatingSize_Float_Unspecified,
} _ZN4main3ast12FloatingSizeE;


#line 32 "src/ast.z"
typedef enum _ZN4main3ast15PrimitiveTyKindE {
PrimitiveTyKind_Void,
PrimitiveTyKind_ConstVoid,
PrimitiveTyKind_Signed,
PrimitiveTyKind_Unsigned,
PrimitiveTyKind_Floating,
PrimitiveTyKind_Bool,
PrimitiveTyKind_Char,
PrimitiveTyKind_ConstChar,
} _ZN4main3ast15PrimitiveTyKindE;


typedef union _ZN4main3ast15PrimitiveTyNodeE _ZN4main3ast15PrimitiveTyNodeE;
#line 43 "src/ast.z"
typedef union _ZN4main3ast15PrimitiveTyNodeE {
_ZN4main3ast11IntegerSizeE integer;
_ZN4main3ast12FloatingSizeE floating;
} _ZN4main3ast15PrimitiveTyNodeE;


typedef struct _ZN4main3ast11PrimitiveTyE _ZN4main3ast11PrimitiveTyE;
#line 48 "src/ast.z"
typedef struct _ZN4main3ast11PrimitiveTyE {
_ZN4main3ast15PrimitiveTyNodeE node;
_ZN4main3ast15PrimitiveTyKindE kind;
} _ZN4main3ast11PrimitiveTyE;


#line 53 "src/ast.z"
typedef enum _ZN4main3ast11BindingKindE {
BindingKind_Item,
BindingKind_Variable,
BindingKind_Parameter,
BindingKind_PrimitiveType,
BindingKind_Variant,
} _ZN4main3ast11BindingKindE;


typedef struct _ZN4main3ast4ItemE _ZN4main3ast4ItemE;
#line 61 "src/ast.z"

typedef struct _ZN4main3ast11EnumVariantE _ZN4main3ast11EnumVariantE;
#line 62 "src/ast.z"

typedef struct _ZN4main3ast17FunctionParameterE _ZN4main3ast17FunctionParameterE;
#line 63 "src/ast.z"

typedef struct _ZN4main3ast7LetDataE _ZN4main3ast7LetDataE;
#line 64 "src/ast.z"

typedef struct _ZN4main3ast11PrimitiveTyE _ZN4main3ast11PrimitiveTyE;
#line 65 "src/ast.z"

typedef union _ZN4main3ast11BindingNodeE _ZN4main3ast11BindingNodeE;
#line 67 "src/ast.z"
typedef union _ZN4main3ast11BindingNodeE {
_ZN4main3ast4ItemE*  item;
_ZN4main3ast7LetDataE*  variable;
_ZN4main3ast17FunctionParameterE*  parameter;
_ZN4main3ast11PrimitiveTyE primitive;
_ZN4main3ast11EnumVariantE*  variant;
} _ZN4main3ast11BindingNodeE;


typedef struct _ZN4main3ast7BindingE _ZN4main3ast7BindingE;
#line 75 "src/ast.z"
typedef struct _ZN4main3ast7BindingE {
_ZN4main3ast11BindingKindE kind;
_ZN4main3ast11BindingNodeE node;
} _ZN4main3ast7BindingE;


typedef struct _ZN4main3ast4PathE _ZN4main3ast4PathE;
#line 80 "src/ast.z"
typedef struct _ZN4main3ast4PathE {
_ZN4main3ast5IdentE*  segments;
u32 num_segments;
_ZN4main3ast7BindingE binding;
_ZN4main10source_map4SpanE span;
} _ZN4main3ast4PathE;


typedef struct _ZN4main3ast2TyE _ZN4main3ast2TyE;
#line 87 "src/ast.z"

typedef struct _ZN4main3ast8FieldDefE _ZN4main3ast8FieldDefE;
#line 89 "src/ast.z"
typedef struct _ZN4main3ast8FieldDefE {
_ZN4main9interning3SidE name;
_ZN4main3ast2TyE*  ty;
} _ZN4main3ast8FieldDefE;


typedef struct _ZN4main3ast11CompoundDefE _ZN4main3ast11CompoundDefE;
#line 94 "src/ast.z"
typedef struct _ZN4main3ast11CompoundDefE {
_ZN4main3ast4PathE path;
_ZN4main3ast8FieldDefE*  fields;
u32 num_fields;
} _ZN4main3ast11CompoundDefE;


typedef struct _ZN4main3ast7EnumDefE _ZN4main3ast7EnumDefE;
#line 100 "src/ast.z"
typedef struct _ZN4main3ast7EnumDefE {
_ZN4main3ast4PathE path;
_ZN4main9interning3SidE*  variants;
u32 num_variants;
} _ZN4main3ast7EnumDefE;


typedef struct _ZN4main3ast5FnDefE _ZN4main3ast5FnDefE;
#line 106 "src/ast.z"
typedef struct _ZN4main3ast5FnDefE {
_ZN4main3ast2TyE* *  parameters;
u32 num_parameters;
_ZN4main3ast2TyE*  output;
} _ZN4main3ast5FnDefE;


#line 112 "src/ast.z"
typedef enum _ZN4main3ast6TyKindE {
TyKind_Void,
TyKind_ConstVoid,
TyKind_Variadic,
TyKind_Bool,
TyKind_Char,
TyKind_ConstChar,
TyKind_Signed,
TyKind_Unsigned,
TyKind_Floating,
TyKind_Ptr,
TyKind_Fn,
TyKind_Enum,
TyKind_Struct,
TyKind_Union,
} _ZN4main3ast6TyKindE;


typedef union _ZN4main3ast10TyKindNodeE _ZN4main3ast10TyKindNodeE;
#line 129 "src/ast.z"
typedef union _ZN4main3ast10TyKindNodeE {
_ZN4main3ast11IntegerSizeE integer;
_ZN4main3ast12FloatingSizeE floating;
_ZN4main3ast2TyE*  ptr;
_ZN4main3ast11CompoundDefE compound;
_ZN4main3ast7EnumDefE _enum;
_ZN4main3ast5FnDefE function;
} _ZN4main3ast10TyKindNodeE;


typedef struct _ZN4main3ast2TyE _ZN4main3ast2TyE;
#line 138 "src/ast.z"
typedef struct _ZN4main3ast2TyE {
_ZN4main3ast6TyKindE kind;
_ZN4main3ast10TyKindNodeE node;
} _ZN4main3ast2TyE;


typedef struct _ZN4main3ast7PatternE _ZN4main3ast7PatternE;
#line 143 "src/ast.z"
typedef struct _ZN4main3ast7PatternE {
_ZN4main3ast5IdentE ident;
_ZN4main10source_map4SpanE span;
} _ZN4main3ast7PatternE;


typedef struct _ZN4main3ast4ItemE _ZN4main3ast4ItemE;
#line 148 "src/ast.z"

typedef struct _ZN4main3ast10IndexEntryE _ZN4main3ast10IndexEntryE;
#line 150 "src/ast.z"
typedef struct _ZN4main3ast10IndexEntryE {
_ZN4main3ast4PathE path;
} _ZN4main3ast10IndexEntryE;


typedef struct _ZN4main3ast6ModuleE _ZN4main3ast6ModuleE;
#line 154 "src/ast.z"
typedef struct _ZN4main3ast6ModuleE {
_ZN4main10source_map4SpanE span;
_ZN4main3ast4ItemE* *  items;
u32 num_items;
_ZN4main6intmap6IntMapE*  index_lookup;
_ZN4main3ast10IndexEntryE*  index;
u32 num_indices;
_ZN4main3ast4PathE path;
_ZN4main3ast6ModuleE*  parent;
} _ZN4main3ast6ModuleE;


#line 165 "src/ast.z"
typedef enum _ZN4main3ast11AstTypeKindE {
AstTypeKind_Void,
AstTypeKind_Ptr,
AstTypeKind_Path,
AstTypeKind_Variadic,
} _ZN4main3ast11AstTypeKindE;


typedef struct _ZN4main3ast12GenericParamE _ZN4main3ast12GenericParamE;
#line 172 "src/ast.z"
typedef struct _ZN4main3ast12GenericParamE {
_ZN4main3ast5IdentE ident;
} _ZN4main3ast12GenericParamE;


typedef struct _ZN4main3ast8GenericsE _ZN4main3ast8GenericsE;
#line 176 "src/ast.z"
typedef struct _ZN4main3ast8GenericsE {
_ZN4main3ast12GenericParamE*  parameters;
u32 num_parameters;
_ZN4main10source_map4SpanE span;
} _ZN4main3ast8GenericsE;


typedef union _ZN4main3ast15AstTypeKindNodeE _ZN4main3ast15AstTypeKindNodeE;
#line 182 "src/ast.z"
typedef union _ZN4main3ast15AstTypeKindNodeE {
_ZN4main3ast4PathE path;
_ZN4main3ast7AstTypeE*  ptr;
} _ZN4main3ast15AstTypeKindNodeE;


typedef struct _ZN4main3ast7AstTypeE _ZN4main3ast7AstTypeE;
#line 187 "src/ast.z"
typedef struct _ZN4main3ast7AstTypeE {
_ZN4main3ast11AstTypeKindE kind;
_ZN4main3ast15AstTypeKindNodeE node;
_ZN4main3ast2TyE*  ty;
} _ZN4main3ast7AstTypeE;


#line 193 "src/ast.z"
typedef enum _ZN4main3ast11LiteralKindE {
LiteralKind_Int,
LiteralKind_Float,
LiteralKind_Bool,
LiteralKind_Char,
LiteralKind_Str,
} _ZN4main3ast11LiteralKindE;


typedef union _ZN4main3ast12LiteralValueE _ZN4main3ast12LiteralValueE;
#line 201 "src/ast.z"
typedef union _ZN4main3ast12LiteralValueE {
f64 floating;
u64 integer;
bool boolean;
char ch;
_ZN4main9interning3SidE str;
} _ZN4main3ast12LiteralValueE;


typedef struct _ZN4main3ast7LiteralE _ZN4main3ast7LiteralE;
#line 209 "src/ast.z"
typedef struct _ZN4main3ast7LiteralE {
_ZN4main3ast11LiteralKindE kind;
_ZN4main3ast12LiteralValueE value;
} _ZN4main3ast7LiteralE;


#line 215 "src/ast.z"
typedef enum _ZN4main3ast17UnaryOperatorKindE {
UnaryOperatorKind_Deref,
UnaryOperatorKind_Refer,
UnaryOperatorKind_Negation,
UnaryOperatorKind_Complement,
} _ZN4main3ast17UnaryOperatorKindE;


#line 226 "src/ast.z"
typedef enum _ZN4main3ast18BinaryOperatorKindE {
BinaryOperatorKind_Invalid,
BinaryOperatorKind_Addition,
BinaryOperatorKind_Subtraction,
BinaryOperatorKind_Product,
BinaryOperatorKind_Division,
BinaryOperatorKind_Modulus,
BinaryOperatorKind_Less,
BinaryOperatorKind_LessEq,
BinaryOperatorKind_Greater,
BinaryOperatorKind_GreaterEq,
BinaryOperatorKind_Equality,
BinaryOperatorKind_NotEq,
BinaryOperatorKind_BAnd,
BinaryOperatorKind_BOr,
BinaryOperatorKind_Xor,
BinaryOperatorKind_LeftShift,
BinaryOperatorKind_RightShift,
BinaryOperatorKind_And,
BinaryOperatorKind_Or,
} _ZN4main3ast18BinaryOperatorKindE;


typedef struct _ZN4main3ast10BinaryDataE _ZN4main3ast10BinaryDataE;
#line 255 "src/ast.z"
typedef struct _ZN4main3ast10BinaryDataE {
_ZN4main3ast18BinaryOperatorKindE op;
_ZN4main3ast4ExprE*  left;
_ZN4main3ast4ExprE*  right;
} _ZN4main3ast10BinaryDataE;


typedef struct _ZN4main3ast8CallDataE _ZN4main3ast8CallDataE;
#line 261 "src/ast.z"
typedef struct _ZN4main3ast8CallDataE {
_ZN4main3ast4ExprE*  func;
_ZN4main3ast4ExprE* *  args;
u32 num_args;
} _ZN4main3ast8CallDataE;


typedef struct _ZN4main3ast8CastDataE _ZN4main3ast8CastDataE;
#line 267 "src/ast.z"
typedef struct _ZN4main3ast8CastDataE {
_ZN4main3ast4ExprE*  inner;
_ZN4main3ast7AstTypeE*  ast_ty;
_ZN4main3ast2TyE*  ty;
} _ZN4main3ast8CastDataE;


typedef struct _ZN4main3ast15ConditionalDataE _ZN4main3ast15ConditionalDataE;
#line 273 "src/ast.z"
typedef struct _ZN4main3ast15ConditionalDataE {
_ZN4main3ast4ExprE*  condition;
_ZN4main3ast4ExprE*  then;
_ZN4main3ast4ExprE*  otherwise;
} _ZN4main3ast15ConditionalDataE;


typedef struct _ZN4main3ast9WhileDataE _ZN4main3ast9WhileDataE;
#line 279 "src/ast.z"
typedef struct _ZN4main3ast9WhileDataE {
_ZN4main3ast4ExprE*  condition;
_ZN4main3ast4ExprE*  body;
} _ZN4main3ast9WhileDataE;


typedef struct _ZN4main3ast12IndexingDataE _ZN4main3ast12IndexingDataE;
#line 284 "src/ast.z"
typedef struct _ZN4main3ast12IndexingDataE {
_ZN4main3ast4ExprE*  array;
_ZN4main3ast4ExprE*  index;
} _ZN4main3ast12IndexingDataE;


typedef struct _ZN4main3ast9FieldDataE _ZN4main3ast9FieldDataE;
#line 289 "src/ast.z"
typedef struct _ZN4main3ast9FieldDataE {
_ZN4main3ast4ExprE*  strct;
_ZN4main3ast5IdentE ident;
} _ZN4main3ast9FieldDataE;


typedef struct _ZN4main3ast9UnaryDataE _ZN4main3ast9UnaryDataE;
#line 294 "src/ast.z"
typedef struct _ZN4main3ast9UnaryDataE {
_ZN4main3ast17UnaryOperatorKindE op;
_ZN4main3ast4ExprE*  inner;
} _ZN4main3ast9UnaryDataE;


typedef struct _ZN4main3ast14AssignmentDataE _ZN4main3ast14AssignmentDataE;
#line 299 "src/ast.z"
typedef struct _ZN4main3ast14AssignmentDataE {
_ZN4main3ast4ExprE*  left;
_ZN4main3ast4ExprE*  right;
} _ZN4main3ast14AssignmentDataE;


typedef struct _ZN4main3ast7LetDataE _ZN4main3ast7LetDataE;
#line 304 "src/ast.z"
typedef struct _ZN4main3ast7LetDataE {
_ZN4main3ast7PatternE pat;
_ZN4main3ast4ExprE*  value;
_ZN4main3ast7AstTypeE*  ast_ty;
_ZN4main3ast2TyE*  ty;
} _ZN4main3ast7LetDataE;


#line 311 "src/ast.z"
typedef enum _ZN4main3ast8ExprKindE {
ExprKind_Binary,
ExprKind_Block,
ExprKind_Call,
ExprKind_Cast,
ExprKind_Conditional,
ExprKind_Field,
ExprKind_Indexing,
ExprKind_Path,
ExprKind_Literal,
ExprKind_Sizeof,
ExprKind_Unary,
ExprKind_While,
ExprKind_Assignment,
ExprKind_Let,
ExprKind_Return,
ExprKind_ControlFlow,
ExprKind_Defer,
ExprKind_Empty,
} _ZN4main3ast8ExprKindE;


typedef union _ZN4main3ast12ExprKindNodeE _ZN4main3ast12ExprKindNodeE;
#line 332 "src/ast.z"
typedef union _ZN4main3ast12ExprKindNodeE {
_ZN4main3ast10BinaryDataE binary;
_ZN4main3ast5BlockE*  block;
_ZN4main3ast8CallDataE call;
_ZN4main3ast8CastDataE _cast;
_ZN4main3ast15ConditionalDataE conditional;
bool control_flow_is_continue;
_ZN4main3ast9FieldDataE field;
_ZN4main3ast12IndexingDataE indexing;
_ZN4main3ast4PathE path;
_ZN4main3ast7LiteralE lit;
_ZN4main3ast4ExprE*  _sizeof;
_ZN4main3ast9UnaryDataE unary;
_ZN4main3ast9WhileDataE whl;
_ZN4main3ast14AssignmentDataE assignment;
_ZN4main3ast4ExprE*  _return;
_ZN4main3ast7LetDataE _let;
} _ZN4main3ast12ExprKindNodeE;


typedef struct _ZN4main3ast4ExprE _ZN4main3ast4ExprE;
#line 351 "src/ast.z"
typedef struct _ZN4main3ast4ExprE {
_ZN4main10source_map4SpanE span;
_ZN4main3ast8ExprKindE kind;
_ZN4main3ast12ExprKindNodeE node;
_ZN4main3ast2TyE*  ty;
} _ZN4main3ast4ExprE;


typedef struct _ZN4main3ast5BlockE _ZN4main3ast5BlockE;
#line 358 "src/ast.z"
typedef struct _ZN4main3ast5BlockE {
_ZN4main3ast4ExprE* *  exprs;
u32 num_exprs;
_ZN4main10source_map4SpanE span;
} _ZN4main3ast5BlockE;


#line 364 "src/ast.z"
typedef enum _ZN4main3ast14VisibilityKindE {
VisibilityKind_Public,
VisibilityKind_Private,
} _ZN4main3ast14VisibilityKindE;


typedef struct _ZN4main3ast10VisibilityE _ZN4main3ast10VisibilityE;
#line 369 "src/ast.z"
typedef struct _ZN4main3ast10VisibilityE {
_ZN4main3ast14VisibilityKindE kind;
} _ZN4main3ast10VisibilityE;


typedef struct _ZN4main3ast13CompoundFieldE _ZN4main3ast13CompoundFieldE;
#line 373 "src/ast.z"
typedef struct _ZN4main3ast13CompoundFieldE {
_ZN4main3ast5IdentE ident;
_ZN4main3ast7AstTypeE*  ast_ty;
} _ZN4main3ast13CompoundFieldE;


typedef struct _ZN4main3ast12CompoundDataE _ZN4main3ast12CompoundDataE;
#line 378 "src/ast.z"
typedef struct _ZN4main3ast12CompoundDataE {
_ZN4main3ast13CompoundFieldE*  fields;
u32 num_fields;
_ZN4main3ast8GenericsE generics;
_ZN4main3ast2TyE*  ty;
} _ZN4main3ast12CompoundDataE;


typedef struct _ZN4main3ast11EnumVariantE _ZN4main3ast11EnumVariantE;
#line 385 "src/ast.z"
typedef struct _ZN4main3ast11EnumVariantE {
_ZN4main3ast5IdentE ident;
_ZN4main3ast4ItemE*  _enum;
} _ZN4main3ast11EnumVariantE;


typedef struct _ZN4main3ast8EnumDataE _ZN4main3ast8EnumDataE;
#line 390 "src/ast.z"
typedef struct _ZN4main3ast8EnumDataE {
_ZN4main3ast11EnumVariantE*  variants;
u32 num_variants;
_ZN4main3ast2TyE*  ty;
} _ZN4main3ast8EnumDataE;


typedef struct _ZN4main3ast17FunctionParameterE _ZN4main3ast17FunctionParameterE;
#line 396 "src/ast.z"
typedef struct _ZN4main3ast17FunctionParameterE {
_ZN4main3ast7PatternE pat;
_ZN4main3ast7AstTypeE*  ast_ty;
_ZN4main3ast2TyE*  ty;
} _ZN4main3ast17FunctionParameterE;


typedef struct _ZN4main3ast14FunctionHeaderE _ZN4main3ast14FunctionHeaderE;
#line 403 "src/ast.z"
typedef struct _ZN4main3ast14FunctionHeaderE {
_ZN4main3ast17FunctionParameterE*  parameters;
u32 num_parameters;
_ZN4main3ast7AstTypeE*  output_ast_ty;
_ZN4main3ast8GenericsE generics;
_ZN4main3ast2TyE*  ty;
} _ZN4main3ast14FunctionHeaderE;


typedef struct _ZN4main3ast12FunctionDataE _ZN4main3ast12FunctionDataE;
#line 411 "src/ast.z"
typedef struct _ZN4main3ast12FunctionDataE {
_ZN4main3ast14FunctionHeaderE header;
_ZN4main3ast4ExprE*  body;
} _ZN4main3ast12FunctionDataE;


typedef struct _ZN4main3ast12VariableDataE _ZN4main3ast12VariableDataE;
#line 417 "src/ast.z"
typedef struct _ZN4main3ast12VariableDataE {
_ZN4main3ast7AstTypeE*  ast_ty;
_ZN4main3ast2TyE*  ty;
bool mutable;
_ZN4main3ast4ExprE*  body;
} _ZN4main3ast12VariableDataE;


typedef union _ZN4main3ast12ItemKindNodeE _ZN4main3ast12ItemKindNodeE;
#line 424 "src/ast.z"
typedef union _ZN4main3ast12ItemKindNodeE {
_ZN4main3ast12CompoundDataE compound;
_ZN4main3ast8EnumDataE _enum;
_ZN4main3ast12VariableDataE variable;
_ZN4main3ast12FunctionDataE function;
_ZN4main3ast6ModuleE*  module;
_ZN4main3ast4PathE _use;
} _ZN4main3ast12ItemKindNodeE;


#line 433 "src/ast.z"
typedef enum _ZN4main3ast8ItemKindE {
ItemKind_Const,
ItemKind_Enum,
ItemKind_Function,
ItemKind_Module,
ItemKind_Struct,
ItemKind_Union,
ItemKind_Use,
ItemKind_Variable,
} _ZN4main3ast8ItemKindE;


typedef struct _ZN4main3ast4ItemE _ZN4main3ast4ItemE;
#line 444 "src/ast.z"
typedef struct _ZN4main3ast4ItemE {
_ZN4main3ast5IdentE ident;
_ZN4main3ast8ItemKindE kind;
_ZN4main3ast12ItemKindNodeE node;
_ZN4main3ast10VisibilityE vis;
_ZN4main10source_map4SpanE span;
bool should_mangle;
} _ZN4main3ast4ItemE;


typedef struct _ZN4main3ast3AstE _ZN4main3ast3AstE;
#line 453 "src/ast.z"
typedef struct _ZN4main3ast3AstE {
_ZN4main3ast4ItemE*  items;
u32 num_items;
_ZN4main3ast6ModuleE*  root_module;
} _ZN4main3ast3AstE;


#line 460 "src/ast.z"
_ZN4main3ast4ExprE*  _ZN4main3ast15ast_create_exprE(_ZN4main3ast3AstE*  ast, _ZN4main3ast8ExprKindE kind) {
#line 461 "src/ast.z"
_ZN4main3ast4ExprE*  expr = malloc(sizeof(_ZN4main3ast4ExprE)) ;
;
#line 462 "src/ast.z"
expr->kind = kind;
;
#line 464 "src/ast.z"
return expr;
;
}

#line 467 "src/ast.z"
_ZN4main3ast4ItemE*  _ZN4main3ast15ast_create_itemE(_ZN4main3ast3AstE*  ast) {
#line 469 "src/ast.z"
_ZN4main3ast4ItemE*  item = &ast->items[ast->num_items];
;
#line 470 "src/ast.z"
ast->num_items = (ast->num_items+ 1);
;
#line 472 "src/ast.z"
return item;
;
}










typedef struct _ZN4main6parser14ParsingContextE _ZN4main6parser14ParsingContextE;
#line 11 "src/parser.z"
typedef struct _ZN4main6parser14ParsingContextE {
u64 current_token;
_ZN4main6tokens5TokenE*  tokens;
u64 num_tokens;
_ZN4main10source_map9SourceMapE*  source_map;
_ZN4main7session7SessionE*  sess;
_ZN4main3ast6ModuleE*  current_module;
_ZN4main3ast3AstE*  ast;
} _ZN4main6parser14ParsingContextE;


#line 21 "src/parser.z"
bool _ZN4main6parser15is_done_parsingE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 22 "src/parser.z"
return (ctx->num_tokens== ctx->current_token);
;
}

#line 25 "src/parser.z"
bool _ZN4main6parser6acceptE(_ZN4main6parser14ParsingContextE*  ctx, _ZN4main6tokens9TokenKindE token) {
#line 26 "src/parser.z"
_ZN4main6tokens5TokenE tok = ctx->tokens[ctx->current_token];
;
#line 27 "src/parser.z"
if ((!_ZN4main6parser15is_done_parsingE(ctx) && (tok.kind== token))){
#line 28 "src/parser.z"
ctx->current_token = (ctx->current_token+ 1);
;
#line 29 "src/parser.z"
return true;
;
}
;
#line 31 "src/parser.z"
return false;
;
}

#line 34 "src/parser.z"
bool _ZN4main6parser10can_acceptE(_ZN4main6parser14ParsingContextE*  ctx, _ZN4main6tokens9TokenKindE token) {
#line 35 "src/parser.z"
_ZN4main6tokens5TokenE tok = ctx->tokens[ctx->current_token];
;
#line 36 "src/parser.z"
if ((!_ZN4main6parser15is_done_parsingE(ctx) && (tok.kind== token))){
#line 37 "src/parser.z"
return true;
;
}
;
#line 39 "src/parser.z"
return false;
;
}

#line 42 "src/parser.z"
_ZN4main6tokens5TokenE _ZN4main6parser10look_aheadE(_ZN4main6parser14ParsingContextE*  ctx, u64 offset) {
#line 43 "src/parser.z"
if ((ctx->current_token== ctx->num_tokens)){
#line 44 "src/parser.z"
_ZN4main6tokens5TokenE eof_tok ;
;
#line 45 "src/parser.z"
eof_tok.kind = _ZN4main4cstd3EOFE;
;
#line 46 "src/parser.z"
return eof_tok;
;
}
else {
#line 47 "src/parser.z"
return ctx->tokens[(ctx->current_token+ offset)];
;
}
;
}

#line 50 "src/parser.z"
_ZN4main6tokens5TokenE _ZN4main6parser7consumeE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 51 "src/parser.z"
ctx->current_token = (ctx->current_token+ 1);
;
#line 52 "src/parser.z"
return ctx->tokens[(ctx->current_token- 1)];
;
}

#line 55 "src/parser.z"
_ZN4main6tokens5TokenE _ZN4main6parser6expectE(_ZN4main6parser14ParsingContextE*  ctx, _ZN4main6tokens9TokenKindE kind) {
#line 56 "src/parser.z"
_ZN4main6tokens5TokenE tok = _ZN4main6parser7consumeE(ctx) ;
;
#line 57 "src/parser.z"
if ((tok.kind== kind)){
#line 58 "src/parser.z"
return tok;
;
}
else {
#line 60 "src/parser.z"
_ZN4main5error10emit_errorE(ctx->source_map,tok.span,"Expect failed!") ;
#line 61 "src/parser.z"
abort() ;
}
;
}

#line 65 "src/parser.z"
u32 _ZN4main6parser10span_startE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 66 "src/parser.z"
return ctx->tokens[ctx->current_token].span.from;
;
}

#line 69 "src/parser.z"
u32 _ZN4main6parser8span_endE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 70 "src/parser.z"
return ctx->tokens[(ctx->current_token- 1)].span.to;
;
}

#line 73 "src/parser.z"
_ZN4main3ast5IdentE _ZN4main6parser16parse_identifierE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 75 "src/parser.z"
_ZN4main3ast5IdentE ident ;
;
#line 76 "src/parser.z"
ident.span.from = _ZN4main6parser10span_startE(ctx) ;
;
#line 77 "src/parser.z"
_ZN4main6tokens5TokenE tok = _ZN4main6parser7consumeE(ctx) ;
;
#line 79 "src/parser.z"
if ((tok.kind!= TokenKind_Identifier)){
#line 79 "src/parser.z"
_ZN4main5error10emit_errorE(ctx->source_map,tok.span,"Invalid identifier") ;
}
;
#line 81 "src/parser.z"
ident.name = tok.lexeme;
;
#line 82 "src/parser.z"
ident.span.to = _ZN4main6parser8span_endE(ctx) ;
;
#line 84 "src/parser.z"
return ident;
;
}

#line 87 "src/parser.z"
_ZN4main3ast4PathE _ZN4main6parser10parse_pathE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 88 "src/parser.z"
_ZN4main3ast4PathE path ;
;
#line 89 "src/parser.z"
path.segments = malloc((sizeof(_ZN4main3ast5IdentE)* 6)) ;
;
#line 90 "src/parser.z"
path.num_segments = 0;
;
#line 91 "src/parser.z"
path.span.from = _ZN4main6parser10span_startE(ctx) ;
;
#line 93 "src/parser.z"
while ( true)
{
#line 94 "src/parser.z"
if (_ZN4main6parser6acceptE(ctx,TokenKind_Star) ){
#line 95 "src/parser.z"
path.segments[path.num_segments].name.x = 0;
;
}
else {
#line 97 "src/parser.z"
path.segments[path.num_segments] = _ZN4main6parser16parse_identifierE(ctx) ;
;
}
;
#line 99 "src/parser.z"
path.num_segments = (path.num_segments+ 1);
;
#line 100 "src/parser.z"
if (!_ZN4main6parser6acceptE(ctx,TokenKind_ColonColon) ){
#line 100 "src/parser.z"
break;
;
}
;
}
;
#line 103 "src/parser.z"
path.span.to = _ZN4main6parser8span_endE(ctx) ;
;
#line 104 "src/parser.z"
return path;
;
}

#line 107 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser15parse_path_exprE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 108 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Path) ;
;
#line 109 "src/parser.z"
expr->node.path = _ZN4main6parser10parse_pathE(ctx) ;
;
#line 110 "src/parser.z"
return expr;
;
}

#line 113 "src/parser.z"
_ZN4main3ast7PatternE _ZN4main6parser13parse_patternE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 114 "src/parser.z"
_ZN4main3ast7PatternE pat ;
;
#line 115 "src/parser.z"
pat.span.from = _ZN4main6parser10span_startE(ctx) ;
;
#line 116 "src/parser.z"
pat.ident = _ZN4main6parser16parse_identifierE(ctx) ;
;
#line 117 "src/parser.z"
pat.span.to = _ZN4main6parser10span_startE(ctx) ;
;
#line 118 "src/parser.z"
return pat;
;
}

#line 121 "src/parser.z"
_ZN4main3ast7AstTypeE*  _ZN4main6parser10parse_typeE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 122 "src/parser.z"
_ZN4main3ast15AstTypeKindNodeE node ;
;
#line 123 "src/parser.z"
_ZN4main3ast11AstTypeKindE kind ;
;
#line 125 "src/parser.z"
_ZN4main6tokens5TokenE token = _ZN4main6parser10look_aheadE(ctx,0) ;
;
#line 126 "src/parser.z"
if ((token.kind== TokenKind_Identifier)){
#line 127 "src/parser.z"
kind = AstTypeKind_Path;
;
#line 128 "src/parser.z"
node.path = _ZN4main6parser10parse_pathE(ctx) ;
;
}
else {
#line 129 "src/parser.z"
if ((token.kind== TokenKind_Star)){
#line 130 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_Star) ;
#line 131 "src/parser.z"
kind = AstTypeKind_Ptr;
;
#line 132 "src/parser.z"
node.ptr = _ZN4main6parser10parse_typeE(ctx) ;
;
}
else {
#line 133 "src/parser.z"
if ((token.kind== TokenKind_Ellipsis)){
#line 134 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_Ellipsis) ;
#line 135 "src/parser.z"
kind = AstTypeKind_Variadic;
;
}
else {
#line 137 "src/parser.z"
_ZN4main5error10emit_errorE(ctx->source_map,token.span,"Expected type") ;
}
;
}
;
}
;
#line 139 "src/parser.z"
_ZN4main3ast7AstTypeE*  type = malloc(sizeof(_ZN4main3ast7AstTypeE)) ;
;
#line 140 "src/parser.z"
type->kind = kind;
;
#line 141 "src/parser.z"
type->node = node;
;
#line 143 "src/parser.z"
return type;
;
}

#line 146 "src/parser.z"
_ZN4main3ast18BinaryOperatorKindE _ZN4main6parser32convert_token_to_binary_operatorE(_ZN4main6tokens9TokenKindE tok) {
#line 147 "src/parser.z"
if ((tok== TokenKind_Plus)){
#line 147 "src/parser.z"
return BinaryOperatorKind_Addition;
;
}
else {
#line 148 "src/parser.z"
if ((tok== TokenKind_Minus)){
#line 148 "src/parser.z"
return BinaryOperatorKind_Subtraction;
;
}
else {
#line 149 "src/parser.z"
if ((tok== TokenKind_Star)){
#line 149 "src/parser.z"
return BinaryOperatorKind_Product;
;
}
else {
#line 150 "src/parser.z"
if ((tok== TokenKind_Slash)){
#line 150 "src/parser.z"
return BinaryOperatorKind_Division;
;
}
else {
#line 151 "src/parser.z"
if ((tok== TokenKind_Percent)){
#line 151 "src/parser.z"
return BinaryOperatorKind_Modulus;
;
}
else {
#line 152 "src/parser.z"
if ((tok== TokenKind_Less)){
#line 152 "src/parser.z"
return BinaryOperatorKind_Less;
;
}
else {
#line 153 "src/parser.z"
if ((tok== TokenKind_LessEqual)){
#line 153 "src/parser.z"
return BinaryOperatorKind_LessEq;
;
}
else {
#line 154 "src/parser.z"
if ((tok== TokenKind_Greater)){
#line 154 "src/parser.z"
return BinaryOperatorKind_Greater;
;
}
else {
#line 155 "src/parser.z"
if ((tok== TokenKind_GreaterEqual)){
#line 155 "src/parser.z"
return BinaryOperatorKind_GreaterEq;
;
}
else {
#line 156 "src/parser.z"
if ((tok== TokenKind_EqualEqual)){
#line 156 "src/parser.z"
return BinaryOperatorKind_Equality;
;
}
else {
#line 157 "src/parser.z"
if ((tok== TokenKind_BangEqual)){
#line 157 "src/parser.z"
return BinaryOperatorKind_NotEq;
;
}
else {
#line 158 "src/parser.z"
if ((tok== TokenKind_AndAnd)){
#line 158 "src/parser.z"
return BinaryOperatorKind_And;
;
}
else {
#line 159 "src/parser.z"
if ((tok== TokenKind_OrOr)){
#line 159 "src/parser.z"
return BinaryOperatorKind_Or;
;
}
else {
#line 160 "src/parser.z"
if ((tok== TokenKind_And)){
#line 160 "src/parser.z"
return BinaryOperatorKind_BAnd;
;
}
else {
#line 161 "src/parser.z"
if ((tok== TokenKind_Or)){
#line 161 "src/parser.z"
return BinaryOperatorKind_BOr;
;
}
else {
#line 162 "src/parser.z"
if ((tok== TokenKind_Hat)){
#line 162 "src/parser.z"
return BinaryOperatorKind_Xor;
;
}
else {
#line 163 "src/parser.z"
if ((tok== TokenKind_LessLess)){
#line 163 "src/parser.z"
return BinaryOperatorKind_LeftShift;
;
}
else {
#line 164 "src/parser.z"
if ((tok== TokenKind_GreaterGreater)){
#line 164 "src/parser.z"
return BinaryOperatorKind_RightShift;
;
}
else {
#line 165 "src/parser.z"
return BinaryOperatorKind_Invalid;
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}

#line 168 "src/parser.z"
u32 _ZN4main6parser30get_binary_operator_precedenceE(_ZN4main3ast18BinaryOperatorKindE op) {
#line 169 "src/parser.z"
if ((op== BinaryOperatorKind_Product)){
#line 169 "src/parser.z"
return 10;
;
}
else {
#line 170 "src/parser.z"
if ((op== BinaryOperatorKind_Division)){
#line 170 "src/parser.z"
return 10;
;
}
else {
#line 171 "src/parser.z"
if ((op== BinaryOperatorKind_Modulus)){
#line 171 "src/parser.z"
return 10;
;
}
else {
#line 172 "src/parser.z"
if ((op== BinaryOperatorKind_Addition)){
#line 172 "src/parser.z"
return 9;
;
}
else {
#line 173 "src/parser.z"
if ((op== BinaryOperatorKind_Subtraction)){
#line 173 "src/parser.z"
return 9;
;
}
else {
#line 174 "src/parser.z"
if ((op== BinaryOperatorKind_LeftShift)){
#line 174 "src/parser.z"
return 8;
;
}
else {
#line 175 "src/parser.z"
if ((op== BinaryOperatorKind_RightShift)){
#line 175 "src/parser.z"
return 8;
;
}
else {
#line 176 "src/parser.z"
if ((op== BinaryOperatorKind_BAnd)){
#line 176 "src/parser.z"
return 7;
;
}
else {
#line 177 "src/parser.z"
if ((op== BinaryOperatorKind_Xor)){
#line 177 "src/parser.z"
return 6;
;
}
else {
#line 178 "src/parser.z"
if ((op== BinaryOperatorKind_BOr)){
#line 178 "src/parser.z"
return 5;
;
}
else {
#line 179 "src/parser.z"
if ((op== BinaryOperatorKind_Less)){
#line 179 "src/parser.z"
return 4;
;
}
else {
#line 180 "src/parser.z"
if ((op== BinaryOperatorKind_LessEq)){
#line 180 "src/parser.z"
return 4;
;
}
else {
#line 181 "src/parser.z"
if ((op== BinaryOperatorKind_Greater)){
#line 181 "src/parser.z"
return 4;
;
}
else {
#line 182 "src/parser.z"
if ((op== BinaryOperatorKind_GreaterEq)){
#line 182 "src/parser.z"
return 4;
;
}
else {
#line 183 "src/parser.z"
if ((op== BinaryOperatorKind_Equality)){
#line 183 "src/parser.z"
return 4;
;
}
else {
#line 184 "src/parser.z"
if ((op== BinaryOperatorKind_NotEq)){
#line 184 "src/parser.z"
return 4;
;
}
else {
#line 185 "src/parser.z"
if ((op== BinaryOperatorKind_And)){
#line 185 "src/parser.z"
return 3;
;
}
else {
#line 186 "src/parser.z"
if ((op== BinaryOperatorKind_Or)){
#line 186 "src/parser.z"
return 2;
;
}
else {
#line 187 "src/parser.z"
return 0;
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}

#line 190 "src/parser.z"
u32 _ZN4main6parser22get_current_precedenceE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 192 "src/parser.z"
if ((ctx->num_tokens<= ctx->current_token)){
#line 193 "src/parser.z"
return 0;
;
}
else {
#line 195 "src/parser.z"
_ZN4main6tokens5TokenE tok = ctx->tokens[ctx->current_token];
;
#line 196 "src/parser.z"
u32 op_precedence = _ZN4main6parser30get_binary_operator_precedenceE(_ZN4main6parser32convert_token_to_binary_operatorE(tok.kind) ) ;
;
#line 197 "src/parser.z"
if ((op_precedence> 0)){
#line 197 "src/parser.z"
return op_precedence;
;
}
else {
#line 198 "src/parser.z"
if ((tok.kind== TokenKind_Dot)){
#line 198 "src/parser.z"
return 13;
;
}
else {
#line 199 "src/parser.z"
if (((tok.kind== TokenKind_LeftBracket)|| (tok.kind== TokenKind_LeftParen))){
#line 199 "src/parser.z"
return 12;
;
}
else {
#line 200 "src/parser.z"
if ((tok.kind== TokenKind_Equal)){
#line 200 "src/parser.z"
return 1;
;
}
else {
#line 201 "src/parser.z"
return 0;
;
}
;
}
;
}
;
}
;
}
;
}

#line 205 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser16parse_expressionE(_ZN4main6parser14ParsingContextE*  ctx, u32 precedence) ;

#line 207 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser21parse_integer_literalE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 209 "src/parser.z"
_ZN4main6tokens5TokenE tok = _ZN4main6parser6expectE(ctx,TokenKind_Integer) ;
;
#line 211 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Literal) ;
;
#line 212 "src/parser.z"
expr->node.lit.kind = LiteralKind_Int;
;
#line 214 "src/parser.z"
_ZN4main7session7SessionE*  sess = ctx->sess;
;
#line 215 "src/parser.z"
expr->node.lit.value.integer = atol(_ZN4main9interning7get_strE(&sess->interner,tok.lexeme) ) ;
;
#line 216 "src/parser.z"
return expr;
;
}

#line 219 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser19parse_float_literalE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 221 "src/parser.z"
_ZN4main6tokens5TokenE tok = _ZN4main6parser6expectE(ctx,TokenKind_Float) ;
;
#line 223 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Literal) ;
;
#line 224 "src/parser.z"
expr->node.lit.kind = LiteralKind_Float;
;
#line 226 "src/parser.z"
_ZN4main7session7SessionE*  sess = ctx->sess;
;
#line 227 "src/parser.z"
expr->node.lit.value.floating = atof(_ZN4main9interning7get_strE(&sess->interner,tok.lexeme) ) ;
;
#line 228 "src/parser.z"
return expr;
;
}

#line 231 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser18parse_char_literalE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 233 "src/parser.z"
_ZN4main6tokens5TokenE tok = _ZN4main6parser6expectE(ctx,TokenKind_Char) ;
;
#line 235 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Literal) ;
;
#line 236 "src/parser.z"
expr->node.lit.kind = LiteralKind_Char;
;
#line 238 "src/parser.z"
_ZN4main7session7SessionE*  sess = ctx->sess;
;
#line 239 "src/parser.z"
char*  s = _ZN4main9interning7get_strE(&sess->interner,tok.lexeme) ;
;
#line 241 "src/parser.z"
u32 len = strlen(s) ;
;
#line 242 "src/parser.z"
if (((len== 2)&& (s[0]== '\\'))){
#line 243 "src/parser.z"
char c ;
;
#line 244 "src/parser.z"
if ((s[1]== 'n')){
#line 244 "src/parser.z"
c = '\n';
;
}
else {
#line 245 "src/parser.z"
if ((s[1]== 't')){
#line 245 "src/parser.z"
c = '\t';
;
}
else {
#line 246 "src/parser.z"
if ((s[1]== 'r')){
#line 246 "src/parser.z"
c = '\r';
;
}
else {
#line 247 "src/parser.z"
if ((s[1]== '\\')){
#line 247 "src/parser.z"
c = '\\';
;
}
else {
#line 248 "src/parser.z"
if ((s[1]== '\'')){
#line 248 "src/parser.z"
c = '\'';
;
}
else {
#line 249 "src/parser.z"
_ZN4main5error10emit_errorE(ctx->source_map,tok.span,"Unknown escape sequence") ;
}
;
}
;
}
;
}
;
}
;
#line 250 "src/parser.z"
expr->node.lit.value.ch = c;
;
}
else {
#line 251 "src/parser.z"
if ((len== 1)){
#line 252 "src/parser.z"
expr->node.lit.value.ch = s[0];
;
}
else {
#line 254 "src/parser.z"
_ZN4main5error10emit_errorE(ctx->source_map,tok.span,"Invalid char literal") ;
}
;
}
;
#line 256 "src/parser.z"
return expr;
;
}

#line 259 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser20parse_string_literalE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 261 "src/parser.z"
_ZN4main6tokens5TokenE tok = _ZN4main6parser6expectE(ctx,TokenKind_String) ;
;
#line 263 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Literal) ;
;
#line 264 "src/parser.z"
expr->node.lit.kind = LiteralKind_Str;
;
#line 266 "src/parser.z"
expr->node.lit.value.str = tok.lexeme;
;
#line 267 "src/parser.z"
return expr;
;
}

#line 270 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser18parse_bool_literalE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 272 "src/parser.z"
_ZN4main6tokens5TokenE tok = _ZN4main6parser7consumeE(ctx) ;
;
#line 274 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Literal) ;
;
#line 275 "src/parser.z"
expr->node.lit.kind = LiteralKind_Bool;
;
#line 276 "src/parser.z"
expr->node.lit.value.boolean = (tok.kind== TokenKind_True);
;
#line 277 "src/parser.z"
return expr;
;
}

#line 280 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser10parse_callE(_ZN4main6parser14ParsingContextE*  ctx, _ZN4main3ast4ExprE*  left) {
#line 282 "src/parser.z"
_ZN4main3ast4ExprE*  result = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Call) ;
;
#line 283 "src/parser.z"
result->node.call.func = left;
;
#line 284 "src/parser.z"
result->node.call.args = malloc((8* 16)) ;
;
#line 285 "src/parser.z"
result->node.call.num_args = 0;
;
#line 287 "src/parser.z"
if (!_ZN4main6parser6acceptE(ctx,TokenKind_RightParen) ){
#line 288 "src/parser.z"
while ( true)
{
#line 289 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main6parser16parse_expressionE(ctx,0) ;
;
#line 290 "src/parser.z"
result->node.call.args[result->node.call.num_args] = expr;
;
#line 291 "src/parser.z"
result->node.call.num_args = (result->node.call.num_args+ 1);
;
#line 292 "src/parser.z"
if (!_ZN4main6parser6acceptE(ctx,TokenKind_Comma) ){
#line 292 "src/parser.z"
break;
;
}
;
}
;
#line 294 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_RightParen) ;
}
;
#line 297 "src/parser.z"
return result;
;
}

#line 301 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser21parse_prefix_operatorE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 302 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Unary) ;
;
#line 304 "src/parser.z"
_ZN4main6tokens5TokenE tok = _ZN4main6parser7consumeE(ctx) ;
;
#line 306 "src/parser.z"
if ((tok.kind== TokenKind_Minus)){
#line 306 "src/parser.z"
expr->node.unary.op = UnaryOperatorKind_Negation;
;
}
else {
#line 307 "src/parser.z"
if ((tok.kind== TokenKind_Bang)){
#line 307 "src/parser.z"
expr->node.unary.op = UnaryOperatorKind_Complement;
;
}
else {
#line 308 "src/parser.z"
if ((tok.kind== TokenKind_And)){
#line 308 "src/parser.z"
expr->node.unary.op = UnaryOperatorKind_Refer;
;
}
else {
#line 309 "src/parser.z"
if ((tok.kind== TokenKind_Star)){
#line 309 "src/parser.z"
expr->node.unary.op = UnaryOperatorKind_Deref;
;
}
else {
#line 310 "src/parser.z"
_ZN4main5error10emit_errorE(ctx->source_map,tok.span,"Invalid prefix operator") ;
}
;
}
;
}
;
}
;
#line 312 "src/parser.z"
expr->node.unary.inner = _ZN4main6parser16parse_expressionE(ctx,11) ;
;
#line 314 "src/parser.z"
return expr;
;
}

#line 317 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser21parse_binary_operatorE(_ZN4main6parser14ParsingContextE*  ctx, _ZN4main3ast4ExprE*  left, _ZN4main3ast18BinaryOperatorKindE operator) {
#line 318 "src/parser.z"
u32 precedence = _ZN4main6parser30get_binary_operator_precedenceE(operator) ;
;
#line 319 "src/parser.z"
_ZN4main3ast4ExprE*  right = _ZN4main6parser16parse_expressionE(ctx,precedence) ;
;
#line 321 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Binary) ;
;
#line 322 "src/parser.z"
expr->node.binary.op = operator;
;
#line 323 "src/parser.z"
expr->node.binary.left = left;
;
#line 324 "src/parser.z"
expr->node.binary.right = right;
;
#line 326 "src/parser.z"
return expr;
;
}

#line 329 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser18parse_field_accessE(_ZN4main6parser14ParsingContextE*  ctx, _ZN4main3ast4ExprE*  left) {
#line 330 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Field) ;
;
#line 331 "src/parser.z"
expr->node.field.ident = _ZN4main6parser16parse_identifierE(ctx) ;
;
#line 332 "src/parser.z"
expr->node.field.strct = left;
;
#line 334 "src/parser.z"
return expr;
;
}

#line 337 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser14parse_indexingE(_ZN4main6parser14ParsingContextE*  ctx, _ZN4main3ast4ExprE*  left) {
#line 339 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Indexing) ;
;
#line 340 "src/parser.z"
expr->node.indexing.index = _ZN4main6parser16parse_expressionE(ctx,0) ;
;
#line 341 "src/parser.z"
expr->node.indexing.array = left;
;
#line 343 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_RightBracket) ;
#line 345 "src/parser.z"
return expr;
;
}

#line 348 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser16parse_assignmentE(_ZN4main6parser14ParsingContextE*  ctx, _ZN4main3ast4ExprE*  left) {
#line 349 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Assignment) ;
;
#line 350 "src/parser.z"
expr->node.assignment.left = left;
;
#line 351 "src/parser.z"
expr->node.assignment.right = _ZN4main6parser16parse_expressionE(ctx,0) ;
;
#line 353 "src/parser.z"
return expr;
;
}

#line 356 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser20parse_infix_operatorE(_ZN4main6parser14ParsingContextE*  ctx, _ZN4main3ast4ExprE*  left, _ZN4main6tokens5TokenE tok) {
#line 358 "src/parser.z"
if ((tok.kind== TokenKind_LeftParen)){
#line 358 "src/parser.z"
return _ZN4main6parser10parse_callE(ctx,left) ;
;
}
;
#line 359 "src/parser.z"
if ((tok.kind== TokenKind_Dot)){
#line 359 "src/parser.z"
return _ZN4main6parser18parse_field_accessE(ctx,left) ;
;
}
;
#line 360 "src/parser.z"
if ((tok.kind== TokenKind_LeftBracket)){
#line 360 "src/parser.z"
return _ZN4main6parser14parse_indexingE(ctx,left) ;
;
}
;
#line 361 "src/parser.z"
if ((tok.kind== TokenKind_Equal)){
#line 361 "src/parser.z"
return _ZN4main6parser16parse_assignmentE(ctx,left) ;
;
}
;
#line 363 "src/parser.z"
_ZN4main3ast18BinaryOperatorKindE op = _ZN4main6parser32convert_token_to_binary_operatorE(tok.kind) ;
;
#line 364 "src/parser.z"
if ((op!= BinaryOperatorKind_Invalid)){
#line 365 "src/parser.z"
return _ZN4main6parser21parse_binary_operatorE(ctx,left,op) ;
;
}
else {
#line 367 "src/parser.z"
_ZN4main5error10emit_errorE(ctx->source_map,tok.span,"Unsupported infix operator") ;
}
;
#line 368 "src/parser.z"
return _ZN4main4cstd4nullE;
;
}

#line 371 "src/parser.z"
_ZN4main3ast5BlockE*  _ZN4main6parser11parse_blockE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 373 "src/parser.z"
_ZN4main3ast5BlockE*  block = malloc(sizeof(_ZN4main3ast5BlockE)) ;
;
#line 374 "src/parser.z"
block->exprs = malloc((8* 128)) ;
;
#line 375 "src/parser.z"
block->num_exprs = 0;
;
#line 376 "src/parser.z"
block->span.from = _ZN4main6parser10span_startE(ctx) ;
;
#line 378 "src/parser.z"
_ZN4main6tokens5TokenE next = _ZN4main6parser10look_aheadE(ctx,0) ;
;
#line 379 "src/parser.z"
if ((next.kind== TokenKind_LeftCurly)){
#line 380 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_LeftCurly) ;
#line 381 "src/parser.z"
u32 i = 0;
;
#line 382 "src/parser.z"
while ( !_ZN4main6parser6acceptE(ctx,TokenKind_RightCurly) )
{
#line 383 "src/parser.z"
block->exprs[i] = _ZN4main6parser16parse_expressionE(ctx,0) ;
;
#line 384 "src/parser.z"
block->num_exprs = (block->num_exprs+ 1);
;
#line 385 "src/parser.z"
i = (i+ 1);
;
}
;
}
else {
#line 388 "src/parser.z"
block->exprs[0] = _ZN4main6parser16parse_expressionE(ctx,0) ;
;
#line 389 "src/parser.z"
block->num_exprs = 1;
;
}
;
#line 391 "src/parser.z"
block->span.to = _ZN4main6parser8span_endE(ctx) ;
;
#line 393 "src/parser.z"
return block;
;
}

#line 396 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser16parse_block_exprE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 397 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Block) ;
;
#line 398 "src/parser.z"
expr->node.block = _ZN4main6parser11parse_blockE(ctx) ;
;
#line 399 "src/parser.z"
return expr;
;
}

#line 402 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser8parse_ifE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 404 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_If) ;
#line 406 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Conditional) ;
;
#line 407 "src/parser.z"
expr->node.conditional.condition = _ZN4main6parser16parse_expressionE(ctx,0) ;
;
#line 408 "src/parser.z"
expr->node.conditional.then = _ZN4main6parser16parse_block_exprE(ctx) ;
;
#line 410 "src/parser.z"
if (_ZN4main6parser6acceptE(ctx,TokenKind_Else) ){
#line 411 "src/parser.z"
expr->node.conditional.otherwise = _ZN4main6parser16parse_block_exprE(ctx) ;
;
}
else {
#line 413 "src/parser.z"
expr->node.conditional.otherwise = _ZN4main4cstd4nullE;
;
}
;
#line 416 "src/parser.z"
return expr;
;
}

#line 419 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser11parse_whileE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 420 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_While) ;
#line 422 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_While) ;
;
#line 423 "src/parser.z"
expr->node.whl.condition = _ZN4main6parser16parse_expressionE(ctx,0) ;
;
#line 424 "src/parser.z"
expr->node.whl.body = _ZN4main6parser16parse_block_exprE(ctx) ;
;
#line 426 "src/parser.z"
return expr;
;
}

#line 429 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser12parse_sizeofE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 430 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_Sizeof) ;
#line 431 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_LeftParen) ;
#line 433 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Sizeof) ;
;
#line 434 "src/parser.z"
expr->node._sizeof = _ZN4main6parser16parse_expressionE(ctx,0) ;
;
#line 435 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_RightParen) ;
#line 437 "src/parser.z"
return expr;
;
}

#line 440 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser9parse_letE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 442 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Let) ;
;
#line 443 "src/parser.z"
_ZN4main6parser7consumeE(ctx) ;
#line 444 "src/parser.z"
expr->node._let.pat = _ZN4main6parser13parse_patternE(ctx) ;
;
#line 445 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_Colon) ;
#line 446 "src/parser.z"
expr->node._let.ast_ty = _ZN4main6parser10parse_typeE(ctx) ;
;
#line 448 "src/parser.z"
if (_ZN4main6parser6acceptE(ctx,TokenKind_Equal) ){
#line 448 "src/parser.z"
expr->node._let.value = _ZN4main6parser16parse_expressionE(ctx,0) ;
;
}
else {
#line 449 "src/parser.z"
expr->node._let.value = 0;
;
}
;
#line 451 "src/parser.z"
return expr;
;
}

#line 455 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser18parse_control_flowE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 456 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_ControlFlow) ;
;
#line 457 "src/parser.z"
expr->node.control_flow_is_continue = _ZN4main6parser6acceptE(ctx,TokenKind_Continue) ;
;
#line 459 "src/parser.z"
if (!expr->node.control_flow_is_continue){
#line 459 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_Break) ;
}
;
#line 461 "src/parser.z"
return expr;
;
}

#line 464 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser12parse_returnE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 465 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_Return) ;
#line 466 "src/parser.z"
_ZN4main3ast4ExprE*  expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Return) ;
;
#line 467 "src/parser.z"
expr->node._return = _ZN4main6parser16parse_expressionE(ctx,0) ;
;
#line 469 "src/parser.z"
return expr;
;
}

#line 472 "src/parser.z"
_ZN4main3ast4ExprE*  _ZN4main6parser16parse_expressionE(_ZN4main6parser14ParsingContextE*  ctx, u32 precedence) {
#line 473 "src/parser.z"
_ZN4main6tokens5TokenE tok = _ZN4main6parser10look_aheadE(ctx,0) ;
;
#line 474 "src/parser.z"
_ZN4main10source_map4SpanE span ;
;
#line 475 "src/parser.z"
span.from = _ZN4main6parser10span_startE(ctx) ;
;
#line 477 "src/parser.z"
_ZN4main3ast4ExprE*  left ;
;
#line 479 "src/parser.z"
if ((tok.kind== TokenKind_Integer)){
#line 479 "src/parser.z"
left = _ZN4main6parser21parse_integer_literalE(ctx) ;
;
}
else {
#line 480 "src/parser.z"
if ((tok.kind== TokenKind_Char)){
#line 480 "src/parser.z"
left = _ZN4main6parser18parse_char_literalE(ctx) ;
;
}
else {
#line 481 "src/parser.z"
if ((tok.kind== TokenKind_String)){
#line 481 "src/parser.z"
left = _ZN4main6parser20parse_string_literalE(ctx) ;
;
}
else {
#line 482 "src/parser.z"
if ((tok.kind== TokenKind_Float)){
#line 482 "src/parser.z"
left = _ZN4main6parser19parse_float_literalE(ctx) ;
;
}
else {
#line 483 "src/parser.z"
if (((tok.kind== TokenKind_False)|| (tok.kind== TokenKind_True))){
#line 483 "src/parser.z"
left = _ZN4main6parser18parse_bool_literalE(ctx) ;
;
}
else {
#line 484 "src/parser.z"
if (((((tok.kind== TokenKind_Minus)|| (tok.kind== TokenKind_Bang))|| (tok.kind== TokenKind_And))|| (tok.kind== TokenKind_Star))){
#line 485 "src/parser.z"
left = _ZN4main6parser21parse_prefix_operatorE(ctx) ;
;
}
else {
#line 486 "src/parser.z"
if ((tok.kind== TokenKind_If)){
#line 486 "src/parser.z"
left = _ZN4main6parser8parse_ifE(ctx) ;
;
}
else {
#line 487 "src/parser.z"
if ((tok.kind== TokenKind_Sizeof)){
#line 487 "src/parser.z"
left = _ZN4main6parser12parse_sizeofE(ctx) ;
;
}
else {
#line 488 "src/parser.z"
if ((tok.kind== TokenKind_While)){
#line 488 "src/parser.z"
left = _ZN4main6parser11parse_whileE(ctx) ;
;
}
else {
#line 489 "src/parser.z"
if (((tok.kind== TokenKind_Continue)|| (tok.kind== TokenKind_Break))){
#line 489 "src/parser.z"
left = _ZN4main6parser18parse_control_flowE(ctx) ;
;
}
else {
#line 490 "src/parser.z"
if ((tok.kind== TokenKind_Return)){
#line 490 "src/parser.z"
left = _ZN4main6parser12parse_returnE(ctx) ;
;
}
else {
#line 491 "src/parser.z"
if (((tok.kind== TokenKind_Var)|| (tok.kind== TokenKind_Val))){
#line 491 "src/parser.z"
left = _ZN4main6parser9parse_letE(ctx) ;
;
}
else {
#line 492 "src/parser.z"
if ((tok.kind== TokenKind_Identifier)){
#line 492 "src/parser.z"
left = _ZN4main6parser15parse_path_exprE(ctx) ;
;
}
else {
#line 493 "src/parser.z"
if ((tok.kind== TokenKind_LeftParen)){
#line 494 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_LeftParen) ;
#line 495 "src/parser.z"
left = _ZN4main6parser16parse_expressionE(ctx,0) ;
;
#line 496 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_RightParen) ;
}
else {
#line 498 "src/parser.z"
if ((tok.kind== TokenKind_LeftCurly)){
#line 498 "src/parser.z"
left = _ZN4main6parser16parse_block_exprE(ctx) ;
;
}
else {
#line 499 "src/parser.z"
_ZN4main5error10emit_errorE(ctx->source_map,tok.span,"Invalid expression prefix") ;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
#line 501 "src/parser.z"
while ( (precedence< _ZN4main6parser22get_current_precedenceE(ctx) ))
{
#line 502 "src/parser.z"
_ZN4main6tokens5TokenE next_tok = _ZN4main6parser7consumeE(ctx) ;
;
#line 503 "src/parser.z"
left = _ZN4main6parser20parse_infix_operatorE(ctx,left,next_tok) ;
;
}
;
#line 505 "src/parser.z"
span.to = _ZN4main6parser8span_endE(ctx) ;
;
#line 506 "src/parser.z"
left->span = span;
;
#line 508 "src/parser.z"
_ZN4main6parser6acceptE(ctx,TokenKind_Semicolon) ;
#line 510 "src/parser.z"
return left;
;
}

#line 513 "src/parser.z"
_ZN4main3ast8GenericsE _ZN4main6parser14parse_genericsE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 514 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_Less) ;
#line 515 "src/parser.z"
_ZN4main3ast8GenericsE generics ;
;
#line 516 "src/parser.z"
generics.parameters = malloc((4* sizeof(_ZN4main3ast12GenericParamE))) ;
;
#line 517 "src/parser.z"
generics.num_parameters = 0;
;
#line 519 "src/parser.z"
while ( !_ZN4main6parser6acceptE(ctx,TokenKind_Greater) )
{
#line 520 "src/parser.z"
generics.parameters[generics.num_parameters].ident = _ZN4main6parser16parse_identifierE(ctx) ;
;
#line 522 "src/parser.z"
_ZN4main6parser6acceptE(ctx,TokenKind_Comma) ;
#line 523 "src/parser.z"
generics.num_parameters = (generics.num_parameters+ 1);
;
}
;
#line 525 "src/parser.z"
return generics;
;
}

#line 528 "src/parser.z"
void  _ZN4main6parser19parse_variable_declE(_ZN4main6parser14ParsingContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 530 "src/parser.z"
_ZN4main6tokens5TokenE keyword = _ZN4main6parser7consumeE(ctx) ;
;
#line 531 "src/parser.z"
if ((keyword.kind== TokenKind_Val)){
#line 531 "src/parser.z"
item->kind = ItemKind_Const;
;
}
else {
#line 532 "src/parser.z"
if ((keyword.kind== TokenKind_Var)){
#line 532 "src/parser.z"
item->kind = ItemKind_Variable;
;
}
else {
#line 533 "src/parser.z"
abort() ;
}
;
}
;
#line 535 "src/parser.z"
item->ident = _ZN4main6parser16parse_identifierE(ctx) ;
;
#line 536 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_Colon) ;
#line 537 "src/parser.z"
item->node.variable.ast_ty = _ZN4main6parser10parse_typeE(ctx) ;
;
#line 539 "src/parser.z"
if (_ZN4main6parser6acceptE(ctx,TokenKind_Equal) ){
#line 539 "src/parser.z"
item->node.variable.body = _ZN4main6parser16parse_expressionE(ctx,0) ;
;
}
else {
#line 540 "src/parser.z"
item->node.variable.body = 0;
;
}
;
}

#line 543 "src/parser.z"
void  _ZN4main6parser19parse_compound_declE(_ZN4main6parser14ParsingContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 545 "src/parser.z"
if (_ZN4main6parser6acceptE(ctx,TokenKind_Struct) ){
#line 545 "src/parser.z"
item->kind = ItemKind_Struct;
;
}
else {
#line 546 "src/parser.z"
if (_ZN4main6parser6acceptE(ctx,TokenKind_Union) ){
#line 546 "src/parser.z"
item->kind = ItemKind_Union;
;
}
else {
#line 547 "src/parser.z"
abort() ;
}
;
}
;
#line 549 "src/parser.z"
item->ident = _ZN4main6parser16parse_identifierE(ctx) ;
;
#line 551 "src/parser.z"
if (_ZN4main6parser10can_acceptE(ctx,TokenKind_Less) ){
#line 551 "src/parser.z"
item->node.compound.generics = _ZN4main6parser14parse_genericsE(ctx) ;
;
}
else {
#line 552 "src/parser.z"
item->node.compound.generics.num_parameters = 0;
;
}
;
#line 554 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_LeftCurly) ;
#line 556 "src/parser.z"
item->node.compound.fields = malloc((sizeof(_ZN4main3ast13CompoundFieldE)* 16)) ;
;
#line 557 "src/parser.z"
item->node.compound.num_fields = 0;
;
#line 559 "src/parser.z"
while ( !_ZN4main6parser6acceptE(ctx,TokenKind_RightCurly) )
{
#line 560 "src/parser.z"
_ZN4main6tokens5TokenE token = _ZN4main6parser7consumeE(ctx) ;
;
#line 561 "src/parser.z"
if ((token.kind!= TokenKind_Identifier)){
#line 561 "src/parser.z"
_ZN4main5error10emit_errorE(ctx->source_map,token.span,"Expected field identifier") ;
}
;
#line 563 "src/parser.z"
item->node.compound.fields[item->node.compound.num_fields].ident.name = token.lexeme;
;
#line 564 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_Colon) ;
#line 566 "src/parser.z"
_ZN4main3ast7AstTypeE*  type = _ZN4main6parser10parse_typeE(ctx) ;
;
#line 567 "src/parser.z"
item->node.compound.fields[item->node.compound.num_fields].ast_ty = type;
;
#line 568 "src/parser.z"
item->node.compound.num_fields = (item->node.compound.num_fields+ 1);
;
#line 569 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_Comma) ;
}
;
}

#line 574 "src/parser.z"
void  _ZN4main6parser15parse_enum_declE(_ZN4main6parser14ParsingContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 576 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_Enum) ;
#line 577 "src/parser.z"
item->kind = ItemKind_Enum;
;
#line 579 "src/parser.z"
item->ident = _ZN4main6parser16parse_identifierE(ctx) ;
;
#line 581 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_LeftCurly) ;
#line 583 "src/parser.z"
item->node._enum.variants = malloc((sizeof(_ZN4main3ast11EnumVariantE)* 128)) ;
;
#line 584 "src/parser.z"
item->node._enum.num_variants = 0;
;
#line 586 "src/parser.z"
while ( !_ZN4main6parser6acceptE(ctx,TokenKind_RightCurly) )
{
#line 587 "src/parser.z"
item->node._enum.variants[item->node._enum.num_variants].ident = _ZN4main6parser16parse_identifierE(ctx) ;
;
#line 588 "src/parser.z"
item->node._enum.variants[item->node._enum.num_variants]._enum = item;
;
#line 589 "src/parser.z"
item->node._enum.num_variants = (item->node._enum.num_variants+ 1);
;
#line 590 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_Comma) ;
}
;
}

#line 594 "src/parser.z"
_ZN4main3ast14FunctionHeaderE _ZN4main6parser21parse_function_headerE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 595 "src/parser.z"
_ZN4main3ast14FunctionHeaderE header ;
;
#line 597 "src/parser.z"
header.parameters = malloc((sizeof(_ZN4main3ast17FunctionParameterE)* 16)) ;
;
#line 598 "src/parser.z"
header.num_parameters = 0;
;
#line 600 "src/parser.z"
if (_ZN4main6parser10can_acceptE(ctx,TokenKind_Less) ){
#line 600 "src/parser.z"
header.generics = _ZN4main6parser14parse_genericsE(ctx) ;
;
}
else {
#line 601 "src/parser.z"
header.generics.num_parameters = 0;
;
}
;
#line 603 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_LeftParen) ;
#line 605 "src/parser.z"
while ( !_ZN4main6parser6acceptE(ctx,TokenKind_RightParen) )
{
#line 607 "src/parser.z"
header.parameters[header.num_parameters].pat = _ZN4main6parser13parse_patternE(ctx) ;
;
#line 609 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_Colon) ;
#line 610 "src/parser.z"
_ZN4main3ast7AstTypeE*  type = _ZN4main6parser10parse_typeE(ctx) ;
;
#line 611 "src/parser.z"
header.parameters[header.num_parameters].ast_ty = type;
;
#line 612 "src/parser.z"
header.num_parameters = (header.num_parameters+ 1);
;
#line 614 "src/parser.z"
_ZN4main6parser6acceptE(ctx,TokenKind_Comma) ;
}
;
#line 617 "src/parser.z"
if (_ZN4main6parser6acceptE(ctx,TokenKind_Arrow) ){
#line 617 "src/parser.z"
header.output_ast_ty = _ZN4main6parser10parse_typeE(ctx) ;
;
}
else {
#line 620 "src/parser.z"
_ZN4main3ast7AstTypeE*  output = malloc(sizeof(_ZN4main3ast7AstTypeE)) ;
;
#line 621 "src/parser.z"
output->kind = AstTypeKind_Void;
;
#line 622 "src/parser.z"
header.output_ast_ty = output;
;
}
;
#line 625 "src/parser.z"
return header;
;
}

#line 628 "src/parser.z"
void  _ZN4main6parser19parse_function_declE(_ZN4main6parser14ParsingContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 630 "src/parser.z"
item->kind = ItemKind_Function;
;
#line 632 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_Fn) ;
#line 634 "src/parser.z"
item->ident = _ZN4main6parser16parse_identifierE(ctx) ;
;
#line 636 "src/parser.z"
_ZN4main7session7SessionE*  sess = ctx->sess;
;
#line 637 "src/parser.z"
if ((item->ident.name.x== _ZN4main9interning6internE(&sess->interner,"main") .x)){
#line 637 "src/parser.z"
item->should_mangle = false;
;
}
;
#line 639 "src/parser.z"
item->node.function.header = _ZN4main6parser21parse_function_headerE(ctx) ;
;
#line 641 "src/parser.z"
if ((_ZN4main6parser10look_aheadE(ctx,0) .kind== TokenKind_LeftCurly)){
#line 641 "src/parser.z"
item->node.function.body = _ZN4main6parser16parse_expressionE(ctx,0) ;
;
}
else {
#line 642 "src/parser.z"
item->node.function.body = 0;
;
}
;
}

#line 645 "src/parser.z"
void  _ZN4main6parser9parse_useE(_ZN4main6parser14ParsingContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 646 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_Use) ;
#line 648 "src/parser.z"
item->kind = ItemKind_Use;
;
#line 649 "src/parser.z"
item->node._use = _ZN4main6parser10parse_pathE(ctx) ;
;
#line 650 "src/parser.z"
item->ident.name.x = 0;
;
#line 652 "src/parser.z"
_ZN4main6parser6acceptE(ctx,TokenKind_Semicolon) ;
}

#line 655 "src/parser.z"
_ZN4main3ast6ModuleE*  _ZN4main6parser15parse_mod_innerE(_ZN4main6parser14ParsingContextE*  ctx, _ZN4main3ast5IdentE name) ;

#line 656 "src/parser.z"
_ZN4main3ast6ModuleE*  _ZN4main6parser18parse_mod_externalE(_ZN4main7session7SessionE*  sess, _ZN4main3ast3AstE*  ast, char*  path, _ZN4main3ast6ModuleE*  parent) ;

#line 658 "src/parser.z"
void  _ZN4main6parser9parse_modE(_ZN4main6parser14ParsingContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 659 "src/parser.z"
_ZN4main6parser6expectE(ctx,TokenKind_Mod) ;
#line 661 "src/parser.z"
item->ident = _ZN4main6parser16parse_identifierE(ctx) ;
;
#line 662 "src/parser.z"
item->kind = ItemKind_Module;
;
#line 664 "src/parser.z"
if (_ZN4main6parser6acceptE(ctx,TokenKind_LeftCurly) ){
#line 664 "src/parser.z"
item->node.module = _ZN4main6parser15parse_mod_innerE(ctx,item->ident) ;
;
}
else {
#line 666 "src/parser.z"
_ZN4main7session7SessionE*  sess = ctx->sess;
;
#line 667 "src/parser.z"
char*  path = _ZN4main9interning7get_strE(&sess->interner,item->ident.name) ;
;
#line 668 "src/parser.z"
item->node.module = _ZN4main6parser18parse_mod_externalE(ctx->sess,ctx->ast,path,ctx->current_module) ;
;
}
;
}

#line 673 "src/parser.z"
_ZN4main3ast4ItemE*  _ZN4main6parser10parse_itemE(_ZN4main6parser14ParsingContextE*  ctx) {
#line 675 "src/parser.z"
_ZN4main3ast4ItemE*  item = _ZN4main3ast15ast_create_itemE(ctx->ast) ;
;
#line 676 "src/parser.z"
item->span.from = _ZN4main6parser10span_startE(ctx) ;
;
#line 677 "src/parser.z"
item->should_mangle = !_ZN4main6parser6acceptE(ctx,TokenKind_Extern) ;
;
#line 679 "src/parser.z"
_ZN4main6tokens5TokenE tok = _ZN4main6parser10look_aheadE(ctx,0) ;
;
#line 681 "src/parser.z"
if ((tok.kind== TokenKind_Fn)){
#line 681 "src/parser.z"
_ZN4main6parser19parse_function_declE(ctx,item) ;
}
else {
#line 682 "src/parser.z"
if (((tok.kind== TokenKind_Struct)|| (tok.kind== TokenKind_Union))){
#line 682 "src/parser.z"
_ZN4main6parser19parse_compound_declE(ctx,item) ;
}
else {
#line 683 "src/parser.z"
if ((tok.kind== TokenKind_Enum)){
#line 683 "src/parser.z"
_ZN4main6parser15parse_enum_declE(ctx,item) ;
}
else {
#line 684 "src/parser.z"
if (((tok.kind== TokenKind_Var)|| (tok.kind== TokenKind_Val))){
#line 684 "src/parser.z"
_ZN4main6parser19parse_variable_declE(ctx,item) ;
}
else {
#line 685 "src/parser.z"
if ((tok.kind== TokenKind_Use)){
#line 685 "src/parser.z"
_ZN4main6parser9parse_useE(ctx,item) ;
}
else {
#line 686 "src/parser.z"
if ((tok.kind== TokenKind_Mod)){
#line 686 "src/parser.z"
_ZN4main6parser9parse_modE(ctx,item) ;
}
else {
#line 687 "src/parser.z"
_ZN4main5error10emit_errorE(ctx->source_map,tok.span,"Unexpected token on top-level") ;
}
;
}
;
}
;
}
;
}
;
}
;
#line 689 "src/parser.z"
_ZN4main6parser6acceptE(ctx,TokenKind_Semicolon) ;
#line 691 "src/parser.z"
item->span.to = _ZN4main6parser8span_endE(ctx) ;
;
#line 692 "src/parser.z"
return item;
;
}

#line 695 "src/parser.z"
_ZN4main3ast6ModuleE*  _ZN4main6parser15parse_mod_innerE(_ZN4main6parser14ParsingContextE*  ctx, _ZN4main3ast5IdentE name) {
#line 696 "src/parser.z"
_ZN4main3ast6ModuleE*  module = malloc(sizeof(_ZN4main3ast6ModuleE)) ;
;
#line 697 "src/parser.z"
module->span.from = _ZN4main6parser10span_startE(ctx) ;
;
#line 698 "src/parser.z"
module->items = malloc((8* 2048)) ;
;
#line 699 "src/parser.z"
module->num_items = 0;
;
#line 700 "src/parser.z"
module->index_lookup = _ZN4main6intmap13intmap_createE(2048) ;
;
#line 701 "src/parser.z"
module->index = malloc((sizeof(_ZN4main3ast10IndexEntryE)* 2048)) ;
;
#line 702 "src/parser.z"
module->num_indices = 1;
;
#line 703 "src/parser.z"
module->parent = ctx->current_module;
;
#line 705 "src/parser.z"
_ZN4main3ast6ModuleE*  parent = module->parent;
;
#line 707 "src/parser.z"
if (parent){
#line 707 "src/parser.z"
module->path.num_segments = (parent->path.num_segments+ 1);
;
}
else {
#line 708 "src/parser.z"
module->path.num_segments = 1;
;
}
;
#line 710 "src/parser.z"
module->path.segments = malloc((sizeof(_ZN4main3ast5IdentE)* module->path.num_segments)) ;
;
#line 711 "src/parser.z"
if (parent){
#line 711 "src/parser.z"
memcpy(module->path.segments,parent->path.segments,(parent->path.num_segments* sizeof(_ZN4main3ast5IdentE))) ;
}
;
#line 712 "src/parser.z"
module->path.segments[(module->path.num_segments- 1)] = name;
;
#line 714 "src/parser.z"
ctx->current_module = module;
;
#line 716 "src/parser.z"
while ( (!_ZN4main6parser6acceptE(ctx,TokenKind_RightCurly) && !_ZN4main6parser15is_done_parsingE(ctx) ))
{
#line 717 "src/parser.z"
module->items[module->num_items] = _ZN4main6parser10parse_itemE(ctx) ;
;
#line 718 "src/parser.z"
module->num_items = (module->num_items+ 1);
;
}
;
#line 721 "src/parser.z"
module->span.to = _ZN4main6parser8span_endE(ctx) ;
;
#line 723 "src/parser.z"
ctx->current_module = module->parent;
;
#line 725 "src/parser.z"
return module;
;
}

#line 728 "src/parser.z"
_ZN4main3ast6ModuleE*  _ZN4main6parser18parse_mod_externalE(_ZN4main7session7SessionE*  sess, _ZN4main3ast3AstE*  ast, char*  path, _ZN4main3ast6ModuleE*  parent) {
#line 730 "src/parser.z"
_ZN4main10source_map10SourceFileE*  source_file = _ZN4main10source_map19source_map_new_fileE(&sess->source,sess->root_path,path) ;
;
#line 732 "src/parser.z"
u32 num_tokens ;
;
#line 733 "src/parser.z"
_ZN4main6tokens5TokenE*  tokens = _ZN4main5lexer3lexE(sess,source_file,&num_tokens) ;
;
#line 735 "src/parser.z"
_ZN4main6parser14ParsingContextE ctx ;
;
#line 736 "src/parser.z"
ctx.current_token = 0;
;
#line 737 "src/parser.z"
ctx.tokens = tokens;
;
#line 738 "src/parser.z"
ctx.num_tokens = num_tokens;
;
#line 739 "src/parser.z"
ctx.source_map = &sess->source;
;
#line 740 "src/parser.z"
ctx.sess = sess;
;
#line 741 "src/parser.z"
ctx.ast = ast;
;
#line 742 "src/parser.z"
ctx.current_module = parent;
;
#line 744 "src/parser.z"
_ZN4main3ast5IdentE name_ident ;
;
#line 745 "src/parser.z"
name_ident.name = _ZN4main9interning6internE(&sess->interner,path) ;
;
#line 746 "src/parser.z"
name_ident.span.from = 0;
;
#line 747 "src/parser.z"
name_ident.span.to = 0;
;
#line 749 "src/parser.z"
_ZN4main3ast6ModuleE*  module = _ZN4main6parser15parse_mod_innerE(&ctx,name_ident) ;
;
#line 751 "src/parser.z"
return module;
;
}

#line 754 "src/parser.z"
_ZN4main3ast6ModuleE*  _ZN4main6parser18create_root_moduleE(_ZN4main7session7SessionE*  sess, _ZN4main3ast3AstE*  ast, char*  path) {
#line 756 "src/parser.z"
_ZN4main3ast6ModuleE*  module = malloc(sizeof(_ZN4main3ast6ModuleE)) ;
;
#line 757 "src/parser.z"
module->items = malloc((8* 2048)) ;
;
#line 758 "src/parser.z"
module->index_lookup = _ZN4main6intmap13intmap_createE(2048) ;
;
#line 759 "src/parser.z"
module->index = malloc((sizeof(_ZN4main3ast10IndexEntryE)* 2048)) ;
;
#line 760 "src/parser.z"
module->num_indices = 1;
;
#line 761 "src/parser.z"
module->parent = _ZN4main4cstd4nullE;
;
#line 762 "src/parser.z"
module->path.num_segments = 0;
;
#line 764 "src/parser.z"
_ZN4main3ast4ItemE*  main_item = _ZN4main3ast15ast_create_itemE(ast) ;
;
#line 765 "src/parser.z"
main_item->kind = ItemKind_Module;
;
#line 766 "src/parser.z"
main_item->ident.name = _ZN4main9interning6internE(&sess->interner,path) ;
;
#line 768 "src/parser.z"
_ZN4main3ast6ModuleE*  main_module = _ZN4main6parser18parse_mod_externalE(sess,ast,path,module) ;
;
#line 769 "src/parser.z"
main_item->span.from = main_module->span.from;
;
#line 770 "src/parser.z"
main_item->span.to = main_module->span.to;
;
#line 771 "src/parser.z"
main_item->node.module = main_module;
;
#line 772 "src/parser.z"
module->items[0] = main_item;
;
#line 773 "src/parser.z"
module->num_items = 1;
;
#line 775 "src/parser.z"
return module;
;
}

#line 778 "src/parser.z"
_ZN4main3ast3AstE _ZN4main6parser5parseE(_ZN4main7session7SessionE*  sess, char*  root_module_name) {
#line 780 "src/parser.z"
_ZN4main3ast3AstE ast ;
;
#line 782 "src/parser.z"
ast.items = malloc((sizeof(_ZN4main3ast4ItemE)* 2048)) ;
;
#line 783 "src/parser.z"
ast.num_items = 1;
;
#line 785 "src/parser.z"
ast.root_module = _ZN4main6parser18create_root_moduleE(sess,&ast,root_module_name) ;
;
#line 787 "src/parser.z"
return ast;
;
}








#line 8 "src/resolution.z"
typedef enum _ZN4main10resolution16VariableInfoKindE {
VariableInfoKind_Variable,
VariableInfoKind_Parameter,
} _ZN4main10resolution16VariableInfoKindE;


typedef union _ZN4main10resolution16VariableInfoNodeE _ZN4main10resolution16VariableInfoNodeE;
#line 13 "src/resolution.z"
typedef union _ZN4main10resolution16VariableInfoNodeE {
_ZN4main3ast7LetDataE*  variable;
_ZN4main3ast17FunctionParameterE*  parameter;
} _ZN4main10resolution16VariableInfoNodeE;


typedef struct _ZN4main10resolution12VariableInfoE _ZN4main10resolution12VariableInfoE;
#line 18 "src/resolution.z"
typedef struct _ZN4main10resolution12VariableInfoE {
_ZN4main3ast5IdentE ident;
_ZN4main10resolution16VariableInfoKindE kind;
_ZN4main10resolution16VariableInfoNodeE node;
} _ZN4main10resolution12VariableInfoE;


typedef struct _ZN4main10resolution13VariableBlockE _ZN4main10resolution13VariableBlockE;
#line 24 "src/resolution.z"
typedef struct _ZN4main10resolution13VariableBlockE {
_ZN4main10resolution12VariableInfoE*  variables;
u32 num_variables;
} _ZN4main10resolution13VariableBlockE;


#line 29 "src/resolution.z"
typedef enum _ZN4main10resolution9ScopeKindE {
ScopeKind_VariableBlock,
ScopeKind_Module,
} _ZN4main10resolution9ScopeKindE;


typedef union _ZN4main10resolution9ScopeNodeE _ZN4main10resolution9ScopeNodeE;
#line 34 "src/resolution.z"
typedef union _ZN4main10resolution9ScopeNodeE {
_ZN4main3ast6ModuleE*  module;
_ZN4main10resolution13VariableBlockE variable;
} _ZN4main10resolution9ScopeNodeE;


typedef struct _ZN4main10resolution5ScopeE _ZN4main10resolution5ScopeE;
#line 39 "src/resolution.z"
typedef struct _ZN4main10resolution5ScopeE {
_ZN4main10resolution9ScopeKindE kind;
_ZN4main10resolution9ScopeNodeE node;
} _ZN4main10resolution5ScopeE;


typedef struct _ZN4main10resolution17PrimitiveTypeSidsE _ZN4main10resolution17PrimitiveTypeSidsE;
#line 44 "src/resolution.z"
typedef struct _ZN4main10resolution17PrimitiveTypeSidsE {
_ZN4main9interning3SidE _void;
_ZN4main9interning3SidE _constvoid;
_ZN4main9interning3SidE _bool;
_ZN4main9interning3SidE _char;
_ZN4main9interning3SidE _constchar;
_ZN4main9interning3SidE _i8;
_ZN4main9interning3SidE _i16;
_ZN4main9interning3SidE _i32;
_ZN4main9interning3SidE _i64;
_ZN4main9interning3SidE _u8;
_ZN4main9interning3SidE _u16;
_ZN4main9interning3SidE _u32;
_ZN4main9interning3SidE _u64;
_ZN4main9interning3SidE _f32;
_ZN4main9interning3SidE _f64;
} _ZN4main10resolution17PrimitiveTypeSidsE;


#line 62 "src/resolution.z"
void  _ZN4main10resolution23setup_primitive_ty_sidsE(_ZN4main9interning8InternerE*  i, _ZN4main10resolution17PrimitiveTypeSidsE*  p) {
#line 63 "src/resolution.z"
p->_void = _ZN4main9interning6internE(i,"void") ;
;
#line 64 "src/resolution.z"
p->_constvoid = _ZN4main9interning6internE(i,"constvoid") ;
;
#line 65 "src/resolution.z"
p->_bool = _ZN4main9interning6internE(i,"bool") ;
;
#line 66 "src/resolution.z"
p->_char = _ZN4main9interning6internE(i,"char") ;
;
#line 67 "src/resolution.z"
p->_constchar = _ZN4main9interning6internE(i,"constchar") ;
;
#line 68 "src/resolution.z"
p->_i8 = _ZN4main9interning6internE(i,"i8") ;
;
#line 69 "src/resolution.z"
p->_i16 = _ZN4main9interning6internE(i,"i16") ;
;
#line 70 "src/resolution.z"
p->_i32 = _ZN4main9interning6internE(i,"i32") ;
;
#line 71 "src/resolution.z"
p->_i64 = _ZN4main9interning6internE(i,"i64") ;
;
#line 72 "src/resolution.z"
p->_u8 = _ZN4main9interning6internE(i,"u8") ;
;
#line 73 "src/resolution.z"
p->_u16 = _ZN4main9interning6internE(i,"u16") ;
;
#line 74 "src/resolution.z"
p->_u32 = _ZN4main9interning6internE(i,"u32") ;
;
#line 75 "src/resolution.z"
p->_u64 = _ZN4main9interning6internE(i,"u64") ;
;
#line 76 "src/resolution.z"
p->_f32 = _ZN4main9interning6internE(i,"f32") ;
;
#line 77 "src/resolution.z"
p->_f64 = _ZN4main9interning6internE(i,"f64") ;
;
}

typedef struct _ZN4main10resolution17ResolutionContextE _ZN4main10resolution17ResolutionContextE;
#line 80 "src/resolution.z"
typedef struct _ZN4main10resolution17ResolutionContextE {
_ZN4main10resolution5ScopeE*  scope_stack;
u32 stack_top;
_ZN4main3ast3AstE*  ast;
_ZN4main10source_map9SourceMapE*  source_map;
_ZN4main9interning8InternerE*  interner;
_ZN4main3ast6ModuleE*  root_module;
_ZN4main10resolution17PrimitiveTypeSidsE primitive_ty_sids;
} _ZN4main10resolution17ResolutionContextE;


#line 90 "src/resolution.z"
void  _ZN4main10resolution10push_blockE(_ZN4main10resolution17ResolutionContextE*  ctx) {
#line 91 "src/resolution.z"
ctx->stack_top = (ctx->stack_top+ 1);
;
#line 92 "src/resolution.z"
_ZN4main10resolution5ScopeE*  scope = &ctx->scope_stack[ctx->stack_top];
;
#line 94 "src/resolution.z"
scope->kind = ScopeKind_VariableBlock;
;
#line 95 "src/resolution.z"
scope->node.variable.variables = malloc((8* 32)) ;
;
#line 96 "src/resolution.z"
scope->node.variable.num_variables = 0;
;
}

#line 99 "src/resolution.z"
void  _ZN4main10resolution9pop_blockE(_ZN4main10resolution17ResolutionContextE*  ctx) {
#line 100 "src/resolution.z"
_ZN4main10resolution5ScopeE*  scope = &ctx->scope_stack[ctx->stack_top];
;
#line 101 "src/resolution.z"
free(scope->node.variable.variables) ;
#line 102 "src/resolution.z"
ctx->stack_top = (ctx->stack_top- 1);
;
}

#line 105 "src/resolution.z"
void  _ZN4main10resolution14push_parameterE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast5IdentE ident, _ZN4main3ast17FunctionParameterE*  data) {
#line 106 "src/resolution.z"
_ZN4main10resolution5ScopeE*  scope = &ctx->scope_stack[ctx->stack_top];
;
#line 107 "src/resolution.z"
if ((scope->kind!= ScopeKind_VariableBlock)){
#line 107 "src/resolution.z"
abort() ;
}
;
#line 108 "src/resolution.z"
_ZN4main10resolution13VariableBlockE*  v = &scope->node.variable;
;
#line 109 "src/resolution.z"
v->variables[v->num_variables].ident = ident;
;
#line 110 "src/resolution.z"
v->variables[v->num_variables].kind = VariableInfoKind_Parameter;
;
#line 111 "src/resolution.z"
v->variables[v->num_variables].node.parameter = data;
;
#line 112 "src/resolution.z"
v->num_variables = (v->num_variables+ 1);
;
}

#line 115 "src/resolution.z"
void  _ZN4main10resolution13push_variableE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast5IdentE ident, _ZN4main3ast7LetDataE*  data) {
#line 116 "src/resolution.z"
_ZN4main10resolution5ScopeE*  scope = &ctx->scope_stack[ctx->stack_top];
;
#line 117 "src/resolution.z"
if ((scope->kind!= ScopeKind_VariableBlock)){
#line 117 "src/resolution.z"
abort() ;
}
;
#line 118 "src/resolution.z"
_ZN4main10resolution13VariableBlockE*  v = &scope->node.variable;
;
#line 119 "src/resolution.z"
v->variables[v->num_variables].ident = ident;
;
#line 120 "src/resolution.z"
v->variables[v->num_variables].kind = VariableInfoKind_Variable;
;
#line 121 "src/resolution.z"
v->variables[v->num_variables].node.variable = data;
;
#line 122 "src/resolution.z"
v->num_variables = (v->num_variables+ 1);
;
}

#line 125 "src/resolution.z"
void  _ZN4main10resolution11push_moduleE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast6ModuleE*  module) {
#line 126 "src/resolution.z"
ctx->stack_top = (ctx->stack_top+ 1);
;
#line 127 "src/resolution.z"
_ZN4main10resolution5ScopeE*  scope = &ctx->scope_stack[ctx->stack_top];
;
#line 129 "src/resolution.z"
scope->kind = ScopeKind_Module;
;
#line 130 "src/resolution.z"
scope->node.module = module;
;
}

#line 133 "src/resolution.z"
void  _ZN4main10resolution10pop_moduleE(_ZN4main10resolution17ResolutionContextE*  ctx) {
#line 134 "src/resolution.z"
ctx->stack_top = (ctx->stack_top- 1);
;
}

#line 139 "src/resolution.z"
_ZN4main3ast4PathE _ZN4main10resolution6lookupE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast5IdentE ident) {
#line 140 "src/resolution.z"
i32 i = ctx->stack_top;
;
#line 141 "src/resolution.z"
while ( (i> 0))
{
#line 142 "src/resolution.z"
_ZN4main10resolution5ScopeE*  scope = &ctx->scope_stack[i];
;
#line 143 "src/resolution.z"
if ((scope->kind== ScopeKind_Module)){
#line 144 "src/resolution.z"
_ZN4main3ast6ModuleE*  module = scope->node.module;
;
#line 145 "src/resolution.z"
u32 idx = _ZN4main6intmap13intmap_lookupE(module->index_lookup,ident.name.x) ;
;
#line 146 "src/resolution.z"
if ((idx> 0)){
#line 147 "src/resolution.z"
_ZN4main3ast10IndexEntryE entry = module->index[idx];
;
#line 148 "src/resolution.z"
return entry.path;
;
}
;
}
else {
#line 151 "src/resolution.z"
if ((scope->kind== ScopeKind_VariableBlock)){
#line 152 "src/resolution.z"
_ZN4main10resolution13VariableBlockE*  block = &scope->node.variable;
;
#line 153 "src/resolution.z"
i32 j = (block->num_variables- 1);
;
#line 154 "src/resolution.z"
while ( (j>= 0))
{
#line 155 "src/resolution.z"
_ZN4main10resolution12VariableInfoE variable = block->variables[j];
;
#line 156 "src/resolution.z"
if ((variable.ident.name.x== ident.name.x)){
#line 157 "src/resolution.z"
_ZN4main3ast4PathE path ;
;
#line 158 "src/resolution.z"
path.segments = malloc(sizeof(_ZN4main3ast5IdentE)) ;
;
#line 159 "src/resolution.z"
path.segments[0] = variable.ident;
;
#line 160 "src/resolution.z"
path.num_segments = 1;
;
#line 161 "src/resolution.z"
if ((variable.kind== VariableInfoKind_Variable)){
#line 162 "src/resolution.z"
path.binding.kind = BindingKind_Variable;
;
#line 163 "src/resolution.z"
path.binding.node.variable = variable.node.variable;
;
}
else {
#line 165 "src/resolution.z"
if ((variable.kind== VariableInfoKind_Parameter)){
#line 166 "src/resolution.z"
path.binding.kind = BindingKind_Parameter;
;
#line 167 "src/resolution.z"
path.binding.node.parameter = variable.node.parameter;
;
}
;
}
;
#line 169 "src/resolution.z"
return path;
;
}
;
#line 171 "src/resolution.z"
j = (j- 1);
;
}
;
}
;
}
;
#line 174 "src/resolution.z"
i = (i- 1);
;
}
;
#line 176 "src/resolution.z"
_ZN4main5error10emit_errorE(ctx->source_map,ident.span,"Unable to resolve item") ;
#line 177 "src/resolution.z"
abort() ;
}

#line 180 "src/resolution.z"
_ZN4main3ast7BindingE _ZN4main10resolution17index_use_bindingE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast4PathE path) {
#line 181 "src/resolution.z"
_ZN4main3ast6ModuleE*  cur_mod = ctx->root_module;
;
#line 182 "src/resolution.z"
u32 i = 0;
;
#line 183 "src/resolution.z"
while ( true)
{
#line 184 "src/resolution.z"
u32 j = 0;
;
#line 185 "src/resolution.z"
bool found = false;
;
#line 186 "src/resolution.z"
while ( (j< cur_mod->num_items))
{
#line 187 "src/resolution.z"
_ZN4main3ast4ItemE*  item = cur_mod->items[j];
;
#line 188 "src/resolution.z"
if ((item->ident.name.x== path.segments[i].name.x)){
#line 189 "src/resolution.z"
if ((item->kind== ItemKind_Module)){
#line 190 "src/resolution.z"
cur_mod = item->node.module;
;
}
else {
#line 192 "src/resolution.z"
if ((i!= (path.num_segments- 1))){
#line 192 "src/resolution.z"
_ZN4main5error10emit_errorE(ctx->source_map,path.span,"Invalid path in use") ;
}
;
}
;
#line 194 "src/resolution.z"
if (((i== (path.num_segments- 1))|| (path.segments[(i+ 1)].name.x== 0))){
#line 195 "src/resolution.z"
_ZN4main3ast7BindingE binding ;
;
#line 196 "src/resolution.z"
binding.kind = BindingKind_Item;
;
#line 197 "src/resolution.z"
binding.node.item = item;
;
#line 198 "src/resolution.z"
return binding;
;
}
;
#line 201 "src/resolution.z"
found = true;
;
#line 202 "src/resolution.z"
break;
;
}
;
#line 204 "src/resolution.z"
j = (j+ 1);
;
}
;
#line 206 "src/resolution.z"
if (!found){
#line 206 "src/resolution.z"
_ZN4main5error10emit_errorE(ctx->source_map,path.span,"Unable to resolve use") ;
}
;
#line 207 "src/resolution.z"
i = (i+ 1);
;
}
;
}

#line 211 "src/resolution.z"
void  _ZN4main10resolution12absolute_useE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast6ModuleE*  module, _ZN4main3ast4ItemE*  item) {
#line 212 "src/resolution.z"
_ZN4main3ast4PathE*  p = &item->node._use;
;
#line 213 "src/resolution.z"
_ZN4main3ast4PathE abs ;
;
#line 214 "src/resolution.z"
if ((p->segments[0].name.x== _ZN4main9interning6internE(ctx->interner,"self") .x)){
#line 215 "src/resolution.z"
abs.num_segments = ((module->path.num_segments+ p->num_segments)- 1);
;
#line 216 "src/resolution.z"
abs.segments = malloc((sizeof(_ZN4main3ast5IdentE)* abs.num_segments)) ;
;
#line 217 "src/resolution.z"
memcpy(abs.segments,module->path.segments,(sizeof(_ZN4main3ast5IdentE)* module->path.num_segments)) ;
#line 218 "src/resolution.z"
memcpy(&abs.segments[module->path.num_segments],&p->segments[1],(sizeof(_ZN4main3ast5IdentE)* (p->num_segments- 1))) ;
#line 219 "src/resolution.z"
*p = abs;
;
}
else {
#line 221 "src/resolution.z"
if ((p->segments[0].name.x== _ZN4main9interning6internE(ctx->interner,"super") .x)){
#line 222 "src/resolution.z"
_ZN4main3ast6ModuleE*  parent = module->parent;
;
#line 223 "src/resolution.z"
abs.num_segments = ((parent->path.num_segments+ p->num_segments)- 1);
;
#line 224 "src/resolution.z"
abs.segments = malloc((sizeof(_ZN4main3ast5IdentE)* abs.num_segments)) ;
;
#line 225 "src/resolution.z"
memcpy(abs.segments,parent->path.segments,(sizeof(_ZN4main3ast5IdentE)* parent->path.num_segments)) ;
#line 226 "src/resolution.z"
memcpy(&abs.segments[parent->path.num_segments],&p->segments[1],(sizeof(_ZN4main3ast5IdentE)* (p->num_segments- 1))) ;
#line 227 "src/resolution.z"
*p = abs;
;
}
;
}
;
}

#line 231 "src/resolution.z"
void  _ZN4main10resolution9index_useE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast6ModuleE*  module) {
#line 232 "src/resolution.z"
u32 i = 0;
;
#line 233 "src/resolution.z"
while ( (i< module->num_items))
{
#line 234 "src/resolution.z"
_ZN4main3ast4ItemE*  item = module->items[i];
;
#line 235 "src/resolution.z"
if ((item->kind== ItemKind_Use)){
#line 236 "src/resolution.z"
_ZN4main10resolution12absolute_useE(ctx,module,item) ;
#line 237 "src/resolution.z"
_ZN4main3ast4PathE*  path = &item->node._use;
;
#line 238 "src/resolution.z"
path->binding = _ZN4main10resolution17index_use_bindingE(ctx,*path) ;
;
}
;
#line 241 "src/resolution.z"
if ((item->kind== ItemKind_Module)){
#line 242 "src/resolution.z"
_ZN4main10resolution9index_useE(ctx,item->node.module) ;
}
;
#line 245 "src/resolution.z"
i = (i+ 1);
;
}
;
}

#line 249 "src/resolution.z"
void  _ZN4main10resolution8add_itemE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast6ModuleE*  module, _ZN4main3ast6ModuleE*  parent, _ZN4main3ast4ItemE*  item) {
#line 251 "src/resolution.z"
_ZN4main3ast10IndexEntryE*  idx_entry = &module->index[module->num_indices];
;
#line 254 "src/resolution.z"
idx_entry->path.num_segments = (parent->path.num_segments+ 1);
;
#line 255 "src/resolution.z"
idx_entry->path.segments = malloc((sizeof(_ZN4main3ast5IdentE)* idx_entry->path.num_segments)) ;
;
#line 256 "src/resolution.z"
memcpy(idx_entry->path.segments,parent->path.segments,(sizeof(_ZN4main3ast5IdentE)* parent->path.num_segments)) ;
#line 257 "src/resolution.z"
idx_entry->path.segments[parent->path.num_segments] = item->ident;
;
#line 258 "src/resolution.z"
idx_entry->path.binding.kind = BindingKind_Item;
;
#line 259 "src/resolution.z"
idx_entry->path.binding.node.item = item;
;
#line 261 "src/resolution.z"
_ZN4main6intmap13intmap_insertE(module->index_lookup,item->ident.name.x,module->num_indices) ;
#line 263 "src/resolution.z"
module->num_indices = (module->num_indices+ 1);
;
}

#line 267 "src/resolution.z"
void  _ZN4main10resolution17add_absolute_itemE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast6ModuleE*  module, _ZN4main3ast4PathE path, _ZN4main3ast4ItemE*  item) {
#line 269 "src/resolution.z"
_ZN4main3ast10IndexEntryE*  idx_entry = &module->index[module->num_indices];
;
#line 272 "src/resolution.z"
idx_entry->path = path;
;
#line 274 "src/resolution.z"
_ZN4main6intmap13intmap_insertE(module->index_lookup,item->ident.name.x,module->num_indices) ;
#line 276 "src/resolution.z"
module->num_indices = (module->num_indices+ 1);
;
}

#line 279 "src/resolution.z"
void  _ZN4main10resolution12index_moduleE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast6ModuleE*  module) {
#line 280 "src/resolution.z"
u32 i = 0;
;
#line 281 "src/resolution.z"
while ( (i< module->num_items))
{
#line 282 "src/resolution.z"
_ZN4main3ast4ItemE*  item = module->items[i];
;
#line 284 "src/resolution.z"
if ((item->kind== ItemKind_Use)){
#line 285 "src/resolution.z"
_ZN4main3ast4PathE path = item->node._use;
;
#line 287 "src/resolution.z"
if ((path.segments[(path.num_segments- 1)].name.x!= 0)){
#line 288 "src/resolution.z"
_ZN4main10resolution17add_absolute_itemE(ctx,module,path,path.binding.node.item) ;
}
;
}
else {
#line 291 "src/resolution.z"
_ZN4main10resolution8add_itemE(ctx,module,module,item) ;
}
;
#line 293 "src/resolution.z"
i = (i+ 1);
;
}
;
#line 296 "src/resolution.z"
i = 0;
;
#line 297 "src/resolution.z"
while ( (i< module->num_items))
{
#line 298 "src/resolution.z"
_ZN4main3ast4ItemE*  item = module->items[i];
;
#line 299 "src/resolution.z"
if ((item->kind== ItemKind_Module)){
#line 299 "src/resolution.z"
_ZN4main10resolution12index_moduleE(ctx,item->node.module) ;
}
;
#line 300 "src/resolution.z"
i = (i+ 1);
;
}
;
}

#line 304 "src/resolution.z"
void  _ZN4main10resolution22index_module_wildcardsE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast6ModuleE*  module) {
#line 305 "src/resolution.z"
u32 i = 0;
;
#line 306 "src/resolution.z"
while ( (i< module->num_items))
{
#line 307 "src/resolution.z"
_ZN4main3ast4ItemE*  item = module->items[i];
;
#line 309 "src/resolution.z"
if ((item->kind== ItemKind_Use)){
#line 310 "src/resolution.z"
_ZN4main3ast4PathE path = item->node._use;
;
#line 311 "src/resolution.z"
if ((path.segments[(path.num_segments- 1)].name.x== 0)){
#line 312 "src/resolution.z"
_ZN4main3ast4ItemE*  bound = path.binding.node.item;
;
#line 313 "src/resolution.z"
if ((bound->kind== ItemKind_Module)){
#line 314 "src/resolution.z"
_ZN4main3ast6ModuleE*  m = bound->node.module;
;
#line 315 "src/resolution.z"
u32 j = 0;
;
#line 316 "src/resolution.z"
while ( (j< m->num_items))
{
#line 317 "src/resolution.z"
_ZN4main3ast4ItemE*  it = m->items[j];
;
#line 318 "src/resolution.z"
_ZN4main10resolution8add_itemE(ctx,module,m,it) ;
#line 319 "src/resolution.z"
j = (j+ 1);
;
}
;
}
else {
#line 322 "src/resolution.z"
abort() ;
}
;
}
;
}
;
#line 325 "src/resolution.z"
i = (i+ 1);
;
}
;
#line 328 "src/resolution.z"
i = 0;
;
#line 329 "src/resolution.z"
while ( (i< module->num_items))
{
#line 330 "src/resolution.z"
_ZN4main3ast4ItemE*  item = module->items[i];
;
#line 331 "src/resolution.z"
if ((item->kind== ItemKind_Module)){
#line 331 "src/resolution.z"
_ZN4main10resolution22index_module_wildcardsE(ctx,item->node.module) ;
}
;
#line 332 "src/resolution.z"
i = (i+ 1);
;
}
;
}

#line 336 "src/resolution.z"
bool _ZN4main10resolution25check_if_sid_is_primitiveE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main9interning3SidE s, _ZN4main3ast11PrimitiveTyE*  prim) {
#line 338 "src/resolution.z"
_ZN4main10resolution17PrimitiveTypeSidsE*  p = &ctx->primitive_ty_sids;
;
#line 339 "src/resolution.z"
if ((s.x== p->_void.x)){
#line 339 "src/resolution.z"
prim->kind = PrimitiveTyKind_Void;
;
}
else {
#line 340 "src/resolution.z"
if ((s.x== p->_constvoid.x)){
#line 340 "src/resolution.z"
prim->kind = PrimitiveTyKind_ConstVoid;
;
}
else {
#line 341 "src/resolution.z"
if ((s.x== p->_bool.x)){
#line 341 "src/resolution.z"
prim->kind = PrimitiveTyKind_Bool;
;
}
else {
#line 342 "src/resolution.z"
if ((s.x== p->_char.x)){
#line 342 "src/resolution.z"
prim->kind = PrimitiveTyKind_Char;
;
}
else {
#line 343 "src/resolution.z"
if ((s.x== p->_constchar.x)){
#line 343 "src/resolution.z"
prim->kind = PrimitiveTyKind_ConstChar;
;
}
else {
#line 345 "src/resolution.z"
if ((s.x== p->_i8.x)){
#line 345 "src/resolution.z"
prim->kind = PrimitiveTyKind_Signed;
;
#line 345 "src/resolution.z"
prim->node.integer = IntegerSize_I8;
;
}
else {
#line 346 "src/resolution.z"
if ((s.x== p->_i16.x)){
#line 346 "src/resolution.z"
prim->kind = PrimitiveTyKind_Signed;
;
#line 346 "src/resolution.z"
prim->node.integer = IntegerSize_I16;
;
}
else {
#line 347 "src/resolution.z"
if ((s.x== p->_i32.x)){
#line 347 "src/resolution.z"
prim->kind = PrimitiveTyKind_Signed;
;
#line 347 "src/resolution.z"
prim->node.integer = IntegerSize_I32;
;
}
else {
#line 348 "src/resolution.z"
if ((s.x== p->_i64.x)){
#line 348 "src/resolution.z"
prim->kind = PrimitiveTyKind_Signed;
;
#line 348 "src/resolution.z"
prim->node.integer = IntegerSize_I64;
;
}
else {
#line 350 "src/resolution.z"
if ((s.x== p->_u8.x)){
#line 350 "src/resolution.z"
prim->kind = PrimitiveTyKind_Unsigned;
;
#line 350 "src/resolution.z"
prim->node.integer = IntegerSize_I8;
;
}
else {
#line 351 "src/resolution.z"
if ((s.x== p->_u16.x)){
#line 351 "src/resolution.z"
prim->kind = PrimitiveTyKind_Unsigned;
;
#line 351 "src/resolution.z"
prim->node.integer = IntegerSize_I16;
;
}
else {
#line 352 "src/resolution.z"
if ((s.x== p->_u32.x)){
#line 352 "src/resolution.z"
prim->kind = PrimitiveTyKind_Unsigned;
;
#line 352 "src/resolution.z"
prim->node.integer = IntegerSize_I32;
;
}
else {
#line 353 "src/resolution.z"
if ((s.x== p->_u64.x)){
#line 353 "src/resolution.z"
prim->kind = PrimitiveTyKind_Unsigned;
;
#line 353 "src/resolution.z"
prim->node.integer = IntegerSize_I64;
;
}
else {
#line 355 "src/resolution.z"
if ((s.x== p->_f32.x)){
#line 355 "src/resolution.z"
prim->kind = PrimitiveTyKind_Floating;
;
#line 355 "src/resolution.z"
prim->node.floating = FloatingSize_F32;
;
}
else {
#line 356 "src/resolution.z"
if ((s.x== p->_f64.x)){
#line 356 "src/resolution.z"
prim->kind = PrimitiveTyKind_Floating;
;
#line 356 "src/resolution.z"
prim->node.floating = FloatingSize_F64;
;
}
else {
#line 358 "src/resolution.z"
return false;
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
#line 360 "src/resolution.z"
return true;
;
}

#line 363 "src/resolution.z"
void  _ZN4main10resolution12resolve_pathE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast4PathE*  path) {
#line 364 "src/resolution.z"
_ZN4main3ast11PrimitiveTyE prim ;
;
#line 366 "src/resolution.z"
if (_ZN4main10resolution25check_if_sid_is_primitiveE(ctx,path->segments[0].name,&prim) ){
#line 367 "src/resolution.z"
path->binding.kind = BindingKind_PrimitiveType;
;
#line 368 "src/resolution.z"
path->binding.node.primitive = prim;
;
}
else {
#line 370 "src/resolution.z"
if ((path->num_segments> 1)){
#line 371 "src/resolution.z"
_ZN4main3ast4PathE base_path = _ZN4main10resolution6lookupE(ctx,path->segments[0]) ;
;
#line 372 "src/resolution.z"
if ((base_path.binding.kind== BindingKind_Item)){
#line 373 "src/resolution.z"
_ZN4main3ast4ItemE*  item = base_path.binding.node.item;
;
#line 375 "src/resolution.z"
if ((item->kind== ItemKind_Enum)){
#line 377 "src/resolution.z"
_ZN4main3ast4PathE p ;
;
#line 378 "src/resolution.z"
p.num_segments = (base_path.num_segments+ 1);
;
#line 379 "src/resolution.z"
p.segments = malloc((sizeof(_ZN4main3ast5IdentE)* p.num_segments)) ;
;
#line 380 "src/resolution.z"
memcpy(p.segments,base_path.segments,(base_path.num_segments* sizeof(_ZN4main3ast5IdentE))) ;
#line 383 "src/resolution.z"
u32 i = 0;
;
#line 384 "src/resolution.z"
_ZN4main3ast8EnumDataE data = item->node._enum;
;
#line 385 "src/resolution.z"
bool found = false;
;
#line 386 "src/resolution.z"
while ( (i< data.num_variants))
{
#line 387 "src/resolution.z"
if ((data.variants[i].ident.name.x== path->segments[1].name.x)){
#line 388 "src/resolution.z"
p.segments[base_path.num_segments] = data.variants[i].ident;
;
#line 389 "src/resolution.z"
p.binding.kind = BindingKind_Variant;
;
#line 390 "src/resolution.z"
p.binding.node.variant = &data.variants[i];
;
#line 391 "src/resolution.z"
found = true;
;
#line 392 "src/resolution.z"
break;
;
}
;
#line 394 "src/resolution.z"
i = (i+ 1);
;
}
;
#line 396 "src/resolution.z"
if (!found){
#line 396 "src/resolution.z"
_ZN4main5error10emit_errorE(ctx->source_map,path->span,"Enum does not have requested variant") ;
}
;
#line 398 "src/resolution.z"
*path = p;
;
}
else {
#line 400 "src/resolution.z"
abort() ;
}
;
}
else {
#line 402 "src/resolution.z"
abort() ;
}
;
}
else {
#line 404 "src/resolution.z"
if ((path->num_segments== 1)){
#line 405 "src/resolution.z"
*path = _ZN4main10resolution6lookupE(ctx,path->segments[0]) ;
;
}
;
}
;
}
;
}

#line 409 "src/resolution.z"
void  _ZN4main10resolution12resolve_typeE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast7AstTypeE*  ty) {
#line 410 "src/resolution.z"
if ((ty->kind== AstTypeKind_Ptr)){
#line 411 "src/resolution.z"
_ZN4main10resolution12resolve_typeE(ctx,ty->node.ptr) ;
}
else {
#line 413 "src/resolution.z"
if ((ty->kind== AstTypeKind_Path)){
#line 414 "src/resolution.z"
_ZN4main10resolution12resolve_pathE(ctx,&ty->node.path) ;
}
;
}
;
}

#line 418 "src/resolution.z"
void  _ZN4main10resolution12resolve_exprE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast4ExprE*  expr) ;

#line 419 "src/resolution.z"
void  _ZN4main10resolution12resolve_itemE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast4ItemE*  item) ;

#line 421 "src/resolution.z"
void  _ZN4main10resolution13resolve_unaryE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast9UnaryDataE unary) {
#line 422 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,unary.inner) ;
}

#line 425 "src/resolution.z"
void  _ZN4main10resolution14resolve_binaryE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast10BinaryDataE binary) {
#line 426 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,binary.left) ;
#line 427 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,binary.right) ;
}

#line 430 "src/resolution.z"
void  _ZN4main10resolution12resolve_callE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast8CallDataE call) {
#line 431 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,call.func) ;
#line 433 "src/resolution.z"
u32 i = 0;
;
#line 434 "src/resolution.z"
while ( (i< call.num_args))
{
#line 435 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,call.args[i]) ;
#line 436 "src/resolution.z"
i = (i+ 1);
;
}
;
}

#line 440 "src/resolution.z"
void  _ZN4main10resolution19resolve_conditionalE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast15ConditionalDataE cond) {
#line 441 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,cond.condition) ;
#line 442 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,cond.then) ;
#line 443 "src/resolution.z"
if (cond.otherwise){
#line 444 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,cond.otherwise) ;
}
;
}

#line 448 "src/resolution.z"
void  _ZN4main10resolution13resolve_whileE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast9WhileDataE data) {
#line 449 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,data.condition) ;
#line 450 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,data.body) ;
}

#line 453 "src/resolution.z"
void  _ZN4main10resolution16resolve_indexingE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast12IndexingDataE idx) {
#line 454 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,idx.array) ;
#line 455 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,idx.index) ;
}

#line 458 "src/resolution.z"
void  _ZN4main10resolution13resolve_fieldE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast9FieldDataE field) {
#line 459 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,field.strct) ;
}

#line 462 "src/resolution.z"
void  _ZN4main10resolution18resolve_assignmentE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast14AssignmentDataE assignment) {
#line 463 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,assignment.left) ;
#line 464 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,assignment.right) ;
}

#line 467 "src/resolution.z"
void  _ZN4main10resolution13resolve_blockE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast5BlockE*  block) {
#line 469 "src/resolution.z"
_ZN4main10resolution10push_blockE(ctx) ;
#line 470 "src/resolution.z"
u32 i = 0;
;
#line 471 "src/resolution.z"
while ( (i< block->num_exprs))
{
#line 472 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,block->exprs[i]) ;
#line 473 "src/resolution.z"
i = (i+ 1);
;
}
;
#line 475 "src/resolution.z"
_ZN4main10resolution9pop_blockE(ctx) ;
}

#line 478 "src/resolution.z"
void  _ZN4main10resolution11resolve_letE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast7LetDataE*  data) {
#line 479 "src/resolution.z"
_ZN4main10resolution13push_variableE(ctx,data->pat.ident,data) ;
#line 480 "src/resolution.z"
_ZN4main10resolution12resolve_typeE(ctx,data->ast_ty) ;
#line 481 "src/resolution.z"
if (data->value){
#line 481 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,data->value) ;
}
;
}

#line 484 "src/resolution.z"
void  _ZN4main10resolution14resolve_sizeofE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast4ExprE*  expr) {
#line 485 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,expr) ;
}

#line 488 "src/resolution.z"
void  _ZN4main10resolution12resolve_exprE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast4ExprE*  expr) {
#line 489 "src/resolution.z"
if ((expr->kind== ExprKind_Unary)){
#line 489 "src/resolution.z"
_ZN4main10resolution13resolve_unaryE(ctx,expr->node.unary) ;
}
else {
#line 490 "src/resolution.z"
if ((expr->kind== ExprKind_Binary)){
#line 490 "src/resolution.z"
_ZN4main10resolution14resolve_binaryE(ctx,expr->node.binary) ;
}
else {
#line 491 "src/resolution.z"
if ((expr->kind== ExprKind_Block)){
#line 491 "src/resolution.z"
_ZN4main10resolution13resolve_blockE(ctx,expr->node.block) ;
}
else {
#line 492 "src/resolution.z"
if ((expr->kind== ExprKind_Call)){
#line 492 "src/resolution.z"
_ZN4main10resolution12resolve_callE(ctx,expr->node.call) ;
}
else {
#line 493 "src/resolution.z"
if ((expr->kind== ExprKind_Conditional)){
#line 493 "src/resolution.z"
_ZN4main10resolution19resolve_conditionalE(ctx,expr->node.conditional) ;
}
else {
#line 494 "src/resolution.z"
if ((expr->kind== ExprKind_While)){
#line 494 "src/resolution.z"
_ZN4main10resolution13resolve_whileE(ctx,expr->node.whl) ;
}
else {
#line 495 "src/resolution.z"
if ((expr->kind== ExprKind_Indexing)){
#line 495 "src/resolution.z"
_ZN4main10resolution16resolve_indexingE(ctx,expr->node.indexing) ;
}
else {
#line 496 "src/resolution.z"
if ((expr->kind== ExprKind_Field)){
#line 496 "src/resolution.z"
_ZN4main10resolution13resolve_fieldE(ctx,expr->node.field) ;
}
else {
#line 497 "src/resolution.z"
if ((expr->kind== ExprKind_Path)){
#line 497 "src/resolution.z"
_ZN4main10resolution12resolve_pathE(ctx,&expr->node.path) ;
}
else {
#line 498 "src/resolution.z"
if ((expr->kind== ExprKind_Assignment)){
#line 498 "src/resolution.z"
_ZN4main10resolution18resolve_assignmentE(ctx,expr->node.assignment) ;
}
else {
#line 499 "src/resolution.z"
if ((expr->kind== ExprKind_Let)){
#line 499 "src/resolution.z"
_ZN4main10resolution11resolve_letE(ctx,&expr->node._let) ;
}
else {
#line 500 "src/resolution.z"
if ((expr->kind== ExprKind_Return)){
#line 500 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,expr->node._return) ;
}
else {
#line 501 "src/resolution.z"
if ((expr->kind== ExprKind_Literal)){
}
else {
#line 502 "src/resolution.z"
if ((expr->kind== ExprKind_ControlFlow)){
}
else {
#line 503 "src/resolution.z"
if ((expr->kind== ExprKind_Sizeof)){
#line 503 "src/resolution.z"
_ZN4main10resolution14resolve_sizeofE(ctx,expr->node._sizeof) ;
}
else {
#line 504 "src/resolution.z"
abort() ;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}

#line 507 "src/resolution.z"
void  _ZN4main10resolution16resolve_functionE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 508 "src/resolution.z"
_ZN4main3ast12FunctionDataE func = item->node.function;
;
#line 510 "src/resolution.z"
_ZN4main10resolution12resolve_typeE(ctx,func.header.output_ast_ty) ;
#line 511 "src/resolution.z"
u32 i = 0;
;
#line 512 "src/resolution.z"
while ( (i< func.header.num_parameters))
{
#line 513 "src/resolution.z"
_ZN4main3ast17FunctionParameterE*  param = &func.header.parameters[i];
;
#line 514 "src/resolution.z"
_ZN4main10resolution12resolve_typeE(ctx,param->ast_ty) ;
#line 515 "src/resolution.z"
i = (i+ 1);
;
}
;
#line 518 "src/resolution.z"
if (func.body){
#line 519 "src/resolution.z"
_ZN4main10resolution10push_blockE(ctx) ;
#line 520 "src/resolution.z"
u32 i = 0;
;
#line 521 "src/resolution.z"
while ( (i< func.header.num_parameters))
{
#line 522 "src/resolution.z"
_ZN4main3ast17FunctionParameterE*  param = &func.header.parameters[i];
;
#line 523 "src/resolution.z"
_ZN4main10resolution14push_parameterE(ctx,param->pat.ident,param) ;
#line 525 "src/resolution.z"
i = (i+ 1);
;
}
;
#line 528 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,item->node.function.body) ;
#line 529 "src/resolution.z"
_ZN4main10resolution9pop_blockE(ctx) ;
}
;
}

#line 533 "src/resolution.z"
void  _ZN4main10resolution16resolve_variableE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 534 "src/resolution.z"
_ZN4main10resolution12resolve_typeE(ctx,item->node.variable.ast_ty) ;
#line 535 "src/resolution.z"
_ZN4main10resolution10push_blockE(ctx) ;
#line 536 "src/resolution.z"
if (item->node.variable.body){
#line 537 "src/resolution.z"
_ZN4main10resolution12resolve_exprE(ctx,item->node.variable.body) ;
}
;
#line 539 "src/resolution.z"
_ZN4main10resolution9pop_blockE(ctx) ;
}

#line 542 "src/resolution.z"
void  _ZN4main10resolution16resolve_compoundE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 544 "src/resolution.z"
_ZN4main3ast12CompoundDataE data = item->node.compound;
;
#line 546 "src/resolution.z"
u32 i = 0;
;
#line 547 "src/resolution.z"
while ( (i< data.num_fields))
{
#line 548 "src/resolution.z"
_ZN4main10resolution12resolve_typeE(ctx,data.fields[i].ast_ty) ;
#line 549 "src/resolution.z"
i = (i+ 1);
;
}
;
}

#line 553 "src/resolution.z"
void  _ZN4main10resolution14resolve_moduleE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast6ModuleE*  module) ;

#line 555 "src/resolution.z"
void  _ZN4main10resolution12resolve_itemE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 556 "src/resolution.z"
if (((item->kind== ItemKind_Const)|| (item->kind== ItemKind_Variable))){
#line 556 "src/resolution.z"
_ZN4main10resolution16resolve_variableE(ctx,item) ;
}
;
#line 557 "src/resolution.z"
if ((item->kind== ItemKind_Function)){
#line 557 "src/resolution.z"
_ZN4main10resolution16resolve_functionE(ctx,item) ;
}
;
#line 558 "src/resolution.z"
if (((item->kind== ItemKind_Struct)|| (item->kind== ItemKind_Union))){
#line 558 "src/resolution.z"
_ZN4main10resolution16resolve_compoundE(ctx,item) ;
}
;
#line 559 "src/resolution.z"
if ((item->kind== ItemKind_Module)){
#line 559 "src/resolution.z"
_ZN4main10resolution14resolve_moduleE(ctx,item->node.module) ;
}
;
}

#line 562 "src/resolution.z"
void  _ZN4main10resolution14resolve_moduleE(_ZN4main10resolution17ResolutionContextE*  ctx, _ZN4main3ast6ModuleE*  module) {
#line 563 "src/resolution.z"
_ZN4main10resolution11push_moduleE(ctx,module) ;
#line 565 "src/resolution.z"
u32 i = 0;
;
#line 566 "src/resolution.z"
while ( (i< module->num_items))
{
#line 567 "src/resolution.z"
_ZN4main10resolution12resolve_itemE(ctx,module->items[i]) ;
#line 568 "src/resolution.z"
i = (i+ 1);
;
}
;
#line 570 "src/resolution.z"
_ZN4main10resolution10pop_moduleE(ctx) ;
}

#line 573 "src/resolution.z"
void  _ZN4main10resolution7resolveE(_ZN4main7session7SessionE*  sess, _ZN4main3ast3AstE*  ast) {
#line 574 "src/resolution.z"
_ZN4main10resolution17ResolutionContextE ctx ;
;
#line 576 "src/resolution.z"
ctx.interner = &sess->interner;
;
#line 577 "src/resolution.z"
_ZN4main10resolution23setup_primitive_ty_sidsE(ctx.interner,&ctx.primitive_ty_sids) ;
#line 578 "src/resolution.z"
ctx.ast = ast;
;
#line 579 "src/resolution.z"
ctx.scope_stack = malloc((sizeof(_ZN4main10resolution5ScopeE)* 128)) ;
;
#line 580 "src/resolution.z"
ctx.stack_top = 0;
;
#line 581 "src/resolution.z"
ctx.source_map = &sess->source;
;
#line 582 "src/resolution.z"
ctx.root_module = ast->root_module;
;
#line 584 "src/resolution.z"
_ZN4main10resolution9index_useE(&ctx,ast->root_module) ;
#line 585 "src/resolution.z"
_ZN4main10resolution12index_moduleE(&ctx,ast->root_module) ;
#line 586 "src/resolution.z"
_ZN4main10resolution22index_module_wildcardsE(&ctx,ast->root_module) ;
#line 587 "src/resolution.z"
_ZN4main10resolution14resolve_moduleE(&ctx,ast->root_module) ;
}







typedef struct _ZN4main9typecheck11CommonTypesE _ZN4main9typecheck11CommonTypesE;
#line 8 "src/typecheck.z"
typedef struct _ZN4main9typecheck11CommonTypesE {
_ZN4main3ast2TyE*  _void;
_ZN4main3ast2TyE*  _constvoid;
_ZN4main3ast2TyE*  _variadic;
_ZN4main3ast2TyE*  _bool;
_ZN4main3ast2TyE*  _char;
_ZN4main3ast2TyE*  _constchar;
_ZN4main3ast2TyE*  _i8;
_ZN4main3ast2TyE*  _i16;
_ZN4main3ast2TyE*  _i32;
_ZN4main3ast2TyE*  _i64;
_ZN4main3ast2TyE*  _u8;
_ZN4main3ast2TyE*  _u16;
_ZN4main3ast2TyE*  _u32;
_ZN4main3ast2TyE*  _u64;
_ZN4main3ast2TyE*  _f32;
_ZN4main3ast2TyE*  _f64;
} _ZN4main9typecheck11CommonTypesE;


typedef struct _ZN4main9typecheck11TypeContextE _ZN4main9typecheck11TypeContextE;
#line 27 "src/typecheck.z"
typedef struct _ZN4main9typecheck11TypeContextE {
_ZN4main3ast3AstE*  ast;
_ZN4main9interning8InternerE*  interner;
_ZN4main10source_map9SourceMapE*  source_map;
_ZN4main9typecheck11CommonTypesE common;
_ZN4main6intmap6IntMapE*  types_lookup;
_ZN4main3ast2TyE*  types;
u32 next_type_idx;
} _ZN4main9typecheck11TypeContextE;


#line 37 "src/typecheck.z"
u32 _ZN4main9typecheck12integer_sizeE(_ZN4main3ast11IntegerSizeE size) {
#line 38 "src/typecheck.z"
if ((size== IntegerSize_I8)){
#line 38 "src/typecheck.z"
return 8;
;
}
else {
#line 39 "src/typecheck.z"
if ((size== IntegerSize_I16)){
#line 39 "src/typecheck.z"
return 16;
;
}
else {
#line 40 "src/typecheck.z"
if ((size== IntegerSize_I32)){
#line 40 "src/typecheck.z"
return 32;
;
}
else {
#line 41 "src/typecheck.z"
if ((size== IntegerSize_I64)){
#line 41 "src/typecheck.z"
return 64;
;
}
else {
#line 42 "src/typecheck.z"
abort() ;
}
;
}
;
}
;
}
;
}

#line 45 "src/typecheck.z"
u32 _ZN4main9typecheck13floating_sizeE(_ZN4main3ast12FloatingSizeE size) {
#line 46 "src/typecheck.z"
if ((size== FloatingSize_F32)){
#line 46 "src/typecheck.z"
return 32;
;
}
else {
#line 47 "src/typecheck.z"
if ((size== FloatingSize_F64)){
#line 47 "src/typecheck.z"
return 64;
;
}
else {
#line 48 "src/typecheck.z"
abort() ;
}
;
}
;
}

#line 51 "src/typecheck.z"
u64 _ZN4main9typecheck7hash_tyE(_ZN4main3ast2TyE*  ty) ;

#line 53 "src/typecheck.z"
u64 _ZN4main9typecheck7hash_fnE(_ZN4main3ast2TyE*  ty) {
#line 55 "src/typecheck.z"
_ZN4main3ast5FnDefE def = ty->node.function;
;
#line 56 "src/typecheck.z"
u64 h = _ZN4main9typecheck7hash_tyE(def.output) ;
;
#line 58 "src/typecheck.z"
u32 i = 0;
;
#line 59 "src/typecheck.z"
while ( (i< def.num_parameters))
{
#line 60 "src/typecheck.z"
h = (h^ (((_ZN4main9typecheck7hash_tyE(def.parameters[i]) + 2654435769)+ (h<< 6))+ (h>> 2)));
;
#line 61 "src/typecheck.z"
i = (i+ 1);
;
}
;
#line 63 "src/typecheck.z"
return h;
;
}

#line 66 "src/typecheck.z"
u64 _ZN4main9typecheck9hash_pathE(_ZN4main3ast4PathE path) {
#line 67 "src/typecheck.z"
u64 h = path.num_segments;
;
#line 68 "src/typecheck.z"
u32 i = 0;
;
#line 69 "src/typecheck.z"
while ( (i< path.num_segments))
{
#line 70 "src/typecheck.z"
h = (h^ (((path.segments[i].name.x+ 2654435769)+ (h<< 6))+ (h>> 2)));
;
#line 71 "src/typecheck.z"
i = (i+ 1);
;
}
;
#line 73 "src/typecheck.z"
return h;
;
}

#line 76 "src/typecheck.z"
u64 _ZN4main9typecheck7hash_tyE(_ZN4main3ast2TyE*  ty) {
#line 78 "src/typecheck.z"
u64 h ;
;
#line 80 "src/typecheck.z"
h = ty->kind;
;
#line 82 "src/typecheck.z"
if (((ty->kind== TyKind_Signed)|| (ty->kind== TyKind_Unsigned))){
#line 82 "src/typecheck.z"
h = (h^ (_ZN4main9typecheck12integer_sizeE(ty->node.integer) << 4));
;
}
else {
#line 83 "src/typecheck.z"
if ((ty->kind== TyKind_Floating)){
#line 83 "src/typecheck.z"
h = (h^ (_ZN4main9typecheck13floating_sizeE(ty->node.floating) << 4));
;
}
else {
#line 84 "src/typecheck.z"
if (((ty->kind== TyKind_Struct)|| (ty->kind== TyKind_Union))){
#line 84 "src/typecheck.z"
h = (h^ (_ZN4main9typecheck9hash_pathE(ty->node.compound.path) << 4));
;
}
else {
#line 85 "src/typecheck.z"
if ((ty->kind== TyKind_Enum)){
#line 85 "src/typecheck.z"
h = (h^ (_ZN4main9typecheck9hash_pathE(ty->node._enum.path) << 4));
;
}
else {
#line 86 "src/typecheck.z"
if ((ty->kind== TyKind_Fn)){
#line 86 "src/typecheck.z"
h = (h^ (_ZN4main9typecheck7hash_fnE(ty) << 4));
;
}
else {
#line 87 "src/typecheck.z"
if ((ty->kind== TyKind_Ptr)){
#line 87 "src/typecheck.z"
h = (h^ (_ZN4main9typecheck7hash_tyE(ty->node.ptr) << 4));
;
}
;
}
;
}
;
}
;
}
;
}
;
#line 89 "src/typecheck.z"
return h;
;
}

#line 92 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck9intern_tyE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast2TyE ty) {
#line 93 "src/typecheck.z"
u64 h = _ZN4main9typecheck7hash_tyE(&ty) ;
;
#line 94 "src/typecheck.z"
u32 ty_idx = _ZN4main6intmap13intmap_lookupE(ctx->types_lookup,h) ;
;
#line 95 "src/typecheck.z"
if ((ty_idx== 0)){
#line 96 "src/typecheck.z"
ty_idx = ctx->next_type_idx;
;
#line 97 "src/typecheck.z"
ctx->next_type_idx = (ctx->next_type_idx+ 1);
;
#line 98 "src/typecheck.z"
_ZN4main6intmap13intmap_insertE(ctx->types_lookup,h,ty_idx) ;
#line 99 "src/typecheck.z"
ctx->types[ty_idx] = ty;
;
}
;
#line 101 "src/typecheck.z"
return &ctx->types[ty_idx];
;
}

#line 104 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck16create_base_typeE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast6TyKindE kind) {
#line 105 "src/typecheck.z"
_ZN4main3ast2TyE ty ;
;
#line 106 "src/typecheck.z"
ty.kind = kind;
;
#line 107 "src/typecheck.z"
return _ZN4main9typecheck9intern_tyE(ctx,ty) ;
;
}

#line 110 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck17create_float_typeE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast12FloatingSizeE size) {
#line 111 "src/typecheck.z"
_ZN4main3ast2TyE ty ;
;
#line 112 "src/typecheck.z"
ty.kind = TyKind_Floating;
;
#line 113 "src/typecheck.z"
ty.node.floating = size;
;
#line 114 "src/typecheck.z"
return _ZN4main9typecheck9intern_tyE(ctx,ty) ;
;
}

#line 117 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck15create_int_typeE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast6TyKindE kind, _ZN4main3ast11IntegerSizeE size) {
#line 118 "src/typecheck.z"
_ZN4main3ast2TyE ty ;
;
#line 119 "src/typecheck.z"
ty.kind = kind;
;
#line 120 "src/typecheck.z"
ty.node.integer = size;
;
#line 121 "src/typecheck.z"
return _ZN4main9typecheck9intern_tyE(ctx,ty) ;
;
}

#line 124 "src/typecheck.z"
void  _ZN4main9typecheck19create_common_typesE(_ZN4main9typecheck11TypeContextE*  ctx) {
#line 125 "src/typecheck.z"
_ZN4main9typecheck11CommonTypesE*  t = &ctx->common;
;
#line 126 "src/typecheck.z"
t->_void = _ZN4main9typecheck16create_base_typeE(ctx,TyKind_Void) ;
;
#line 127 "src/typecheck.z"
t->_constvoid = _ZN4main9typecheck16create_base_typeE(ctx,TyKind_ConstVoid) ;
;
#line 128 "src/typecheck.z"
t->_variadic = _ZN4main9typecheck16create_base_typeE(ctx,TyKind_Variadic) ;
;
#line 129 "src/typecheck.z"
t->_bool = _ZN4main9typecheck16create_base_typeE(ctx,TyKind_Bool) ;
;
#line 130 "src/typecheck.z"
t->_char = _ZN4main9typecheck16create_base_typeE(ctx,TyKind_Char) ;
;
#line 131 "src/typecheck.z"
t->_constchar = _ZN4main9typecheck16create_base_typeE(ctx,TyKind_ConstChar) ;
;
#line 133 "src/typecheck.z"
t->_i8 = _ZN4main9typecheck15create_int_typeE(ctx,TyKind_Signed,IntegerSize_I8) ;
;
#line 134 "src/typecheck.z"
t->_i16 = _ZN4main9typecheck15create_int_typeE(ctx,TyKind_Signed,IntegerSize_I16) ;
;
#line 135 "src/typecheck.z"
t->_i32 = _ZN4main9typecheck15create_int_typeE(ctx,TyKind_Signed,IntegerSize_I32) ;
;
#line 136 "src/typecheck.z"
t->_i64 = _ZN4main9typecheck15create_int_typeE(ctx,TyKind_Signed,IntegerSize_I64) ;
;
#line 138 "src/typecheck.z"
t->_u8 = _ZN4main9typecheck15create_int_typeE(ctx,TyKind_Unsigned,IntegerSize_I8) ;
;
#line 139 "src/typecheck.z"
t->_u16 = _ZN4main9typecheck15create_int_typeE(ctx,TyKind_Unsigned,IntegerSize_I16) ;
;
#line 140 "src/typecheck.z"
t->_u32 = _ZN4main9typecheck15create_int_typeE(ctx,TyKind_Unsigned,IntegerSize_I32) ;
;
#line 141 "src/typecheck.z"
t->_u64 = _ZN4main9typecheck15create_int_typeE(ctx,TyKind_Unsigned,IntegerSize_I64) ;
;
#line 143 "src/typecheck.z"
t->_f32 = _ZN4main9typecheck17create_float_typeE(ctx,FloatingSize_F32) ;
;
#line 144 "src/typecheck.z"
t->_f64 = _ZN4main9typecheck17create_float_typeE(ctx,FloatingSize_F64) ;
;
}

#line 147 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck14ast_type_to_tyE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast7AstTypeE*  ast_ty) ;

#line 149 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck15primitive_to_tyE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast11PrimitiveTyE prim) {
#line 150 "src/typecheck.z"
_ZN4main9typecheck11CommonTypesE*  t = &ctx->common;
;
#line 151 "src/typecheck.z"
if ((prim.kind== PrimitiveTyKind_Void)){
#line 151 "src/typecheck.z"
return t->_void;
;
}
else {
#line 152 "src/typecheck.z"
if ((prim.kind== PrimitiveTyKind_Bool)){
#line 152 "src/typecheck.z"
return t->_bool;
;
}
else {
#line 153 "src/typecheck.z"
if ((prim.kind== PrimitiveTyKind_Char)){
#line 153 "src/typecheck.z"
return t->_char;
;
}
else {
#line 155 "src/typecheck.z"
if ((prim.kind== PrimitiveTyKind_ConstChar)){
#line 155 "src/typecheck.z"
return t->_constchar;
;
}
else {
#line 156 "src/typecheck.z"
if ((prim.kind== PrimitiveTyKind_ConstVoid)){
#line 156 "src/typecheck.z"
return t->_constvoid;
;
}
else {
#line 158 "src/typecheck.z"
if ((prim.kind== PrimitiveTyKind_Signed)){
#line 159 "src/typecheck.z"
if ((prim.node.integer== IntegerSize_I8)){
#line 159 "src/typecheck.z"
return t->_i8;
;
}
else {
#line 160 "src/typecheck.z"
if ((prim.node.integer== IntegerSize_I16)){
#line 160 "src/typecheck.z"
return t->_i16;
;
}
else {
#line 161 "src/typecheck.z"
if ((prim.node.integer== IntegerSize_I32)){
#line 161 "src/typecheck.z"
return t->_i32;
;
}
else {
#line 162 "src/typecheck.z"
if ((prim.node.integer== IntegerSize_I64)){
#line 162 "src/typecheck.z"
return t->_i64;
;
}
else {
#line 163 "src/typecheck.z"
abort() ;
}
;
}
;
}
;
}
;
}
else {
#line 165 "src/typecheck.z"
if ((prim.kind== PrimitiveTyKind_Unsigned)){
#line 166 "src/typecheck.z"
if ((prim.node.integer== IntegerSize_I8)){
#line 166 "src/typecheck.z"
return t->_u8;
;
}
else {
#line 167 "src/typecheck.z"
if ((prim.node.integer== IntegerSize_I16)){
#line 167 "src/typecheck.z"
return t->_u16;
;
}
else {
#line 168 "src/typecheck.z"
if ((prim.node.integer== IntegerSize_I32)){
#line 168 "src/typecheck.z"
return t->_u32;
;
}
else {
#line 169 "src/typecheck.z"
if ((prim.node.integer== IntegerSize_I64)){
#line 169 "src/typecheck.z"
return t->_u64;
;
}
else {
#line 170 "src/typecheck.z"
abort() ;
}
;
}
;
}
;
}
;
}
else {
#line 172 "src/typecheck.z"
if ((prim.kind== PrimitiveTyKind_Floating)){
#line 173 "src/typecheck.z"
if ((prim.node.floating== FloatingSize_F32)){
#line 173 "src/typecheck.z"
return t->_f32;
;
}
else {
#line 174 "src/typecheck.z"
if ((prim.node.floating== FloatingSize_F64)){
#line 174 "src/typecheck.z"
return t->_f64;
;
}
else {
#line 175 "src/typecheck.z"
abort() ;
}
;
}
;
}
else {
#line 177 "src/typecheck.z"
abort() ;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}

#line 180 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck14ast_path_to_tyE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast7AstTypeE*  ast_ty) {
#line 181 "src/typecheck.z"
_ZN4main3ast7BindingE binding = ast_ty->node.path.binding;
;
#line 183 "src/typecheck.z"
if ((binding.kind== BindingKind_PrimitiveType)){
#line 184 "src/typecheck.z"
return _ZN4main9typecheck15primitive_to_tyE(ctx,binding.node.primitive) ;
;
}
else {
#line 186 "src/typecheck.z"
if ((binding.kind== BindingKind_Item)){
#line 187 "src/typecheck.z"
_ZN4main3ast4ItemE*  item = binding.node.item;
;
#line 188 "src/typecheck.z"
if (((item->kind== ItemKind_Struct)|| (item->kind== ItemKind_Union))){
#line 188 "src/typecheck.z"
return item->node.compound.ty;
;
}
else {
#line 189 "src/typecheck.z"
if ((item->kind== ItemKind_Function)){
#line 189 "src/typecheck.z"
return item->node.function.header.ty;
;
}
else {
#line 190 "src/typecheck.z"
if ((item->kind== ItemKind_Enum)){
#line 190 "src/typecheck.z"
return item->node._enum.ty;
;
}
else {
#line 191 "src/typecheck.z"
return _ZN4main4cstd4nullE;
;
}
;
}
;
}
;
}
else {
#line 193 "src/typecheck.z"
abort() ;
}
;
}
;
}

#line 196 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck13ast_ptr_to_tyE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast7AstTypeE*  ast_ty) {
#line 197 "src/typecheck.z"
_ZN4main3ast2TyE ty ;
;
#line 198 "src/typecheck.z"
ty.kind = TyKind_Ptr;
;
#line 199 "src/typecheck.z"
ty.node.ptr = _ZN4main9typecheck14ast_type_to_tyE(ctx,ast_ty->node.ptr) ;
;
#line 200 "src/typecheck.z"
return _ZN4main9typecheck9intern_tyE(ctx,ty) ;
;
}

#line 203 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck14ast_type_to_tyE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast7AstTypeE*  ast_ty) {
#line 204 "src/typecheck.z"
if ((ast_ty->kind== AstTypeKind_Void)){
#line 204 "src/typecheck.z"
return ctx->common._void;
;
}
else {
#line 205 "src/typecheck.z"
if ((ast_ty->kind== AstTypeKind_Path)){
#line 205 "src/typecheck.z"
return _ZN4main9typecheck14ast_path_to_tyE(ctx,ast_ty) ;
;
}
else {
#line 206 "src/typecheck.z"
if ((ast_ty->kind== AstTypeKind_Ptr)){
#line 206 "src/typecheck.z"
return _ZN4main9typecheck13ast_ptr_to_tyE(ctx,ast_ty) ;
;
}
else {
#line 207 "src/typecheck.z"
if ((ast_ty->kind== AstTypeKind_Variadic)){
#line 207 "src/typecheck.z"
return ctx->common._variadic;
;
}
else {
#line 208 "src/typecheck.z"
abort() ;
}
;
}
;
}
;
}
;
}

#line 211 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck17ast_literal_to_tyE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast7LiteralE lit) {
#line 212 "src/typecheck.z"
if ((lit.kind== LiteralKind_Int)){
#line 212 "src/typecheck.z"
return ctx->common._i32;
;
}
else {
#line 213 "src/typecheck.z"
if ((lit.kind== LiteralKind_Float)){
#line 213 "src/typecheck.z"
return ctx->common._f32;
;
}
else {
#line 214 "src/typecheck.z"
if ((lit.kind== LiteralKind_Bool)){
#line 214 "src/typecheck.z"
return ctx->common._bool;
;
}
else {
#line 215 "src/typecheck.z"
if ((lit.kind== LiteralKind_Char)){
#line 215 "src/typecheck.z"
return ctx->common._char;
;
}
else {
#line 216 "src/typecheck.z"
if ((lit.kind== LiteralKind_Str)){
#line 217 "src/typecheck.z"
_ZN4main3ast2TyE str_ty ;
;
#line 218 "src/typecheck.z"
str_ty.kind = TyKind_Ptr;
;
#line 219 "src/typecheck.z"
str_ty.node.ptr = ctx->common._char;
;
#line 220 "src/typecheck.z"
return _ZN4main9typecheck9intern_tyE(ctx,str_ty) ;
;
}
else {
#line 222 "src/typecheck.z"
abort() ;
}
;
}
;
}
;
}
;
}
;
}

#line 225 "src/typecheck.z"
u32 _ZN4main9typecheck11coerce_typeE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast2TyE*  from, _ZN4main3ast2TyE*  to) {
#line 227 "src/typecheck.z"
if ((from== to)){
#line 227 "src/typecheck.z"
return 1;
;
}
else {
#line 228 "src/typecheck.z"
if ((to->kind== TyKind_Variadic)){
#line 228 "src/typecheck.z"
return 1;
;
}
else {
#line 229 "src/typecheck.z"
if (((from->kind== TyKind_Signed)|| (from->kind== TyKind_Unsigned))){
#line 230 "src/typecheck.z"
u32 from_size = _ZN4main9typecheck12integer_sizeE(from->node.integer) ;
;
#line 232 "src/typecheck.z"
if (((to->kind== TyKind_Signed)|| (to->kind== TyKind_Unsigned))){
#line 233 "src/typecheck.z"
u32 to_size = _ZN4main9typecheck12integer_sizeE(to->node.integer) ;
;
#line 234 "src/typecheck.z"
if ((from_size<= to_size)){
#line 234 "src/typecheck.z"
return 2;
;
}
;
}
;
#line 236 "src/typecheck.z"
if ((to->kind== TyKind_Bool)){
#line 236 "src/typecheck.z"
return 2;
;
}
;
#line 238 "src/typecheck.z"
if ((to->kind== TyKind_Ptr)){
#line 238 "src/typecheck.z"
return 2;
;
}
;
}
else {
#line 240 "src/typecheck.z"
if ((from->kind== TyKind_Ptr)){
#line 241 "src/typecheck.z"
_ZN4main3ast2TyE*  inner_from = from->node.ptr;
;
#line 243 "src/typecheck.z"
if ((to->kind== TyKind_Bool)){
#line 243 "src/typecheck.z"
return 2;
;
}
else {
#line 245 "src/typecheck.z"
if ((to->kind== TyKind_Ptr)){
#line 246 "src/typecheck.z"
_ZN4main3ast2TyE*  inner_to = to->node.ptr;
;
#line 247 "src/typecheck.z"
if (((inner_from->kind== TyKind_Void)|| (inner_from->kind== TyKind_ConstVoid))){
#line 247 "src/typecheck.z"
return 2;
;
}
;
#line 248 "src/typecheck.z"
if (((inner_to->kind== TyKind_Void)|| (inner_to->kind== TyKind_ConstVoid))){
#line 248 "src/typecheck.z"
return 2;
;
}
;
#line 250 "src/typecheck.z"
if (((inner_from->kind== TyKind_Char)&& (inner_to->kind== TyKind_ConstChar))){
#line 250 "src/typecheck.z"
return 2;
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
#line 253 "src/typecheck.z"
return 0;
;
}

#line 256 "src/typecheck.z"
void  _ZN4main9typecheck18coerce_binary_exprE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ExprE*  expr, _ZN4main3ast2TyE*  left, _ZN4main3ast2TyE*  right) {
#line 258 "src/typecheck.z"
u32 coerce_left = _ZN4main9typecheck11coerce_typeE(ctx,left,right) ;
;
#line 259 "src/typecheck.z"
u32 coerce_right = _ZN4main9typecheck11coerce_typeE(ctx,right,left) ;
;
#line 261 "src/typecheck.z"
if (((coerce_left== 1)|| (coerce_right== 1))){
}
else {
#line 262 "src/typecheck.z"
if ((coerce_left== 2)){
#line 263 "src/typecheck.z"
_ZN4main3ast4ExprE*  cast_expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Cast) ;
;
#line 264 "src/typecheck.z"
cast_expr->node._cast.ty = right;
;
#line 265 "src/typecheck.z"
cast_expr->node._cast.inner = expr->node.binary.left;
;
#line 266 "src/typecheck.z"
expr->node.binary.left = cast_expr;
;
}
else {
#line 268 "src/typecheck.z"
if ((coerce_right== 2)){
#line 269 "src/typecheck.z"
_ZN4main3ast4ExprE*  cast_expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Cast) ;
;
#line 270 "src/typecheck.z"
cast_expr->node._cast.ty = left;
;
#line 271 "src/typecheck.z"
cast_expr->node._cast.inner = expr->node.binary.right;
;
#line 272 "src/typecheck.z"
expr->node.binary.right = cast_expr;
;
}
else {
#line 274 "src/typecheck.z"
_ZN4main5error10emit_errorE(ctx->source_map,expr->span,"Cannot coerce type in binary expression") ;
}
;
}
;
}
;
}

#line 277 "src/typecheck.z"
_ZN4main3ast4ExprE*  _ZN4main9typecheck16coerce_expr_typeE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ExprE*  expr, _ZN4main3ast2TyE*  from, _ZN4main3ast2TyE*  to) {
#line 278 "src/typecheck.z"
u32 can_coerce = _ZN4main9typecheck11coerce_typeE(ctx,from,to) ;
;
#line 279 "src/typecheck.z"
if ((can_coerce== 1)){
#line 279 "src/typecheck.z"
return expr;
;
}
else {
#line 280 "src/typecheck.z"
if ((can_coerce== 2)){
#line 281 "src/typecheck.z"
_ZN4main3ast4ExprE*  cast_expr = _ZN4main3ast15ast_create_exprE(ctx->ast,ExprKind_Cast) ;
;
#line 282 "src/typecheck.z"
cast_expr->node._cast.ty = to;
;
#line 283 "src/typecheck.z"
cast_expr->node._cast.inner = expr;
;
#line 284 "src/typecheck.z"
return cast_expr;
;
}
else {
#line 286 "src/typecheck.z"
_ZN4main5error10emit_errorE(ctx->source_map,expr->span,"Cannot coerce type") ;
}
;
}
;
#line 287 "src/typecheck.z"
abort() ;
}

#line 290 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck10check_exprE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ExprE*  expr) ;

#line 291 "src/typecheck.z"
void  _ZN4main9typecheck10check_itemE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ItemE*  item) ;

#line 292 "src/typecheck.z"
void  _ZN4main9typecheck9check_modE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast6ModuleE*  module) ;

#line 294 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck11check_unaryE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ExprE*  expr) {
#line 295 "src/typecheck.z"
_ZN4main3ast2TyE*  inner_ty = _ZN4main9typecheck10check_exprE(ctx,expr->node.unary.inner) ;
;
#line 296 "src/typecheck.z"
_ZN4main3ast17UnaryOperatorKindE op = expr->node.unary.op;
;
#line 297 "src/typecheck.z"
if ((op== UnaryOperatorKind_Deref)){
#line 298 "src/typecheck.z"
if ((inner_ty->kind== TyKind_Ptr)){
#line 299 "src/typecheck.z"
return inner_ty->node.ptr;
;
}
else {
#line 301 "src/typecheck.z"
_ZN4main5error10emit_errorE(ctx->source_map,expr->span,"Trying to deref non-pointer") ;
}
;
}
else {
#line 303 "src/typecheck.z"
if ((op== UnaryOperatorKind_Refer)){
#line 304 "src/typecheck.z"
_ZN4main3ast2TyE ptr_ty ;
;
#line 305 "src/typecheck.z"
ptr_ty.kind = TyKind_Ptr;
;
#line 306 "src/typecheck.z"
ptr_ty.node.ptr = inner_ty;
;
#line 307 "src/typecheck.z"
return _ZN4main9typecheck9intern_tyE(ctx,ptr_ty) ;
;
}
else {
#line 309 "src/typecheck.z"
if ((op== UnaryOperatorKind_Negation)){
#line 310 "src/typecheck.z"
return inner_ty;
;
}
else {
#line 312 "src/typecheck.z"
if ((op== UnaryOperatorKind_Complement)){
#line 313 "src/typecheck.z"
expr->node.unary.inner = _ZN4main9typecheck16coerce_expr_typeE(ctx,expr->node.unary.inner,inner_ty,ctx->common._bool) ;
;
#line 314 "src/typecheck.z"
return ctx->common._bool;
;
}
;
}
;
}
;
}
;
#line 316 "src/typecheck.z"
abort() ;
}

#line 319 "src/typecheck.z"
bool _ZN4main9typecheck19operator_is_booleanE(_ZN4main3ast18BinaryOperatorKindE op) {
#line 320 "src/typecheck.z"
return ((((((((op== BinaryOperatorKind_Less)|| (op== BinaryOperatorKind_LessEq))|| (op== BinaryOperatorKind_NotEq))|| (op== BinaryOperatorKind_Greater))|| (op== BinaryOperatorKind_GreaterEq))|| (op== BinaryOperatorKind_Equality))|| (op== BinaryOperatorKind_And))|| (op== BinaryOperatorKind_Or));
;
}

#line 325 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck12check_binaryE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ExprE*  expr) {
#line 326 "src/typecheck.z"
_ZN4main3ast18BinaryOperatorKindE op = expr->node.binary.op;
;
#line 327 "src/typecheck.z"
_ZN4main3ast2TyE*  left = _ZN4main9typecheck10check_exprE(ctx,expr->node.binary.left) ;
;
#line 328 "src/typecheck.z"
_ZN4main3ast2TyE*  right = _ZN4main9typecheck10check_exprE(ctx,expr->node.binary.right) ;
;
#line 330 "src/typecheck.z"
_ZN4main9typecheck18coerce_binary_exprE(ctx,expr,left,right) ;
#line 332 "src/typecheck.z"
if (_ZN4main9typecheck19operator_is_booleanE(op) ){
#line 332 "src/typecheck.z"
return ctx->common._bool;
;
}
else {
#line 333 "src/typecheck.z"
return left;
;
}
;
}

#line 336 "src/typecheck.z"
void  _ZN4main9typecheck11check_blockE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast5BlockE*  block) {
#line 337 "src/typecheck.z"
u32 i = 0;
;
#line 338 "src/typecheck.z"
while ( (i< block->num_exprs))
{
#line 339 "src/typecheck.z"
_ZN4main9typecheck10check_exprE(ctx,block->exprs[i]) ;
#line 340 "src/typecheck.z"
i = (i+ 1);
;
}
;
}

#line 344 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck16check_block_exprE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ExprE*  expr) {
#line 345 "src/typecheck.z"
_ZN4main9typecheck11check_blockE(ctx,expr->node.block) ;
#line 346 "src/typecheck.z"
return ctx->common._void;
;
}

#line 349 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck10check_callE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ExprE*  expr) {
#line 350 "src/typecheck.z"
_ZN4main3ast8CallDataE call = expr->node.call;
;
#line 351 "src/typecheck.z"
_ZN4main3ast2TyE*  fn_ty = _ZN4main9typecheck10check_exprE(ctx,call.func) ;
;
#line 352 "src/typecheck.z"
if ((fn_ty->kind!= TyKind_Fn)){
#line 352 "src/typecheck.z"
_ZN4main5error12emit_warningE(ctx->source_map,expr->span,"Tried to call non-function") ;
}
;
#line 354 "src/typecheck.z"
_ZN4main3ast5FnDefE*  fn_def = &fn_ty->node.function;
;
#line 356 "src/typecheck.z"
bool is_variadic = false;
;
#line 357 "src/typecheck.z"
if ((fn_def->num_parameters> 0)){
#line 358 "src/typecheck.z"
_ZN4main3ast2TyE*  param_ty = fn_def->parameters[(fn_def->num_parameters- 1)];
;
#line 359 "src/typecheck.z"
is_variadic = (param_ty->kind== TyKind_Variadic);
;
}
;
#line 362 "src/typecheck.z"
if (((call.num_args== fn_def->num_parameters)|| ((call.num_args>= (fn_def->num_parameters- 1))&& is_variadic))){
#line 363 "src/typecheck.z"
i32 i = 0;
;
#line 364 "src/typecheck.z"
while ( ((i< call.num_args)&& (i< fn_def->num_parameters)))
{
#line 365 "src/typecheck.z"
_ZN4main3ast2TyE*  arg_ty = _ZN4main9typecheck10check_exprE(ctx,call.args[i]) ;
;
#line 366 "src/typecheck.z"
call.args[i] = _ZN4main9typecheck16coerce_expr_typeE(ctx,call.args[i],arg_ty,fn_def->parameters[i]) ;
;
#line 367 "src/typecheck.z"
i = (i+ 1);
;
}
;
}
else {
#line 370 "src/typecheck.z"
_ZN4main5error10emit_errorE(ctx->source_map,expr->span,"Called function with incorrect number of arguments") ;
}
;
#line 371 "src/typecheck.z"
return fn_def->output;
;
}

#line 374 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck17check_conditionalE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ExprE*  expr) {
#line 375 "src/typecheck.z"
_ZN4main3ast15ConditionalDataE*  data = &expr->node.conditional;
;
#line 377 "src/typecheck.z"
_ZN4main3ast2TyE*  cond_ty = _ZN4main9typecheck10check_exprE(ctx,data->condition) ;
;
#line 378 "src/typecheck.z"
data->condition = _ZN4main9typecheck16coerce_expr_typeE(ctx,data->condition,cond_ty,ctx->common._bool) ;
;
#line 380 "src/typecheck.z"
_ZN4main9typecheck10check_exprE(ctx,data->then) ;
#line 381 "src/typecheck.z"
if (data->otherwise){
#line 382 "src/typecheck.z"
_ZN4main9typecheck10check_exprE(ctx,data->otherwise) ;
}
;
#line 384 "src/typecheck.z"
return ctx->common._void;
;
}

#line 387 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck11check_whileE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ExprE*  expr) {
#line 388 "src/typecheck.z"
_ZN4main3ast9WhileDataE data = expr->node.whl;
;
#line 389 "src/typecheck.z"
_ZN4main3ast4ExprE*  condition = data.condition;
;
#line 390 "src/typecheck.z"
_ZN4main3ast2TyE*  cond_ty = _ZN4main9typecheck10check_exprE(ctx,condition) ;
;
#line 391 "src/typecheck.z"
if ((cond_ty->kind!= TyKind_Bool)){
#line 391 "src/typecheck.z"
_ZN4main5error12emit_warningE(ctx->source_map,condition->span,"Condition must be of type bool") ;
}
;
#line 392 "src/typecheck.z"
_ZN4main9typecheck10check_exprE(ctx,data.body) ;
#line 393 "src/typecheck.z"
return ctx->common._void;
;
}

#line 396 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck14check_indexingE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ExprE*  expr) {
#line 397 "src/typecheck.z"
_ZN4main3ast12IndexingDataE data = expr->node.indexing;
;
#line 398 "src/typecheck.z"
_ZN4main3ast2TyE*  array_ty = _ZN4main9typecheck10check_exprE(ctx,data.array) ;
;
#line 399 "src/typecheck.z"
if ((array_ty->kind!= TyKind_Ptr)){
#line 399 "src/typecheck.z"
_ZN4main5error10emit_errorE(ctx->source_map,expr->span,"Cannot index into non-ptr type") ;
}
;
#line 400 "src/typecheck.z"
_ZN4main3ast2TyE*  index_ty = _ZN4main9typecheck10check_exprE(ctx,data.index) ;
;
#line 401 "src/typecheck.z"
if (!((index_ty->kind== TyKind_Signed)|| (index_ty->kind== TyKind_Unsigned))){
#line 402 "src/typecheck.z"
_ZN4main5error10emit_errorE(ctx->source_map,expr->span,"Only integers are valid indices") ;
}
;
#line 404 "src/typecheck.z"
return array_ty->node.ptr;
;
}

#line 407 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck11check_fieldE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ExprE*  expr) {
#line 408 "src/typecheck.z"
_ZN4main3ast9FieldDataE data = expr->node.field;
;
#line 409 "src/typecheck.z"
_ZN4main3ast2TyE*  compound_ty = _ZN4main9typecheck10check_exprE(ctx,data.strct) ;
;
#line 411 "src/typecheck.z"
_ZN4main3ast2TyE*  ptr_inner = compound_ty->node.ptr;
;
#line 412 "src/typecheck.z"
if (((compound_ty->kind== TyKind_Ptr)&& ((ptr_inner->kind== TyKind_Struct)|| (ptr_inner->kind== TyKind_Union)))){
#line 413 "src/typecheck.z"
compound_ty = compound_ty->node.ptr;
;
}
;
#line 416 "src/typecheck.z"
if (((compound_ty->kind!= TyKind_Struct)&& (compound_ty->kind!= TyKind_Union))){
#line 416 "src/typecheck.z"
_ZN4main5error10emit_errorE(ctx->source_map,expr->span,"Cannot access field of non-compound type") ;
}
;
#line 418 "src/typecheck.z"
_ZN4main3ast11CompoundDefE compound = compound_ty->node.compound;
;
#line 420 "src/typecheck.z"
u32 i = 0;
;
#line 421 "src/typecheck.z"
while ( (i< compound.num_fields))
{
#line 422 "src/typecheck.z"
if ((compound.fields[i].name.x== data.ident.name.x)){
#line 423 "src/typecheck.z"
return compound.fields[i].ty;
;
}
;
#line 425 "src/typecheck.z"
i = (i+ 1);
;
}
;
#line 427 "src/typecheck.z"
_ZN4main5error12emit_warningE(ctx->source_map,expr->span,"Compound type has no such field") ;
#line 428 "src/typecheck.z"
return _ZN4main4cstd4nullE;
;
}

#line 431 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck10check_pathE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4PathE*  path) {
#line 432 "src/typecheck.z"
if ((path->binding.kind== BindingKind_Item)){
#line 433 "src/typecheck.z"
_ZN4main3ast4ItemE*  item = path->binding.node.item;
;
#line 434 "src/typecheck.z"
if (((item->kind== ItemKind_Struct)|| (item->kind== ItemKind_Union))){
#line 435 "src/typecheck.z"
return item->node.compound.ty;
;
}
else {
#line 437 "src/typecheck.z"
if ((item->kind== ItemKind_Enum)){
#line 438 "src/typecheck.z"
return item->node._enum.ty;
;
}
else {
#line 440 "src/typecheck.z"
if ((item->kind== ItemKind_Function)){
#line 441 "src/typecheck.z"
return item->node.function.header.ty;
;
}
else {
#line 443 "src/typecheck.z"
if (((item->kind== ItemKind_Const)|| (item->kind== ItemKind_Variable))){
#line 444 "src/typecheck.z"
return item->node.variable.ty;
;
}
else {
#line 446 "src/typecheck.z"
abort() ;
}
;
}
;
}
;
}
;
}
else {
#line 448 "src/typecheck.z"
if ((path->binding.kind== BindingKind_Variable)){
#line 449 "src/typecheck.z"
_ZN4main3ast7LetDataE*  data = path->binding.node.variable;
;
#line 450 "src/typecheck.z"
return data->ty;
;
}
else {
#line 452 "src/typecheck.z"
if ((path->binding.kind== BindingKind_Parameter)){
#line 453 "src/typecheck.z"
_ZN4main3ast17FunctionParameterE*  param = path->binding.node.parameter;
;
#line 454 "src/typecheck.z"
return param->ty;
;
}
else {
#line 456 "src/typecheck.z"
if ((path->binding.kind== BindingKind_Variant)){
#line 457 "src/typecheck.z"
_ZN4main3ast11EnumVariantE*  variant = path->binding.node.variant;
;
#line 458 "src/typecheck.z"
_ZN4main3ast4ItemE*  enum_item = variant->_enum;
;
#line 459 "src/typecheck.z"
return enum_item->node._enum.ty;
;
}
else {
#line 461 "src/typecheck.z"
if ((path->binding.kind== BindingKind_PrimitiveType)){
#line 462 "src/typecheck.z"
return _ZN4main9typecheck15primitive_to_tyE(ctx,path->binding.node.primitive) ;
;
}
else {
#line 464 "src/typecheck.z"
abort() ;
}
;
}
;
}
;
}
;
}
;
}

#line 468 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck9check_letE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast7LetDataE*  data) {
#line 469 "src/typecheck.z"
data->ty = _ZN4main9typecheck14ast_type_to_tyE(ctx,data->ast_ty) ;
;
#line 470 "src/typecheck.z"
if (data->value){
#line 470 "src/typecheck.z"
_ZN4main9typecheck10check_exprE(ctx,data->value) ;
}
;
#line 471 "src/typecheck.z"
return ctx->common._void;
;
}

#line 474 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck16check_assignmentE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast14AssignmentDataE assignment) {
#line 475 "src/typecheck.z"
_ZN4main9typecheck10check_exprE(ctx,assignment.left) ;
#line 476 "src/typecheck.z"
_ZN4main9typecheck10check_exprE(ctx,assignment.right) ;
#line 477 "src/typecheck.z"
return ctx->common._void;
;
}

#line 480 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck12check_returnE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ExprE*  expr) {
#line 481 "src/typecheck.z"
_ZN4main9typecheck10check_exprE(ctx,expr) ;
#line 482 "src/typecheck.z"
return ctx->common._void;
;
}

#line 485 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck12check_sizeofE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ExprE*  expr) {
#line 486 "src/typecheck.z"
_ZN4main9typecheck10check_exprE(ctx,expr) ;
#line 487 "src/typecheck.z"
return ctx->common._u64;
;
}

#line 490 "src/typecheck.z"
_ZN4main3ast2TyE*  _ZN4main9typecheck10check_exprE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ExprE*  expr) {
#line 491 "src/typecheck.z"
if ((expr->kind== ExprKind_Unary)){
#line 491 "src/typecheck.z"
return _ZN4main9typecheck11check_unaryE(ctx,expr) ;
;
}
else {
#line 492 "src/typecheck.z"
if ((expr->kind== ExprKind_Binary)){
#line 492 "src/typecheck.z"
return _ZN4main9typecheck12check_binaryE(ctx,expr) ;
;
}
else {
#line 493 "src/typecheck.z"
if ((expr->kind== ExprKind_Block)){
#line 493 "src/typecheck.z"
return _ZN4main9typecheck16check_block_exprE(ctx,expr) ;
;
}
else {
#line 494 "src/typecheck.z"
if ((expr->kind== ExprKind_Call)){
#line 494 "src/typecheck.z"
return _ZN4main9typecheck10check_callE(ctx,expr) ;
;
}
else {
#line 495 "src/typecheck.z"
if ((expr->kind== ExprKind_Conditional)){
#line 495 "src/typecheck.z"
return _ZN4main9typecheck17check_conditionalE(ctx,expr) ;
;
}
else {
#line 496 "src/typecheck.z"
if ((expr->kind== ExprKind_ControlFlow)){
#line 496 "src/typecheck.z"
return ctx->common._void;
;
}
else {
#line 497 "src/typecheck.z"
if ((expr->kind== ExprKind_While)){
#line 497 "src/typecheck.z"
return _ZN4main9typecheck11check_whileE(ctx,expr) ;
;
}
else {
#line 498 "src/typecheck.z"
if ((expr->kind== ExprKind_Indexing)){
#line 498 "src/typecheck.z"
return _ZN4main9typecheck14check_indexingE(ctx,expr) ;
;
}
else {
#line 499 "src/typecheck.z"
if ((expr->kind== ExprKind_Field)){
#line 499 "src/typecheck.z"
return _ZN4main9typecheck11check_fieldE(ctx,expr) ;
;
}
else {
#line 500 "src/typecheck.z"
if ((expr->kind== ExprKind_Path)){
#line 500 "src/typecheck.z"
return _ZN4main9typecheck10check_pathE(ctx,&expr->node.path) ;
;
}
else {
#line 501 "src/typecheck.z"
if ((expr->kind== ExprKind_Literal)){
#line 501 "src/typecheck.z"
return _ZN4main9typecheck17ast_literal_to_tyE(ctx,expr->node.lit) ;
;
}
else {
#line 502 "src/typecheck.z"
if ((expr->kind== ExprKind_Assignment)){
#line 502 "src/typecheck.z"
return _ZN4main9typecheck16check_assignmentE(ctx,expr->node.assignment) ;
;
}
else {
#line 503 "src/typecheck.z"
if ((expr->kind== ExprKind_Let)){
#line 503 "src/typecheck.z"
return _ZN4main9typecheck9check_letE(ctx,&expr->node._let) ;
;
}
else {
#line 504 "src/typecheck.z"
if ((expr->kind== ExprKind_Return)){
#line 504 "src/typecheck.z"
return _ZN4main9typecheck12check_returnE(ctx,expr->node._return) ;
;
}
else {
#line 505 "src/typecheck.z"
if ((expr->kind== ExprKind_Sizeof)){
#line 505 "src/typecheck.z"
return _ZN4main9typecheck12check_sizeofE(ctx,expr->node._sizeof) ;
;
}
else {
#line 506 "src/typecheck.z"
abort() ;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}

#line 510 "src/typecheck.z"
void  _ZN4main9typecheck14check_variableE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 511 "src/typecheck.z"
_ZN4main3ast12VariableDataE*  data = &item->node.variable;
;
#line 512 "src/typecheck.z"
_ZN4main3ast2TyE*  decl_ty = data->ty;
;
#line 514 "src/typecheck.z"
if (item->node.variable.body){
#line 515 "src/typecheck.z"
_ZN4main3ast2TyE*  expr_ty = _ZN4main9typecheck10check_exprE(ctx,data->body) ;
;
#line 517 "src/typecheck.z"
data->body = _ZN4main9typecheck16coerce_expr_typeE(ctx,data->body,expr_ty,decl_ty) ;
;
}
;
}

#line 521 "src/typecheck.z"
void  _ZN4main9typecheck14check_functionE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 523 "src/typecheck.z"
if (item->node.function.body){
#line 524 "src/typecheck.z"
_ZN4main9typecheck10check_exprE(ctx,item->node.function.body) ;
}
;
}

#line 528 "src/typecheck.z"
void  _ZN4main9typecheck10check_itemE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 529 "src/typecheck.z"
if ((item->kind== ItemKind_Enum)){
}
else {
#line 530 "src/typecheck.z"
if (((item->kind== ItemKind_Struct)|| (item->kind== ItemKind_Union))){
}
else {
#line 531 "src/typecheck.z"
if ((item->kind== ItemKind_Use)){
}
else {
#line 532 "src/typecheck.z"
if ((item->kind== ItemKind_Module)){
#line 532 "src/typecheck.z"
_ZN4main9typecheck9check_modE(ctx,item->node.module) ;
}
else {
#line 533 "src/typecheck.z"
if (((item->kind== ItemKind_Const)|| (item->kind== ItemKind_Variable))){
#line 533 "src/typecheck.z"
_ZN4main9typecheck14check_variableE(ctx,item) ;
}
else {
#line 534 "src/typecheck.z"
if ((item->kind== ItemKind_Function)){
#line 534 "src/typecheck.z"
_ZN4main9typecheck14check_functionE(ctx,item) ;
}
else {
#line 535 "src/typecheck.z"
abort() ;
}
;
}
;
}
;
}
;
}
;
}
;
}

#line 538 "src/typecheck.z"
void  _ZN4main9typecheck9check_modE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast6ModuleE*  module) {
#line 539 "src/typecheck.z"
u32 i = 0;
;
#line 540 "src/typecheck.z"
while ( (i< module->num_items))
{
#line 541 "src/typecheck.z"
_ZN4main9typecheck10check_itemE(ctx,module->items[i]) ;
#line 542 "src/typecheck.z"
i = (i+ 1);
;
}
;
}

#line 546 "src/typecheck.z"
void  _ZN4main9typecheck12collect_enumE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ItemE*  item, _ZN4main3ast4PathE path) {
#line 548 "src/typecheck.z"
_ZN4main3ast2TyE*  ty = item->node._enum.ty;
;
#line 549 "src/typecheck.z"
_ZN4main3ast7EnumDefE*  def = &ty->node._enum;
;
#line 551 "src/typecheck.z"
def->variants = malloc((sizeof(_ZN4main9interning3SidE)* item->node._enum.num_variants)) ;
;
#line 552 "src/typecheck.z"
u32 i = 0;
;
#line 553 "src/typecheck.z"
while ( (i< item->node._enum.num_variants))
{
#line 554 "src/typecheck.z"
def->variants[i] = item->node._enum.variants[i].ident.name;
;
#line 555 "src/typecheck.z"
i = (i+ 1);
;
}
;
#line 557 "src/typecheck.z"
def->num_variants = item->node._enum.num_variants;
;
}

#line 560 "src/typecheck.z"
void  _ZN4main9typecheck16collect_variableE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 561 "src/typecheck.z"
_ZN4main3ast12VariableDataE*  data = &item->node.variable;
;
#line 562 "src/typecheck.z"
data->ty = _ZN4main9typecheck14ast_type_to_tyE(ctx,data->ast_ty) ;
;
}

#line 565 "src/typecheck.z"
void  _ZN4main9typecheck16collect_functionE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 567 "src/typecheck.z"
_ZN4main3ast14FunctionHeaderE*  header = &item->node.function.header;
;
#line 569 "src/typecheck.z"
_ZN4main3ast5FnDefE def ;
;
#line 571 "src/typecheck.z"
def.output = _ZN4main9typecheck14ast_type_to_tyE(ctx,header->output_ast_ty) ;
;
#line 572 "src/typecheck.z"
def.num_parameters = header->num_parameters;
;
#line 573 "src/typecheck.z"
def.parameters = malloc((8* def.num_parameters)) ;
;
#line 575 "src/typecheck.z"
u32 i = 0;
;
#line 576 "src/typecheck.z"
while ( (i< def.num_parameters))
{
#line 577 "src/typecheck.z"
_ZN4main3ast2TyE*  param_ty = _ZN4main9typecheck14ast_type_to_tyE(ctx,header->parameters[i].ast_ty) ;
;
#line 578 "src/typecheck.z"
def.parameters[i] = param_ty;
;
#line 579 "src/typecheck.z"
header->parameters[i].ty = param_ty;
;
#line 580 "src/typecheck.z"
i = (i+ 1);
;
}
;
#line 583 "src/typecheck.z"
_ZN4main3ast2TyE ty ;
;
#line 584 "src/typecheck.z"
ty.kind = TyKind_Fn;
;
#line 585 "src/typecheck.z"
ty.node.function = def;
;
#line 587 "src/typecheck.z"
item->node.function.header.ty = _ZN4main9typecheck9intern_tyE(ctx,ty) ;
;
}

#line 590 "src/typecheck.z"
void  _ZN4main9typecheck16collect_compoundE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ItemE*  item, _ZN4main3ast4PathE path) {
#line 591 "src/typecheck.z"
_ZN4main3ast2TyE*  ty = item->node.compound.ty;
;
#line 592 "src/typecheck.z"
_ZN4main3ast11CompoundDefE*  def = &ty->node.compound;
;
#line 594 "src/typecheck.z"
if ((item->node.compound.num_fields> 0)){
#line 596 "src/typecheck.z"
def->fields = malloc((sizeof(_ZN4main3ast8FieldDefE)* item->node.compound.num_fields)) ;
;
#line 597 "src/typecheck.z"
u32 i = 0;
;
#line 598 "src/typecheck.z"
while ( (i< item->node.compound.num_fields))
{
#line 599 "src/typecheck.z"
def->fields[i].name = item->node.compound.fields[i].ident.name;
;
#line 600 "src/typecheck.z"
def->fields[i].ty = _ZN4main9typecheck14ast_type_to_tyE(ctx,item->node.compound.fields[i].ast_ty) ;
;
#line 601 "src/typecheck.z"
i = (i+ 1);
;
}
;
#line 603 "src/typecheck.z"
def->num_fields = item->node.compound.num_fields;
;
}
;
}

#line 608 "src/typecheck.z"
void  _ZN4main9typecheck11collect_modE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast6ModuleE*  module) ;

#line 610 "src/typecheck.z"
void  _ZN4main9typecheck12collect_itemE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast4ItemE*  item, _ZN4main3ast4PathE path) {
#line 611 "src/typecheck.z"
if ((item->kind== ItemKind_Enum)){
#line 611 "src/typecheck.z"
_ZN4main9typecheck12collect_enumE(ctx,item,path) ;
}
else {
#line 612 "src/typecheck.z"
if ((item->kind== ItemKind_Function)){
#line 612 "src/typecheck.z"
_ZN4main9typecheck16collect_functionE(ctx,item) ;
}
else {
#line 613 "src/typecheck.z"
if (((item->kind== ItemKind_Variable)|| (item->kind== ItemKind_Const))){
#line 613 "src/typecheck.z"
_ZN4main9typecheck16collect_variableE(ctx,item) ;
}
else {
#line 614 "src/typecheck.z"
if (((item->kind== ItemKind_Struct)|| (item->kind== ItemKind_Union))){
#line 614 "src/typecheck.z"
_ZN4main9typecheck16collect_compoundE(ctx,item,path) ;
}
else {
#line 615 "src/typecheck.z"
if ((item->kind== ItemKind_Module)){
#line 615 "src/typecheck.z"
_ZN4main9typecheck11collect_modE(ctx,item->node.module) ;
}
;
}
;
}
;
}
;
}
;
}

#line 618 "src/typecheck.z"
void  _ZN4main9typecheck11collect_modE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast6ModuleE*  module) {
#line 619 "src/typecheck.z"
u32 i = 0;
;
#line 620 "src/typecheck.z"
while ( (i< module->num_items))
{
#line 621 "src/typecheck.z"
_ZN4main3ast4ItemE*  item = module->items[i];
;
#line 622 "src/typecheck.z"
u32 idx = _ZN4main6intmap13intmap_lookupE(module->index_lookup,item->ident.name.x) ;
;
#line 623 "src/typecheck.z"
_ZN4main9typecheck12collect_itemE(ctx,item,module->index[idx].path) ;
#line 624 "src/typecheck.z"
i = (i+ 1);
;
}
;
}

#line 628 "src/typecheck.z"
void  _ZN4main9typecheck13collect_namesE(_ZN4main9typecheck11TypeContextE*  ctx, _ZN4main3ast6ModuleE*  module) {
#line 629 "src/typecheck.z"
u32 i = 0;
;
#line 630 "src/typecheck.z"
while ( (i< module->num_items))
{
#line 631 "src/typecheck.z"
_ZN4main3ast4ItemE*  item = module->items[i];
;
#line 632 "src/typecheck.z"
if (((item->kind== ItemKind_Struct)|| (item->kind== ItemKind_Union))){
#line 633 "src/typecheck.z"
_ZN4main3ast11CompoundDefE def ;
;
#line 634 "src/typecheck.z"
def.path.num_segments = (module->path.num_segments+ 1);
;
#line 635 "src/typecheck.z"
def.path.segments = malloc((sizeof(_ZN4main3ast5IdentE)* def.path.num_segments)) ;
;
#line 636 "src/typecheck.z"
memcpy(def.path.segments,module->path.segments,(sizeof(_ZN4main3ast5IdentE)* module->path.num_segments)) ;
#line 637 "src/typecheck.z"
def.path.segments[module->path.num_segments] = item->ident;
;
#line 639 "src/typecheck.z"
_ZN4main3ast2TyE ty ;
;
#line 640 "src/typecheck.z"
if ((item->kind== ItemKind_Struct)){
#line 640 "src/typecheck.z"
ty.kind = TyKind_Struct;
;
}
else {
#line 641 "src/typecheck.z"
if ((item->kind== ItemKind_Union)){
#line 641 "src/typecheck.z"
ty.kind = TyKind_Union;
;
}
;
}
;
#line 643 "src/typecheck.z"
ty.node.compound = def;
;
#line 645 "src/typecheck.z"
item->node.compound.ty = _ZN4main9typecheck9intern_tyE(ctx,ty) ;
;
}
else {
#line 647 "src/typecheck.z"
if ((item->kind== ItemKind_Enum)){
#line 649 "src/typecheck.z"
_ZN4main3ast7EnumDefE def ;
;
#line 650 "src/typecheck.z"
def.path.num_segments = (module->path.num_segments+ 1);
;
#line 651 "src/typecheck.z"
def.path.segments = malloc((sizeof(_ZN4main3ast5IdentE)* def.path.num_segments)) ;
;
#line 652 "src/typecheck.z"
memcpy(def.path.segments,module->path.segments,(sizeof(_ZN4main3ast5IdentE)* module->path.num_segments)) ;
#line 653 "src/typecheck.z"
def.path.segments[module->path.num_segments] = item->ident;
;
#line 655 "src/typecheck.z"
_ZN4main3ast2TyE ty ;
;
#line 656 "src/typecheck.z"
ty.kind = TyKind_Enum;
;
#line 658 "src/typecheck.z"
ty.node._enum = def;
;
#line 660 "src/typecheck.z"
item->node._enum.ty = _ZN4main9typecheck9intern_tyE(ctx,ty) ;
;
}
else {
#line 662 "src/typecheck.z"
if ((item->kind== ItemKind_Module)){
#line 662 "src/typecheck.z"
_ZN4main9typecheck13collect_namesE(ctx,item->node.module) ;
}
;
}
;
}
;
#line 663 "src/typecheck.z"
i = (i+ 1);
;
}
;
}

#line 667 "src/typecheck.z"
void  _ZN4main9typecheck5checkE(_ZN4main7session7SessionE*  sess, _ZN4main3ast3AstE*  ast) {
#line 668 "src/typecheck.z"
_ZN4main9typecheck11TypeContextE ctx ;
;
#line 670 "src/typecheck.z"
ctx.ast = ast;
;
#line 671 "src/typecheck.z"
ctx.interner = &sess->interner;
;
#line 672 "src/typecheck.z"
ctx.source_map = &sess->source;
;
#line 673 "src/typecheck.z"
ctx.types_lookup = _ZN4main6intmap13intmap_createE(1024) ;
;
#line 674 "src/typecheck.z"
ctx.types = malloc((sizeof(_ZN4main3ast2TyE)* 1024)) ;
;
#line 675 "src/typecheck.z"
ctx.next_type_idx = 1;
;
#line 676 "src/typecheck.z"
_ZN4main9typecheck19create_common_typesE(&ctx) ;
#line 678 "src/typecheck.z"
_ZN4main9typecheck13collect_namesE(&ctx,ast->root_module) ;
#line 679 "src/typecheck.z"
_ZN4main9typecheck11collect_modE(&ctx,ast->root_module) ;
#line 680 "src/typecheck.z"
_ZN4main9typecheck9check_modE(&ctx,ast->root_module) ;
}








typedef struct _ZN4main7codegen14CodegenContextE _ZN4main7codegen14CodegenContextE;
#line 8 "src/codegen.z"
typedef struct _ZN4main7codegen14CodegenContextE {
_ZN4main4cstd4FILEE*  out;
_ZN4main6strmap6StrMapE*  ident_is_ptr;
_ZN4main7session7SessionE*  sess;
_ZN4main3ast3AstE*  ast;
_ZN4main10source_map9SourceMapE*  source;
_ZN4main3ast6ModuleE*  current_module;
_ZN4main9interning8InternerE*  interner;
} _ZN4main7codegen14CodegenContextE;


#line 18 "src/codegen.z"
void  _ZN4main7codegen13generate_exprE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast4ExprE*  expr) ;

#line 19 "src/codegen.z"
void  _ZN4main7codegen14generate_blockE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast5BlockE*  block) ;

#line 20 "src/codegen.z"
void  _ZN4main7codegen13generate_itemE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast4ItemE*  item) ;

#line 22 "src/codegen.z"
u32 _ZN4main7codegen11type_is_ptrE(_ZN4main3ast7AstTypeE*  ty) {
#line 23 "src/codegen.z"
if ((ty->kind== AstTypeKind_Ptr)){
#line 23 "src/codegen.z"
return 1;
;
}
else {
#line 24 "src/codegen.z"
return 0;
;
}
;
}

#line 27 "src/codegen.z"
void  _ZN4main7codegen16generate_preludeE(_ZN4main7codegen14CodegenContextE*  ctx) {
#line 28 "src/codegen.z"
fprintf(ctx->out,"//Prelude\n") ;
#line 29 "src/codegen.z"
fprintf(ctx->out,"#include <stdint.h>\n") ;
#line 30 "src/codegen.z"
fprintf(ctx->out,"#include <stdbool.h>\n") ;
#line 31 "src/codegen.z"
fprintf(ctx->out,"typedef uint8_t u8;\n") ;
#line 32 "src/codegen.z"
fprintf(ctx->out,"typedef uint16_t u16;\n") ;
#line 33 "src/codegen.z"
fprintf(ctx->out,"typedef uint32_t u32;\n") ;
#line 34 "src/codegen.z"
fprintf(ctx->out,"typedef uint64_t u64;\n") ;
#line 35 "src/codegen.z"
fprintf(ctx->out,"typedef int8_t i8;\n") ;
#line 36 "src/codegen.z"
fprintf(ctx->out,"typedef int16_t i16;\n") ;
#line 37 "src/codegen.z"
fprintf(ctx->out,"typedef int32_t i32;\n") ;
#line 38 "src/codegen.z"
fprintf(ctx->out,"typedef int64_t i64;\n") ;
#line 39 "src/codegen.z"
fprintf(ctx->out,"typedef float f32;\n") ;
#line 40 "src/codegen.z"
fprintf(ctx->out,"typedef double f64;\n") ;
#line 41 "src/codegen.z"
fprintf(ctx->out,"typedef const char constchar;\n") ;
#line 42 "src/codegen.z"
fprintf(ctx->out,"typedef const void constvoid;\n") ;
}

#line 45 "src/codegen.z"
void  _ZN4main7codegen12generate_sidE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main9interning3SidE sid) {
#line 46 "src/codegen.z"
fprintf(ctx->out,"%s",_ZN4main9interning7get_strE(ctx->interner,sid) ) ;
}

#line 49 "src/codegen.z"
void  _ZN4main7codegen19generate_identifierE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast5IdentE ident) {
#line 50 "src/codegen.z"
_ZN4main7codegen12generate_sidE(ctx,ident.name) ;
}

#line 53 "src/codegen.z"
void  _ZN4main7codegen16generate_patternE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast7PatternE pat) {
#line 54 "src/codegen.z"
_ZN4main7codegen19generate_identifierE(ctx,pat.ident) ;
}

#line 57 "src/codegen.z"
void  _ZN4main7codegen11mangle_pathE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast4PathE path) {
#line 58 "src/codegen.z"
_ZN4main3ast4ItemE*  item = path.binding.node.item;
;
#line 59 "src/codegen.z"
if (((path.binding.kind== BindingKind_Item)&& item->should_mangle)){
#line 60 "src/codegen.z"
fprintf(ctx->out,"_ZN") ;
#line 61 "src/codegen.z"
u32 i = 0;
;
#line 62 "src/codegen.z"
while ( (i< path.num_segments))
{
#line 63 "src/codegen.z"
char*  seg = _ZN4main9interning7get_strE(ctx->interner,path.segments[i].name) ;
;
#line 64 "src/codegen.z"
fprintf(ctx->out,"%lu%s",strlen(seg) ,seg) ;
#line 65 "src/codegen.z"
i = (i+ 1);
;
}
;
#line 67 "src/codegen.z"
fprintf(ctx->out,"E") ;
}
else {
#line 68 "src/codegen.z"
if ((path.binding.kind== BindingKind_Variant)){
#line 69 "src/codegen.z"
fprintf(ctx->out,"%s_%s",_ZN4main9interning7get_strE(ctx->interner,path.segments[(path.num_segments- 2)].name) ,_ZN4main9interning7get_strE(ctx->interner,path.segments[(path.num_segments- 1)].name) ) ;
}
else {
#line 72 "src/codegen.z"
fprintf(ctx->out,"%s",_ZN4main9interning7get_strE(ctx->interner,path.segments[(path.num_segments- 1)].name) ) ;
}
;
}
;
}

#line 76 "src/codegen.z"
void  _ZN4main7codegen21mangle_path_and_identE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast4PathE path, _ZN4main3ast5IdentE ident) {
#line 77 "src/codegen.z"
fprintf(ctx->out," _ZN") ;
#line 78 "src/codegen.z"
u32 i = 0;
;
#line 79 "src/codegen.z"
while ( (i< path.num_segments))
{
#line 80 "src/codegen.z"
char*  seg = _ZN4main9interning7get_strE(ctx->interner,path.segments[i].name) ;
;
#line 81 "src/codegen.z"
fprintf(ctx->out,"%lu%s",strlen(seg) ,seg) ;
#line 82 "src/codegen.z"
i = (i+ 1);
;
}
;
#line 84 "src/codegen.z"
char*  name = _ZN4main9interning7get_strE(ctx->interner,ident.name) ;
;
#line 85 "src/codegen.z"
fprintf(ctx->out,"%lu%sE",strlen(name) ,name) ;
}

#line 88 "src/codegen.z"
void  _ZN4main7codegen20mangle_function_nameE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast6ModuleE*  module, _ZN4main3ast5IdentE ident, _ZN4main3ast14FunctionHeaderE header) {
#line 89 "src/codegen.z"
_ZN4main7codegen21mangle_path_and_identE(ctx,module->path,ident) ;
}

#line 92 "src/codegen.z"
void  _ZN4main7codegen13generate_typeE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast7AstTypeE*  ty) {
#line 93 "src/codegen.z"
if ((ty->kind== AstTypeKind_Path)){
#line 94 "src/codegen.z"
_ZN4main7codegen11mangle_pathE(ctx,ty->node.path) ;
}
else {
#line 96 "src/codegen.z"
if ((ty->kind== AstTypeKind_Ptr)){
#line 97 "src/codegen.z"
_ZN4main7codegen13generate_typeE(ctx,ty->node.ptr) ;
#line 98 "src/codegen.z"
fprintf(ctx->out,"* ") ;
}
else {
#line 100 "src/codegen.z"
if ((ty->kind== AstTypeKind_Void)){
#line 101 "src/codegen.z"
fprintf(ctx->out,"void ") ;
}
else {
#line 103 "src/codegen.z"
abort() ;
}
;
}
;
}
;
}

#line 106 "src/codegen.z"
void  _ZN4main7codegen13generate_charE(_ZN4main7codegen14CodegenContextE*  ctx, char c) {
#line 107 "src/codegen.z"
if ((c== '\n')){
#line 107 "src/codegen.z"
fprintf(ctx->out,"'\\n'") ;
}
else {
#line 108 "src/codegen.z"
if ((c== '\t')){
#line 108 "src/codegen.z"
fprintf(ctx->out,"'\\t'") ;
}
else {
#line 109 "src/codegen.z"
if ((c== '\r')){
#line 109 "src/codegen.z"
fprintf(ctx->out,"'\\r'") ;
}
else {
#line 110 "src/codegen.z"
if ((c== '\\')){
#line 110 "src/codegen.z"
fprintf(ctx->out,"'\\\\'") ;
}
else {
#line 111 "src/codegen.z"
if ((c== '\'')){
#line 111 "src/codegen.z"
fprintf(ctx->out,"'\\''") ;
}
else {
#line 112 "src/codegen.z"
fprintf(ctx->out,"'%c'",c) ;
}
;
}
;
}
;
}
;
}
;
}

#line 115 "src/codegen.z"
void  _ZN4main7codegen16generate_literalE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast7LiteralE lit) {
#line 116 "src/codegen.z"
if ((lit.kind== LiteralKind_Int)){
#line 116 "src/codegen.z"
fprintf(ctx->out,"%ld",lit.value.integer) ;
}
else {
#line 117 "src/codegen.z"
if ((lit.kind== LiteralKind_Float)){
#line 117 "src/codegen.z"
fprintf(ctx->out,"%f",lit.value.floating) ;
}
else {
#line 118 "src/codegen.z"
if ((lit.kind== LiteralKind_Bool)){
#line 118 "src/codegen.z"
if (lit.value.boolean){
#line 118 "src/codegen.z"
fprintf(ctx->out,"true") ;
}
else {
#line 118 "src/codegen.z"
fprintf(ctx->out,"false") ;
}
;
}
else {
#line 119 "src/codegen.z"
if ((lit.kind== LiteralKind_Str)){
#line 120 "src/codegen.z"
fprintf(ctx->out,"\"%s\"",_ZN4main9interning7get_strE(ctx->interner,lit.value.str) ) ;
}
else {
#line 122 "src/codegen.z"
if ((lit.kind== LiteralKind_Char)){
#line 122 "src/codegen.z"
_ZN4main7codegen13generate_charE(ctx,lit.value.ch) ;
}
else {
#line 123 "src/codegen.z"
abort() ;
}
;
}
;
}
;
}
;
}
;
}

#line 126 "src/codegen.z"
void  _ZN4main7codegen14generate_unaryE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast9UnaryDataE unary) {
#line 127 "src/codegen.z"
if ((unary.op== UnaryOperatorKind_Negation)){
#line 127 "src/codegen.z"
fprintf(ctx->out,"-") ;
}
else {
#line 128 "src/codegen.z"
if ((unary.op== UnaryOperatorKind_Complement)){
#line 128 "src/codegen.z"
fprintf(ctx->out,"!") ;
}
else {
#line 129 "src/codegen.z"
if ((unary.op== UnaryOperatorKind_Refer)){
#line 129 "src/codegen.z"
fprintf(ctx->out,"&") ;
}
else {
#line 130 "src/codegen.z"
if ((unary.op== UnaryOperatorKind_Deref)){
#line 130 "src/codegen.z"
fprintf(ctx->out,"*") ;
}
else {
#line 131 "src/codegen.z"
abort() ;
}
;
}
;
}
;
}
;
#line 133 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,unary.inner) ;
}

#line 136 "src/codegen.z"
void  _ZN4main7codegen15generate_binaryE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast10BinaryDataE binary) {
#line 137 "src/codegen.z"
fprintf(ctx->out,"(") ;
#line 138 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,binary.left) ;
#line 139 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Addition)){
#line 139 "src/codegen.z"
fprintf(ctx->out,"+ ") ;
}
else {
#line 140 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Subtraction)){
#line 140 "src/codegen.z"
fprintf(ctx->out,"- ") ;
}
else {
#line 141 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Product)){
#line 141 "src/codegen.z"
fprintf(ctx->out,"* ") ;
}
else {
#line 142 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Division)){
#line 142 "src/codegen.z"
fprintf(ctx->out,"/ ") ;
}
else {
#line 143 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Modulus)){
#line 143 "src/codegen.z"
fprintf(ctx->out,"%% ") ;
}
else {
#line 145 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Less)){
#line 145 "src/codegen.z"
fprintf(ctx->out,"< ") ;
}
else {
#line 146 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_LessEq)){
#line 146 "src/codegen.z"
fprintf(ctx->out,"<= ") ;
}
else {
#line 147 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Greater)){
#line 147 "src/codegen.z"
fprintf(ctx->out,"> ") ;
}
else {
#line 148 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_GreaterEq)){
#line 148 "src/codegen.z"
fprintf(ctx->out,">= ") ;
}
else {
#line 149 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Equality)){
#line 149 "src/codegen.z"
fprintf(ctx->out,"== ") ;
}
else {
#line 150 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_NotEq)){
#line 150 "src/codegen.z"
fprintf(ctx->out,"!= ") ;
}
else {
#line 152 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_BAnd)){
#line 152 "src/codegen.z"
fprintf(ctx->out,"& ") ;
}
else {
#line 153 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_BOr)){
#line 153 "src/codegen.z"
fprintf(ctx->out,"| ") ;
}
else {
#line 154 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Xor)){
#line 154 "src/codegen.z"
fprintf(ctx->out,"^ ") ;
}
else {
#line 155 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_LeftShift)){
#line 155 "src/codegen.z"
fprintf(ctx->out,"<< ") ;
}
else {
#line 156 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_RightShift)){
#line 156 "src/codegen.z"
fprintf(ctx->out,">> ") ;
}
else {
#line 158 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_And)){
#line 158 "src/codegen.z"
fprintf(ctx->out,"&& ") ;
}
else {
#line 159 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Or)){
#line 159 "src/codegen.z"
fprintf(ctx->out,"|| ") ;
}
else {
#line 160 "src/codegen.z"
abort() ;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
#line 161 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,binary.right) ;
#line 162 "src/codegen.z"
fprintf(ctx->out,")") ;
}

#line 165 "src/codegen.z"
void  _ZN4main7codegen13generate_callE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast8CallDataE call) {
#line 166 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,call.func) ;
#line 168 "src/codegen.z"
fprintf(ctx->out,"(") ;
#line 169 "src/codegen.z"
u32 i = 0;
;
#line 170 "src/codegen.z"
while ( (i< call.num_args))
{
#line 171 "src/codegen.z"
_ZN4main3ast4ExprE*  arg = call.args[i];
;
#line 172 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,arg) ;
#line 173 "src/codegen.z"
if ((i< (call.num_args- 1))){
#line 173 "src/codegen.z"
fprintf(ctx->out,",") ;
}
;
#line 174 "src/codegen.z"
i = (i+ 1);
;
}
;
#line 176 "src/codegen.z"
fprintf(ctx->out,") ") ;
}

#line 179 "src/codegen.z"
void  _ZN4main7codegen20generate_conditionalE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast15ConditionalDataE cond) {
#line 180 "src/codegen.z"
fprintf(ctx->out,"if (") ;
#line 181 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,cond.condition) ;
#line 182 "src/codegen.z"
fprintf(ctx->out,")") ;
#line 183 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,cond.then) ;
#line 184 "src/codegen.z"
if (cond.otherwise){
#line 185 "src/codegen.z"
fprintf(ctx->out,"else ") ;
#line 186 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,cond.otherwise) ;
}
;
}

#line 190 "src/codegen.z"
void  _ZN4main7codegen14generate_whileE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast9WhileDataE data) {
#line 191 "src/codegen.z"
fprintf(ctx->out,"while ( ") ;
#line 192 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,data.condition) ;
#line 193 "src/codegen.z"
fprintf(ctx->out,")\n") ;
#line 194 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,data.body) ;
}

#line 197 "src/codegen.z"
void  _ZN4main7codegen17generate_indexingE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast12IndexingDataE idx) {
#line 198 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,idx.array) ;
#line 199 "src/codegen.z"
fprintf(ctx->out,"[") ;
#line 200 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,idx.index) ;
#line 201 "src/codegen.z"
fprintf(ctx->out,"]") ;
}

#line 204 "src/codegen.z"
void  _ZN4main7codegen14generate_fieldE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast9FieldDataE field) {
#line 205 "src/codegen.z"
_ZN4main3ast4ExprE*  strct = field.strct;
;
#line 206 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,strct) ;
#line 208 "src/codegen.z"
char*  field_name = _ZN4main9interning7get_strE(ctx->interner,field.ident.name) ;
;
#line 210 "src/codegen.z"
bool is_ptr = false;
;
#line 211 "src/codegen.z"
char*  accessor_str ;
;
#line 212 "src/codegen.z"
if ((strct->kind== ExprKind_Path)){
#line 213 "src/codegen.z"
char*  strct_name = _ZN4main9interning7get_strE(ctx->interner,strct->node.path.segments[0].name) ;
;
#line 214 "src/codegen.z"
is_ptr = _ZN4main6strmap13strmap_lookupE(ctx->ident_is_ptr,strct_name) ;
;
}
;
#line 217 "src/codegen.z"
if (is_ptr){
#line 217 "src/codegen.z"
accessor_str = "->";
;
}
else {
#line 218 "src/codegen.z"
accessor_str = ".";
;
}
;
#line 219 "src/codegen.z"
fprintf(ctx->out,"%s%s",accessor_str,field_name) ;
}

#line 222 "src/codegen.z"
void  _ZN4main7codegen15generate_sizeofE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast4ExprE*  expr) {
#line 223 "src/codegen.z"
fprintf(ctx->out,"sizeof(") ;
#line 224 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,expr) ;
#line 225 "src/codegen.z"
fprintf(ctx->out,")") ;
}

#line 228 "src/codegen.z"
void  _ZN4main7codegen19generate_assignmentE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast14AssignmentDataE assignment) {
#line 229 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,assignment.left) ;
#line 230 "src/codegen.z"
fprintf(ctx->out," = ") ;
#line 231 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,assignment.right) ;
#line 232 "src/codegen.z"
fprintf(ctx->out,";\n") ;
}

#line 235 "src/codegen.z"
void  _ZN4main7codegen15generate_returnE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast4ExprE*  expr) {
#line 236 "src/codegen.z"
fprintf(ctx->out,"return ") ;
#line 237 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,expr) ;
#line 238 "src/codegen.z"
fprintf(ctx->out,";\n") ;
}

#line 241 "src/codegen.z"
void  _ZN4main7codegen21generate_control_flowE(_ZN4main7codegen14CodegenContextE*  ctx, bool is_continue) {
#line 242 "src/codegen.z"
if (is_continue){
#line 242 "src/codegen.z"
fprintf(ctx->out,"continue;\n") ;
}
else {
#line 243 "src/codegen.z"
fprintf(ctx->out,"break;\n") ;
}
;
}

#line 246 "src/codegen.z"
void  _ZN4main7codegen12generate_letE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast7LetDataE data) {
#line 248 "src/codegen.z"
_ZN4main7codegen13generate_typeE(ctx,data.ast_ty) ;
#line 250 "src/codegen.z"
char*  var_name = _ZN4main9interning7get_strE(ctx->interner,data.pat.ident.name) ;
;
#line 252 "src/codegen.z"
_ZN4main6strmap13strmap_insertE(ctx->ident_is_ptr,var_name,_ZN4main7codegen11type_is_ptrE(data.ast_ty) ) ;
#line 253 "src/codegen.z"
fprintf(ctx->out," %s ",var_name) ;
#line 254 "src/codegen.z"
if (data.value){
#line 255 "src/codegen.z"
fprintf(ctx->out,"= ") ;
#line 256 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,data.value) ;
}
;
#line 258 "src/codegen.z"
fprintf(ctx->out,";\n") ;
}

#line 261 "src/codegen.z"
void  _ZN4main7codegen13generate_castE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast8CastDataE data) {
#line 263 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,data.inner) ;
}

#line 266 "src/codegen.z"
void  _ZN4main7codegen13generate_exprE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast4ExprE*  expr) {
#line 267 "src/codegen.z"
if ((expr->kind== ExprKind_Unary)){
#line 267 "src/codegen.z"
_ZN4main7codegen14generate_unaryE(ctx,expr->node.unary) ;
}
else {
#line 268 "src/codegen.z"
if ((expr->kind== ExprKind_Binary)){
#line 268 "src/codegen.z"
_ZN4main7codegen15generate_binaryE(ctx,expr->node.binary) ;
}
else {
#line 269 "src/codegen.z"
if ((expr->kind== ExprKind_Block)){
#line 269 "src/codegen.z"
_ZN4main7codegen14generate_blockE(ctx,expr->node.block) ;
}
else {
#line 270 "src/codegen.z"
if ((expr->kind== ExprKind_Call)){
#line 270 "src/codegen.z"
_ZN4main7codegen13generate_callE(ctx,expr->node.call) ;
}
else {
#line 271 "src/codegen.z"
if ((expr->kind== ExprKind_Conditional)){
#line 271 "src/codegen.z"
_ZN4main7codegen20generate_conditionalE(ctx,expr->node.conditional) ;
}
else {
#line 272 "src/codegen.z"
if ((expr->kind== ExprKind_While)){
#line 272 "src/codegen.z"
_ZN4main7codegen14generate_whileE(ctx,expr->node.whl) ;
}
else {
#line 273 "src/codegen.z"
if ((expr->kind== ExprKind_Indexing)){
#line 273 "src/codegen.z"
_ZN4main7codegen17generate_indexingE(ctx,expr->node.indexing) ;
}
else {
#line 274 "src/codegen.z"
if ((expr->kind== ExprKind_Field)){
#line 274 "src/codegen.z"
_ZN4main7codegen14generate_fieldE(ctx,expr->node.field) ;
}
else {
#line 275 "src/codegen.z"
if ((expr->kind== ExprKind_Literal)){
#line 275 "src/codegen.z"
_ZN4main7codegen16generate_literalE(ctx,expr->node.lit) ;
}
else {
#line 276 "src/codegen.z"
if ((expr->kind== ExprKind_Path)){
#line 276 "src/codegen.z"
_ZN4main7codegen11mangle_pathE(ctx,expr->node.path) ;
}
else {
#line 277 "src/codegen.z"
if ((expr->kind== ExprKind_Sizeof)){
#line 277 "src/codegen.z"
_ZN4main7codegen15generate_sizeofE(ctx,expr->node._sizeof) ;
}
else {
#line 278 "src/codegen.z"
if ((expr->kind== ExprKind_Assignment)){
#line 278 "src/codegen.z"
_ZN4main7codegen19generate_assignmentE(ctx,expr->node.assignment) ;
}
else {
#line 279 "src/codegen.z"
if ((expr->kind== ExprKind_ControlFlow)){
#line 279 "src/codegen.z"
_ZN4main7codegen21generate_control_flowE(ctx,expr->node.control_flow_is_continue) ;
}
else {
#line 280 "src/codegen.z"
if ((expr->kind== ExprKind_Let)){
#line 280 "src/codegen.z"
_ZN4main7codegen12generate_letE(ctx,expr->node._let) ;
}
else {
#line 281 "src/codegen.z"
if ((expr->kind== ExprKind_Return)){
#line 281 "src/codegen.z"
_ZN4main7codegen15generate_returnE(ctx,expr->node._return) ;
}
else {
#line 282 "src/codegen.z"
if ((expr->kind== ExprKind_Cast)){
#line 282 "src/codegen.z"
_ZN4main7codegen13generate_castE(ctx,expr->node._cast) ;
}
else {
#line 283 "src/codegen.z"
abort() ;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}

#line 286 "src/codegen.z"
void  _ZN4main7codegen14generate_blockE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast5BlockE*  block) {
#line 287 "src/codegen.z"
fprintf(ctx->out,"{\n") ;
#line 288 "src/codegen.z"
u32 i = 0;
;
#line 290 "src/codegen.z"
while ( (i< block->num_exprs))
{
#line 291 "src/codegen.z"
_ZN4main3ast4ExprE*  expr = block->exprs[i];
;
#line 292 "src/codegen.z"
_ZN4main10source_map19emit_line_directiveE(ctx->out,ctx->source,expr->span) ;
#line 293 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,expr) ;
#line 294 "src/codegen.z"
fprintf(ctx->out,";\n") ;
#line 295 "src/codegen.z"
i = (i+ 1);
;
}
;
#line 297 "src/codegen.z"
fprintf(ctx->out,"}\n") ;
}

#line 300 "src/codegen.z"
void  _ZN4main7codegen17generate_variableE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 302 "src/codegen.z"
_ZN4main10source_map19emit_line_directiveE(ctx->out,ctx->source,item->span) ;
#line 304 "src/codegen.z"
_ZN4main7codegen13generate_typeE(ctx,item->node.variable.ast_ty) ;
#line 306 "src/codegen.z"
char*  var_name = _ZN4main9interning7get_strE(ctx->interner,item->ident.name) ;
;
#line 308 "src/codegen.z"
_ZN4main3ast6ModuleE*  module = ctx->current_module;
;
#line 310 "src/codegen.z"
_ZN4main6strmap13strmap_insertE(ctx->ident_is_ptr,var_name,_ZN4main7codegen11type_is_ptrE(item->node.variable.ast_ty) ) ;
#line 311 "src/codegen.z"
_ZN4main7codegen21mangle_path_and_identE(ctx,module->path,item->ident) ;
#line 312 "src/codegen.z"
if (item->node.variable.body){
#line 313 "src/codegen.z"
fprintf(ctx->out,"= ") ;
#line 314 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,item->node.variable.body) ;
}
;
#line 316 "src/codegen.z"
fprintf(ctx->out,";\n") ;
}

#line 319 "src/codegen.z"
void  _ZN4main7codegen17generate_functionE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 321 "src/codegen.z"
_ZN4main10source_map19emit_line_directiveE(ctx->out,ctx->source,item->span) ;
#line 323 "src/codegen.z"
_ZN4main3ast12FunctionDataE func = item->node.function;
;
#line 324 "src/codegen.z"
_ZN4main3ast14FunctionHeaderE header = func.header;
;
#line 325 "src/codegen.z"
_ZN4main7codegen13generate_typeE(ctx,header.output_ast_ty) ;
#line 327 "src/codegen.z"
if (item->should_mangle){
#line 327 "src/codegen.z"
_ZN4main7codegen20mangle_function_nameE(ctx,ctx->current_module,item->ident,header) ;
}
else {
#line 328 "src/codegen.z"
fprintf(ctx->out," %s",_ZN4main9interning7get_strE(ctx->interner,item->ident.name) ) ;
}
;
#line 329 "src/codegen.z"
fprintf(ctx->out,"(") ;
#line 331 "src/codegen.z"
u32 i = 0;
;
#line 332 "src/codegen.z"
while ( (i< header.num_parameters))
{
#line 333 "src/codegen.z"
_ZN4main3ast7AstTypeE*  ty = header.parameters[i].ast_ty;
;
#line 334 "src/codegen.z"
if ((ty->kind== AstTypeKind_Variadic)){
#line 335 "src/codegen.z"
fprintf(ctx->out,"...") ;
#line 336 "src/codegen.z"
break;
;
}
;
#line 339 "src/codegen.z"
_ZN4main7codegen13generate_typeE(ctx,ty) ;
#line 341 "src/codegen.z"
char*  param_name = _ZN4main9interning7get_strE(ctx->interner,header.parameters[i].pat.ident.name) ;
;
#line 342 "src/codegen.z"
_ZN4main6strmap13strmap_insertE(ctx->ident_is_ptr,param_name,_ZN4main7codegen11type_is_ptrE(header.parameters[i].ast_ty) ) ;
#line 343 "src/codegen.z"
fprintf(ctx->out," %s",param_name) ;
#line 344 "src/codegen.z"
if ((i< (header.num_parameters- 1))){
#line 344 "src/codegen.z"
fprintf(ctx->out,", ") ;
}
;
#line 345 "src/codegen.z"
i = (i+ 1);
;
}
;
#line 347 "src/codegen.z"
fprintf(ctx->out,") ") ;
#line 348 "src/codegen.z"
if (func.body){
#line 348 "src/codegen.z"
_ZN4main7codegen13generate_exprE(ctx,func.body) ;
}
else {
#line 349 "src/codegen.z"
fprintf(ctx->out,";\n") ;
}
;
}

#line 352 "src/codegen.z"
void  _ZN4main7codegen13generate_enumE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 354 "src/codegen.z"
char*  enum_name = _ZN4main9interning7get_strE(ctx->interner,item->ident.name) ;
;
#line 355 "src/codegen.z"
_ZN4main3ast6ModuleE*  module = ctx->current_module;
;
#line 357 "src/codegen.z"
_ZN4main10source_map19emit_line_directiveE(ctx->out,ctx->source,item->span) ;
#line 358 "src/codegen.z"
fprintf(ctx->out,"typedef enum") ;
#line 359 "src/codegen.z"
_ZN4main7codegen21mangle_path_and_identE(ctx,module->path,item->ident) ;
#line 360 "src/codegen.z"
fprintf(ctx->out," {\n") ;
#line 361 "src/codegen.z"
u32 i = 0;
;
#line 363 "src/codegen.z"
_ZN4main3ast8EnumDataE data = item->node._enum;
;
#line 365 "src/codegen.z"
while ( (i< data.num_variants))
{
#line 366 "src/codegen.z"
char*  variant_name = _ZN4main9interning7get_strE(ctx->interner,data.variants[i].ident.name) ;
;
#line 367 "src/codegen.z"
fprintf(ctx->out,"%s_%s,\n",enum_name,variant_name) ;
#line 368 "src/codegen.z"
i = (i+ 1);
;
}
;
#line 370 "src/codegen.z"
fprintf(ctx->out,"}") ;
#line 371 "src/codegen.z"
_ZN4main7codegen21mangle_path_and_identE(ctx,module->path,item->ident) ;
#line 372 "src/codegen.z"
fprintf(ctx->out,";\n\n") ;
}

#line 375 "src/codegen.z"
void  _ZN4main7codegen17generate_compoundE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 377 "src/codegen.z"
char*  compound_kind ;
;
#line 378 "src/codegen.z"
if ((item->kind== ItemKind_Struct)){
#line 378 "src/codegen.z"
compound_kind = "struct";
;
}
else {
#line 379 "src/codegen.z"
compound_kind = "union";
;
}
;
#line 381 "src/codegen.z"
_ZN4main3ast12CompoundDataE data = item->node.compound;
;
#line 383 "src/codegen.z"
_ZN4main3ast6ModuleE*  module = ctx->current_module;
;
#line 385 "src/codegen.z"
fprintf(ctx->out,"typedef %s",compound_kind) ;
#line 386 "src/codegen.z"
_ZN4main7codegen21mangle_path_and_identE(ctx,module->path,item->ident) ;
#line 387 "src/codegen.z"
_ZN4main7codegen21mangle_path_and_identE(ctx,module->path,item->ident) ;
#line 388 "src/codegen.z"
fprintf(ctx->out,";\n") ;
#line 390 "src/codegen.z"
_ZN4main10source_map19emit_line_directiveE(ctx->out,ctx->source,item->span) ;
#line 391 "src/codegen.z"
if ((data.num_fields> 0)){
#line 392 "src/codegen.z"
fprintf(ctx->out,"typedef %s",compound_kind) ;
#line 393 "src/codegen.z"
_ZN4main7codegen21mangle_path_and_identE(ctx,module->path,item->ident) ;
#line 394 "src/codegen.z"
fprintf(ctx->out," {\n") ;
#line 395 "src/codegen.z"
u32 i = 0;
;
#line 396 "src/codegen.z"
while ( (i< data.num_fields))
{
#line 397 "src/codegen.z"
_ZN4main7codegen13generate_typeE(ctx,data.fields[i].ast_ty) ;
#line 399 "src/codegen.z"
char*  field_name = _ZN4main9interning7get_strE(ctx->interner,data.fields[i].ident.name) ;
;
#line 400 "src/codegen.z"
fprintf(ctx->out," %s;\n",field_name) ;
#line 401 "src/codegen.z"
i = (i+ 1);
;
}
;
#line 403 "src/codegen.z"
fprintf(ctx->out,"}") ;
#line 404 "src/codegen.z"
_ZN4main7codegen21mangle_path_and_identE(ctx,module->path,item->ident) ;
#line 405 "src/codegen.z"
fprintf(ctx->out,";\n\n") ;
}
;
}

#line 409 "src/codegen.z"
void  _ZN4main7codegen12generate_modE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast6ModuleE*  module) {
#line 410 "src/codegen.z"
_ZN4main3ast6ModuleE*  old_module = ctx->current_module;
;
#line 411 "src/codegen.z"
ctx->current_module = module;
;
#line 412 "src/codegen.z"
u32 i = 0;
;
#line 413 "src/codegen.z"
while ( (i< module->num_items))
{
#line 414 "src/codegen.z"
_ZN4main7codegen13generate_itemE(ctx,module->items[i]) ;
#line 415 "src/codegen.z"
i = (i+ 1);
;
}
;
#line 417 "src/codegen.z"
ctx->current_module = old_module;
;
}

#line 420 "src/codegen.z"
void  _ZN4main7codegen13generate_itemE(_ZN4main7codegen14CodegenContextE*  ctx, _ZN4main3ast4ItemE*  item) {
#line 422 "src/codegen.z"
if (((item->kind== ItemKind_Const)|| (item->kind== ItemKind_Variable))){
#line 422 "src/codegen.z"
_ZN4main7codegen17generate_variableE(ctx,item) ;
}
else {
#line 423 "src/codegen.z"
if ((item->kind== ItemKind_Enum)){
#line 423 "src/codegen.z"
_ZN4main7codegen13generate_enumE(ctx,item) ;
}
else {
#line 424 "src/codegen.z"
if ((item->kind== ItemKind_Function)){
#line 424 "src/codegen.z"
_ZN4main7codegen17generate_functionE(ctx,item) ;
}
else {
#line 425 "src/codegen.z"
if (((item->kind== ItemKind_Struct)|| (item->kind== ItemKind_Union))){
#line 425 "src/codegen.z"
_ZN4main7codegen17generate_compoundE(ctx,item) ;
}
else {
#line 426 "src/codegen.z"
if ((item->kind== ItemKind_Module)){
#line 426 "src/codegen.z"
_ZN4main7codegen12generate_modE(ctx,item->node.module) ;
}
;
}
;
}
;
}
;
}
;
#line 427 "src/codegen.z"
fprintf(ctx->out,"\n") ;
}

#line 430 "src/codegen.z"
void  _ZN4main7codegen8generateE(_ZN4main7session7SessionE*  sess, _ZN4main3ast3AstE ast, char*  output_file) {
#line 431 "src/codegen.z"
_ZN4main7codegen14CodegenContextE ctx ;
;
#line 433 "src/codegen.z"
ctx.out = fopen(output_file,"w") ;
;
#line 434 "src/codegen.z"
ctx.ident_is_ptr = _ZN4main6strmap13strmap_createE(1024) ;
;
#line 435 "src/codegen.z"
ctx.sess = sess;
;
#line 436 "src/codegen.z"
ctx.interner = &sess->interner;
;
#line 437 "src/codegen.z"
ctx.source = &sess->source;
;
#line 438 "src/codegen.z"
ctx.ast = &ast;
;
#line 440 "src/codegen.z"
_ZN4main7codegen16generate_preludeE(&ctx) ;
#line 442 "src/codegen.z"
_ZN4main7codegen12generate_modE(&ctx,ast.root_module) ;
}











#line 27 "src/main.z"
char*  basename(char*  path) ;

#line 28 "src/main.z"
char*  dirname(char*  path) ;

#line 30 "src/main.z"
i32 main(i32 argc, char* *  argv) {
#line 31 "src/main.z"
if ((argc!= 3)){
#line 32 "src/main.z"
printf("Usage: compiler INPUT OUTPUT\n") ;
#line 33 "src/main.z"
abort() ;
}
;
#line 36 "src/main.z"
_ZN4main7session7SessionE sess ;
;
#line 39 "src/main.z"
sess.interner = _ZN4main9interning15interner_createE() ;
;
#line 40 "src/main.z"
sess.source = _ZN4main10source_map17source_map_createE() ;
;
#line 41 "src/main.z"
char*  root_filename = basename(argv[1]) ;
;
#line 42 "src/main.z"
sess.root_path = dirname(argv[1]) ;
;
#line 44 "src/main.z"
strtok(root_filename,".z") ;
#line 45 "src/main.z"
_ZN4main3ast3AstE ast = _ZN4main6parser5parseE(&sess,root_filename) ;
;
#line 47 "src/main.z"
_ZN4main10resolution7resolveE(&sess,&ast) ;
#line 48 "src/main.z"
_ZN4main9typecheck5checkE(&sess,&ast) ;
#line 49 "src/main.z"
_ZN4main7codegen8generateE(&sess,ast,argv[2]) ;
#line 51 "src/main.z"
return 0;
;
}


