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
void  load_file_content(SourceFile *  file) {
FILE * fp = fopen(file->name,"rb") ;

fseek(fp,0,SEEK_END) ;
file->length = ftell(fp) ;
rewind(fp) ;
file->content = malloc(file->length) ;
fread(file->content,1,file->length,fp) ;
fclose(fp) ;
}

int  main(int  argc, char * *  argv) {
if ((argc!= 3)){
printf("Usage: compiler INPUT OUTPUT\n") ;
abort() ;
}
;
Session sess ;

sess.interner = interner_create() ;
sess.source = source_map_create() ;
SourceFile * source_file = source_map_new_file(&sess.source,argv[1]) ;

load_file_content(source_file) ;
Token * tokens ;

u32 num_tokens ;

lex(&sess,source_file,&tokens,&num_tokens) ;
CompilationUnit unit = parse(&sess,tokens,num_tokens) ;

resolve(&sess,&unit) ;
generate(&sess,unit,argv[2]) ;
return 0;
}

