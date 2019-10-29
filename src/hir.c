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

typedef struct Expr Expr;

typedef struct Block Block;

typedef struct HirId HirId;
typedef struct HirId {
  u32 owner;
  u32 local;
} HirId;

typedef struct Ident Ident;
typedef struct Ident {
  char *name;
} Ident;

typedef struct Path Path;
typedef struct Path {
  char **segments;
  u32 num_segments;
} Path;

typedef enum TypeKind {
  _TypeKind_Unit,
  _TypeKind_Ptr,
  _TypeKind_Path,
} TypeKind;

typedef union TypeKindNode TypeKindNode;
typedef union TypeKindNode {
  char *path;
  Type *ptr;
} TypeKindNode;

typedef struct Type Type;
typedef struct Type {
  HirId id;
  TypeKind kind;
  TypeKindNode node;
} Type;

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
  HirId id;
  Type *ty;
} CompoundField;

typedef struct CompoundData CompoundData;
typedef struct CompoundData {
  CompoundField *fields;
  u32 num_fields;
} CompoundData;

typedef struct EnumVariant EnumVariant;
typedef struct EnumVariant {
  Ident ident;
  HirId id;
} EnumVariant;

typedef struct EnumData EnumData;
typedef struct EnumData {
  EnumVariant *variants;
  u32 num_variants;
} EnumData;

typedef struct FunctionParameter FunctionParameter;
typedef struct FunctionParameter {
  Ident name;
  Type *ty;
} FunctionParameter;

typedef struct FunctionData FunctionData;
typedef struct FunctionData {
  FunctionParameter *parameters;
  u32 num_parameters;
  Type *output;
  Block *body;
} FunctionData;

typedef struct VariableData VariableData;
typedef struct VariableData {
  Type *ty;
  bool mutable;
  Expr *body;
} VariableData;

typedef enum ItemKind {
  _ItemKind_Const,
  _ItemKind_Enum,
  _ItemKind_Function,
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
} ItemKindNode;

typedef struct Item Item;
typedef struct Item {
  Ident ident;
  HirId id;
  ItemKind kind;
  ItemKindNode node;
  Visibility vis;
} Item;

typedef struct BinaryData BinaryData;
typedef struct BinaryData {
  BinaryOperatorKind op;
  Expr *left;
  Expr *right;
} BinaryData;

typedef struct CallData CallData;
typedef struct CallData {
  Expr *func;
  Expr **args;
  u32 num_args;
} CallData;

typedef struct ConditionalData ConditionalData;
typedef struct ConditionalData {
  Expr *condition;
  Block *then;
  Block *otherwise;
} ConditionalData;

typedef struct IndexingData IndexingData;
typedef struct IndexingData {
  Expr *array;
  Expr *index;
} IndexingData;

typedef struct FieldData FieldData;
typedef struct FieldData {
  Expr *strct;
  Ident ident;
} FieldData;

typedef struct UnaryData UnaryData;
typedef struct UnaryData {
  UnaryOperatorKind op;
  Expr *inner;
} UnaryData;

typedef enum ExprKind {
  _ExprKind_Binary,
  _ExprKind_Block,
  _ExprKind_Call,
  _ExprKind_Conditional,
  _ExprKind_Field,
  _ExprKind_Indexing,
  _ExprKind_Identifier,
  _ExprKind_Path,
  _ExprKind_Literal,
  _ExprKind_Unary,
} ExprKind;

typedef union ExprKindNode ExprKindNode;
typedef union ExprKindNode {
  BinaryData binary;
  Block *block;
  CallData call;
  ConditionalData conditional;
  FieldData field;
  IndexingData indexing;
  Ident ident;
  Path path;
  Literal lit;
  UnaryData unary;
} ExprKindNode;

typedef struct Expr Expr;
typedef struct Expr {
  HirId id;
  ExprKind kind;
  ExprKindNode node;
} Expr;

typedef struct AssignmentData AssignmentData;
typedef struct AssignmentData {
  Expr *left;
  Expr *right;
} AssignmentData;

typedef struct WhileData WhileData;
typedef struct WhileData {
  Expr *condition;
  Block *body;
} WhileData;

typedef enum StmtKind {
  _StmtKind_Assignment,
  _StmtKind_Item,
  _StmtKind_Expr,
  _StmtKind_Return,
  _StmtKind_Break,
  _StmtKind_Continue,
  _StmtKind_Defer,
  _StmtKind_While,
  _StmtKind_Empty,
} StmtKind;

typedef union StmtKindNode StmtKindNode;
typedef union StmtKindNode {
  AssignmentData assignment;
  Item *item;
  Expr *expr;
  WhileData _while;
  Expr *_return;
  Expr *_defer;
} StmtKindNode;

typedef struct Stmt Stmt;
typedef struct Stmt {
  StmtKind kind;
  StmtKindNode node;
} Stmt;

typedef struct Block Block;
typedef struct Block {
  Stmt **stmts;
  u32 num_stmts;
  HirId id;
} Block;
