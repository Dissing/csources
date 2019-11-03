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
typedef struct Span Span;
typedef struct Span {
u32 from;
u32 to;
} Span;


typedef struct SourceFile SourceFile;
typedef struct SourceFile {
char * name;
char * content;
u32 length;
u32 start;
u32 end;
u32 * lines;
u32 num_lines;
} SourceFile;


typedef struct SourceMap SourceMap;
typedef struct SourceMap {
SourceFile * files;
u32 num_files;
u32 * file_starts;
} SourceMap;


SourceMap  source_map_create() {
SourceMap map ;

map.files = calloc(8,1) ;
map.num_files = 0;
map.file_starts = calloc(sizeof(u32) ,1) ;
return map;
}

SourceFile *  source_map_new_file(SourceMap *  self, char *  filename) {
SourceFile * file = &self->files[self->num_files];

self->num_files = (self->num_files+ 1);
file->name = filename;
file->lines = calloc(sizeof(u32) ,4096) ;
file->num_lines = 1;
return file;
}

SourceFile *  source_map_info(SourceMap *  m, Span  span, u32 *  first, u32 *  last) {
u32 i = 0;

SourceFile * file = 0;

while ( (i< m->num_files))
{
if ((m->file_starts[i]>= span.from)){
file = &m->files[i];
break;
}
;
i = (i+ 1);
}
if (!file){
abort() ;
}
;
i = 0;
while ( (i< file->num_lines))
{
if ((file->lines[i]<= span.from)){
*first = i;
}
else {
break;
}
;
i = (i+ 1);
}
i = (i- 1);
while ( (i< file->num_lines))
{
if ((file->lines[i]<= span.to)){
*last = i;
}
else {
break;
}
;
i = (i+ 1);
}
return file;
}

void  emit_line_directive(FILE *  fp, SourceMap *  m, Span  span) {
u32 line_first ;

u32 line_end ;

SourceFile * file = source_map_info(m,span,&line_first,&line_end) ;

fprintf(fp,"#line %u \"%s\"\n",(line_first+ 1),file->name) ;
}

void  source_snippet(SourceMap *  m, Span  span) {
u32 line_first ;

u32 line_last ;

SourceFile * file = source_map_info(m,span,&line_first,&line_last) ;

printf("%s:%u\n",file->name,(line_first+ 1)) ;
char * buffer = malloc(1024) ;

u32 i = line_first;

while ( (i<= line_last))
{
u32 line_start = file->lines[i];

u32 line_end = file->lines[(i+ 1)];

u32 length = (line_end- line_start);

memcpy(buffer,&file->content[line_start],length) ;
buffer[(length+ 1)] = 0;
printf("%s\n",buffer) ;
i = (i+ 1);
}
}

void  emit_error(SourceMap *  m, Span  span, char *  msg) {
printf("error: %s\n",msg) ;
source_snippet(m,span) ;
abort() ;
}

