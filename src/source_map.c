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
typedef struct Span Span;
#line 1 "src/source_map.z"
typedef struct Span {
  u32 from;
  u32 to;
} Span;

typedef struct SourceFile SourceFile;
#line 6 "src/source_map.z"
typedef struct SourceFile {
  char *name;
  char *content;
  u32 length;
  u32 start;
  u32 end;
  u32 *lines;
  u32 num_lines;
} SourceFile;

typedef struct SourceMap SourceMap;
#line 16 "src/source_map.z"
typedef struct SourceMap {
  SourceFile *files;
  u32 num_files;
  u32 *file_starts;
} SourceMap;

#line 22 "src/source_map.z"
SourceMap source_map_create() {
#line 23 "src/source_map.z"
#line 23 "src/source_map.z"
  SourceMap map;

#line 24 "src/source_map.z"
  map.files = calloc(sizeof(SourceFile), 16);
#line 25 "src/source_map.z"
  map.num_files = 0;
#line 26 "src/source_map.z"
  map.file_starts = calloc(sizeof(u32), 16);
#line 28 "src/source_map.z"
  return map;
}

#line 31 "src/source_map.z"
void load_file_content(SourceFile *file) {
#line 32 "src/source_map.z"
#line 32 "src/source_map.z"
  FILE *fp = fopen(file->name, "rb");

#line 33 "src/source_map.z"
  fseek(fp, 0, SEEK_END);
#line 34 "src/source_map.z"
  file->length = ftell(fp);
#line 35 "src/source_map.z"
  rewind(fp);
#line 36 "src/source_map.z"
  file->content = malloc(file->length);
#line 37 "src/source_map.z"
  fread(file->content, 1, file->length, fp);
#line 38 "src/source_map.z"
  fclose(fp);
}

#line 41 "src/source_map.z"
SourceFile *source_map_new_file(SourceMap *self, char *path, char *filename) {
#line 42 "src/source_map.z"
#line 42 "src/source_map.z"
  SourceFile *file = &self->files[self->num_files];

#line 43 "src/source_map.z"
  self->num_files = (self->num_files + 1);
#line 45 "src/source_map.z"
#line 45 "src/source_map.z"
  u32 needed_length = ((strlen(path) + strlen(filename)) + 4);

#line 47 "src/source_map.z"
#line 47 "src/source_map.z"
  char *name_buffer = malloc(needed_length);

#line 49 "src/source_map.z"
#line 49 "src/source_map.z"
  char *dot_found = strtok(filename, ".z");

#line 50 "src/source_map.z"
  if ((dot_found != null)) {
#line 50 "src/source_map.z"
    sprintf(name_buffer, "%s/%s.z", path, filename);
  } else {
#line 51 "src/source_map.z"
    sprintf(name_buffer, "%s/%s", path, filename);
  };
#line 53 "src/source_map.z"
  file->name = name_buffer;
#line 54 "src/source_map.z"
  file->lines = calloc(sizeof(u32), 4096);
#line 55 "src/source_map.z"
  file->num_lines = 1;
#line 57 "src/source_map.z"
  if ((self->num_files > 1)) {
#line 57 "src/source_map.z"
    file->start = self->files[(self->num_files - 2)].end;
  } else {
#line 58 "src/source_map.z"
    file->start = 0;
  };
#line 60 "src/source_map.z"
  self->file_starts[(self->num_files - 1)] = file->start;
#line 62 "src/source_map.z"
  load_file_content(file);
#line 64 "src/source_map.z"
  return file;
}

#line 67 "src/source_map.z"
void source_file_newline(SourceFile *self, u32 position) {
#line 68 "src/source_map.z"
  self->lines[self->num_lines] = (self->start + position);
#line 69 "src/source_map.z"
  self->num_lines = (self->num_lines + 1);
}

#line 72 "src/source_map.z"
void source_file_done(SourceFile *self, u32 length) {
#line 73 "src/source_map.z"
  self->end = (self->start + length);
}

#line 76 "src/source_map.z"
SourceFile *source_map_info(SourceMap *m, Span span, u32 *first, u32 *last) {
#line 77 "src/source_map.z"
#line 77 "src/source_map.z"
  u32 i = 0;

#line 78 "src/source_map.z"
#line 78 "src/source_map.z"
  SourceFile *file = 0;

#line 79 "src/source_map.z"
  while ((i < m->num_files)) {
#line 80 "src/source_map.z"
    if ((m->file_starts[i] > span.from)) {
#line 80 "src/source_map.z"
      break;
    };
#line 81 "src/source_map.z"
    file = &m->files[i];
#line 82 "src/source_map.z"
    i = (i + 1);
  };
#line 85 "src/source_map.z"
  if (!file) {
#line 85 "src/source_map.z"
    abort();
  };
#line 87 "src/source_map.z"
  i = 0;
#line 88 "src/source_map.z"
  while ((i < file->num_lines)) {
#line 89 "src/source_map.z"
    if ((file->lines[i] <= span.from)) {
#line 90 "src/source_map.z"
      *first = i;
    } else {
#line 92 "src/source_map.z"
      break;
    };
#line 93 "src/source_map.z"
    i = (i + 1);
  };
#line 95 "src/source_map.z"
  i = (i - 1);
#line 96 "src/source_map.z"
  while ((i < file->num_lines)) {
#line 97 "src/source_map.z"
    if ((file->lines[i] <= span.to)) {
#line 98 "src/source_map.z"
      *last = i;
    } else {
#line 100 "src/source_map.z"
      break;
    };
#line 101 "src/source_map.z"
    i = (i + 1);
  };
#line 104 "src/source_map.z"
  return file;
}

#line 107 "src/source_map.z"
void emit_line_directive(FILE *fp, SourceMap *m, Span span) {
#line 108 "src/source_map.z"
#line 108 "src/source_map.z"
  u32 line_first;

#line 109 "src/source_map.z"
#line 109 "src/source_map.z"
  u32 line_end;

#line 111 "src/source_map.z"
#line 111 "src/source_map.z"
  SourceFile *file = source_map_info(m, span, &line_first, &line_end);

#line 113 "src/source_map.z"
  fprintf(fp, "#line %u \"%s\"\n", (line_first + 1), file->name);
}

#line 116 "src/source_map.z"
void source_snippet(SourceMap *m, Span span) {
#line 118 "src/source_map.z"
#line 118 "src/source_map.z"
  u32 line_first;

#line 119 "src/source_map.z"
#line 119 "src/source_map.z"
  u32 line_last;

#line 121 "src/source_map.z"
#line 121 "src/source_map.z"
  SourceFile *file = source_map_info(m, span, &line_first, &line_last);

#line 123 "src/source_map.z"
  printf("%s:%u\n", file->name, (line_first + 1));
#line 125 "src/source_map.z"
#line 125 "src/source_map.z"
  char *buffer = malloc(1024);

#line 126 "src/source_map.z"
#line 126 "src/source_map.z"
  u32 i = line_first;

#line 127 "src/source_map.z"
  while ((i <= line_last)) {
#line 128 "src/source_map.z"
#line 128 "src/source_map.z"
    u32 line_start = file->lines[i];

#line 129 "src/source_map.z"
#line 129 "src/source_map.z"
    u32 line_end = file->lines[(i + 1)];

#line 130 "src/source_map.z"
#line 130 "src/source_map.z"
    u32 length = (line_end - line_start);

#line 132 "src/source_map.z"
    memcpy(buffer, &file->content[line_start], length);
#line 133 "src/source_map.z"
    buffer[(length + 1)] = 0;
#line 134 "src/source_map.z"
    printf("%s\n", buffer);
#line 135 "src/source_map.z"
    i = (i + 1);
  };
}
