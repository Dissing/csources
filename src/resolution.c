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
typedef struct Scope Scope;
typedef struct Scope {
IntMap * symbols;
u32 current_owner;
u32 next_local;
} Scope;


typedef struct ResolutionContext ResolutionContext;
typedef struct ResolutionContext {
Scope * scope_stack;
u32 stack_top;
CompilationUnit * unit;
SourceMap * source_map;
Interner * interner;
} ResolutionContext;


u64  encode_id(NodeId  id) {
u64 owner = id.owner;

u64 v = ((owner<< 32)| id.local);

return v;
}

NodeId  decode_id(u64  v) {
NodeId id ;

id.owner = (v>> 32);
id.local = v;
return id;
}

void  push_ident(ResolutionContext *  ctx, Ident  ident, NodeId  id) {
intmap_insert(ctx->scope_stack[ctx->stack_top].symbols,ident.name.x,encode_id(id) ) ;
}

bool  lookup_ident(ResolutionContext *  ctx, Ident  ident, NodeId *  id) {
i32 i = ctx->stack_top;

while ( (i>= 0))
{
u64 v = intmap_lookup(ctx->scope_stack[i].symbols,ident.name.x) ;

if ((v> 0)){
*id = decode_id(v) ;
return true;
}
;
i = (i- 1);
}
return false;
}

void  push_scope(ResolutionContext *  ctx) {
ctx->stack_top = (ctx->stack_top+ 1);
ctx->scope_stack[ctx->stack_top].current_owner = ctx->scope_stack[(ctx->stack_top- 1)].current_owner;
ctx->scope_stack[ctx->stack_top].next_local = 2;
}

void  pop_scope(ResolutionContext *  ctx) {
intmap_reset(ctx->scope_stack[ctx->stack_top].symbols) ;
ctx->stack_top = (ctx->stack_top- 1);
}

void  scan_item(ResolutionContext *  ctx, Item *  item) {
push_ident(ctx,item->ident,item->id) ;
}

void  resolve_path(ResolutionContext *  ctx, Path *  path) {
NodeId id ;

if (lookup_ident(ctx,path->segments[0],&id) ){
path->res.kind = _ResKind_Definition;
path->res.node.def = id;
}
else {
printf("Failed to resolve %s\n",get_str(ctx->interner,path->segments[0].name) ) ;
}
;
}

void  resolve_expr(ResolutionContext *  ctx, Expr *  expr) ;

void  resolve_block(ResolutionContext *  ctx, Block *  block) ;

void  resolve_stmt(ResolutionContext *  ctx, Stmt *  stmt) ;

void  resolve_item(ResolutionContext *  ctx, Item *  item) ;

void  resolve_unary(ResolutionContext *  ctx, UnaryData  unary) {
resolve_expr(ctx,unary.inner) ;
}

void  resolve_binary(ResolutionContext *  ctx, BinaryData  binary) {
resolve_expr(ctx,binary.left) ;
resolve_expr(ctx,binary.right) ;
}

void  resolve_call(ResolutionContext *  ctx, CallData  call) {
resolve_expr(ctx,call.func) ;
u32 i = 0;

while ( (i< call.num_args))
{
resolve_expr(ctx,call.args[i]) ;
i = (i+ 1);
}
}

void  resolve_conditional(ResolutionContext *  ctx, ConditionalData  cond) {
resolve_expr(ctx,cond.condition) ;
resolve_expr(ctx,cond.then) ;
if (cond.otherwise){
resolve_expr(ctx,cond.otherwise) ;
}
;
}

void  resolve_while(ResolutionContext *  ctx, WhileData  data) {
resolve_expr(ctx,data.condition) ;
resolve_expr(ctx,data.body) ;
}

void  resolve_indexing(ResolutionContext *  ctx, IndexingData  idx) {
resolve_expr(ctx,idx.array) ;
resolve_expr(ctx,idx.index) ;
}

void  resolve_field(ResolutionContext *  ctx, FieldData  field) {
resolve_expr(ctx,field.strct) ;
}

void  resolve_expr(ResolutionContext *  ctx, Expr *  expr) {
if ((expr->kind== _ExprKind_Unary)){
resolve_unary(ctx,expr->node.unary) ;
}
else {
if ((expr->kind== _ExprKind_Binary)){
resolve_binary(ctx,expr->node.binary) ;
}
else {
if ((expr->kind== _ExprKind_Block)){
resolve_block(ctx,expr->node.block) ;
}
else {
if ((expr->kind== _ExprKind_Call)){
resolve_call(ctx,expr->node.call) ;
}
else {
if ((expr->kind== _ExprKind_Conditional)){
resolve_conditional(ctx,expr->node.conditional) ;
}
else {
if ((expr->kind== _ExprKind_While)){
resolve_while(ctx,expr->node.whl) ;
}
else {
if ((expr->kind== _ExprKind_Indexing)){
resolve_indexing(ctx,expr->node.indexing) ;
}
else {
if ((expr->kind== _ExprKind_Field)){
resolve_field(ctx,expr->node.field) ;
}
else {
if ((expr->kind== _ExprKind_Path)){
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

void  resolve_assignment(ResolutionContext *  ctx, AssignmentData  assignment) {
resolve_expr(ctx,assignment.left) ;
resolve_expr(ctx,assignment.right) ;
}

void  resolve_stmt(ResolutionContext *  ctx, Stmt *  stmt) {
if ((stmt->kind== _StmtKind_Assignment)){
resolve_assignment(ctx,stmt->node.assignment) ;
}
else {
if ((stmt->kind== _StmtKind_Expr)){
resolve_expr(ctx,stmt->node.expr) ;
}
else {
if ((stmt->kind== _StmtKind_Item)){
resolve_item(ctx,unit_get_item(ctx->unit,stmt->node.item) ) ;
}
else {
if ((stmt->kind== _StmtKind_Return)){
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

void  resolve_block(ResolutionContext *  ctx, Block *  block) {
push_scope(ctx) ;
u32 i = 0;

while ( (i< block->num_stmts))
{
Stmt * stmt = block->stmts[i];

if ((stmt->kind== _StmtKind_Item)){
Item * item = unit_get_item(ctx->unit,stmt->node.item) ;

push_ident(ctx,item->ident,stmt->node.item) ;
}
;
i = (i+ 1);
}
i = 0;
while ( (i< block->num_stmts))
{
resolve_stmt(ctx,block->stmts[i]) ;
i = (i+ 1);
}
pop_scope(ctx) ;
}

void  resolve_body(ResolutionContext *  ctx, Body  body) {
resolve_expr(ctx,body.value) ;
}

void  resolve_function(ResolutionContext *  ctx, Item *  item) {
Scope * scope = &ctx->scope_stack[ctx->stack_top];

FunctionData func = item->node.function;

if (func.body.local){
scope->current_owner = item->id.owner;
push_scope(ctx) ;
u32 i = 0;

while ( (i< func.header.num_parameters))
{
FunctionParameter * param = &func.header.parameters[i];

param->id.owner = scope->current_owner;
param->id.local = scope->next_local;
scope->next_local = (scope->next_local+ 1);
push_ident(ctx,func.header.parameters[i].ident,param->id) ;
i = (i+ 1);
}
resolve_body(ctx,unit_get_body(ctx->unit,item->node.function.body) ) ;
pop_scope(ctx) ;
}
;
}

void  resolve_variable(ResolutionContext *  ctx, Item *  item) {
Scope * scope = &ctx->scope_stack[ctx->stack_top];

if (item->node.variable.body.local){
scope->current_owner = item->id.owner;
resolve_body(ctx,unit_get_body(ctx->unit,item->node.variable.body) ) ;
}
;
}

void  resolve_item(ResolutionContext *  ctx, Item *  item) {
if (((item->kind== _ItemKind_Const)|| (item->kind== _ItemKind_Variable))){
resolve_variable(ctx,item) ;
}
;
if ((item->kind== _ItemKind_Function)){
resolve_function(ctx,item) ;
}
;
}

void  resolve(Session *  sess, CompilationUnit *  unit) {
ResolutionContext ctx ;

ctx.interner = &sess->interner;
ctx.unit = unit;
ctx.scope_stack = malloc((sizeof(Scope) * 128)) ;
ctx.stack_top = 0;
u32 i = 0;

while ( (i< 128))
{
ctx.scope_stack[i].symbols = intmap_create(1024) ;
i = (i+ 1);
}
i = 0;
while ( (i< unit->module.num_items))
{
Item * item = unit_get_item(unit,unit->module.items[i]) ;

scan_item(&ctx,item) ;
i = (i+ 1);
}
i = 0;
while ( (i< unit->module.num_items))
{
Item * item = unit_get_item(unit,unit->module.items[i]) ;

resolve_item(&ctx,item) ;
i = (i+ 1);
}
}

