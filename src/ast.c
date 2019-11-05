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
  Ident *segments;
  u32 num_segments;
  Res res;
} Path;

typedef struct Mod Mod;
#line 34 "src/ast.z"
typedef struct Mod {
  Span span;
  NodeId *items;
  u32 num_items;
} Mod;

#line 40 "src/ast.z"
typedef enum TypeKind {
  TypeKind_Unit,
  TypeKind_Ptr,
  TypeKind_Path,
} TypeKind;

typedef struct GenericParam GenericParam;
#line 46 "src/ast.z"
typedef struct GenericParam {
  NodeId id;
  Ident ident;
} GenericParam;

typedef struct Generics Generics;
#line 51 "src/ast.z"
typedef struct Generics {
  GenericParam *parameters;
  u32 num_parameters;
  Span span;
} Generics;

typedef union TypeKindNode TypeKindNode;
#line 57 "src/ast.z"
typedef union TypeKindNode {
  Sid path;
  Type *ptr;
} TypeKindNode;

typedef struct Type Type;
#line 62 "src/ast.z"
typedef struct Type {
  NodeId id;
  TypeKind kind;
  TypeKindNode node;
} Type;

#line 68 "src/ast.z"
typedef enum LiteralKind {
  LiteralKind_Int,
  LiteralKind_Float,
  LiteralKind_Bool,
  LiteralKind_Char,
  LiteralKind_Str,
} LiteralKind;

typedef union LiteralValue LiteralValue;
#line 76 "src/ast.z"
typedef union LiteralValue {
  f64 floating;
  u64 integer;
  bool boolean;
  char ch;
  Sid str;
} LiteralValue;

typedef struct Literal Literal;
#line 84 "src/ast.z"
typedef struct Literal {
  LiteralKind kind;
  LiteralValue value;
} Literal;

#line 90 "src/ast.z"
typedef enum UnaryOperatorKind {
  UnaryOperatorKind_Deref,
  UnaryOperatorKind_Refer,
  UnaryOperatorKind_Negation,
  UnaryOperatorKind_Complement,
} UnaryOperatorKind;

#line 101 "src/ast.z"
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
#line 130 "src/ast.z"
typedef struct BinaryData {
  BinaryOperatorKind op;
  Expr *left;
  Expr *right;
} BinaryData;

typedef struct CallData CallData;
#line 136 "src/ast.z"
typedef struct CallData {
  Expr *func;
  Expr **args;
  u32 num_args;
} CallData;

typedef struct ConditionalData ConditionalData;
#line 142 "src/ast.z"
typedef struct ConditionalData {
  Expr *condition;
  Expr *then;
  Expr *otherwise;
} ConditionalData;

typedef struct WhileData WhileData;
#line 148 "src/ast.z"
typedef struct WhileData {
  Expr *condition;
  Expr *body;
} WhileData;

typedef struct IndexingData IndexingData;
#line 153 "src/ast.z"
typedef struct IndexingData {
  Expr *array;
  Expr *index;
} IndexingData;

typedef struct FieldData FieldData;
#line 158 "src/ast.z"
typedef struct FieldData {
  Expr *strct;
  Ident ident;
} FieldData;

typedef struct UnaryData UnaryData;
#line 163 "src/ast.z"
typedef struct UnaryData {
  UnaryOperatorKind op;
  Expr *inner;
} UnaryData;

#line 168 "src/ast.z"
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
#line 181 "src/ast.z"
typedef union ExprKindNode {
  BinaryData binary;
  Block *block;
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
#line 194 "src/ast.z"
typedef struct Expr {
  NodeId id;
  Span span;
  ExprKind kind;
  ExprKindNode node;
} Expr;

typedef struct AssignmentData AssignmentData;
#line 201 "src/ast.z"
typedef struct AssignmentData {
  Expr *left;
  Expr *right;
} AssignmentData;

#line 206 "src/ast.z"
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
#line 217 "src/ast.z"
typedef union StmtKindNode {
  AssignmentData assignment;
  NodeId item;
  Expr *expr;
  Expr *_return;
  Expr *_defer;
} StmtKindNode;

typedef struct Stmt Stmt;
#line 225 "src/ast.z"
typedef struct Stmt {
  StmtKind kind;
  StmtKindNode node;
  Span span;
} Stmt;

typedef struct Block Block;
#line 231 "src/ast.z"
typedef struct Block {
  Stmt **stmts;
  u32 num_stmts;
  NodeId id;
  Span span;
} Block;

typedef struct Body Body;
#line 238 "src/ast.z"
typedef struct Body {
  Expr *value;
} Body;

#line 242 "src/ast.z"
typedef enum VisibilityKind {
  VisibilityKind_Public,
  VisibilityKind_Private,
} VisibilityKind;

typedef struct Visibility Visibility;
#line 247 "src/ast.z"
typedef struct Visibility {
  VisibilityKind kind;
} Visibility;

typedef struct CompoundField CompoundField;
#line 251 "src/ast.z"
typedef struct CompoundField {
  Ident ident;
  NodeId id;
  Type *ty;
} CompoundField;

typedef struct CompoundData CompoundData;
#line 257 "src/ast.z"
typedef struct CompoundData {
  CompoundField *fields;
  u32 num_fields;
  Generics generics;
} CompoundData;

typedef struct EnumVariant EnumVariant;
#line 263 "src/ast.z"
typedef struct EnumVariant {
  Ident ident;
  NodeId id;
} EnumVariant;

typedef struct EnumData EnumData;
#line 268 "src/ast.z"
typedef struct EnumData {
  EnumVariant *variants;
  u32 num_variants;
} EnumData;

typedef struct FunctionParameter FunctionParameter;
#line 273 "src/ast.z"
typedef struct FunctionParameter {
  Ident ident;
  NodeId id;
  Type *ty;
} FunctionParameter;

typedef struct FunctionHeader FunctionHeader;
#line 280 "src/ast.z"
typedef struct FunctionHeader {
  FunctionParameter *parameters;
  u32 num_parameters;
  Type *output;
  Generics generics;
} FunctionHeader;

typedef struct FunctionData FunctionData;
#line 287 "src/ast.z"
typedef struct FunctionData {
  FunctionHeader header;
  NodeId body;
} FunctionData;

typedef struct UseData UseData;
#line 292 "src/ast.z"
typedef struct UseData {
  Path path;
} UseData;

typedef struct VariableData VariableData;
#line 296 "src/ast.z"
typedef struct VariableData {
  Type *ty;
  bool mutable;
  NodeId body;
} VariableData;

#line 302 "src/ast.z"
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
#line 313 "src/ast.z"
typedef union ItemKindNode {
  CompoundData compound;
  EnumData _enum;
  VariableData variable;
  FunctionData function;
  Mod module;
  UseData _use;
} ItemKindNode;

typedef struct Item Item;
#line 322 "src/ast.z"
typedef struct Item {
  Ident ident;
  NodeId id;
  ItemKind kind;
  ItemKindNode node;
  Visibility vis;
  Span span;
} Item;

typedef struct CompilationUnit CompilationUnit;
#line 331 "src/ast.z"
typedef struct CompilationUnit {
  IntMap *body_map;
  Body *bodies;
  u32 num_bodies;
  IntMap *item_map;
  Item *items;
  u32 num_items;
  Mod module;
} CompilationUnit;

#line 343 "src/ast.z"
Body *unit_create_body(CompilationUnit *unit, NodeId owner_item, NodeId *id) {
#line 345 "src/ast.z"
#line 345 "src/ast.z"
  u32 idx = unit->num_bodies;

#line 346 "src/ast.z"
#line 346 "src/ast.z"
  Body *body = &unit->bodies[idx];

#line 347 "src/ast.z"
  unit->num_bodies = (unit->num_bodies + 1);
#line 349 "src/ast.z"
#line 349 "src/ast.z"
  u64 owner = owner_item.owner;

#line 350 "src/ast.z"
#line 350 "src/ast.z"
  u64 local = 1;

#line 351 "src/ast.z"
#line 351 "src/ast.z"
  u64 key = ((owner << 32) | local);

#line 352 "src/ast.z"
  intmap_insert(unit->body_map, key, idx);
#line 354 "src/ast.z"
  id->owner = owner;
#line 355 "src/ast.z"
  id->local = local;
#line 357 "src/ast.z"
  return body;
}

#line 360 "src/ast.z"
Body unit_get_body(CompilationUnit *unit, NodeId id) {
#line 361 "src/ast.z"
#line 361 "src/ast.z"
  u64 owner = id.owner;

#line 362 "src/ast.z"
#line 362 "src/ast.z"
  u64 key = ((owner << 32) | id.local);

#line 363 "src/ast.z"
#line 363 "src/ast.z"
  u32 idx = intmap_lookup(unit->body_map, key);

#line 364 "src/ast.z"
  return unit->bodies[idx];
}

#line 367 "src/ast.z"
Item *unit_create_item(CompilationUnit *unit, NodeId *id) {
#line 369 "src/ast.z"
#line 369 "src/ast.z"
  u32 idx = unit->num_items;

#line 370 "src/ast.z"
#line 370 "src/ast.z"
  Item *item = &unit->items[idx];

#line 371 "src/ast.z"
  unit->num_items = (unit->num_items + 1);
#line 373 "src/ast.z"
#line 373 "src/ast.z"
  u64 owner = idx;

#line 374 "src/ast.z"
#line 374 "src/ast.z"
  u64 local = 0;

#line 375 "src/ast.z"
#line 375 "src/ast.z"
  u64 key = ((owner << 32) | local);

#line 376 "src/ast.z"
  intmap_insert(unit->item_map, key, idx);
#line 378 "src/ast.z"
  id->owner = owner;
#line 379 "src/ast.z"
  id->local = local;
#line 380 "src/ast.z"
  item->id = *id;
#line 382 "src/ast.z"
  return item;
}

#line 385 "src/ast.z"
Item *unit_get_item(CompilationUnit *unit, NodeId id) {
#line 386 "src/ast.z"
#line 386 "src/ast.z"
  u64 owner = id.owner;

#line 387 "src/ast.z"
#line 387 "src/ast.z"
  u64 key = ((owner << 32) | id.local);

#line 388 "src/ast.z"
#line 388 "src/ast.z"
  u32 idx = intmap_lookup(unit->item_map, key);

#line 389 "src/ast.z"
  return &unit->items[idx];
}
