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

typedef struct FILE FILE;
#line 18 "src/cstd.z"

#line 20 "src/cstd.z"
FILE*  fopen(constchar*  filename, constchar*  mode) ;

#line 21 "src/cstd.z"
i32 fclose(FILE*  stream) ;

#line 23 "src/cstd.z"
u64 fread(void*  buffer, u64 size, u64 count, FILE*  stream) ;

#line 24 "src/cstd.z"
u64 fwrite(constvoid*  buffer, u64 size, u64 count, FILE*  stream) ;

#line 26 "src/cstd.z"
i32 fseek(FILE*  stream, i64 offset, i32 origin) ;

#line 27 "src/cstd.z"
void  rewind(FILE*  stream) ;

#line 28 "src/cstd.z"
i64 ftell(FILE*  stream) ;

#line 30 "src/cstd.z"
i32 SEEK_SET = 0;

#line 31 "src/cstd.z"
i32 SEEK_CUR = 1;

#line 32 "src/cstd.z"
i32 SEEK_END = 2;

#line 34 "src/cstd.z"
i32 printf(constchar*  format, ...) ;

#line 35 "src/cstd.z"
i32 fprintf(FILE*  stream, constchar*  format, ...) ;

#line 36 "src/cstd.z"
i32 sprintf(char*  buffer, constchar*  format, ...) ;

#line 38 "src/cstd.z"
void*  null = 0;

#line 39 "src/cstd.z"
i32 EOF = -1;


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
IntMap*  map = malloc(sizeof(IntMap)) ;
;
#line 12 "src/intmap.z"
map->size = size;
;
#line 13 "src/intmap.z"
map->load = 0;
;
#line 14 "src/intmap.z"
map->keys = malloc((size* 8)) ;
;
#line 15 "src/intmap.z"
map->values = malloc((size* 8)) ;
;
#line 17 "src/intmap.z"
u32 i = 0;
;
#line 18 "src/intmap.z"
while ( (i< size))
{
#line 19 "src/intmap.z"
map->keys[i] = 0;
;
#line 20 "src/intmap.z"
map->values[i] = 0;
;
#line 21 "src/intmap.z"
i = (i+ 1);
;
}
;
#line 24 "src/intmap.z"
return map;
;
}

#line 27 "src/intmap.z"
u64 intmap_hash(u64 k) {
#line 28 "src/intmap.z"
if ((k!= 0)){
#line 28 "src/intmap.z"
return k;
;
}
else {
#line 29 "src/intmap.z"
return 1;
;
}
;
}

#line 32 "src/intmap.z"
void  intmap_reset(IntMap*  map) {
#line 33 "src/intmap.z"
map->load = 0;
;
#line 34 "src/intmap.z"
memset(map->keys,0,(sizeof(map->size)* 8)) ;
#line 35 "src/intmap.z"
memset(map->values,0,(sizeof(map->size)* 8)) ;
}

#line 38 "src/intmap.z"
void  intmap_insert(IntMap*  map, u64 key, u64 value) {
#line 39 "src/intmap.z"
u64 h = (intmap_hash(key) % map->size);
;
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
;
#line 47 "src/intmap.z"
break;
;
}
else {
#line 48 "src/intmap.z"
if ((map->keys[h]== 0)){
#line 49 "src/intmap.z"
map->keys[h] = key;
;
#line 50 "src/intmap.z"
map->values[h] = value;
;
#line 51 "src/intmap.z"
map->load = (map->load+ 1);
;
#line 52 "src/intmap.z"
break;
;
}
else {
#line 54 "src/intmap.z"
h = ((h+ 1)% map->size);
;
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
u64 h = (intmap_hash(key) % map->size);
;
#line 61 "src/intmap.z"
while ( true)
{
#line 62 "src/intmap.z"
if ((map->keys[h]== 0)){
#line 62 "src/intmap.z"
return 0;
;
}
;
#line 63 "src/intmap.z"
if ((map->keys[h]== key)){
#line 64 "src/intmap.z"
return map->values[h];
;
}
;
#line 66 "src/intmap.z"
h = ((h+ 1)% map->size);
;
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
StrMap*  map = malloc(sizeof(StrMap)) ;
;
#line 12 "src/strmap.z"
map->size = size;
;
#line 13 "src/strmap.z"
map->load = 0;
;
#line 14 "src/strmap.z"
map->keys = malloc((size* 8)) ;
;
#line 15 "src/strmap.z"
map->values = malloc((size* 4)) ;
;
#line 17 "src/strmap.z"
u32 i = 0;
;
#line 18 "src/strmap.z"
while ( (i< size))
{
#line 19 "src/strmap.z"
map->keys[i] = 0;
;
#line 20 "src/strmap.z"
map->values[i] = 0;
;
#line 21 "src/strmap.z"
i = (i+ 1);
;
}
;
#line 24 "src/strmap.z"
return map;
;
}

#line 27 "src/strmap.z"
u32 strmap_hash(char*  s) {
#line 28 "src/strmap.z"
u32 hash = 5381;
;
#line 29 "src/strmap.z"
i32 c = *s;
;
#line 30 "src/strmap.z"
while ( (c!= 0))
{
#line 31 "src/strmap.z"
hash = (((hash<< 5)+ hash)+ c);
;
#line 32 "src/strmap.z"
s = (s+ 1);
;
#line 33 "src/strmap.z"
c = *s;
;
}
;
#line 35 "src/strmap.z"
if ((hash!= 0)){
#line 35 "src/strmap.z"
return hash;
;
}
else {
#line 36 "src/strmap.z"
return 1;
;
}
;
}

#line 39 "src/strmap.z"
void  strmap_insert(StrMap*  map, char*  key, u32 value) {
#line 40 "src/strmap.z"
u32 h = (strmap_hash(key) % map->size);
;
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
if (((map->keys[h]!= 0)&& !strcmp(map->keys[h],key) )){
#line 47 "src/strmap.z"
map->values[h] = value;
;
#line 48 "src/strmap.z"
break;
;
}
else {
#line 49 "src/strmap.z"
if ((map->keys[h]== 0)){
#line 50 "src/strmap.z"
map->keys[h] = key;
;
#line 51 "src/strmap.z"
map->values[h] = value;
;
#line 52 "src/strmap.z"
map->load = (map->load+ 1);
;
#line 53 "src/strmap.z"
break;
;
}
else {
#line 55 "src/strmap.z"
h = ((h+ 1)% map->size);
;
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
u32 h = (strmap_hash(key) % map->size);
;
#line 62 "src/strmap.z"
while ( true)
{
#line 63 "src/strmap.z"
if ((map->keys[h]== 0)){
#line 63 "src/strmap.z"
return 0;
;
}
;
#line 64 "src/strmap.z"
if (!strcmp(map->keys[h],key) ){
#line 65 "src/strmap.z"
return map->values[h];
;
}
;
#line 67 "src/strmap.z"
h = ((h+ 1)% map->size);
;
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
SourceMap map ;
;
#line 24 "src/source_map.z"
map.files = calloc(sizeof(SourceFile),16) ;
;
#line 25 "src/source_map.z"
map.num_files = 0;
;
#line 26 "src/source_map.z"
map.file_starts = calloc(sizeof(u32),16) ;
;
#line 28 "src/source_map.z"
return map;
;
}

#line 31 "src/source_map.z"
void  load_file_content(SourceFile*  file) {
#line 32 "src/source_map.z"
FILE*  fp = fopen(file->name,"rb") ;
;
#line 33 "src/source_map.z"
fseek(fp,0,SEEK_END) ;
#line 34 "src/source_map.z"
file->length = ftell(fp) ;
;
#line 35 "src/source_map.z"
rewind(fp) ;
#line 36 "src/source_map.z"
file->content = malloc(file->length) ;
;
#line 37 "src/source_map.z"
fread(file->content,1,file->length,fp) ;
#line 38 "src/source_map.z"
fclose(fp) ;
}

#line 41 "src/source_map.z"
SourceFile*  source_map_new_file(SourceMap*  self, char*  path, char*  filename) {
#line 42 "src/source_map.z"
SourceFile*  file = &self->files[self->num_files];
;
#line 43 "src/source_map.z"
self->num_files = (self->num_files+ 1);
;
#line 45 "src/source_map.z"
u32 needed_length = ((strlen(path) + strlen(filename) )+ 4);
;
#line 47 "src/source_map.z"
char*  name_buffer = malloc(needed_length) ;
;
#line 49 "src/source_map.z"
sprintf(name_buffer,"%s/%s.z",path,filename) ;
#line 51 "src/source_map.z"
file->name = name_buffer;
;
#line 52 "src/source_map.z"
file->lines = calloc(sizeof(u32),4096) ;
;
#line 53 "src/source_map.z"
file->num_lines = 1;
;
#line 55 "src/source_map.z"
if ((self->num_files> 1)){
#line 55 "src/source_map.z"
file->start = self->files[(self->num_files- 2)].end;
;
}
else {
#line 56 "src/source_map.z"
file->start = 0;
;
}
;
#line 58 "src/source_map.z"
self->file_starts[(self->num_files- 1)] = file->start;
;
#line 60 "src/source_map.z"
load_file_content(file) ;
#line 62 "src/source_map.z"
return file;
;
}

#line 65 "src/source_map.z"
void  source_file_newline(SourceFile*  self, u32 position) {
#line 66 "src/source_map.z"
self->lines[self->num_lines] = (self->start+ position);
;
#line 67 "src/source_map.z"
self->num_lines = (self->num_lines+ 1);
;
}

#line 70 "src/source_map.z"
void  source_file_done(SourceFile*  self, u32 length) {
#line 71 "src/source_map.z"
self->end = (self->start+ length);
;
}

#line 74 "src/source_map.z"
SourceFile*  source_map_info(SourceMap*  m, Span span, u32*  first, u32*  last) {
#line 75 "src/source_map.z"
u32 i = 0;
;
#line 76 "src/source_map.z"
SourceFile*  file = 0;
;
#line 77 "src/source_map.z"
while ( (i< m->num_files))
{
#line 78 "src/source_map.z"
if ((m->file_starts[i]> span.from)){
#line 78 "src/source_map.z"
break;
;
}
;
#line 79 "src/source_map.z"
file = &m->files[i];
;
#line 80 "src/source_map.z"
i = (i+ 1);
;
}
;
#line 83 "src/source_map.z"
if (!file){
#line 83 "src/source_map.z"
abort() ;
}
;
#line 85 "src/source_map.z"
i = 0;
;
#line 86 "src/source_map.z"
while ( (i< file->num_lines))
{
#line 87 "src/source_map.z"
if ((file->lines[i]<= span.from)){
#line 88 "src/source_map.z"
*first = i;
;
}
else {
#line 90 "src/source_map.z"
break;
;
}
;
#line 91 "src/source_map.z"
i = (i+ 1);
;
}
;
#line 93 "src/source_map.z"
i = (i- 1);
;
#line 94 "src/source_map.z"
while ( (i< file->num_lines))
{
#line 95 "src/source_map.z"
if ((file->lines[i]<= span.to)){
#line 96 "src/source_map.z"
*last = i;
;
}
else {
#line 98 "src/source_map.z"
break;
;
}
;
#line 99 "src/source_map.z"
i = (i+ 1);
;
}
;
#line 102 "src/source_map.z"
return file;
;
}

#line 105 "src/source_map.z"
void  emit_line_directive(FILE*  fp, SourceMap*  m, Span span) {
#line 106 "src/source_map.z"
u32 line_first ;
;
#line 107 "src/source_map.z"
u32 line_end ;
;
#line 109 "src/source_map.z"
SourceFile*  file = source_map_info(m,span,&line_first,&line_end) ;
;
#line 111 "src/source_map.z"
fprintf(fp,"#line %u \"%s\"\n",(line_first+ 1),file->name) ;
}

#line 114 "src/source_map.z"
void  source_snippet(SourceMap*  m, Span span) {
#line 116 "src/source_map.z"
u32 line_first ;
;
#line 117 "src/source_map.z"
u32 line_last ;
;
#line 119 "src/source_map.z"
SourceFile*  file = source_map_info(m,span,&line_first,&line_last) ;
;
#line 121 "src/source_map.z"
printf("%s:%u\n",file->name,(line_first+ 1)) ;
#line 123 "src/source_map.z"
char*  buffer = malloc(1024) ;
;
#line 124 "src/source_map.z"
u32 i = line_first;
;
#line 125 "src/source_map.z"
while ( (i<= line_last))
{
#line 126 "src/source_map.z"
u32 line_start = file->lines[i];
;
#line 127 "src/source_map.z"
u32 line_end = file->lines[(i+ 1)];
;
#line 128 "src/source_map.z"
u32 length = (line_end- line_start);
;
#line 129 "src/source_map.z"
memcpy(buffer,&file->content[((line_start+ 1)- file->start)],length) ;
#line 130 "src/source_map.z"
buffer[(length+ 1)] = 0;
;
#line 131 "src/source_map.z"
printf("%s\n",buffer) ;
#line 132 "src/source_map.z"
i = (i+ 1);
;
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

#line 9 "src/error.z"
void  emit_warning(SourceMap*  m, Span span, char*  msg) {
#line 10 "src/error.z"
printf("warning: %s\n",msg) ;
#line 11 "src/error.z"
source_snippet(m,span) ;
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
Interner interner ;
;
#line 14 "src/interning.z"
interner.str_lookup = strmap_create(2048) ;
;
#line 15 "src/interning.z"
interner.sid_lookup = calloc(8,2048) ;
;
#line 16 "src/interning.z"
interner.next_sid = 1;
;
#line 17 "src/interning.z"
return interner;
;
}

#line 21 "src/interning.z"
Sid intern(Interner*  self, char*  string) {
#line 22 "src/interning.z"
Sid sid ;
;
#line 23 "src/interning.z"
sid.x = strmap_lookup(self->str_lookup,string) ;
;
#line 24 "src/interning.z"
if ((sid.x== 0)){
#line 26 "src/interning.z"
sid.x = self->next_sid;
;
#line 27 "src/interning.z"
self->next_sid = (self->next_sid+ 1);
;
#line 29 "src/interning.z"
u64 len = (strlen(string) + 1);
;
#line 30 "src/interning.z"
char*  copy = malloc(len) ;
;
#line 31 "src/interning.z"
memcpy(copy,string,len) ;
#line 32 "src/interning.z"
self->sid_lookup[sid.x] = copy;
;
#line 34 "src/interning.z"
strmap_insert(self->str_lookup,copy,sid.x) ;
}
;
#line 36 "src/interning.z"
return sid;
;
}

#line 39 "src/interning.z"
char*  get_str(Interner*  self, Sid sid) {
#line 40 "src/interning.z"
return self->sid_lookup[sid.x];
;
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
} TokenKind;


typedef struct Token Token;
#line 72 "src/tokens.z"
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
;
}

#line 17 "src/lexer.z"
bool is_digit(char c) {
#line 18 "src/lexer.z"
return ((c>= '0')&& (c<= '9'));
;
}

#line 21 "src/lexer.z"
bool is_alphanumeric(char c) {
#line 22 "src/lexer.z"
return (is_alphabetic(c) || is_digit(c) );
;
}

#line 25 "src/lexer.z"
bool is_done_lexing(LexingContext*  ctx) {
#line 26 "src/lexer.z"
SourceFile*  source = ctx->source;
;
#line 27 "src/lexer.z"
return (ctx->current>= source->length);
;
}

#line 30 "src/lexer.z"
char peek_token(LexingContext*  ctx, u32 offset) {
#line 31 "src/lexer.z"
if (is_done_lexing(ctx) ){
#line 31 "src/lexer.z"
return 0;
;
}
;
#line 32 "src/lexer.z"
SourceFile*  source = ctx->source;
;
#line 33 "src/lexer.z"
return source->content[(ctx->current+ offset)];
;
}

#line 36 "src/lexer.z"
char advance(LexingContext*  ctx) {
#line 37 "src/lexer.z"
ctx->current = (ctx->current+ 1);
;
#line 38 "src/lexer.z"
SourceFile*  source = ctx->source;
;
#line 39 "src/lexer.z"
return source->content[(ctx->current- 1)];
;
}

#line 42 "src/lexer.z"
void  add_token(LexingContext*  ctx, TokenKind kind, Sid lexeme) {
#line 43 "src/lexer.z"
Token token ;
;
#line 44 "src/lexer.z"
token.kind = kind;
;
#line 45 "src/lexer.z"
token.lexeme = lexeme;
;
#line 46 "src/lexer.z"
token.span.from = (ctx->start+ ctx->file_span_offset);
;
#line 47 "src/lexer.z"
token.span.to = (ctx->current+ ctx->file_span_offset);
;
#line 48 "src/lexer.z"
ctx->tokens[ctx->current_token_idx] = token;
;
#line 49 "src/lexer.z"
ctx->current_token_idx = (ctx->current_token_idx+ 1);
;
}

#line 52 "src/lexer.z"
void  add_simple_token(LexingContext*  ctx, TokenKind kind) {
#line 53 "src/lexer.z"
Sid null_sid ;
;
#line 54 "src/lexer.z"
null_sid.x = 0;
;
#line 55 "src/lexer.z"
add_token(ctx,kind,null_sid) ;
}

#line 58 "src/lexer.z"
void  add_lookahead_conditional_token(LexingContext*  ctx, char expect, TokenKind first, TokenKind second) {
#line 59 "src/lexer.z"
TokenKind kind ;
;
#line 60 "src/lexer.z"
if ((peek_token(ctx,0) == expect)){
#line 61 "src/lexer.z"
advance(ctx) ;
#line 62 "src/lexer.z"
kind = first;
;
}
else {
#line 64 "src/lexer.z"
kind = second;
;
}
;
#line 66 "src/lexer.z"
Sid null_sid ;
;
#line 67 "src/lexer.z"
null_sid.x = 0;
;
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
u32 str_len = (ctx->current- ((ctx->start+ start_offset)+ end_offset));
;
#line 77 "src/lexer.z"
SourceFile*  source = ctx->source;
;
#line 78 "src/lexer.z"
memcpy(ctx->lexeme_buffer,&source->content[(ctx->start+ start_offset)],str_len) ;
#line 79 "src/lexer.z"
ctx->lexeme_buffer[str_len] = 0;
;
#line 80 "src/lexer.z"
Session*  sess = ctx->sess;
;
#line 81 "src/lexer.z"
Sid sid = intern(&sess->interner,ctx->lexeme_buffer) ;
;
#line 83 "src/lexer.z"
return sid;
;
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
;
}
;
#line 94 "src/lexer.z"
if (!strcmp(s,"continue") ){
#line 94 "src/lexer.z"
return TokenKind_Continue;
;
}
;
#line 95 "src/lexer.z"
if (!strcmp(s,"const") ){
#line 95 "src/lexer.z"
return TokenKind_Continue;
;
}
;
#line 96 "src/lexer.z"
if (!strcmp(s,"defer") ){
#line 96 "src/lexer.z"
return TokenKind_Defer;
;
}
;
#line 97 "src/lexer.z"
if (!strcmp(s,"enum") ){
#line 97 "src/lexer.z"
return TokenKind_Enum;
;
}
;
#line 98 "src/lexer.z"
if (!strcmp(s,"extern") ){
#line 98 "src/lexer.z"
return TokenKind_Extern;
;
}
;
#line 99 "src/lexer.z"
if (!strcmp(s,"else") ){
#line 99 "src/lexer.z"
return TokenKind_Else;
;
}
;
#line 100 "src/lexer.z"
if (!strcmp(s,"false") ){
#line 100 "src/lexer.z"
return TokenKind_False;
;
}
;
#line 101 "src/lexer.z"
if (!strcmp(s,"fn") ){
#line 101 "src/lexer.z"
return TokenKind_Fn;
;
}
;
#line 102 "src/lexer.z"
if (!strcmp(s,"for") ){
#line 102 "src/lexer.z"
return TokenKind_For;
;
}
;
#line 103 "src/lexer.z"
if (!strcmp(s,"if") ){
#line 103 "src/lexer.z"
return TokenKind_If;
;
}
;
#line 104 "src/lexer.z"
if (!strcmp(s,"mod") ){
#line 104 "src/lexer.z"
return TokenKind_Mod;
;
}
;
#line 105 "src/lexer.z"
if (!strcmp(s,"return") ){
#line 105 "src/lexer.z"
return TokenKind_Return;
;
}
;
#line 106 "src/lexer.z"
if (!strcmp(s,"struct") ){
#line 106 "src/lexer.z"
return TokenKind_Struct;
;
}
;
#line 107 "src/lexer.z"
if (!strcmp(s,"sizeof") ){
#line 107 "src/lexer.z"
return TokenKind_Sizeof;
;
}
;
#line 108 "src/lexer.z"
if (!strcmp(s,"true") ){
#line 108 "src/lexer.z"
return TokenKind_True;
;
}
;
#line 109 "src/lexer.z"
if (!strcmp(s,"union") ){
#line 109 "src/lexer.z"
return TokenKind_Union;
;
}
;
#line 110 "src/lexer.z"
if (!strcmp(s,"use") ){
#line 110 "src/lexer.z"
return TokenKind_Use;
;
}
;
#line 111 "src/lexer.z"
if (!strcmp(s,"var") ){
#line 111 "src/lexer.z"
return TokenKind_Var;
;
}
;
#line 112 "src/lexer.z"
if (!strcmp(s,"val") ){
#line 112 "src/lexer.z"
return TokenKind_Val;
;
}
;
#line 113 "src/lexer.z"
if (!strcmp(s,"while") ){
#line 113 "src/lexer.z"
return TokenKind_While;
;
}
;
#line 114 "src/lexer.z"
return TokenKind_Invalid;
;
}

#line 117 "src/lexer.z"
void  lex_char(LexingContext*  ctx) {
#line 119 "src/lexer.z"
SourceFile*  source = ctx->source;
;
#line 120 "src/lexer.z"
u32 start_line = (source->num_lines+ 1);
;
#line 122 "src/lexer.z"
while ( (((peek_token(ctx,0) != '\'')|| ((peek_token(ctx,-1) == '\\')&& (peek_token(ctx,-2) != '\\')))&& !is_done_lexing(ctx) ))
{
#line 123 "src/lexer.z"
char c = advance(ctx) ;
;
#line 124 "src/lexer.z"
if ((c== '\n')){
#line 124 "src/lexer.z"
read_newline(ctx) ;
}
;
}
;
#line 127 "src/lexer.z"
if (is_done_lexing(ctx) ){
#line 128 "src/lexer.z"
printf("Unterminated char starting on line %u\n",start_line) ;
#line 129 "src/lexer.z"
abort() ;
}
;
#line 133 "src/lexer.z"
advance(ctx) ;
#line 135 "src/lexer.z"
add_token(ctx,TokenKind_Char,get_lexeme(ctx,1,1) ) ;
}

#line 138 "src/lexer.z"
void  lex_string(LexingContext*  ctx) {
#line 140 "src/lexer.z"
SourceFile*  source = ctx->source;
;
#line 142 "src/lexer.z"
u32 start_line = (source->num_lines+ 1);
;
#line 144 "src/lexer.z"
while ( (((peek_token(ctx,0) != '"')|| ((peek_token(ctx,-1) == '\\')&& (peek_token(ctx,-2) != '\\')))&& !is_done_lexing(ctx) ))
{
#line 145 "src/lexer.z"
char c = advance(ctx) ;
;
#line 146 "src/lexer.z"
if ((c== '\n')){
#line 146 "src/lexer.z"
read_newline(ctx) ;
}
;
}
;
#line 149 "src/lexer.z"
if (is_done_lexing(ctx) ){
#line 150 "src/lexer.z"
printf("Unterminated string starting on line %u\n",start_line) ;
#line 151 "src/lexer.z"
abort() ;
}
;
#line 155 "src/lexer.z"
advance(ctx) ;
#line 157 "src/lexer.z"
add_token(ctx,TokenKind_String,get_lexeme(ctx,1,1) ) ;
}

#line 160 "src/lexer.z"
void  lex_number(LexingContext*  ctx) {
#line 162 "src/lexer.z"
while ( is_digit(peek_token(ctx,0) ) )
{
#line 162 "src/lexer.z"
advance(ctx) ;
}
;
#line 163 "src/lexer.z"
bool dot_encountered = false;
;
#line 164 "src/lexer.z"
if (((peek_token(ctx,0) == '.')&& is_digit(peek_token(ctx,1) ) )){
#line 165 "src/lexer.z"
dot_encountered = true;
;
#line 166 "src/lexer.z"
advance(ctx) ;
#line 167 "src/lexer.z"
while ( is_digit(peek_token(ctx,0) ) )
{
#line 167 "src/lexer.z"
advance(ctx) ;
}
;
}
;
#line 170 "src/lexer.z"
TokenKind t ;
;
#line 171 "src/lexer.z"
if (dot_encountered){
#line 171 "src/lexer.z"
t = TokenKind_Float;
;
}
else {
#line 172 "src/lexer.z"
t = TokenKind_Integer;
;
}
;
#line 174 "src/lexer.z"
add_token(ctx,t,get_lexeme(ctx,0,0) ) ;
}

#line 177 "src/lexer.z"
void  lex_identifier(LexingContext*  ctx) {
#line 178 "src/lexer.z"
while ( (is_alphanumeric(peek_token(ctx,0) ) || (peek_token(ctx,0) == '_')))
{
#line 178 "src/lexer.z"
advance(ctx) ;
}
;
#line 180 "src/lexer.z"
Sid lexeme = get_lexeme(ctx,0,0) ;
;
#line 182 "src/lexer.z"
Session*  sess = ctx->sess;
;
#line 183 "src/lexer.z"
char*  lexeme_str = get_str(&sess->interner,lexeme) ;
;
#line 184 "src/lexer.z"
TokenKind keyword = is_keyword(lexeme_str) ;
;
#line 185 "src/lexer.z"
if ((keyword!= TokenKind_Invalid)){
#line 185 "src/lexer.z"
add_simple_token(ctx,keyword) ;
}
else {
#line 186 "src/lexer.z"
add_token(ctx,TokenKind_Identifier,lexeme) ;
}
;
}

#line 189 "src/lexer.z"
void  scan_token(LexingContext*  ctx) {
#line 190 "src/lexer.z"
char c = advance(ctx) ;
;
#line 194 "src/lexer.z"
if ((c== '(')){
#line 194 "src/lexer.z"
add_simple_token(ctx,TokenKind_LeftParen) ;
}
else {
#line 195 "src/lexer.z"
if ((c== ')')){
#line 195 "src/lexer.z"
add_simple_token(ctx,TokenKind_RightParen) ;
}
else {
#line 196 "src/lexer.z"
if ((c== '[')){
#line 196 "src/lexer.z"
add_simple_token(ctx,TokenKind_LeftBracket) ;
}
else {
#line 197 "src/lexer.z"
if ((c== ']')){
#line 197 "src/lexer.z"
add_simple_token(ctx,TokenKind_RightBracket) ;
}
else {
#line 198 "src/lexer.z"
if ((c== '{')){
#line 198 "src/lexer.z"
add_simple_token(ctx,TokenKind_LeftCurly) ;
}
else {
#line 199 "src/lexer.z"
if ((c== '}')){
#line 199 "src/lexer.z"
add_simple_token(ctx,TokenKind_RightCurly) ;
}
else {
#line 200 "src/lexer.z"
if ((c== '+')){
#line 200 "src/lexer.z"
add_simple_token(ctx,TokenKind_Plus) ;
}
else {
#line 201 "src/lexer.z"
if ((c== '*')){
#line 201 "src/lexer.z"
add_simple_token(ctx,TokenKind_Star) ;
}
else {
#line 202 "src/lexer.z"
if ((c== '%')){
#line 202 "src/lexer.z"
add_simple_token(ctx,TokenKind_Percent) ;
}
else {
#line 203 "src/lexer.z"
if ((c== '^')){
#line 203 "src/lexer.z"
add_simple_token(ctx,TokenKind_Hat) ;
}
else {
#line 204 "src/lexer.z"
if ((c== ';')){
#line 204 "src/lexer.z"
add_simple_token(ctx,TokenKind_Semicolon) ;
}
else {
#line 205 "src/lexer.z"
if ((c== ',')){
#line 205 "src/lexer.z"
add_simple_token(ctx,TokenKind_Comma) ;
}
else {
#line 206 "src/lexer.z"
if ((c== '-')){
#line 206 "src/lexer.z"
add_lookahead_conditional_token(ctx,'>',TokenKind_Arrow,TokenKind_Minus) ;
}
else {
#line 207 "src/lexer.z"
if ((c== ':')){
#line 207 "src/lexer.z"
add_lookahead_conditional_token(ctx,':',TokenKind_ColonColon,TokenKind_Colon) ;
}
else {
#line 208 "src/lexer.z"
if ((c== '=')){
#line 208 "src/lexer.z"
add_lookahead_conditional_token(ctx,'=',TokenKind_EqualEqual,TokenKind_Equal) ;
}
else {
#line 209 "src/lexer.z"
if ((c== '!')){
#line 209 "src/lexer.z"
add_lookahead_conditional_token(ctx,'=',TokenKind_BangEqual,TokenKind_Bang) ;
}
else {
#line 210 "src/lexer.z"
if ((c== '&')){
#line 210 "src/lexer.z"
add_lookahead_conditional_token(ctx,'&',TokenKind_AndAnd,TokenKind_And) ;
}
else {
#line 211 "src/lexer.z"
if ((c== '|')){
#line 211 "src/lexer.z"
add_lookahead_conditional_token(ctx,'|',TokenKind_OrOr,TokenKind_Or) ;
}
else {
#line 212 "src/lexer.z"
if ((c== '.')){
#line 213 "src/lexer.z"
if (((peek_token(ctx,0) == '.')&& (peek_token(ctx,1) == '.'))){
#line 214 "src/lexer.z"
advance(ctx) ;
#line 214 "src/lexer.z"
advance(ctx) ;
#line 215 "src/lexer.z"
add_simple_token(ctx,TokenKind_Ellipsis) ;
}
else {
#line 217 "src/lexer.z"
add_simple_token(ctx,TokenKind_Dot) ;
}
;
}
else {
#line 219 "src/lexer.z"
if ((c== '<')){
#line 220 "src/lexer.z"
char n1 = peek_token(ctx,0) ;
;
#line 221 "src/lexer.z"
if ((n1== '<')){
#line 221 "src/lexer.z"
advance(ctx) ;
#line 221 "src/lexer.z"
add_simple_token(ctx,TokenKind_LessLess) ;
}
else {
#line 222 "src/lexer.z"
if ((n1== '=')){
#line 222 "src/lexer.z"
advance(ctx) ;
#line 222 "src/lexer.z"
add_simple_token(ctx,TokenKind_LessEqual) ;
}
else {
#line 223 "src/lexer.z"
add_simple_token(ctx,TokenKind_Less) ;
}
;
}
;
}
else {
#line 225 "src/lexer.z"
if ((c== '>')){
#line 226 "src/lexer.z"
char n2 = peek_token(ctx,0) ;
;
#line 227 "src/lexer.z"
if ((n2== '>')){
#line 227 "src/lexer.z"
advance(ctx) ;
#line 227 "src/lexer.z"
add_simple_token(ctx,TokenKind_GreaterGreater) ;
}
else {
#line 228 "src/lexer.z"
if ((n2== '=')){
#line 228 "src/lexer.z"
advance(ctx) ;
#line 228 "src/lexer.z"
add_simple_token(ctx,TokenKind_GreaterEqual) ;
}
else {
#line 229 "src/lexer.z"
add_simple_token(ctx,TokenKind_Greater) ;
}
;
}
;
}
else {
#line 231 "src/lexer.z"
if ((c== '/')){
#line 232 "src/lexer.z"
if ((peek_token(ctx,0) == '/')){
#line 232 "src/lexer.z"
single_line_comment(ctx) ;
}
else {
#line 233 "src/lexer.z"
add_simple_token(ctx,TokenKind_Slash) ;
}
;
}
else {
#line 235 "src/lexer.z"
if ((((c== ' ')|| (c== '\t'))|| (c== '\r'))){
}
else {
#line 236 "src/lexer.z"
if ((c== '\n')){
#line 236 "src/lexer.z"
read_newline(ctx) ;
}
else {
#line 237 "src/lexer.z"
if ((c== '"')){
#line 237 "src/lexer.z"
lex_string(ctx) ;
}
else {
#line 238 "src/lexer.z"
if ((c== '\'')){
#line 238 "src/lexer.z"
lex_char(ctx) ;
}
else {
#line 240 "src/lexer.z"
if (is_digit(c) ){
#line 240 "src/lexer.z"
lex_number(ctx) ;
}
else {
#line 241 "src/lexer.z"
if ((is_alphabetic(c) || (c== '_'))){
#line 241 "src/lexer.z"
lex_identifier(ctx) ;
}
else {
#line 243 "src/lexer.z"
SourceFile*  source = ctx->source;
;
#line 244 "src/lexer.z"
printf("Unexpected character %c = %d on line %u\n",c,c,source->num_lines) ;
#line 245 "src/lexer.z"
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

#line 250 "src/lexer.z"
Token*  lex(Session*  sess, SourceFile*  source, u32*  num_tokens) {
#line 252 "src/lexer.z"
LexingContext*  ctx = malloc(sizeof(LexingContext)) ;
;
#line 253 "src/lexer.z"
ctx->source = source;
;
#line 254 "src/lexer.z"
ctx->file_span_offset = source->start;
;
#line 255 "src/lexer.z"
ctx->start = 0;
;
#line 256 "src/lexer.z"
ctx->current = 0;
;
#line 257 "src/lexer.z"
ctx->tokens = malloc((sizeof(Token)* 10000)) ;
;
#line 258 "src/lexer.z"
ctx->current_token_idx = 0;
;
#line 259 "src/lexer.z"
ctx->sess = sess;
;
#line 261 "src/lexer.z"
ctx->lexeme_buffer = malloc(1024) ;
;
#line 263 "src/lexer.z"
while ( !is_done_lexing(ctx) )
{
#line 264 "src/lexer.z"
ctx->start = ctx->current;
;
#line 265 "src/lexer.z"
scan_token(ctx) ;
}
;
#line 268 "src/lexer.z"
source_file_done(source,ctx->current) ;
#line 270 "src/lexer.z"
if ((ctx->current_token_idx> 10000)){
#line 271 "src/lexer.z"
printf("Lexer token overflow: %u!\n",ctx->current_token_idx) ;
#line 272 "src/lexer.z"
abort() ;
}
;
#line 275 "src/lexer.z"
*num_tokens = ctx->current_token_idx;
;
#line 276 "src/lexer.z"
return ctx->tokens;
;
}


#line 1 "src/types.z"
typedef enum IntegerSize {
IntegerSize_I8,
IntegerSize_I16,
IntegerSize_I32,
IntegerSize_I64,
IntegerSize_Int_Arch,
IntegerSize_Int_Unspecified,
} IntegerSize;


#line 10 "src/types.z"
typedef enum FloatingSize {
FloatingSize_F32,
FloatingSize_F64,
FloatingSize_Float_Unspecified,
} FloatingSize;


#line 16 "src/types.z"
typedef enum PrimitiveTyKind {
PrimitiveTyKind_Void,
PrimitiveTyKind_Signed,
PrimitiveTyKind_Unsigned,
PrimitiveTyKind_Floating,
PrimitiveTyKind_Bool,
PrimitiveTyKind_Char,
} PrimitiveTyKind;


typedef union PrimitiveTyNode PrimitiveTyNode;
#line 25 "src/types.z"
typedef union PrimitiveTyNode {
IntegerSize integer;
FloatingSize floating;
} PrimitiveTyNode;


typedef struct PrimitiveTy PrimitiveTy;
#line 30 "src/types.z"
typedef struct PrimitiveTy {
PrimitiveTyNode node;
PrimitiveTyKind kind;
} PrimitiveTy;


typedef struct Ty Ty;
#line 35 "src/types.z"

typedef struct FieldDef FieldDef;
#line 37 "src/types.z"
typedef struct FieldDef {
Sid name;
Ty*  ty;
} FieldDef;


typedef struct CompoundDef CompoundDef;
#line 42 "src/types.z"
typedef struct CompoundDef {
u32 def_id;
FieldDef*  fields;
u32 num_fields;
} CompoundDef;


typedef struct EnumDef EnumDef;
#line 48 "src/types.z"
typedef struct EnumDef {
u32 def_id;
Sid*  variants;
u32 num_variants;
} EnumDef;


typedef struct FnDef FnDef;
#line 54 "src/types.z"
typedef struct FnDef {
Ty* *  parameters;
u32 num_parameters;
Ty*  output;
} FnDef;


#line 60 "src/types.z"
typedef enum TyKind {
TyKind_Bool,
TyKind_Char,
TyKind_Signed,
TyKind_Unsigned,
TyKind_Floating,
TyKind_Ptr,
TyKind_Fn,
TyKind_Enum,
TyKind_Struct,
TyKind_Union,
TyKind_Void,
} TyKind;


typedef union TyKindNode TyKindNode;
#line 74 "src/types.z"
typedef union TyKindNode {
IntegerSize integer;
FloatingSize floating;
Ty*  ptr;
CompoundDef compound;
EnumDef _enum;
FnDef function;
} TyKindNode;


typedef struct Ty Ty;
#line 83 "src/types.z"
typedef struct Ty {
TyKind kind;
TyKindNode node;
} Ty;



typedef struct AstType AstType;
#line 2 "src/ast.z"

typedef struct Expr Expr;
#line 3 "src/ast.z"

typedef struct Block Block;
#line 4 "src/ast.z"

typedef struct Item Item;
#line 5 "src/ast.z"

typedef struct Ident Ident;
#line 7 "src/ast.z"
typedef struct Ident {
Sid name;
Span span;
} Ident;


#line 12 "src/ast.z"
typedef enum BindingKind {
BindingKind_Item,
BindingKind_Variable,
BindingKind_PrimitiveType,
} BindingKind;


typedef struct FunctionParameter FunctionParameter;
#line 18 "src/ast.z"

typedef union BindingNode BindingNode;
#line 20 "src/ast.z"
typedef union BindingNode {
Item*  item;
u32 slot;
PrimitiveTy primitive;
} BindingNode;


typedef struct Binding Binding;
#line 26 "src/ast.z"
typedef struct Binding {
BindingKind kind;
BindingNode node;
} Binding;


typedef struct Path Path;
#line 31 "src/ast.z"
typedef struct Path {
Ident*  segments;
u32 num_segments;
Binding binding;
Span span;
} Path;


typedef struct Pattern Pattern;
#line 38 "src/ast.z"
typedef struct Pattern {
Ident ident;
Span span;
} Pattern;


typedef struct Item Item;
#line 43 "src/ast.z"

typedef struct IndexEntry IndexEntry;
#line 45 "src/ast.z"
typedef struct IndexEntry {
Path path;
} IndexEntry;


typedef struct Module Module;
#line 49 "src/ast.z"
typedef struct Module {
Span span;
Item* *  items;
u32 num_items;
IntMap*  index_lookup;
IndexEntry*  index;
u32 num_indices;
Path path;
Module*  parent;
} Module;


#line 60 "src/ast.z"
typedef enum AstTypeKind {
AstTypeKind_Void,
AstTypeKind_Ptr,
AstTypeKind_Path,
AstTypeKind_Variadic,
} AstTypeKind;


typedef struct GenericParam GenericParam;
#line 67 "src/ast.z"
typedef struct GenericParam {
Ident ident;
} GenericParam;


typedef struct Generics Generics;
#line 71 "src/ast.z"
typedef struct Generics {
GenericParam*  parameters;
u32 num_parameters;
Span span;
} Generics;


typedef union AstTypeKindNode AstTypeKindNode;
#line 77 "src/ast.z"
typedef union AstTypeKindNode {
Sid path;
AstType*  ptr;
} AstTypeKindNode;


typedef struct AstType AstType;
#line 82 "src/ast.z"
typedef struct AstType {
AstTypeKind kind;
AstTypeKindNode node;
} AstType;


#line 87 "src/ast.z"
typedef enum LiteralKind {
LiteralKind_Int,
LiteralKind_Float,
LiteralKind_Bool,
LiteralKind_Char,
LiteralKind_Str,
} LiteralKind;


typedef union LiteralValue LiteralValue;
#line 95 "src/ast.z"
typedef union LiteralValue {
f64 floating;
u64 integer;
bool boolean;
char ch;
Sid str;
} LiteralValue;


typedef struct Literal Literal;
#line 103 "src/ast.z"
typedef struct Literal {
LiteralKind kind;
LiteralValue value;
} Literal;


#line 109 "src/ast.z"
typedef enum UnaryOperatorKind {
UnaryOperatorKind_Deref,
UnaryOperatorKind_Refer,
UnaryOperatorKind_Negation,
UnaryOperatorKind_Complement,
} UnaryOperatorKind;


#line 120 "src/ast.z"
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
#line 149 "src/ast.z"
typedef struct BinaryData {
BinaryOperatorKind op;
Expr*  left;
Expr*  right;
} BinaryData;


typedef struct CallData CallData;
#line 155 "src/ast.z"
typedef struct CallData {
Expr*  func;
Expr* *  args;
u32 num_args;
} CallData;


typedef struct ConditionalData ConditionalData;
#line 161 "src/ast.z"
typedef struct ConditionalData {
Expr*  condition;
Expr*  then;
Expr*  otherwise;
} ConditionalData;


typedef struct WhileData WhileData;
#line 167 "src/ast.z"
typedef struct WhileData {
Expr*  condition;
Expr*  body;
} WhileData;


typedef struct IndexingData IndexingData;
#line 172 "src/ast.z"
typedef struct IndexingData {
Expr*  array;
Expr*  index;
} IndexingData;


typedef struct FieldData FieldData;
#line 177 "src/ast.z"
typedef struct FieldData {
Expr*  strct;
Ident ident;
} FieldData;


typedef struct UnaryData UnaryData;
#line 182 "src/ast.z"
typedef struct UnaryData {
UnaryOperatorKind op;
Expr*  inner;
} UnaryData;


typedef struct AssignmentData AssignmentData;
#line 187 "src/ast.z"
typedef struct AssignmentData {
Expr*  left;
Expr*  right;
} AssignmentData;


typedef struct LetData LetData;
#line 192 "src/ast.z"
typedef struct LetData {
Pattern pat;
Expr*  value;
AstType*  ty;
} LetData;


#line 198 "src/ast.z"
typedef enum ExprKind {
ExprKind_Binary,
ExprKind_Block,
ExprKind_Call,
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
} ExprKind;


typedef union ExprKindNode ExprKindNode;
#line 218 "src/ast.z"
typedef union ExprKindNode {
BinaryData binary;
Block*  block;
CallData call;
ConditionalData conditional;
bool control_flow_is_continue;
FieldData field;
IndexingData indexing;
Path path;
Literal lit;
Expr*  _sizeof;
UnaryData unary;
WhileData whl;
AssignmentData assignment;
Expr*  _return;
LetData _let;
} ExprKindNode;


typedef struct Expr Expr;
#line 236 "src/ast.z"
typedef struct Expr {
Span span;
ExprKind kind;
ExprKindNode node;
} Expr;


typedef struct Block Block;
#line 242 "src/ast.z"
typedef struct Block {
Expr* *  exprs;
u32 num_exprs;
Span span;
} Block;


#line 248 "src/ast.z"
typedef enum VisibilityKind {
VisibilityKind_Public,
VisibilityKind_Private,
} VisibilityKind;


typedef struct Visibility Visibility;
#line 253 "src/ast.z"
typedef struct Visibility {
VisibilityKind kind;
} Visibility;


typedef struct CompoundField CompoundField;
#line 257 "src/ast.z"
typedef struct CompoundField {
Ident ident;
AstType*  ty;
} CompoundField;


typedef struct CompoundData CompoundData;
#line 262 "src/ast.z"
typedef struct CompoundData {
CompoundField*  fields;
u32 num_fields;
Generics generics;
} CompoundData;


typedef struct EnumVariant EnumVariant;
#line 268 "src/ast.z"
typedef struct EnumVariant {
Ident ident;
} EnumVariant;


typedef struct EnumData EnumData;
#line 272 "src/ast.z"
typedef struct EnumData {
EnumVariant*  variants;
u32 num_variants;
} EnumData;


typedef struct FunctionParameter FunctionParameter;
#line 277 "src/ast.z"
typedef struct FunctionParameter {
Pattern pat;
AstType*  ty;
} FunctionParameter;


typedef struct FunctionHeader FunctionHeader;
#line 283 "src/ast.z"
typedef struct FunctionHeader {
FunctionParameter*  parameters;
u32 num_parameters;
AstType*  output;
Generics generics;
} FunctionHeader;


typedef struct FunctionData FunctionData;
#line 290 "src/ast.z"
typedef struct FunctionData {
FunctionHeader header;
Expr*  body;
bool is_extern;
} FunctionData;


typedef struct VariableData VariableData;
#line 297 "src/ast.z"
typedef struct VariableData {
AstType*  ty;
bool mutable;
Expr*  body;
} VariableData;


typedef union ItemKindNode ItemKindNode;
#line 303 "src/ast.z"
typedef union ItemKindNode {
CompoundData compound;
EnumData _enum;
VariableData variable;
FunctionData function;
Module*  module;
Path _use;
} ItemKindNode;


#line 312 "src/ast.z"
typedef enum ItemKind {
ItemKind_Const,
ItemKind_Enum,
ItemKind_Function,
ItemKind_Module,
ItemKind_Struct,
ItemKind_Union,
ItemKind_Use,
ItemKind_Variable,
} ItemKind;


typedef struct Item Item;
#line 323 "src/ast.z"
typedef struct Item {
Ident ident;
ItemKind kind;
ItemKindNode node;
Visibility vis;
Span span;
} Item;


typedef struct Ast Ast;
#line 331 "src/ast.z"
typedef struct Ast {
Item*  items;
u32 num_items;
Module*  root_module;
} Ast;


#line 338 "src/ast.z"
Expr*  ast_create_expr(Ast*  ast, ExprKind kind) {
#line 339 "src/ast.z"
Expr*  expr = malloc(sizeof(Expr)) ;
;
#line 340 "src/ast.z"
expr->kind = kind;
;
#line 342 "src/ast.z"
return expr;
;
}

#line 345 "src/ast.z"
Item*  ast_create_item(Ast*  ast) {
#line 347 "src/ast.z"
Item*  item = &ast->items[ast->num_items];
;
#line 348 "src/ast.z"
ast->num_items = (ast->num_items+ 1);
;
#line 350 "src/ast.z"
return item;
;
}


typedef struct ParsingContext ParsingContext;
#line 2 "src/parser.z"
typedef struct ParsingContext {
u64 current_token;
Token*  tokens;
u64 num_tokens;
SourceMap*  source_map;
Session*  sess;
Module*  current_module;
Ast*  ast;
} ParsingContext;


#line 12 "src/parser.z"
bool is_done_parsing(ParsingContext*  ctx) {
#line 13 "src/parser.z"
return (ctx->num_tokens== ctx->current_token);
;
}

#line 16 "src/parser.z"
bool accept(ParsingContext*  ctx, TokenKind token) {
#line 17 "src/parser.z"
Token tok = ctx->tokens[ctx->current_token];
;
#line 18 "src/parser.z"
if ((!is_done_parsing(ctx) && (tok.kind== token))){
#line 19 "src/parser.z"
ctx->current_token = (ctx->current_token+ 1);
;
#line 20 "src/parser.z"
return true;
;
}
;
#line 22 "src/parser.z"
return false;
;
}

#line 25 "src/parser.z"
bool can_accept(ParsingContext*  ctx, TokenKind token) {
#line 26 "src/parser.z"
Token tok = ctx->tokens[ctx->current_token];
;
#line 27 "src/parser.z"
if ((!is_done_parsing(ctx) && (tok.kind== token))){
#line 28 "src/parser.z"
return true;
;
}
;
#line 30 "src/parser.z"
return false;
;
}

#line 33 "src/parser.z"
Token look_ahead(ParsingContext*  ctx, u64 offset) {
#line 34 "src/parser.z"
if ((ctx->current_token== ctx->num_tokens)){
#line 35 "src/parser.z"
Token eof_tok ;
;
#line 36 "src/parser.z"
eof_tok.kind = EOF;
;
#line 37 "src/parser.z"
return eof_tok;
;
}
else {
#line 38 "src/parser.z"
return ctx->tokens[(ctx->current_token+ offset)];
;
}
;
}

#line 41 "src/parser.z"
Token consume(ParsingContext*  ctx) {
#line 42 "src/parser.z"
ctx->current_token = (ctx->current_token+ 1);
;
#line 43 "src/parser.z"
return ctx->tokens[(ctx->current_token- 1)];
;
}

#line 46 "src/parser.z"
Token expect(ParsingContext*  ctx, TokenKind kind) {
#line 47 "src/parser.z"
Token tok = consume(ctx) ;
;
#line 48 "src/parser.z"
if ((tok.kind== kind)){
#line 49 "src/parser.z"
return tok;
;
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
;
}

#line 60 "src/parser.z"
u32 span_end(ParsingContext*  ctx) {
#line 61 "src/parser.z"
return ctx->tokens[(ctx->current_token- 1)].span.to;
;
}

#line 64 "src/parser.z"
Ident parse_identifier(ParsingContext*  ctx) {
#line 66 "src/parser.z"
Ident ident ;
;
#line 67 "src/parser.z"
ident.span.from = span_start(ctx) ;
;
#line 68 "src/parser.z"
Token tok = consume(ctx) ;
;
#line 70 "src/parser.z"
if ((tok.kind!= TokenKind_Identifier)){
#line 70 "src/parser.z"
emit_error(ctx->source_map,tok.span,"Invalid identifier") ;
}
;
#line 72 "src/parser.z"
ident.name = tok.lexeme;
;
#line 73 "src/parser.z"
ident.span.to = span_end(ctx) ;
;
#line 75 "src/parser.z"
return ident;
;
}

#line 78 "src/parser.z"
Path parse_path(ParsingContext*  ctx) {
#line 79 "src/parser.z"
Path path ;
;
#line 80 "src/parser.z"
path.segments = malloc((8* 4)) ;
;
#line 81 "src/parser.z"
path.num_segments = 0;
;
#line 82 "src/parser.z"
path.span.from = span_start(ctx) ;
;
#line 84 "src/parser.z"
while ( true)
{
#line 85 "src/parser.z"
if (accept(ctx,TokenKind_Star) ){
#line 86 "src/parser.z"
path.segments[path.num_segments].name.x = 0;
;
}
else {
#line 88 "src/parser.z"
path.segments[path.num_segments] = parse_identifier(ctx) ;
;
}
;
#line 90 "src/parser.z"
path.num_segments = (path.num_segments+ 1);
;
#line 91 "src/parser.z"
if (!accept(ctx,TokenKind_ColonColon) ){
#line 91 "src/parser.z"
break;
;
}
;
}
;
#line 94 "src/parser.z"
path.span.to = span_end(ctx) ;
;
#line 95 "src/parser.z"
return path;
;
}

#line 98 "src/parser.z"
Expr*  parse_path_expr(ParsingContext*  ctx) {
#line 99 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_Path) ;
;
#line 100 "src/parser.z"
expr->node.path = parse_path(ctx) ;
;
#line 101 "src/parser.z"
return expr;
;
}

#line 104 "src/parser.z"
Pattern parse_pattern(ParsingContext*  ctx) {
#line 105 "src/parser.z"
Pattern pat ;
;
#line 106 "src/parser.z"
pat.span.from = span_start(ctx) ;
;
#line 107 "src/parser.z"
pat.ident = parse_identifier(ctx) ;
;
#line 108 "src/parser.z"
pat.span.to = span_start(ctx) ;
;
#line 109 "src/parser.z"
return pat;
;
}

#line 112 "src/parser.z"
AstType*  parse_type(ParsingContext*  ctx) {
#line 113 "src/parser.z"
AstTypeKindNode node ;
;
#line 114 "src/parser.z"
AstTypeKind kind ;
;
#line 116 "src/parser.z"
Token token = consume(ctx) ;
;
#line 117 "src/parser.z"
if ((token.kind== TokenKind_Identifier)){
#line 118 "src/parser.z"
kind = AstTypeKind_Path;
;
#line 119 "src/parser.z"
node.path = token.lexeme;
;
}
else {
#line 120 "src/parser.z"
if ((token.kind== TokenKind_Star)){
#line 121 "src/parser.z"
kind = AstTypeKind_Ptr;
;
#line 122 "src/parser.z"
node.ptr = parse_type(ctx) ;
;
}
else {
#line 123 "src/parser.z"
if ((token.kind== TokenKind_Ellipsis)){
#line 124 "src/parser.z"
kind = AstTypeKind_Variadic;
;
}
else {
#line 126 "src/parser.z"
emit_error(ctx->source_map,token.span,"Expected type") ;
}
;
}
;
}
;
#line 128 "src/parser.z"
AstType*  type = malloc(sizeof(AstType)) ;
;
#line 129 "src/parser.z"
type->kind = kind;
;
#line 130 "src/parser.z"
type->node = node;
;
#line 132 "src/parser.z"
return type;
;
}

#line 135 "src/parser.z"
BinaryOperatorKind convert_token_to_binary_operator(TokenKind tok) {
#line 136 "src/parser.z"
if ((tok== TokenKind_Plus)){
#line 136 "src/parser.z"
return BinaryOperatorKind_Addition;
;
}
else {
#line 137 "src/parser.z"
if ((tok== TokenKind_Minus)){
#line 137 "src/parser.z"
return BinaryOperatorKind_Subtraction;
;
}
else {
#line 138 "src/parser.z"
if ((tok== TokenKind_Star)){
#line 138 "src/parser.z"
return BinaryOperatorKind_Product;
;
}
else {
#line 139 "src/parser.z"
if ((tok== TokenKind_Slash)){
#line 139 "src/parser.z"
return BinaryOperatorKind_Division;
;
}
else {
#line 140 "src/parser.z"
if ((tok== TokenKind_Percent)){
#line 140 "src/parser.z"
return BinaryOperatorKind_Modulus;
;
}
else {
#line 141 "src/parser.z"
if ((tok== TokenKind_Less)){
#line 141 "src/parser.z"
return BinaryOperatorKind_Less;
;
}
else {
#line 142 "src/parser.z"
if ((tok== TokenKind_LessEqual)){
#line 142 "src/parser.z"
return BinaryOperatorKind_LessEq;
;
}
else {
#line 143 "src/parser.z"
if ((tok== TokenKind_Greater)){
#line 143 "src/parser.z"
return BinaryOperatorKind_Greater;
;
}
else {
#line 144 "src/parser.z"
if ((tok== TokenKind_GreaterEqual)){
#line 144 "src/parser.z"
return BinaryOperatorKind_GreaterEq;
;
}
else {
#line 145 "src/parser.z"
if ((tok== TokenKind_EqualEqual)){
#line 145 "src/parser.z"
return BinaryOperatorKind_Equality;
;
}
else {
#line 146 "src/parser.z"
if ((tok== TokenKind_BangEqual)){
#line 146 "src/parser.z"
return BinaryOperatorKind_NotEq;
;
}
else {
#line 147 "src/parser.z"
if ((tok== TokenKind_AndAnd)){
#line 147 "src/parser.z"
return BinaryOperatorKind_And;
;
}
else {
#line 148 "src/parser.z"
if ((tok== TokenKind_OrOr)){
#line 148 "src/parser.z"
return BinaryOperatorKind_Or;
;
}
else {
#line 149 "src/parser.z"
if ((tok== TokenKind_And)){
#line 149 "src/parser.z"
return BinaryOperatorKind_BAnd;
;
}
else {
#line 150 "src/parser.z"
if ((tok== TokenKind_Or)){
#line 150 "src/parser.z"
return BinaryOperatorKind_BOr;
;
}
else {
#line 151 "src/parser.z"
if ((tok== TokenKind_Hat)){
#line 151 "src/parser.z"
return BinaryOperatorKind_Xor;
;
}
else {
#line 152 "src/parser.z"
if ((tok== TokenKind_LessLess)){
#line 152 "src/parser.z"
return BinaryOperatorKind_LeftShift;
;
}
else {
#line 153 "src/parser.z"
if ((tok== TokenKind_GreaterGreater)){
#line 153 "src/parser.z"
return BinaryOperatorKind_RightShift;
;
}
else {
#line 154 "src/parser.z"
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

#line 157 "src/parser.z"
u32 get_binary_operator_precedence(BinaryOperatorKind op) {
#line 158 "src/parser.z"
if ((op== BinaryOperatorKind_Product)){
#line 158 "src/parser.z"
return 10;
;
}
else {
#line 159 "src/parser.z"
if ((op== BinaryOperatorKind_Division)){
#line 159 "src/parser.z"
return 10;
;
}
else {
#line 160 "src/parser.z"
if ((op== BinaryOperatorKind_Modulus)){
#line 160 "src/parser.z"
return 10;
;
}
else {
#line 161 "src/parser.z"
if ((op== BinaryOperatorKind_Addition)){
#line 161 "src/parser.z"
return 9;
;
}
else {
#line 162 "src/parser.z"
if ((op== BinaryOperatorKind_Subtraction)){
#line 162 "src/parser.z"
return 9;
;
}
else {
#line 163 "src/parser.z"
if ((op== BinaryOperatorKind_LeftShift)){
#line 163 "src/parser.z"
return 8;
;
}
else {
#line 164 "src/parser.z"
if ((op== BinaryOperatorKind_RightShift)){
#line 164 "src/parser.z"
return 8;
;
}
else {
#line 165 "src/parser.z"
if ((op== BinaryOperatorKind_BAnd)){
#line 165 "src/parser.z"
return 7;
;
}
else {
#line 166 "src/parser.z"
if ((op== BinaryOperatorKind_Xor)){
#line 166 "src/parser.z"
return 6;
;
}
else {
#line 167 "src/parser.z"
if ((op== BinaryOperatorKind_BOr)){
#line 167 "src/parser.z"
return 5;
;
}
else {
#line 168 "src/parser.z"
if ((op== BinaryOperatorKind_Less)){
#line 168 "src/parser.z"
return 4;
;
}
else {
#line 169 "src/parser.z"
if ((op== BinaryOperatorKind_LessEq)){
#line 169 "src/parser.z"
return 4;
;
}
else {
#line 170 "src/parser.z"
if ((op== BinaryOperatorKind_Greater)){
#line 170 "src/parser.z"
return 4;
;
}
else {
#line 171 "src/parser.z"
if ((op== BinaryOperatorKind_GreaterEq)){
#line 171 "src/parser.z"
return 4;
;
}
else {
#line 172 "src/parser.z"
if ((op== BinaryOperatorKind_Equality)){
#line 172 "src/parser.z"
return 4;
;
}
else {
#line 173 "src/parser.z"
if ((op== BinaryOperatorKind_NotEq)){
#line 173 "src/parser.z"
return 4;
;
}
else {
#line 174 "src/parser.z"
if ((op== BinaryOperatorKind_And)){
#line 174 "src/parser.z"
return 3;
;
}
else {
#line 175 "src/parser.z"
if ((op== BinaryOperatorKind_Or)){
#line 175 "src/parser.z"
return 2;
;
}
else {
#line 176 "src/parser.z"
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

#line 179 "src/parser.z"
u32 get_current_precedence(ParsingContext*  ctx) {
#line 181 "src/parser.z"
if ((ctx->num_tokens<= ctx->current_token)){
#line 182 "src/parser.z"
return 0;
;
}
else {
#line 184 "src/parser.z"
Token tok = ctx->tokens[ctx->current_token];
;
#line 185 "src/parser.z"
u32 op_precedence = get_binary_operator_precedence(convert_token_to_binary_operator(tok.kind) ) ;
;
#line 186 "src/parser.z"
if ((op_precedence> 0)){
#line 186 "src/parser.z"
return op_precedence;
;
}
else {
#line 187 "src/parser.z"
if ((tok.kind== TokenKind_Dot)){
#line 187 "src/parser.z"
return 13;
;
}
else {
#line 188 "src/parser.z"
if (((tok.kind== TokenKind_LeftBracket)|| (tok.kind== TokenKind_LeftParen))){
#line 188 "src/parser.z"
return 12;
;
}
else {
#line 189 "src/parser.z"
if ((tok.kind== TokenKind_Equal)){
#line 189 "src/parser.z"
return 1;
;
}
else {
#line 190 "src/parser.z"
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

#line 194 "src/parser.z"
Expr*  parse_expression(ParsingContext*  ctx, u32 precedence) ;

#line 196 "src/parser.z"
Expr*  parse_integer_literal(ParsingContext*  ctx) {
#line 198 "src/parser.z"
Token tok = expect(ctx,TokenKind_Integer) ;
;
#line 200 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_Literal) ;
;
#line 201 "src/parser.z"
expr->node.lit.kind = LiteralKind_Int;
;
#line 203 "src/parser.z"
Session*  sess = ctx->sess;
;
#line 204 "src/parser.z"
expr->node.lit.value.integer = atol(get_str(&sess->interner,tok.lexeme) ) ;
;
#line 205 "src/parser.z"
return expr;
;
}

#line 208 "src/parser.z"
Expr*  parse_float_literal(ParsingContext*  ctx) {
#line 210 "src/parser.z"
Token tok = expect(ctx,TokenKind_Float) ;
;
#line 212 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_Literal) ;
;
#line 213 "src/parser.z"
expr->node.lit.kind = LiteralKind_Float;
;
#line 215 "src/parser.z"
Session*  sess = ctx->sess;
;
#line 216 "src/parser.z"
expr->node.lit.value.floating = atof(get_str(&sess->interner,tok.lexeme) ) ;
;
#line 217 "src/parser.z"
return expr;
;
}

#line 220 "src/parser.z"
Expr*  parse_char_literal(ParsingContext*  ctx) {
#line 222 "src/parser.z"
Token tok = expect(ctx,TokenKind_Char) ;
;
#line 224 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_Literal) ;
;
#line 225 "src/parser.z"
expr->node.lit.kind = LiteralKind_Char;
;
#line 227 "src/parser.z"
Session*  sess = ctx->sess;
;
#line 228 "src/parser.z"
char*  s = get_str(&sess->interner,tok.lexeme) ;
;
#line 230 "src/parser.z"
u32 len = strlen(s) ;
;
#line 231 "src/parser.z"
if (((len== 2)&& (s[0]== '\\'))){
#line 232 "src/parser.z"
char c ;
;
#line 233 "src/parser.z"
if ((s[1]== 'n')){
#line 233 "src/parser.z"
c = '\n';
;
}
else {
#line 234 "src/parser.z"
if ((s[1]== 't')){
#line 234 "src/parser.z"
c = '\t';
;
}
else {
#line 235 "src/parser.z"
if ((s[1]== 'r')){
#line 235 "src/parser.z"
c = '\r';
;
}
else {
#line 236 "src/parser.z"
if ((s[1]== '\\')){
#line 236 "src/parser.z"
c = '\\';
;
}
else {
#line 237 "src/parser.z"
if ((s[1]== '\'')){
#line 237 "src/parser.z"
c = '\'';
;
}
else {
#line 238 "src/parser.z"
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
#line 239 "src/parser.z"
expr->node.lit.value.ch = c;
;
}
else {
#line 240 "src/parser.z"
if ((len== 1)){
#line 241 "src/parser.z"
expr->node.lit.value.ch = s[0];
;
}
else {
#line 243 "src/parser.z"
emit_error(ctx->source_map,tok.span,"Invalid char literal") ;
}
;
}
;
#line 245 "src/parser.z"
return expr;
;
}

#line 248 "src/parser.z"
Expr*  parse_string_literal(ParsingContext*  ctx) {
#line 250 "src/parser.z"
Token tok = expect(ctx,TokenKind_String) ;
;
#line 252 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_Literal) ;
;
#line 253 "src/parser.z"
expr->node.lit.kind = LiteralKind_Str;
;
#line 255 "src/parser.z"
expr->node.lit.value.str = tok.lexeme;
;
#line 256 "src/parser.z"
return expr;
;
}

#line 259 "src/parser.z"
Expr*  parse_bool_literal(ParsingContext*  ctx) {
#line 261 "src/parser.z"
Token tok = consume(ctx) ;
;
#line 263 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_Literal) ;
;
#line 264 "src/parser.z"
expr->node.lit.kind = LiteralKind_Bool;
;
#line 265 "src/parser.z"
expr->node.lit.value.boolean = (tok.kind== TokenKind_True);
;
#line 266 "src/parser.z"
return expr;
;
}

#line 269 "src/parser.z"
Expr*  parse_call(ParsingContext*  ctx, Expr*  left) {
#line 271 "src/parser.z"
Expr*  result = ast_create_expr(ctx->ast,ExprKind_Call) ;
;
#line 272 "src/parser.z"
result->node.call.func = left;
;
#line 273 "src/parser.z"
result->node.call.args = malloc((8* 16)) ;
;
#line 274 "src/parser.z"
result->node.call.num_args = 0;
;
#line 276 "src/parser.z"
if (!accept(ctx,TokenKind_RightParen) ){
#line 277 "src/parser.z"
while ( true)
{
#line 278 "src/parser.z"
Expr*  expr = parse_expression(ctx,0) ;
;
#line 279 "src/parser.z"
result->node.call.args[result->node.call.num_args] = expr;
;
#line 280 "src/parser.z"
result->node.call.num_args = (result->node.call.num_args+ 1);
;
#line 281 "src/parser.z"
if (!accept(ctx,TokenKind_Comma) ){
#line 281 "src/parser.z"
break;
;
}
;
}
;
#line 283 "src/parser.z"
expect(ctx,TokenKind_RightParen) ;
}
;
#line 286 "src/parser.z"
return result;
;
}

#line 290 "src/parser.z"
Expr*  parse_prefix_operator(ParsingContext*  ctx) {
#line 291 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_Unary) ;
;
#line 293 "src/parser.z"
Token tok = consume(ctx) ;
;
#line 295 "src/parser.z"
if ((tok.kind== TokenKind_Minus)){
#line 295 "src/parser.z"
expr->node.unary.op = UnaryOperatorKind_Negation;
;
}
else {
#line 296 "src/parser.z"
if ((tok.kind== TokenKind_Bang)){
#line 296 "src/parser.z"
expr->node.unary.op = UnaryOperatorKind_Complement;
;
}
else {
#line 297 "src/parser.z"
if ((tok.kind== TokenKind_And)){
#line 297 "src/parser.z"
expr->node.unary.op = UnaryOperatorKind_Refer;
;
}
else {
#line 298 "src/parser.z"
if ((tok.kind== TokenKind_Star)){
#line 298 "src/parser.z"
expr->node.unary.op = UnaryOperatorKind_Deref;
;
}
else {
#line 299 "src/parser.z"
emit_error(ctx->source_map,tok.span,"Invalid prefix operator") ;
}
;
}
;
}
;
}
;
#line 301 "src/parser.z"
expr->node.unary.inner = parse_expression(ctx,11) ;
;
#line 303 "src/parser.z"
return expr;
;
}

#line 306 "src/parser.z"
Expr*  parse_binary_operator(ParsingContext*  ctx, Expr*  left, BinaryOperatorKind operator) {
#line 307 "src/parser.z"
u32 precedence = get_binary_operator_precedence(operator) ;
;
#line 308 "src/parser.z"
Expr*  right = parse_expression(ctx,precedence) ;
;
#line 310 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_Binary) ;
;
#line 311 "src/parser.z"
expr->node.binary.op = operator;
;
#line 312 "src/parser.z"
expr->node.binary.left = left;
;
#line 313 "src/parser.z"
expr->node.binary.right = right;
;
#line 315 "src/parser.z"
return expr;
;
}

#line 318 "src/parser.z"
Expr*  parse_field_access(ParsingContext*  ctx, Expr*  left) {
#line 319 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_Field) ;
;
#line 320 "src/parser.z"
expr->node.field.ident = parse_identifier(ctx) ;
;
#line 321 "src/parser.z"
expr->node.field.strct = left;
;
#line 323 "src/parser.z"
return expr;
;
}

#line 326 "src/parser.z"
Expr*  parse_indexing(ParsingContext*  ctx, Expr*  left) {
#line 328 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_Indexing) ;
;
#line 329 "src/parser.z"
expr->node.indexing.index = parse_expression(ctx,0) ;
;
#line 330 "src/parser.z"
expr->node.indexing.array = left;
;
#line 332 "src/parser.z"
expect(ctx,TokenKind_RightBracket) ;
#line 334 "src/parser.z"
return expr;
;
}

#line 337 "src/parser.z"
Expr*  parse_assignment(ParsingContext*  ctx, Expr*  left) {
#line 338 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_Assignment) ;
;
#line 339 "src/parser.z"
expr->node.assignment.left = left;
;
#line 340 "src/parser.z"
expr->node.assignment.right = parse_expression(ctx,0) ;
;
#line 342 "src/parser.z"
return expr;
;
}

#line 345 "src/parser.z"
Expr*  parse_infix_operator(ParsingContext*  ctx, Expr*  left, Token tok) {
#line 347 "src/parser.z"
if ((tok.kind== TokenKind_LeftParen)){
#line 347 "src/parser.z"
return parse_call(ctx,left) ;
;
}
;
#line 348 "src/parser.z"
if ((tok.kind== TokenKind_Dot)){
#line 348 "src/parser.z"
return parse_field_access(ctx,left) ;
;
}
;
#line 349 "src/parser.z"
if ((tok.kind== TokenKind_LeftBracket)){
#line 349 "src/parser.z"
return parse_indexing(ctx,left) ;
;
}
;
#line 350 "src/parser.z"
if ((tok.kind== TokenKind_Equal)){
#line 350 "src/parser.z"
return parse_assignment(ctx,left) ;
;
}
;
#line 352 "src/parser.z"
BinaryOperatorKind op = convert_token_to_binary_operator(tok.kind) ;
;
#line 353 "src/parser.z"
if ((op!= BinaryOperatorKind_Invalid)){
#line 354 "src/parser.z"
return parse_binary_operator(ctx,left,op) ;
;
}
else {
#line 356 "src/parser.z"
emit_error(ctx->source_map,tok.span,"Unsupported infix operator") ;
}
;
#line 357 "src/parser.z"
return null;
;
}

#line 360 "src/parser.z"
Block*  parse_block(ParsingContext*  ctx) {
#line 362 "src/parser.z"
Block*  block = malloc(sizeof(Block)) ;
;
#line 363 "src/parser.z"
block->exprs = malloc((8* 128)) ;
;
#line 364 "src/parser.z"
block->num_exprs = 0;
;
#line 365 "src/parser.z"
block->span.from = span_start(ctx) ;
;
#line 367 "src/parser.z"
Token next = look_ahead(ctx,0) ;
;
#line 368 "src/parser.z"
if ((next.kind== TokenKind_LeftCurly)){
#line 369 "src/parser.z"
expect(ctx,TokenKind_LeftCurly) ;
#line 370 "src/parser.z"
u32 i = 0;
;
#line 371 "src/parser.z"
while ( !accept(ctx,TokenKind_RightCurly) )
{
#line 372 "src/parser.z"
block->exprs[i] = parse_expression(ctx,0) ;
;
#line 373 "src/parser.z"
block->num_exprs = (block->num_exprs+ 1);
;
#line 374 "src/parser.z"
i = (i+ 1);
;
}
;
}
else {
#line 377 "src/parser.z"
block->exprs[0] = parse_expression(ctx,0) ;
;
#line 378 "src/parser.z"
block->num_exprs = 1;
;
}
;
#line 380 "src/parser.z"
block->span.to = span_end(ctx) ;
;
#line 382 "src/parser.z"
return block;
;
}

#line 385 "src/parser.z"
Expr*  parse_block_expr(ParsingContext*  ctx) {
#line 386 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_Block) ;
;
#line 387 "src/parser.z"
expr->node.block = parse_block(ctx) ;
;
#line 388 "src/parser.z"
return expr;
;
}

#line 391 "src/parser.z"
Expr*  parse_if(ParsingContext*  ctx) {
#line 393 "src/parser.z"
expect(ctx,TokenKind_If) ;
#line 395 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_Conditional) ;
;
#line 396 "src/parser.z"
expr->node.conditional.condition = parse_expression(ctx,0) ;
;
#line 397 "src/parser.z"
expr->node.conditional.then = parse_block_expr(ctx) ;
;
#line 399 "src/parser.z"
if (accept(ctx,TokenKind_Else) ){
#line 400 "src/parser.z"
expr->node.conditional.otherwise = parse_block_expr(ctx) ;
;
}
else {
#line 402 "src/parser.z"
expr->node.conditional.otherwise = null;
;
}
;
#line 405 "src/parser.z"
return expr;
;
}

#line 408 "src/parser.z"
Expr*  parse_while(ParsingContext*  ctx) {
#line 409 "src/parser.z"
expect(ctx,TokenKind_While) ;
#line 411 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_While) ;
;
#line 412 "src/parser.z"
expr->node.whl.condition = parse_expression(ctx,0) ;
;
#line 413 "src/parser.z"
expr->node.whl.body = parse_block_expr(ctx) ;
;
#line 415 "src/parser.z"
return expr;
;
}

#line 418 "src/parser.z"
Expr*  parse_sizeof(ParsingContext*  ctx) {
#line 419 "src/parser.z"
expect(ctx,TokenKind_Sizeof) ;
#line 420 "src/parser.z"
expect(ctx,TokenKind_LeftParen) ;
#line 422 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_Sizeof) ;
;
#line 423 "src/parser.z"
expr->node._sizeof = parse_expression(ctx,0) ;
;
#line 424 "src/parser.z"
expect(ctx,TokenKind_RightParen) ;
#line 426 "src/parser.z"
return expr;
;
}

#line 429 "src/parser.z"
Expr*  parse_let(ParsingContext*  ctx) {
#line 431 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_Let) ;
;
#line 432 "src/parser.z"
consume(ctx) ;
#line 433 "src/parser.z"
expr->node._let.pat = parse_pattern(ctx) ;
;
#line 434 "src/parser.z"
expect(ctx,TokenKind_Colon) ;
#line 435 "src/parser.z"
expr->node._let.ty = parse_type(ctx) ;
;
#line 437 "src/parser.z"
if (accept(ctx,TokenKind_Equal) ){
#line 437 "src/parser.z"
expr->node._let.value = parse_expression(ctx,0) ;
;
}
else {
#line 438 "src/parser.z"
expr->node._let.value = 0;
;
}
;
#line 440 "src/parser.z"
return expr;
;
}

#line 444 "src/parser.z"
Expr*  parse_control_flow(ParsingContext*  ctx) {
#line 445 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_ControlFlow) ;
;
#line 446 "src/parser.z"
expr->node.control_flow_is_continue = accept(ctx,TokenKind_Continue) ;
;
#line 448 "src/parser.z"
if (!expr->node.control_flow_is_continue){
#line 448 "src/parser.z"
expect(ctx,TokenKind_Break) ;
}
;
#line 450 "src/parser.z"
return expr;
;
}

#line 453 "src/parser.z"
Expr*  parse_return(ParsingContext*  ctx) {
#line 454 "src/parser.z"
expect(ctx,TokenKind_Return) ;
#line 455 "src/parser.z"
Expr*  expr = ast_create_expr(ctx->ast,ExprKind_Return) ;
;
#line 456 "src/parser.z"
expr->node._return = parse_expression(ctx,0) ;
;
#line 458 "src/parser.z"
return expr;
;
}

#line 461 "src/parser.z"
Expr*  parse_expression(ParsingContext*  ctx, u32 precedence) {
#line 462 "src/parser.z"
Token tok = look_ahead(ctx,0) ;
;
#line 463 "src/parser.z"
Span span ;
;
#line 464 "src/parser.z"
span.from = span_start(ctx) ;
;
#line 466 "src/parser.z"
Expr*  left ;
;
#line 468 "src/parser.z"
if ((tok.kind== TokenKind_Integer)){
#line 468 "src/parser.z"
left = parse_integer_literal(ctx) ;
;
}
else {
#line 469 "src/parser.z"
if ((tok.kind== TokenKind_Char)){
#line 469 "src/parser.z"
left = parse_char_literal(ctx) ;
;
}
else {
#line 470 "src/parser.z"
if ((tok.kind== TokenKind_String)){
#line 470 "src/parser.z"
left = parse_string_literal(ctx) ;
;
}
else {
#line 471 "src/parser.z"
if ((tok.kind== TokenKind_Float)){
#line 471 "src/parser.z"
left = parse_float_literal(ctx) ;
;
}
else {
#line 472 "src/parser.z"
if (((tok.kind== TokenKind_False)|| (tok.kind== TokenKind_True))){
#line 472 "src/parser.z"
left = parse_bool_literal(ctx) ;
;
}
else {
#line 473 "src/parser.z"
if (((((tok.kind== TokenKind_Minus)|| (tok.kind== TokenKind_Bang))|| (tok.kind== TokenKind_And))|| (tok.kind== TokenKind_Star))){
#line 474 "src/parser.z"
left = parse_prefix_operator(ctx) ;
;
}
else {
#line 475 "src/parser.z"
if ((tok.kind== TokenKind_If)){
#line 475 "src/parser.z"
left = parse_if(ctx) ;
;
}
else {
#line 476 "src/parser.z"
if ((tok.kind== TokenKind_Sizeof)){
#line 476 "src/parser.z"
left = parse_sizeof(ctx) ;
;
}
else {
#line 477 "src/parser.z"
if ((tok.kind== TokenKind_While)){
#line 477 "src/parser.z"
left = parse_while(ctx) ;
;
}
else {
#line 478 "src/parser.z"
if (((tok.kind== TokenKind_Continue)|| (tok.kind== TokenKind_Break))){
#line 478 "src/parser.z"
left = parse_control_flow(ctx) ;
;
}
else {
#line 479 "src/parser.z"
if ((tok.kind== TokenKind_Return)){
#line 479 "src/parser.z"
left = parse_return(ctx) ;
;
}
else {
#line 480 "src/parser.z"
if (((tok.kind== TokenKind_Var)|| (tok.kind== TokenKind_Val))){
#line 480 "src/parser.z"
left = parse_let(ctx) ;
;
}
else {
#line 481 "src/parser.z"
if ((tok.kind== TokenKind_Identifier)){
#line 481 "src/parser.z"
left = parse_path_expr(ctx) ;
;
}
else {
#line 482 "src/parser.z"
if ((tok.kind== TokenKind_LeftParen)){
#line 483 "src/parser.z"
expect(ctx,TokenKind_LeftParen) ;
#line 484 "src/parser.z"
left = parse_expression(ctx,0) ;
;
#line 485 "src/parser.z"
expect(ctx,TokenKind_RightParen) ;
}
else {
#line 487 "src/parser.z"
if ((tok.kind== TokenKind_LeftCurly)){
#line 487 "src/parser.z"
left = parse_block_expr(ctx) ;
;
}
else {
#line 488 "src/parser.z"
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
}
;
}
;
}
;
}
;
#line 490 "src/parser.z"
while ( (precedence< get_current_precedence(ctx) ))
{
#line 491 "src/parser.z"
Token next_tok = consume(ctx) ;
;
#line 492 "src/parser.z"
left = parse_infix_operator(ctx,left,next_tok) ;
;
}
;
#line 494 "src/parser.z"
span.to = span_end(ctx) ;
;
#line 495 "src/parser.z"
left->span = span;
;
#line 497 "src/parser.z"
accept(ctx,TokenKind_Semicolon) ;
#line 499 "src/parser.z"
return left;
;
}

#line 502 "src/parser.z"
Generics parse_generics(ParsingContext*  ctx) {
#line 503 "src/parser.z"
expect(ctx,TokenKind_Less) ;
#line 504 "src/parser.z"
Generics generics ;
;
#line 505 "src/parser.z"
generics.parameters = malloc((4* sizeof(GenericParam))) ;
;
#line 506 "src/parser.z"
generics.num_parameters = 0;
;
#line 508 "src/parser.z"
while ( !accept(ctx,TokenKind_Greater) )
{
#line 509 "src/parser.z"
generics.parameters[generics.num_parameters].ident = parse_identifier(ctx) ;
;
#line 511 "src/parser.z"
accept(ctx,TokenKind_Comma) ;
#line 512 "src/parser.z"
generics.num_parameters = (generics.num_parameters+ 1);
;
}
;
#line 514 "src/parser.z"
return generics;
;
}

#line 517 "src/parser.z"
void  parse_variable_decl(ParsingContext*  ctx, Item*  item) {
#line 519 "src/parser.z"
Token keyword = consume(ctx) ;
;
#line 520 "src/parser.z"
if ((keyword.kind== TokenKind_Val)){
#line 520 "src/parser.z"
item->kind = ItemKind_Const;
;
}
else {
#line 521 "src/parser.z"
if ((keyword.kind== TokenKind_Var)){
#line 521 "src/parser.z"
item->kind = ItemKind_Variable;
;
}
else {
#line 522 "src/parser.z"
abort() ;
}
;
}
;
#line 524 "src/parser.z"
item->ident = parse_identifier(ctx) ;
;
#line 525 "src/parser.z"
expect(ctx,TokenKind_Colon) ;
#line 526 "src/parser.z"
item->node.variable.ty = parse_type(ctx) ;
;
#line 528 "src/parser.z"
if (accept(ctx,TokenKind_Equal) ){
#line 528 "src/parser.z"
item->node.variable.body = parse_expression(ctx,0) ;
;
}
else {
#line 529 "src/parser.z"
item->node.variable.body = 0;
;
}
;
}

#line 532 "src/parser.z"
void  parse_compound_decl(ParsingContext*  ctx, Item*  item) {
#line 534 "src/parser.z"
if (accept(ctx,TokenKind_Struct) ){
#line 534 "src/parser.z"
item->kind = ItemKind_Struct;
;
}
else {
#line 535 "src/parser.z"
if (accept(ctx,TokenKind_Union) ){
#line 535 "src/parser.z"
item->kind = ItemKind_Union;
;
}
else {
#line 536 "src/parser.z"
abort() ;
}
;
}
;
#line 538 "src/parser.z"
item->ident = parse_identifier(ctx) ;
;
#line 540 "src/parser.z"
if (can_accept(ctx,TokenKind_Less) ){
#line 540 "src/parser.z"
item->node.compound.generics = parse_generics(ctx) ;
;
}
else {
#line 541 "src/parser.z"
item->node.compound.generics.num_parameters = 0;
;
}
;
#line 543 "src/parser.z"
expect(ctx,TokenKind_LeftCurly) ;
#line 545 "src/parser.z"
item->node.compound.fields = malloc((sizeof(CompoundField)* 16)) ;
;
#line 546 "src/parser.z"
item->node.compound.num_fields = 0;
;
#line 548 "src/parser.z"
while ( !accept(ctx,TokenKind_RightCurly) )
{
#line 549 "src/parser.z"
Token token = consume(ctx) ;
;
#line 550 "src/parser.z"
if ((token.kind!= TokenKind_Identifier)){
#line 550 "src/parser.z"
emit_error(ctx->source_map,token.span,"Expected field identifier") ;
}
;
#line 552 "src/parser.z"
item->node.compound.fields[item->node.compound.num_fields].ident.name = token.lexeme;
;
#line 553 "src/parser.z"
expect(ctx,TokenKind_Colon) ;
#line 555 "src/parser.z"
AstType*  type = parse_type(ctx) ;
;
#line 556 "src/parser.z"
item->node.compound.fields[item->node.compound.num_fields].ty = type;
;
#line 557 "src/parser.z"
item->node.compound.num_fields = (item->node.compound.num_fields+ 1);
;
#line 558 "src/parser.z"
expect(ctx,TokenKind_Comma) ;
}
;
}

#line 563 "src/parser.z"
void  parse_enum_decl(ParsingContext*  ctx, Item*  item) {
#line 565 "src/parser.z"
expect(ctx,TokenKind_Enum) ;
#line 566 "src/parser.z"
item->kind = ItemKind_Enum;
;
#line 568 "src/parser.z"
item->ident = parse_identifier(ctx) ;
;
#line 570 "src/parser.z"
expect(ctx,TokenKind_LeftCurly) ;
#line 572 "src/parser.z"
item->node._enum.variants = malloc((sizeof(EnumVariant)* 128)) ;
;
#line 573 "src/parser.z"
item->node._enum.num_variants = 0;
;
#line 575 "src/parser.z"
while ( !accept(ctx,TokenKind_RightCurly) )
{
#line 576 "src/parser.z"
item->node._enum.variants[item->node._enum.num_variants].ident = parse_identifier(ctx) ;
;
#line 577 "src/parser.z"
item->node._enum.num_variants = (item->node._enum.num_variants+ 1);
;
#line 578 "src/parser.z"
expect(ctx,TokenKind_Comma) ;
}
;
}

#line 582 "src/parser.z"
FunctionHeader parse_function_header(ParsingContext*  ctx) {
#line 583 "src/parser.z"
FunctionHeader header ;
;
#line 585 "src/parser.z"
header.parameters = malloc((sizeof(FunctionParameter)* 16)) ;
;
#line 586 "src/parser.z"
header.num_parameters = 0;
;
#line 588 "src/parser.z"
if (can_accept(ctx,TokenKind_Less) ){
#line 588 "src/parser.z"
header.generics = parse_generics(ctx) ;
;
}
else {
#line 589 "src/parser.z"
header.generics.num_parameters = 0;
;
}
;
#line 591 "src/parser.z"
expect(ctx,TokenKind_LeftParen) ;
#line 593 "src/parser.z"
while ( !accept(ctx,TokenKind_RightParen) )
{
#line 595 "src/parser.z"
header.parameters[header.num_parameters].pat = parse_pattern(ctx) ;
;
#line 597 "src/parser.z"
expect(ctx,TokenKind_Colon) ;
#line 598 "src/parser.z"
AstType*  type = parse_type(ctx) ;
;
#line 599 "src/parser.z"
header.parameters[header.num_parameters].ty = type;
;
#line 600 "src/parser.z"
header.num_parameters = (header.num_parameters+ 1);
;
#line 602 "src/parser.z"
accept(ctx,TokenKind_Comma) ;
}
;
#line 605 "src/parser.z"
if (accept(ctx,TokenKind_Arrow) ){
#line 605 "src/parser.z"
header.output = parse_type(ctx) ;
;
}
else {
#line 608 "src/parser.z"
AstType*  output = malloc(sizeof(AstType)) ;
;
#line 609 "src/parser.z"
output->kind = AstTypeKind_Void;
;
#line 610 "src/parser.z"
header.output = output;
;
}
;
#line 613 "src/parser.z"
return header;
;
}

#line 616 "src/parser.z"
void  parse_function_decl(ParsingContext*  ctx, Item*  item) {
#line 618 "src/parser.z"
item->kind = ItemKind_Function;
;
#line 619 "src/parser.z"
item->node.function.is_extern = accept(ctx,TokenKind_Extern) ;
;
#line 621 "src/parser.z"
expect(ctx,TokenKind_Fn) ;
#line 623 "src/parser.z"
item->ident = parse_identifier(ctx) ;
;
#line 625 "src/parser.z"
item->node.function.header = parse_function_header(ctx) ;
;
#line 627 "src/parser.z"
if ((look_ahead(ctx,0) .kind== TokenKind_LeftCurly)){
#line 627 "src/parser.z"
item->node.function.body = parse_expression(ctx,0) ;
;
}
else {
#line 628 "src/parser.z"
item->node.function.body = 0;
;
}
;
}

#line 631 "src/parser.z"
void  parse_use(ParsingContext*  ctx, Item*  item) {
#line 632 "src/parser.z"
expect(ctx,TokenKind_Use) ;
#line 634 "src/parser.z"
item->kind = ItemKind_Use;
;
#line 635 "src/parser.z"
item->node._use = parse_path(ctx) ;
;
#line 637 "src/parser.z"
accept(ctx,TokenKind_Semicolon) ;
}

#line 640 "src/parser.z"
Module*  parse_mod_inner(ParsingContext*  ctx, Ident name) ;

#line 641 "src/parser.z"
Module*  parse_mod_external(Session*  sess, Ast*  ast, char*  path, Module*  parent) ;

#line 643 "src/parser.z"
void  parse_mod(ParsingContext*  ctx, Item*  item) {
#line 644 "src/parser.z"
expect(ctx,TokenKind_Mod) ;
#line 646 "src/parser.z"
item->ident = parse_identifier(ctx) ;
;
#line 647 "src/parser.z"
item->kind = ItemKind_Module;
;
#line 649 "src/parser.z"
if (accept(ctx,TokenKind_LeftCurly) ){
#line 649 "src/parser.z"
item->node.module = parse_mod_inner(ctx,item->ident) ;
;
}
else {
#line 651 "src/parser.z"
Session*  sess = ctx->sess;
;
#line 652 "src/parser.z"
char*  path = get_str(&sess->interner,item->ident.name) ;
;
#line 653 "src/parser.z"
item->node.module = parse_mod_external(ctx->sess,ctx->ast,path,ctx->current_module) ;
;
}
;
}

#line 658 "src/parser.z"
Item*  parse_item(ParsingContext*  ctx) {
#line 659 "src/parser.z"
Token tok = look_ahead(ctx,0) ;
;
#line 661 "src/parser.z"
Item*  item = ast_create_item(ctx->ast) ;
;
#line 662 "src/parser.z"
item->span.from = span_start(ctx) ;
;
#line 664 "src/parser.z"
if (((tok.kind== TokenKind_Fn)|| (tok.kind== TokenKind_Extern))){
#line 664 "src/parser.z"
parse_function_decl(ctx,item) ;
}
else {
#line 665 "src/parser.z"
if (((tok.kind== TokenKind_Struct)|| (tok.kind== TokenKind_Union))){
#line 665 "src/parser.z"
parse_compound_decl(ctx,item) ;
}
else {
#line 666 "src/parser.z"
if ((tok.kind== TokenKind_Enum)){
#line 666 "src/parser.z"
parse_enum_decl(ctx,item) ;
}
else {
#line 667 "src/parser.z"
if (((tok.kind== TokenKind_Var)|| (tok.kind== TokenKind_Val))){
#line 667 "src/parser.z"
parse_variable_decl(ctx,item) ;
}
else {
#line 668 "src/parser.z"
if ((tok.kind== TokenKind_Use)){
#line 668 "src/parser.z"
parse_use(ctx,item) ;
}
else {
#line 669 "src/parser.z"
if ((tok.kind== TokenKind_Mod)){
#line 669 "src/parser.z"
parse_mod(ctx,item) ;
}
else {
#line 670 "src/parser.z"
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
#line 672 "src/parser.z"
accept(ctx,TokenKind_Semicolon) ;
#line 674 "src/parser.z"
item->span.to = span_end(ctx) ;
;
#line 675 "src/parser.z"
return item;
;
}

#line 678 "src/parser.z"
Module*  parse_mod_inner(ParsingContext*  ctx, Ident name) {
#line 679 "src/parser.z"
Module*  module = malloc(sizeof(Module)) ;
;
#line 680 "src/parser.z"
module->span.from = span_start(ctx) ;
;
#line 681 "src/parser.z"
module->items = malloc((8* 2048)) ;
;
#line 682 "src/parser.z"
module->num_items = 0;
;
#line 683 "src/parser.z"
module->index_lookup = intmap_create(2048) ;
;
#line 684 "src/parser.z"
module->index = malloc((sizeof(IndexEntry)* 2048)) ;
;
#line 685 "src/parser.z"
module->num_indices = 1;
;
#line 686 "src/parser.z"
module->parent = ctx->current_module;
;
#line 688 "src/parser.z"
Module*  parent = module->parent;
;
#line 690 "src/parser.z"
if (parent){
#line 690 "src/parser.z"
module->path.num_segments = (parent->path.num_segments+ 1);
;
}
else {
#line 691 "src/parser.z"
module->path.num_segments = 1;
;
}
;
#line 693 "src/parser.z"
module->path.segments = malloc((sizeof(Ident)* module->path.num_segments)) ;
;
#line 694 "src/parser.z"
if (parent){
#line 694 "src/parser.z"
memcpy(module->path.segments,parent->path.segments,(parent->path.num_segments* sizeof(Ident))) ;
}
;
#line 695 "src/parser.z"
module->path.segments[(module->path.num_segments- 1)] = name;
;
#line 697 "src/parser.z"
ctx->current_module = module;
;
#line 699 "src/parser.z"
while ( (!accept(ctx,TokenKind_RightCurly) && !is_done_parsing(ctx) ))
{
#line 700 "src/parser.z"
module->items[module->num_items] = parse_item(ctx) ;
;
#line 701 "src/parser.z"
module->num_items = (module->num_items+ 1);
;
}
;
#line 704 "src/parser.z"
module->span.to = span_end(ctx) ;
;
#line 706 "src/parser.z"
ctx->current_module = module->parent;
;
#line 708 "src/parser.z"
return module;
;
}

#line 711 "src/parser.z"
Module*  parse_mod_external(Session*  sess, Ast*  ast, char*  path, Module*  parent) {
#line 713 "src/parser.z"
SourceFile*  source_file = source_map_new_file(&sess->source,sess->root_path,path) ;
;
#line 715 "src/parser.z"
u32 num_tokens ;
;
#line 716 "src/parser.z"
Token*  tokens = lex(sess,source_file,&num_tokens) ;
;
#line 718 "src/parser.z"
ParsingContext ctx ;
;
#line 719 "src/parser.z"
ctx.current_token = 0;
;
#line 720 "src/parser.z"
ctx.tokens = tokens;
;
#line 721 "src/parser.z"
ctx.num_tokens = num_tokens;
;
#line 722 "src/parser.z"
ctx.source_map = &sess->source;
;
#line 723 "src/parser.z"
ctx.sess = sess;
;
#line 724 "src/parser.z"
ctx.ast = ast;
;
#line 725 "src/parser.z"
ctx.current_module = parent;
;
#line 727 "src/parser.z"
Ident name_ident ;
;
#line 728 "src/parser.z"
name_ident.name = intern(&sess->interner,path) ;
;
#line 729 "src/parser.z"
name_ident.span.from = 0;
;
#line 730 "src/parser.z"
name_ident.span.to = 0;
;
#line 732 "src/parser.z"
Module*  module = parse_mod_inner(&ctx,name_ident) ;
;
#line 734 "src/parser.z"
return module;
;
}

#line 737 "src/parser.z"
Module*  create_root_module(Session*  sess, Ast*  ast, char*  path) {
#line 739 "src/parser.z"
Module*  module = malloc(sizeof(Module)) ;
;
#line 740 "src/parser.z"
module->items = malloc((8* 2048)) ;
;
#line 741 "src/parser.z"
module->index_lookup = intmap_create(2048) ;
;
#line 742 "src/parser.z"
module->index = malloc((sizeof(IndexEntry)* 2048)) ;
;
#line 743 "src/parser.z"
module->num_indices = 1;
;
#line 744 "src/parser.z"
module->parent = null;
;
#line 746 "src/parser.z"
Item*  main_item = ast_create_item(ast) ;
;
#line 747 "src/parser.z"
main_item->kind = ItemKind_Module;
;
#line 748 "src/parser.z"
main_item->ident.name = intern(&sess->interner,path) ;
;
#line 750 "src/parser.z"
Module*  main_module = parse_mod_external(sess,ast,path,module) ;
;
#line 751 "src/parser.z"
main_item->span.from = main_module->span.from;
;
#line 752 "src/parser.z"
main_item->span.to = main_module->span.to;
;
#line 753 "src/parser.z"
main_item->node.module = main_module;
;
#line 754 "src/parser.z"
module->items[0] = main_item;
;
#line 755 "src/parser.z"
module->num_items = 1;
;
#line 757 "src/parser.z"
return module;
;
}

#line 760 "src/parser.z"
Ast parse(Session*  sess, char*  root_module_name) {
#line 762 "src/parser.z"
Ast ast ;
;
#line 764 "src/parser.z"
ast.items = malloc((sizeof(Item)* 2048)) ;
;
#line 765 "src/parser.z"
ast.num_items = 1;
;
#line 767 "src/parser.z"
ast.root_module = create_root_module(sess,&ast,root_module_name) ;
;
#line 769 "src/parser.z"
return ast;
;
}


typedef struct VariableInfo VariableInfo;
#line 1 "src/resolution.z"
typedef struct VariableInfo {
Ident ident;
u32 slot;
} VariableInfo;


typedef struct VariableBlock VariableBlock;
#line 6 "src/resolution.z"
typedef struct VariableBlock {
VariableInfo*  variables;
u32 num_variables;
} VariableBlock;


#line 11 "src/resolution.z"
typedef enum ScopeKind {
ScopeKind_VariableBlock,
ScopeKind_Module,
} ScopeKind;


typedef union ScopeNode ScopeNode;
#line 16 "src/resolution.z"
typedef union ScopeNode {
Module*  module;
VariableBlock variable;
} ScopeNode;


typedef struct Scope Scope;
#line 21 "src/resolution.z"
typedef struct Scope {
ScopeKind kind;
ScopeNode node;
} Scope;


typedef struct PrimitiveTypeSids PrimitiveTypeSids;
#line 26 "src/resolution.z"
typedef struct PrimitiveTypeSids {
Sid _void;
Sid _bool;
Sid _char;
Sid _i8;
Sid _i16;
Sid _i32;
Sid _i64;
Sid _u8;
Sid _u16;
Sid _u32;
Sid _u64;
Sid _f32;
Sid _f64;
} PrimitiveTypeSids;


#line 42 "src/resolution.z"
void  setup_primitive_ty_sids(Interner*  i, PrimitiveTypeSids*  p) {
#line 43 "src/resolution.z"
p->_void = intern(i,"void") ;
;
#line 44 "src/resolution.z"
p->_bool = intern(i,"bool") ;
;
#line 45 "src/resolution.z"
p->_char = intern(i,"char") ;
;
#line 46 "src/resolution.z"
p->_i8 = intern(i,"i8") ;
;
#line 47 "src/resolution.z"
p->_i16 = intern(i,"i16") ;
;
#line 48 "src/resolution.z"
p->_i32 = intern(i,"i32") ;
;
#line 49 "src/resolution.z"
p->_i64 = intern(i,"i64") ;
;
#line 50 "src/resolution.z"
p->_u8 = intern(i,"u8") ;
;
#line 51 "src/resolution.z"
p->_u16 = intern(i,"u16") ;
;
#line 52 "src/resolution.z"
p->_u32 = intern(i,"u32") ;
;
#line 53 "src/resolution.z"
p->_u64 = intern(i,"u64") ;
;
#line 54 "src/resolution.z"
p->_f32 = intern(i,"f32") ;
;
#line 55 "src/resolution.z"
p->_f64 = intern(i,"f64") ;
;
}

typedef struct ResolutionContext ResolutionContext;
#line 58 "src/resolution.z"
typedef struct ResolutionContext {
Scope*  scope_stack;
u32 stack_top;
Ast*  ast;
SourceMap*  source_map;
Interner*  interner;
Module*  root_module;
PrimitiveTypeSids primitive_ty_sids;
} ResolutionContext;


#line 68 "src/resolution.z"
void  push_block(ResolutionContext*  ctx) {
#line 69 "src/resolution.z"
ctx->stack_top = (ctx->stack_top+ 1);
;
#line 70 "src/resolution.z"
Scope*  scope = &ctx->scope_stack[ctx->stack_top];
;
#line 72 "src/resolution.z"
scope->kind = ScopeKind_VariableBlock;
;
#line 73 "src/resolution.z"
scope->node.variable.variables = malloc((8* 32)) ;
;
#line 74 "src/resolution.z"
scope->node.variable.num_variables = 0;
;
}

#line 77 "src/resolution.z"
void  pop_block(ResolutionContext*  ctx) {
#line 78 "src/resolution.z"
Scope*  scope = &ctx->scope_stack[ctx->stack_top];
;
#line 79 "src/resolution.z"
free(scope->node.variable.variables) ;
#line 80 "src/resolution.z"
ctx->stack_top = (ctx->stack_top- 1);
;
}

#line 83 "src/resolution.z"
u32 push_variable(ResolutionContext*  ctx, Ident ident) {
#line 84 "src/resolution.z"
Scope*  scope = &ctx->scope_stack[ctx->stack_top];
;
#line 85 "src/resolution.z"
if ((scope->kind!= ScopeKind_VariableBlock)){
#line 85 "src/resolution.z"
abort() ;
}
;
#line 86 "src/resolution.z"
VariableBlock*  v = &scope->node.variable;
;
#line 87 "src/resolution.z"
v->variables[v->num_variables].ident = ident;
;
#line 88 "src/resolution.z"
v->variables[v->num_variables].slot = v->num_variables;
;
#line 89 "src/resolution.z"
v->num_variables = (v->num_variables+ 1);
;
#line 90 "src/resolution.z"
return v->variables[v->num_variables].slot;
;
}

#line 93 "src/resolution.z"
void  push_module(ResolutionContext*  ctx, Module*  module) {
#line 94 "src/resolution.z"
ctx->stack_top = (ctx->stack_top+ 1);
;
#line 95 "src/resolution.z"
Scope*  scope = &ctx->scope_stack[ctx->stack_top];
;
#line 97 "src/resolution.z"
scope->kind = ScopeKind_Module;
;
#line 98 "src/resolution.z"
scope->node.module = module;
;
}

#line 101 "src/resolution.z"
void  pop_module(ResolutionContext*  ctx) {
#line 102 "src/resolution.z"
ctx->stack_top = (ctx->stack_top- 1);
;
}

#line 107 "src/resolution.z"
Path lookup(ResolutionContext*  ctx, Ident ident) {
#line 108 "src/resolution.z"
i32 i = ctx->stack_top;
;
#line 109 "src/resolution.z"
while ( (i> 0))
{
#line 110 "src/resolution.z"
Scope*  scope = &ctx->scope_stack[i];
;
#line 111 "src/resolution.z"
if ((scope->kind== ScopeKind_Module)){
#line 112 "src/resolution.z"
Module*  module = scope->node.module;
;
#line 113 "src/resolution.z"
u32 idx = intmap_lookup(module->index_lookup,ident.name.x) ;
;
#line 114 "src/resolution.z"
if ((idx> 0)){
#line 115 "src/resolution.z"
IndexEntry entry = module->index[idx];
;
#line 116 "src/resolution.z"
return entry.path;
;
}
;
}
else {
#line 119 "src/resolution.z"
if ((scope->kind== ScopeKind_VariableBlock)){
#line 120 "src/resolution.z"
VariableBlock*  block = &scope->node.variable;
;
#line 121 "src/resolution.z"
i32 j = (block->num_variables- 1);
;
#line 122 "src/resolution.z"
while ( (j>= 0))
{
#line 123 "src/resolution.z"
VariableInfo variable = block->variables[j];
;
#line 124 "src/resolution.z"
if ((variable.ident.name.x== ident.name.x)){
#line 125 "src/resolution.z"
Path path ;
;
#line 126 "src/resolution.z"
path.segments = malloc(sizeof(Ident)) ;
;
#line 127 "src/resolution.z"
path.segments[0] = variable.ident;
;
#line 128 "src/resolution.z"
path.num_segments = 1;
;
#line 129 "src/resolution.z"
path.binding.kind = BindingKind_Variable;
;
#line 130 "src/resolution.z"
path.binding.node.slot = variable.slot;
;
#line 131 "src/resolution.z"
return path;
;
}
;
#line 133 "src/resolution.z"
j = (j- 1);
;
}
;
}
;
}
;
#line 136 "src/resolution.z"
i = (i- 1);
;
}
;
#line 138 "src/resolution.z"
emit_error(ctx->source_map,ident.span,"Unable to resolve item") ;
#line 139 "src/resolution.z"
abort() ;
}

#line 142 "src/resolution.z"
Binding index_use_binding(ResolutionContext*  ctx, Path path) {
#line 143 "src/resolution.z"
Module*  cur_mod = ctx->root_module;
;
#line 144 "src/resolution.z"
u32 i = 0;
;
#line 145 "src/resolution.z"
while ( true)
{
#line 146 "src/resolution.z"
u32 j = 0;
;
#line 147 "src/resolution.z"
bool found = false;
;
#line 148 "src/resolution.z"
while ( (j< cur_mod->num_items))
{
#line 149 "src/resolution.z"
Item*  item = cur_mod->items[j];
;
#line 150 "src/resolution.z"
if ((item->ident.name.x== path.segments[i].name.x)){
#line 151 "src/resolution.z"
if ((item->kind== ItemKind_Module)){
#line 152 "src/resolution.z"
cur_mod = item->node.module;
;
}
else {
#line 154 "src/resolution.z"
if ((i!= (path.num_segments- 1))){
#line 154 "src/resolution.z"
emit_error(ctx->source_map,path.span,"Invalid path in use") ;
}
;
}
;
#line 156 "src/resolution.z"
if (((i== (path.num_segments- 1))|| (path.segments[(i+ 1)].name.x== 0))){
#line 157 "src/resolution.z"
Binding binding ;
;
#line 158 "src/resolution.z"
binding.kind = BindingKind_Item;
;
#line 159 "src/resolution.z"
binding.node.item = item;
;
#line 160 "src/resolution.z"
return binding;
;
}
;
#line 163 "src/resolution.z"
found = true;
;
}
;
#line 165 "src/resolution.z"
j = (j+ 1);
;
}
;
#line 167 "src/resolution.z"
if (!found){
#line 167 "src/resolution.z"
emit_error(ctx->source_map,path.span,"Unable to resolve use") ;
}
;
#line 168 "src/resolution.z"
i = (i+ 1);
;
}
;
}

#line 172 "src/resolution.z"
void  absolute_use(ResolutionContext*  ctx, Module*  module, Item*  item) {
#line 173 "src/resolution.z"
Path*  p = &item->node._use;
;
#line 174 "src/resolution.z"
Path abs ;
;
#line 175 "src/resolution.z"
if ((p->segments[0].name.x== intern(ctx->interner,"self") .x)){
#line 176 "src/resolution.z"
abs.num_segments = ((module->path.num_segments+ p->num_segments)- 1);
;
#line 177 "src/resolution.z"
abs.segments = malloc((sizeof(Ident)* abs.num_segments)) ;
;
#line 178 "src/resolution.z"
memcpy(abs.segments,module->path.segments,(sizeof(Ident)* module->path.num_segments)) ;
#line 179 "src/resolution.z"
memcpy(&abs.segments[module->path.num_segments],&p->segments[1],(sizeof(Ident)* (p->num_segments- 1))) ;
#line 180 "src/resolution.z"
*p = abs;
;
}
else {
#line 182 "src/resolution.z"
if ((p->segments[0].name.x== intern(ctx->interner,"super") .x)){
#line 183 "src/resolution.z"
Module*  parent = module->parent;
;
#line 184 "src/resolution.z"
abs.num_segments = ((parent->path.num_segments+ p->num_segments)- 1);
;
#line 185 "src/resolution.z"
abs.segments = malloc((sizeof(Ident)* abs.num_segments)) ;
;
#line 186 "src/resolution.z"
memcpy(abs.segments,parent->path.segments,(sizeof(Ident)* parent->path.num_segments)) ;
#line 187 "src/resolution.z"
memcpy(&abs.segments[parent->path.num_segments],&p->segments[1],(sizeof(Ident)* (p->num_segments- 1))) ;
#line 188 "src/resolution.z"
*p = abs;
;
}
;
}
;
}

#line 192 "src/resolution.z"
void  index_use(ResolutionContext*  ctx, Module*  module) {
#line 193 "src/resolution.z"
u32 i = 0;
;
#line 194 "src/resolution.z"
while ( (i< module->num_items))
{
#line 195 "src/resolution.z"
Item*  item = module->items[i];
;
#line 196 "src/resolution.z"
if ((item->kind== ItemKind_Use)){
#line 197 "src/resolution.z"
absolute_use(ctx,module,item) ;
#line 198 "src/resolution.z"
Path*  path = &item->node._use;
;
#line 199 "src/resolution.z"
path->binding = index_use_binding(ctx,*path) ;
;
}
;
#line 202 "src/resolution.z"
if ((item->kind== ItemKind_Module)){
#line 203 "src/resolution.z"
index_use(ctx,item->node.module) ;
}
;
#line 206 "src/resolution.z"
i = (i+ 1);
;
}
;
}

#line 210 "src/resolution.z"
void  add_item(ResolutionContext*  ctx, Module*  module, Item*  item) {
#line 212 "src/resolution.z"
IndexEntry*  idx_entry = &module->index[module->num_indices];
;
#line 215 "src/resolution.z"
idx_entry->path.num_segments = 1;
;
#line 216 "src/resolution.z"
idx_entry->path.segments = malloc((sizeof(Ident)* idx_entry->path.num_segments)) ;
;
#line 218 "src/resolution.z"
idx_entry->path.segments[0] = item->ident;
;
#line 219 "src/resolution.z"
idx_entry->path.binding.kind = BindingKind_Item;
;
#line 220 "src/resolution.z"
idx_entry->path.binding.node.item = item;
;
#line 222 "src/resolution.z"
intmap_insert(module->index_lookup,item->ident.name.x,module->num_indices) ;
#line 224 "src/resolution.z"
module->num_indices = (module->num_indices+ 1);
;
}

#line 227 "src/resolution.z"
void  index_module(ResolutionContext*  ctx, Module*  module) {
#line 228 "src/resolution.z"
u32 i = 0;
;
#line 229 "src/resolution.z"
while ( (i< module->num_items))
{
#line 230 "src/resolution.z"
Item*  item = module->items[i];
;
#line 232 "src/resolution.z"
if ((item->kind== ItemKind_Use)){
#line 233 "src/resolution.z"
Path path = item->node._use;
;
#line 235 "src/resolution.z"
if ((path.segments[(path.num_segments- 1)].name.x!= 0)){
#line 236 "src/resolution.z"
add_item(ctx,module,path.binding.node.item) ;
}
;
}
else {
#line 239 "src/resolution.z"
add_item(ctx,module,item) ;
}
;
#line 241 "src/resolution.z"
i = (i+ 1);
;
}
;
#line 244 "src/resolution.z"
i = 0;
;
#line 245 "src/resolution.z"
while ( (i< module->num_items))
{
#line 246 "src/resolution.z"
Item*  item = module->items[i];
;
#line 247 "src/resolution.z"
if ((item->kind== ItemKind_Module)){
#line 247 "src/resolution.z"
index_module(ctx,item->node.module) ;
}
;
#line 248 "src/resolution.z"
i = (i+ 1);
;
}
;
}

#line 252 "src/resolution.z"
void  index_module_wildcards(ResolutionContext*  ctx, Module*  module) {
#line 253 "src/resolution.z"
u32 i = 0;
;
#line 254 "src/resolution.z"
while ( (i< module->num_items))
{
#line 255 "src/resolution.z"
Item*  item = module->items[i];
;
#line 257 "src/resolution.z"
if ((item->kind== ItemKind_Use)){
#line 258 "src/resolution.z"
Path path = item->node._use;
;
#line 259 "src/resolution.z"
if ((path.segments[(path.num_segments- 1)].name.x== 0)){
#line 260 "src/resolution.z"
Item*  bound = path.binding.node.item;
;
#line 261 "src/resolution.z"
if ((bound->kind== ItemKind_Module)){
#line 262 "src/resolution.z"
Module*  m = bound->node.module;
;
#line 263 "src/resolution.z"
u32 j = 0;
;
#line 264 "src/resolution.z"
while ( (j< m->num_items))
{
#line 265 "src/resolution.z"
Item*  it = m->items[j];
;
#line 266 "src/resolution.z"
add_item(ctx,module,it) ;
#line 267 "src/resolution.z"
j = (j+ 1);
;
}
;
}
else {
#line 270 "src/resolution.z"
abort() ;
}
;
}
;
}
;
#line 273 "src/resolution.z"
i = (i+ 1);
;
}
;
#line 276 "src/resolution.z"
i = 0;
;
#line 277 "src/resolution.z"
while ( (i< module->num_items))
{
#line 278 "src/resolution.z"
Item*  item = module->items[i];
;
#line 279 "src/resolution.z"
if ((item->kind== ItemKind_Module)){
#line 279 "src/resolution.z"
index_module_wildcards(ctx,item->node.module) ;
}
;
#line 280 "src/resolution.z"
i = (i+ 1);
;
}
;
}

#line 284 "src/resolution.z"
bool check_if_sid_is_primitive(ResolutionContext*  ctx, Sid s, PrimitiveTy*  prim) {
#line 286 "src/resolution.z"
PrimitiveTypeSids*  p = &ctx->primitive_ty_sids;
;
#line 287 "src/resolution.z"
if ((s.x== p->_void.x)){
#line 287 "src/resolution.z"
prim->kind = PrimitiveTyKind_Void;
;
}
else {
#line 288 "src/resolution.z"
if ((s.x== p->_bool.x)){
#line 288 "src/resolution.z"
prim->kind = PrimitiveTyKind_Bool;
;
}
else {
#line 289 "src/resolution.z"
if ((s.x== p->_char.x)){
#line 289 "src/resolution.z"
prim->kind = PrimitiveTyKind_Char;
;
}
else {
#line 291 "src/resolution.z"
if ((s.x== p->_i8.x)){
#line 291 "src/resolution.z"
prim->kind = PrimitiveTyKind_Signed;
;
#line 291 "src/resolution.z"
prim->node.integer = IntegerSize_I8;
;
}
else {
#line 292 "src/resolution.z"
if ((s.x== p->_i16.x)){
#line 292 "src/resolution.z"
prim->kind = PrimitiveTyKind_Signed;
;
#line 292 "src/resolution.z"
prim->node.integer = IntegerSize_I16;
;
}
else {
#line 293 "src/resolution.z"
if ((s.x== p->_i32.x)){
#line 293 "src/resolution.z"
prim->kind = PrimitiveTyKind_Signed;
;
#line 293 "src/resolution.z"
prim->node.integer = IntegerSize_I32;
;
}
else {
#line 294 "src/resolution.z"
if ((s.x== p->_i64.x)){
#line 294 "src/resolution.z"
prim->kind = PrimitiveTyKind_Signed;
;
#line 294 "src/resolution.z"
prim->node.integer = IntegerSize_I64;
;
}
else {
#line 296 "src/resolution.z"
if ((s.x== p->_u8.x)){
#line 296 "src/resolution.z"
prim->kind = PrimitiveTyKind_Unsigned;
;
#line 296 "src/resolution.z"
prim->node.integer = IntegerSize_I8;
;
}
else {
#line 297 "src/resolution.z"
if ((s.x== p->_u16.x)){
#line 297 "src/resolution.z"
prim->kind = PrimitiveTyKind_Unsigned;
;
#line 297 "src/resolution.z"
prim->node.integer = IntegerSize_I16;
;
}
else {
#line 298 "src/resolution.z"
if ((s.x== p->_u32.x)){
#line 298 "src/resolution.z"
prim->kind = PrimitiveTyKind_Unsigned;
;
#line 298 "src/resolution.z"
prim->node.integer = IntegerSize_I32;
;
}
else {
#line 299 "src/resolution.z"
if ((s.x== p->_u64.x)){
#line 299 "src/resolution.z"
prim->kind = PrimitiveTyKind_Unsigned;
;
#line 299 "src/resolution.z"
prim->node.integer = IntegerSize_I64;
;
}
else {
#line 301 "src/resolution.z"
if ((s.x== p->_f32.x)){
#line 301 "src/resolution.z"
prim->kind = PrimitiveTyKind_Floating;
;
#line 301 "src/resolution.z"
prim->node.floating = FloatingSize_F32;
;
}
else {
#line 302 "src/resolution.z"
if ((s.x== p->_f64.x)){
#line 302 "src/resolution.z"
prim->kind = PrimitiveTyKind_Floating;
;
#line 302 "src/resolution.z"
prim->node.floating = FloatingSize_F64;
;
}
else {
#line 304 "src/resolution.z"
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
#line 306 "src/resolution.z"
return true;
;
}

#line 309 "src/resolution.z"
void  resolve_path(ResolutionContext*  ctx, Path*  path) {
#line 310 "src/resolution.z"
PrimitiveTy prim ;
;
#line 312 "src/resolution.z"
if (check_if_sid_is_primitive(ctx,path->segments[0].name,&prim) ){
#line 313 "src/resolution.z"
path->binding.kind = BindingKind_PrimitiveType;
;
#line 314 "src/resolution.z"
path->binding.node.primitive = prim;
;
}
else {
#line 316 "src/resolution.z"
if ((path->num_segments> 1)){
#line 316 "src/resolution.z"
abort() ;
}
else {
#line 317 "src/resolution.z"
if ((path->num_segments== 1)){
#line 318 "src/resolution.z"
*path = lookup(ctx,path->segments[0]) ;
;
}
;
}
;
}
;
}

#line 322 "src/resolution.z"
void  resolve_expr(ResolutionContext*  ctx, Expr*  expr) ;

#line 323 "src/resolution.z"
void  resolve_item(ResolutionContext*  ctx, Item*  item) ;

#line 325 "src/resolution.z"
void  resolve_unary(ResolutionContext*  ctx, UnaryData unary) {
#line 326 "src/resolution.z"
resolve_expr(ctx,unary.inner) ;
}

#line 329 "src/resolution.z"
void  resolve_binary(ResolutionContext*  ctx, BinaryData binary) {
#line 330 "src/resolution.z"
resolve_expr(ctx,binary.left) ;
#line 331 "src/resolution.z"
resolve_expr(ctx,binary.right) ;
}

#line 334 "src/resolution.z"
void  resolve_call(ResolutionContext*  ctx, CallData call) {
#line 335 "src/resolution.z"
resolve_expr(ctx,call.func) ;
#line 337 "src/resolution.z"
u32 i = 0;
;
#line 338 "src/resolution.z"
while ( (i< call.num_args))
{
#line 339 "src/resolution.z"
resolve_expr(ctx,call.args[i]) ;
#line 340 "src/resolution.z"
i = (i+ 1);
;
}
;
}

#line 344 "src/resolution.z"
void  resolve_conditional(ResolutionContext*  ctx, ConditionalData cond) {
#line 345 "src/resolution.z"
resolve_expr(ctx,cond.condition) ;
#line 346 "src/resolution.z"
resolve_expr(ctx,cond.then) ;
#line 347 "src/resolution.z"
if (cond.otherwise){
#line 348 "src/resolution.z"
resolve_expr(ctx,cond.otherwise) ;
}
;
}

#line 352 "src/resolution.z"
void  resolve_while(ResolutionContext*  ctx, WhileData data) {
#line 353 "src/resolution.z"
resolve_expr(ctx,data.condition) ;
#line 354 "src/resolution.z"
resolve_expr(ctx,data.body) ;
}

#line 357 "src/resolution.z"
void  resolve_indexing(ResolutionContext*  ctx, IndexingData idx) {
#line 358 "src/resolution.z"
resolve_expr(ctx,idx.array) ;
#line 359 "src/resolution.z"
resolve_expr(ctx,idx.index) ;
}

#line 362 "src/resolution.z"
void  resolve_field(ResolutionContext*  ctx, FieldData field) {
#line 363 "src/resolution.z"
resolve_expr(ctx,field.strct) ;
}

#line 366 "src/resolution.z"
void  resolve_assignment(ResolutionContext*  ctx, AssignmentData assignment) {
#line 367 "src/resolution.z"
resolve_expr(ctx,assignment.left) ;
#line 368 "src/resolution.z"
resolve_expr(ctx,assignment.right) ;
}

#line 371 "src/resolution.z"
void  resolve_block(ResolutionContext*  ctx, Block*  block) {
#line 373 "src/resolution.z"
push_block(ctx) ;
#line 374 "src/resolution.z"
u32 i = 0;
;
#line 375 "src/resolution.z"
while ( (i< block->num_exprs))
{
#line 376 "src/resolution.z"
resolve_expr(ctx,block->exprs[i]) ;
#line 377 "src/resolution.z"
i = (i+ 1);
;
}
;
#line 379 "src/resolution.z"
pop_block(ctx) ;
}

#line 382 "src/resolution.z"
void  resolve_let(ResolutionContext*  ctx, LetData data) {
#line 383 "src/resolution.z"
push_variable(ctx,data.pat.ident) ;
#line 384 "src/resolution.z"
resolve_expr(ctx,data.value) ;
}

#line 387 "src/resolution.z"
void  resolve_expr(ResolutionContext*  ctx, Expr*  expr) {
#line 388 "src/resolution.z"
if ((expr->kind== ExprKind_Unary)){
#line 388 "src/resolution.z"
resolve_unary(ctx,expr->node.unary) ;
}
else {
#line 389 "src/resolution.z"
if ((expr->kind== ExprKind_Binary)){
#line 389 "src/resolution.z"
resolve_binary(ctx,expr->node.binary) ;
}
else {
#line 390 "src/resolution.z"
if ((expr->kind== ExprKind_Block)){
#line 390 "src/resolution.z"
resolve_block(ctx,expr->node.block) ;
}
else {
#line 391 "src/resolution.z"
if ((expr->kind== ExprKind_Call)){
#line 391 "src/resolution.z"
resolve_call(ctx,expr->node.call) ;
}
else {
#line 392 "src/resolution.z"
if ((expr->kind== ExprKind_Conditional)){
#line 392 "src/resolution.z"
resolve_conditional(ctx,expr->node.conditional) ;
}
else {
#line 393 "src/resolution.z"
if ((expr->kind== ExprKind_While)){
#line 393 "src/resolution.z"
resolve_while(ctx,expr->node.whl) ;
}
else {
#line 394 "src/resolution.z"
if ((expr->kind== ExprKind_Indexing)){
#line 394 "src/resolution.z"
resolve_indexing(ctx,expr->node.indexing) ;
}
else {
#line 395 "src/resolution.z"
if ((expr->kind== ExprKind_Field)){
#line 395 "src/resolution.z"
resolve_field(ctx,expr->node.field) ;
}
else {
#line 396 "src/resolution.z"
if ((expr->kind== ExprKind_Path)){
#line 396 "src/resolution.z"
resolve_path(ctx,&expr->node.path) ;
}
else {
#line 397 "src/resolution.z"
if ((expr->kind== ExprKind_Assignment)){
#line 397 "src/resolution.z"
resolve_assignment(ctx,expr->node.assignment) ;
}
else {
#line 398 "src/resolution.z"
if ((expr->kind== ExprKind_Let)){
#line 398 "src/resolution.z"
resolve_let(ctx,expr->node._let) ;
}
else {
#line 399 "src/resolution.z"
if ((expr->kind== ExprKind_Return)){
#line 399 "src/resolution.z"
resolve_expr(ctx,expr->node._return) ;
}
else {
#line 400 "src/resolution.z"
if ((expr->kind== ExprKind_Literal)){
}
else {
#line 401 "src/resolution.z"
if ((expr->kind== ExprKind_ControlFlow)){
}
else {
#line 402 "src/resolution.z"
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

#line 405 "src/resolution.z"
void  resolve_function(ResolutionContext*  ctx, Item*  item) {
#line 406 "src/resolution.z"
FunctionData func = item->node.function;
;
#line 407 "src/resolution.z"
if (func.body){
#line 408 "src/resolution.z"
push_block(ctx) ;
#line 409 "src/resolution.z"
u32 i = 0;
;
#line 410 "src/resolution.z"
while ( (i< func.header.num_parameters))
{
#line 411 "src/resolution.z"
FunctionParameter*  param = &func.header.parameters[i];
;
#line 412 "src/resolution.z"
push_variable(ctx,param->pat.ident) ;
#line 414 "src/resolution.z"
i = (i+ 1);
;
}
;
#line 417 "src/resolution.z"
resolve_expr(ctx,item->node.function.body) ;
#line 418 "src/resolution.z"
pop_block(ctx) ;
}
;
}

#line 422 "src/resolution.z"
void  resolve_variable(ResolutionContext*  ctx, Item*  item) {
#line 423 "src/resolution.z"
push_block(ctx) ;
#line 424 "src/resolution.z"
if (item->node.variable.body){
#line 425 "src/resolution.z"
resolve_expr(ctx,item->node.variable.body) ;
}
;
#line 427 "src/resolution.z"
pop_block(ctx) ;
}

#line 430 "src/resolution.z"
void  resolve_module(ResolutionContext*  ctx, Module*  module) ;

#line 432 "src/resolution.z"
void  resolve_item(ResolutionContext*  ctx, Item*  item) {
#line 433 "src/resolution.z"
if (((item->kind== ItemKind_Const)|| (item->kind== ItemKind_Variable))){
#line 433 "src/resolution.z"
resolve_variable(ctx,item) ;
}
;
#line 434 "src/resolution.z"
if ((item->kind== ItemKind_Function)){
#line 434 "src/resolution.z"
resolve_function(ctx,item) ;
}
;
#line 435 "src/resolution.z"
if ((item->kind== ItemKind_Module)){
#line 435 "src/resolution.z"
resolve_module(ctx,item->node.module) ;
}
;
}

#line 438 "src/resolution.z"
void  resolve_module(ResolutionContext*  ctx, Module*  module) {
#line 439 "src/resolution.z"
push_module(ctx,module) ;
#line 441 "src/resolution.z"
u32 i = 0;
;
#line 442 "src/resolution.z"
while ( (i< module->num_items))
{
#line 443 "src/resolution.z"
resolve_item(ctx,module->items[i]) ;
#line 444 "src/resolution.z"
i = (i+ 1);
;
}
;
#line 446 "src/resolution.z"
pop_module(ctx) ;
}

#line 449 "src/resolution.z"
void  resolve(Session*  sess, Ast*  ast) {
#line 450 "src/resolution.z"
ResolutionContext ctx ;
;
#line 452 "src/resolution.z"
ctx.interner = &sess->interner;
;
#line 453 "src/resolution.z"
setup_primitive_ty_sids(ctx.interner,&ctx.primitive_ty_sids) ;
#line 454 "src/resolution.z"
ctx.ast = ast;
;
#line 455 "src/resolution.z"
ctx.scope_stack = malloc((sizeof(Scope)* 128)) ;
;
#line 456 "src/resolution.z"
ctx.stack_top = 0;
;
#line 457 "src/resolution.z"
ctx.source_map = &sess->source;
;
#line 458 "src/resolution.z"
ctx.root_module = ast->root_module;
;
#line 460 "src/resolution.z"
index_use(&ctx,ast->root_module) ;
#line 461 "src/resolution.z"
index_module(&ctx,ast->root_module) ;
#line 462 "src/resolution.z"
index_module_wildcards(&ctx,ast->root_module) ;
#line 463 "src/resolution.z"
resolve_module(&ctx,ast->root_module) ;
}


typedef struct CodegenContext CodegenContext;
#line 2 "src/codegen.z"
typedef struct CodegenContext {
FILE*  out;
StrMap*  ident_is_ptr;
Session*  sess;
Ast*  ast;
SourceMap*  source;
} CodegenContext;


#line 10 "src/codegen.z"
void  generate_expr(CodegenContext*  ctx, Expr*  expr) ;

#line 11 "src/codegen.z"
void  generate_block(CodegenContext*  ctx, Block*  block) ;

#line 12 "src/codegen.z"
void  generate_item(CodegenContext*  ctx, Item*  item) ;

#line 14 "src/codegen.z"
bool type_is_ptr(AstType*  ty) {
#line 15 "src/codegen.z"
return (ty->kind== AstTypeKind_Ptr);
;
}

#line 18 "src/codegen.z"
void  generate_prelude(CodegenContext*  ctx) {
#line 19 "src/codegen.z"
fprintf(ctx->out,"//Prelude\n") ;
#line 20 "src/codegen.z"
fprintf(ctx->out,"#include <stdint.h>\n") ;
#line 21 "src/codegen.z"
fprintf(ctx->out,"#include <stdbool.h>\n") ;
#line 22 "src/codegen.z"
fprintf(ctx->out,"typedef uint8_t u8;\n") ;
#line 23 "src/codegen.z"
fprintf(ctx->out,"typedef uint16_t u16;\n") ;
#line 24 "src/codegen.z"
fprintf(ctx->out,"typedef uint32_t u32;\n") ;
#line 25 "src/codegen.z"
fprintf(ctx->out,"typedef uint64_t u64;\n") ;
#line 26 "src/codegen.z"
fprintf(ctx->out,"typedef int8_t i8;\n") ;
#line 27 "src/codegen.z"
fprintf(ctx->out,"typedef int16_t i16;\n") ;
#line 28 "src/codegen.z"
fprintf(ctx->out,"typedef int32_t i32;\n") ;
#line 29 "src/codegen.z"
fprintf(ctx->out,"typedef int64_t i64;\n") ;
#line 30 "src/codegen.z"
fprintf(ctx->out,"typedef float f32;\n") ;
#line 31 "src/codegen.z"
fprintf(ctx->out,"typedef double f64;\n") ;
#line 32 "src/codegen.z"
fprintf(ctx->out,"typedef const char constchar;\n") ;
#line 33 "src/codegen.z"
fprintf(ctx->out,"typedef const void constvoid;\n") ;
}

#line 36 "src/codegen.z"
void  generate_sid(CodegenContext*  ctx, Sid sid) {
#line 37 "src/codegen.z"
Session*  sess = ctx->sess;
;
#line 38 "src/codegen.z"
fprintf(ctx->out,"%s",get_str(&sess->interner,sid) ) ;
}

#line 41 "src/codegen.z"
void  generate_identifier(CodegenContext*  ctx, Ident ident) {
#line 42 "src/codegen.z"
generate_sid(ctx,ident.name) ;
}

#line 45 "src/codegen.z"
void  generate_pattern(CodegenContext*  ctx, Pattern pat) {
#line 46 "src/codegen.z"
generate_identifier(ctx,pat.ident) ;
}

#line 49 "src/codegen.z"
void  generate_type(CodegenContext*  ctx, AstType*  ty) {
#line 50 "src/codegen.z"
if ((ty->kind== AstTypeKind_Path)){
#line 50 "src/codegen.z"
generate_sid(ctx,ty->node.path) ;
}
else {
#line 51 "src/codegen.z"
if ((ty->kind== AstTypeKind_Ptr)){
#line 52 "src/codegen.z"
generate_type(ctx,ty->node.ptr) ;
#line 53 "src/codegen.z"
fprintf(ctx->out,"* ") ;
}
else {
#line 55 "src/codegen.z"
if ((ty->kind== AstTypeKind_Void)){
#line 56 "src/codegen.z"
fprintf(ctx->out,"void ") ;
}
else {
#line 58 "src/codegen.z"
abort() ;
}
;
}
;
}
;
}

#line 61 "src/codegen.z"
void  generate_char(CodegenContext*  ctx, char c) {
#line 62 "src/codegen.z"
if ((c== '\n')){
#line 62 "src/codegen.z"
fprintf(ctx->out,"'\\n'") ;
}
else {
#line 63 "src/codegen.z"
if ((c== '\t')){
#line 63 "src/codegen.z"
fprintf(ctx->out,"'\\t'") ;
}
else {
#line 64 "src/codegen.z"
if ((c== '\r')){
#line 64 "src/codegen.z"
fprintf(ctx->out,"'\\r'") ;
}
else {
#line 65 "src/codegen.z"
if ((c== '\\')){
#line 65 "src/codegen.z"
fprintf(ctx->out,"'\\\\'") ;
}
else {
#line 66 "src/codegen.z"
if ((c== '\'')){
#line 66 "src/codegen.z"
fprintf(ctx->out,"'\\''") ;
}
else {
#line 67 "src/codegen.z"
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

#line 70 "src/codegen.z"
void  generate_literal(CodegenContext*  ctx, Literal lit) {
#line 71 "src/codegen.z"
if ((lit.kind== LiteralKind_Int)){
#line 71 "src/codegen.z"
fprintf(ctx->out,"%ld",lit.value.integer) ;
}
else {
#line 72 "src/codegen.z"
if ((lit.kind== LiteralKind_Float)){
#line 72 "src/codegen.z"
fprintf(ctx->out,"%f",lit.value.floating) ;
}
else {
#line 73 "src/codegen.z"
if ((lit.kind== LiteralKind_Bool)){
#line 73 "src/codegen.z"
if (lit.value.boolean){
#line 73 "src/codegen.z"
fprintf(ctx->out,"true") ;
}
else {
#line 73 "src/codegen.z"
fprintf(ctx->out,"false") ;
}
;
}
else {
#line 74 "src/codegen.z"
if ((lit.kind== LiteralKind_Str)){
#line 75 "src/codegen.z"
Session*  sess = ctx->sess;
;
#line 76 "src/codegen.z"
fprintf(ctx->out,"\"%s\"",get_str(&sess->interner,lit.value.str) ) ;
}
else {
#line 78 "src/codegen.z"
if ((lit.kind== LiteralKind_Char)){
#line 78 "src/codegen.z"
generate_char(ctx,lit.value.ch) ;
}
else {
#line 79 "src/codegen.z"
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

#line 82 "src/codegen.z"
void  generate_unary(CodegenContext*  ctx, UnaryData unary) {
#line 83 "src/codegen.z"
if ((unary.op== UnaryOperatorKind_Negation)){
#line 83 "src/codegen.z"
fprintf(ctx->out,"-") ;
}
else {
#line 84 "src/codegen.z"
if ((unary.op== UnaryOperatorKind_Complement)){
#line 84 "src/codegen.z"
fprintf(ctx->out,"!") ;
}
else {
#line 85 "src/codegen.z"
if ((unary.op== UnaryOperatorKind_Refer)){
#line 85 "src/codegen.z"
fprintf(ctx->out,"&") ;
}
else {
#line 86 "src/codegen.z"
if ((unary.op== UnaryOperatorKind_Deref)){
#line 86 "src/codegen.z"
fprintf(ctx->out,"*") ;
}
else {
#line 87 "src/codegen.z"
abort() ;
}
;
}
;
}
;
}
;
#line 89 "src/codegen.z"
generate_expr(ctx,unary.inner) ;
}

#line 92 "src/codegen.z"
void  generate_binary(CodegenContext*  ctx, BinaryData binary) {
#line 93 "src/codegen.z"
fprintf(ctx->out,"(") ;
#line 94 "src/codegen.z"
generate_expr(ctx,binary.left) ;
#line 95 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Addition)){
#line 95 "src/codegen.z"
fprintf(ctx->out,"+ ") ;
}
else {
#line 96 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Subtraction)){
#line 96 "src/codegen.z"
fprintf(ctx->out,"- ") ;
}
else {
#line 97 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Product)){
#line 97 "src/codegen.z"
fprintf(ctx->out,"* ") ;
}
else {
#line 98 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Division)){
#line 98 "src/codegen.z"
fprintf(ctx->out,"/ ") ;
}
else {
#line 99 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Modulus)){
#line 99 "src/codegen.z"
fprintf(ctx->out,"%% ") ;
}
else {
#line 101 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Less)){
#line 101 "src/codegen.z"
fprintf(ctx->out,"< ") ;
}
else {
#line 102 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_LessEq)){
#line 102 "src/codegen.z"
fprintf(ctx->out,"<= ") ;
}
else {
#line 103 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Greater)){
#line 103 "src/codegen.z"
fprintf(ctx->out,"> ") ;
}
else {
#line 104 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_GreaterEq)){
#line 104 "src/codegen.z"
fprintf(ctx->out,">= ") ;
}
else {
#line 105 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Equality)){
#line 105 "src/codegen.z"
fprintf(ctx->out,"== ") ;
}
else {
#line 106 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_NotEq)){
#line 106 "src/codegen.z"
fprintf(ctx->out,"!= ") ;
}
else {
#line 108 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_BAnd)){
#line 108 "src/codegen.z"
fprintf(ctx->out,"& ") ;
}
else {
#line 109 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_BOr)){
#line 109 "src/codegen.z"
fprintf(ctx->out,"| ") ;
}
else {
#line 110 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Xor)){
#line 110 "src/codegen.z"
fprintf(ctx->out,"^ ") ;
}
else {
#line 111 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_LeftShift)){
#line 111 "src/codegen.z"
fprintf(ctx->out,"<< ") ;
}
else {
#line 112 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_RightShift)){
#line 112 "src/codegen.z"
fprintf(ctx->out,">> ") ;
}
else {
#line 114 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_And)){
#line 114 "src/codegen.z"
fprintf(ctx->out,"&& ") ;
}
else {
#line 115 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Or)){
#line 115 "src/codegen.z"
fprintf(ctx->out,"|| ") ;
}
else {
#line 116 "src/codegen.z"
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
#line 117 "src/codegen.z"
generate_expr(ctx,binary.right) ;
#line 118 "src/codegen.z"
fprintf(ctx->out,")") ;
}

#line 121 "src/codegen.z"
void  generate_call(CodegenContext*  ctx, CallData call) {
#line 122 "src/codegen.z"
generate_expr(ctx,call.func) ;
#line 124 "src/codegen.z"
fprintf(ctx->out,"(") ;
#line 125 "src/codegen.z"
u32 i = 0;
;
#line 126 "src/codegen.z"
while ( (i< call.num_args))
{
#line 127 "src/codegen.z"
Expr*  arg = call.args[i];
;
#line 128 "src/codegen.z"
generate_expr(ctx,arg) ;
#line 129 "src/codegen.z"
if ((i< (call.num_args- 1))){
#line 129 "src/codegen.z"
fprintf(ctx->out,",") ;
}
;
#line 130 "src/codegen.z"
i = (i+ 1);
;
}
;
#line 132 "src/codegen.z"
fprintf(ctx->out,") ") ;
}

#line 135 "src/codegen.z"
void  generate_conditional(CodegenContext*  ctx, ConditionalData cond) {
#line 136 "src/codegen.z"
fprintf(ctx->out,"if (") ;
#line 137 "src/codegen.z"
generate_expr(ctx,cond.condition) ;
#line 138 "src/codegen.z"
fprintf(ctx->out,")") ;
#line 139 "src/codegen.z"
generate_expr(ctx,cond.then) ;
#line 140 "src/codegen.z"
if (cond.otherwise){
#line 141 "src/codegen.z"
fprintf(ctx->out,"else ") ;
#line 142 "src/codegen.z"
generate_expr(ctx,cond.otherwise) ;
}
;
}

#line 146 "src/codegen.z"
void  generate_while(CodegenContext*  ctx, WhileData data) {
#line 147 "src/codegen.z"
fprintf(ctx->out,"while ( ") ;
#line 148 "src/codegen.z"
generate_expr(ctx,data.condition) ;
#line 149 "src/codegen.z"
fprintf(ctx->out,")\n") ;
#line 150 "src/codegen.z"
generate_expr(ctx,data.body) ;
}

#line 153 "src/codegen.z"
void  generate_indexing(CodegenContext*  ctx, IndexingData idx) {
#line 154 "src/codegen.z"
generate_expr(ctx,idx.array) ;
#line 155 "src/codegen.z"
fprintf(ctx->out,"[") ;
#line 156 "src/codegen.z"
generate_expr(ctx,idx.index) ;
#line 157 "src/codegen.z"
fprintf(ctx->out,"]") ;
}

#line 160 "src/codegen.z"
void  generate_field(CodegenContext*  ctx, FieldData field) {
#line 161 "src/codegen.z"
Expr*  strct = field.strct;
;
#line 162 "src/codegen.z"
generate_expr(ctx,strct) ;
#line 164 "src/codegen.z"
Session*  sess = ctx->sess;
;
#line 165 "src/codegen.z"
char*  field_name = get_str(&sess->interner,field.ident.name) ;
;
#line 167 "src/codegen.z"
bool is_ptr = false;
;
#line 168 "src/codegen.z"
char*  accessor_str ;
;
#line 169 "src/codegen.z"
if ((strct->kind== ExprKind_Path)){
#line 170 "src/codegen.z"
char*  strct_name = get_str(&sess->interner,strct->node.path.segments[0].name) ;
;
#line 171 "src/codegen.z"
is_ptr = strmap_lookup(ctx->ident_is_ptr,strct_name) ;
;
}
;
#line 174 "src/codegen.z"
if (is_ptr){
#line 174 "src/codegen.z"
accessor_str = "->";
;
}
else {
#line 175 "src/codegen.z"
accessor_str = ".";
;
}
;
#line 176 "src/codegen.z"
fprintf(ctx->out,"%s%s",accessor_str,field_name) ;
}

#line 179 "src/codegen.z"
void  generate_path(CodegenContext*  ctx, Path path) {
#line 180 "src/codegen.z"
u32 i = 0;
;
#line 181 "src/codegen.z"
while ( (i< path.num_segments))
{
#line 182 "src/codegen.z"
generate_identifier(ctx,path.segments[i]) ;
#line 183 "src/codegen.z"
if ((i< (path.num_segments- 1))){
#line 183 "src/codegen.z"
fprintf(ctx->out,"_") ;
}
;
#line 184 "src/codegen.z"
i = (i+ 1);
;
}
;
}

#line 188 "src/codegen.z"
void  generate_sizeof(CodegenContext*  ctx, Expr*  expr) {
#line 189 "src/codegen.z"
fprintf(ctx->out,"sizeof(") ;
#line 190 "src/codegen.z"
generate_expr(ctx,expr) ;
#line 191 "src/codegen.z"
fprintf(ctx->out,")") ;
}

#line 194 "src/codegen.z"
void  generate_assignment(CodegenContext*  ctx, AssignmentData assignment) {
#line 195 "src/codegen.z"
generate_expr(ctx,assignment.left) ;
#line 196 "src/codegen.z"
fprintf(ctx->out," = ") ;
#line 197 "src/codegen.z"
generate_expr(ctx,assignment.right) ;
#line 198 "src/codegen.z"
fprintf(ctx->out,";\n") ;
}

#line 201 "src/codegen.z"
void  generate_return(CodegenContext*  ctx, Expr*  expr) {
#line 202 "src/codegen.z"
fprintf(ctx->out,"return ") ;
#line 203 "src/codegen.z"
generate_expr(ctx,expr) ;
#line 204 "src/codegen.z"
fprintf(ctx->out,";\n") ;
}

#line 207 "src/codegen.z"
void  generate_control_flow(CodegenContext*  ctx, bool is_continue) {
#line 208 "src/codegen.z"
if (is_continue){
#line 208 "src/codegen.z"
fprintf(ctx->out,"continue;\n") ;
}
else {
#line 209 "src/codegen.z"
fprintf(ctx->out,"break;\n") ;
}
;
}

#line 212 "src/codegen.z"
void  generate_let(CodegenContext*  ctx, LetData data) {
#line 214 "src/codegen.z"
generate_type(ctx,data.ty) ;
#line 216 "src/codegen.z"
Session*  sess = ctx->sess;
;
#line 217 "src/codegen.z"
char*  var_name = get_str(&sess->interner,data.pat.ident.name) ;
;
#line 219 "src/codegen.z"
strmap_insert(ctx->ident_is_ptr,var_name,type_is_ptr(data.ty) ) ;
#line 220 "src/codegen.z"
fprintf(ctx->out," %s ",var_name) ;
#line 221 "src/codegen.z"
if (data.value){
#line 222 "src/codegen.z"
fprintf(ctx->out,"= ") ;
#line 223 "src/codegen.z"
generate_expr(ctx,data.value) ;
}
;
#line 225 "src/codegen.z"
fprintf(ctx->out,";\n") ;
}

#line 228 "src/codegen.z"
void  generate_expr(CodegenContext*  ctx, Expr*  expr) {
#line 229 "src/codegen.z"
if ((expr->kind== ExprKind_Unary)){
#line 229 "src/codegen.z"
generate_unary(ctx,expr->node.unary) ;
}
else {
#line 230 "src/codegen.z"
if ((expr->kind== ExprKind_Binary)){
#line 230 "src/codegen.z"
generate_binary(ctx,expr->node.binary) ;
}
else {
#line 231 "src/codegen.z"
if ((expr->kind== ExprKind_Block)){
#line 231 "src/codegen.z"
generate_block(ctx,expr->node.block) ;
}
else {
#line 232 "src/codegen.z"
if ((expr->kind== ExprKind_Call)){
#line 232 "src/codegen.z"
generate_call(ctx,expr->node.call) ;
}
else {
#line 233 "src/codegen.z"
if ((expr->kind== ExprKind_Conditional)){
#line 233 "src/codegen.z"
generate_conditional(ctx,expr->node.conditional) ;
}
else {
#line 234 "src/codegen.z"
if ((expr->kind== ExprKind_While)){
#line 234 "src/codegen.z"
generate_while(ctx,expr->node.whl) ;
}
else {
#line 235 "src/codegen.z"
if ((expr->kind== ExprKind_Indexing)){
#line 235 "src/codegen.z"
generate_indexing(ctx,expr->node.indexing) ;
}
else {
#line 236 "src/codegen.z"
if ((expr->kind== ExprKind_Field)){
#line 236 "src/codegen.z"
generate_field(ctx,expr->node.field) ;
}
else {
#line 237 "src/codegen.z"
if ((expr->kind== ExprKind_Literal)){
#line 237 "src/codegen.z"
generate_literal(ctx,expr->node.lit) ;
}
else {
#line 238 "src/codegen.z"
if ((expr->kind== ExprKind_Path)){
#line 238 "src/codegen.z"
generate_path(ctx,expr->node.path) ;
}
else {
#line 239 "src/codegen.z"
if ((expr->kind== ExprKind_Sizeof)){
#line 239 "src/codegen.z"
generate_sizeof(ctx,expr->node._sizeof) ;
}
else {
#line 240 "src/codegen.z"
if ((expr->kind== ExprKind_Assignment)){
#line 240 "src/codegen.z"
generate_assignment(ctx,expr->node.assignment) ;
}
else {
#line 241 "src/codegen.z"
if ((expr->kind== ExprKind_ControlFlow)){
#line 241 "src/codegen.z"
generate_control_flow(ctx,expr->node.control_flow_is_continue) ;
}
else {
#line 242 "src/codegen.z"
if ((expr->kind== ExprKind_Let)){
#line 242 "src/codegen.z"
generate_let(ctx,expr->node._let) ;
}
else {
#line 243 "src/codegen.z"
if ((expr->kind== ExprKind_Return)){
#line 243 "src/codegen.z"
generate_return(ctx,expr->node._return) ;
}
else {
#line 244 "src/codegen.z"
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

#line 247 "src/codegen.z"
void  generate_block(CodegenContext*  ctx, Block*  block) {
#line 248 "src/codegen.z"
fprintf(ctx->out,"{\n") ;
#line 249 "src/codegen.z"
u32 i = 0;
;
#line 251 "src/codegen.z"
while ( (i< block->num_exprs))
{
#line 252 "src/codegen.z"
Expr*  expr = block->exprs[i];
;
#line 253 "src/codegen.z"
emit_line_directive(ctx->out,ctx->source,expr->span) ;
#line 254 "src/codegen.z"
generate_expr(ctx,expr) ;
#line 255 "src/codegen.z"
fprintf(ctx->out,";\n") ;
#line 256 "src/codegen.z"
i = (i+ 1);
;
}
;
#line 258 "src/codegen.z"
fprintf(ctx->out,"}\n") ;
}

#line 261 "src/codegen.z"
void  generate_variable(CodegenContext*  ctx, Item*  item) {
#line 263 "src/codegen.z"
emit_line_directive(ctx->out,ctx->source,item->span) ;
#line 265 "src/codegen.z"
generate_type(ctx,item->node.variable.ty) ;
#line 267 "src/codegen.z"
Session*  sess = ctx->sess;
;
#line 268 "src/codegen.z"
char*  var_name = get_str(&sess->interner,item->ident.name) ;
;
#line 270 "src/codegen.z"
strmap_insert(ctx->ident_is_ptr,var_name,type_is_ptr(item->node.variable.ty) ) ;
#line 271 "src/codegen.z"
fprintf(ctx->out," %s ",var_name) ;
#line 272 "src/codegen.z"
if (item->node.variable.body){
#line 273 "src/codegen.z"
fprintf(ctx->out,"= ") ;
#line 274 "src/codegen.z"
generate_expr(ctx,item->node.variable.body) ;
}
;
#line 276 "src/codegen.z"
fprintf(ctx->out,";\n") ;
}

#line 279 "src/codegen.z"
void  generate_function(CodegenContext*  ctx, Item*  item) {
#line 281 "src/codegen.z"
emit_line_directive(ctx->out,ctx->source,item->span) ;
#line 283 "src/codegen.z"
FunctionData func = item->node.function;
;
#line 284 "src/codegen.z"
FunctionHeader header = func.header;
;
#line 285 "src/codegen.z"
generate_type(ctx,header.output) ;
#line 287 "src/codegen.z"
Session*  sess = ctx->sess;
;
#line 288 "src/codegen.z"
char*  func_name = get_str(&sess->interner,item->ident.name) ;
;
#line 290 "src/codegen.z"
fprintf(ctx->out," %s(",func_name) ;
#line 292 "src/codegen.z"
u32 i = 0;
;
#line 293 "src/codegen.z"
while ( (i< header.num_parameters))
{
#line 294 "src/codegen.z"
AstType*  ty = header.parameters[i].ty;
;
#line 295 "src/codegen.z"
if ((ty->kind== AstTypeKind_Variadic)){
#line 296 "src/codegen.z"
fprintf(ctx->out,"...") ;
#line 297 "src/codegen.z"
break;
;
}
;
#line 300 "src/codegen.z"
generate_type(ctx,ty) ;
#line 302 "src/codegen.z"
char*  param_name = get_str(&sess->interner,header.parameters[i].pat.ident.name) ;
;
#line 303 "src/codegen.z"
strmap_insert(ctx->ident_is_ptr,param_name,type_is_ptr(header.parameters[i].ty) ) ;
#line 304 "src/codegen.z"
fprintf(ctx->out," %s",param_name) ;
#line 305 "src/codegen.z"
if ((i< (header.num_parameters- 1))){
#line 305 "src/codegen.z"
fprintf(ctx->out,", ") ;
}
;
#line 306 "src/codegen.z"
i = (i+ 1);
;
}
;
#line 308 "src/codegen.z"
fprintf(ctx->out,") ") ;
#line 309 "src/codegen.z"
if (func.body){
#line 309 "src/codegen.z"
generate_expr(ctx,func.body) ;
}
else {
#line 310 "src/codegen.z"
fprintf(ctx->out,";\n") ;
}
;
}

#line 313 "src/codegen.z"
void  generate_enum(CodegenContext*  ctx, Item*  item) {
#line 315 "src/codegen.z"
Session*  sess = ctx->sess;
;
#line 316 "src/codegen.z"
char*  enum_name = get_str(&sess->interner,item->ident.name) ;
;
#line 318 "src/codegen.z"
emit_line_directive(ctx->out,ctx->source,item->span) ;
#line 319 "src/codegen.z"
fprintf(ctx->out,"typedef enum %s {\n",enum_name) ;
#line 320 "src/codegen.z"
u32 i = 0;
;
#line 322 "src/codegen.z"
EnumData data = item->node._enum;
;
#line 324 "src/codegen.z"
while ( (i< data.num_variants))
{
#line 325 "src/codegen.z"
char*  variant_name = get_str(&sess->interner,data.variants[i].ident.name) ;
;
#line 326 "src/codegen.z"
fprintf(ctx->out,"%s_%s,\n",enum_name,variant_name) ;
#line 327 "src/codegen.z"
i = (i+ 1);
;
}
;
#line 329 "src/codegen.z"
fprintf(ctx->out,"} %s;\n\n",enum_name) ;
}

#line 332 "src/codegen.z"
void  generate_compound(CodegenContext*  ctx, Item*  item) {
#line 334 "src/codegen.z"
Session*  sess = ctx->sess;
;
#line 335 "src/codegen.z"
char*  compound_name = get_str(&sess->interner,item->ident.name) ;
;
#line 337 "src/codegen.z"
char*  compound_kind ;
;
#line 338 "src/codegen.z"
if ((item->kind== ItemKind_Struct)){
#line 338 "src/codegen.z"
compound_kind = "struct";
;
}
else {
#line 339 "src/codegen.z"
compound_kind = "union";
;
}
;
#line 341 "src/codegen.z"
CompoundData data = item->node.compound;
;
#line 343 "src/codegen.z"
fprintf(ctx->out,"typedef %s %s %s;\n",compound_kind,compound_name,compound_name) ;
#line 345 "src/codegen.z"
emit_line_directive(ctx->out,ctx->source,item->span) ;
#line 346 "src/codegen.z"
if ((data.num_fields> 0)){
#line 347 "src/codegen.z"
fprintf(ctx->out,"typedef %s %s {\n",compound_kind,compound_name) ;
#line 348 "src/codegen.z"
u32 i = 0;
;
#line 349 "src/codegen.z"
while ( (i< data.num_fields))
{
#line 350 "src/codegen.z"
generate_type(ctx,data.fields[i].ty) ;
#line 352 "src/codegen.z"
char*  field_name = get_str(&sess->interner,data.fields[i].ident.name) ;
;
#line 353 "src/codegen.z"
fprintf(ctx->out," %s;\n",field_name) ;
#line 354 "src/codegen.z"
i = (i+ 1);
;
}
;
#line 356 "src/codegen.z"
fprintf(ctx->out,"} %s;\n\n",compound_name) ;
}
;
}

#line 360 "src/codegen.z"
void  generate_mod(CodegenContext*  ctx, Module*  module) {
#line 361 "src/codegen.z"
u32 i = 0;
;
#line 362 "src/codegen.z"
while ( (i< module->num_items))
{
#line 363 "src/codegen.z"
generate_item(ctx,module->items[i]) ;
#line 364 "src/codegen.z"
i = (i+ 1);
;
}
;
}

#line 368 "src/codegen.z"
void  generate_item(CodegenContext*  ctx, Item*  item) {
#line 370 "src/codegen.z"
if (((item->kind== ItemKind_Const)|| (item->kind== ItemKind_Variable))){
#line 370 "src/codegen.z"
generate_variable(ctx,item) ;
}
else {
#line 371 "src/codegen.z"
if ((item->kind== ItemKind_Enum)){
#line 371 "src/codegen.z"
generate_enum(ctx,item) ;
}
else {
#line 372 "src/codegen.z"
if ((item->kind== ItemKind_Function)){
#line 372 "src/codegen.z"
generate_function(ctx,item) ;
}
else {
#line 373 "src/codegen.z"
if (((item->kind== ItemKind_Struct)|| (item->kind== ItemKind_Union))){
#line 373 "src/codegen.z"
generate_compound(ctx,item) ;
}
else {
#line 374 "src/codegen.z"
if ((item->kind== ItemKind_Module)){
#line 374 "src/codegen.z"
generate_mod(ctx,item->node.module) ;
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
#line 375 "src/codegen.z"
fprintf(ctx->out,"\n") ;
}

#line 378 "src/codegen.z"
void  generate(Session*  sess, Ast ast, char*  output_file) {
#line 379 "src/codegen.z"
CodegenContext ctx ;
;
#line 381 "src/codegen.z"
ctx.out = fopen(output_file,"w") ;
;
#line 382 "src/codegen.z"
ctx.ident_is_ptr = strmap_create(1024) ;
;
#line 383 "src/codegen.z"
ctx.sess = sess;
;
#line 384 "src/codegen.z"
ctx.source = &sess->source;
;
#line 385 "src/codegen.z"
ctx.ast = &ast;
;
#line 387 "src/codegen.z"
generate_prelude(&ctx) ;
#line 389 "src/codegen.z"
generate_mod(&ctx,ast.root_module) ;
}


#line 17 "src/main.z"
char*  basename(char*  path) ;

#line 18 "src/main.z"
char*  dirname(char*  path) ;

#line 20 "src/main.z"
int main(int argc, char* *  argv) {
#line 21 "src/main.z"
if ((argc!= 3)){
#line 22 "src/main.z"
printf("Usage: compiler INPUT OUTPUT\n") ;
#line 23 "src/main.z"
abort() ;
}
;
#line 26 "src/main.z"
Session sess ;
;
#line 29 "src/main.z"
sess.interner = interner_create() ;
;
#line 30 "src/main.z"
sess.source = source_map_create() ;
;
#line 31 "src/main.z"
char*  root_filename = basename(argv[1]) ;
;
#line 32 "src/main.z"
sess.root_path = dirname(argv[1]) ;
;
#line 34 "src/main.z"
char*  root_module = malloc((strlen(root_filename) + 1)) ;
;
#line 36 "src/main.z"
strtok(root_filename,".z") ;
#line 37 "src/main.z"
char*  dot_found = strtok(null,".") ;
;
#line 38 "src/main.z"
if ((dot_found!= null)){
#line 39 "src/main.z"
memcpy(root_module,root_filename,(dot_found- root_filename)) ;
#line 40 "src/main.z"
root_module[((dot_found- root_filename)+ 1)] = 0;
;
}
else {
#line 42 "src/main.z"
abort() ;
}
;
#line 44 "src/main.z"
Ast ast = parse(&sess,root_module) ;
;
#line 48 "src/main.z"
generate(&sess,ast,argv[2]) ;
#line 50 "src/main.z"
return 0;
;
}


