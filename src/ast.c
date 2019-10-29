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
typedef struct AstType AstType;

typedef struct AstExpr AstExpr;

typedef struct AstStmt AstStmt;

typedef struct AstItem AstItem;

typedef struct AstBlock AstBlock;

typedef struct AstPath AstPath;
typedef struct AstPath {
  char **segments;
  u32 num_segments;
} AstPath;

typedef enum AstTypeKind {
  _AstTypeKind_Unit,
  _AstTypeKind_Ptr,
  _AstTypeKind_Path,
} AstTypeKind;

typedef union AstTypeNode AstTypeNode;
typedef union AstTypeNode {
  char *path;
  AstType *ptr;
} AstTypeNode;

typedef struct AstType AstType;
typedef struct AstType {
  AstTypeKind kind;
  AstTypeNode node;
} AstType;

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
  char *str;
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

typedef struct BinaryAstExpr BinaryAstExpr;
typedef struct BinaryAstExpr {
  BinaryOperatorKind operator;
  AstExpr *left;
  AstExpr *right;
} BinaryAstExpr;

typedef struct CastAstExpr CastAstExpr;
typedef struct CastAstExpr {
  AstType *target_type;
  AstExpr *inner;
} CastAstExpr;

typedef struct CallAstExpr CallAstExpr;
typedef struct CallAstExpr {
  AstExpr *func;
  AstExpr **args;
  u32 num_args;
} CallAstExpr;

typedef struct ConditionalAstExpr ConditionalAstExpr;
typedef struct ConditionalAstExpr {
  AstExpr *condition;
  AstBlock *then;
  AstBlock *otherwise;
} ConditionalAstExpr;

typedef struct IndexingAstExpr IndexingAstExpr;
typedef struct IndexingAstExpr {
  AstExpr *array;
  AstExpr *index;
} IndexingAstExpr;

typedef struct FieldAstExpr FieldAstExpr;
typedef struct FieldAstExpr {
  AstExpr *strct;
  char *field_name;
} FieldAstExpr;

typedef struct UnaryAstExpr UnaryAstExpr;
typedef struct UnaryAstExpr {
  UnaryOperatorKind operator;
  AstExpr *inner;
} UnaryAstExpr;

typedef union AstExprNode AstExprNode;
typedef union AstExprNode {
  BinaryAstExpr binary;
  CastAstExpr _cast;
  CallAstExpr call;
  char *identifier;
  ConditionalAstExpr conditional;
  IndexingAstExpr index;
  Literal literal;
  FieldAstExpr field;
  UnaryAstExpr unary;
  AstPath path;
} AstExprNode;

typedef enum AstExprKind {
  _AstExprKind_Binary,
  _AstExprKind_Cast,
  _AstExprKind_Call,
  _AstExprKind_Identifier,
  _AstExprKind_Conditional,
  _AstExprKind_Indexing,
  _AstExprKind_Literal,
  _AstExprKind_Field,
  _AstExprKind_Unary,
  _AstExprKind_Path,
} AstExprKind;

typedef struct AstExpr AstExpr;
typedef struct AstExpr {
  AstExprKind kind;
  AstExprNode node;
} AstExpr;

typedef struct AssignmentAstStmt AssignmentAstStmt;
typedef struct AssignmentAstStmt {
  AstExpr *left;
  AstExpr *right;
} AssignmentAstStmt;

typedef struct WhileAstStmt WhileAstStmt;
typedef struct WhileAstStmt {
  AstExpr *condition;
  AstBlock *body;
} WhileAstStmt;

typedef enum AstStmtKind {
  _AstStmtKind_Assignment,
  _AstStmtKind_Item,
  _AstStmtKind_Expr,
  _AstStmtKind_Return,
  _AstStmtKind_Break,
  _AstStmtKind_Continue,
  _AstStmtKind_Defer,
  _AstStmtKind_While,
  _AstStmtKind_Empty,
} AstStmtKind;

typedef union AstStmtNode AstStmtNode;
typedef union AstStmtNode {
  AssignmentAstStmt assignment;
  AstItem *item;
  AstExpr *expr;
  AstExpr *_return;
  AstExpr *_defer;
  WhileAstStmt _while;
} AstStmtNode;

typedef struct AstStmt AstStmt;
typedef struct AstStmt {
  AstStmtKind kind;
  AstStmtNode node;
} AstStmt;

typedef struct AstBlock AstBlock;
typedef struct AstBlock {
  AstStmt **stmts;
  u32 num_stmts;
} AstBlock;

typedef struct CompoundTypeDecl CompoundTypeDecl;
typedef struct CompoundTypeDecl {
  char **field_names;
  AstType **field_types;
  u32 num_fields;
} CompoundTypeDecl;

typedef struct EnumDecl EnumDecl;
typedef struct EnumDecl {
  char **field_names;
  u32 num_fields;
} EnumDecl;

typedef struct FunctionSignature FunctionSignature;
typedef struct FunctionSignature {
  AstType **parameter_types;
  char **parameter_names;
  u32 num_parameters;
  AstType *output_type;
} FunctionSignature;

typedef struct FunctionDecl FunctionDecl;
typedef struct FunctionDecl {
  FunctionSignature signature;
  AstBlock *block;
} FunctionDecl;

typedef struct VariableDecl VariableDecl;
typedef struct VariableDecl {
  AstType *type;
  AstExpr *value;
} VariableDecl;

typedef enum AstItemKind {
  _AstItemKind_Const,
  _AstItemKind_Enum,
  _AstItemKind_Function,
  _AstItemKind_Struct,
  _AstItemKind_Union,
  _AstItemKind_Variable,
} AstItemKind;

typedef union AstItemNode AstItemNode;
typedef union AstItemNode {
  FunctionDecl function;
  VariableDecl variable;
  CompoundTypeDecl compound_type;
  EnumDecl _enum;
} AstItemNode;

typedef struct AstItem AstItem;
typedef struct AstItem {
  char *name;
  AstItemKind kind;
  AstItemNode node;
} AstItem;
