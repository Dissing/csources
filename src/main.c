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
typedef const char constchar;
typedef const void constvoid;
#define null 0ul
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

#line 11 "src/cstd.z"
f64 atof(constchar*  str) ;

#line 12 "src/cstd.z"
i64 atol(constchar*  str) ;

#line 14 "src/cstd.z"
void  abort() ;

#line 15 "src/cstd.z"
void  exit(i32 status) ;

#line 17 "src/cstd.z"
FILE*  fopen(constchar*  filename, constchar*  mode) ;

#line 18 "src/cstd.z"
i32 fclose(FILE*  stream) ;

#line 19 "src/cstd.z"
i32 fseek(FILE*  stream, i64 offset, i32 origin) ;

#line 20 "src/cstd.z"
void  rewind(FILE*  stream) ;

#line 21 "src/cstd.z"
i64 ftell(FILE*  stream) ;

#line 23 "src/cstd.z"
i32 printf(constchar*  format, ...) ;

#line 24 "src/cstd.z"
i32 fprintf(FILE*  stream, constchar*  format, ...) ;

#line 25 "src/cstd.z"
i32 sprintf(char*  buffer, constchar*  format, ...) ;


typedef struct IntMap IntMap;
#line 2 "src/intmap.z"
typedef struct IntMap {
u64*  keys;
u64*  values;
u64 size;
u64 load;
} IntMap;


#line 9 "src/intmap.z"
IntMap*  intmap_create(u64 size) {
#line 10 "src/intmap.z"
#line 10 "src/intmap.z"
IntMap*  map = malloc(sizeof(IntMap) ) ;

#line 12 "src/intmap.z"
map->size = size;
#line 13 "src/intmap.z"
map->load = 0;
#line 14 "src/intmap.z"
map->keys = malloc((size* 8)) ;
#line 15 "src/intmap.z"
map->values = malloc((size* 8)) ;
#line 17 "src/intmap.z"
#line 17 "src/intmap.z"
u32 i = 0;

#line 18 "src/intmap.z"
while ( (i< size))
{
#line 19 "src/intmap.z"
map->keys[i] = 0;
#line 20 "src/intmap.z"
map->values[i] = null;
#line 21 "src/intmap.z"
i = (i+ 1);
}
;
#line 24 "src/intmap.z"
return map;
}

#line 27 "src/intmap.z"
u64 intmap_hash(u64 k) {
#line 28 "src/intmap.z"
if ((k!= null)){
#line 28 "src/intmap.z"
return k;
}
else {
#line 29 "src/intmap.z"
return 1;
}
;
}

#line 32 "src/intmap.z"
void  intmap_reset(IntMap*  map) {
#line 33 "src/intmap.z"
map->load = 0;
#line 34 "src/intmap.z"
memset(map->keys,0,(sizeof(map->size) * 8)) ;
#line 35 "src/intmap.z"
memset(map->values,0,(sizeof(map->size) * 8)) ;
}

#line 38 "src/intmap.z"
void  intmap_insert(IntMap*  map, u64 key, u64 value) {
#line 39 "src/intmap.z"
#line 39 "src/intmap.z"
u64 h = (intmap_hash(key) % map->size);

#line 40 "src/intmap.z"
if (((map->load+ 1)>= map->size)){
#line 41 "src/intmap.z"
printf("Hashmap of size %lu is full!\n",map->size) ;
#line 42 "src/intmap.z"
exit(-1) ;
}
;
#line 44 "src/intmap.z"
while ( true)
{
#line 45 "src/intmap.z"
if ((map->keys[h]== key)){
#line 46 "src/intmap.z"
map->values[h] = value;
#line 47 "src/intmap.z"
break;
}
else {
#line 48 "src/intmap.z"
if ((map->keys[h]== null)){
#line 49 "src/intmap.z"
map->keys[h] = key;
#line 50 "src/intmap.z"
map->values[h] = value;
#line 51 "src/intmap.z"
map->load = (map->load+ 1);
#line 52 "src/intmap.z"
break;
}
else {
#line 54 "src/intmap.z"
h = ((h+ 1)% map->size);
}
;
}
;
}
;
}

#line 59 "src/intmap.z"
u64 intmap_lookup(IntMap*  map, u64 key) {
#line 60 "src/intmap.z"
#line 60 "src/intmap.z"
u64 h = (intmap_hash(key) % map->size);

#line 61 "src/intmap.z"
while ( true)
{
#line 62 "src/intmap.z"
if ((map->keys[h]== null)){
#line 62 "src/intmap.z"
return null;
}
;
#line 63 "src/intmap.z"
if ((map->keys[h]== key)){
#line 64 "src/intmap.z"
return map->values[h];
}
;
#line 66 "src/intmap.z"
h = ((h+ 1)% map->size);
}
;
}

#line 70 "src/intmap.z"
void  intmap_destroy(IntMap*  map) {
#line 71 "src/intmap.z"
free(map->keys) ;
#line 72 "src/intmap.z"
free(map->values) ;
#line 73 "src/intmap.z"
free(map) ;
}


typedef struct StrMap StrMap;
#line 2 "src/strmap.z"
typedef struct StrMap {
char* *  keys;
u32*  values;
u64 size;
u64 load;
} StrMap;


#line 9 "src/strmap.z"
StrMap*  strmap_create(u64 size) {
#line 10 "src/strmap.z"
#line 10 "src/strmap.z"
StrMap*  map = malloc(sizeof(StrMap) ) ;

#line 12 "src/strmap.z"
map->size = size;
#line 13 "src/strmap.z"
map->load = 0;
#line 14 "src/strmap.z"
map->keys = malloc((size* 8)) ;
#line 15 "src/strmap.z"
map->values = malloc((size* 4)) ;
#line 17 "src/strmap.z"
#line 17 "src/strmap.z"
u32 i = 0;

#line 18 "src/strmap.z"
while ( (i< size))
{
#line 19 "src/strmap.z"
map->keys[i] = 0;
#line 20 "src/strmap.z"
map->values[i] = null;
#line 21 "src/strmap.z"
i = (i+ 1);
}
;
#line 24 "src/strmap.z"
return map;
}

#line 27 "src/strmap.z"
u32 strmap_hash(char*  s) {
#line 28 "src/strmap.z"
#line 28 "src/strmap.z"
u32 hash = 5381;

#line 29 "src/strmap.z"
#line 29 "src/strmap.z"
i32 c = *s;

#line 30 "src/strmap.z"
while ( (c!= 0))
{
#line 31 "src/strmap.z"
hash = (((hash<< 5)+ hash)+ c);
#line 32 "src/strmap.z"
s = (s+ 1);
#line 33 "src/strmap.z"
c = *s;
}
;
#line 35 "src/strmap.z"
if ((hash!= null)){
#line 35 "src/strmap.z"
return hash;
}
else {
#line 36 "src/strmap.z"
return 1;
}
;
}

#line 39 "src/strmap.z"
void  strmap_insert(StrMap*  map, char*  key, u32 value) {
#line 40 "src/strmap.z"
#line 40 "src/strmap.z"
u32 h = (strmap_hash(key) % map->size);

#line 41 "src/strmap.z"
if (((map->load+ 1)>= map->size)){
#line 42 "src/strmap.z"
printf("Hashmap of size %lu is full!\n",map->size) ;
#line 43 "src/strmap.z"
exit(-1) ;
}
;
#line 45 "src/strmap.z"
while ( true)
{
#line 46 "src/strmap.z"
if (((map->keys[h]!= null)&& !strcmp(map->keys[h],key) )){
#line 47 "src/strmap.z"
map->values[h] = value;
#line 48 "src/strmap.z"
break;
}
else {
#line 49 "src/strmap.z"
if ((map->keys[h]== null)){
#line 50 "src/strmap.z"
map->keys[h] = key;
#line 51 "src/strmap.z"
map->values[h] = value;
#line 52 "src/strmap.z"
map->load = (map->load+ 1);
#line 53 "src/strmap.z"
break;
}
else {
#line 55 "src/strmap.z"
h = ((h+ 1)% map->size);
}
;
}
;
}
;
}

#line 60 "src/strmap.z"
u32 strmap_lookup(StrMap*  map, char*  key) {
#line 61 "src/strmap.z"
#line 61 "src/strmap.z"
u32 h = (strmap_hash(key) % map->size);

#line 62 "src/strmap.z"
while ( true)
{
#line 63 "src/strmap.z"
if ((map->keys[h]== null)){
#line 63 "src/strmap.z"
return null;
}
;
#line 64 "src/strmap.z"
if (!strcmp(map->keys[h],key) ){
#line 65 "src/strmap.z"
return map->values[h];
}
;
#line 67 "src/strmap.z"
h = ((h+ 1)% map->size);
}
;
}

#line 71 "src/strmap.z"
void  strmap_destroy(StrMap*  map) {
#line 72 "src/strmap.z"
free(map->keys) ;
#line 73 "src/strmap.z"
free(map->values) ;
#line 74 "src/strmap.z"
free(map) ;
}


typedef struct Span Span;
#line 1 "src/source_map.z"
typedef struct Span {
u32 from;
u32 to;
} Span;


typedef struct SourceFile SourceFile;
#line 6 "src/source_map.z"
typedef struct SourceFile {
char*  name;
char*  content;
u32 length;
u32 start;
u32 end;
u32*  lines;
u32 num_lines;
} SourceFile;


typedef struct SourceMap SourceMap;
#line 16 "src/source_map.z"
typedef struct SourceMap {
SourceFile*  files;
u32 num_files;
u32*  file_starts;
} SourceMap;


#line 22 "src/source_map.z"
SourceMap source_map_create() {
#line 23 "src/source_map.z"
#line 23 "src/source_map.z"
SourceMap map ;

#line 24 "src/source_map.z"
map.files = calloc(sizeof(SourceFile) ,16) ;
#line 25 "src/source_map.z"
map.num_files = 0;
#line 26 "src/source_map.z"
map.file_starts = calloc(sizeof(u32) ,16) ;
#line 28 "src/source_map.z"
return map;
}

#line 31 "src/source_map.z"
void  load_file_content(SourceFile*  file) {
#line 32 "src/source_map.z"
#line 32 "src/source_map.z"
FILE*  fp = fopen(file->name,"rb") ;

#line 33 "src/source_map.z"
fseek(fp,0,SEEK_END) ;
#line 34 "src/source_map.z"
file->length = ftell(fp) ;
#line 35 "src/source_map.z"
rewind(fp) ;
#line 36 "src/source_map.z"
file->content = malloc(file->length) ;
#line 37 "src/source_map.z"
fread(file->content,1,file->length,fp) ;
#line 38 "src/source_map.z"
fclose(fp) ;
}

#line 41 "src/source_map.z"
SourceFile*  source_map_new_file(SourceMap*  self, char*  path, char*  filename) {
#line 42 "src/source_map.z"
#line 42 "src/source_map.z"
SourceFile*  file = &self->files[self->num_files];

#line 43 "src/source_map.z"
self->num_files = (self->num_files+ 1);
#line 45 "src/source_map.z"
#line 45 "src/source_map.z"
u32 needed_length = ((strlen(path) + strlen(filename) )+ 4);

#line 47 "src/source_map.z"
#line 47 "src/source_map.z"
char*  name_buffer = malloc(needed_length) ;

#line 49 "src/source_map.z"
#line 49 "src/source_map.z"
char*  dot_found = strtok(filename,".z") ;

#line 50 "src/source_map.z"
if ((dot_found!= null)){
#line 50 "src/source_map.z"
sprintf(name_buffer,"%s/%s.z",path,filename) ;
}
else {
#line 51 "src/source_map.z"
sprintf(name_buffer,"%s/%s",path,filename) ;
}
;
#line 53 "src/source_map.z"
file->name = name_buffer;
#line 54 "src/source_map.z"
file->lines = calloc(sizeof(u32) ,4096) ;
#line 55 "src/source_map.z"
file->num_lines = 1;
#line 57 "src/source_map.z"
if ((self->num_files> 1)){
#line 57 "src/source_map.z"
file->start = self->files[(self->num_files- 2)].end;
}
else {
#line 58 "src/source_map.z"
file->start = 0;
}
;
#line 60 "src/source_map.z"
self->file_starts[(self->num_files- 1)] = file->start;
#line 62 "src/source_map.z"
load_file_content(file) ;
#line 64 "src/source_map.z"
return file;
}

#line 67 "src/source_map.z"
void  source_file_newline(SourceFile*  self, u32 position) {
#line 68 "src/source_map.z"
self->lines[self->num_lines] = (self->start+ position);
#line 69 "src/source_map.z"
self->num_lines = (self->num_lines+ 1);
}

#line 72 "src/source_map.z"
void  source_file_done(SourceFile*  self, u32 length) {
#line 73 "src/source_map.z"
self->end = (self->start+ length);
}

#line 76 "src/source_map.z"
SourceFile*  source_map_info(SourceMap*  m, Span span, u32*  first, u32*  last) {
#line 77 "src/source_map.z"
#line 77 "src/source_map.z"
u32 i = 0;

#line 78 "src/source_map.z"
#line 78 "src/source_map.z"
SourceFile*  file = 0;

#line 79 "src/source_map.z"
while ( (i< m->num_files))
{
#line 80 "src/source_map.z"
if ((m->file_starts[i]> span.from)){
#line 80 "src/source_map.z"
break;
}
;
#line 81 "src/source_map.z"
file = &m->files[i];
#line 82 "src/source_map.z"
i = (i+ 1);
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
#line 88 "src/source_map.z"
while ( (i< file->num_lines))
{
#line 89 "src/source_map.z"
if ((file->lines[i]<= span.from)){
#line 90 "src/source_map.z"
*first = i;
}
else {
#line 92 "src/source_map.z"
break;
}
;
#line 93 "src/source_map.z"
i = (i+ 1);
}
;
#line 95 "src/source_map.z"
i = (i- 1);
#line 96 "src/source_map.z"
while ( (i< file->num_lines))
{
#line 97 "src/source_map.z"
if ((file->lines[i]<= span.to)){
#line 98 "src/source_map.z"
*last = i;
}
else {
#line 100 "src/source_map.z"
break;
}
;
#line 101 "src/source_map.z"
i = (i+ 1);
}
;
#line 104 "src/source_map.z"
return file;
}

#line 107 "src/source_map.z"
void  emit_line_directive(FILE*  fp, SourceMap*  m, Span span) {
#line 108 "src/source_map.z"
#line 108 "src/source_map.z"
u32 line_first ;

#line 109 "src/source_map.z"
#line 109 "src/source_map.z"
u32 line_end ;

#line 111 "src/source_map.z"
#line 111 "src/source_map.z"
SourceFile*  file = source_map_info(m,span,&line_first,&line_end) ;

#line 113 "src/source_map.z"
fprintf(fp,"#line %u \"%s\"\n",(line_first+ 1),file->name) ;
}

#line 116 "src/source_map.z"
void  source_snippet(SourceMap*  m, Span span) {
#line 118 "src/source_map.z"
#line 118 "src/source_map.z"
u32 line_first ;

#line 119 "src/source_map.z"
#line 119 "src/source_map.z"
u32 line_last ;

#line 121 "src/source_map.z"
#line 121 "src/source_map.z"
SourceFile*  file = source_map_info(m,span,&line_first,&line_last) ;

#line 123 "src/source_map.z"
printf("%s:%u\n",file->name,(line_first+ 1)) ;
#line 125 "src/source_map.z"
#line 125 "src/source_map.z"
char*  buffer = malloc(1024) ;

#line 126 "src/source_map.z"
#line 126 "src/source_map.z"
u32 i = line_first;

#line 127 "src/source_map.z"
while ( (i<= line_last))
{
#line 128 "src/source_map.z"
#line 128 "src/source_map.z"
u32 line_start = file->lines[i];

#line 129 "src/source_map.z"
#line 129 "src/source_map.z"
u32 line_end = file->lines[(i+ 1)];

#line 130 "src/source_map.z"
#line 130 "src/source_map.z"
u32 length = (line_end- line_start);

#line 132 "src/source_map.z"
memcpy(buffer,&file->content[line_start],length) ;
#line 133 "src/source_map.z"
buffer[(length+ 1)] = 0;
#line 134 "src/source_map.z"
printf("%s\n",buffer) ;
#line 135 "src/source_map.z"
i = (i+ 1);
}
;
}


#line 2 "src/error.z"
void  emit_error(SourceMap*  m, Span span, char*  msg) {
#line 3 "src/error.z"
printf("error: %s\n",msg) ;
#line 4 "src/error.z"
source_snippet(m,span) ;
#line 5 "src/error.z"
abort() ;
}


typedef struct Sid Sid;
#line 2 "src/interning.z"
typedef struct Sid {
u32 x;
} Sid;


typedef struct Interner Interner;
#line 6 "src/interning.z"
typedef struct Interner {
StrMap*  str_lookup;
char* *  sid_lookup;
u32 next_sid;
} Interner;


#line 12 "src/interning.z"
Interner interner_create() {
#line 13 "src/interning.z"
#line 13 "src/interning.z"
Interner interner ;

#line 14 "src/interning.z"
interner.str_lookup = strmap_create(2048) ;
#line 15 "src/interning.z"
interner.sid_lookup = calloc(8,2048) ;
#line 16 "src/interning.z"
interner.next_sid = 1;
#line 17 "src/interning.z"
return interner;
}

#line 21 "src/interning.z"
Sid intern(Interner*  self, char*  string) {
#line 22 "src/interning.z"
#line 22 "src/interning.z"
Sid sid ;

#line 23 "src/interning.z"
sid.x = strmap_lookup(self->str_lookup,string) ;
#line 24 "src/interning.z"
if ((sid.x== 0)){
#line 26 "src/interning.z"
sid.x = self->next_sid;
#line 27 "src/interning.z"
self->next_sid = (self->next_sid+ 1);
#line 29 "src/interning.z"
#line 29 "src/interning.z"
u64 len = (strlen(string) + 1);

#line 30 "src/interning.z"
#line 30 "src/interning.z"
char*  copy = malloc(len) ;

#line 31 "src/interning.z"
memcpy(copy,string,len) ;
#line 32 "src/interning.z"
self->sid_lookup[sid.x] = copy;
#line 34 "src/interning.z"
strmap_insert(self->str_lookup,copy,sid.x) ;
}
;
#line 36 "src/interning.z"
return sid;
}

#line 39 "src/interning.z"
char*  get_str(Interner*  self, Sid sid) {
#line 40 "src/interning.z"
return self->sid_lookup[sid.x];
}


typedef struct Session Session;
#line 3 "src/session.z"
typedef struct Session {
Interner interner;
SourceMap source;
char*  root_path;
} Session;



#line 3 "src/tokens.z"
typedef enum TokenKind {
TokenKind_Invalid,
TokenKind_Identifier,
TokenKind_EOF,
TokenKind_Break,
TokenKind_Const,
TokenKind_Continue,
TokenKind_Defer,
TokenKind_Enum,
TokenKind_Else,
TokenKind_Fn,
TokenKind_For,
TokenKind_If,
TokenKind_Mod,
TokenKind_Return,
TokenKind_Static,
TokenKind_Struct,
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
} TokenKind;


typedef struct Token Token;
#line 70 "src/tokens.z"
typedef struct Token {
TokenKind kind;
Span span;
Sid lexeme;
} Token;



typedef struct LexingContext LexingContext;
#line 1 "src/lexer.z"
typedef struct LexingContext {
u32 start;
u32 current;
u32 line;
u32 file_span_offset;
SourceFile*  source;
Token*  tokens;
u32 current_token_idx;
Session*  sess;
char*  lexeme_buffer;
} LexingContext;


#line 13 "src/lexer.z"
bool is_alphabetic(char c) {
#line 14 "src/lexer.z"
return (((c>= 'A')&& (c<= 'Z'))|| ((c>= 'a')&& (c<= 'z')));
}

#line 17 "src/lexer.z"
bool is_digit(char c) {
#line 18 "src/lexer.z"
return ((c>= '0')&& (c<= '9'));
}

#line 21 "src/lexer.z"
bool is_alphanumeric(char c) {
#line 22 "src/lexer.z"
return (is_alphabetic(c) || is_digit(c) );
}

#line 25 "src/lexer.z"
bool is_done_lexing(LexingContext*  ctx) {
#line 26 "src/lexer.z"
#line 26 "src/lexer.z"
SourceFile*  source = ctx->source;

#line 27 "src/lexer.z"
return (ctx->current>= source->length);
}

#line 30 "src/lexer.z"
char peek_token(LexingContext*  ctx, u32 offset) {
#line 31 "src/lexer.z"
if (is_done_lexing(ctx) ){
#line 31 "src/lexer.z"
return 0;
}
;
#line 32 "src/lexer.z"
#line 32 "src/lexer.z"
SourceFile*  source = ctx->source;

#line 33 "src/lexer.z"
return source->content[(ctx->current+ offset)];
}

#line 36 "src/lexer.z"
char advance(LexingContext*  ctx) {
#line 37 "src/lexer.z"
ctx->current = (ctx->current+ 1);
#line 38 "src/lexer.z"
#line 38 "src/lexer.z"
SourceFile*  source = ctx->source;

#line 39 "src/lexer.z"
return source->content[(ctx->current- 1)];
}

#line 42 "src/lexer.z"
void  add_token(LexingContext*  ctx, TokenKind kind, Sid lexeme) {
#line 43 "src/lexer.z"
#line 43 "src/lexer.z"
Token token ;

#line 44 "src/lexer.z"
token.kind = kind;
#line 45 "src/lexer.z"
token.lexeme = lexeme;
#line 46 "src/lexer.z"
token.span.from = (ctx->start+ ctx->file_span_offset);
#line 47 "src/lexer.z"
token.span.to = (ctx->current+ ctx->file_span_offset);
#line 48 "src/lexer.z"
ctx->tokens[ctx->current_token_idx] = token;
#line 49 "src/lexer.z"
ctx->current_token_idx = (ctx->current_token_idx+ 1);
}

#line 52 "src/lexer.z"
void  add_simple_token(LexingContext*  ctx, TokenKind kind) {
#line 53 "src/lexer.z"
#line 53 "src/lexer.z"
Sid null_sid ;

#line 54 "src/lexer.z"
null_sid.x = 0;
#line 55 "src/lexer.z"
add_token(ctx,kind,null_sid) ;
}

#line 58 "src/lexer.z"
void  add_lookahead_conditional_token(LexingContext*  ctx, char expect, TokenKind first, TokenKind second) {
#line 59 "src/lexer.z"
#line 59 "src/lexer.z"
TokenKind kind ;

#line 60 "src/lexer.z"
if ((peek_token(ctx,0) == expect)){
#line 61 "src/lexer.z"
advance(ctx) ;
#line 62 "src/lexer.z"
kind = first;
}
else {
#line 64 "src/lexer.z"
kind = second;
}
;
#line 66 "src/lexer.z"
#line 66 "src/lexer.z"
Sid null_sid ;

#line 67 "src/lexer.z"
null_sid.x = 0;
#line 68 "src/lexer.z"
add_token(ctx,kind,null_sid) ;
}

#line 71 "src/lexer.z"
void  read_newline(LexingContext*  ctx) {
#line 72 "src/lexer.z"
source_file_newline(ctx->source,ctx->start) ;
}

#line 75 "src/lexer.z"
Sid get_lexeme(LexingContext*  ctx, u32 start_offset, u32 end_offset) {
#line 76 "src/lexer.z"
#line 76 "src/lexer.z"
u32 str_len = (ctx->current- ((ctx->start+ start_offset)+ end_offset));

#line 77 "src/lexer.z"
#line 77 "src/lexer.z"
SourceFile*  source = ctx->source;

#line 78 "src/lexer.z"
memcpy(ctx->lexeme_buffer,&source->content[(ctx->start+ start_offset)],str_len) ;
#line 79 "src/lexer.z"
ctx->lexeme_buffer[str_len] = 0;
#line 80 "src/lexer.z"
#line 80 "src/lexer.z"
Session*  sess = ctx->sess;

#line 81 "src/lexer.z"
#line 81 "src/lexer.z"
Sid sid = intern(&sess->interner,ctx->lexeme_buffer) ;

#line 83 "src/lexer.z"
return sid;
}

#line 86 "src/lexer.z"
void  single_line_comment(LexingContext*  ctx) {
#line 87 "src/lexer.z"
while ( ((peek_token(ctx,0) != '\n')&& !is_done_lexing(ctx) ))
{
#line 87 "src/lexer.z"
advance(ctx) ;
}
;
}

#line 90 "src/lexer.z"
TokenKind is_keyword(char*  s) {
#line 93 "src/lexer.z"
if (!strcmp(s,"break") ){
#line 93 "src/lexer.z"
return TokenKind_Break;
}
;
#line 94 "src/lexer.z"
if (!strcmp(s,"continue") ){
#line 94 "src/lexer.z"
return TokenKind_Continue;
}
;
#line 95 "src/lexer.z"
if (!strcmp(s,"const") ){
#line 95 "src/lexer.z"
return TokenKind_Continue;
}
;
#line 96 "src/lexer.z"
if (!strcmp(s,"defer") ){
#line 96 "src/lexer.z"
return TokenKind_Defer;
}
;
#line 97 "src/lexer.z"
if (!strcmp(s,"enum") ){
#line 97 "src/lexer.z"
return TokenKind_Enum;
}
;
#line 98 "src/lexer.z"
if (!strcmp(s,"else") ){
#line 98 "src/lexer.z"
return TokenKind_Else;
}
;
#line 99 "src/lexer.z"
if (!strcmp(s,"false") ){
#line 99 "src/lexer.z"
return TokenKind_False;
}
;
#line 100 "src/lexer.z"
if (!strcmp(s,"fn") ){
#line 100 "src/lexer.z"
return TokenKind_Fn;
}
;
#line 101 "src/lexer.z"
if (!strcmp(s,"for") ){
#line 101 "src/lexer.z"
return TokenKind_For;
}
;
#line 102 "src/lexer.z"
if (!strcmp(s,"if") ){
#line 102 "src/lexer.z"
return TokenKind_If;
}
;
#line 103 "src/lexer.z"
if (!strcmp(s,"mod") ){
#line 103 "src/lexer.z"
return TokenKind_Mod;
}
;
#line 104 "src/lexer.z"
if (!strcmp(s,"return") ){
#line 104 "src/lexer.z"
return TokenKind_Return;
}
;
#line 105 "src/lexer.z"
if (!strcmp(s,"struct") ){
#line 105 "src/lexer.z"
return TokenKind_Struct;
}
;
#line 106 "src/lexer.z"
if (!strcmp(s,"true") ){
#line 106 "src/lexer.z"
return TokenKind_True;
}
;
#line 107 "src/lexer.z"
if (!strcmp(s,"union") ){
#line 107 "src/lexer.z"
return TokenKind_Union;
}
;
#line 108 "src/lexer.z"
if (!strcmp(s,"use") ){
#line 108 "src/lexer.z"
return TokenKind_Use;
}
;
#line 109 "src/lexer.z"
if (!strcmp(s,"var") ){
#line 109 "src/lexer.z"
return TokenKind_Var;
}
;
#line 110 "src/lexer.z"
if (!strcmp(s,"val") ){
#line 110 "src/lexer.z"
return TokenKind_Val;
}
;
#line 111 "src/lexer.z"
if (!strcmp(s,"while") ){
#line 111 "src/lexer.z"
return TokenKind_While;
}
;
#line 112 "src/lexer.z"
return TokenKind_Invalid;
}

#line 115 "src/lexer.z"
void  lex_char(LexingContext*  ctx) {
#line 117 "src/lexer.z"
#line 117 "src/lexer.z"
SourceFile*  source = ctx->source;

#line 118 "src/lexer.z"
#line 118 "src/lexer.z"
u32 start_line = (source->num_lines+ 1);

#line 120 "src/lexer.z"
while ( (((peek_token(ctx,0) != '\'')|| ((peek_token(ctx,-1) == '\\')&& (peek_token(ctx,-2) != '\\')))&& !is_done_lexing(ctx) ))
{
#line 121 "src/lexer.z"
#line 121 "src/lexer.z"
char c = advance(ctx) ;

#line 122 "src/lexer.z"
if ((c== '\n')){
#line 122 "src/lexer.z"
read_newline(ctx) ;
}
;
}
;
#line 125 "src/lexer.z"
if (is_done_lexing(ctx) ){
#line 126 "src/lexer.z"
printf("Unterminated char starting on line %u\n",start_line) ;
#line 127 "src/lexer.z"
abort() ;
}
;
#line 131 "src/lexer.z"
advance(ctx) ;
#line 133 "src/lexer.z"
add_token(ctx,TokenKind_Char,get_lexeme(ctx,1,1) ) ;
}

#line 136 "src/lexer.z"
void  lex_string(LexingContext*  ctx) {
#line 138 "src/lexer.z"
#line 138 "src/lexer.z"
SourceFile*  source = ctx->source;

#line 140 "src/lexer.z"
#line 140 "src/lexer.z"
u32 start_line = (source->num_lines+ 1);

#line 142 "src/lexer.z"
while ( (((peek_token(ctx,0) != '"')|| ((peek_token(ctx,-1) == '\\')&& (peek_token(ctx,-2) != '\\')))&& !is_done_lexing(ctx) ))
{
#line 143 "src/lexer.z"
#line 143 "src/lexer.z"
char c = advance(ctx) ;

#line 144 "src/lexer.z"
if ((c== '\n')){
#line 144 "src/lexer.z"
read_newline(ctx) ;
}
;
}
;
#line 147 "src/lexer.z"
if (is_done_lexing(ctx) ){
#line 148 "src/lexer.z"
printf("Unterminated string starting on line %u\n",start_line) ;
#line 149 "src/lexer.z"
abort() ;
}
;
#line 153 "src/lexer.z"
advance(ctx) ;
#line 155 "src/lexer.z"
add_token(ctx,TokenKind_String,get_lexeme(ctx,1,1) ) ;
}

#line 158 "src/lexer.z"
void  lex_number(LexingContext*  ctx) {
#line 160 "src/lexer.z"
while ( is_digit(peek_token(ctx,0) ) )
{
#line 160 "src/lexer.z"
advance(ctx) ;
}
;
#line 161 "src/lexer.z"
#line 161 "src/lexer.z"
bool dot_encountered = false;

#line 162 "src/lexer.z"
if (((peek_token(ctx,0) == '.')&& is_digit(peek_token(ctx,1) ) )){
#line 163 "src/lexer.z"
dot_encountered = true;
#line 164 "src/lexer.z"
advance(ctx) ;
#line 165 "src/lexer.z"
while ( is_digit(peek_token(ctx,0) ) )
{
#line 165 "src/lexer.z"
advance(ctx) ;
}
;
}
;
#line 168 "src/lexer.z"
#line 168 "src/lexer.z"
TokenKind t ;

#line 169 "src/lexer.z"
if (dot_encountered){
#line 169 "src/lexer.z"
t = TokenKind_Float;
}
else {
#line 170 "src/lexer.z"
t = TokenKind_Integer;
}
;
#line 172 "src/lexer.z"
add_token(ctx,t,get_lexeme(ctx,0,0) ) ;
}

#line 175 "src/lexer.z"
void  lex_identifier(LexingContext*  ctx) {
#line 176 "src/lexer.z"
while ( (is_alphanumeric(peek_token(ctx,0) ) || (peek_token(ctx,0) == '_')))
{
#line 176 "src/lexer.z"
advance(ctx) ;
}
;
#line 178 "src/lexer.z"
#line 178 "src/lexer.z"
Sid lexeme = get_lexeme(ctx,0,0) ;

#line 180 "src/lexer.z"
#line 180 "src/lexer.z"
Session*  sess = ctx->sess;

#line 181 "src/lexer.z"
#line 181 "src/lexer.z"
char*  lexeme_str = get_str(&sess->interner,lexeme) ;

#line 182 "src/lexer.z"
#line 182 "src/lexer.z"
TokenKind keyword = is_keyword(lexeme_str) ;

#line 183 "src/lexer.z"
if ((keyword!= TokenKind_Invalid)){
#line 183 "src/lexer.z"
add_simple_token(ctx,keyword) ;
}
else {
#line 184 "src/lexer.z"
add_token(ctx,TokenKind_Identifier,lexeme) ;
}
;
}

#line 187 "src/lexer.z"
void  scan_token(LexingContext*  ctx) {
#line 188 "src/lexer.z"
#line 188 "src/lexer.z"
char c = advance(ctx) ;

#line 192 "src/lexer.z"
if ((c== '(')){
#line 192 "src/lexer.z"
add_simple_token(ctx,TokenKind_LeftParen) ;
}
else {
#line 193 "src/lexer.z"
if ((c== ')')){
#line 193 "src/lexer.z"
add_simple_token(ctx,TokenKind_RightParen) ;
}
else {
#line 194 "src/lexer.z"
if ((c== '[')){
#line 194 "src/lexer.z"
add_simple_token(ctx,TokenKind_LeftBracket) ;
}
else {
#line 195 "src/lexer.z"
if ((c== ']')){
#line 195 "src/lexer.z"
add_simple_token(ctx,TokenKind_RightBracket) ;
}
else {
#line 196 "src/lexer.z"
if ((c== '{')){
#line 196 "src/lexer.z"
add_simple_token(ctx,TokenKind_LeftCurly) ;
}
else {
#line 197 "src/lexer.z"
if ((c== '}')){
#line 197 "src/lexer.z"
add_simple_token(ctx,TokenKind_RightCurly) ;
}
else {
#line 198 "src/lexer.z"
if ((c== '+')){
#line 198 "src/lexer.z"
add_simple_token(ctx,TokenKind_Plus) ;
}
else {
#line 199 "src/lexer.z"
if ((c== '*')){
#line 199 "src/lexer.z"
add_simple_token(ctx,TokenKind_Star) ;
}
else {
#line 200 "src/lexer.z"
if ((c== '%')){
#line 200 "src/lexer.z"
add_simple_token(ctx,TokenKind_Percent) ;
}
else {
#line 201 "src/lexer.z"
if ((c== '^')){
#line 201 "src/lexer.z"
add_simple_token(ctx,TokenKind_Hat) ;
}
else {
#line 202 "src/lexer.z"
if ((c== ';')){
#line 202 "src/lexer.z"
add_simple_token(ctx,TokenKind_Semicolon) ;
}
else {
#line 203 "src/lexer.z"
if ((c== ',')){
#line 203 "src/lexer.z"
add_simple_token(ctx,TokenKind_Comma) ;
}
else {
#line 204 "src/lexer.z"
if ((c== '-')){
#line 204 "src/lexer.z"
add_lookahead_conditional_token(ctx,'>',TokenKind_Arrow,TokenKind_Minus) ;
}
else {
#line 205 "src/lexer.z"
if ((c== ':')){
#line 205 "src/lexer.z"
add_lookahead_conditional_token(ctx,':',TokenKind_ColonColon,TokenKind_Colon) ;
}
else {
#line 206 "src/lexer.z"
if ((c== '=')){
#line 206 "src/lexer.z"
add_lookahead_conditional_token(ctx,'=',TokenKind_EqualEqual,TokenKind_Equal) ;
}
else {
#line 207 "src/lexer.z"
if ((c== '!')){
#line 207 "src/lexer.z"
add_lookahead_conditional_token(ctx,'=',TokenKind_BangEqual,TokenKind_Bang) ;
}
else {
#line 208 "src/lexer.z"
if ((c== '&')){
#line 208 "src/lexer.z"
add_lookahead_conditional_token(ctx,'&',TokenKind_AndAnd,TokenKind_And) ;
}
else {
#line 209 "src/lexer.z"
if ((c== '|')){
#line 209 "src/lexer.z"
add_lookahead_conditional_token(ctx,'|',TokenKind_OrOr,TokenKind_Or) ;
}
else {
#line 210 "src/lexer.z"
if ((c== '.')){
#line 211 "src/lexer.z"
if (((peek_token(ctx,0) == '.')&& (peek_token(ctx,1) == '.'))){
#line 212 "src/lexer.z"
advance(ctx) ;
#line 212 "src/lexer.z"
advance(ctx) ;
#line 213 "src/lexer.z"
add_simple_token(ctx,TokenKind_Ellipsis) ;
}
else {
#line 215 "src/lexer.z"
add_simple_token(ctx,TokenKind_Dot) ;
}
;
}
else {
#line 217 "src/lexer.z"
if ((c== '<')){
#line 218 "src/lexer.z"
#line 218 "src/lexer.z"
char n1 = peek_token(ctx,0) ;

#line 219 "src/lexer.z"
if ((n1== '<')){
#line 219 "src/lexer.z"
advance(ctx) ;
#line 219 "src/lexer.z"
add_simple_token(ctx,TokenKind_LessLess) ;
}
else {
#line 220 "src/lexer.z"
if ((n1== '=')){
#line 220 "src/lexer.z"
advance(ctx) ;
#line 220 "src/lexer.z"
add_simple_token(ctx,TokenKind_LessEqual) ;
}
else {
#line 221 "src/lexer.z"
add_simple_token(ctx,TokenKind_Less) ;
}
;
}
;
}
else {
#line 223 "src/lexer.z"
if ((c== '>')){
#line 224 "src/lexer.z"
#line 224 "src/lexer.z"
char n2 = peek_token(ctx,0) ;

#line 225 "src/lexer.z"
if ((n2== '>')){
#line 225 "src/lexer.z"
advance(ctx) ;
#line 225 "src/lexer.z"
add_simple_token(ctx,TokenKind_GreaterGreater) ;
}
else {
#line 226 "src/lexer.z"
if ((n2== '=')){
#line 226 "src/lexer.z"
advance(ctx) ;
#line 226 "src/lexer.z"
add_simple_token(ctx,TokenKind_GreaterEqual) ;
}
else {
#line 227 "src/lexer.z"
add_simple_token(ctx,TokenKind_Greater) ;
}
;
}
;
}
else {
#line 229 "src/lexer.z"
if ((c== '/')){
#line 230 "src/lexer.z"
if ((peek_token(ctx,0) == '/')){
#line 230 "src/lexer.z"
single_line_comment(ctx) ;
}
else {
#line 231 "src/lexer.z"
add_simple_token(ctx,TokenKind_Slash) ;
}
;
}
else {
#line 233 "src/lexer.z"
if ((((c== ' ')|| (c== '\t'))|| (c== '\r'))){
}
else {
#line 234 "src/lexer.z"
if ((c== '\n')){
#line 234 "src/lexer.z"
read_newline(ctx) ;
}
else {
#line 235 "src/lexer.z"
if ((c== '"')){
#line 235 "src/lexer.z"
lex_string(ctx) ;
}
else {
#line 236 "src/lexer.z"
if ((c== '\'')){
#line 236 "src/lexer.z"
lex_char(ctx) ;
}
else {
#line 238 "src/lexer.z"
if (is_digit(c) ){
#line 238 "src/lexer.z"
lex_number(ctx) ;
}
else {
#line 239 "src/lexer.z"
if ((is_alphabetic(c) || (c== '_'))){
#line 239 "src/lexer.z"
lex_identifier(ctx) ;
}
else {
#line 241 "src/lexer.z"
#line 241 "src/lexer.z"
SourceFile*  source = ctx->source;

#line 242 "src/lexer.z"
printf("Unexpected character %c = %d on line %u\n",c,c,source->num_lines) ;
#line 243 "src/lexer.z"
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

#line 248 "src/lexer.z"
void  lex(Session*  sess, SourceFile*  source, Token* *  tokens, u32*  num_tokens) {
#line 250 "src/lexer.z"
#line 250 "src/lexer.z"
LexingContext*  ctx = malloc(sizeof(LexingContext) ) ;

#line 251 "src/lexer.z"
ctx->source = source;
#line 252 "src/lexer.z"
ctx->file_span_offset = source->start;
#line 253 "src/lexer.z"
ctx->start = 0;
#line 254 "src/lexer.z"
ctx->current = 0;
#line 255 "src/lexer.z"
ctx->tokens = malloc((sizeof(Token) * 10000)) ;
#line 256 "src/lexer.z"
ctx->current_token_idx = 0;
#line 257 "src/lexer.z"
ctx->sess = sess;
#line 259 "src/lexer.z"
ctx->lexeme_buffer = malloc(1024) ;
#line 261 "src/lexer.z"
while ( !is_done_lexing(ctx) )
{
#line 262 "src/lexer.z"
ctx->start = ctx->current;
#line 263 "src/lexer.z"
scan_token(ctx) ;
}
;
#line 266 "src/lexer.z"
source_file_done(source,ctx->current) ;
#line 268 "src/lexer.z"
if ((ctx->current_token_idx> 10000)){
#line 269 "src/lexer.z"
printf("Lexer token overflow: %u!\n",ctx->current_token_idx) ;
#line 270 "src/lexer.z"
abort() ;
}
;
#line 273 "src/lexer.z"
*tokens = ctx->tokens;
#line 274 "src/lexer.z"
*num_tokens = ctx->current_token_idx;
}


typedef struct Type Type;
#line 2 "src/ast.z"

typedef struct Expr Expr;
#line 3 "src/ast.z"

typedef struct Block Block;
#line 4 "src/ast.z"

typedef struct NodeId NodeId;
#line 6 "src/ast.z"
typedef struct NodeId {
u32 owner;
u32 local;
} NodeId;


typedef struct Ident Ident;
#line 11 "src/ast.z"
typedef struct Ident {
Sid name;
} Ident;


#line 15 "src/ast.z"
typedef enum ResKind {
ResKind_Definition,
} ResKind;


typedef union ResNode ResNode;
#line 19 "src/ast.z"
typedef union ResNode {
NodeId def;
} ResNode;


typedef struct Res Res;
#line 23 "src/ast.z"
typedef struct Res {
ResKind kind;
ResNode node;
} Res;


typedef struct Path Path;
#line 28 "src/ast.z"
typedef struct Path {
Ident*  segments;
u32 num_segments;
Res res;
} Path;


typedef struct Mod Mod;
#line 34 "src/ast.z"
typedef struct Mod {
Span span;
NodeId*  items;
u32 num_items;
} Mod;


#line 40 "src/ast.z"
typedef enum TypeKind {
TypeKind_Unit,
TypeKind_Ptr,
TypeKind_Path,
TypeKind_Variadic,
} TypeKind;


typedef struct GenericParam GenericParam;
#line 47 "src/ast.z"
typedef struct GenericParam {
NodeId id;
Ident ident;
} GenericParam;


typedef struct Generics Generics;
#line 52 "src/ast.z"
typedef struct Generics {
GenericParam*  parameters;
u32 num_parameters;
Span span;
} Generics;


typedef union TypeKindNode TypeKindNode;
#line 58 "src/ast.z"
typedef union TypeKindNode {
Sid path;
Type*  ptr;
} TypeKindNode;


typedef struct Type Type;
#line 63 "src/ast.z"
typedef struct Type {
NodeId id;
TypeKind kind;
TypeKindNode node;
} Type;


#line 69 "src/ast.z"
typedef enum LiteralKind {
LiteralKind_Int,
LiteralKind_Float,
LiteralKind_Bool,
LiteralKind_Char,
LiteralKind_Str,
} LiteralKind;


typedef union LiteralValue LiteralValue;
#line 77 "src/ast.z"
typedef union LiteralValue {
f64 floating;
u64 integer;
bool boolean;
char ch;
Sid str;
} LiteralValue;


typedef struct Literal Literal;
#line 85 "src/ast.z"
typedef struct Literal {
LiteralKind kind;
LiteralValue value;
} Literal;


#line 91 "src/ast.z"
typedef enum UnaryOperatorKind {
UnaryOperatorKind_Deref,
UnaryOperatorKind_Refer,
UnaryOperatorKind_Negation,
UnaryOperatorKind_Complement,
} UnaryOperatorKind;


#line 102 "src/ast.z"
typedef enum BinaryOperatorKind {
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
} BinaryOperatorKind;


typedef struct BinaryData BinaryData;
#line 131 "src/ast.z"
typedef struct BinaryData {
BinaryOperatorKind op;
Expr*  left;
Expr*  right;
} BinaryData;


typedef struct CallData CallData;
#line 137 "src/ast.z"
typedef struct CallData {
Expr*  func;
Expr* *  args;
u32 num_args;
} CallData;


typedef struct ConditionalData ConditionalData;
#line 143 "src/ast.z"
typedef struct ConditionalData {
Expr*  condition;
Expr*  then;
Expr*  otherwise;
} ConditionalData;


typedef struct WhileData WhileData;
#line 149 "src/ast.z"
typedef struct WhileData {
Expr*  condition;
Expr*  body;
} WhileData;


typedef struct IndexingData IndexingData;
#line 154 "src/ast.z"
typedef struct IndexingData {
Expr*  array;
Expr*  index;
} IndexingData;


typedef struct FieldData FieldData;
#line 159 "src/ast.z"
typedef struct FieldData {
Expr*  strct;
Ident ident;
} FieldData;


typedef struct UnaryData UnaryData;
#line 164 "src/ast.z"
typedef struct UnaryData {
UnaryOperatorKind op;
Expr*  inner;
} UnaryData;


#line 169 "src/ast.z"
typedef enum ExprKind {
ExprKind_Binary,
ExprKind_Block,
ExprKind_Call,
ExprKind_Conditional,
ExprKind_Field,
ExprKind_Indexing,
ExprKind_Path,
ExprKind_Literal,
ExprKind_Unary,
ExprKind_While,
} ExprKind;


typedef union ExprKindNode ExprKindNode;
#line 182 "src/ast.z"
typedef union ExprKindNode {
BinaryData binary;
Block*  block;
CallData call;
ConditionalData conditional;
FieldData field;
IndexingData indexing;
Path path;
Literal lit;
UnaryData unary;
WhileData whl;
} ExprKindNode;


typedef struct Expr Expr;
#line 195 "src/ast.z"
typedef struct Expr {
NodeId id;
Span span;
ExprKind kind;
ExprKindNode node;
} Expr;


typedef struct AssignmentData AssignmentData;
#line 202 "src/ast.z"
typedef struct AssignmentData {
Expr*  left;
Expr*  right;
} AssignmentData;


#line 207 "src/ast.z"
typedef enum StmtKind {
StmtKind_Assignment,
StmtKind_Item,
StmtKind_Expr,
StmtKind_Return,
StmtKind_Break,
StmtKind_Continue,
StmtKind_Defer,
StmtKind_Empty,
} StmtKind;


typedef union StmtKindNode StmtKindNode;
#line 218 "src/ast.z"
typedef union StmtKindNode {
AssignmentData assignment;
NodeId item;
Expr*  expr;
Expr*  _return;
Expr*  _defer;
} StmtKindNode;


typedef struct Stmt Stmt;
#line 226 "src/ast.z"
typedef struct Stmt {
StmtKind kind;
StmtKindNode node;
Span span;
} Stmt;


typedef struct Block Block;
#line 232 "src/ast.z"
typedef struct Block {
Stmt* *  stmts;
u32 num_stmts;
NodeId id;
Span span;
} Block;


typedef struct Body Body;
#line 239 "src/ast.z"
typedef struct Body {
Expr*  value;
} Body;


#line 243 "src/ast.z"
typedef enum VisibilityKind {
VisibilityKind_Public,
VisibilityKind_Private,
} VisibilityKind;


typedef struct Visibility Visibility;
#line 248 "src/ast.z"
typedef struct Visibility {
VisibilityKind kind;
} Visibility;


typedef struct CompoundField CompoundField;
#line 252 "src/ast.z"
typedef struct CompoundField {
Ident ident;
NodeId id;
Type*  ty;
} CompoundField;


typedef struct CompoundData CompoundData;
#line 258 "src/ast.z"
typedef struct CompoundData {
CompoundField*  fields;
u32 num_fields;
Generics generics;
} CompoundData;


typedef struct EnumVariant EnumVariant;
#line 264 "src/ast.z"
typedef struct EnumVariant {
Ident ident;
NodeId id;
} EnumVariant;


typedef struct EnumData EnumData;
#line 269 "src/ast.z"
typedef struct EnumData {
EnumVariant*  variants;
u32 num_variants;
} EnumData;


typedef struct FunctionParameter FunctionParameter;
#line 274 "src/ast.z"
typedef struct FunctionParameter {
Ident ident;
NodeId id;
Type*  ty;
} FunctionParameter;


typedef struct FunctionHeader FunctionHeader;
#line 281 "src/ast.z"
typedef struct FunctionHeader {
FunctionParameter*  parameters;
u32 num_parameters;
Type*  output;
Generics generics;
} FunctionHeader;


typedef struct FunctionData FunctionData;
#line 288 "src/ast.z"
typedef struct FunctionData {
FunctionHeader header;
NodeId body;
} FunctionData;


typedef struct UseData UseData;
#line 293 "src/ast.z"
typedef struct UseData {
Path path;
} UseData;


typedef struct VariableData VariableData;
#line 297 "src/ast.z"
typedef struct VariableData {
Type*  ty;
bool mutable;
NodeId body;
} VariableData;


#line 303 "src/ast.z"
typedef enum ItemKind {
ItemKind_Const,
ItemKind_Enum,
ItemKind_Function,
ItemKind_Mod,
ItemKind_Struct,
ItemKind_Union,
ItemKind_Use,
ItemKind_Variable,
} ItemKind;


typedef union ItemKindNode ItemKindNode;
#line 314 "src/ast.z"
typedef union ItemKindNode {
CompoundData compound;
EnumData _enum;
VariableData variable;
FunctionData function;
Mod module;
UseData _use;
} ItemKindNode;


typedef struct Item Item;
#line 323 "src/ast.z"
typedef struct Item {
Ident ident;
NodeId id;
ItemKind kind;
ItemKindNode node;
Visibility vis;
Span span;
} Item;


typedef struct CompilationUnit CompilationUnit;
#line 332 "src/ast.z"
typedef struct CompilationUnit {
IntMap*  body_map;
Body*  bodies;
u32 num_bodies;
IntMap*  item_map;
Item*  items;
u32 num_items;
Mod module;
} CompilationUnit;


#line 344 "src/ast.z"
Body*  unit_create_body(CompilationUnit*  unit, NodeId owner_item, NodeId*  id) {
#line 346 "src/ast.z"
#line 346 "src/ast.z"
u32 idx = unit->num_bodies;

#line 347 "src/ast.z"
#line 347 "src/ast.z"
Body*  body = &unit->bodies[idx];

#line 348 "src/ast.z"
unit->num_bodies = (unit->num_bodies+ 1);
#line 350 "src/ast.z"
#line 350 "src/ast.z"
u64 owner = owner_item.owner;

#line 351 "src/ast.z"
#line 351 "src/ast.z"
u64 local = 1;

#line 352 "src/ast.z"
#line 352 "src/ast.z"
u64 key = ((owner<< 32)| local);

#line 353 "src/ast.z"
intmap_insert(unit->body_map,key,idx) ;
#line 355 "src/ast.z"
id->owner = owner;
#line 356 "src/ast.z"
id->local = local;
#line 358 "src/ast.z"
return body;
}

#line 361 "src/ast.z"
Body unit_get_body(CompilationUnit*  unit, NodeId id) {
#line 362 "src/ast.z"
#line 362 "src/ast.z"
u64 owner = id.owner;

#line 363 "src/ast.z"
#line 363 "src/ast.z"
u64 key = ((owner<< 32)| id.local);

#line 364 "src/ast.z"
#line 364 "src/ast.z"
u32 idx = intmap_lookup(unit->body_map,key) ;

#line 365 "src/ast.z"
return unit->bodies[idx];
}

#line 368 "src/ast.z"
Item*  unit_create_item(CompilationUnit*  unit, NodeId*  id) {
#line 370 "src/ast.z"
#line 370 "src/ast.z"
u32 idx = unit->num_items;

#line 371 "src/ast.z"
#line 371 "src/ast.z"
Item*  item = &unit->items[idx];

#line 372 "src/ast.z"
unit->num_items = (unit->num_items+ 1);
#line 374 "src/ast.z"
#line 374 "src/ast.z"
u64 owner = idx;

#line 375 "src/ast.z"
#line 375 "src/ast.z"
u64 local = 0;

#line 376 "src/ast.z"
#line 376 "src/ast.z"
u64 key = ((owner<< 32)| local);

#line 377 "src/ast.z"
intmap_insert(unit->item_map,key,idx) ;
#line 379 "src/ast.z"
id->owner = owner;
#line 380 "src/ast.z"
id->local = local;
#line 381 "src/ast.z"
item->id = *id;
#line 383 "src/ast.z"
return item;
}

#line 386 "src/ast.z"
Item*  unit_get_item(CompilationUnit*  unit, NodeId id) {
#line 387 "src/ast.z"
#line 387 "src/ast.z"
u64 owner = id.owner;

#line 388 "src/ast.z"
#line 388 "src/ast.z"
u64 key = ((owner<< 32)| id.local);

#line 389 "src/ast.z"
#line 389 "src/ast.z"
u32 idx = intmap_lookup(unit->item_map,key) ;

#line 390 "src/ast.z"
return &unit->items[idx];
}


typedef struct ParsingContext ParsingContext;
#line 1 "src/parser.z"
typedef struct ParsingContext {
u64 current_token;
Token*  tokens;
u64 num_tokens;
SourceMap*  source_map;
Session*  sess;
CompilationUnit*  unit;
u32 next_owner;
u32 current_owner;
} ParsingContext;


#line 12 "src/parser.z"
bool is_done_parsing(ParsingContext*  ctx) {
#line 13 "src/parser.z"
return (ctx->num_tokens== ctx->current_token);
}

#line 16 "src/parser.z"
bool accept(ParsingContext*  ctx, TokenKind token) {
#line 17 "src/parser.z"
#line 17 "src/parser.z"
Token tok = ctx->tokens[ctx->current_token];

#line 18 "src/parser.z"
if ((!is_done_parsing(ctx) && (tok.kind== token))){
#line 19 "src/parser.z"
ctx->current_token = (ctx->current_token+ 1);
#line 20 "src/parser.z"
return true;
}
;
#line 22 "src/parser.z"
return false;
}

#line 25 "src/parser.z"
bool can_accept(ParsingContext*  ctx, TokenKind token) {
#line 26 "src/parser.z"
#line 26 "src/parser.z"
Token tok = ctx->tokens[ctx->current_token];

#line 27 "src/parser.z"
if ((!is_done_parsing(ctx) && (tok.kind== token))){
#line 28 "src/parser.z"
return true;
}
;
#line 30 "src/parser.z"
return false;
}

#line 33 "src/parser.z"
Token look_ahead(ParsingContext*  ctx, u64 offset) {
#line 34 "src/parser.z"
if ((ctx->current_token== ctx->num_tokens)){
#line 35 "src/parser.z"
#line 35 "src/parser.z"
Token eof_tok ;

#line 36 "src/parser.z"
eof_tok.kind = EOF;
#line 37 "src/parser.z"
return eof_tok;
}
else {
#line 38 "src/parser.z"
return ctx->tokens[(ctx->current_token+ offset)];
}
;
}

#line 41 "src/parser.z"
Token consume(ParsingContext*  ctx) {
#line 42 "src/parser.z"
ctx->current_token = (ctx->current_token+ 1);
#line 43 "src/parser.z"
return ctx->tokens[(ctx->current_token- 1)];
}

#line 46 "src/parser.z"
Token expect(ParsingContext*  ctx, TokenKind kind) {
#line 47 "src/parser.z"
#line 47 "src/parser.z"
Token tok = consume(ctx) ;

#line 48 "src/parser.z"
if ((tok.kind== kind)){
#line 49 "src/parser.z"
return tok;
}
else {
#line 51 "src/parser.z"
emit_error(ctx->source_map,tok.span,"Expect failed!") ;
#line 52 "src/parser.z"
abort() ;
}
;
}

#line 56 "src/parser.z"
u32 span_start(ParsingContext*  ctx) {
#line 57 "src/parser.z"
return ctx->tokens[ctx->current_token].span.from;
}

#line 60 "src/parser.z"
u32 span_end(ParsingContext*  ctx) {
#line 61 "src/parser.z"
return ctx->tokens[(ctx->current_token- 1)].span.to;
}

#line 64 "src/parser.z"
Ident parse_identifier(ParsingContext*  ctx) {
#line 66 "src/parser.z"
#line 66 "src/parser.z"
Token tok = consume(ctx) ;

#line 68 "src/parser.z"
if ((tok.kind!= TokenKind_Identifier)){
#line 68 "src/parser.z"
emit_error(ctx->source_map,tok.span,"Invalid identifier") ;
}
;
#line 70 "src/parser.z"
#line 70 "src/parser.z"
Ident ident ;

#line 71 "src/parser.z"
ident.name = tok.lexeme;
#line 72 "src/parser.z"
return ident;
}

#line 75 "src/parser.z"
Path parse_path(ParsingContext*  ctx) {
#line 76 "src/parser.z"
#line 76 "src/parser.z"
Path path ;

#line 77 "src/parser.z"
path.segments = malloc((8* 4)) ;
#line 78 "src/parser.z"
path.num_segments = 0;
#line 80 "src/parser.z"
while ( true)
{
#line 81 "src/parser.z"
path.segments[path.num_segments] = parse_identifier(ctx) ;
#line 82 "src/parser.z"
path.num_segments = (path.num_segments+ 1);
#line 83 "src/parser.z"
if (!accept(ctx,TokenKind_ColonColon) ){
#line 83 "src/parser.z"
break;
}
;
}
;
#line 85 "src/parser.z"
return path;
}

#line 88 "src/parser.z"
Expr*  parse_path_expr(ParsingContext*  ctx) {
#line 89 "src/parser.z"
#line 89 "src/parser.z"
Expr*  expr = malloc(sizeof(Expr) ) ;

#line 90 "src/parser.z"
expr->kind = ExprKind_Path;
#line 91 "src/parser.z"
expr->node.path = parse_path(ctx) ;
#line 92 "src/parser.z"
return expr;
}

#line 95 "src/parser.z"
Type*  parse_type(ParsingContext*  ctx) {
#line 96 "src/parser.z"
#line 96 "src/parser.z"
TypeKindNode node ;

#line 97 "src/parser.z"
#line 97 "src/parser.z"
TypeKind kind ;

#line 99 "src/parser.z"
#line 99 "src/parser.z"
Token token = consume(ctx) ;

#line 100 "src/parser.z"
if ((token.kind== TokenKind_Identifier)){
#line 101 "src/parser.z"
kind = TypeKind_Path;
#line 102 "src/parser.z"
node.path = token.lexeme;
}
else {
#line 103 "src/parser.z"
if ((token.kind== TokenKind_Star)){
#line 104 "src/parser.z"
kind = TypeKind_Ptr;
#line 105 "src/parser.z"
node.ptr = parse_type(ctx) ;
}
else {
#line 106 "src/parser.z"
if ((token.kind== TokenKind_Ellipsis)){
#line 107 "src/parser.z"
kind = TypeKind_Variadic;
}
else {
#line 109 "src/parser.z"
emit_error(ctx->source_map,token.span,"Expected type") ;
}
;
}
;
}
;
#line 111 "src/parser.z"
#line 111 "src/parser.z"
Type*  type = malloc(sizeof(Type) ) ;

#line 112 "src/parser.z"
type->kind = kind;
#line 113 "src/parser.z"
type->node = node;
#line 115 "src/parser.z"
return type;
}

#line 118 "src/parser.z"
BinaryOperatorKind convert_token_to_binary_operator(TokenKind tok) {
#line 119 "src/parser.z"
if ((tok== TokenKind_Plus)){
#line 119 "src/parser.z"
return BinaryOperatorKind_Addition;
}
else {
#line 120 "src/parser.z"
if ((tok== TokenKind_Minus)){
#line 120 "src/parser.z"
return BinaryOperatorKind_Subtraction;
}
else {
#line 121 "src/parser.z"
if ((tok== TokenKind_Star)){
#line 121 "src/parser.z"
return BinaryOperatorKind_Product;
}
else {
#line 122 "src/parser.z"
if ((tok== TokenKind_Slash)){
#line 122 "src/parser.z"
return BinaryOperatorKind_Division;
}
else {
#line 123 "src/parser.z"
if ((tok== TokenKind_Percent)){
#line 123 "src/parser.z"
return BinaryOperatorKind_Modulus;
}
else {
#line 124 "src/parser.z"
if ((tok== TokenKind_Less)){
#line 124 "src/parser.z"
return BinaryOperatorKind_Less;
}
else {
#line 125 "src/parser.z"
if ((tok== TokenKind_LessEqual)){
#line 125 "src/parser.z"
return BinaryOperatorKind_LessEq;
}
else {
#line 126 "src/parser.z"
if ((tok== TokenKind_Greater)){
#line 126 "src/parser.z"
return BinaryOperatorKind_Greater;
}
else {
#line 127 "src/parser.z"
if ((tok== TokenKind_GreaterEqual)){
#line 127 "src/parser.z"
return BinaryOperatorKind_GreaterEq;
}
else {
#line 128 "src/parser.z"
if ((tok== TokenKind_EqualEqual)){
#line 128 "src/parser.z"
return BinaryOperatorKind_Equality;
}
else {
#line 129 "src/parser.z"
if ((tok== TokenKind_BangEqual)){
#line 129 "src/parser.z"
return BinaryOperatorKind_NotEq;
}
else {
#line 130 "src/parser.z"
if ((tok== TokenKind_AndAnd)){
#line 130 "src/parser.z"
return BinaryOperatorKind_And;
}
else {
#line 131 "src/parser.z"
if ((tok== TokenKind_OrOr)){
#line 131 "src/parser.z"
return BinaryOperatorKind_Or;
}
else {
#line 132 "src/parser.z"
if ((tok== TokenKind_And)){
#line 132 "src/parser.z"
return BinaryOperatorKind_BAnd;
}
else {
#line 133 "src/parser.z"
if ((tok== TokenKind_Or)){
#line 133 "src/parser.z"
return BinaryOperatorKind_BOr;
}
else {
#line 134 "src/parser.z"
if ((tok== TokenKind_Hat)){
#line 134 "src/parser.z"
return BinaryOperatorKind_Xor;
}
else {
#line 135 "src/parser.z"
if ((tok== TokenKind_LessLess)){
#line 135 "src/parser.z"
return BinaryOperatorKind_LeftShift;
}
else {
#line 136 "src/parser.z"
if ((tok== TokenKind_GreaterGreater)){
#line 136 "src/parser.z"
return BinaryOperatorKind_RightShift;
}
else {
#line 137 "src/parser.z"
return BinaryOperatorKind_Invalid;
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

#line 140 "src/parser.z"
u32 get_binary_operator_precedence(BinaryOperatorKind op) {
#line 141 "src/parser.z"
if ((op== BinaryOperatorKind_Product)){
#line 141 "src/parser.z"
return 10;
}
else {
#line 142 "src/parser.z"
if ((op== BinaryOperatorKind_Division)){
#line 142 "src/parser.z"
return 10;
}
else {
#line 143 "src/parser.z"
if ((op== BinaryOperatorKind_Modulus)){
#line 143 "src/parser.z"
return 10;
}
else {
#line 144 "src/parser.z"
if ((op== BinaryOperatorKind_Addition)){
#line 144 "src/parser.z"
return 9;
}
else {
#line 145 "src/parser.z"
if ((op== BinaryOperatorKind_Subtraction)){
#line 145 "src/parser.z"
return 9;
}
else {
#line 146 "src/parser.z"
if ((op== BinaryOperatorKind_LeftShift)){
#line 146 "src/parser.z"
return 8;
}
else {
#line 147 "src/parser.z"
if ((op== BinaryOperatorKind_RightShift)){
#line 147 "src/parser.z"
return 8;
}
else {
#line 148 "src/parser.z"
if ((op== BinaryOperatorKind_BAnd)){
#line 148 "src/parser.z"
return 7;
}
else {
#line 149 "src/parser.z"
if ((op== BinaryOperatorKind_Xor)){
#line 149 "src/parser.z"
return 6;
}
else {
#line 150 "src/parser.z"
if ((op== BinaryOperatorKind_BOr)){
#line 150 "src/parser.z"
return 5;
}
else {
#line 151 "src/parser.z"
if ((op== BinaryOperatorKind_Less)){
#line 151 "src/parser.z"
return 4;
}
else {
#line 152 "src/parser.z"
if ((op== BinaryOperatorKind_LessEq)){
#line 152 "src/parser.z"
return 4;
}
else {
#line 153 "src/parser.z"
if ((op== BinaryOperatorKind_Greater)){
#line 153 "src/parser.z"
return 4;
}
else {
#line 154 "src/parser.z"
if ((op== BinaryOperatorKind_GreaterEq)){
#line 154 "src/parser.z"
return 4;
}
else {
#line 155 "src/parser.z"
if ((op== BinaryOperatorKind_Equality)){
#line 155 "src/parser.z"
return 4;
}
else {
#line 156 "src/parser.z"
if ((op== BinaryOperatorKind_NotEq)){
#line 156 "src/parser.z"
return 4;
}
else {
#line 157 "src/parser.z"
if ((op== BinaryOperatorKind_And)){
#line 157 "src/parser.z"
return 3;
}
else {
#line 158 "src/parser.z"
if ((op== BinaryOperatorKind_Or)){
#line 158 "src/parser.z"
return 2;
}
else {
#line 159 "src/parser.z"
return 0;
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

#line 162 "src/parser.z"
u32 get_current_precedence(ParsingContext*  ctx) {
#line 164 "src/parser.z"
if ((ctx->num_tokens<= ctx->current_token)){
#line 165 "src/parser.z"
return 0;
}
else {
#line 167 "src/parser.z"
#line 167 "src/parser.z"
Token tok = ctx->tokens[ctx->current_token];

#line 168 "src/parser.z"
#line 168 "src/parser.z"
u32 op_precedence = get_binary_operator_precedence(convert_token_to_binary_operator(tok.kind) ) ;

#line 169 "src/parser.z"
if ((op_precedence> 0)){
#line 169 "src/parser.z"
return op_precedence;
}
else {
#line 170 "src/parser.z"
if ((tok.kind== TokenKind_Dot)){
#line 170 "src/parser.z"
return 13;
}
else {
#line 171 "src/parser.z"
if (((tok.kind== TokenKind_LeftBracket)|| (tok.kind== TokenKind_LeftParen))){
#line 171 "src/parser.z"
return 12;
}
else {
#line 172 "src/parser.z"
return 0;
}
;
}
;
}
;
}
;
}

#line 176 "src/parser.z"
Expr*  parse_expression(ParsingContext*  ctx, u32 precedence) ;

#line 178 "src/parser.z"
Expr*  parse_integer_literal(ParsingContext*  ctx) {
#line 180 "src/parser.z"
#line 180 "src/parser.z"
Token tok = expect(ctx,TokenKind_Integer) ;

#line 182 "src/parser.z"
#line 182 "src/parser.z"
Expr*  expr = malloc(sizeof(Expr) ) ;

#line 183 "src/parser.z"
expr->kind = ExprKind_Literal;
#line 184 "src/parser.z"
expr->node.lit.kind = LiteralKind_Int;
#line 186 "src/parser.z"
#line 186 "src/parser.z"
Session*  sess = ctx->sess;

#line 187 "src/parser.z"
expr->node.lit.value.integer = atol(get_str(&sess->interner,tok.lexeme) ) ;
#line 188 "src/parser.z"
return expr;
}

#line 191 "src/parser.z"
Expr*  parse_float_literal(ParsingContext*  ctx) {
#line 193 "src/parser.z"
#line 193 "src/parser.z"
Token tok = expect(ctx,TokenKind_Float) ;

#line 195 "src/parser.z"
#line 195 "src/parser.z"
Expr*  expr = malloc(sizeof(Expr) ) ;

#line 196 "src/parser.z"
expr->kind = ExprKind_Literal;
#line 197 "src/parser.z"
expr->node.lit.kind = LiteralKind_Float;
#line 199 "src/parser.z"
#line 199 "src/parser.z"
Session*  sess = ctx->sess;

#line 200 "src/parser.z"
expr->node.lit.value.floating = atof(get_str(&sess->interner,tok.lexeme) ) ;
#line 201 "src/parser.z"
return expr;
}

#line 204 "src/parser.z"
Expr*  parse_char_literal(ParsingContext*  ctx) {
#line 206 "src/parser.z"
#line 206 "src/parser.z"
Token tok = expect(ctx,TokenKind_Char) ;

#line 208 "src/parser.z"
#line 208 "src/parser.z"
Expr*  expr = malloc(sizeof(Expr) ) ;

#line 209 "src/parser.z"
expr->kind = ExprKind_Literal;
#line 210 "src/parser.z"
expr->node.lit.kind = LiteralKind_Char;
#line 212 "src/parser.z"
#line 212 "src/parser.z"
Session*  sess = ctx->sess;

#line 213 "src/parser.z"
#line 213 "src/parser.z"
char*  s = get_str(&sess->interner,tok.lexeme) ;

#line 215 "src/parser.z"
#line 215 "src/parser.z"
u32 len = strlen(s) ;

#line 216 "src/parser.z"
if (((len== 2)&& (s[0]== '\\'))){
#line 217 "src/parser.z"
#line 217 "src/parser.z"
char c ;

#line 218 "src/parser.z"
if ((s[1]== 'n')){
#line 218 "src/parser.z"
c = '\n';
}
else {
#line 219 "src/parser.z"
if ((s[1]== 't')){
#line 219 "src/parser.z"
c = '\t';
}
else {
#line 220 "src/parser.z"
if ((s[1]== 'r')){
#line 220 "src/parser.z"
c = '\r';
}
else {
#line 221 "src/parser.z"
if ((s[1]== '\\')){
#line 221 "src/parser.z"
c = '\\';
}
else {
#line 222 "src/parser.z"
if ((s[1]== '\'')){
#line 222 "src/parser.z"
c = '\'';
}
else {
#line 223 "src/parser.z"
emit_error(ctx->source_map,tok.span,"Unknown escape sequence") ;
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
#line 224 "src/parser.z"
expr->node.lit.value.ch = c;
}
else {
#line 225 "src/parser.z"
if ((len== 1)){
#line 226 "src/parser.z"
expr->node.lit.value.ch = s[0];
}
else {
#line 228 "src/parser.z"
emit_error(ctx->source_map,tok.span,"Invalid char literal") ;
}
;
}
;
#line 230 "src/parser.z"
return expr;
}

#line 233 "src/parser.z"
Expr*  parse_string_literal(ParsingContext*  ctx) {
#line 235 "src/parser.z"
#line 235 "src/parser.z"
Token tok = expect(ctx,TokenKind_String) ;

#line 237 "src/parser.z"
#line 237 "src/parser.z"
Expr*  expr = malloc(sizeof(Expr) ) ;

#line 238 "src/parser.z"
expr->kind = ExprKind_Literal;
#line 239 "src/parser.z"
expr->node.lit.kind = LiteralKind_Str;
#line 241 "src/parser.z"
expr->node.lit.value.str = tok.lexeme;
#line 242 "src/parser.z"
return expr;
}

#line 245 "src/parser.z"
Expr*  parse_bool_literal(ParsingContext*  ctx) {
#line 247 "src/parser.z"
#line 247 "src/parser.z"
Token tok = consume(ctx) ;

#line 249 "src/parser.z"
#line 249 "src/parser.z"
Expr*  expr = malloc(sizeof(Expr) ) ;

#line 250 "src/parser.z"
expr->kind = ExprKind_Literal;
#line 251 "src/parser.z"
expr->node.lit.kind = LiteralKind_Bool;
#line 252 "src/parser.z"
expr->node.lit.value.boolean = (tok.kind== TokenKind_True);
#line 253 "src/parser.z"
return expr;
}

#line 256 "src/parser.z"
Expr*  parse_call(ParsingContext*  ctx, Expr*  left) {
#line 258 "src/parser.z"
#line 258 "src/parser.z"
Expr*  result = malloc(sizeof(Expr) ) ;

#line 259 "src/parser.z"
result->kind = ExprKind_Call;
#line 260 "src/parser.z"
result->node.call.func = left;
#line 261 "src/parser.z"
result->node.call.args = malloc((8* 16)) ;
#line 262 "src/parser.z"
result->node.call.num_args = 0;
#line 264 "src/parser.z"
if (!accept(ctx,TokenKind_RightParen) ){
#line 265 "src/parser.z"
while ( true)
{
#line 266 "src/parser.z"
#line 266 "src/parser.z"
Expr*  expr = parse_expression(ctx,0) ;

#line 267 "src/parser.z"
result->node.call.args[result->node.call.num_args] = expr;
#line 268 "src/parser.z"
result->node.call.num_args = (result->node.call.num_args+ 1);
#line 269 "src/parser.z"
if (!accept(ctx,TokenKind_Comma) ){
#line 269 "src/parser.z"
break;
}
;
}
;
#line 271 "src/parser.z"
expect(ctx,TokenKind_RightParen) ;
}
;
#line 274 "src/parser.z"
return result;
}

#line 278 "src/parser.z"
Expr*  parse_prefix_operator(ParsingContext*  ctx) {
#line 279 "src/parser.z"
#line 279 "src/parser.z"
Expr*  expr = malloc(sizeof(Expr) ) ;

#line 280 "src/parser.z"
expr->kind = ExprKind_Unary;
#line 282 "src/parser.z"
#line 282 "src/parser.z"
Token tok = consume(ctx) ;

#line 284 "src/parser.z"
if ((tok.kind== TokenKind_Minus)){
#line 284 "src/parser.z"
expr->node.unary.op = UnaryOperatorKind_Negation;
}
else {
#line 285 "src/parser.z"
if ((tok.kind== TokenKind_Bang)){
#line 285 "src/parser.z"
expr->node.unary.op = UnaryOperatorKind_Complement;
}
else {
#line 286 "src/parser.z"
if ((tok.kind== TokenKind_And)){
#line 286 "src/parser.z"
expr->node.unary.op = UnaryOperatorKind_Refer;
}
else {
#line 287 "src/parser.z"
if ((tok.kind== TokenKind_Star)){
#line 287 "src/parser.z"
expr->node.unary.op = UnaryOperatorKind_Deref;
}
else {
#line 288 "src/parser.z"
emit_error(ctx->source_map,tok.span,"Invalid prefix operator") ;
}
;
}
;
}
;
}
;
#line 290 "src/parser.z"
expr->node.unary.inner = parse_expression(ctx,11) ;
#line 292 "src/parser.z"
return expr;
}

#line 295 "src/parser.z"
Expr*  parse_binary_operator(ParsingContext*  ctx, Expr*  left, BinaryOperatorKind operator) {
#line 296 "src/parser.z"
#line 296 "src/parser.z"
u32 precedence = get_binary_operator_precedence(operator) ;

#line 297 "src/parser.z"
#line 297 "src/parser.z"
Expr*  right = parse_expression(ctx,precedence) ;

#line 299 "src/parser.z"
#line 299 "src/parser.z"
Expr*  expr = malloc(sizeof(Expr) ) ;

#line 300 "src/parser.z"
expr->kind = ExprKind_Binary;
#line 301 "src/parser.z"
expr->node.binary.op = operator;
#line 302 "src/parser.z"
expr->node.binary.left = left;
#line 303 "src/parser.z"
expr->node.binary.right = right;
#line 305 "src/parser.z"
return expr;
}

#line 308 "src/parser.z"
Expr*  parse_field_access(ParsingContext*  ctx, Expr*  left) {
#line 309 "src/parser.z"
#line 309 "src/parser.z"
Expr*  expr = malloc(sizeof(Expr) ) ;

#line 310 "src/parser.z"
expr->kind = ExprKind_Field;
#line 311 "src/parser.z"
expr->node.field.ident = parse_identifier(ctx) ;
#line 312 "src/parser.z"
expr->node.field.strct = left;
#line 314 "src/parser.z"
return expr;
}

#line 317 "src/parser.z"
Expr*  parse_indexing(ParsingContext*  ctx, Expr*  left) {
#line 319 "src/parser.z"
#line 319 "src/parser.z"
Expr*  expr = malloc(sizeof(Expr) ) ;

#line 320 "src/parser.z"
expr->kind = ExprKind_Indexing;
#line 321 "src/parser.z"
expr->node.indexing.index = parse_expression(ctx,0) ;
#line 322 "src/parser.z"
expr->node.indexing.array = left;
#line 324 "src/parser.z"
expect(ctx,TokenKind_RightBracket) ;
#line 326 "src/parser.z"
return expr;
}

#line 329 "src/parser.z"
Expr*  parse_infix_operator(ParsingContext*  ctx, Expr*  left, Token tok) {
#line 331 "src/parser.z"
if ((tok.kind== TokenKind_LeftParen)){
#line 331 "src/parser.z"
return parse_call(ctx,left) ;
}
;
#line 332 "src/parser.z"
if ((tok.kind== TokenKind_Dot)){
#line 332 "src/parser.z"
return parse_field_access(ctx,left) ;
}
;
#line 333 "src/parser.z"
if ((tok.kind== TokenKind_LeftBracket)){
#line 333 "src/parser.z"
return parse_indexing(ctx,left) ;
}
;
#line 335 "src/parser.z"
#line 335 "src/parser.z"
BinaryOperatorKind op = convert_token_to_binary_operator(tok.kind) ;

#line 336 "src/parser.z"
if ((op!= BinaryOperatorKind_Invalid)){
#line 337 "src/parser.z"
return parse_binary_operator(ctx,left,op) ;
}
else {
#line 339 "src/parser.z"
emit_error(ctx->source_map,tok.span,"Unsupported infix operator") ;
}
;
#line 340 "src/parser.z"
return null;
}

#line 343 "src/parser.z"
Stmt*  parse_stmt(ParsingContext*  ctx) ;

#line 344 "src/parser.z"
Block*  parse_block(ParsingContext*  ctx) {
#line 346 "src/parser.z"
#line 346 "src/parser.z"
Block*  block = malloc(sizeof(Block) ) ;

#line 347 "src/parser.z"
block->stmts = malloc((8* 128)) ;
#line 348 "src/parser.z"
block->num_stmts = 0;
#line 349 "src/parser.z"
block->span.from = span_start(ctx) ;
#line 351 "src/parser.z"
#line 351 "src/parser.z"
Token next = look_ahead(ctx,0) ;

#line 352 "src/parser.z"
if ((next.kind== TokenKind_LeftCurly)){
#line 353 "src/parser.z"
expect(ctx,TokenKind_LeftCurly) ;
#line 354 "src/parser.z"
#line 354 "src/parser.z"
u32 i = 0;

#line 355 "src/parser.z"
while ( !accept(ctx,TokenKind_RightCurly) )
{
#line 356 "src/parser.z"
block->stmts[i] = parse_stmt(ctx) ;
#line 357 "src/parser.z"
block->num_stmts = (block->num_stmts+ 1);
#line 358 "src/parser.z"
i = (i+ 1);
}
;
}
else {
#line 361 "src/parser.z"
block->stmts[0] = parse_stmt(ctx) ;
#line 362 "src/parser.z"
block->num_stmts = 1;
}
;
#line 364 "src/parser.z"
block->span.to = span_end(ctx) ;
#line 366 "src/parser.z"
return block;
}

#line 369 "src/parser.z"
Expr*  parse_block_expr(ParsingContext*  ctx) {
#line 370 "src/parser.z"
#line 370 "src/parser.z"
Expr*  expr = malloc(sizeof(Expr) ) ;

#line 371 "src/parser.z"
expr->kind = ExprKind_Block;
#line 372 "src/parser.z"
expr->node.block = parse_block(ctx) ;
#line 373 "src/parser.z"
return expr;
}

#line 376 "src/parser.z"
Expr*  parse_if(ParsingContext*  ctx) {
#line 378 "src/parser.z"
expect(ctx,TokenKind_If) ;
#line 380 "src/parser.z"
#line 380 "src/parser.z"
Expr*  expr = malloc(sizeof(Expr) ) ;

#line 381 "src/parser.z"
expr->kind = ExprKind_Conditional;
#line 382 "src/parser.z"
expr->node.conditional.condition = parse_expression(ctx,0) ;
#line 383 "src/parser.z"
expr->node.conditional.then = parse_block_expr(ctx) ;
#line 385 "src/parser.z"
if (accept(ctx,TokenKind_Else) ){
#line 386 "src/parser.z"
expr->node.conditional.otherwise = parse_block_expr(ctx) ;
}
else {
#line 388 "src/parser.z"
expr->node.conditional.otherwise = null;
}
;
#line 391 "src/parser.z"
return expr;
}

#line 394 "src/parser.z"
Expr*  parse_while(ParsingContext*  ctx) {
#line 395 "src/parser.z"
expect(ctx,TokenKind_While) ;
#line 397 "src/parser.z"
#line 397 "src/parser.z"
Expr*  expr = malloc(sizeof(Expr) ) ;

#line 398 "src/parser.z"
expr->kind = ExprKind_While;
#line 399 "src/parser.z"
expr->node.whl.condition = parse_expression(ctx,0) ;
#line 400 "src/parser.z"
expr->node.whl.body = parse_block_expr(ctx) ;
#line 402 "src/parser.z"
return expr;
}

#line 405 "src/parser.z"
Expr*  parse_expression(ParsingContext*  ctx, u32 precedence) {
#line 406 "src/parser.z"
#line 406 "src/parser.z"
Token tok = look_ahead(ctx,0) ;

#line 407 "src/parser.z"
#line 407 "src/parser.z"
Span span ;

#line 408 "src/parser.z"
span.from = span_start(ctx) ;
#line 410 "src/parser.z"
#line 410 "src/parser.z"
Expr*  left ;

#line 412 "src/parser.z"
if ((tok.kind== TokenKind_Identifier)){
#line 412 "src/parser.z"
left = parse_path_expr(ctx) ;
}
else {
#line 413 "src/parser.z"
if ((tok.kind== TokenKind_Integer)){
#line 413 "src/parser.z"
left = parse_integer_literal(ctx) ;
}
else {
#line 414 "src/parser.z"
if ((tok.kind== TokenKind_Char)){
#line 414 "src/parser.z"
left = parse_char_literal(ctx) ;
}
else {
#line 415 "src/parser.z"
if ((tok.kind== TokenKind_String)){
#line 415 "src/parser.z"
left = parse_string_literal(ctx) ;
}
else {
#line 416 "src/parser.z"
if ((tok.kind== TokenKind_Float)){
#line 416 "src/parser.z"
left = parse_float_literal(ctx) ;
}
else {
#line 417 "src/parser.z"
if (((tok.kind== TokenKind_False)|| (tok.kind== TokenKind_True))){
#line 417 "src/parser.z"
left = parse_bool_literal(ctx) ;
}
else {
#line 418 "src/parser.z"
if (((((tok.kind== TokenKind_Minus)|| (tok.kind== TokenKind_Bang))|| (tok.kind== TokenKind_And))|| (tok.kind== TokenKind_Star))){
#line 419 "src/parser.z"
left = parse_prefix_operator(ctx) ;
}
else {
#line 420 "src/parser.z"
if ((tok.kind== TokenKind_If)){
#line 420 "src/parser.z"
left = parse_if(ctx) ;
}
else {
#line 421 "src/parser.z"
if ((tok.kind== TokenKind_While)){
#line 421 "src/parser.z"
left = parse_while(ctx) ;
}
else {
#line 422 "src/parser.z"
if ((tok.kind== TokenKind_LeftParen)){
#line 423 "src/parser.z"
expect(ctx,TokenKind_LeftParen) ;
#line 424 "src/parser.z"
left = parse_expression(ctx,0) ;
#line 425 "src/parser.z"
expect(ctx,TokenKind_RightParen) ;
}
else {
#line 427 "src/parser.z"
if ((tok.kind== TokenKind_LeftCurly)){
#line 427 "src/parser.z"
left = parse_block_expr(ctx) ;
}
else {
#line 428 "src/parser.z"
emit_error(ctx->source_map,tok.span,"Invalid expression prefix") ;
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
#line 430 "src/parser.z"
while ( (precedence< get_current_precedence(ctx) ))
{
#line 431 "src/parser.z"
#line 431 "src/parser.z"
Token next_tok = consume(ctx) ;

#line 432 "src/parser.z"
left = parse_infix_operator(ctx,left,next_tok) ;
}
;
#line 434 "src/parser.z"
span.to = span_end(ctx) ;
#line 435 "src/parser.z"
left->span = span;
#line 437 "src/parser.z"
return left;
}

#line 440 "src/parser.z"
NodeId parse_item(ParsingContext*  ctx) ;

#line 442 "src/parser.z"
Stmt*  parse_stmt(ParsingContext*  ctx) {
#line 444 "src/parser.z"
#line 444 "src/parser.z"
Stmt*  stmt = malloc(sizeof(Stmt) ) ;

#line 445 "src/parser.z"
stmt->span.from = span_start(ctx) ;
#line 447 "src/parser.z"
#line 447 "src/parser.z"
Token tok = look_ahead(ctx,0) ;

#line 448 "src/parser.z"
if (accept(ctx,TokenKind_Break) ){
#line 449 "src/parser.z"
stmt->kind = StmtKind_Break;
}
else {
#line 450 "src/parser.z"
if (accept(ctx,TokenKind_Continue) ){
#line 451 "src/parser.z"
stmt->kind = StmtKind_Continue;
}
else {
#line 452 "src/parser.z"
if (accept(ctx,TokenKind_Return) ){
#line 453 "src/parser.z"
stmt->kind = StmtKind_Return;
#line 454 "src/parser.z"
stmt->node._return = parse_expression(ctx,0) ;
}
else {
#line 455 "src/parser.z"
if (accept(ctx,TokenKind_Defer) ){
#line 456 "src/parser.z"
stmt->kind = StmtKind_Defer;
#line 457 "src/parser.z"
stmt->node._defer = parse_expression(ctx,0) ;
}
else {
#line 458 "src/parser.z"
if (accept(ctx,TokenKind_Semicolon) ){
#line 459 "src/parser.z"
stmt->kind = StmtKind_Empty;
}
else {
#line 460 "src/parser.z"
if (((tok.kind== TokenKind_Var)|| (tok.kind== TokenKind_Val))){
#line 461 "src/parser.z"
stmt->kind = StmtKind_Item;
#line 462 "src/parser.z"
stmt->node.item = parse_item(ctx) ;
}
else {
#line 464 "src/parser.z"
#line 464 "src/parser.z"
Expr*  left = parse_expression(ctx,0) ;

#line 465 "src/parser.z"
#line 465 "src/parser.z"
Token next = look_ahead(ctx,0) ;

#line 467 "src/parser.z"
if ((next.kind== TokenKind_Equal)){
#line 468 "src/parser.z"
stmt->kind = StmtKind_Assignment;
#line 469 "src/parser.z"
stmt->node.assignment.left = left;
#line 470 "src/parser.z"
expect(ctx,TokenKind_Equal) ;
#line 471 "src/parser.z"
stmt->node.assignment.right = parse_expression(ctx,0) ;
}
else {
#line 473 "src/parser.z"
stmt->kind = StmtKind_Expr;
#line 474 "src/parser.z"
stmt->node.expr = left;
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
#line 478 "src/parser.z"
accept(ctx,TokenKind_Semicolon) ;
#line 479 "src/parser.z"
stmt->span.to = span_end(ctx) ;
#line 481 "src/parser.z"
return stmt;
}

#line 484 "src/parser.z"
Generics parse_generics(ParsingContext*  ctx) {
#line 485 "src/parser.z"
expect(ctx,TokenKind_Less) ;
#line 486 "src/parser.z"
#line 486 "src/parser.z"
Generics generics ;

#line 487 "src/parser.z"
generics.parameters = malloc((4* sizeof(GenericParam) )) ;
#line 488 "src/parser.z"
generics.num_parameters = 0;
#line 490 "src/parser.z"
while ( !accept(ctx,TokenKind_Greater) )
{
#line 491 "src/parser.z"
generics.parameters[generics.num_parameters].ident = parse_identifier(ctx) ;
#line 493 "src/parser.z"
accept(ctx,TokenKind_Comma) ;
#line 494 "src/parser.z"
generics.num_parameters = (generics.num_parameters+ 1);
}
;
#line 496 "src/parser.z"
return generics;
}

#line 499 "src/parser.z"
NodeId parse_body(ParsingContext*  ctx, NodeId owner) {
#line 500 "src/parser.z"
#line 500 "src/parser.z"
NodeId id ;

#line 501 "src/parser.z"
#line 501 "src/parser.z"
Body*  body = unit_create_body(ctx->unit,owner,&id) ;

#line 503 "src/parser.z"
body->value = parse_expression(ctx,0) ;
#line 505 "src/parser.z"
return id;
}

#line 508 "src/parser.z"
void  parse_variable_decl(ParsingContext*  ctx, Item*  item) {
#line 510 "src/parser.z"
#line 510 "src/parser.z"
Token keyword = consume(ctx) ;

#line 511 "src/parser.z"
if ((keyword.kind== TokenKind_Val)){
#line 511 "src/parser.z"
item->kind = ItemKind_Const;
}
else {
#line 512 "src/parser.z"
if ((keyword.kind== TokenKind_Var)){
#line 512 "src/parser.z"
item->kind = ItemKind_Variable;
}
else {
#line 513 "src/parser.z"
abort() ;
}
;
}
;
#line 515 "src/parser.z"
item->ident = parse_identifier(ctx) ;
#line 516 "src/parser.z"
expect(ctx,TokenKind_Colon) ;
#line 517 "src/parser.z"
item->node.variable.ty = parse_type(ctx) ;
#line 519 "src/parser.z"
if (accept(ctx,TokenKind_Equal) ){
#line 519 "src/parser.z"
item->node.variable.body = parse_body(ctx,item->id) ;
}
else {
#line 520 "src/parser.z"
item->node.variable.body.owner = null;
}
;
}

#line 523 "src/parser.z"
void  parse_compound_decl(ParsingContext*  ctx, Item*  item) {
#line 525 "src/parser.z"
if (accept(ctx,TokenKind_Struct) ){
#line 525 "src/parser.z"
item->kind = ItemKind_Struct;
}
else {
#line 526 "src/parser.z"
if (accept(ctx,TokenKind_Union) ){
#line 526 "src/parser.z"
item->kind = ItemKind_Union;
}
else {
#line 527 "src/parser.z"
abort() ;
}
;
}
;
#line 529 "src/parser.z"
item->ident = parse_identifier(ctx) ;
#line 531 "src/parser.z"
if (can_accept(ctx,TokenKind_Less) ){
#line 531 "src/parser.z"
item->node.compound.generics = parse_generics(ctx) ;
}
else {
#line 532 "src/parser.z"
item->node.compound.generics.num_parameters = 0;
}
;
#line 534 "src/parser.z"
expect(ctx,TokenKind_LeftCurly) ;
#line 536 "src/parser.z"
item->node.compound.fields = malloc((sizeof(CompoundField) * 16)) ;
#line 537 "src/parser.z"
item->node.compound.num_fields = 0;
#line 539 "src/parser.z"
while ( !accept(ctx,TokenKind_RightCurly) )
{
#line 540 "src/parser.z"
#line 540 "src/parser.z"
Token token = consume(ctx) ;

#line 541 "src/parser.z"
if ((token.kind!= TokenKind_Identifier)){
#line 541 "src/parser.z"
emit_error(ctx->source_map,token.span,"Expected field identifier") ;
}
;
#line 543 "src/parser.z"
item->node.compound.fields[item->node.compound.num_fields].ident.name = token.lexeme;
#line 544 "src/parser.z"
expect(ctx,TokenKind_Colon) ;
#line 546 "src/parser.z"
#line 546 "src/parser.z"
Type*  type = parse_type(ctx) ;

#line 547 "src/parser.z"
item->node.compound.fields[item->node.compound.num_fields].ty = type;
#line 548 "src/parser.z"
item->node.compound.num_fields = (item->node.compound.num_fields+ 1);
#line 549 "src/parser.z"
expect(ctx,TokenKind_Comma) ;
}
;
}

#line 554 "src/parser.z"
void  parse_enum_decl(ParsingContext*  ctx, Item*  item) {
#line 556 "src/parser.z"
expect(ctx,TokenKind_Enum) ;
#line 557 "src/parser.z"
item->kind = ItemKind_Enum;
#line 559 "src/parser.z"
item->ident = parse_identifier(ctx) ;
#line 561 "src/parser.z"
expect(ctx,TokenKind_LeftCurly) ;
#line 563 "src/parser.z"
item->node._enum.variants = malloc((sizeof(EnumVariant) * 128)) ;
#line 564 "src/parser.z"
item->node._enum.num_variants = 0;
#line 566 "src/parser.z"
while ( !accept(ctx,TokenKind_RightCurly) )
{
#line 567 "src/parser.z"
item->node._enum.variants[item->node._enum.num_variants].ident = parse_identifier(ctx) ;
#line 568 "src/parser.z"
item->node._enum.num_variants = (item->node._enum.num_variants+ 1);
#line 569 "src/parser.z"
expect(ctx,TokenKind_Comma) ;
}
;
}

#line 573 "src/parser.z"
FunctionHeader parse_function_header(ParsingContext*  ctx) {
#line 574 "src/parser.z"
#line 574 "src/parser.z"
FunctionHeader header ;

#line 576 "src/parser.z"
header.parameters = malloc((sizeof(FunctionParameter) * 16)) ;
#line 577 "src/parser.z"
header.num_parameters = 0;
#line 579 "src/parser.z"
if (can_accept(ctx,TokenKind_Less) ){
#line 579 "src/parser.z"
header.generics = parse_generics(ctx) ;
}
else {
#line 580 "src/parser.z"
header.generics.num_parameters = 0;
}
;
#line 582 "src/parser.z"
expect(ctx,TokenKind_LeftParen) ;
#line 584 "src/parser.z"
while ( !accept(ctx,TokenKind_RightParen) )
{
#line 586 "src/parser.z"
header.parameters[header.num_parameters].ident = parse_identifier(ctx) ;
#line 588 "src/parser.z"
expect(ctx,TokenKind_Colon) ;
#line 589 "src/parser.z"
#line 589 "src/parser.z"
Type*  type = parse_type(ctx) ;

#line 590 "src/parser.z"
header.parameters[header.num_parameters].ty = type;
#line 591 "src/parser.z"
header.num_parameters = (header.num_parameters+ 1);
#line 593 "src/parser.z"
accept(ctx,TokenKind_Comma) ;
}
;
#line 596 "src/parser.z"
if (accept(ctx,TokenKind_Arrow) ){
#line 596 "src/parser.z"
header.output = parse_type(ctx) ;
}
else {
#line 599 "src/parser.z"
#line 599 "src/parser.z"
Type*  output = malloc(sizeof(Type) ) ;

#line 600 "src/parser.z"
output->kind = TypeKind_Unit;
#line 601 "src/parser.z"
header.output = output;
}
;
#line 604 "src/parser.z"
return header;
}

#line 607 "src/parser.z"
void  parse_function_decl(ParsingContext*  ctx, Item*  item) {
#line 608 "src/parser.z"
expect(ctx,TokenKind_Fn) ;
#line 610 "src/parser.z"
item->ident = parse_identifier(ctx) ;
#line 611 "src/parser.z"
item->kind = ItemKind_Function;
#line 613 "src/parser.z"
item->node.function.header = parse_function_header(ctx) ;
#line 615 "src/parser.z"
if ((look_ahead(ctx,0) .kind== TokenKind_LeftCurly)){
#line 615 "src/parser.z"
item->node.function.body = parse_body(ctx,item->id) ;
}
else {
#line 616 "src/parser.z"
item->node.function.body.owner = null;
}
;
}

#line 619 "src/parser.z"
void  parse_use(ParsingContext*  ctx, Item*  item) {
#line 620 "src/parser.z"
expect(ctx,TokenKind_Use) ;
#line 622 "src/parser.z"
item->kind = ItemKind_Use;
#line 623 "src/parser.z"
item->node._use.path = parse_path(ctx) ;
#line 625 "src/parser.z"
accept(ctx,TokenKind_Semicolon) ;
}

#line 628 "src/parser.z"
Mod parse_mod_inner(ParsingContext*  ctx) ;

#line 629 "src/parser.z"
Mod parse_mod_external(Session*  sess, CompilationUnit*  unit, char*  path) ;

#line 631 "src/parser.z"
void  parse_mod(ParsingContext*  ctx, Item*  item) {
#line 632 "src/parser.z"
expect(ctx,TokenKind_Mod) ;
#line 634 "src/parser.z"
item->ident = parse_identifier(ctx) ;
#line 635 "src/parser.z"
item->kind = ItemKind_Mod;
#line 637 "src/parser.z"
if (accept(ctx,TokenKind_LeftCurly) ){
#line 637 "src/parser.z"
item->node.module = parse_mod_inner(ctx) ;
}
else {
#line 639 "src/parser.z"
#line 639 "src/parser.z"
Session*  sess = ctx->sess;

#line 640 "src/parser.z"
#line 640 "src/parser.z"
char*  path = get_str(&sess->interner,item->ident.name) ;

#line 641 "src/parser.z"
item->node.module = parse_mod_external(ctx->sess,ctx->unit,path) ;
}
;
}

#line 646 "src/parser.z"
NodeId parse_item(ParsingContext*  ctx) {
#line 647 "src/parser.z"
#line 647 "src/parser.z"
Token tok = look_ahead(ctx,0) ;

#line 649 "src/parser.z"
#line 649 "src/parser.z"
NodeId id ;

#line 650 "src/parser.z"
#line 650 "src/parser.z"
Item*  item = unit_create_item(ctx->unit,&id) ;

#line 651 "src/parser.z"
item->span.from = span_start(ctx) ;
#line 653 "src/parser.z"
if ((tok.kind== TokenKind_Fn)){
#line 653 "src/parser.z"
parse_function_decl(ctx,item) ;
}
else {
#line 654 "src/parser.z"
if (((tok.kind== TokenKind_Struct)|| (tok.kind== TokenKind_Union))){
#line 654 "src/parser.z"
parse_compound_decl(ctx,item) ;
}
else {
#line 655 "src/parser.z"
if ((tok.kind== TokenKind_Enum)){
#line 655 "src/parser.z"
parse_enum_decl(ctx,item) ;
}
else {
#line 656 "src/parser.z"
if (((tok.kind== TokenKind_Var)|| (tok.kind== TokenKind_Val))){
#line 656 "src/parser.z"
parse_variable_decl(ctx,item) ;
}
else {
#line 657 "src/parser.z"
if ((tok.kind== TokenKind_Use)){
#line 657 "src/parser.z"
parse_use(ctx,item) ;
}
else {
#line 658 "src/parser.z"
if ((tok.kind== TokenKind_Mod)){
#line 658 "src/parser.z"
parse_mod(ctx,item) ;
}
else {
#line 659 "src/parser.z"
emit_error(ctx->source_map,tok.span,"Unexpected token on top-level") ;
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
#line 661 "src/parser.z"
accept(ctx,TokenKind_Semicolon) ;
#line 663 "src/parser.z"
item->span.to = span_end(ctx) ;
#line 664 "src/parser.z"
return id;
}

#line 667 "src/parser.z"
Mod parse_mod_inner(ParsingContext*  ctx) {
#line 668 "src/parser.z"
#line 668 "src/parser.z"
Mod module ;

#line 669 "src/parser.z"
module.span.from = span_start(ctx) ;
#line 670 "src/parser.z"
module.items = malloc((sizeof(NodeId) * 2048)) ;
#line 671 "src/parser.z"
module.num_items = 0;
#line 673 "src/parser.z"
while ( (!accept(ctx,TokenKind_RightCurly) && !is_done_parsing(ctx) ))
{
#line 674 "src/parser.z"
module.items[module.num_items] = parse_item(ctx) ;
#line 675 "src/parser.z"
module.num_items = (module.num_items+ 1);
}
;
#line 678 "src/parser.z"
module.span.to = span_end(ctx) ;
#line 680 "src/parser.z"
return module;
}

#line 683 "src/parser.z"
Mod parse_mod_external(Session*  sess, CompilationUnit*  unit, char*  path) {
#line 685 "src/parser.z"
#line 685 "src/parser.z"
SourceFile*  source_file = source_map_new_file(&sess->source,sess->root_path,path) ;

#line 687 "src/parser.z"
#line 687 "src/parser.z"
Token*  tokens ;

#line 688 "src/parser.z"
#line 688 "src/parser.z"
u32 num_tokens ;

#line 689 "src/parser.z"
lex(sess,source_file,&tokens,&num_tokens) ;
#line 691 "src/parser.z"
#line 691 "src/parser.z"
ParsingContext ctx ;

#line 692 "src/parser.z"
ctx.current_token = 0;
#line 693 "src/parser.z"
ctx.tokens = tokens;
#line 694 "src/parser.z"
ctx.num_tokens = num_tokens;
#line 695 "src/parser.z"
ctx.source_map = &sess->source;
#line 696 "src/parser.z"
ctx.sess = sess;
#line 697 "src/parser.z"
ctx.unit = unit;
#line 699 "src/parser.z"
#line 699 "src/parser.z"
Mod module = parse_mod_inner(&ctx) ;

#line 701 "src/parser.z"
return module;
}

#line 704 "src/parser.z"
CompilationUnit parse(Session*  sess, char*  root_module_name) {
#line 706 "src/parser.z"
#line 706 "src/parser.z"
CompilationUnit unit ;

#line 708 "src/parser.z"
unit.body_map = intmap_create(2048) ;
#line 709 "src/parser.z"
unit.bodies = malloc((sizeof(Body) * 2048)) ;
#line 710 "src/parser.z"
unit.num_bodies = 1;
#line 712 "src/parser.z"
unit.item_map = intmap_create(2048) ;
#line 713 "src/parser.z"
unit.items = malloc((sizeof(Item) * 2048)) ;
#line 714 "src/parser.z"
unit.num_items = 1;
#line 716 "src/parser.z"
unit.module = parse_mod_external(sess,&unit,root_module_name) ;
#line 718 "src/parser.z"
return unit;
}


typedef struct Scope Scope;
#line 2 "src/resolution.z"
typedef struct Scope {
IntMap*  symbols;
u32 current_owner;
u32 next_local;
} Scope;


typedef struct ResolutionContext ResolutionContext;
#line 8 "src/resolution.z"
typedef struct ResolutionContext {
Scope*  scope_stack;
u32 stack_top;
CompilationUnit*  unit;
SourceMap*  source_map;
Interner*  interner;
} ResolutionContext;


#line 16 "src/resolution.z"
u64 encode_id(NodeId id) {
#line 17 "src/resolution.z"
#line 17 "src/resolution.z"
u64 owner = id.owner;

#line 18 "src/resolution.z"
#line 18 "src/resolution.z"
u64 v = ((owner<< 32)| id.local);

#line 19 "src/resolution.z"
return v;
}

#line 22 "src/resolution.z"
NodeId decode_id(u64 v) {
#line 23 "src/resolution.z"
#line 23 "src/resolution.z"
NodeId id ;

#line 24 "src/resolution.z"
id.owner = (v>> 32);
#line 25 "src/resolution.z"
id.local = v;
#line 26 "src/resolution.z"
return id;
}

#line 29 "src/resolution.z"
void  push_ident(ResolutionContext*  ctx, Ident ident, NodeId id) {
#line 30 "src/resolution.z"
intmap_insert(ctx->scope_stack[ctx->stack_top].symbols,ident.name.x,encode_id(id) ) ;
}

#line 33 "src/resolution.z"
bool lookup_ident(ResolutionContext*  ctx, Ident ident, NodeId*  id) {
#line 34 "src/resolution.z"
#line 34 "src/resolution.z"
i32 i = ctx->stack_top;

#line 36 "src/resolution.z"
while ( (i>= 0))
{
#line 37 "src/resolution.z"
#line 37 "src/resolution.z"
u64 v = intmap_lookup(ctx->scope_stack[i].symbols,ident.name.x) ;

#line 38 "src/resolution.z"
if ((v> 0)){
#line 39 "src/resolution.z"
*id = decode_id(v) ;
#line 40 "src/resolution.z"
return true;
}
;
#line 42 "src/resolution.z"
i = (i- 1);
}
;
#line 44 "src/resolution.z"
return false;
}

#line 47 "src/resolution.z"
void  push_scope(ResolutionContext*  ctx) {
#line 48 "src/resolution.z"
ctx->stack_top = (ctx->stack_top+ 1);
#line 49 "src/resolution.z"
ctx->scope_stack[ctx->stack_top].current_owner = ctx->scope_stack[(ctx->stack_top- 1)].current_owner;
#line 50 "src/resolution.z"
ctx->scope_stack[ctx->stack_top].next_local = 2;
}

#line 53 "src/resolution.z"
void  pop_scope(ResolutionContext*  ctx) {
#line 54 "src/resolution.z"
intmap_reset(ctx->scope_stack[ctx->stack_top].symbols) ;
#line 55 "src/resolution.z"
ctx->stack_top = (ctx->stack_top- 1);
}

#line 58 "src/resolution.z"
void  scan_item(ResolutionContext*  ctx, Item*  item) {
#line 59 "src/resolution.z"
push_ident(ctx,item->ident,item->id) ;
}

#line 62 "src/resolution.z"
void  resolve_path(ResolutionContext*  ctx, Path*  path) {
#line 63 "src/resolution.z"
#line 63 "src/resolution.z"
NodeId id ;

#line 64 "src/resolution.z"
if (lookup_ident(ctx,path->segments[0],&id) ){
#line 65 "src/resolution.z"
path->res.kind = ResKind_Definition;
#line 66 "src/resolution.z"
path->res.node.def = id;
}
else {
#line 69 "src/resolution.z"
printf("Failed to resolve %s\n",get_str(ctx->interner,path->segments[0].name) ) ;
}
;
}

#line 73 "src/resolution.z"
void  resolve_expr(ResolutionContext*  ctx, Expr*  expr) ;

#line 74 "src/resolution.z"
void  resolve_block(ResolutionContext*  ctx, Block*  block) ;

#line 75 "src/resolution.z"
void  resolve_stmt(ResolutionContext*  ctx, Stmt*  stmt) ;

#line 76 "src/resolution.z"
void  resolve_item(ResolutionContext*  ctx, Item*  item) ;

#line 78 "src/resolution.z"
void  resolve_unary(ResolutionContext*  ctx, UnaryData unary) {
#line 79 "src/resolution.z"
resolve_expr(ctx,unary.inner) ;
}

#line 82 "src/resolution.z"
void  resolve_binary(ResolutionContext*  ctx, BinaryData binary) {
#line 83 "src/resolution.z"
resolve_expr(ctx,binary.left) ;
#line 84 "src/resolution.z"
resolve_expr(ctx,binary.right) ;
}

#line 87 "src/resolution.z"
void  resolve_call(ResolutionContext*  ctx, CallData call) {
#line 88 "src/resolution.z"
resolve_expr(ctx,call.func) ;
#line 90 "src/resolution.z"
#line 90 "src/resolution.z"
u32 i = 0;

#line 91 "src/resolution.z"
while ( (i< call.num_args))
{
#line 92 "src/resolution.z"
resolve_expr(ctx,call.args[i]) ;
#line 93 "src/resolution.z"
i = (i+ 1);
}
;
}

#line 97 "src/resolution.z"
void  resolve_conditional(ResolutionContext*  ctx, ConditionalData cond) {
#line 98 "src/resolution.z"
resolve_expr(ctx,cond.condition) ;
#line 99 "src/resolution.z"
resolve_expr(ctx,cond.then) ;
#line 100 "src/resolution.z"
if (cond.otherwise){
#line 101 "src/resolution.z"
resolve_expr(ctx,cond.otherwise) ;
}
;
}

#line 105 "src/resolution.z"
void  resolve_while(ResolutionContext*  ctx, WhileData data) {
#line 106 "src/resolution.z"
resolve_expr(ctx,data.condition) ;
#line 107 "src/resolution.z"
resolve_expr(ctx,data.body) ;
}

#line 110 "src/resolution.z"
void  resolve_indexing(ResolutionContext*  ctx, IndexingData idx) {
#line 111 "src/resolution.z"
resolve_expr(ctx,idx.array) ;
#line 112 "src/resolution.z"
resolve_expr(ctx,idx.index) ;
}

#line 115 "src/resolution.z"
void  resolve_field(ResolutionContext*  ctx, FieldData field) {
#line 116 "src/resolution.z"
resolve_expr(ctx,field.strct) ;
}

#line 119 "src/resolution.z"
void  resolve_expr(ResolutionContext*  ctx, Expr*  expr) {
#line 120 "src/resolution.z"
if ((expr->kind== ExprKind_Unary)){
#line 120 "src/resolution.z"
resolve_unary(ctx,expr->node.unary) ;
}
else {
#line 121 "src/resolution.z"
if ((expr->kind== ExprKind_Binary)){
#line 121 "src/resolution.z"
resolve_binary(ctx,expr->node.binary) ;
}
else {
#line 122 "src/resolution.z"
if ((expr->kind== ExprKind_Block)){
#line 122 "src/resolution.z"
resolve_block(ctx,expr->node.block) ;
}
else {
#line 123 "src/resolution.z"
if ((expr->kind== ExprKind_Call)){
#line 123 "src/resolution.z"
resolve_call(ctx,expr->node.call) ;
}
else {
#line 124 "src/resolution.z"
if ((expr->kind== ExprKind_Conditional)){
#line 124 "src/resolution.z"
resolve_conditional(ctx,expr->node.conditional) ;
}
else {
#line 125 "src/resolution.z"
if ((expr->kind== ExprKind_While)){
#line 125 "src/resolution.z"
resolve_while(ctx,expr->node.whl) ;
}
else {
#line 126 "src/resolution.z"
if ((expr->kind== ExprKind_Indexing)){
#line 126 "src/resolution.z"
resolve_indexing(ctx,expr->node.indexing) ;
}
else {
#line 127 "src/resolution.z"
if ((expr->kind== ExprKind_Field)){
#line 127 "src/resolution.z"
resolve_field(ctx,expr->node.field) ;
}
else {
#line 128 "src/resolution.z"
if ((expr->kind== ExprKind_Path)){
#line 128 "src/resolution.z"
resolve_path(ctx,&expr->node.path) ;
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

#line 131 "src/resolution.z"
void  resolve_assignment(ResolutionContext*  ctx, AssignmentData assignment) {
#line 132 "src/resolution.z"
resolve_expr(ctx,assignment.left) ;
#line 133 "src/resolution.z"
resolve_expr(ctx,assignment.right) ;
}

#line 136 "src/resolution.z"
void  resolve_stmt(ResolutionContext*  ctx, Stmt*  stmt) {
#line 137 "src/resolution.z"
if ((stmt->kind== StmtKind_Assignment)){
#line 137 "src/resolution.z"
resolve_assignment(ctx,stmt->node.assignment) ;
}
else {
#line 138 "src/resolution.z"
if ((stmt->kind== StmtKind_Expr)){
#line 138 "src/resolution.z"
resolve_expr(ctx,stmt->node.expr) ;
}
else {
#line 139 "src/resolution.z"
if ((stmt->kind== StmtKind_Item)){
#line 139 "src/resolution.z"
resolve_item(ctx,unit_get_item(ctx->unit,stmt->node.item) ) ;
}
else {
#line 140 "src/resolution.z"
if ((stmt->kind== StmtKind_Return)){
#line 140 "src/resolution.z"
resolve_expr(ctx,stmt->node._return) ;
}
;
}
;
}
;
}
;
}

#line 143 "src/resolution.z"
void  resolve_block(ResolutionContext*  ctx, Block*  block) {
#line 145 "src/resolution.z"
push_scope(ctx) ;
#line 146 "src/resolution.z"
#line 146 "src/resolution.z"
u32 i = 0;

#line 147 "src/resolution.z"
while ( (i< block->num_stmts))
{
#line 148 "src/resolution.z"
#line 148 "src/resolution.z"
Stmt*  stmt = block->stmts[i];

#line 149 "src/resolution.z"
if ((stmt->kind== StmtKind_Item)){
#line 150 "src/resolution.z"
#line 150 "src/resolution.z"
Item*  item = unit_get_item(ctx->unit,stmt->node.item) ;

#line 151 "src/resolution.z"
push_ident(ctx,item->ident,stmt->node.item) ;
}
;
#line 153 "src/resolution.z"
i = (i+ 1);
}
;
#line 156 "src/resolution.z"
i = 0;
#line 157 "src/resolution.z"
while ( (i< block->num_stmts))
{
#line 158 "src/resolution.z"
resolve_stmt(ctx,block->stmts[i]) ;
#line 159 "src/resolution.z"
i = (i+ 1);
}
;
#line 161 "src/resolution.z"
pop_scope(ctx) ;
}

#line 164 "src/resolution.z"
void  resolve_body(ResolutionContext*  ctx, Body body) {
#line 165 "src/resolution.z"
resolve_expr(ctx,body.value) ;
}

#line 168 "src/resolution.z"
void  resolve_function(ResolutionContext*  ctx, Item*  item) {
#line 169 "src/resolution.z"
#line 169 "src/resolution.z"
Scope*  scope = &ctx->scope_stack[ctx->stack_top];

#line 170 "src/resolution.z"
#line 170 "src/resolution.z"
FunctionData func = item->node.function;

#line 171 "src/resolution.z"
if (func.body.local){
#line 172 "src/resolution.z"
scope->current_owner = item->id.owner;
#line 173 "src/resolution.z"
push_scope(ctx) ;
#line 174 "src/resolution.z"
#line 174 "src/resolution.z"
u32 i = 0;

#line 175 "src/resolution.z"
while ( (i< func.header.num_parameters))
{
#line 176 "src/resolution.z"
#line 176 "src/resolution.z"
FunctionParameter*  param = &func.header.parameters[i];

#line 177 "src/resolution.z"
param->id.owner = scope->current_owner;
#line 178 "src/resolution.z"
param->id.local = scope->next_local;
#line 179 "src/resolution.z"
scope->next_local = (scope->next_local+ 1);
#line 181 "src/resolution.z"
push_ident(ctx,func.header.parameters[i].ident,param->id) ;
#line 182 "src/resolution.z"
i = (i+ 1);
}
;
#line 185 "src/resolution.z"
resolve_body(ctx,unit_get_body(ctx->unit,item->node.function.body) ) ;
#line 186 "src/resolution.z"
pop_scope(ctx) ;
}
;
}

#line 190 "src/resolution.z"
void  resolve_variable(ResolutionContext*  ctx, Item*  item) {
#line 191 "src/resolution.z"
#line 191 "src/resolution.z"
Scope*  scope = &ctx->scope_stack[ctx->stack_top];

#line 192 "src/resolution.z"
if (item->node.variable.body.local){
#line 193 "src/resolution.z"
scope->current_owner = item->id.owner;
#line 194 "src/resolution.z"
resolve_body(ctx,unit_get_body(ctx->unit,item->node.variable.body) ) ;
}
;
}

#line 198 "src/resolution.z"
void  resolve_mod(ResolutionContext*  ctx, Mod*  module) ;

#line 200 "src/resolution.z"
void  resolve_item(ResolutionContext*  ctx, Item*  item) {
#line 201 "src/resolution.z"
if (((item->kind== ItemKind_Const)|| (item->kind== ItemKind_Variable))){
#line 201 "src/resolution.z"
resolve_variable(ctx,item) ;
}
;
#line 202 "src/resolution.z"
if ((item->kind== ItemKind_Function)){
#line 202 "src/resolution.z"
resolve_function(ctx,item) ;
}
;
#line 203 "src/resolution.z"
if ((item->kind== ItemKind_Mod)){
#line 203 "src/resolution.z"
resolve_mod(ctx,&item->node.module) ;
}
;
}

#line 206 "src/resolution.z"
void  resolve_mod(ResolutionContext*  ctx, Mod*  module) {
#line 207 "src/resolution.z"
#line 207 "src/resolution.z"
u32 i = 0;

#line 208 "src/resolution.z"
while ( (i< module->num_items))
{
#line 209 "src/resolution.z"
#line 209 "src/resolution.z"
Item*  item = unit_get_item(ctx->unit,module->items[i]) ;

#line 210 "src/resolution.z"
scan_item(ctx,item) ;
#line 211 "src/resolution.z"
i = (i+ 1);
}
;
#line 214 "src/resolution.z"
i = 0;
#line 215 "src/resolution.z"
while ( (i< module->num_items))
{
#line 216 "src/resolution.z"
#line 216 "src/resolution.z"
Item*  item = unit_get_item(ctx->unit,module->items[i]) ;

#line 217 "src/resolution.z"
resolve_item(ctx,item) ;
#line 218 "src/resolution.z"
i = (i+ 1);
}
;
}

#line 222 "src/resolution.z"
void  resolve(Session*  sess, CompilationUnit*  unit) {
#line 223 "src/resolution.z"
#line 223 "src/resolution.z"
ResolutionContext ctx ;

#line 225 "src/resolution.z"
ctx.interner = &sess->interner;
#line 226 "src/resolution.z"
ctx.unit = unit;
#line 227 "src/resolution.z"
ctx.scope_stack = malloc((sizeof(Scope) * 128)) ;
#line 228 "src/resolution.z"
ctx.stack_top = 0;
#line 229 "src/resolution.z"
#line 229 "src/resolution.z"
u32 i = 0;

#line 230 "src/resolution.z"
while ( (i< 128))
{
#line 231 "src/resolution.z"
ctx.scope_stack[i].symbols = intmap_create(1024) ;
#line 232 "src/resolution.z"
i = (i+ 1);
}
;
#line 235 "src/resolution.z"
resolve_mod(&ctx,&unit->module) ;
}


typedef struct CodegenContext CodegenContext;
#line 2 "src/codegen.z"
typedef struct CodegenContext {
FILE*  out;
StrMap*  ident_is_ptr;
Session*  sess;
CompilationUnit*  unit;
SourceMap*  source;
} CodegenContext;


#line 10 "src/codegen.z"
void  generate_expr(CodegenContext*  ctx, Expr*  expr) ;

#line 11 "src/codegen.z"
void  generate_block(CodegenContext*  ctx, Block*  block) ;

#line 12 "src/codegen.z"
void  generate_stmt(CodegenContext*  ctx, Stmt*  stmt) ;

#line 13 "src/codegen.z"
void  generate_item(CodegenContext*  ctx, Item*  item) ;

#line 15 "src/codegen.z"
bool type_is_ptr(Type*  ty) {
#line 16 "src/codegen.z"
return (ty->kind== TypeKind_Ptr);
}

#line 19 "src/codegen.z"
void  generate_prelude(CodegenContext*  ctx) {
#line 20 "src/codegen.z"
fprintf(ctx->out,"//Prelude\n") ;
#line 21 "src/codegen.z"
fprintf(ctx->out,"#include <stdint.h>\n") ;
#line 22 "src/codegen.z"
fprintf(ctx->out,"#include <stdbool.h>\n") ;
#line 23 "src/codegen.z"
fprintf(ctx->out,"#include <stdio.h>\n") ;
#line 24 "src/codegen.z"
fprintf(ctx->out,"#include <stdlib.h>\n") ;
#line 25 "src/codegen.z"
fprintf(ctx->out,"#include <string.h>\n") ;
#line 26 "src/codegen.z"
fprintf(ctx->out,"typedef uint8_t u8;\n") ;
#line 27 "src/codegen.z"
fprintf(ctx->out,"typedef uint16_t u16;\n") ;
#line 28 "src/codegen.z"
fprintf(ctx->out,"typedef uint32_t u32;\n") ;
#line 29 "src/codegen.z"
fprintf(ctx->out,"typedef uint64_t u64;\n") ;
#line 30 "src/codegen.z"
fprintf(ctx->out,"typedef int8_t i8;\n") ;
#line 31 "src/codegen.z"
fprintf(ctx->out,"typedef int16_t i16;\n") ;
#line 32 "src/codegen.z"
fprintf(ctx->out,"typedef int32_t i32;\n") ;
#line 33 "src/codegen.z"
fprintf(ctx->out,"typedef int64_t i64;\n") ;
#line 34 "src/codegen.z"
fprintf(ctx->out,"typedef float f32;\n") ;
#line 35 "src/codegen.z"
fprintf(ctx->out,"typedef double f64;\n") ;
#line 36 "src/codegen.z"
fprintf(ctx->out,"typedef const char constchar;\n") ;
#line 37 "src/codegen.z"
fprintf(ctx->out,"typedef const void constvoid;\n") ;
#line 38 "src/codegen.z"
fprintf(ctx->out,"#define null 0ul\n") ;
}

#line 41 "src/codegen.z"
void  generate_sid(CodegenContext*  ctx, Sid sid) {
#line 42 "src/codegen.z"
#line 42 "src/codegen.z"
Session*  sess = ctx->sess;

#line 43 "src/codegen.z"
fprintf(ctx->out,"%s",get_str(&sess->interner,sid) ) ;
}

#line 46 "src/codegen.z"
void  generate_identifier(CodegenContext*  ctx, Ident ident) {
#line 47 "src/codegen.z"
generate_sid(ctx,ident.name) ;
}

#line 50 "src/codegen.z"
void  generate_type(CodegenContext*  ctx, Type*  ty) {
#line 51 "src/codegen.z"
if ((ty->kind== TypeKind_Path)){
#line 51 "src/codegen.z"
generate_sid(ctx,ty->node.path) ;
}
else {
#line 52 "src/codegen.z"
if ((ty->kind== TypeKind_Ptr)){
#line 53 "src/codegen.z"
generate_type(ctx,ty->node.ptr) ;
#line 54 "src/codegen.z"
fprintf(ctx->out,"* ") ;
}
else {
#line 56 "src/codegen.z"
if ((ty->kind== TypeKind_Unit)){
#line 57 "src/codegen.z"
fprintf(ctx->out,"void ") ;
}
else {
#line 59 "src/codegen.z"
abort() ;
}
;
}
;
}
;
}

#line 62 "src/codegen.z"
void  generate_char(CodegenContext*  ctx, char c) {
#line 63 "src/codegen.z"
if ((c== '\n')){
#line 63 "src/codegen.z"
fprintf(ctx->out,"'\\n'") ;
}
else {
#line 64 "src/codegen.z"
if ((c== '\t')){
#line 64 "src/codegen.z"
fprintf(ctx->out,"'\\t'") ;
}
else {
#line 65 "src/codegen.z"
if ((c== '\r')){
#line 65 "src/codegen.z"
fprintf(ctx->out,"'\\r'") ;
}
else {
#line 66 "src/codegen.z"
if ((c== '\\')){
#line 66 "src/codegen.z"
fprintf(ctx->out,"'\\\\'") ;
}
else {
#line 67 "src/codegen.z"
if ((c== '\'')){
#line 67 "src/codegen.z"
fprintf(ctx->out,"'\\''") ;
}
else {
#line 68 "src/codegen.z"
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

#line 71 "src/codegen.z"
void  generate_literal(CodegenContext*  ctx, Literal lit) {
#line 72 "src/codegen.z"
if ((lit.kind== LiteralKind_Int)){
#line 72 "src/codegen.z"
fprintf(ctx->out,"%ld",lit.value.integer) ;
}
else {
#line 73 "src/codegen.z"
if ((lit.kind== LiteralKind_Float)){
#line 73 "src/codegen.z"
fprintf(ctx->out,"%f",lit.value.floating) ;
}
else {
#line 74 "src/codegen.z"
if ((lit.kind== LiteralKind_Bool)){
#line 74 "src/codegen.z"
if (lit.value.boolean){
#line 74 "src/codegen.z"
fprintf(ctx->out,"true") ;
}
else {
#line 74 "src/codegen.z"
fprintf(ctx->out,"false") ;
}
;
}
else {
#line 75 "src/codegen.z"
if ((lit.kind== LiteralKind_Str)){
#line 76 "src/codegen.z"
#line 76 "src/codegen.z"
Session*  sess = ctx->sess;

#line 77 "src/codegen.z"
fprintf(ctx->out,"\"%s\"",get_str(&sess->interner,lit.value.str) ) ;
}
else {
#line 79 "src/codegen.z"
if ((lit.kind== LiteralKind_Char)){
#line 79 "src/codegen.z"
generate_char(ctx,lit.value.ch) ;
}
else {
#line 80 "src/codegen.z"
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

#line 83 "src/codegen.z"
void  generate_body(CodegenContext*  ctx, Body body) {
#line 84 "src/codegen.z"
generate_expr(ctx,body.value) ;
}

#line 87 "src/codegen.z"
void  generate_unary(CodegenContext*  ctx, UnaryData unary) {
#line 88 "src/codegen.z"
if ((unary.op== UnaryOperatorKind_Negation)){
#line 88 "src/codegen.z"
fprintf(ctx->out,"-") ;
}
else {
#line 89 "src/codegen.z"
if ((unary.op== UnaryOperatorKind_Complement)){
#line 89 "src/codegen.z"
fprintf(ctx->out,"!") ;
}
else {
#line 90 "src/codegen.z"
if ((unary.op== UnaryOperatorKind_Refer)){
#line 90 "src/codegen.z"
fprintf(ctx->out,"&") ;
}
else {
#line 91 "src/codegen.z"
if ((unary.op== UnaryOperatorKind_Deref)){
#line 91 "src/codegen.z"
fprintf(ctx->out,"*") ;
}
else {
#line 92 "src/codegen.z"
abort() ;
}
;
}
;
}
;
}
;
#line 94 "src/codegen.z"
generate_expr(ctx,unary.inner) ;
}

#line 97 "src/codegen.z"
void  generate_binary(CodegenContext*  ctx, BinaryData binary) {
#line 98 "src/codegen.z"
fprintf(ctx->out,"(") ;
#line 99 "src/codegen.z"
generate_expr(ctx,binary.left) ;
#line 100 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Addition)){
#line 100 "src/codegen.z"
fprintf(ctx->out,"+ ") ;
}
else {
#line 101 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Subtraction)){
#line 101 "src/codegen.z"
fprintf(ctx->out,"- ") ;
}
else {
#line 102 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Product)){
#line 102 "src/codegen.z"
fprintf(ctx->out,"* ") ;
}
else {
#line 103 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Division)){
#line 103 "src/codegen.z"
fprintf(ctx->out,"/ ") ;
}
else {
#line 104 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Modulus)){
#line 104 "src/codegen.z"
fprintf(ctx->out,"%% ") ;
}
else {
#line 106 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Less)){
#line 106 "src/codegen.z"
fprintf(ctx->out,"< ") ;
}
else {
#line 107 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_LessEq)){
#line 107 "src/codegen.z"
fprintf(ctx->out,"<= ") ;
}
else {
#line 108 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Greater)){
#line 108 "src/codegen.z"
fprintf(ctx->out,"> ") ;
}
else {
#line 109 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_GreaterEq)){
#line 109 "src/codegen.z"
fprintf(ctx->out,">= ") ;
}
else {
#line 110 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Equality)){
#line 110 "src/codegen.z"
fprintf(ctx->out,"== ") ;
}
else {
#line 111 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_NotEq)){
#line 111 "src/codegen.z"
fprintf(ctx->out,"!= ") ;
}
else {
#line 113 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_BAnd)){
#line 113 "src/codegen.z"
fprintf(ctx->out,"& ") ;
}
else {
#line 114 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_BOr)){
#line 114 "src/codegen.z"
fprintf(ctx->out,"| ") ;
}
else {
#line 115 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Xor)){
#line 115 "src/codegen.z"
fprintf(ctx->out,"^ ") ;
}
else {
#line 116 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_LeftShift)){
#line 116 "src/codegen.z"
fprintf(ctx->out,"<< ") ;
}
else {
#line 117 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_RightShift)){
#line 117 "src/codegen.z"
fprintf(ctx->out,">> ") ;
}
else {
#line 119 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_And)){
#line 119 "src/codegen.z"
fprintf(ctx->out,"&& ") ;
}
else {
#line 120 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Or)){
#line 120 "src/codegen.z"
fprintf(ctx->out,"|| ") ;
}
else {
#line 121 "src/codegen.z"
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
#line 122 "src/codegen.z"
generate_expr(ctx,binary.right) ;
#line 123 "src/codegen.z"
fprintf(ctx->out,")") ;
}

#line 126 "src/codegen.z"
void  generate_call(CodegenContext*  ctx, CallData call) {
#line 127 "src/codegen.z"
generate_expr(ctx,call.func) ;
#line 129 "src/codegen.z"
fprintf(ctx->out,"(") ;
#line 130 "src/codegen.z"
#line 130 "src/codegen.z"
u32 i = 0;

#line 131 "src/codegen.z"
while ( (i< call.num_args))
{
#line 132 "src/codegen.z"
#line 132 "src/codegen.z"
Expr*  arg = call.args[i];

#line 133 "src/codegen.z"
generate_expr(ctx,arg) ;
#line 134 "src/codegen.z"
if ((i< (call.num_args- 1))){
#line 134 "src/codegen.z"
fprintf(ctx->out,",") ;
}
;
#line 135 "src/codegen.z"
i = (i+ 1);
}
;
#line 137 "src/codegen.z"
fprintf(ctx->out,") ") ;
}

#line 140 "src/codegen.z"
void  generate_conditional(CodegenContext*  ctx, ConditionalData cond) {
#line 141 "src/codegen.z"
fprintf(ctx->out,"if (") ;
#line 142 "src/codegen.z"
generate_expr(ctx,cond.condition) ;
#line 143 "src/codegen.z"
fprintf(ctx->out,")") ;
#line 144 "src/codegen.z"
generate_expr(ctx,cond.then) ;
#line 145 "src/codegen.z"
if (cond.otherwise){
#line 146 "src/codegen.z"
fprintf(ctx->out,"else ") ;
#line 147 "src/codegen.z"
generate_expr(ctx,cond.otherwise) ;
}
;
}

#line 151 "src/codegen.z"
void  generate_while(CodegenContext*  ctx, WhileData data) {
#line 152 "src/codegen.z"
fprintf(ctx->out,"while ( ") ;
#line 153 "src/codegen.z"
generate_expr(ctx,data.condition) ;
#line 154 "src/codegen.z"
fprintf(ctx->out,")\n") ;
#line 155 "src/codegen.z"
generate_expr(ctx,data.body) ;
}

#line 158 "src/codegen.z"
void  generate_indexing(CodegenContext*  ctx, IndexingData idx) {
#line 159 "src/codegen.z"
generate_expr(ctx,idx.array) ;
#line 160 "src/codegen.z"
fprintf(ctx->out,"[") ;
#line 161 "src/codegen.z"
generate_expr(ctx,idx.index) ;
#line 162 "src/codegen.z"
fprintf(ctx->out,"]") ;
}

#line 165 "src/codegen.z"
void  generate_field(CodegenContext*  ctx, FieldData field) {
#line 166 "src/codegen.z"
#line 166 "src/codegen.z"
Expr*  strct = field.strct;

#line 167 "src/codegen.z"
generate_expr(ctx,strct) ;
#line 169 "src/codegen.z"
#line 169 "src/codegen.z"
Session*  sess = ctx->sess;

#line 170 "src/codegen.z"
#line 170 "src/codegen.z"
char*  field_name = get_str(&sess->interner,field.ident.name) ;

#line 172 "src/codegen.z"
#line 172 "src/codegen.z"
bool is_ptr = false;

#line 173 "src/codegen.z"
#line 173 "src/codegen.z"
char*  accessor_str ;

#line 174 "src/codegen.z"
if ((strct->kind== ExprKind_Path)){
#line 175 "src/codegen.z"
#line 175 "src/codegen.z"
char*  strct_name = get_str(&sess->interner,strct->node.path.segments[0].name) ;

#line 176 "src/codegen.z"
is_ptr = strmap_lookup(ctx->ident_is_ptr,strct_name) ;
}
;
#line 179 "src/codegen.z"
if (is_ptr){
#line 179 "src/codegen.z"
accessor_str = "->";
}
else {
#line 180 "src/codegen.z"
accessor_str = ".";
}
;
#line 181 "src/codegen.z"
fprintf(ctx->out,"%s%s",accessor_str,field_name) ;
}

#line 184 "src/codegen.z"
void  generate_path(CodegenContext*  ctx, Path path) {
#line 185 "src/codegen.z"
#line 185 "src/codegen.z"
u32 i = 0;

#line 186 "src/codegen.z"
while ( (i< path.num_segments))
{
#line 187 "src/codegen.z"
generate_identifier(ctx,path.segments[i]) ;
#line 188 "src/codegen.z"
if ((i< (path.num_segments- 1))){
#line 188 "src/codegen.z"
fprintf(ctx->out,"_") ;
}
;
#line 189 "src/codegen.z"
i = (i+ 1);
}
;
}

#line 193 "src/codegen.z"
void  generate_expr(CodegenContext*  ctx, Expr*  expr) {
#line 194 "src/codegen.z"
if ((expr->kind== ExprKind_Unary)){
#line 194 "src/codegen.z"
generate_unary(ctx,expr->node.unary) ;
}
else {
#line 195 "src/codegen.z"
if ((expr->kind== ExprKind_Binary)){
#line 195 "src/codegen.z"
generate_binary(ctx,expr->node.binary) ;
}
else {
#line 196 "src/codegen.z"
if ((expr->kind== ExprKind_Block)){
#line 196 "src/codegen.z"
generate_block(ctx,expr->node.block) ;
}
else {
#line 197 "src/codegen.z"
if ((expr->kind== ExprKind_Call)){
#line 197 "src/codegen.z"
generate_call(ctx,expr->node.call) ;
}
else {
#line 198 "src/codegen.z"
if ((expr->kind== ExprKind_Conditional)){
#line 198 "src/codegen.z"
generate_conditional(ctx,expr->node.conditional) ;
}
else {
#line 199 "src/codegen.z"
if ((expr->kind== ExprKind_While)){
#line 199 "src/codegen.z"
generate_while(ctx,expr->node.whl) ;
}
else {
#line 200 "src/codegen.z"
if ((expr->kind== ExprKind_Indexing)){
#line 200 "src/codegen.z"
generate_indexing(ctx,expr->node.indexing) ;
}
else {
#line 201 "src/codegen.z"
if ((expr->kind== ExprKind_Field)){
#line 201 "src/codegen.z"
generate_field(ctx,expr->node.field) ;
}
else {
#line 202 "src/codegen.z"
if ((expr->kind== ExprKind_Literal)){
#line 202 "src/codegen.z"
generate_literal(ctx,expr->node.lit) ;
}
else {
#line 203 "src/codegen.z"
if ((expr->kind== ExprKind_Path)){
#line 203 "src/codegen.z"
generate_path(ctx,expr->node.path) ;
}
else {
#line 204 "src/codegen.z"
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

#line 207 "src/codegen.z"
void  generate_assignment(CodegenContext*  ctx, AssignmentData assignment) {
#line 208 "src/codegen.z"
generate_expr(ctx,assignment.left) ;
#line 209 "src/codegen.z"
fprintf(ctx->out," = ") ;
#line 210 "src/codegen.z"
generate_expr(ctx,assignment.right) ;
#line 211 "src/codegen.z"
fprintf(ctx->out,";\n") ;
}

#line 214 "src/codegen.z"
void  generate_return(CodegenContext*  ctx, Expr*  expr) {
#line 215 "src/codegen.z"
fprintf(ctx->out,"return ") ;
#line 216 "src/codegen.z"
generate_expr(ctx,expr) ;
#line 217 "src/codegen.z"
fprintf(ctx->out,";\n") ;
}

#line 220 "src/codegen.z"
void  generate_stmt(CodegenContext*  ctx, Stmt*  stmt) {
#line 221 "src/codegen.z"
emit_line_directive(ctx->out,ctx->source,stmt->span) ;
#line 222 "src/codegen.z"
if ((stmt->kind== StmtKind_Assignment)){
#line 222 "src/codegen.z"
generate_assignment(ctx,stmt->node.assignment) ;
}
else {
#line 223 "src/codegen.z"
if ((stmt->kind== StmtKind_Break)){
#line 223 "src/codegen.z"
fprintf(ctx->out,"break;\n") ;
}
else {
#line 224 "src/codegen.z"
if ((stmt->kind== StmtKind_Continue)){
#line 224 "src/codegen.z"
fprintf(ctx->out,"continue;\n") ;
}
else {
#line 225 "src/codegen.z"
if ((stmt->kind== StmtKind_Expr)){
#line 225 "src/codegen.z"
generate_expr(ctx,stmt->node.expr) ;
#line 225 "src/codegen.z"
fprintf(ctx->out,";\n") ;
}
else {
#line 226 "src/codegen.z"
if ((stmt->kind== StmtKind_Item)){
#line 226 "src/codegen.z"
generate_item(ctx,unit_get_item(ctx->unit,stmt->node.item) ) ;
}
else {
#line 227 "src/codegen.z"
if ((stmt->kind== StmtKind_Return)){
#line 227 "src/codegen.z"
generate_return(ctx,stmt->node._return) ;
}
else {
#line 228 "src/codegen.z"
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

#line 231 "src/codegen.z"
void  generate_block(CodegenContext*  ctx, Block*  block) {
#line 232 "src/codegen.z"
fprintf(ctx->out,"{\n") ;
#line 233 "src/codegen.z"
#line 233 "src/codegen.z"
u32 i = 0;

#line 235 "src/codegen.z"
while ( (i< block->num_stmts))
{
#line 236 "src/codegen.z"
generate_stmt(ctx,block->stmts[i]) ;
#line 237 "src/codegen.z"
i = (i+ 1);
}
;
#line 239 "src/codegen.z"
fprintf(ctx->out,"}\n") ;
}

#line 242 "src/codegen.z"
void  generate_variable(CodegenContext*  ctx, Item*  item) {
#line 244 "src/codegen.z"
emit_line_directive(ctx->out,ctx->source,item->span) ;
#line 246 "src/codegen.z"
generate_type(ctx,item->node.variable.ty) ;
#line 248 "src/codegen.z"
#line 248 "src/codegen.z"
Session*  sess = ctx->sess;

#line 249 "src/codegen.z"
#line 249 "src/codegen.z"
char*  var_name = get_str(&sess->interner,item->ident.name) ;

#line 251 "src/codegen.z"
strmap_insert(ctx->ident_is_ptr,var_name,type_is_ptr(item->node.variable.ty) ) ;
#line 252 "src/codegen.z"
fprintf(ctx->out," %s ",var_name) ;
#line 253 "src/codegen.z"
if (item->node.variable.body.local){
#line 254 "src/codegen.z"
fprintf(ctx->out,"= ") ;
#line 255 "src/codegen.z"
generate_body(ctx,unit_get_body(ctx->unit,item->node.variable.body) ) ;
}
;
#line 257 "src/codegen.z"
fprintf(ctx->out,";\n") ;
}

#line 260 "src/codegen.z"
void  generate_function(CodegenContext*  ctx, Item*  item) {
#line 262 "src/codegen.z"
emit_line_directive(ctx->out,ctx->source,item->span) ;
#line 264 "src/codegen.z"
#line 264 "src/codegen.z"
FunctionData func = item->node.function;

#line 265 "src/codegen.z"
#line 265 "src/codegen.z"
FunctionHeader header = func.header;

#line 266 "src/codegen.z"
generate_type(ctx,header.output) ;
#line 268 "src/codegen.z"
#line 268 "src/codegen.z"
Session*  sess = ctx->sess;

#line 269 "src/codegen.z"
#line 269 "src/codegen.z"
char*  func_name = get_str(&sess->interner,item->ident.name) ;

#line 271 "src/codegen.z"
fprintf(ctx->out," %s(",func_name) ;
#line 273 "src/codegen.z"
#line 273 "src/codegen.z"
u32 i = 0;

#line 274 "src/codegen.z"
while ( (i< header.num_parameters))
{
#line 275 "src/codegen.z"
#line 275 "src/codegen.z"
Type*  ty = header.parameters[i].ty;

#line 276 "src/codegen.z"
if ((ty->kind== TypeKind_Variadic)){
#line 277 "src/codegen.z"
fprintf(ctx->out,"...") ;
#line 278 "src/codegen.z"
break;
}
;
#line 281 "src/codegen.z"
generate_type(ctx,ty) ;
#line 283 "src/codegen.z"
#line 283 "src/codegen.z"
char*  param_name = get_str(&sess->interner,header.parameters[i].ident.name) ;

#line 284 "src/codegen.z"
strmap_insert(ctx->ident_is_ptr,param_name,type_is_ptr(header.parameters[i].ty) ) ;
#line 285 "src/codegen.z"
fprintf(ctx->out," %s",param_name) ;
#line 286 "src/codegen.z"
if ((i< (header.num_parameters- 1))){
#line 286 "src/codegen.z"
fprintf(ctx->out,", ") ;
}
;
#line 287 "src/codegen.z"
i = (i+ 1);
}
;
#line 289 "src/codegen.z"
fprintf(ctx->out,") ") ;
#line 290 "src/codegen.z"
if (func.body.local){
#line 290 "src/codegen.z"
generate_body(ctx,unit_get_body(ctx->unit,func.body) ) ;
}
else {
#line 291 "src/codegen.z"
fprintf(ctx->out,";\n") ;
}
;
}

#line 294 "src/codegen.z"
void  generate_enum(CodegenContext*  ctx, Item*  item) {
#line 296 "src/codegen.z"
#line 296 "src/codegen.z"
Session*  sess = ctx->sess;

#line 297 "src/codegen.z"
#line 297 "src/codegen.z"
char*  enum_name = get_str(&sess->interner,item->ident.name) ;

#line 299 "src/codegen.z"
emit_line_directive(ctx->out,ctx->source,item->span) ;
#line 300 "src/codegen.z"
fprintf(ctx->out,"typedef enum %s {\n",enum_name) ;
#line 301 "src/codegen.z"
#line 301 "src/codegen.z"
u32 i = 0;

#line 303 "src/codegen.z"
#line 303 "src/codegen.z"
EnumData data = item->node._enum;

#line 305 "src/codegen.z"
while ( (i< data.num_variants))
{
#line 306 "src/codegen.z"
#line 306 "src/codegen.z"
char*  variant_name = get_str(&sess->interner,data.variants[i].ident.name) ;

#line 307 "src/codegen.z"
fprintf(ctx->out,"%s_%s,\n",enum_name,variant_name) ;
#line 308 "src/codegen.z"
i = (i+ 1);
}
;
#line 310 "src/codegen.z"
fprintf(ctx->out,"} %s;\n\n",enum_name) ;
}

#line 313 "src/codegen.z"
void  generate_compound(CodegenContext*  ctx, Item*  item) {
#line 315 "src/codegen.z"
#line 315 "src/codegen.z"
Session*  sess = ctx->sess;

#line 316 "src/codegen.z"
#line 316 "src/codegen.z"
char*  compound_name = get_str(&sess->interner,item->ident.name) ;

#line 318 "src/codegen.z"
#line 318 "src/codegen.z"
char*  compound_kind ;

#line 319 "src/codegen.z"
if ((item->kind== ItemKind_Struct)){
#line 319 "src/codegen.z"
compound_kind = "struct";
}
else {
#line 320 "src/codegen.z"
compound_kind = "union";
}
;
#line 322 "src/codegen.z"
#line 322 "src/codegen.z"
CompoundData data = item->node.compound;

#line 324 "src/codegen.z"
fprintf(ctx->out,"typedef %s %s %s;\n",compound_kind,compound_name,compound_name) ;
#line 326 "src/codegen.z"
emit_line_directive(ctx->out,ctx->source,item->span) ;
#line 327 "src/codegen.z"
if ((data.num_fields> 0)){
#line 328 "src/codegen.z"
fprintf(ctx->out,"typedef %s %s {\n",compound_kind,compound_name) ;
#line 329 "src/codegen.z"
#line 329 "src/codegen.z"
u32 i = 0;

#line 330 "src/codegen.z"
while ( (i< data.num_fields))
{
#line 331 "src/codegen.z"
generate_type(ctx,data.fields[i].ty) ;
#line 333 "src/codegen.z"
#line 333 "src/codegen.z"
char*  field_name = get_str(&sess->interner,data.fields[i].ident.name) ;

#line 334 "src/codegen.z"
fprintf(ctx->out," %s;\n",field_name) ;
#line 335 "src/codegen.z"
i = (i+ 1);
}
;
#line 337 "src/codegen.z"
fprintf(ctx->out,"} %s;\n\n",compound_name) ;
}
;
}

#line 341 "src/codegen.z"
void  generate_mod(CodegenContext*  ctx, Mod*  module) {
#line 342 "src/codegen.z"
#line 342 "src/codegen.z"
u32 i = 0;

#line 343 "src/codegen.z"
while ( (i< module->num_items))
{
#line 344 "src/codegen.z"
#line 344 "src/codegen.z"
Item*  item = unit_get_item(ctx->unit,module->items[i]) ;

#line 345 "src/codegen.z"
generate_item(ctx,item) ;
#line 346 "src/codegen.z"
i = (i+ 1);
}
;
}

#line 350 "src/codegen.z"
void  generate_item(CodegenContext*  ctx, Item*  item) {
#line 352 "src/codegen.z"
if (((item->kind== ItemKind_Const)|| (item->kind== ItemKind_Variable))){
#line 352 "src/codegen.z"
generate_variable(ctx,item) ;
}
else {
#line 353 "src/codegen.z"
if ((item->kind== ItemKind_Enum)){
#line 353 "src/codegen.z"
generate_enum(ctx,item) ;
}
else {
#line 354 "src/codegen.z"
if ((item->kind== ItemKind_Function)){
#line 354 "src/codegen.z"
generate_function(ctx,item) ;
}
else {
#line 355 "src/codegen.z"
if (((item->kind== ItemKind_Struct)|| (item->kind== ItemKind_Union))){
#line 355 "src/codegen.z"
generate_compound(ctx,item) ;
}
else {
#line 356 "src/codegen.z"
if ((item->kind== ItemKind_Mod)){
#line 356 "src/codegen.z"
generate_mod(ctx,&item->node.module) ;
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
#line 357 "src/codegen.z"
fprintf(ctx->out,"\n") ;
}

#line 360 "src/codegen.z"
void  generate(Session*  sess, CompilationUnit unit, char*  output_file) {
#line 361 "src/codegen.z"
#line 361 "src/codegen.z"
CodegenContext ctx ;

#line 363 "src/codegen.z"
ctx.out = fopen(output_file,"w") ;
#line 364 "src/codegen.z"
ctx.ident_is_ptr = strmap_create(1024) ;
#line 365 "src/codegen.z"
ctx.sess = sess;
#line 366 "src/codegen.z"
ctx.source = &sess->source;
#line 367 "src/codegen.z"
ctx.unit = &unit;
#line 369 "src/codegen.z"
generate_prelude(&ctx) ;
#line 371 "src/codegen.z"
generate_mod(&ctx,&unit.module) ;
}


#line 16 "src/main.z"
char*  basename(char*  path) ;

#line 17 "src/main.z"
char*  dirname(char*  path) ;

#line 19 "src/main.z"
int main(int argc, char* *  argv) {
#line 20 "src/main.z"
if ((argc!= 3)){
#line 21 "src/main.z"
printf("Usage: compiler INPUT OUTPUT\n") ;
#line 22 "src/main.z"
abort() ;
}
;
#line 25 "src/main.z"
#line 25 "src/main.z"
Session sess ;

#line 28 "src/main.z"
sess.interner = interner_create() ;
#line 29 "src/main.z"
sess.source = source_map_create() ;
#line 30 "src/main.z"
#line 30 "src/main.z"
char*  root_module = basename(argv[1]) ;

#line 31 "src/main.z"
sess.root_path = dirname(argv[1]) ;
#line 33 "src/main.z"
#line 33 "src/main.z"
CompilationUnit unit = parse(&sess,root_module) ;

#line 35 "src/main.z"
resolve(&sess,&unit) ;
#line 37 "src/main.z"
generate(&sess,unit,argv[2]) ;
#line 39 "src/main.z"
return 0;
}

