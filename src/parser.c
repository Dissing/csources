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
typedef struct ParsingContext ParsingContext;
typedef struct ParsingContext {
u64 current_token;
Token * tokens;
u64 num_tokens;
SourceMap * source_map;
Session * sess;
CompilationUnit unit;
u32 next_owner;
u32 current_owner;
} ParsingContext;


bool  is_done_parsing(ParsingContext *  ctx) {
return (ctx->num_tokens== ctx->current_token);
}

bool  accept(ParsingContext *  ctx, TokenKind  token) {
Token tok = ctx->tokens[ctx->current_token];

if ((!is_done_parsing(ctx) && (tok.kind== token))){
ctx->current_token = (ctx->current_token+ 1);
return true;
}
;
return false;
}

Token  look_ahead(ParsingContext *  ctx, u64  offset) {
if ((ctx->current_token== ctx->num_tokens)){
Token eof_tok ;

eof_tok.kind = EOF;
return eof_tok;
}
else {
return ctx->tokens[(ctx->current_token+ offset)];
}
;
}

Token  consume(ParsingContext *  ctx) {
ctx->current_token = (ctx->current_token+ 1);
return ctx->tokens[(ctx->current_token- 1)];
}

Token  expect(ParsingContext *  ctx, TokenKind  kind) {
Token tok = consume(ctx) ;

if ((tok.kind== kind)){
return tok;
}
else {
emit_error(ctx->source_map,tok.span,"Expect failed!") ;
abort() ;
}
;
}

u32  span_start(ParsingContext *  ctx) {
return ctx->tokens[ctx->current_token].span.from;
}

u32  span_end(ParsingContext *  ctx) {
return ctx->tokens[(ctx->current_token- 1)].span.to;
}

Ident  parse_identifier(ParsingContext *  ctx) {
Token tok = consume(ctx) ;

if ((tok.kind!= _TokenKind_Identifier)){
emit_error(ctx->source_map,tok.span,"Invalid identifier") ;
}
;
Ident ident ;

ident.name = tok.lexeme;
return ident;
}

Path  parse_path(ParsingContext *  ctx) {
Path path ;

path.segments = malloc((8* 4)) ;
path.num_segments = 0;
while ( true)
{
path.segments[path.num_segments] = parse_identifier(ctx) ;
path.num_segments = (path.num_segments+ 1);
if (!accept(ctx,_TokenKind_ColonColon) ){
break;
}
;
}
return path;
}

Expr *  parse_path_expr(ParsingContext *  ctx) {
Expr * expr = malloc(sizeof(Expr) ) ;

expr->kind = _ExprKind_Path;
expr->node.path = parse_path(ctx) ;
return expr;
}

Type *  parse_type(ParsingContext *  ctx) {
TypeKindNode node ;

TypeKind kind ;

Token token = consume(ctx) ;

if ((token.kind== _TokenKind_Identifier)){
kind = _TypeKind_Path;
node.path = token.lexeme;
}
else {
if ((token.kind== _TokenKind_Star)){
kind = _TypeKind_Ptr;
node.ptr = parse_type(ctx) ;
}
else {
emit_error(ctx->source_map,token.span,"Expected type") ;
}
;
}
;
Type * type = malloc(sizeof(Type) ) ;

type->kind = kind;
type->node = node;
return type;
}

BinaryOperatorKind  convert_token_to_binary_operator(TokenKind  tok) {
if ((tok== _TokenKind_Plus)){
return _BinaryOperatorKind_Addition;
}
else {
if ((tok== _TokenKind_Minus)){
return _BinaryOperatorKind_Subtraction;
}
else {
if ((tok== _TokenKind_Star)){
return _BinaryOperatorKind_Product;
}
else {
if ((tok== _TokenKind_Slash)){
return _BinaryOperatorKind_Division;
}
else {
if ((tok== _TokenKind_Percent)){
return _BinaryOperatorKind_Modulus;
}
else {
if ((tok== _TokenKind_Less)){
return _BinaryOperatorKind_Less;
}
else {
if ((tok== _TokenKind_LessEqual)){
return _BinaryOperatorKind_LessEq;
}
else {
if ((tok== _TokenKind_Greater)){
return _BinaryOperatorKind_Greater;
}
else {
if ((tok== _TokenKind_GreaterEqual)){
return _BinaryOperatorKind_GreaterEq;
}
else {
if ((tok== _TokenKind_EqualEqual)){
return _BinaryOperatorKind_Equality;
}
else {
if ((tok== _TokenKind_BangEqual)){
return _BinaryOperatorKind_NotEq;
}
else {
if ((tok== _TokenKind_AndAnd)){
return _BinaryOperatorKind_And;
}
else {
if ((tok== _TokenKind_OrOr)){
return _BinaryOperatorKind_Or;
}
else {
if ((tok== _TokenKind_And)){
return _BinaryOperatorKind_BAnd;
}
else {
if ((tok== _TokenKind_Or)){
return _BinaryOperatorKind_BOr;
}
else {
if ((tok== _TokenKind_Hat)){
return _BinaryOperatorKind_Xor;
}
else {
if ((tok== _TokenKind_LessLess)){
return _BinaryOperatorKind_LeftShift;
}
else {
if ((tok== _TokenKind_GreaterGreater)){
return _BinaryOperatorKind_RightShift;
}
else {
return _BinaryOperatorKind_Invalid;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}

u32  get_binary_operator_precedence(BinaryOperatorKind  op) {
if ((op== _BinaryOperatorKind_Product)){
return 10;
}
else {
if ((op== _BinaryOperatorKind_Division)){
return 10;
}
else {
if ((op== _BinaryOperatorKind_Modulus)){
return 10;
}
else {
if ((op== _BinaryOperatorKind_Addition)){
return 9;
}
else {
if ((op== _BinaryOperatorKind_Subtraction)){
return 9;
}
else {
if ((op== _BinaryOperatorKind_LeftShift)){
return 8;
}
else {
if ((op== _BinaryOperatorKind_RightShift)){
return 8;
}
else {
if ((op== _BinaryOperatorKind_BAnd)){
return 7;
}
else {
if ((op== _BinaryOperatorKind_Xor)){
return 6;
}
else {
if ((op== _BinaryOperatorKind_BOr)){
return 5;
}
else {
if ((op== _BinaryOperatorKind_Less)){
return 4;
}
else {
if ((op== _BinaryOperatorKind_LessEq)){
return 4;
}
else {
if ((op== _BinaryOperatorKind_Greater)){
return 4;
}
else {
if ((op== _BinaryOperatorKind_GreaterEq)){
return 4;
}
else {
if ((op== _BinaryOperatorKind_Equality)){
return 4;
}
else {
if ((op== _BinaryOperatorKind_NotEq)){
return 4;
}
else {
if ((op== _BinaryOperatorKind_And)){
return 3;
}
else {
if ((op== _BinaryOperatorKind_Or)){
return 2;
}
else {
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

u32  get_current_precedence(ParsingContext *  ctx) {
if ((ctx->num_tokens<= ctx->current_token)){
return 0;
}
else {
Token tok = ctx->tokens[ctx->current_token];

u32 op_precedence = get_binary_operator_precedence(convert_token_to_binary_operator(tok.kind) ) ;

if ((op_precedence> 0)){
return op_precedence;
}
else {
if ((tok.kind== _TokenKind_Dot)){
return 13;
}
else {
if (((tok.kind== _TokenKind_LeftBracket)|| (tok.kind== _TokenKind_LeftParen))){
return 12;
}
else {
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

Expr *  parse_expression(ParsingContext *  ctx, u32  precedence) ;

Expr *  parse_integer_literal(ParsingContext *  ctx) {
Token tok = expect(ctx,_TokenKind_Integer) ;

Expr * expr = malloc(sizeof(Expr) ) ;

expr->kind = _ExprKind_Literal;
expr->node.lit.kind = _LiteralKind_Int;
Session * sess = ctx->sess;

expr->node.lit.value.integer = atol(get_str(&sess->interner,tok.lexeme) ) ;
return expr;
}

Expr *  parse_float_literal(ParsingContext *  ctx) {
Token tok = expect(ctx,_TokenKind_Float) ;

Expr * expr = malloc(sizeof(Expr) ) ;

expr->kind = _ExprKind_Literal;
expr->node.lit.kind = _LiteralKind_Float;
Session * sess = ctx->sess;

expr->node.lit.value.floating = atof(get_str(&sess->interner,tok.lexeme) ) ;
return expr;
}

Expr *  parse_char_literal(ParsingContext *  ctx) {
Token tok = expect(ctx,_TokenKind_Char) ;

Expr * expr = malloc(sizeof(Expr) ) ;

expr->kind = _ExprKind_Literal;
expr->node.lit.kind = _LiteralKind_Char;
Session * sess = ctx->sess;

char * s = get_str(&sess->interner,tok.lexeme) ;

u32 len = strlen(s) ;

if (((len== 2)&& (s[0]== '\\'))){
char c ;

if ((s[1]== 'n')){
c = '\n';
}
else {
if ((s[1]== 't')){
c = '\t';
}
else {
if ((s[1]== 'r')){
c = '\r';
}
else {
if ((s[1]== '\\')){
c = '\\';
}
else {
if ((s[1]== '\'')){
c = '\'';
}
else {
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
expr->node.lit.value.ch = c;
}
else {
if ((len== 1)){
expr->node.lit.value.ch = s[0];
}
else {
emit_error(ctx->source_map,tok.span,"Invalid char literal") ;
}
;
}
;
return expr;
}

Expr *  parse_string_literal(ParsingContext *  ctx) {
Token tok = expect(ctx,_TokenKind_String) ;

Expr * expr = malloc(sizeof(Expr) ) ;

expr->kind = _ExprKind_Literal;
expr->node.lit.kind = _LiteralKind_Str;
expr->node.lit.value.str = tok.lexeme;
return expr;
}

Expr *  parse_bool_literal(ParsingContext *  ctx) {
Token tok = consume(ctx) ;

Expr * expr = malloc(sizeof(Expr) ) ;

expr->kind = _ExprKind_Literal;
expr->node.lit.kind = _LiteralKind_Bool;
expr->node.lit.value.boolean = (tok.kind== _TokenKind_True);
return expr;
}

Expr *  parse_call(ParsingContext *  ctx, Expr *  left) {
Expr * result = malloc(sizeof(Expr) ) ;

result->kind = _ExprKind_Call;
result->node.call.func = left;
result->node.call.args = malloc((8* 16)) ;
result->node.call.num_args = 0;
if (!accept(ctx,_TokenKind_RightParen) ){
while ( true)
{
Expr * expr = parse_expression(ctx,0) ;

result->node.call.args[result->node.call.num_args] = expr;
result->node.call.num_args = (result->node.call.num_args+ 1);
if (!accept(ctx,_TokenKind_Comma) ){
break;
}
;
}
expect(ctx,_TokenKind_RightParen) ;
}
;
return result;
}

Expr *  parse_prefix_operator(ParsingContext *  ctx) {
Expr * expr = malloc(sizeof(Expr) ) ;

expr->kind = _ExprKind_Unary;
Token tok = consume(ctx) ;

if ((tok.kind== _TokenKind_Minus)){
expr->node.unary.op = _UnaryOperatorKind_Negation;
}
else {
if ((tok.kind== _TokenKind_Bang)){
expr->node.unary.op = _UnaryOperatorKind_Complement;
}
else {
if ((tok.kind== _TokenKind_And)){
expr->node.unary.op = _UnaryOperatorKind_Refer;
}
else {
if ((tok.kind== _TokenKind_Star)){
expr->node.unary.op = _UnaryOperatorKind_Deref;
}
else {
emit_error(ctx->source_map,tok.span,"Invalid prefix operator") ;
}
;
}
;
}
;
}
;
expr->node.unary.inner = parse_expression(ctx,11) ;
return expr;
}

Expr *  parse_binary_operator(ParsingContext *  ctx, Expr *  left, BinaryOperatorKind  operator) {
u32 precedence = get_binary_operator_precedence(operator) ;

Expr * right = parse_expression(ctx,precedence) ;

Expr * expr = malloc(sizeof(Expr) ) ;

expr->kind = _ExprKind_Binary;
expr->node.binary.op = operator;
expr->node.binary.left = left;
expr->node.binary.right = right;
return expr;
}

Expr *  parse_field_access(ParsingContext *  ctx, Expr *  left) {
Expr * expr = malloc(sizeof(Expr) ) ;

expr->kind = _ExprKind_Field;
expr->node.field.ident = parse_identifier(ctx) ;
expr->node.field.strct = left;
return expr;
}

Expr *  parse_indexing(ParsingContext *  ctx, Expr *  left) {
Expr * expr = malloc(sizeof(Expr) ) ;

expr->kind = _ExprKind_Indexing;
expr->node.indexing.index = parse_expression(ctx,0) ;
expr->node.indexing.array = left;
expect(ctx,_TokenKind_RightBracket) ;
return expr;
}

Expr *  parse_infix_operator(ParsingContext *  ctx, Expr *  left, Token  tok) {
if ((tok.kind== _TokenKind_LeftParen)){
return parse_call(ctx,left) ;
}
;
if ((tok.kind== _TokenKind_Dot)){
return parse_field_access(ctx,left) ;
}
;
if ((tok.kind== _TokenKind_LeftBracket)){
return parse_indexing(ctx,left) ;
}
;
BinaryOperatorKind op = convert_token_to_binary_operator(tok.kind) ;

if ((op!= _BinaryOperatorKind_Invalid)){
return parse_binary_operator(ctx,left,op) ;
}
else {
emit_error(ctx->source_map,tok.span,"Unsupported infix operator") ;
}
;
return null;
}

Stmt *  parse_stmt(ParsingContext *  ctx) ;

Block *  parse_block(ParsingContext *  ctx) {
Block * block = malloc(sizeof(Block) ) ;

block->stmts = malloc((8* 128)) ;
block->num_stmts = 0;
block->span.from = span_start(ctx) ;
Token next = look_ahead(ctx,0) ;

if ((next.kind== _TokenKind_LeftCurly)){
expect(ctx,_TokenKind_LeftCurly) ;
u32 i = 0;

while ( !accept(ctx,_TokenKind_RightCurly) )
{
block->stmts[i] = parse_stmt(ctx) ;
block->num_stmts = (block->num_stmts+ 1);
i = (i+ 1);
}
}
else {
block->stmts[0] = parse_stmt(ctx) ;
block->num_stmts = 1;
}
;
block->span.to = span_end(ctx) ;
return block;
}

Expr *  parse_block_expr(ParsingContext *  ctx) {
Expr * expr = malloc(sizeof(Expr) ) ;

expr->kind = _ExprKind_Block;
expr->node.block = parse_block(ctx) ;
return expr;
}

Expr *  parse_if(ParsingContext *  ctx) {
expect(ctx,_TokenKind_If) ;
Expr * expr = malloc(sizeof(Expr) ) ;

expr->kind = _ExprKind_Conditional;
expr->node.conditional.condition = parse_expression(ctx,0) ;
expr->node.conditional.then = parse_block_expr(ctx) ;
if (accept(ctx,_TokenKind_Else) ){
expr->node.conditional.otherwise = parse_block_expr(ctx) ;
}
else {
expr->node.conditional.otherwise = null;
}
;
return expr;
}

Expr *  parse_while(ParsingContext *  ctx) {
expect(ctx,_TokenKind_While) ;
Expr * expr = malloc(sizeof(Expr) ) ;

expr->kind = _ExprKind_While;
expr->node.whl.condition = parse_expression(ctx,0) ;
expr->node.whl.body = parse_block_expr(ctx) ;
return expr;
}

Expr *  parse_expression(ParsingContext *  ctx, u32  precedence) {
Token tok = look_ahead(ctx,0) ;

Span span ;

span.from = span_start(ctx) ;
Expr * left ;

if ((tok.kind== _TokenKind_Identifier)){
left = parse_path_expr(ctx) ;
}
else {
if ((tok.kind== _TokenKind_Integer)){
left = parse_integer_literal(ctx) ;
}
else {
if ((tok.kind== _TokenKind_Char)){
left = parse_char_literal(ctx) ;
}
else {
if ((tok.kind== _TokenKind_String)){
left = parse_string_literal(ctx) ;
}
else {
if ((tok.kind== _TokenKind_Float)){
left = parse_float_literal(ctx) ;
}
else {
if (((tok.kind== _TokenKind_False)|| (tok.kind== _TokenKind_True))){
left = parse_bool_literal(ctx) ;
}
else {
if (((((tok.kind== _TokenKind_Minus)|| (tok.kind== _TokenKind_Bang))|| (tok.kind== _TokenKind_And))|| (tok.kind== _TokenKind_Star))){
left = parse_prefix_operator(ctx) ;
}
else {
if ((tok.kind== _TokenKind_If)){
left = parse_if(ctx) ;
}
else {
if ((tok.kind== _TokenKind_While)){
left = parse_while(ctx) ;
}
else {
if ((tok.kind== _TokenKind_LeftParen)){
expect(ctx,_TokenKind_LeftParen) ;
left = parse_expression(ctx,0) ;
expect(ctx,_TokenKind_RightParen) ;
}
else {
if ((tok.kind== _TokenKind_LeftCurly)){
left = parse_block_expr(ctx) ;
}
else {
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
while ( (precedence< get_current_precedence(ctx) ))
{
Token next_tok = consume(ctx) ;

left = parse_infix_operator(ctx,left,next_tok) ;
}
span.to = span_end(ctx) ;
left->span = span;
return left;
}

NodeId  parse_item(ParsingContext *  ctx) ;

Stmt *  parse_stmt(ParsingContext *  ctx) {
Stmt * stmt = malloc(sizeof(Stmt) ) ;

stmt->span.from = span_start(ctx) ;
Token tok = look_ahead(ctx,0) ;

if (accept(ctx,_TokenKind_Break) ){
stmt->kind = _StmtKind_Break;
}
else {
if (accept(ctx,_TokenKind_Continue) ){
stmt->kind = _StmtKind_Continue;
}
else {
if (accept(ctx,_TokenKind_Return) ){
stmt->kind = _StmtKind_Return;
stmt->node._return = parse_expression(ctx,0) ;
}
else {
if (accept(ctx,_TokenKind_Defer) ){
stmt->kind = _StmtKind_Defer;
stmt->node._defer = parse_expression(ctx,0) ;
}
else {
if (accept(ctx,_TokenKind_Semicolon) ){
stmt->kind = _StmtKind_Empty;
}
else {
if (((tok.kind== _TokenKind_Var)|| (tok.kind== _TokenKind_Val))){
stmt->kind = _StmtKind_Item;
stmt->node.item = parse_item(ctx) ;
}
else {
Expr * left = parse_expression(ctx,0) ;

Token next = look_ahead(ctx,0) ;

if ((next.kind== _TokenKind_Equal)){
stmt->kind = _StmtKind_Assignment;
stmt->node.assignment.left = left;
expect(ctx,_TokenKind_Equal) ;
stmt->node.assignment.right = parse_expression(ctx,0) ;
}
else {
stmt->kind = _StmtKind_Expr;
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
accept(ctx,_TokenKind_Semicolon) ;
stmt->span.to = span_end(ctx) ;
return stmt;
}

NodeId  parse_body(ParsingContext *  ctx, NodeId  owner) {
NodeId id ;

Body * body = unit_create_body(&ctx->unit,owner,&id) ;

body->value = parse_expression(ctx,0) ;
return id;
}

void  parse_variable_decl(ParsingContext *  ctx, Item *  item) {
Token keyword = consume(ctx) ;

if ((keyword.kind== _TokenKind_Val)){
item->kind = _ItemKind_Const;
}
else {
if ((keyword.kind== _TokenKind_Var)){
item->kind = _ItemKind_Variable;
}
else {
abort() ;
}
;
}
;
item->ident = parse_identifier(ctx) ;
expect(ctx,_TokenKind_Colon) ;
item->node.variable.ty = parse_type(ctx) ;
if (accept(ctx,_TokenKind_Equal) ){
item->node.variable.body = parse_body(ctx,item->id) ;
}
else {
item->node.variable.body.owner = null;
}
;
}

void  parse_compound_decl(ParsingContext *  ctx, Item *  item) {
if (accept(ctx,_TokenKind_Struct) ){
item->kind = _ItemKind_Struct;
}
else {
if (accept(ctx,_TokenKind_Union) ){
item->kind = _ItemKind_Union;
}
else {
abort() ;
}
;
}
;
item->ident = parse_identifier(ctx) ;
expect(ctx,_TokenKind_LeftCurly) ;
item->node.compound.fields = malloc((sizeof(CompoundField) * 16)) ;
item->node.compound.num_fields = 0;
while ( !accept(ctx,_TokenKind_RightCurly) )
{
Token token = consume(ctx) ;

if ((token.kind!= _TokenKind_Identifier)){
emit_error(ctx->source_map,token.span,"Expected field identifier") ;
}
;
item->node.compound.fields[item->node.compound.num_fields].ident.name = token.lexeme;
expect(ctx,_TokenKind_Colon) ;
Type * type = parse_type(ctx) ;

item->node.compound.fields[item->node.compound.num_fields].ty = type;
item->node.compound.num_fields = (item->node.compound.num_fields+ 1);
expect(ctx,_TokenKind_Comma) ;
}
}

void  parse_enum_decl(ParsingContext *  ctx, Item *  item) {
expect(ctx,_TokenKind_Enum) ;
item->kind = _ItemKind_Enum;
item->ident = parse_identifier(ctx) ;
expect(ctx,_TokenKind_LeftCurly) ;
item->node._enum.variants = malloc((sizeof(EnumVariant) * 128)) ;
item->node._enum.num_variants = 0;
while ( !accept(ctx,_TokenKind_RightCurly) )
{
item->node._enum.variants[item->node._enum.num_variants].ident = parse_identifier(ctx) ;
item->node._enum.num_variants = (item->node._enum.num_variants+ 1);
expect(ctx,_TokenKind_Comma) ;
}
}

FunctionHeader  parse_function_header(ParsingContext *  ctx) {
FunctionHeader header ;

header.parameters = malloc((sizeof(FunctionParameter) * 16)) ;
header.num_parameters = 0;
expect(ctx,_TokenKind_LeftParen) ;
while ( !accept(ctx,_TokenKind_RightParen) )
{
header.parameters[header.num_parameters].ident = parse_identifier(ctx) ;
expect(ctx,_TokenKind_Colon) ;
Type * type = parse_type(ctx) ;

header.parameters[header.num_parameters].ty = type;
header.num_parameters = (header.num_parameters+ 1);
accept(ctx,_TokenKind_Comma) ;
}
if (accept(ctx,_TokenKind_Arrow) ){
header.output = parse_type(ctx) ;
}
else {
Type * output = malloc(sizeof(Type) ) ;

output->kind = _TypeKind_Unit;
header.output = output;
}
;
return header;
}

void  parse_function_decl(ParsingContext *  ctx, Item *  item) {
expect(ctx,_TokenKind_Fn) ;
item->ident = parse_identifier(ctx) ;
item->kind = _ItemKind_Function;
item->node.function.header = parse_function_header(ctx) ;
if ((look_ahead(ctx,0) .kind== _TokenKind_LeftCurly)){
item->node.function.body = parse_body(ctx,item->id) ;
}
else {
item->node.function.body.owner = null;
}
;
}

NodeId  parse_item(ParsingContext *  ctx) {
Token tok = look_ahead(ctx,0) ;

NodeId id ;

Item * item = unit_create_item(&ctx->unit,&id) ;

item->span.from = span_start(ctx) ;
if ((tok.kind== _TokenKind_Fn)){
parse_function_decl(ctx,item) ;
}
else {
if (((tok.kind== _TokenKind_Struct)|| (tok.kind== _TokenKind_Union))){
parse_compound_decl(ctx,item) ;
}
else {
if ((tok.kind== _TokenKind_Enum)){
parse_enum_decl(ctx,item) ;
}
else {
if (((tok.kind== _TokenKind_Var)|| (tok.kind== _TokenKind_Val))){
parse_variable_decl(ctx,item) ;
}
else {
emit_error(ctx->source_map,tok.span,"Unexpected token on top-level") ;
}
;
}
;
}
;
}
;
accept(ctx,_TokenKind_Semicolon) ;
item->span.to = span_end(ctx) ;
return id;
}

void  parse_mod_inner(ParsingContext *  ctx, Mod *  module) {
while ( (!accept(ctx,_TokenKind_RightCurly) && !is_done_parsing(ctx) ))
{
module->items[module->num_items] = parse_item(ctx) ;
module->num_items = (module->num_items+ 1);
}
}

CompilationUnit  parse(Session *  sess, Token *  tokens, u32  num_tokens) {
ParsingContext ctx ;

ctx.current_token = 0;
ctx.tokens = tokens;
ctx.num_tokens = num_tokens;
ctx.source_map = &sess->source;
ctx.sess = sess;
ctx.unit.body_map = intmap_create(2048) ;
ctx.unit.bodies = malloc((sizeof(Body) * 2048)) ;
ctx.unit.num_bodies = 1;
ctx.unit.item_map = intmap_create(2048) ;
ctx.unit.items = malloc((sizeof(Item) * 2048)) ;
ctx.unit.num_items = 1;
ctx.unit.module.items = malloc((sizeof(NodeId) * 2048)) ;
ctx.unit.module.num_items = 0;
ctx.unit.module.span.from = span_start(&ctx) ;
parse_mod_inner(&ctx,&ctx.unit.module) ;
ctx.unit.module.span.to = span_end(&ctx) ;
return ctx.unit;
}

