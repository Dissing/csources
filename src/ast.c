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
typedef struct Type Type;

typedef struct Expr Expr;

typedef struct Block Block;

typedef struct NodeId NodeId;
typedef struct NodeId {
u32 owner;
u32 local;
} NodeId;


typedef struct Ident Ident;
typedef struct Ident {
Sid name;
} Ident;


typedef enum ResKind {
_ResKind_Definition,
} ResKind;


typedef union ResNode ResNode;
typedef union ResNode {
NodeId def;
} ResNode;


typedef struct Res Res;
typedef struct Res {
ResKind kind;
ResNode node;
} Res;


typedef struct Path Path;
typedef struct Path {
Ident * segments;
u32 num_segments;
Res res;
} Path;


typedef struct Mod Mod;
typedef struct Mod {
Span span;
NodeId * items;
u32 num_items;
} Mod;


typedef enum TypeKind {
_TypeKind_Unit,
_TypeKind_Ptr,
_TypeKind_Path,
} TypeKind;


typedef union TypeKindNode TypeKindNode;
typedef union TypeKindNode {
Sid path;
Type * ptr;
} TypeKindNode;


typedef struct Type Type;
typedef struct Type {
NodeId id;
TypeKind kind;
TypeKindNode node;
} Type;


typedef enum LiteralKind {
_LiteralKind_Int,
_LiteralKind_Float,
_LiteralKind_Bool,
_LiteralKind_Char,
_LiteralKind_Str,
} LiteralKind;


typedef union LiteralValue LiteralValue;
typedef union LiteralValue {
f64 floating;
u64 integer;
bool boolean;
char ch;
Sid str;
} LiteralValue;


typedef struct Literal Literal;
typedef struct Literal {
LiteralKind kind;
LiteralValue value;
} Literal;


typedef enum UnaryOperatorKind {
_UnaryOperatorKind_Deref,
_UnaryOperatorKind_Refer,
_UnaryOperatorKind_Negation,
_UnaryOperatorKind_Complement,
} UnaryOperatorKind;


typedef enum BinaryOperatorKind {
_BinaryOperatorKind_Invalid,
_BinaryOperatorKind_Addition,
_BinaryOperatorKind_Subtraction,
_BinaryOperatorKind_Product,
_BinaryOperatorKind_Division,
_BinaryOperatorKind_Modulus,
_BinaryOperatorKind_Less,
_BinaryOperatorKind_LessEq,
_BinaryOperatorKind_Greater,
_BinaryOperatorKind_GreaterEq,
_BinaryOperatorKind_Equality,
_BinaryOperatorKind_NotEq,
_BinaryOperatorKind_BAnd,
_BinaryOperatorKind_BOr,
_BinaryOperatorKind_Xor,
_BinaryOperatorKind_LeftShift,
_BinaryOperatorKind_RightShift,
_BinaryOperatorKind_And,
_BinaryOperatorKind_Or,
} BinaryOperatorKind;


typedef struct BinaryData BinaryData;
typedef struct BinaryData {
BinaryOperatorKind op;
Expr * left;
Expr * right;
} BinaryData;


typedef struct CallData CallData;
typedef struct CallData {
Expr * func;
Expr * * args;
u32 num_args;
} CallData;


typedef struct ConditionalData ConditionalData;
typedef struct ConditionalData {
Expr * condition;
Expr * then;
Expr * otherwise;
} ConditionalData;


typedef struct WhileData WhileData;
typedef struct WhileData {
Expr * condition;
Expr * body;
} WhileData;


typedef struct IndexingData IndexingData;
typedef struct IndexingData {
Expr * array;
Expr * index;
} IndexingData;


typedef struct FieldData FieldData;
typedef struct FieldData {
Expr * strct;
Ident ident;
} FieldData;


typedef struct UnaryData UnaryData;
typedef struct UnaryData {
UnaryOperatorKind op;
Expr * inner;
} UnaryData;


typedef enum ExprKind {
_ExprKind_Binary,
_ExprKind_Block,
_ExprKind_Call,
_ExprKind_Conditional,
_ExprKind_Field,
_ExprKind_Indexing,
_ExprKind_Path,
_ExprKind_Literal,
_ExprKind_Unary,
_ExprKind_While,
} ExprKind;


typedef union ExprKindNode ExprKindNode;
typedef union ExprKindNode {
BinaryData binary;
Block * block;
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
typedef struct Expr {
NodeId id;
Span span;
ExprKind kind;
ExprKindNode node;
} Expr;


typedef struct AssignmentData AssignmentData;
typedef struct AssignmentData {
Expr * left;
Expr * right;
} AssignmentData;


typedef enum StmtKind {
_StmtKind_Assignment,
_StmtKind_Item,
_StmtKind_Expr,
_StmtKind_Return,
_StmtKind_Break,
_StmtKind_Continue,
_StmtKind_Defer,
_StmtKind_Empty,
} StmtKind;


typedef union StmtKindNode StmtKindNode;
typedef union StmtKindNode {
AssignmentData assignment;
NodeId item;
Expr * expr;
Expr * _return;
Expr * _defer;
} StmtKindNode;


typedef struct Stmt Stmt;
typedef struct Stmt {
StmtKind kind;
StmtKindNode node;
Span span;
} Stmt;


typedef struct Block Block;
typedef struct Block {
Stmt * * stmts;
u32 num_stmts;
NodeId id;
Span span;
} Block;


typedef struct Body Body;
typedef struct Body {
Expr * value;
} Body;


typedef enum VisibilityKind {
_VisibilityKind_Public,
_VisibilityKind_Private,
} VisibilityKind;


typedef struct Visibility Visibility;
typedef struct Visibility {
VisibilityKind kind;
} Visibility;


typedef struct CompoundField CompoundField;
typedef struct CompoundField {
Ident ident;
NodeId id;
Type * ty;
} CompoundField;


typedef struct CompoundData CompoundData;
typedef struct CompoundData {
CompoundField * fields;
u32 num_fields;
} CompoundData;


typedef struct EnumVariant EnumVariant;
typedef struct EnumVariant {
Ident ident;
NodeId id;
} EnumVariant;


typedef struct EnumData EnumData;
typedef struct EnumData {
EnumVariant * variants;
u32 num_variants;
} EnumData;


typedef struct FunctionParameter FunctionParameter;
typedef struct FunctionParameter {
Ident ident;
NodeId id;
Type * ty;
} FunctionParameter;


typedef struct FunctionHeader FunctionHeader;
typedef struct FunctionHeader {
FunctionParameter * parameters;
u32 num_parameters;
Type * output;
} FunctionHeader;


typedef struct FunctionData FunctionData;
typedef struct FunctionData {
FunctionHeader header;
NodeId body;
} FunctionData;


typedef struct VariableData VariableData;
typedef struct VariableData {
Type * ty;
bool mutable;
NodeId body;
} VariableData;


typedef enum ItemKind {
_ItemKind_Const,
_ItemKind_Enum,
_ItemKind_Function,
_ItemKind_Mod,
_ItemKind_Struct,
_ItemKind_Union,
_ItemKind_Variable,
} ItemKind;


typedef union ItemKindNode ItemKindNode;
typedef union ItemKindNode {
CompoundData compound;
EnumData _enum;
VariableData variable;
FunctionData function;
Mod module;
} ItemKindNode;


typedef struct Item Item;
typedef struct Item {
Ident ident;
NodeId id;
ItemKind kind;
ItemKindNode node;
Visibility vis;
Span span;
} Item;


typedef struct CompilationUnit CompilationUnit;
typedef struct CompilationUnit {
IntMap * body_map;
Body * bodies;
u32 num_bodies;
IntMap * item_map;
Item * items;
u32 num_items;
Mod module;
} CompilationUnit;


Body *  unit_create_body(CompilationUnit *  unit, NodeId  owner_item, NodeId *  id) {
u32 idx = unit->num_bodies;

Body * body = &unit->bodies[idx];

unit->num_bodies = (unit->num_bodies+ 1);
u64 owner = owner_item.owner;

u64 local = 1;

u64 key = ((owner<< 32)| local);

intmap_insert(unit->body_map,key,idx) ;
id->owner = owner;
id->local = local;
return body;
}

Body  unit_get_body(CompilationUnit *  unit, NodeId  id) {
u64 owner = id.owner;

u64 key = ((owner<< 32)| id.local);

u32 idx = intmap_lookup(unit->body_map,key) ;

return unit->bodies[idx];
}

Item *  unit_create_item(CompilationUnit *  unit, NodeId *  id) {
u32 idx = unit->num_items;

Item * item = &unit->items[idx];

unit->num_items = (unit->num_items+ 1);
u64 owner = idx;

u64 local = 0;

u64 key = ((owner<< 32)| local);

intmap_insert(unit->item_map,key,idx) ;
id->owner = owner;
id->local = local;
item->id = *id;
return item;
}

Item *  unit_get_item(CompilationUnit *  unit, NodeId  id) {
u64 owner = id.owner;

u64 key = ((owner<< 32)| id.local);

u32 idx = intmap_lookup(unit->item_map,key) ;

return &unit->items[idx];
}

