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
typedef struct LexingContext LexingContext;
typedef struct LexingContext {
u32 start;
u32 current;
u32 line;
SourceFile * source;
Token * tokens;
u32 current_token_idx;
Session * sess;
char * lexeme_buffer;
} LexingContext;


bool  is_alphabetic(char  c) {
return (((c>= 'A')&& (c<= 'Z'))|| ((c>= 'a')&& (c<= 'z')));
}

bool  is_digit(char  c) {
return ((c>= '0')&& (c<= '9'));
}

bool  is_alphanumeric(char  c) {
return (is_alphabetic(c) || is_digit(c) );
}

bool  is_done_lexing(LexingContext *  ctx) {
SourceFile * source = ctx->source;

return (ctx->current>= source->length);
}

char  peek_token(LexingContext *  ctx, u32  offset) {
if (is_done_lexing(ctx) ){
return 0;
}
;
SourceFile * source = ctx->source;

return source->content[(ctx->current+ offset)];
}

char  advance(LexingContext *  ctx) {
ctx->current = (ctx->current+ 1);
SourceFile * source = ctx->source;

return source->content[(ctx->current- 1)];
}

void  add_token(LexingContext *  ctx, TokenKind  kind, Sid  lexeme) {
Token token ;

token.kind = kind;
token.lexeme = lexeme;
token.span.from = ctx->start;
token.span.to = ctx->current;
ctx->tokens[ctx->current_token_idx] = token;
ctx->current_token_idx = (ctx->current_token_idx+ 1);
}

void  add_simple_token(LexingContext *  ctx, TokenKind  kind) {
Sid null_sid ;

null_sid.x = 0;
add_token(ctx,kind,null_sid) ;
}

void  add_lookahead_conditional_token(LexingContext *  ctx, char  expect, TokenKind  first, TokenKind  second) {
TokenKind kind ;

if ((peek_token(ctx,0) == expect)){
advance(ctx) ;
kind = first;
}
else {
kind = second;
}
;
Sid null_sid ;

null_sid.x = 0;
add_token(ctx,kind,null_sid) ;
}

void  read_newline(LexingContext *  ctx) {
SourceFile * source = ctx->source;

source->lines[source->num_lines] = (ctx->start+ 1);
source->num_lines = (source->num_lines+ 1);
}

Sid  get_lexeme(LexingContext *  ctx, u32  start_offset, u32  end_offset) {
u32 str_len = (ctx->current- ((ctx->start+ start_offset)+ end_offset));

SourceFile * source = ctx->source;

memcpy(ctx->lexeme_buffer,&source->content[(ctx->start+ start_offset)],str_len) ;
ctx->lexeme_buffer[str_len] = 0;
Session * sess = ctx->sess;

Sid sid = intern(&sess->interner,ctx->lexeme_buffer) ;

return sid;
}

void  single_line_comment(LexingContext *  ctx) {
while ( ((peek_token(ctx,0) != '\n')&& !is_done_lexing(ctx) ))
{
advance(ctx) ;
}
}

TokenKind  is_keyword(char *  s) {
if (!strcmp(s,"break") ){
return _TokenKind_Break;
}
;
if (!strcmp(s,"continue") ){
return _TokenKind_Continue;
}
;
if (!strcmp(s,"const") ){
return _TokenKind_Continue;
}
;
if (!strcmp(s,"defer") ){
return _TokenKind_Defer;
}
;
if (!strcmp(s,"enum") ){
return _TokenKind_Enum;
}
;
if (!strcmp(s,"else") ){
return _TokenKind_Else;
}
;
if (!strcmp(s,"false") ){
return _TokenKind_False;
}
;
if (!strcmp(s,"fn") ){
return _TokenKind_Fn;
}
;
if (!strcmp(s,"for") ){
return _TokenKind_For;
}
;
if (!strcmp(s,"if") ){
return _TokenKind_If;
}
;
if (!strcmp(s,"mod") ){
return _TokenKind_Mod;
}
;
if (!strcmp(s,"return") ){
return _TokenKind_Return;
}
;
if (!strcmp(s,"struct") ){
return _TokenKind_Struct;
}
;
if (!strcmp(s,"true") ){
return _TokenKind_True;
}
;
if (!strcmp(s,"union") ){
return _TokenKind_Union;
}
;
if (!strcmp(s,"var") ){
return _TokenKind_Var;
}
;
if (!strcmp(s,"val") ){
return _TokenKind_Val;
}
;
if (!strcmp(s,"while") ){
return _TokenKind_While;
}
;
return _TokenKind_Invalid;
}

void  lex_char(LexingContext *  ctx) {
SourceFile * source = ctx->source;

u32 start_line = (source->num_lines+ 1);

while ( (((peek_token(ctx,0) != '\'')|| ((peek_token(ctx,-1) == '\\')&& (peek_token(ctx,-2) != '\\')))&& !is_done_lexing(ctx) ))
{
char c = advance(ctx) ;

if ((c== '\n')){
read_newline(ctx) ;
}
;
}
if (is_done_lexing(ctx) ){
printf("Unterminated char starting on line %u\n",start_line) ;
abort() ;
}
;
advance(ctx) ;
add_token(ctx,_TokenKind_Char,get_lexeme(ctx,1,1) ) ;
}

void  lex_string(LexingContext *  ctx) {
SourceFile * source = ctx->source;

u32 start_line = (source->num_lines+ 1);

while ( (((peek_token(ctx,0) != '"')|| ((peek_token(ctx,-1) == '\\')&& (peek_token(ctx,-2) != '\\')))&& !is_done_lexing(ctx) ))
{
char c = advance(ctx) ;

if ((c== '\n')){
read_newline(ctx) ;
}
;
}
if (is_done_lexing(ctx) ){
printf("Unterminated string starting on line %u\n",start_line) ;
abort() ;
}
;
advance(ctx) ;
add_token(ctx,_TokenKind_String,get_lexeme(ctx,1,1) ) ;
}

void  lex_number(LexingContext *  ctx) {
while ( is_digit(peek_token(ctx,0) ) )
{
advance(ctx) ;
}
bool dot_encountered = false;

if (((peek_token(ctx,0) == '.')&& is_digit(peek_token(ctx,1) ) )){
dot_encountered = true;
advance(ctx) ;
while ( is_digit(peek_token(ctx,0) ) )
{
advance(ctx) ;
}
}
;
TokenKind t ;

if (dot_encountered){
t = _TokenKind_Float;
}
else {
t = _TokenKind_Integer;
}
;
add_token(ctx,t,get_lexeme(ctx,0,0) ) ;
}

void  lex_identifier(LexingContext *  ctx) {
while ( (is_alphanumeric(peek_token(ctx,0) ) || (peek_token(ctx,0) == '_')))
{
advance(ctx) ;
}
Sid lexeme = get_lexeme(ctx,0,0) ;

Session * sess = ctx->sess;

char * lexeme_str = get_str(&sess->interner,lexeme) ;

TokenKind keyword = is_keyword(lexeme_str) ;

if ((keyword!= _TokenKind_Invalid)){
add_simple_token(ctx,keyword) ;
}
else {
add_token(ctx,_TokenKind_Identifier,lexeme) ;
}
;
}

void  scan_token(LexingContext *  ctx) {
char c = advance(ctx) ;

if ((c== '(')){
add_simple_token(ctx,_TokenKind_LeftParen) ;
}
else {
if ((c== ')')){
add_simple_token(ctx,_TokenKind_RightParen) ;
}
else {
if ((c== '[')){
add_simple_token(ctx,_TokenKind_LeftBracket) ;
}
else {
if ((c== ']')){
add_simple_token(ctx,_TokenKind_RightBracket) ;
}
else {
if ((c== '{')){
add_simple_token(ctx,_TokenKind_LeftCurly) ;
}
else {
if ((c== '}')){
add_simple_token(ctx,_TokenKind_RightCurly) ;
}
else {
if ((c== '+')){
add_simple_token(ctx,_TokenKind_Plus) ;
}
else {
if ((c== '*')){
add_simple_token(ctx,_TokenKind_Star) ;
}
else {
if ((c== '%')){
add_simple_token(ctx,_TokenKind_Percent) ;
}
else {
if ((c== '^')){
add_simple_token(ctx,_TokenKind_Hat) ;
}
else {
if ((c== ';')){
add_simple_token(ctx,_TokenKind_Semicolon) ;
}
else {
if ((c== '.')){
add_simple_token(ctx,_TokenKind_Dot) ;
}
else {
if ((c== ',')){
add_simple_token(ctx,_TokenKind_Comma) ;
}
else {
if ((c== '-')){
add_lookahead_conditional_token(ctx,'>',_TokenKind_Arrow,_TokenKind_Minus) ;
}
else {
if ((c== ':')){
add_lookahead_conditional_token(ctx,':',_TokenKind_ColonColon,_TokenKind_Colon) ;
}
else {
if ((c== '=')){
add_lookahead_conditional_token(ctx,'=',_TokenKind_EqualEqual,_TokenKind_Equal) ;
}
else {
if ((c== '!')){
add_lookahead_conditional_token(ctx,'=',_TokenKind_BangEqual,_TokenKind_Bang) ;
}
else {
if ((c== '&')){
add_lookahead_conditional_token(ctx,'&',_TokenKind_AndAnd,_TokenKind_And) ;
}
else {
if ((c== '|')){
add_lookahead_conditional_token(ctx,'|',_TokenKind_OrOr,_TokenKind_Or) ;
}
else {
if ((c== '<')){
char n1 = peek_token(ctx,0) ;

if ((n1== '<')){
advance(ctx) ;
add_simple_token(ctx,_TokenKind_LessLess) ;
}
else {
if ((n1== '=')){
advance(ctx) ;
add_simple_token(ctx,_TokenKind_LessEqual) ;
}
else {
add_simple_token(ctx,_TokenKind_Less) ;
}
;
}
;
}
else {
if ((c== '>')){
char n2 = peek_token(ctx,0) ;

if ((n2== '>')){
advance(ctx) ;
add_simple_token(ctx,_TokenKind_GreaterGreater) ;
}
else {
if ((n2== '=')){
advance(ctx) ;
add_simple_token(ctx,_TokenKind_GreaterEqual) ;
}
else {
add_simple_token(ctx,_TokenKind_Greater) ;
}
;
}
;
}
else {
if ((c== '/')){
if ((peek_token(ctx,0) == '/')){
single_line_comment(ctx) ;
}
else {
add_simple_token(ctx,_TokenKind_Slash) ;
}
;
}
else {
if ((((c== ' ')|| (c== '\t'))|| (c== '\r'))){
}
else {
if ((c== '\n')){
read_newline(ctx) ;
}
else {
if ((c== '"')){
lex_string(ctx) ;
}
else {
if ((c== '\'')){
lex_char(ctx) ;
}
else {
if (is_digit(c) ){
lex_number(ctx) ;
}
else {
if ((is_alphabetic(c) || (c== '_'))){
lex_identifier(ctx) ;
}
else {
SourceFile * source = ctx->source;

printf("Unexpected character %c = %d on line %u\n",c,c,source->num_lines) ;
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

void  lex(Session *  sess, SourceFile *  source, Token * *  tokens, u32 *  num_tokens) {
LexingContext * ctx = malloc(sizeof(LexingContext) ) ;

ctx->source = source;
ctx->start = 0;
ctx->current = 0;
ctx->tokens = malloc((sizeof(Token) * 10000)) ;
ctx->current_token_idx = 0;
ctx->sess = sess;
ctx->lexeme_buffer = malloc(1024) ;
while ( !is_done_lexing(ctx) )
{
ctx->start = ctx->current;
scan_token(ctx) ;
}
source->end = ctx->current;
if ((ctx->current_token_idx> 10000)){
printf("Lexer token overflow: %u!\n",ctx->current_token_idx) ;
abort() ;
}
;
*tokens = ctx->tokens;
*num_tokens = ctx->current_token_idx;
}

