//Prelude
#include <stdint.h>
#include <stdbool.h>
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
typedef const char constchar;
typedef const void constvoid;
#line 18 "src/cstd.z"
typedef struct _ZN4cstd4FILEE _ZN4cstd4FILEE;

#line 4 "src/intmap.z"
typedef struct _ZN6intmap6IntMapE _ZN6intmap6IntMapE;

#line 4 "src/strmap.z"
typedef struct _ZN6strmap6StrMapE _ZN6strmap6StrMapE;

#line 3 "src/source_map.z"
typedef struct _ZN10source_map4SpanE _ZN10source_map4SpanE;

#line 8 "src/source_map.z"
typedef struct _ZN10source_map10SourceFileE _ZN10source_map10SourceFileE;

#line 18 "src/source_map.z"
typedef struct _ZN10source_map9SourceMapE _ZN10source_map9SourceMapE;

#line 4 "src/interning.z"
typedef struct _ZN9interning3SidE _ZN9interning3SidE;

#line 8 "src/interning.z"
typedef struct _ZN9interning8InternerE _ZN9interning8InternerE;

#line 5 "src/session.z"
typedef struct _ZN7session8SidBump1E _ZN7session8SidBump1E;

#line 7 "src/session.z"
typedef struct _ZN7session7SessionE _ZN7session7SessionE;

#line 5 "src/tokens.z"
typedef enum _ZN6tokens9TokenKindE {
TokenKind_Invalid,
TokenKind_Identifier,
TokenKind_EOF,
TokenKind_Break,
TokenKind_Cast,
TokenKind_Const,
TokenKind_Continue,
TokenKind_Defer,
TokenKind_Enum,
TokenKind_Else,
TokenKind_Extern,
TokenKind_Fn,
TokenKind_For,
TokenKind_If,
TokenKind_Mod,
TokenKind_Return,
TokenKind_Static,
TokenKind_Struct,
TokenKind_Sizeof,
TokenKind_Union,
TokenKind_Use,
TokenKind_Var,
TokenKind_Val,
TokenKind_While,
TokenKind_Plus,
TokenKind_Minus,
TokenKind_Star,
TokenKind_Slash,
TokenKind_Percent,
TokenKind_LessLess,
TokenKind_GreaterGreater,
TokenKind_And,
TokenKind_AndAnd,
TokenKind_Or,
TokenKind_OrOr,
TokenKind_Hat,
TokenKind_Equal,
TokenKind_Bang,
TokenKind_BangEqual,
TokenKind_EqualEqual,
TokenKind_Less,
TokenKind_Greater,
TokenKind_LessEqual,
TokenKind_GreaterEqual,
TokenKind_LeftParen,
TokenKind_RightParen,
TokenKind_LeftBracket,
TokenKind_RightBracket,
TokenKind_LeftCurly,
TokenKind_RightCurly,
TokenKind_Comma,
TokenKind_Dot,
TokenKind_Colon,
TokenKind_ColonColon,
TokenKind_Semicolon,
TokenKind_Arrow,
TokenKind_Ellipsis,
TokenKind_Integer,
TokenKind_Float,
TokenKind_Char,
TokenKind_String,
TokenKind_True,
TokenKind_False,
} _ZN6tokens9TokenKindE;

#line 75 "src/tokens.z"
typedef struct _ZN6tokens5TokenE _ZN6tokens5TokenE;

#line 8 "src/lexer.z"
typedef struct _ZN5lexer13LexingContextE _ZN5lexer13LexingContextE;

#line 7 "src/ast.z"
typedef struct _ZN3ast7AstTypeE _ZN3ast7AstTypeE;

#line 8 "src/ast.z"
typedef struct _ZN3ast4ExprE _ZN3ast4ExprE;

#line 9 "src/ast.z"
typedef struct _ZN3ast5BlockE _ZN3ast5BlockE;

#line 10 "src/ast.z"
typedef struct _ZN3ast4ItemE _ZN3ast4ItemE;

#line 11 "src/ast.z"
typedef struct _ZN3ast6ModuleE _ZN3ast6ModuleE;

#line 13 "src/ast.z"
typedef struct _ZN3ast5IdentE _ZN3ast5IdentE;

#line 18 "src/ast.z"
typedef enum _ZN3ast11IntegerSizeE {
IntegerSize_I8,
IntegerSize_I16,
IntegerSize_I32,
IntegerSize_I64,
IntegerSize_Int_Arch,
IntegerSize_Int_Unspecified,
} _ZN3ast11IntegerSizeE;

#line 35 "src/ast.z"
typedef enum _ZN3ast12FloatingSizeE {
FloatingSize_F32,
FloatingSize_F64,
FloatingSize_Float_Unspecified,
} _ZN3ast12FloatingSizeE;

#line 47 "src/ast.z"
typedef enum _ZN3ast15PrimitiveTyKindE {
PrimitiveTyKind_Void,
PrimitiveTyKind_ConstVoid,
PrimitiveTyKind_Signed,
PrimitiveTyKind_Unsigned,
PrimitiveTyKind_Floating,
PrimitiveTyKind_Bool,
PrimitiveTyKind_Char,
PrimitiveTyKind_ConstChar,
} _ZN3ast15PrimitiveTyKindE;

#line 58 "src/ast.z"
typedef union _ZN3ast15PrimitiveTyNodeE _ZN3ast15PrimitiveTyNodeE;

#line 63 "src/ast.z"
typedef struct _ZN3ast11PrimitiveTyE _ZN3ast11PrimitiveTyE;

#line 68 "src/ast.z"
typedef enum _ZN3ast11BindingKindE {
BindingKind_Item,
BindingKind_Local,
BindingKind_Module,
BindingKind_Parameter,
BindingKind_PrimitiveType,
BindingKind_Variant,
} _ZN3ast11BindingKindE;

#line 77 "src/ast.z"
typedef struct _ZN3ast4ItemE _ZN3ast4ItemE;

#line 78 "src/ast.z"
typedef struct _ZN3ast11EnumVariantE _ZN3ast11EnumVariantE;

#line 79 "src/ast.z"
typedef struct _ZN3ast17FunctionParameterE _ZN3ast17FunctionParameterE;

#line 80 "src/ast.z"
typedef struct _ZN3ast9LocalDataE _ZN3ast9LocalDataE;

#line 81 "src/ast.z"
typedef struct _ZN3ast11PrimitiveTyE _ZN3ast11PrimitiveTyE;

#line 83 "src/ast.z"
typedef union _ZN3ast11BindingNodeE _ZN3ast11BindingNodeE;

#line 92 "src/ast.z"
typedef struct _ZN3ast7BindingE _ZN3ast7BindingE;

#line 97 "src/ast.z"
typedef struct _ZN3ast4PathE _ZN3ast4PathE;

#line 104 "src/ast.z"
typedef struct _ZN3ast2TyE _ZN3ast2TyE;

#line 106 "src/ast.z"
typedef struct _ZN3ast8FieldDefE _ZN3ast8FieldDefE;

#line 111 "src/ast.z"
typedef struct _ZN3ast11CompoundDefE _ZN3ast11CompoundDefE;

#line 117 "src/ast.z"
typedef struct _ZN3ast7EnumDefE _ZN3ast7EnumDefE;

#line 123 "src/ast.z"
typedef struct _ZN3ast5FnDefE _ZN3ast5FnDefE;

#line 129 "src/ast.z"
typedef enum _ZN3ast6TyKindE {
TyKind_Void,
TyKind_ConstVoid,
TyKind_Variadic,
TyKind_Bool,
TyKind_Char,
TyKind_ConstChar,
TyKind_Signed,
TyKind_Unsigned,
TyKind_Floating,
TyKind_Ptr,
TyKind_Fn,
TyKind_Enum,
TyKind_Struct,
TyKind_Union,
} _ZN3ast6TyKindE;

#line 146 "src/ast.z"
typedef union _ZN3ast10TyKindNodeE _ZN3ast10TyKindNodeE;

#line 155 "src/ast.z"
typedef struct _ZN3ast2TyE _ZN3ast2TyE;

#line 160 "src/ast.z"
typedef struct _ZN3ast7PatternE _ZN3ast7PatternE;

#line 165 "src/ast.z"
typedef struct _ZN3ast4ItemE _ZN3ast4ItemE;

#line 167 "src/ast.z"
typedef struct _ZN3ast6ModuleE _ZN3ast6ModuleE;

#line 175 "src/ast.z"
typedef enum _ZN3ast11AstTypeKindE {
AstTypeKind_Void,
AstTypeKind_Ptr,
AstTypeKind_Path,
AstTypeKind_Variadic,
} _ZN3ast11AstTypeKindE;

#line 182 "src/ast.z"
typedef struct _ZN3ast12GenericParamE _ZN3ast12GenericParamE;

#line 186 "src/ast.z"
typedef struct _ZN3ast8GenericsE _ZN3ast8GenericsE;

#line 192 "src/ast.z"
typedef union _ZN3ast15AstTypeKindNodeE _ZN3ast15AstTypeKindNodeE;

#line 197 "src/ast.z"
typedef struct _ZN3ast7AstTypeE _ZN3ast7AstTypeE;

#line 203 "src/ast.z"
typedef enum _ZN3ast11LiteralKindE {
LiteralKind_Int,
LiteralKind_Float,
LiteralKind_Bool,
LiteralKind_Char,
LiteralKind_Str,
} _ZN3ast11LiteralKindE;

#line 211 "src/ast.z"
typedef union _ZN3ast12LiteralValueE _ZN3ast12LiteralValueE;

#line 219 "src/ast.z"
typedef struct _ZN3ast7LiteralE _ZN3ast7LiteralE;

#line 225 "src/ast.z"
typedef enum _ZN3ast17UnaryOperatorKindE {
UnaryOperatorKind_Deref,
UnaryOperatorKind_Refer,
UnaryOperatorKind_Negation,
UnaryOperatorKind_Complement,
} _ZN3ast17UnaryOperatorKindE;

#line 236 "src/ast.z"
typedef enum _ZN3ast18BinaryOperatorKindE {
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
} _ZN3ast18BinaryOperatorKindE;

#line 265 "src/ast.z"
typedef struct _ZN3ast10BinaryDataE _ZN3ast10BinaryDataE;

#line 271 "src/ast.z"
typedef struct _ZN3ast8CallDataE _ZN3ast8CallDataE;

#line 277 "src/ast.z"
typedef struct _ZN3ast8CastDataE _ZN3ast8CastDataE;

#line 283 "src/ast.z"
typedef struct _ZN3ast15ConditionalDataE _ZN3ast15ConditionalDataE;

#line 289 "src/ast.z"
typedef struct _ZN3ast9WhileDataE _ZN3ast9WhileDataE;

#line 294 "src/ast.z"
typedef struct _ZN3ast12IndexingDataE _ZN3ast12IndexingDataE;

#line 299 "src/ast.z"
typedef struct _ZN3ast9FieldDataE _ZN3ast9FieldDataE;

#line 304 "src/ast.z"
typedef struct _ZN3ast9UnaryDataE _ZN3ast9UnaryDataE;

#line 309 "src/ast.z"
typedef struct _ZN3ast14AssignmentDataE _ZN3ast14AssignmentDataE;

#line 314 "src/ast.z"
typedef struct _ZN3ast9LocalDataE _ZN3ast9LocalDataE;

#line 321 "src/ast.z"
typedef enum _ZN3ast8ExprKindE {
ExprKind_Binary,
ExprKind_Block,
ExprKind_Call,
ExprKind_Cast,
ExprKind_Conditional,
ExprKind_Field,
ExprKind_Indexing,
ExprKind_Path,
ExprKind_Literal,
ExprKind_Sizeof,
ExprKind_Unary,
ExprKind_While,
ExprKind_Assignment,
ExprKind_Local,
ExprKind_Return,
ExprKind_ControlFlow,
ExprKind_Defer,
ExprKind_Empty,
} _ZN3ast8ExprKindE;

#line 342 "src/ast.z"
typedef union _ZN3ast12ExprKindNodeE _ZN3ast12ExprKindNodeE;

#line 361 "src/ast.z"
typedef struct _ZN3ast4ExprE _ZN3ast4ExprE;

#line 368 "src/ast.z"
typedef struct _ZN3ast5BlockE _ZN3ast5BlockE;

#line 374 "src/ast.z"
typedef enum _ZN3ast14VisibilityKindE {
VisibilityKind_Public,
VisibilityKind_Private,
} _ZN3ast14VisibilityKindE;

#line 379 "src/ast.z"
typedef struct _ZN3ast10VisibilityE _ZN3ast10VisibilityE;

#line 383 "src/ast.z"
typedef struct _ZN3ast13CompoundFieldE _ZN3ast13CompoundFieldE;

#line 388 "src/ast.z"
typedef struct _ZN3ast12CompoundDataE _ZN3ast12CompoundDataE;

#line 395 "src/ast.z"
typedef struct _ZN3ast11EnumVariantE _ZN3ast11EnumVariantE;

#line 400 "src/ast.z"
typedef struct _ZN3ast8EnumDataE _ZN3ast8EnumDataE;

#line 406 "src/ast.z"
typedef struct _ZN3ast17FunctionParameterE _ZN3ast17FunctionParameterE;

#line 413 "src/ast.z"
typedef struct _ZN3ast14FunctionHeaderE _ZN3ast14FunctionHeaderE;

#line 421 "src/ast.z"
typedef struct _ZN3ast12FunctionDataE _ZN3ast12FunctionDataE;

#line 427 "src/ast.z"
typedef struct _ZN3ast12VariableDataE _ZN3ast12VariableDataE;

#line 434 "src/ast.z"
typedef union _ZN3ast12ItemKindNodeE _ZN3ast12ItemKindNodeE;

#line 442 "src/ast.z"
typedef enum _ZN3ast8ItemKindE {
ItemKind_Const,
ItemKind_Enum,
ItemKind_Function,
ItemKind_Struct,
ItemKind_Union,
ItemKind_Use,
ItemKind_Variable,
} _ZN3ast8ItemKindE;

#line 452 "src/ast.z"
typedef struct _ZN3ast4ItemE _ZN3ast4ItemE;

#line 468 "src/ast.z"
typedef struct _ZN3ast13CompileTargetE _ZN3ast13CompileTargetE;

#line 12 "src/parser.z"
typedef struct _ZN6parser14ParsingContextE _ZN6parser14ParsingContextE;

#line 9 "src/resolution.z"
typedef enum _ZN10resolution14SymbolInfoKindE {
SymbolInfoKind_Local,
SymbolInfoKind_Parameter,
} _ZN10resolution14SymbolInfoKindE;

#line 14 "src/resolution.z"
typedef union _ZN10resolution14SymbolInfoNodeE _ZN10resolution14SymbolInfoNodeE;

#line 19 "src/resolution.z"
typedef struct _ZN10resolution10SymbolInfoE _ZN10resolution10SymbolInfoE;

#line 25 "src/resolution.z"
typedef struct _ZN10resolution5ScopeE _ZN10resolution5ScopeE;

#line 30 "src/resolution.z"
typedef struct _ZN10resolution17PrimitiveTypeSidsE _ZN10resolution17PrimitiveTypeSidsE;

#line 48 "src/resolution.z"
typedef struct _ZN10resolution10IndexEntryE _ZN10resolution10IndexEntryE;

#line 52 "src/resolution.z"
typedef struct _ZN10resolution17ResolutionContextE _ZN10resolution17ResolutionContextE;

#line 10 "src/typecheck.z"
typedef struct _ZN9typecheck11CommonTypesE _ZN9typecheck11CommonTypesE;

#line 29 "src/typecheck.z"
typedef struct _ZN9typecheck11TypeContextE _ZN9typecheck11TypeContextE;

#line 9 "src/codegen.z"
typedef struct _ZN7codegen14CodegenContextE _ZN7codegen14CodegenContextE;

#line 18 "src/cstd.z"
#line 30 "src/cstd.z"
 i32 _ZN4cstd8SEEK_SETE= 0;
#line 31 "src/cstd.z"
 i32 _ZN4cstd8SEEK_CURE= 1;
#line 32 "src/cstd.z"
 i32 _ZN4cstd8SEEK_ENDE= 2;
#line 38 "src/cstd.z"
 void*  _ZN4cstd4nullE= (( void* )(0));
#line 39 "src/cstd.z"
 i32 _ZN4cstd3EOFE= -1;
#line 4 "src/intmap.z"
typedef struct _ZN6intmap6IntMapE {
 u64*  keys;
 u64*  values;
 u64 size;
 u64 load;
} _ZN6intmap6IntMapE;

#line 4 "src/strmap.z"
typedef struct _ZN6strmap6StrMapE {
 char* *  keys;
 u32*  values;
 u64 size;
 u64 load;
} _ZN6strmap6StrMapE;

#line 3 "src/source_map.z"
typedef struct _ZN10source_map4SpanE {
 u32 from;
 u32 to;
} _ZN10source_map4SpanE;

#line 8 "src/source_map.z"
typedef struct _ZN10source_map10SourceFileE {
 char*  name;
 char*  content;
 u32 length;
 u32 start;
 u32 end;
 u32*  lines;
 u32 num_lines;
} _ZN10source_map10SourceFileE;

#line 18 "src/source_map.z"
typedef struct _ZN10source_map9SourceMapE {
_ZN10source_map10SourceFileE*  files;
 u32 num_files;
 u32*  file_starts;
} _ZN10source_map9SourceMapE;

#line 4 "src/interning.z"
typedef struct _ZN9interning3SidE {
 u32 x;
} _ZN9interning3SidE;

#line 8 "src/interning.z"
typedef struct _ZN9interning8InternerE {
_ZN6strmap6StrMapE*  str_lookup;
 char* *  sid_lookup;
 u32 next_sid;
} _ZN9interning8InternerE;

#line 5 "src/session.z"
#line 7 "src/session.z"
typedef struct _ZN7session7SessionE {
_ZN9interning8InternerE interner;
_ZN10source_map9SourceMapE source;
 char*  root_path;
} _ZN7session7SessionE;

#line 75 "src/tokens.z"
typedef struct _ZN6tokens5TokenE {
_ZN6tokens9TokenKindE kind;
_ZN10source_map4SpanE span;
_ZN9interning3SidE lexeme;
} _ZN6tokens5TokenE;

#line 8 "src/lexer.z"
typedef struct _ZN5lexer13LexingContextE {
 u32 start;
 u32 current;
 u32 line;
 u32 file_span_offset;
_ZN10source_map10SourceFileE*  source;
_ZN6tokens5TokenE*  tokens;
 u32 current_token_idx;
_ZN7session7SessionE*  sess;
 char*  lexeme_buffer;
} _ZN5lexer13LexingContextE;

#line 7 "src/ast.z"
#line 8 "src/ast.z"
#line 9 "src/ast.z"
#line 10 "src/ast.z"
#line 11 "src/ast.z"
#line 13 "src/ast.z"
typedef struct _ZN3ast5IdentE {
_ZN9interning3SidE name;
_ZN10source_map4SpanE span;
} _ZN3ast5IdentE;

#line 58 "src/ast.z"
typedef union _ZN3ast15PrimitiveTyNodeE {
_ZN3ast11IntegerSizeE integer;
_ZN3ast12FloatingSizeE floating;
} _ZN3ast15PrimitiveTyNodeE;

#line 63 "src/ast.z"
typedef struct _ZN3ast11PrimitiveTyE {
_ZN3ast15PrimitiveTyNodeE node;
_ZN3ast15PrimitiveTyKindE kind;
} _ZN3ast11PrimitiveTyE;

#line 77 "src/ast.z"
#line 78 "src/ast.z"
#line 79 "src/ast.z"
#line 80 "src/ast.z"
#line 81 "src/ast.z"
#line 83 "src/ast.z"
typedef union _ZN3ast11BindingNodeE {
_ZN3ast4ItemE*  item;
_ZN3ast9LocalDataE*  local;
_ZN3ast17FunctionParameterE*  parameter;
_ZN3ast11PrimitiveTyE primitive;
_ZN3ast11EnumVariantE*  variant;
_ZN3ast6ModuleE*  module;
} _ZN3ast11BindingNodeE;

#line 92 "src/ast.z"
typedef struct _ZN3ast7BindingE {
_ZN3ast11BindingKindE kind;
_ZN3ast11BindingNodeE node;
} _ZN3ast7BindingE;

#line 97 "src/ast.z"
typedef struct _ZN3ast4PathE {
_ZN3ast5IdentE*  segments;
 u32 num_segments;
_ZN3ast7BindingE binding;
_ZN10source_map4SpanE span;
} _ZN3ast4PathE;

#line 104 "src/ast.z"
#line 106 "src/ast.z"
typedef struct _ZN3ast8FieldDefE {
_ZN9interning3SidE name;
_ZN3ast2TyE*  ty;
} _ZN3ast8FieldDefE;

#line 111 "src/ast.z"
typedef struct _ZN3ast11CompoundDefE {
_ZN3ast4PathE path;
_ZN3ast8FieldDefE*  fields;
 u32 num_fields;
} _ZN3ast11CompoundDefE;

#line 117 "src/ast.z"
typedef struct _ZN3ast7EnumDefE {
_ZN3ast4PathE path;
_ZN9interning3SidE*  variants;
 u32 num_variants;
} _ZN3ast7EnumDefE;

#line 123 "src/ast.z"
typedef struct _ZN3ast5FnDefE {
_ZN3ast2TyE* *  parameters;
 u32 num_parameters;
_ZN3ast2TyE*  output;
} _ZN3ast5FnDefE;

#line 146 "src/ast.z"
typedef union _ZN3ast10TyKindNodeE {
_ZN3ast11IntegerSizeE integer;
_ZN3ast12FloatingSizeE floating;
_ZN3ast2TyE*  ptr;
_ZN3ast11CompoundDefE compound;
_ZN3ast7EnumDefE _enum;
_ZN3ast5FnDefE function;
} _ZN3ast10TyKindNodeE;

#line 155 "src/ast.z"
typedef struct _ZN3ast2TyE {
_ZN3ast6TyKindE kind;
_ZN3ast10TyKindNodeE node;
} _ZN3ast2TyE;

#line 160 "src/ast.z"
typedef struct _ZN3ast7PatternE {
_ZN3ast5IdentE ident;
_ZN10source_map4SpanE span;
} _ZN3ast7PatternE;

#line 165 "src/ast.z"
#line 167 "src/ast.z"
typedef struct _ZN3ast6ModuleE {
_ZN10source_map4SpanE span;
_ZN3ast4ItemE*  items;
 u32 num_items;
_ZN3ast4PathE path;
_ZN3ast6ModuleE*  parent;
} _ZN3ast6ModuleE;

#line 182 "src/ast.z"
typedef struct _ZN3ast12GenericParamE {
_ZN3ast5IdentE ident;
} _ZN3ast12GenericParamE;

#line 186 "src/ast.z"
typedef struct _ZN3ast8GenericsE {
_ZN3ast12GenericParamE*  parameters;
 u32 num_parameters;
_ZN10source_map4SpanE span;
} _ZN3ast8GenericsE;

#line 192 "src/ast.z"
typedef union _ZN3ast15AstTypeKindNodeE {
_ZN3ast4PathE path;
_ZN3ast7AstTypeE*  ptr;
} _ZN3ast15AstTypeKindNodeE;

#line 197 "src/ast.z"
typedef struct _ZN3ast7AstTypeE {
_ZN3ast11AstTypeKindE kind;
_ZN3ast15AstTypeKindNodeE node;
_ZN3ast2TyE*  ty;
} _ZN3ast7AstTypeE;

#line 211 "src/ast.z"
typedef union _ZN3ast12LiteralValueE {
 f64 floating;
 u64 integer;
 bool boolean;
 char ch;
_ZN9interning3SidE str;
} _ZN3ast12LiteralValueE;

#line 219 "src/ast.z"
typedef struct _ZN3ast7LiteralE {
_ZN3ast11LiteralKindE kind;
_ZN3ast12LiteralValueE value;
} _ZN3ast7LiteralE;

#line 265 "src/ast.z"
typedef struct _ZN3ast10BinaryDataE {
_ZN3ast18BinaryOperatorKindE op;
_ZN3ast4ExprE*  left;
_ZN3ast4ExprE*  right;
} _ZN3ast10BinaryDataE;

#line 271 "src/ast.z"
typedef struct _ZN3ast8CallDataE {
_ZN3ast4ExprE*  func;
_ZN3ast4ExprE* *  args;
 u32 num_args;
} _ZN3ast8CallDataE;

#line 277 "src/ast.z"
typedef struct _ZN3ast8CastDataE {
_ZN3ast4ExprE*  inner;
_ZN3ast7AstTypeE*  ast_ty;
_ZN3ast2TyE*  ty;
} _ZN3ast8CastDataE;

#line 283 "src/ast.z"
typedef struct _ZN3ast15ConditionalDataE {
_ZN3ast4ExprE*  condition;
_ZN3ast4ExprE*  then;
_ZN3ast4ExprE*  otherwise;
} _ZN3ast15ConditionalDataE;

#line 289 "src/ast.z"
typedef struct _ZN3ast9WhileDataE {
_ZN3ast4ExprE*  condition;
_ZN3ast4ExprE*  body;
} _ZN3ast9WhileDataE;

#line 294 "src/ast.z"
typedef struct _ZN3ast12IndexingDataE {
_ZN3ast4ExprE*  array;
_ZN3ast4ExprE*  index;
} _ZN3ast12IndexingDataE;

#line 299 "src/ast.z"
typedef struct _ZN3ast9FieldDataE {
_ZN3ast4ExprE*  strct;
_ZN3ast5IdentE ident;
} _ZN3ast9FieldDataE;

#line 304 "src/ast.z"
typedef struct _ZN3ast9UnaryDataE {
_ZN3ast17UnaryOperatorKindE op;
_ZN3ast4ExprE*  inner;
} _ZN3ast9UnaryDataE;

#line 309 "src/ast.z"
typedef struct _ZN3ast14AssignmentDataE {
_ZN3ast4ExprE*  left;
_ZN3ast4ExprE*  right;
} _ZN3ast14AssignmentDataE;

#line 314 "src/ast.z"
typedef struct _ZN3ast9LocalDataE {
_ZN3ast7PatternE pat;
_ZN3ast4ExprE*  value;
_ZN3ast7AstTypeE*  ast_ty;
_ZN3ast2TyE*  ty;
} _ZN3ast9LocalDataE;

#line 342 "src/ast.z"
typedef union _ZN3ast12ExprKindNodeE {
_ZN3ast10BinaryDataE binary;
_ZN3ast5BlockE*  block;
_ZN3ast8CallDataE call;
_ZN3ast8CastDataE _cast;
_ZN3ast15ConditionalDataE conditional;
 bool control_flow_is_continue;
_ZN3ast9FieldDataE field;
_ZN3ast12IndexingDataE indexing;
_ZN3ast4PathE path;
_ZN3ast7LiteralE lit;
_ZN3ast4ExprE*  _sizeof;
_ZN3ast9UnaryDataE unary;
_ZN3ast9WhileDataE whl;
_ZN3ast14AssignmentDataE assignment;
_ZN3ast4ExprE*  _return;
_ZN3ast9LocalDataE local;
} _ZN3ast12ExprKindNodeE;

#line 361 "src/ast.z"
typedef struct _ZN3ast4ExprE {
_ZN10source_map4SpanE span;
_ZN3ast8ExprKindE kind;
_ZN3ast12ExprKindNodeE node;
_ZN3ast2TyE*  ty;
} _ZN3ast4ExprE;

#line 368 "src/ast.z"
typedef struct _ZN3ast5BlockE {
_ZN3ast4ExprE* *  exprs;
 u32 num_exprs;
_ZN10source_map4SpanE span;
} _ZN3ast5BlockE;

#line 379 "src/ast.z"
typedef struct _ZN3ast10VisibilityE {
_ZN3ast14VisibilityKindE kind;
} _ZN3ast10VisibilityE;

#line 383 "src/ast.z"
typedef struct _ZN3ast13CompoundFieldE {
_ZN3ast5IdentE ident;
_ZN3ast7AstTypeE*  ast_ty;
} _ZN3ast13CompoundFieldE;

#line 388 "src/ast.z"
typedef struct _ZN3ast12CompoundDataE {
_ZN3ast13CompoundFieldE*  fields;
 u32 num_fields;
_ZN3ast8GenericsE generics;
_ZN3ast2TyE*  ty;
} _ZN3ast12CompoundDataE;

#line 395 "src/ast.z"
typedef struct _ZN3ast11EnumVariantE {
_ZN3ast5IdentE ident;
_ZN3ast4ItemE*  _enum;
} _ZN3ast11EnumVariantE;

#line 400 "src/ast.z"
typedef struct _ZN3ast8EnumDataE {
_ZN3ast11EnumVariantE*  variants;
 u32 num_variants;
_ZN3ast2TyE*  ty;
} _ZN3ast8EnumDataE;

#line 406 "src/ast.z"
typedef struct _ZN3ast17FunctionParameterE {
_ZN3ast7PatternE pat;
_ZN3ast7AstTypeE*  ast_ty;
_ZN3ast2TyE*  ty;
} _ZN3ast17FunctionParameterE;

#line 413 "src/ast.z"
typedef struct _ZN3ast14FunctionHeaderE {
_ZN3ast17FunctionParameterE*  parameters;
 u32 num_parameters;
_ZN3ast7AstTypeE*  output_ast_ty;
_ZN3ast8GenericsE generics;
_ZN3ast2TyE*  ty;
} _ZN3ast14FunctionHeaderE;

#line 421 "src/ast.z"
typedef struct _ZN3ast12FunctionDataE {
_ZN3ast14FunctionHeaderE header;
_ZN3ast4ExprE*  body;
} _ZN3ast12FunctionDataE;

#line 427 "src/ast.z"
typedef struct _ZN3ast12VariableDataE {
_ZN3ast7AstTypeE*  ast_ty;
_ZN3ast2TyE*  ty;
 bool mutable;
_ZN3ast4ExprE*  body;
} _ZN3ast12VariableDataE;

#line 434 "src/ast.z"
typedef union _ZN3ast12ItemKindNodeE {
_ZN3ast12CompoundDataE compound;
_ZN3ast8EnumDataE _enum;
_ZN3ast12VariableDataE variable;
_ZN3ast12FunctionDataE function;
_ZN3ast4PathE _use;
} _ZN3ast12ItemKindNodeE;

#line 452 "src/ast.z"
typedef struct _ZN3ast4ItemE {
_ZN3ast5IdentE ident;
_ZN3ast8ItemKindE kind;
_ZN3ast12ItemKindNodeE node;
_ZN3ast10VisibilityE vis;
_ZN10source_map4SpanE span;
 bool should_mangle;
} _ZN3ast4ItemE;

#line 468 "src/ast.z"
typedef struct _ZN3ast13CompileTargetE {
_ZN3ast6ModuleE* *  modules;
 u32 num_modules;
} _ZN3ast13CompileTargetE;

#line 12 "src/parser.z"
typedef struct _ZN6parser14ParsingContextE {
 u64 current_token;
_ZN9interning8InternerE*  interner;
_ZN6tokens5TokenE*  tokens;
 u64 num_tokens;
_ZN10source_map9SourceMapE*  source_map;
_ZN7session7SessionE*  sess;
_ZN3ast6ModuleE*  module;
} _ZN6parser14ParsingContextE;

#line 14 "src/resolution.z"
typedef union _ZN10resolution14SymbolInfoNodeE {
_ZN3ast9LocalDataE*  local;
_ZN3ast17FunctionParameterE*  parameter;
} _ZN10resolution14SymbolInfoNodeE;

#line 19 "src/resolution.z"
typedef struct _ZN10resolution10SymbolInfoE {
_ZN3ast5IdentE ident;
_ZN10resolution14SymbolInfoKindE kind;
_ZN10resolution14SymbolInfoNodeE node;
} _ZN10resolution10SymbolInfoE;

#line 25 "src/resolution.z"
typedef struct _ZN10resolution5ScopeE {
_ZN10resolution10SymbolInfoE*  symbols;
 u32 num_symbols;
} _ZN10resolution5ScopeE;

#line 30 "src/resolution.z"
typedef struct _ZN10resolution17PrimitiveTypeSidsE {
_ZN9interning3SidE _void;
_ZN9interning3SidE _constvoid;
_ZN9interning3SidE _bool;
_ZN9interning3SidE _char;
_ZN9interning3SidE _constchar;
_ZN9interning3SidE _i8;
_ZN9interning3SidE _i16;
_ZN9interning3SidE _i32;
_ZN9interning3SidE _i64;
_ZN9interning3SidE _u8;
_ZN9interning3SidE _u16;
_ZN9interning3SidE _u32;
_ZN9interning3SidE _u64;
_ZN9interning3SidE _f32;
_ZN9interning3SidE _f64;
} _ZN10resolution17PrimitiveTypeSidsE;

#line 48 "src/resolution.z"
typedef struct _ZN10resolution10IndexEntryE {
_ZN3ast4PathE path;
} _ZN10resolution10IndexEntryE;

#line 52 "src/resolution.z"
typedef struct _ZN10resolution17ResolutionContextE {
_ZN10resolution5ScopeE*  scope_stack;
 u32 stack_top;
_ZN10source_map9SourceMapE*  source_map;
_ZN9interning8InternerE*  interner;
_ZN3ast6ModuleE*  root_module;
_ZN10resolution17PrimitiveTypeSidsE primitive_ty_sids;
_ZN6intmap6IntMapE*  index_lookup;
_ZN10resolution10IndexEntryE*  index;
 u32 num_indices;
} _ZN10resolution17ResolutionContextE;

#line 10 "src/typecheck.z"
typedef struct _ZN9typecheck11CommonTypesE {
_ZN3ast2TyE*  _void;
_ZN3ast2TyE*  _constvoid;
_ZN3ast2TyE*  _variadic;
_ZN3ast2TyE*  _bool;
_ZN3ast2TyE*  _char;
_ZN3ast2TyE*  _constchar;
_ZN3ast2TyE*  _i8;
_ZN3ast2TyE*  _i16;
_ZN3ast2TyE*  _i32;
_ZN3ast2TyE*  _i64;
_ZN3ast2TyE*  _u8;
_ZN3ast2TyE*  _u16;
_ZN3ast2TyE*  _u32;
_ZN3ast2TyE*  _u64;
_ZN3ast2TyE*  _f32;
_ZN3ast2TyE*  _f64;
} _ZN9typecheck11CommonTypesE;

#line 29 "src/typecheck.z"
typedef struct _ZN9typecheck11TypeContextE {
 bool initialized;
_ZN9interning8InternerE*  interner;
_ZN10source_map9SourceMapE*  source_map;
_ZN9typecheck11CommonTypesE common;
_ZN6intmap6IntMapE*  types_lookup;
_ZN3ast2TyE*  types;
 u32 next_type_idx;
} _ZN9typecheck11TypeContextE;

#line 664 "src/typecheck.z"
_ZN9typecheck11TypeContextE _ZN9typecheck3ctxE;
#line 9 "src/codegen.z"
typedef struct _ZN7codegen14CodegenContextE {
_ZN4cstd4FILEE*  out;
_ZN7session7SessionE*  sess;
_ZN10source_map9SourceMapE*  source;
_ZN3ast6ModuleE*  current_module;
_ZN9interning8InternerE*  interner;
} _ZN7codegen14CodegenContextE;

#line 32 "src/main.z"
 char*  basename( char*  path) ;
#line 33 "src/main.z"
 char*  dirname( char*  path) ;
#line 35 "src/main.z"
_ZN3ast6ModuleE*  _ZN4main10add_moduleE(_ZN7session7SessionE*  sess, _ZN3ast13CompileTargetE*  target, _ZN3ast4PathE path, _ZN3ast6ModuleE*  parent) ;
#line 37 "src/main.z"
_ZN3ast6ModuleE*  _ZN4main11find_moduleE(_ZN7session7SessionE*  sess, _ZN3ast13CompileTargetE*  target, _ZN3ast4PathE path, _ZN3ast6ModuleE*  parent) ;
#line 49 "src/main.z"
_ZN3ast6ModuleE*  _ZN4main10add_moduleE(_ZN7session7SessionE*  sess, _ZN3ast13CompileTargetE*  target, _ZN3ast4PathE path, _ZN3ast6ModuleE*  parent) ;
#line 75 "src/main.z"
 i32 main( i32 argc,  char* *  argv) ;
#line 2 "src/cstd.z"
 void*  malloc( u64 size) ;
#line 3 "src/cstd.z"
 void*  calloc( u64 size,  u64 count) ;
#line 4 "src/cstd.z"
 void free( void*  ptr) ;
#line 6 "src/cstd.z"
 void*  memset( void*  dest,  i32 ch,  u64 size) ;
#line 7 "src/cstd.z"
 void*  memcpy( void*  dest,  void*  src,  u64 size) ;
#line 8 "src/cstd.z"
 i32 strcmp( char*  lhs,  char*  rhs) ;
#line 9 "src/cstd.z"
 u64 strlen( char*  str) ;
#line 10 "src/cstd.z"
 char*  strtok( char*  str,  char*  delim) ;
#line 12 "src/cstd.z"
 f64 atof( char*  str) ;
#line 13 "src/cstd.z"
 i64 atol( char*  str) ;
#line 15 "src/cstd.z"
 void abort() ;
#line 16 "src/cstd.z"
 void exit( i32 status) ;
#line 20 "src/cstd.z"
_ZN4cstd4FILEE*  fopen( char*  filename,  char*  mode) ;
#line 21 "src/cstd.z"
 i32 fclose(_ZN4cstd4FILEE*  stream) ;
#line 23 "src/cstd.z"
 u64 fread( void*  buffer,  u64 size,  u64 count, _ZN4cstd4FILEE*  stream) ;
#line 24 "src/cstd.z"
 u64 fwrite( void*  buffer,  u64 size,  u64 count, _ZN4cstd4FILEE*  stream) ;
#line 26 "src/cstd.z"
 i32 fseek(_ZN4cstd4FILEE*  stream,  i64 offset,  i32 origin) ;
#line 27 "src/cstd.z"
 void rewind(_ZN4cstd4FILEE*  stream) ;
#line 28 "src/cstd.z"
 i64 ftell(_ZN4cstd4FILEE*  stream) ;
#line 34 "src/cstd.z"
 i32 printf( char*  format, ...) ;
#line 35 "src/cstd.z"
 i32 fprintf(_ZN4cstd4FILEE*  stream,  char*  format, ...) ;
#line 36 "src/cstd.z"
 i32 sprintf( char*  buffer,  char*  format, ...) ;
#line 11 "src/intmap.z"
_ZN6intmap6IntMapE*  _ZN6intmap13intmap_createE( u64 size) ;
#line 29 "src/intmap.z"
 u64 _ZN6intmap11intmap_hashE( u64 k) ;
#line 34 "src/intmap.z"
 void _ZN6intmap12intmap_resetE(_ZN6intmap6IntMapE*  map) ;
#line 40 "src/intmap.z"
 void _ZN6intmap13intmap_insertE(_ZN6intmap6IntMapE*  map,  u64 key,  u64 value) ;
#line 61 "src/intmap.z"
 u64 _ZN6intmap13intmap_lookupE(_ZN6intmap6IntMapE*  map,  u64 key) ;
#line 72 "src/intmap.z"
 void _ZN6intmap14intmap_destroyE(_ZN6intmap6IntMapE*  map) ;
#line 11 "src/strmap.z"
_ZN6strmap6StrMapE*  _ZN6strmap13strmap_createE( u64 size) ;
#line 29 "src/strmap.z"
 u32 _ZN6strmap11strmap_hashE( char*  s) ;
#line 42 "src/strmap.z"
 void _ZN6strmap13strmap_insertE(_ZN6strmap6StrMapE*  map,  char*  key,  u32 value) ;
#line 63 "src/strmap.z"
 u32 _ZN6strmap13strmap_lookupE(_ZN6strmap6StrMapE*  map,  char*  key) ;
#line 74 "src/strmap.z"
 void _ZN6strmap14strmap_destroyE(_ZN6strmap6StrMapE*  map) ;
#line 24 "src/source_map.z"
_ZN10source_map9SourceMapE _ZN10source_map17source_map_createE() ;
#line 33 "src/source_map.z"
 void _ZN10source_map17load_file_contentE(_ZN10source_map10SourceFileE*  file) ;
#line 43 "src/source_map.z"
_ZN10source_map10SourceFileE*  _ZN10source_map19source_map_new_fileE(_ZN10source_map9SourceMapE*  map,  char*  path,  char*  filename) ;
#line 67 "src/source_map.z"
 void _ZN10source_map19source_file_newlineE(_ZN10source_map10SourceFileE*  file,  u32 position) ;
#line 72 "src/source_map.z"
 void _ZN10source_map16source_file_doneE(_ZN10source_map10SourceFileE*  file,  u32 length) ;
#line 76 "src/source_map.z"
_ZN10source_map10SourceFileE*  _ZN10source_map15source_map_infoE(_ZN10source_map9SourceMapE*  m, _ZN10source_map4SpanE span,  u32*  first,  u32*  last) ;
#line 107 "src/source_map.z"
 void _ZN10source_map19emit_line_directiveE(_ZN4cstd4FILEE*  fp, _ZN10source_map9SourceMapE*  m, _ZN10source_map4SpanE span) ;
#line 116 "src/source_map.z"
 void _ZN10source_map14source_snippetE(_ZN10source_map9SourceMapE*  m, _ZN10source_map4SpanE span) ;
#line 4 "src/error.z"
 void _ZN5error10emit_errorE(_ZN10source_map9SourceMapE*  m, _ZN10source_map4SpanE span,  char*  msg) ;
#line 11 "src/error.z"
 void _ZN5error12emit_warningE(_ZN10source_map9SourceMapE*  m, _ZN10source_map4SpanE span,  char*  msg) ;
#line 14 "src/interning.z"
_ZN9interning8InternerE _ZN9interning15interner_createE() ;
#line 23 "src/interning.z"
_ZN9interning3SidE _ZN9interning6internE(_ZN9interning8InternerE*  interner,  char*  string) ;
#line 41 "src/interning.z"
 char*  _ZN9interning7get_strE(_ZN9interning8InternerE*  interner, _ZN9interning3SidE sid) ;
#line 20 "src/lexer.z"
 bool _ZN5lexer13is_alphabeticE( char c) ;
#line 24 "src/lexer.z"
 bool _ZN5lexer8is_digitE( char c) ;
#line 28 "src/lexer.z"
 bool _ZN5lexer15is_alphanumericE( char c) ;
#line 32 "src/lexer.z"
 bool _ZN5lexer14is_done_lexingE(_ZN5lexer13LexingContextE*  ctx) ;
#line 37 "src/lexer.z"
 char _ZN5lexer10peek_tokenE(_ZN5lexer13LexingContextE*  ctx,  u32 offset) ;
#line 43 "src/lexer.z"
 char _ZN5lexer7advanceE(_ZN5lexer13LexingContextE*  ctx) ;
#line 49 "src/lexer.z"
 void _ZN5lexer9add_tokenE(_ZN5lexer13LexingContextE*  ctx, _ZN6tokens9TokenKindE kind, _ZN9interning3SidE lexeme) ;
#line 59 "src/lexer.z"
 void _ZN5lexer16add_simple_tokenE(_ZN5lexer13LexingContextE*  ctx, _ZN6tokens9TokenKindE kind) ;
#line 65 "src/lexer.z"
 void _ZN5lexer31add_lookahead_conditional_tokenE(_ZN5lexer13LexingContextE*  ctx,  char expect, _ZN6tokens9TokenKindE first, _ZN6tokens9TokenKindE second) ;
#line 78 "src/lexer.z"
 void _ZN5lexer12read_newlineE(_ZN5lexer13LexingContextE*  ctx) ;
#line 82 "src/lexer.z"
_ZN9interning3SidE _ZN5lexer10get_lexemeE(_ZN5lexer13LexingContextE*  ctx,  u32 start_offset,  u32 end_offset) ;
#line 93 "src/lexer.z"
 void _ZN5lexer19single_line_commentE(_ZN5lexer13LexingContextE*  ctx) ;
#line 97 "src/lexer.z"
_ZN6tokens9TokenKindE _ZN5lexer10is_keywordE( char*  s) ;
#line 125 "src/lexer.z"
 void _ZN5lexer8lex_charE(_ZN5lexer13LexingContextE*  ctx) ;
#line 146 "src/lexer.z"
 void _ZN5lexer10lex_stringE(_ZN5lexer13LexingContextE*  ctx) ;
#line 168 "src/lexer.z"
 void _ZN5lexer10lex_numberE(_ZN5lexer13LexingContextE*  ctx) ;
#line 185 "src/lexer.z"
 void _ZN5lexer14lex_identifierE(_ZN5lexer13LexingContextE*  ctx) ;
#line 197 "src/lexer.z"
 void _ZN5lexer10scan_tokenE(_ZN5lexer13LexingContextE*  ctx) ;
#line 258 "src/lexer.z"
_ZN6tokens5TokenE*  _ZN5lexer3lexE(_ZN7session7SessionE*  sess, _ZN10source_map10SourceFileE*  source,  u32*  num_tokens) ;
#line 27 "src/ast.z"
 u32 _ZN3ast12integer_sizeE(_ZN3ast11IntegerSizeE size) ;
#line 41 "src/ast.z"
 u32 _ZN3ast13floating_sizeE(_ZN3ast12FloatingSizeE size) ;
#line 461 "src/ast.z"
_ZN3ast4ExprE*  _ZN3ast11create_exprE(_ZN3ast8ExprKindE kind) ;
#line 22 "src/parser.z"
 bool _ZN6parser15is_done_parsingE(_ZN6parser14ParsingContextE*  ctx) ;
#line 26 "src/parser.z"
 bool _ZN6parser6acceptE(_ZN6parser14ParsingContextE*  ctx, _ZN6tokens9TokenKindE token) ;
#line 35 "src/parser.z"
 bool _ZN6parser10can_acceptE(_ZN6parser14ParsingContextE*  ctx, _ZN6tokens9TokenKindE token) ;
#line 43 "src/parser.z"
_ZN6tokens5TokenE _ZN6parser10look_aheadE(_ZN6parser14ParsingContextE*  ctx,  u64 offset) ;
#line 51 "src/parser.z"
_ZN6tokens5TokenE _ZN6parser7consumeE(_ZN6parser14ParsingContextE*  ctx) ;
#line 56 "src/parser.z"
_ZN6tokens5TokenE _ZN6parser6expectE(_ZN6parser14ParsingContextE*  ctx, _ZN6tokens9TokenKindE kind) ;
#line 66 "src/parser.z"
 u32 _ZN6parser10span_startE(_ZN6parser14ParsingContextE*  ctx) ;
#line 70 "src/parser.z"
 u32 _ZN6parser8span_endE(_ZN6parser14ParsingContextE*  ctx) ;
#line 74 "src/parser.z"
_ZN3ast5IdentE _ZN6parser16parse_identifierE(_ZN6parser14ParsingContextE*  ctx) ;
#line 88 "src/parser.z"
_ZN3ast4PathE _ZN6parser10parse_pathE(_ZN6parser14ParsingContextE*  ctx) ;
#line 108 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser15parse_path_exprE(_ZN6parser14ParsingContextE*  ctx) ;
#line 114 "src/parser.z"
_ZN3ast7PatternE _ZN6parser13parse_patternE(_ZN6parser14ParsingContextE*  ctx) ;
#line 122 "src/parser.z"
_ZN3ast7AstTypeE*  _ZN6parser10parse_typeE(_ZN6parser14ParsingContextE*  ctx) ;
#line 147 "src/parser.z"
_ZN3ast18BinaryOperatorKindE _ZN6parser32convert_token_to_binary_operatorE(_ZN6tokens9TokenKindE tok) ;
#line 169 "src/parser.z"
 u32 _ZN6parser30get_binary_operator_precedenceE(_ZN3ast18BinaryOperatorKindE op) ;
#line 191 "src/parser.z"
 u32 _ZN6parser22get_current_precedenceE(_ZN6parser14ParsingContextE*  ctx) ;
#line 206 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser16parse_expressionE(_ZN6parser14ParsingContextE*  ctx,  u32 precedence) ;
#line 208 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser21parse_integer_literalE(_ZN6parser14ParsingContextE*  ctx) ;
#line 220 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser19parse_float_literalE(_ZN6parser14ParsingContextE*  ctx) ;
#line 232 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser18parse_char_literalE(_ZN6parser14ParsingContextE*  ctx) ;
#line 260 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser20parse_string_literalE(_ZN6parser14ParsingContextE*  ctx) ;
#line 271 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser18parse_bool_literalE(_ZN6parser14ParsingContextE*  ctx) ;
#line 281 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser10parse_callE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ExprE*  left) ;
#line 302 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser21parse_prefix_operatorE(_ZN6parser14ParsingContextE*  ctx) ;
#line 318 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser21parse_binary_operatorE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ExprE*  left, _ZN3ast18BinaryOperatorKindE operator) ;
#line 330 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser18parse_field_accessE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ExprE*  left) ;
#line 338 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser14parse_indexingE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ExprE*  left) ;
#line 349 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser16parse_assignmentE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ExprE*  left) ;
#line 357 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser20parse_infix_operatorE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ExprE*  left, _ZN6tokens5TokenE tok) ;
#line 372 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser10parse_stmtE(_ZN6parser14ParsingContextE*  ctx) ;
#line 374 "src/parser.z"
_ZN3ast5BlockE*  _ZN6parser11parse_blockE(_ZN6parser14ParsingContextE*  ctx) ;
#line 399 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser16parse_block_exprE(_ZN6parser14ParsingContextE*  ctx) ;
#line 405 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser8parse_ifE(_ZN6parser14ParsingContextE*  ctx) ;
#line 422 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser11parse_whileE(_ZN6parser14ParsingContextE*  ctx) ;
#line 432 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser12parse_sizeofE(_ZN6parser14ParsingContextE*  ctx) ;
#line 443 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser20parse_local_variableE(_ZN6parser14ParsingContextE*  ctx) ;
#line 458 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser18parse_control_flowE(_ZN6parser14ParsingContextE*  ctx) ;
#line 467 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser10parse_castE(_ZN6parser14ParsingContextE*  ctx) ;
#line 480 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser12parse_returnE(_ZN6parser14ParsingContextE*  ctx) ;
#line 488 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser16parse_expressionE(_ZN6parser14ParsingContextE*  ctx,  u32 precedence) ;
#line 524 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser10parse_stmtE(_ZN6parser14ParsingContextE*  ctx) ;
#line 547 "src/parser.z"
_ZN3ast8GenericsE _ZN6parser14parse_genericsE(_ZN6parser14ParsingContextE*  ctx) ;
#line 562 "src/parser.z"
 void _ZN6parser19parse_variable_declE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 576 "src/parser.z"
 void _ZN6parser19parse_compound_declE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 608 "src/parser.z"
 void _ZN6parser15parse_enum_declE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 629 "src/parser.z"
_ZN3ast14FunctionHeaderE _ZN6parser21parse_function_headerE(_ZN6parser14ParsingContextE*  ctx) ;
#line 663 "src/parser.z"
 void _ZN6parser19parse_function_declE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 680 "src/parser.z"
 void _ZN6parser9parse_useE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 690 "src/parser.z"
 void _ZN6parser10parse_itemE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 717 "src/parser.z"
_ZN3ast6ModuleE*  _ZN6parser5parseE(_ZN7session7SessionE*  sess, _ZN10source_map10SourceFileE*  source, _ZN9interning3SidE name, _ZN3ast6ModuleE*  parent) ;
#line 64 "src/resolution.z"
 void _ZN10resolution23setup_primitive_ty_sidsE(_ZN9interning8InternerE*  i, _ZN10resolution17PrimitiveTypeSidsE*  p) ;
#line 82 "src/resolution.z"
 void _ZN10resolution10push_blockE(_ZN10resolution17ResolutionContextE*  ctx) ;
#line 90 "src/resolution.z"
 void _ZN10resolution9pop_blockE(_ZN10resolution17ResolutionContextE*  ctx) ;
#line 96 "src/resolution.z"
 void _ZN10resolution14push_parameterE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast5IdentE ident, _ZN3ast17FunctionParameterE*  data) ;
#line 105 "src/resolution.z"
 void _ZN10resolution10push_localE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast5IdentE ident, _ZN3ast9LocalDataE*  data) ;
#line 114 "src/resolution.z"
_ZN3ast4PathE _ZN10resolution6lookupE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast5IdentE ident) ;
#line 151 "src/resolution.z"
 void _ZN10resolution8add_itemE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast6ModuleE*  parent, _ZN3ast4ItemE*  item) ;
#line 169 "src/resolution.z"
 void _ZN10resolution15import_wildcardE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4PathE path) ;
#line 181 "src/resolution.z"
 void _ZN10resolution12index_moduleE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast6ModuleE*  module) ;
#line 193 "src/resolution.z"
 bool _ZN10resolution25check_if_sid_is_primitiveE(_ZN10resolution17ResolutionContextE*  ctx, _ZN9interning3SidE s, _ZN3ast11PrimitiveTyE*  prim) ;
#line 220 "src/resolution.z"
 void _ZN10resolution12resolve_pathE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4PathE*  path) ;
#line 266 "src/resolution.z"
 void _ZN10resolution12resolve_typeE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast7AstTypeE*  ty) ;
#line 275 "src/resolution.z"
 void _ZN10resolution12resolve_exprE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 276 "src/resolution.z"
 void _ZN10resolution12resolve_itemE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 278 "src/resolution.z"
 void _ZN10resolution13resolve_unaryE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast9UnaryDataE unary) ;
#line 282 "src/resolution.z"
 void _ZN10resolution14resolve_binaryE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast10BinaryDataE binary) ;
#line 287 "src/resolution.z"
 void _ZN10resolution12resolve_callE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast8CallDataE call) ;
#line 297 "src/resolution.z"
 void _ZN10resolution19resolve_conditionalE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast15ConditionalDataE cond) ;
#line 305 "src/resolution.z"
 void _ZN10resolution13resolve_whileE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast9WhileDataE data) ;
#line 310 "src/resolution.z"
 void _ZN10resolution16resolve_indexingE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast12IndexingDataE idx) ;
#line 315 "src/resolution.z"
 void _ZN10resolution13resolve_fieldE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast9FieldDataE field) ;
#line 319 "src/resolution.z"
 void _ZN10resolution18resolve_assignmentE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast14AssignmentDataE assignment) ;
#line 324 "src/resolution.z"
 void _ZN10resolution13resolve_blockE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast5BlockE*  block) ;
#line 335 "src/resolution.z"
 void _ZN10resolution13resolve_localE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast9LocalDataE*  data) ;
#line 341 "src/resolution.z"
 void _ZN10resolution14resolve_sizeofE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 345 "src/resolution.z"
 void _ZN10resolution12resolve_castE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast8CastDataE*  data) ;
#line 350 "src/resolution.z"
 void _ZN10resolution12resolve_exprE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 370 "src/resolution.z"
 void _ZN10resolution16resolve_functionE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 396 "src/resolution.z"
 void _ZN10resolution16resolve_variableE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 405 "src/resolution.z"
 void _ZN10resolution16resolve_compoundE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 416 "src/resolution.z"
 void _ZN10resolution12resolve_itemE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 422 "src/resolution.z"
 void _ZN10resolution14resolve_moduleE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast6ModuleE*  module) ;
#line 431 "src/resolution.z"
 void _ZN10resolution13resolve_namesE(_ZN7session7SessionE*  sess, _ZN3ast6ModuleE*  module) ;
#line 39 "src/typecheck.z"
 u64 _ZN9typecheck7hash_tyE(_ZN3ast2TyE*  ty) ;
#line 41 "src/typecheck.z"
 u64 _ZN9typecheck7hash_fnE(_ZN3ast2TyE*  ty) ;
#line 54 "src/typecheck.z"
 u64 _ZN9typecheck9hash_pathE(_ZN3ast4PathE path) ;
#line 64 "src/typecheck.z"
 u64 _ZN9typecheck7hash_tyE(_ZN3ast2TyE*  ty) ;
#line 80 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck9intern_tyE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast2TyE ty) ;
#line 92 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck16create_base_typeE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast6TyKindE kind) ;
#line 98 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck17create_float_typeE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast12FloatingSizeE size) ;
#line 105 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck15create_int_typeE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast6TyKindE kind, _ZN3ast11IntegerSizeE size) ;
#line 112 "src/typecheck.z"
 void _ZN9typecheck19create_common_typesE(_ZN9typecheck11TypeContextE*  ctx) ;
#line 135 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck14ast_type_to_tyE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast7AstTypeE*  ast_ty) ;
#line 137 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck15primitive_to_tyE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast11PrimitiveTyE prim) ;
#line 168 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck14ast_path_to_tyE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast7AstTypeE*  ast_ty) ;
#line 184 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck13ast_ptr_to_tyE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast7AstTypeE*  ast_ty) ;
#line 191 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck14ast_type_to_tyE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast7AstTypeE*  ast_ty) ;
#line 199 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck17ast_literal_to_tyE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast7LiteralE lit) ;
#line 213 "src/typecheck.z"
 u32 _ZN9typecheck11coerce_typeE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast2TyE*  from, _ZN3ast2TyE*  to) ;
#line 244 "src/typecheck.z"
 void _ZN9typecheck18coerce_binary_exprE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr, _ZN3ast2TyE*  left, _ZN3ast2TyE*  right) ;
#line 265 "src/typecheck.z"
_ZN3ast4ExprE*  _ZN9typecheck16coerce_expr_typeE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr, _ZN3ast2TyE*  from, _ZN3ast2TyE*  to) ;
#line 278 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck10check_exprE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 279 "src/typecheck.z"
 void _ZN9typecheck10check_itemE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 280 "src/typecheck.z"
 void _ZN9typecheck9check_modE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast6ModuleE*  module) ;
#line 282 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck11check_unaryE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 307 "src/typecheck.z"
 bool _ZN9typecheck19operator_is_booleanE(_ZN3ast18BinaryOperatorKindE op) ;
#line 313 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck12check_binaryE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 324 "src/typecheck.z"
 void _ZN9typecheck11check_blockE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast5BlockE*  block) ;
#line 332 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck16check_block_exprE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 337 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck10check_callE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 364 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck17check_conditionalE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 377 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck11check_whileE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 386 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck14check_indexingE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 397 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck11check_fieldE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 421 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck10check_pathE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4PathE*  path) ;
#line 458 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck11check_localE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast9LocalDataE*  data) ;
#line 464 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck16check_assignmentE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast14AssignmentDataE assignment) ;
#line 470 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck12check_returnE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 475 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck12check_sizeofE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 480 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck10check_castE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast8CastDataE*  data) ;
#line 486 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck10check_exprE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 510 "src/typecheck.z"
 void _ZN9typecheck14check_variableE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 521 "src/typecheck.z"
 void _ZN9typecheck14check_functionE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 528 "src/typecheck.z"
 void _ZN9typecheck10check_itemE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 537 "src/typecheck.z"
 void _ZN9typecheck9check_modE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast6ModuleE*  module) ;
#line 545 "src/typecheck.z"
 void _ZN9typecheck12collect_enumE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 559 "src/typecheck.z"
 void _ZN9typecheck16collect_variableE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 564 "src/typecheck.z"
 void _ZN9typecheck16collect_functionE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 589 "src/typecheck.z"
 void _ZN9typecheck16collect_compoundE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 607 "src/typecheck.z"
 void _ZN9typecheck12collect_itemE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 614 "src/typecheck.z"
 void _ZN9typecheck11collect_modE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast6ModuleE*  module) ;
#line 622 "src/typecheck.z"
 void _ZN9typecheck13collect_namesE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast6ModuleE*  module) ;
#line 666 "src/typecheck.z"
 void _ZN9typecheck5checkE(_ZN7session7SessionE*  sess, _ZN3ast6ModuleE*  module) ;
#line 17 "src/codegen.z"
 void _ZN7codegen13generate_exprE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 18 "src/codegen.z"
 void _ZN7codegen14generate_blockE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast5BlockE*  block) ;
#line 19 "src/codegen.z"
 void _ZN7codegen13generate_itemE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 21 "src/codegen.z"
 u32 _ZN7codegen11type_is_ptrE(_ZN3ast7AstTypeE*  ty) ;
#line 26 "src/codegen.z"
 void _ZN7codegen16generate_preludeE(_ZN7codegen14CodegenContextE*  ctx) ;
#line 44 "src/codegen.z"
 void _ZN7codegen12generate_sidE(_ZN7codegen14CodegenContextE*  ctx, _ZN9interning3SidE sid) ;
#line 48 "src/codegen.z"
 void _ZN7codegen19generate_identifierE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast5IdentE ident) ;
#line 52 "src/codegen.z"
 void _ZN7codegen16generate_patternE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast7PatternE pat) ;
#line 56 "src/codegen.z"
 void _ZN7codegen11mangle_pathE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4PathE path) ;
#line 75 "src/codegen.z"
 void _ZN7codegen21mangle_path_and_identE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4PathE path, _ZN3ast5IdentE ident) ;
#line 87 "src/codegen.z"
 void _ZN7codegen20mangle_function_nameE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast6ModuleE*  module, _ZN3ast5IdentE ident, _ZN3ast14FunctionHeaderE header) ;
#line 91 "src/codegen.z"
 void _ZN7codegen11generate_tyE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast2TyE*  ty) ;
#line 118 "src/codegen.z"
 void _ZN7codegen13generate_charE(_ZN7codegen14CodegenContextE*  ctx,  char c) ;
#line 127 "src/codegen.z"
 void _ZN7codegen16generate_literalE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast7LiteralE lit) ;
#line 138 "src/codegen.z"
 void _ZN7codegen14generate_unaryE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast9UnaryDataE unary) ;
#line 148 "src/codegen.z"
 void _ZN7codegen15generate_binaryE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast10BinaryDataE binary) ;
#line 177 "src/codegen.z"
 void _ZN7codegen13generate_callE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast8CallDataE call) ;
#line 191 "src/codegen.z"
 void _ZN7codegen20generate_conditionalE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast15ConditionalDataE cond) ;
#line 202 "src/codegen.z"
 void _ZN7codegen14generate_whileE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast9WhileDataE data) ;
#line 209 "src/codegen.z"
 void _ZN7codegen17generate_indexingE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast12IndexingDataE idx) ;
#line 216 "src/codegen.z"
 void _ZN7codegen14generate_fieldE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast9FieldDataE field) ;
#line 231 "src/codegen.z"
 void _ZN7codegen15generate_sizeofE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 237 "src/codegen.z"
 void _ZN7codegen19generate_assignmentE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast14AssignmentDataE assignment) ;
#line 244 "src/codegen.z"
 void _ZN7codegen15generate_returnE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 250 "src/codegen.z"
 void _ZN7codegen21generate_control_flowE(_ZN7codegen14CodegenContextE*  ctx,  bool is_continue) ;
#line 255 "src/codegen.z"
 void _ZN7codegen14generate_localE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast9LocalDataE data) ;
#line 269 "src/codegen.z"
 void _ZN7codegen13generate_castE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast8CastDataE data) ;
#line 277 "src/codegen.z"
 void _ZN7codegen13generate_exprE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 297 "src/codegen.z"
 void _ZN7codegen14generate_blockE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast5BlockE*  block) ;
#line 311 "src/codegen.z"
 void _ZN7codegen17generate_variableE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 327 "src/codegen.z"
 void _ZN7codegen22generate_function_declE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 360 "src/codegen.z"
 void _ZN7codegen17generate_functionE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 366 "src/codegen.z"
 void _ZN7codegen13generate_enumE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 389 "src/codegen.z"
 void _ZN7codegen17generate_compoundE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 421 "src/codegen.z"
 void _ZN7codegen22generate_compound_declE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 435 "src/codegen.z"
 void _ZN7codegen22generate_mod_type_declE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast6ModuleE*  module) ;
#line 446 "src/codegen.z"
 void _ZN7codegen22generate_mod_type_defsE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast6ModuleE*  module) ;
#line 457 "src/codegen.z"
 void _ZN7codegen20generate_mod_fn_declE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast6ModuleE*  module) ;
#line 470 "src/codegen.z"
 void _ZN7codegen22generate_mod_fn_bodiesE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast6ModuleE*  module) ;
#line 480 "src/codegen.z"
 void _ZN7codegen8generateE(_ZN7session7SessionE*  sess, _ZN3ast13CompileTargetE*  target,  char*  output_file) ;
#line 32 "src/main.z"
 char*  basename( char*  path) ;
#line 33 "src/main.z"
 char*  dirname( char*  path) ;
#line 35 "src/main.z"
_ZN3ast6ModuleE*  _ZN4main10add_moduleE(_ZN7session7SessionE*  sess, _ZN3ast13CompileTargetE*  target, _ZN3ast4PathE path, _ZN3ast6ModuleE*  parent) ;
#line 37 "src/main.z"
_ZN3ast6ModuleE*  _ZN4main11find_moduleE(_ZN7session7SessionE*  sess, _ZN3ast13CompileTargetE*  target, _ZN3ast4PathE path, _ZN3ast6ModuleE*  parent) {
#line 39 "src/main.z"
 i32 i = 0;
;
#line 40 "src/main.z"
while ( ((( u32)(i))< target->num_modules))
{
#line 41 "src/main.z"
_ZN3ast6ModuleE*  module = target->modules[i];
;
#line 42 "src/main.z"
if ((module->path.segments[0].name.x== path.segments[0].name.x)){
#line 42 "src/main.z"
return module;
;
}
;
#line 43 "src/main.z"
i = (i+ 1);
;
}
;
#line 46 "src/main.z"
return _ZN4main10add_moduleE(sess,target,path,parent) ;
;
}
#line 49 "src/main.z"
_ZN3ast6ModuleE*  _ZN4main10add_moduleE(_ZN7session7SessionE*  sess, _ZN3ast13CompileTargetE*  target, _ZN3ast4PathE path, _ZN3ast6ModuleE*  parent) {
#line 51 "src/main.z"
_ZN10source_map10SourceFileE*  source = _ZN10source_map19source_map_new_fileE(&sess->source,sess->root_path,_ZN9interning7get_strE(&sess->interner,path.segments[0].name) ) ;
;
#line 52 "src/main.z"
_ZN3ast6ModuleE*  module = _ZN6parser5parseE(sess,source,path.segments[0].name,parent) ;
;
#line 54 "src/main.z"
target->modules[target->num_modules] = module;
;
#line 55 "src/main.z"
target->num_modules = ((( i32)(target->num_modules))+ 1);
;
#line 57 "src/main.z"
 i32 i = 0;
;
#line 58 "src/main.z"
while ( ((( u32)(i))< module->num_items))
{
#line 59 "src/main.z"
_ZN3ast4ItemE*  item = &module->items[i];
;
#line 60 "src/main.z"
if ((item->kind== ItemKind_Use)){
#line 61 "src/main.z"
_ZN3ast7BindingE binding ;
;
#line 62 "src/main.z"
binding.kind = BindingKind_Module;
;
#line 63 "src/main.z"
binding.node.module = _ZN4main11find_moduleE(sess,target,item->node._use,parent) ;
;
#line 64 "src/main.z"
item->node._use.binding = binding;
;
}
;
#line 66 "src/main.z"
i = (i+ 1);
;
}
;
#line 69 "src/main.z"
_ZN10resolution13resolve_namesE(sess,module) ;
#line 70 "src/main.z"
_ZN9typecheck5checkE(sess,module) ;
#line 72 "src/main.z"
return module;
;
}
#line 75 "src/main.z"
 i32 main( i32 argc,  char* *  argv) {
#line 76 "src/main.z"
if ((argc!= 3)){
#line 77 "src/main.z"
printf((( char* )("Usage: compiler INPUT OUTPUT\n"))) ;
#line 78 "src/main.z"
abort() ;
}
;
#line 81 "src/main.z"
_ZN7session7SessionE sess ;
;
#line 84 "src/main.z"
sess.interner = _ZN9interning15interner_createE() ;
;
#line 85 "src/main.z"
sess.source = _ZN10source_map17source_map_createE() ;
;
#line 86 "src/main.z"
 char*  root_filename = basename(argv[1]) ;
;
#line 87 "src/main.z"
sess.root_path = dirname(argv[1]) ;
;
#line 89 "src/main.z"
strtok(root_filename,(( char* )(".z"))) ;
#line 91 "src/main.z"
_ZN3ast13CompileTargetE target ;
;
#line 92 "src/main.z"
target.modules = malloc((( u64)((8* 64)))) ;
;
#line 93 "src/main.z"
target.num_modules = 0;
;
#line 95 "src/main.z"
_ZN3ast4PathE root_path ;
;
#line 96 "src/main.z"
root_path.segments = malloc(sizeof(_ZN3ast5IdentE)) ;
;
#line 97 "src/main.z"
root_path.segments[0].name = _ZN9interning6internE(&sess.interner,root_filename) ;
;
#line 98 "src/main.z"
root_path.num_segments = 1;
;
#line 100 "src/main.z"
_ZN4main10add_moduleE(&sess,&target,root_path,((_ZN3ast6ModuleE* )(_ZN4cstd4nullE))) ;
#line 102 "src/main.z"
_ZN7codegen8generateE(&sess,&target,argv[2]) ;
#line 104 "src/main.z"
return 0;
;
}
#line 2 "src/cstd.z"
 void*  malloc( u64 size) ;
#line 3 "src/cstd.z"
 void*  calloc( u64 size,  u64 count) ;
#line 4 "src/cstd.z"
 void free( void*  ptr) ;
#line 6 "src/cstd.z"
 void*  memset( void*  dest,  i32 ch,  u64 size) ;
#line 7 "src/cstd.z"
 void*  memcpy( void*  dest,  void*  src,  u64 size) ;
#line 8 "src/cstd.z"
 i32 strcmp( char*  lhs,  char*  rhs) ;
#line 9 "src/cstd.z"
 u64 strlen( char*  str) ;
#line 10 "src/cstd.z"
 char*  strtok( char*  str,  char*  delim) ;
#line 12 "src/cstd.z"
 f64 atof( char*  str) ;
#line 13 "src/cstd.z"
 i64 atol( char*  str) ;
#line 15 "src/cstd.z"
 void abort() ;
#line 16 "src/cstd.z"
 void exit( i32 status) ;
#line 20 "src/cstd.z"
_ZN4cstd4FILEE*  fopen( char*  filename,  char*  mode) ;
#line 21 "src/cstd.z"
 i32 fclose(_ZN4cstd4FILEE*  stream) ;
#line 23 "src/cstd.z"
 u64 fread( void*  buffer,  u64 size,  u64 count, _ZN4cstd4FILEE*  stream) ;
#line 24 "src/cstd.z"
 u64 fwrite( void*  buffer,  u64 size,  u64 count, _ZN4cstd4FILEE*  stream) ;
#line 26 "src/cstd.z"
 i32 fseek(_ZN4cstd4FILEE*  stream,  i64 offset,  i32 origin) ;
#line 27 "src/cstd.z"
 void rewind(_ZN4cstd4FILEE*  stream) ;
#line 28 "src/cstd.z"
 i64 ftell(_ZN4cstd4FILEE*  stream) ;
#line 34 "src/cstd.z"
 i32 printf( char*  format, ...) ;
#line 35 "src/cstd.z"
 i32 fprintf(_ZN4cstd4FILEE*  stream,  char*  format, ...) ;
#line 36 "src/cstd.z"
 i32 sprintf( char*  buffer,  char*  format, ...) ;
#line 11 "src/intmap.z"
_ZN6intmap6IntMapE*  _ZN6intmap13intmap_createE( u64 size) {
#line 12 "src/intmap.z"
_ZN6intmap6IntMapE*  map = malloc(sizeof(_ZN6intmap6IntMapE)) ;
;
#line 14 "src/intmap.z"
map->size = size;
;
#line 15 "src/intmap.z"
map->load = 0;
;
#line 16 "src/intmap.z"
map->keys = malloc((size* (( u64)(8)))) ;
;
#line 17 "src/intmap.z"
map->values = malloc((size* (( u64)(8)))) ;
;
#line 19 "src/intmap.z"
 u32 i = 0;
;
#line 20 "src/intmap.z"
while ( ((( u64)(i))< size))
{
#line 21 "src/intmap.z"
map->keys[i] = 0;
;
#line 22 "src/intmap.z"
map->values[i] = 0;
;
#line 23 "src/intmap.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 26 "src/intmap.z"
return map;
;
}
#line 29 "src/intmap.z"
 u64 _ZN6intmap11intmap_hashE( u64 k) {
#line 30 "src/intmap.z"
if ((k!= (( u64)(0)))){
#line 30 "src/intmap.z"
return k;
;
}
else {
#line 31 "src/intmap.z"
return 1;
;
}
;
}
#line 34 "src/intmap.z"
 void _ZN6intmap12intmap_resetE(_ZN6intmap6IntMapE*  map) {
#line 35 "src/intmap.z"
map->load = 0;
;
#line 36 "src/intmap.z"
memset((( void* )(map->keys)),0,(sizeof(map->size)* (( u64)(8)))) ;
#line 37 "src/intmap.z"
memset((( void* )(map->values)),0,(sizeof(map->size)* (( u64)(8)))) ;
}
#line 40 "src/intmap.z"
 void _ZN6intmap13intmap_insertE(_ZN6intmap6IntMapE*  map,  u64 key,  u64 value) {
#line 41 "src/intmap.z"
 u64 h = (_ZN6intmap11intmap_hashE(key) % map->size);
;
#line 42 "src/intmap.z"
if (((map->load+ (( u64)(1)))>= map->size)){
#line 43 "src/intmap.z"
printf((( char* )("Hashmap of size %lu is full!\n")),map->size) ;
#line 44 "src/intmap.z"
exit(-1) ;
}
;
#line 46 "src/intmap.z"
while ( true)
{
#line 47 "src/intmap.z"
if ((map->keys[h]== key)){
#line 48 "src/intmap.z"
map->values[h] = value;
;
#line 49 "src/intmap.z"
break;
;
}
else {
#line 50 "src/intmap.z"
if ((map->keys[h]== (( u64)(0)))){
#line 51 "src/intmap.z"
map->keys[h] = key;
;
#line 52 "src/intmap.z"
map->values[h] = value;
;
#line 53 "src/intmap.z"
map->load = (map->load+ (( u64)(1)));
;
#line 54 "src/intmap.z"
break;
;
}
else {
#line 56 "src/intmap.z"
h = ((h+ (( u64)(1)))% map->size);
;
}
;
}
;
}
;
}
#line 61 "src/intmap.z"
 u64 _ZN6intmap13intmap_lookupE(_ZN6intmap6IntMapE*  map,  u64 key) {
#line 62 "src/intmap.z"
 u64 h = (_ZN6intmap11intmap_hashE(key) % map->size);
;
#line 63 "src/intmap.z"
while ( true)
{
#line 64 "src/intmap.z"
if ((map->keys[h]== (( u64)(0)))){
#line 64 "src/intmap.z"
return 0;
;
}
;
#line 65 "src/intmap.z"
if ((map->keys[h]== key)){
#line 66 "src/intmap.z"
return map->values[h];
;
}
;
#line 68 "src/intmap.z"
h = ((h+ (( u64)(1)))% map->size);
;
}
;
}
#line 72 "src/intmap.z"
 void _ZN6intmap14intmap_destroyE(_ZN6intmap6IntMapE*  map) {
#line 73 "src/intmap.z"
free((( void* )(map->keys))) ;
#line 74 "src/intmap.z"
free((( void* )(map->values))) ;
#line 75 "src/intmap.z"
free((( void* )(map))) ;
}
#line 11 "src/strmap.z"
_ZN6strmap6StrMapE*  _ZN6strmap13strmap_createE( u64 size) {
#line 12 "src/strmap.z"
_ZN6strmap6StrMapE*  map = malloc(sizeof(_ZN6strmap6StrMapE)) ;
;
#line 14 "src/strmap.z"
map->size = size;
;
#line 15 "src/strmap.z"
map->load = 0;
;
#line 16 "src/strmap.z"
map->keys = malloc((size* (( u64)(8)))) ;
;
#line 17 "src/strmap.z"
map->values = malloc((size* (( u64)(4)))) ;
;
#line 19 "src/strmap.z"
 u32 i = 0;
;
#line 20 "src/strmap.z"
while ( ((( u64)(i))< size))
{
#line 21 "src/strmap.z"
map->keys[i] = 0;
;
#line 22 "src/strmap.z"
map->values[i] = 0;
;
#line 23 "src/strmap.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 26 "src/strmap.z"
return map;
;
}
#line 29 "src/strmap.z"
 u32 _ZN6strmap11strmap_hashE( char*  s) {
#line 30 "src/strmap.z"
 u32 hash = 5381;
;
#line 31 "src/strmap.z"
 i32 c = *s;
;
#line 32 "src/strmap.z"
 u32 i = 0;
;
#line 33 "src/strmap.z"
while ( (c!= 0))
{
#line 34 "src/strmap.z"
hash = ((( i32)((((( i32)(hash))<< 5)+ hash)))+ c);
;
#line 35 "src/strmap.z"
i = ((( i32)(i))+ 1);
;
#line 36 "src/strmap.z"
c = s[i];
;
}
;
#line 38 "src/strmap.z"
if (((( i32)(hash))!= 0)){
#line 38 "src/strmap.z"
return hash;
;
}
else {
#line 39 "src/strmap.z"
return 1;
;
}
;
}
#line 42 "src/strmap.z"
 void _ZN6strmap13strmap_insertE(_ZN6strmap6StrMapE*  map,  char*  key,  u32 value) {
#line 43 "src/strmap.z"
 u32 h = ((( u64)(_ZN6strmap11strmap_hashE(key) ))% map->size);
;
#line 44 "src/strmap.z"
if (((map->load+ (( u64)(1)))>= map->size)){
#line 45 "src/strmap.z"
printf((( char* )("Hashmap of size %lu is full!\n")),map->size) ;
#line 46 "src/strmap.z"
exit(-1) ;
}
;
#line 48 "src/strmap.z"
while ( true)
{
#line 49 "src/strmap.z"
if (((map->keys[h]!= (( char* )(0)))&& !(( bool)(strcmp((( char* )(map->keys[h])),(( char* )(key))) )))){
#line 50 "src/strmap.z"
map->values[h] = value;
;
#line 51 "src/strmap.z"
break;
;
}
else {
#line 52 "src/strmap.z"
if ((map->keys[h]== (( char* )(0)))){
#line 53 "src/strmap.z"
map->keys[h] = key;
;
#line 54 "src/strmap.z"
map->values[h] = value;
;
#line 55 "src/strmap.z"
map->load = (map->load+ (( u64)(1)));
;
#line 56 "src/strmap.z"
break;
;
}
else {
#line 58 "src/strmap.z"
h = ((( u64)(((( i32)(h))+ 1)))% map->size);
;
}
;
}
;
}
;
}
#line 63 "src/strmap.z"
 u32 _ZN6strmap13strmap_lookupE(_ZN6strmap6StrMapE*  map,  char*  key) {
#line 64 "src/strmap.z"
 u32 h = ((( u64)(_ZN6strmap11strmap_hashE(key) ))% map->size);
;
#line 65 "src/strmap.z"
while ( true)
{
#line 66 "src/strmap.z"
if ((map->keys[h]== (( char* )(0)))){
#line 66 "src/strmap.z"
return 0;
;
}
;
#line 67 "src/strmap.z"
if (!(( bool)(strcmp((( char* )(map->keys[h])),(( char* )(key))) ))){
#line 68 "src/strmap.z"
return map->values[h];
;
}
;
#line 70 "src/strmap.z"
h = ((( u64)(((( i32)(h))+ 1)))% map->size);
;
}
;
}
#line 74 "src/strmap.z"
 void _ZN6strmap14strmap_destroyE(_ZN6strmap6StrMapE*  map) {
#line 75 "src/strmap.z"
free((( void* )(map->keys))) ;
#line 76 "src/strmap.z"
free((( void* )(map->values))) ;
#line 77 "src/strmap.z"
free((( void* )(map))) ;
}
#line 24 "src/source_map.z"
_ZN10source_map9SourceMapE _ZN10source_map17source_map_createE() {
#line 25 "src/source_map.z"
_ZN10source_map9SourceMapE map ;
;
#line 26 "src/source_map.z"
map.files = calloc(sizeof(_ZN10source_map10SourceFileE),(( u64)(64))) ;
;
#line 27 "src/source_map.z"
map.num_files = 0;
;
#line 28 "src/source_map.z"
map.file_starts = calloc(sizeof(u32),(( u64)(64))) ;
;
#line 30 "src/source_map.z"
return map;
;
}
#line 33 "src/source_map.z"
 void _ZN10source_map17load_file_contentE(_ZN10source_map10SourceFileE*  file) {
#line 34 "src/source_map.z"
_ZN4cstd4FILEE*  fp = fopen((( char* )(file->name)),(( char* )("rb"))) ;
;
#line 35 "src/source_map.z"
fseek(fp,(( i64)(0)),_ZN4cstd8SEEK_ENDE) ;
#line 36 "src/source_map.z"
file->length = ftell(fp) ;
;
#line 37 "src/source_map.z"
rewind(fp) ;
#line 38 "src/source_map.z"
file->content = malloc((( u64)(file->length))) ;
;
#line 39 "src/source_map.z"
fread((( void* )(file->content)),(( u64)(1)),(( u64)(file->length)),fp) ;
#line 40 "src/source_map.z"
fclose(fp) ;
}
#line 43 "src/source_map.z"
_ZN10source_map10SourceFileE*  _ZN10source_map19source_map_new_fileE(_ZN10source_map9SourceMapE*  map,  char*  path,  char*  filename) {
#line 44 "src/source_map.z"
_ZN10source_map10SourceFileE*  file = &map->files[map->num_files];
;
#line 45 "src/source_map.z"
map->num_files = ((( i32)(map->num_files))+ 1);
;
#line 47 "src/source_map.z"
 u32 needed_length = ((strlen((( char* )(path))) + strlen((( char* )(filename))) )+ (( u64)(4)));
;
#line 49 "src/source_map.z"
 char*  name_buffer = malloc((( u64)(needed_length))) ;
;
#line 51 "src/source_map.z"
sprintf(name_buffer,(( char* )("%s/%s.z")),path,filename) ;
#line 53 "src/source_map.z"
file->name = name_buffer;
;
#line 54 "src/source_map.z"
file->lines = calloc(sizeof(u32),(( u64)(4096))) ;
;
#line 55 "src/source_map.z"
file->num_lines = 1;
;
#line 57 "src/source_map.z"
if (((( i32)(map->num_files))> 1)){
#line 57 "src/source_map.z"
file->start = map->files[((( i32)(map->num_files))- 2)].end;
;
}
else {
#line 58 "src/source_map.z"
file->start = 0;
;
}
;
#line 60 "src/source_map.z"
map->file_starts[((( i32)(map->num_files))- 1)] = file->start;
;
#line 62 "src/source_map.z"
_ZN10source_map17load_file_contentE(file) ;
#line 64 "src/source_map.z"
return file;
;
}
#line 67 "src/source_map.z"
 void _ZN10source_map19source_file_newlineE(_ZN10source_map10SourceFileE*  file,  u32 position) {
#line 68 "src/source_map.z"
file->lines[file->num_lines] = (file->start+ position);
;
#line 69 "src/source_map.z"
file->num_lines = ((( i32)(file->num_lines))+ 1);
;
}
#line 72 "src/source_map.z"
 void _ZN10source_map16source_file_doneE(_ZN10source_map10SourceFileE*  file,  u32 length) {
#line 73 "src/source_map.z"
file->end = (file->start+ length);
;
}
#line 76 "src/source_map.z"
_ZN10source_map10SourceFileE*  _ZN10source_map15source_map_infoE(_ZN10source_map9SourceMapE*  m, _ZN10source_map4SpanE span,  u32*  first,  u32*  last) {
#line 77 "src/source_map.z"
 u32 i = 0;
;
#line 78 "src/source_map.z"
_ZN10source_map10SourceFileE*  file = 0;
;
#line 79 "src/source_map.z"
while ( (i< m->num_files))
{
#line 80 "src/source_map.z"
if ((m->file_starts[i]> span.from)){
#line 80 "src/source_map.z"
break;
;
}
;
#line 81 "src/source_map.z"
file = &m->files[i];
;
#line 82 "src/source_map.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 85 "src/source_map.z"
if (!(( bool)(file))){
#line 85 "src/source_map.z"
abort() ;
}
;
#line 87 "src/source_map.z"
i = 0;
;
#line 88 "src/source_map.z"
while ( (i< file->num_lines))
{
#line 89 "src/source_map.z"
if ((file->lines[i]<= span.from)){
#line 90 "src/source_map.z"
*first = i;
;
}
else {
#line 92 "src/source_map.z"
break;
;
}
;
#line 93 "src/source_map.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 95 "src/source_map.z"
i = ((( i32)(i))- 1);
;
#line 96 "src/source_map.z"
while ( (i< file->num_lines))
{
#line 97 "src/source_map.z"
if ((file->lines[i]<= span.to)){
#line 98 "src/source_map.z"
*last = i;
;
}
else {
#line 100 "src/source_map.z"
break;
;
}
;
#line 101 "src/source_map.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 104 "src/source_map.z"
return file;
;
}
#line 107 "src/source_map.z"
 void _ZN10source_map19emit_line_directiveE(_ZN4cstd4FILEE*  fp, _ZN10source_map9SourceMapE*  m, _ZN10source_map4SpanE span) {
#line 108 "src/source_map.z"
 u32 line_first ;
;
#line 109 "src/source_map.z"
 u32 line_end ;
;
#line 111 "src/source_map.z"
_ZN10source_map10SourceFileE*  file = _ZN10source_map15source_map_infoE(m,span,&line_first,&line_end) ;
;
#line 113 "src/source_map.z"
fprintf(fp,(( char* )("#line %u \"%s\"\n")),((( i32)(line_first))+ 1),file->name) ;
}
#line 116 "src/source_map.z"
 void _ZN10source_map14source_snippetE(_ZN10source_map9SourceMapE*  m, _ZN10source_map4SpanE span) {
#line 118 "src/source_map.z"
 u32 line_first ;
;
#line 119 "src/source_map.z"
 u32 line_last ;
;
#line 121 "src/source_map.z"
_ZN10source_map10SourceFileE*  file = _ZN10source_map15source_map_infoE(m,span,&line_first,&line_last) ;
;
#line 123 "src/source_map.z"
printf((( char* )("%s:%u\n")),file->name,((( i32)(line_first))+ 1)) ;
#line 125 "src/source_map.z"
 char*  buffer = malloc((( u64)(1024))) ;
;
#line 126 "src/source_map.z"
 u32 i = line_first;
;
#line 127 "src/source_map.z"
while ( (i<= line_last))
{
#line 128 "src/source_map.z"
 u32 line_start = file->lines[i];
;
#line 129 "src/source_map.z"
 u32 line_end = file->lines[((( i32)(i))+ 1)];
;
#line 130 "src/source_map.z"
 u32 length = (line_end- line_start);
;
#line 131 "src/source_map.z"
memcpy((( void* )(buffer)),(( void* )(&file->content[(((( i32)(line_start))+ 1)- file->start)])),(( u64)(length))) ;
#line 132 "src/source_map.z"
buffer[((( i32)(length))+ 1)] = 0;
;
#line 133 "src/source_map.z"
printf((( char* )("%s\n")),buffer) ;
#line 134 "src/source_map.z"
i = ((( i32)(i))+ 1);
;
}
;
}
#line 4 "src/error.z"
 void _ZN5error10emit_errorE(_ZN10source_map9SourceMapE*  m, _ZN10source_map4SpanE span,  char*  msg) {
#line 5 "src/error.z"
printf((( char* )("error: %s\n")),msg) ;
#line 6 "src/error.z"
_ZN10source_map14source_snippetE(m,span) ;
#line 7 "src/error.z"
abort() ;
}
#line 11 "src/error.z"
 void _ZN5error12emit_warningE(_ZN10source_map9SourceMapE*  m, _ZN10source_map4SpanE span,  char*  msg) {
#line 12 "src/error.z"
printf((( char* )("warning: %s\n")),msg) ;
#line 13 "src/error.z"
_ZN10source_map14source_snippetE(m,span) ;
}
#line 14 "src/interning.z"
_ZN9interning8InternerE _ZN9interning15interner_createE() {
#line 15 "src/interning.z"
_ZN9interning8InternerE interner ;
;
#line 16 "src/interning.z"
interner.str_lookup = _ZN6strmap13strmap_createE((( u64)(2048))) ;
;
#line 17 "src/interning.z"
interner.sid_lookup = calloc((( u64)(8)),(( u64)(2048))) ;
;
#line 18 "src/interning.z"
interner.next_sid = 1;
;
#line 19 "src/interning.z"
return interner;
;
}
#line 23 "src/interning.z"
_ZN9interning3SidE _ZN9interning6internE(_ZN9interning8InternerE*  interner,  char*  string) {
#line 24 "src/interning.z"
_ZN9interning3SidE sid ;
;
#line 25 "src/interning.z"
sid.x = _ZN6strmap13strmap_lookupE(interner->str_lookup,string) ;
;
#line 26 "src/interning.z"
if (((( i32)(sid.x))== 0)){
#line 28 "src/interning.z"
sid.x = interner->next_sid;
;
#line 29 "src/interning.z"
interner->next_sid = ((( i32)(interner->next_sid))+ 1);
;
#line 31 "src/interning.z"
 u64 len = (strlen((( char* )(string))) + (( u64)(1)));
;
#line 32 "src/interning.z"
 char*  copy = malloc(len) ;
;
#line 33 "src/interning.z"
memcpy((( void* )(copy)),(( void* )(string)),len) ;
#line 34 "src/interning.z"
interner->sid_lookup[sid.x] = copy;
;
#line 36 "src/interning.z"
_ZN6strmap13strmap_insertE(interner->str_lookup,copy,sid.x) ;
}
;
#line 38 "src/interning.z"
return sid;
;
}
#line 41 "src/interning.z"
 char*  _ZN9interning7get_strE(_ZN9interning8InternerE*  interner, _ZN9interning3SidE sid) {
#line 42 "src/interning.z"
return interner->sid_lookup[sid.x];
;
}
#line 20 "src/lexer.z"
 bool _ZN5lexer13is_alphabeticE( char c) {
#line 21 "src/lexer.z"
return (((c>= 'A')&& (c<= 'Z'))|| ((c>= 'a')&& (c<= 'z')));
;
}
#line 24 "src/lexer.z"
 bool _ZN5lexer8is_digitE( char c) {
#line 25 "src/lexer.z"
return ((c>= '0')&& (c<= '9'));
;
}
#line 28 "src/lexer.z"
 bool _ZN5lexer15is_alphanumericE( char c) {
#line 29 "src/lexer.z"
return (_ZN5lexer13is_alphabeticE(c) || _ZN5lexer8is_digitE(c) );
;
}
#line 32 "src/lexer.z"
 bool _ZN5lexer14is_done_lexingE(_ZN5lexer13LexingContextE*  ctx) {
#line 33 "src/lexer.z"
_ZN10source_map10SourceFileE*  source = ctx->source;
;
#line 34 "src/lexer.z"
return (ctx->current>= source->length);
;
}
#line 37 "src/lexer.z"
 char _ZN5lexer10peek_tokenE(_ZN5lexer13LexingContextE*  ctx,  u32 offset) {
#line 38 "src/lexer.z"
if (_ZN5lexer14is_done_lexingE(ctx) ){
#line 38 "src/lexer.z"
return 0;
;
}
;
#line 39 "src/lexer.z"
_ZN10source_map10SourceFileE*  source = ctx->source;
;
#line 40 "src/lexer.z"
return source->content[(ctx->current+ offset)];
;
}
#line 43 "src/lexer.z"
 char _ZN5lexer7advanceE(_ZN5lexer13LexingContextE*  ctx) {
#line 44 "src/lexer.z"
ctx->current = ((( i32)(ctx->current))+ 1);
;
#line 45 "src/lexer.z"
_ZN10source_map10SourceFileE*  source = ctx->source;
;
#line 46 "src/lexer.z"
return source->content[((( i32)(ctx->current))- 1)];
;
}
#line 49 "src/lexer.z"
 void _ZN5lexer9add_tokenE(_ZN5lexer13LexingContextE*  ctx, _ZN6tokens9TokenKindE kind, _ZN9interning3SidE lexeme) {
#line 50 "src/lexer.z"
_ZN6tokens5TokenE token ;
;
#line 51 "src/lexer.z"
token.kind = kind;
;
#line 52 "src/lexer.z"
token.lexeme = lexeme;
;
#line 53 "src/lexer.z"
token.span.from = (ctx->start+ ctx->file_span_offset);
;
#line 54 "src/lexer.z"
token.span.to = (ctx->current+ ctx->file_span_offset);
;
#line 55 "src/lexer.z"
ctx->tokens[ctx->current_token_idx] = token;
;
#line 56 "src/lexer.z"
ctx->current_token_idx = ((( i32)(ctx->current_token_idx))+ 1);
;
}
#line 59 "src/lexer.z"
 void _ZN5lexer16add_simple_tokenE(_ZN5lexer13LexingContextE*  ctx, _ZN6tokens9TokenKindE kind) {
#line 60 "src/lexer.z"
_ZN9interning3SidE null_sid ;
;
#line 61 "src/lexer.z"
null_sid.x = 0;
;
#line 62 "src/lexer.z"
_ZN5lexer9add_tokenE(ctx,kind,null_sid) ;
}
#line 65 "src/lexer.z"
 void _ZN5lexer31add_lookahead_conditional_tokenE(_ZN5lexer13LexingContextE*  ctx,  char expect, _ZN6tokens9TokenKindE first, _ZN6tokens9TokenKindE second) {
#line 66 "src/lexer.z"
_ZN6tokens9TokenKindE kind ;
;
#line 67 "src/lexer.z"
if ((_ZN5lexer10peek_tokenE(ctx,(( u32)(0))) == expect)){
#line 68 "src/lexer.z"
_ZN5lexer7advanceE(ctx) ;
#line 69 "src/lexer.z"
kind = first;
;
}
else {
#line 71 "src/lexer.z"
kind = second;
;
}
;
#line 73 "src/lexer.z"
_ZN9interning3SidE null_sid ;
;
#line 74 "src/lexer.z"
null_sid.x = 0;
;
#line 75 "src/lexer.z"
_ZN5lexer9add_tokenE(ctx,kind,null_sid) ;
}
#line 78 "src/lexer.z"
 void _ZN5lexer12read_newlineE(_ZN5lexer13LexingContextE*  ctx) {
#line 79 "src/lexer.z"
_ZN10source_map19source_file_newlineE(ctx->source,ctx->start) ;
}
#line 82 "src/lexer.z"
_ZN9interning3SidE _ZN5lexer10get_lexemeE(_ZN5lexer13LexingContextE*  ctx,  u32 start_offset,  u32 end_offset) {
#line 83 "src/lexer.z"
 u32 str_len = (ctx->current- ((ctx->start+ start_offset)+ end_offset));
;
#line 84 "src/lexer.z"
_ZN10source_map10SourceFileE*  source = ctx->source;
;
#line 85 "src/lexer.z"
memcpy((( void* )(ctx->lexeme_buffer)),(( void* )(&source->content[(ctx->start+ start_offset)])),(( u64)(str_len))) ;
#line 86 "src/lexer.z"
ctx->lexeme_buffer[str_len] = 0;
;
#line 87 "src/lexer.z"
_ZN7session7SessionE*  sess = ctx->sess;
;
#line 88 "src/lexer.z"
_ZN9interning3SidE sid = _ZN9interning6internE(&sess->interner,ctx->lexeme_buffer) ;
;
#line 90 "src/lexer.z"
return sid;
;
}
#line 93 "src/lexer.z"
 void _ZN5lexer19single_line_commentE(_ZN5lexer13LexingContextE*  ctx) {
#line 94 "src/lexer.z"
while ( ((_ZN5lexer10peek_tokenE(ctx,(( u32)(0))) != '\n')&& !_ZN5lexer14is_done_lexingE(ctx) ))
{
#line 94 "src/lexer.z"
_ZN5lexer7advanceE(ctx) ;
}
;
}
#line 97 "src/lexer.z"
_ZN6tokens9TokenKindE _ZN5lexer10is_keywordE( char*  s) {
#line 100 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("break"))) ))){
#line 100 "src/lexer.z"
return TokenKind_Break;
;
}
;
#line 101 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("cast"))) ))){
#line 101 "src/lexer.z"
return TokenKind_Cast;
;
}
;
#line 102 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("continue"))) ))){
#line 102 "src/lexer.z"
return TokenKind_Continue;
;
}
;
#line 103 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("const"))) ))){
#line 103 "src/lexer.z"
return TokenKind_Continue;
;
}
;
#line 104 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("defer"))) ))){
#line 104 "src/lexer.z"
return TokenKind_Defer;
;
}
;
#line 105 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("enum"))) ))){
#line 105 "src/lexer.z"
return TokenKind_Enum;
;
}
;
#line 106 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("extern"))) ))){
#line 106 "src/lexer.z"
return TokenKind_Extern;
;
}
;
#line 107 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("else"))) ))){
#line 107 "src/lexer.z"
return TokenKind_Else;
;
}
;
#line 108 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("false"))) ))){
#line 108 "src/lexer.z"
return TokenKind_False;
;
}
;
#line 109 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("fn"))) ))){
#line 109 "src/lexer.z"
return TokenKind_Fn;
;
}
;
#line 110 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("for"))) ))){
#line 110 "src/lexer.z"
return TokenKind_For;
;
}
;
#line 111 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("if"))) ))){
#line 111 "src/lexer.z"
return TokenKind_If;
;
}
;
#line 112 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("mod"))) ))){
#line 112 "src/lexer.z"
return TokenKind_Mod;
;
}
;
#line 113 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("return"))) ))){
#line 113 "src/lexer.z"
return TokenKind_Return;
;
}
;
#line 114 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("struct"))) ))){
#line 114 "src/lexer.z"
return TokenKind_Struct;
;
}
;
#line 115 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("sizeof"))) ))){
#line 115 "src/lexer.z"
return TokenKind_Sizeof;
;
}
;
#line 116 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("true"))) ))){
#line 116 "src/lexer.z"
return TokenKind_True;
;
}
;
#line 117 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("union"))) ))){
#line 117 "src/lexer.z"
return TokenKind_Union;
;
}
;
#line 118 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("use"))) ))){
#line 118 "src/lexer.z"
return TokenKind_Use;
;
}
;
#line 119 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("var"))) ))){
#line 119 "src/lexer.z"
return TokenKind_Var;
;
}
;
#line 120 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("val"))) ))){
#line 120 "src/lexer.z"
return TokenKind_Val;
;
}
;
#line 121 "src/lexer.z"
if (!(( bool)(strcmp((( char* )(s)),(( char* )("while"))) ))){
#line 121 "src/lexer.z"
return TokenKind_While;
;
}
;
#line 122 "src/lexer.z"
return TokenKind_Invalid;
;
}
#line 125 "src/lexer.z"
 void _ZN5lexer8lex_charE(_ZN5lexer13LexingContextE*  ctx) {
#line 127 "src/lexer.z"
_ZN10source_map10SourceFileE*  source = ctx->source;
;
#line 128 "src/lexer.z"
 u32 start_line = ((( i32)(source->num_lines))+ 1);
;
#line 130 "src/lexer.z"
while ( (((_ZN5lexer10peek_tokenE(ctx,(( u32)(0))) != '\'')|| ((_ZN5lexer10peek_tokenE(ctx,(( u32)(-1))) == '\\')&& (_ZN5lexer10peek_tokenE(ctx,(( u32)(-2))) != '\\')))&& !_ZN5lexer14is_done_lexingE(ctx) ))
{
#line 131 "src/lexer.z"
 char c = _ZN5lexer7advanceE(ctx) ;
;
#line 132 "src/lexer.z"
if ((c== '\n')){
#line 132 "src/lexer.z"
_ZN5lexer12read_newlineE(ctx) ;
}
;
}
;
#line 135 "src/lexer.z"
if (_ZN5lexer14is_done_lexingE(ctx) ){
#line 136 "src/lexer.z"
printf((( char* )("Unterminated char starting on line %u\n")),start_line) ;
#line 137 "src/lexer.z"
abort() ;
}
;
#line 141 "src/lexer.z"
_ZN5lexer7advanceE(ctx) ;
#line 143 "src/lexer.z"
_ZN5lexer9add_tokenE(ctx,TokenKind_Char,_ZN5lexer10get_lexemeE(ctx,(( u32)(1)),(( u32)(1))) ) ;
}
#line 146 "src/lexer.z"
 void _ZN5lexer10lex_stringE(_ZN5lexer13LexingContextE*  ctx) {
#line 148 "src/lexer.z"
_ZN10source_map10SourceFileE*  source = ctx->source;
;
#line 150 "src/lexer.z"
 u32 start_line = ((( i32)(source->num_lines))+ 1);
;
#line 152 "src/lexer.z"
while ( (((_ZN5lexer10peek_tokenE(ctx,(( u32)(0))) != '"')|| ((_ZN5lexer10peek_tokenE(ctx,(( u32)(-1))) == '\\')&& (_ZN5lexer10peek_tokenE(ctx,(( u32)(-2))) != '\\')))&& !_ZN5lexer14is_done_lexingE(ctx) ))
{
#line 153 "src/lexer.z"
 char c = _ZN5lexer7advanceE(ctx) ;
;
#line 154 "src/lexer.z"
if ((c== '\n')){
#line 154 "src/lexer.z"
_ZN5lexer12read_newlineE(ctx) ;
}
;
}
;
#line 157 "src/lexer.z"
if (_ZN5lexer14is_done_lexingE(ctx) ){
#line 158 "src/lexer.z"
printf((( char* )("Unterminated string starting on line %u\n")),start_line) ;
#line 159 "src/lexer.z"
abort() ;
}
;
#line 163 "src/lexer.z"
_ZN5lexer7advanceE(ctx) ;
#line 165 "src/lexer.z"
_ZN5lexer9add_tokenE(ctx,TokenKind_String,_ZN5lexer10get_lexemeE(ctx,(( u32)(1)),(( u32)(1))) ) ;
}
#line 168 "src/lexer.z"
 void _ZN5lexer10lex_numberE(_ZN5lexer13LexingContextE*  ctx) {
#line 170 "src/lexer.z"
while ( _ZN5lexer8is_digitE(_ZN5lexer10peek_tokenE(ctx,(( u32)(0))) ) )
{
#line 170 "src/lexer.z"
_ZN5lexer7advanceE(ctx) ;
}
;
#line 171 "src/lexer.z"
 bool dot_encountered = false;
;
#line 172 "src/lexer.z"
if (((_ZN5lexer10peek_tokenE(ctx,(( u32)(0))) == '.')&& _ZN5lexer8is_digitE(_ZN5lexer10peek_tokenE(ctx,(( u32)(1))) ) )){
#line 173 "src/lexer.z"
dot_encountered = true;
;
#line 174 "src/lexer.z"
_ZN5lexer7advanceE(ctx) ;
#line 175 "src/lexer.z"
while ( _ZN5lexer8is_digitE(_ZN5lexer10peek_tokenE(ctx,(( u32)(0))) ) )
{
#line 175 "src/lexer.z"
_ZN5lexer7advanceE(ctx) ;
}
;
}
;
#line 178 "src/lexer.z"
_ZN6tokens9TokenKindE t ;
;
#line 179 "src/lexer.z"
if (dot_encountered){
#line 179 "src/lexer.z"
t = TokenKind_Float;
;
}
else {
#line 180 "src/lexer.z"
t = TokenKind_Integer;
;
}
;
#line 182 "src/lexer.z"
_ZN5lexer9add_tokenE(ctx,t,_ZN5lexer10get_lexemeE(ctx,(( u32)(0)),(( u32)(0))) ) ;
}
#line 185 "src/lexer.z"
 void _ZN5lexer14lex_identifierE(_ZN5lexer13LexingContextE*  ctx) {
#line 186 "src/lexer.z"
while ( (_ZN5lexer15is_alphanumericE(_ZN5lexer10peek_tokenE(ctx,(( u32)(0))) ) || (_ZN5lexer10peek_tokenE(ctx,(( u32)(0))) == '_')))
{
#line 186 "src/lexer.z"
_ZN5lexer7advanceE(ctx) ;
}
;
#line 188 "src/lexer.z"
_ZN9interning3SidE lexeme = _ZN5lexer10get_lexemeE(ctx,(( u32)(0)),(( u32)(0))) ;
;
#line 190 "src/lexer.z"
_ZN7session7SessionE*  sess = ctx->sess;
;
#line 191 "src/lexer.z"
 char*  lexeme_str = _ZN9interning7get_strE(&sess->interner,lexeme) ;
;
#line 192 "src/lexer.z"
_ZN6tokens9TokenKindE keyword = _ZN5lexer10is_keywordE(lexeme_str) ;
;
#line 193 "src/lexer.z"
if ((keyword!= TokenKind_Invalid)){
#line 193 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,keyword) ;
}
else {
#line 194 "src/lexer.z"
_ZN5lexer9add_tokenE(ctx,TokenKind_Identifier,lexeme) ;
}
;
}
#line 197 "src/lexer.z"
 void _ZN5lexer10scan_tokenE(_ZN5lexer13LexingContextE*  ctx) {
#line 198 "src/lexer.z"
 char c = _ZN5lexer7advanceE(ctx) ;
;
#line 202 "src/lexer.z"
if ((c== '(')){
#line 202 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_LeftParen) ;
}
else {
#line 203 "src/lexer.z"
if ((c== ')')){
#line 203 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_RightParen) ;
}
else {
#line 204 "src/lexer.z"
if ((c== '[')){
#line 204 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_LeftBracket) ;
}
else {
#line 205 "src/lexer.z"
if ((c== ']')){
#line 205 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_RightBracket) ;
}
else {
#line 206 "src/lexer.z"
if ((c== '{')){
#line 206 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_LeftCurly) ;
}
else {
#line 207 "src/lexer.z"
if ((c== '}')){
#line 207 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_RightCurly) ;
}
else {
#line 208 "src/lexer.z"
if ((c== '+')){
#line 208 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_Plus) ;
}
else {
#line 209 "src/lexer.z"
if ((c== '*')){
#line 209 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_Star) ;
}
else {
#line 210 "src/lexer.z"
if ((c== '%')){
#line 210 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_Percent) ;
}
else {
#line 211 "src/lexer.z"
if ((c== '^')){
#line 211 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_Hat) ;
}
else {
#line 212 "src/lexer.z"
if ((c== ';')){
#line 212 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_Semicolon) ;
}
else {
#line 213 "src/lexer.z"
if ((c== ',')){
#line 213 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_Comma) ;
}
else {
#line 214 "src/lexer.z"
if ((c== '-')){
#line 214 "src/lexer.z"
_ZN5lexer31add_lookahead_conditional_tokenE(ctx,'>',TokenKind_Arrow,TokenKind_Minus) ;
}
else {
#line 215 "src/lexer.z"
if ((c== ':')){
#line 215 "src/lexer.z"
_ZN5lexer31add_lookahead_conditional_tokenE(ctx,':',TokenKind_ColonColon,TokenKind_Colon) ;
}
else {
#line 216 "src/lexer.z"
if ((c== '=')){
#line 216 "src/lexer.z"
_ZN5lexer31add_lookahead_conditional_tokenE(ctx,'=',TokenKind_EqualEqual,TokenKind_Equal) ;
}
else {
#line 217 "src/lexer.z"
if ((c== '!')){
#line 217 "src/lexer.z"
_ZN5lexer31add_lookahead_conditional_tokenE(ctx,'=',TokenKind_BangEqual,TokenKind_Bang) ;
}
else {
#line 218 "src/lexer.z"
if ((c== '&')){
#line 218 "src/lexer.z"
_ZN5lexer31add_lookahead_conditional_tokenE(ctx,'&',TokenKind_AndAnd,TokenKind_And) ;
}
else {
#line 219 "src/lexer.z"
if ((c== '|')){
#line 219 "src/lexer.z"
_ZN5lexer31add_lookahead_conditional_tokenE(ctx,'|',TokenKind_OrOr,TokenKind_Or) ;
}
else {
#line 220 "src/lexer.z"
if ((c== '.')){
#line 221 "src/lexer.z"
if (((_ZN5lexer10peek_tokenE(ctx,(( u32)(0))) == '.')&& (_ZN5lexer10peek_tokenE(ctx,(( u32)(1))) == '.'))){
#line 222 "src/lexer.z"
_ZN5lexer7advanceE(ctx) ;
#line 222 "src/lexer.z"
_ZN5lexer7advanceE(ctx) ;
#line 223 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_Ellipsis) ;
}
else {
#line 225 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_Dot) ;
}
;
}
else {
#line 227 "src/lexer.z"
if ((c== '<')){
#line 228 "src/lexer.z"
 char n1 = _ZN5lexer10peek_tokenE(ctx,(( u32)(0))) ;
;
#line 229 "src/lexer.z"
if ((n1== '<')){
#line 229 "src/lexer.z"
_ZN5lexer7advanceE(ctx) ;
#line 229 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_LessLess) ;
}
else {
#line 230 "src/lexer.z"
if ((n1== '=')){
#line 230 "src/lexer.z"
_ZN5lexer7advanceE(ctx) ;
#line 230 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_LessEqual) ;
}
else {
#line 231 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_Less) ;
}
;
}
;
}
else {
#line 233 "src/lexer.z"
if ((c== '>')){
#line 234 "src/lexer.z"
 char n2 = _ZN5lexer10peek_tokenE(ctx,(( u32)(0))) ;
;
#line 235 "src/lexer.z"
if ((n2== '>')){
#line 235 "src/lexer.z"
_ZN5lexer7advanceE(ctx) ;
#line 235 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_GreaterGreater) ;
}
else {
#line 236 "src/lexer.z"
if ((n2== '=')){
#line 236 "src/lexer.z"
_ZN5lexer7advanceE(ctx) ;
#line 236 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_GreaterEqual) ;
}
else {
#line 237 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_Greater) ;
}
;
}
;
}
else {
#line 239 "src/lexer.z"
if ((c== '/')){
#line 240 "src/lexer.z"
if ((_ZN5lexer10peek_tokenE(ctx,(( u32)(0))) == '/')){
#line 240 "src/lexer.z"
_ZN5lexer19single_line_commentE(ctx) ;
}
else {
#line 241 "src/lexer.z"
_ZN5lexer16add_simple_tokenE(ctx,TokenKind_Slash) ;
}
;
}
else {
#line 243 "src/lexer.z"
if ((((c== ' ')|| (c== '\t'))|| (c== '\r'))){
}
else {
#line 244 "src/lexer.z"
if ((c== '\n')){
#line 244 "src/lexer.z"
_ZN5lexer12read_newlineE(ctx) ;
}
else {
#line 245 "src/lexer.z"
if ((c== '"')){
#line 245 "src/lexer.z"
_ZN5lexer10lex_stringE(ctx) ;
}
else {
#line 246 "src/lexer.z"
if ((c== '\'')){
#line 246 "src/lexer.z"
_ZN5lexer8lex_charE(ctx) ;
}
else {
#line 248 "src/lexer.z"
if (_ZN5lexer8is_digitE(c) ){
#line 248 "src/lexer.z"
_ZN5lexer10lex_numberE(ctx) ;
}
else {
#line 249 "src/lexer.z"
if ((_ZN5lexer13is_alphabeticE(c) || (c== '_'))){
#line 249 "src/lexer.z"
_ZN5lexer14lex_identifierE(ctx) ;
}
else {
#line 251 "src/lexer.z"
_ZN10source_map10SourceFileE*  source = ctx->source;
;
#line 252 "src/lexer.z"
printf((( char* )("Unexpected character %c = %d on line %u\n")),c,c,source->num_lines) ;
#line 253 "src/lexer.z"
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
#line 258 "src/lexer.z"
_ZN6tokens5TokenE*  _ZN5lexer3lexE(_ZN7session7SessionE*  sess, _ZN10source_map10SourceFileE*  source,  u32*  num_tokens) {
#line 260 "src/lexer.z"
_ZN5lexer13LexingContextE*  ctx = malloc(sizeof(_ZN5lexer13LexingContextE)) ;
;
#line 261 "src/lexer.z"
ctx->source = source;
;
#line 262 "src/lexer.z"
ctx->file_span_offset = source->start;
;
#line 263 "src/lexer.z"
ctx->start = 0;
;
#line 264 "src/lexer.z"
ctx->current = 0;
;
#line 265 "src/lexer.z"
ctx->tokens = malloc((sizeof(_ZN6tokens5TokenE)* (( u64)(10000)))) ;
;
#line 266 "src/lexer.z"
ctx->current_token_idx = 0;
;
#line 267 "src/lexer.z"
ctx->sess = sess;
;
#line 269 "src/lexer.z"
ctx->lexeme_buffer = malloc((( u64)(1024))) ;
;
#line 271 "src/lexer.z"
while ( !_ZN5lexer14is_done_lexingE(ctx) )
{
#line 272 "src/lexer.z"
ctx->start = ctx->current;
;
#line 273 "src/lexer.z"
_ZN5lexer10scan_tokenE(ctx) ;
}
;
#line 276 "src/lexer.z"
_ZN10source_map16source_file_doneE(source,ctx->current) ;
#line 278 "src/lexer.z"
if (((( i32)(ctx->current_token_idx))> 10000)){
#line 279 "src/lexer.z"
printf((( char* )("Lexer token overflow: %u!\n")),ctx->current_token_idx) ;
#line 280 "src/lexer.z"
abort() ;
}
;
#line 283 "src/lexer.z"
*num_tokens = ctx->current_token_idx;
;
#line 284 "src/lexer.z"
return ctx->tokens;
;
}
#line 27 "src/ast.z"
 u32 _ZN3ast12integer_sizeE(_ZN3ast11IntegerSizeE size) {
#line 28 "src/ast.z"
if ((size== IntegerSize_I8)){
#line 28 "src/ast.z"
return 8;
;
}
else {
#line 29 "src/ast.z"
if ((size== IntegerSize_I16)){
#line 29 "src/ast.z"
return 16;
;
}
else {
#line 30 "src/ast.z"
if ((size== IntegerSize_I32)){
#line 30 "src/ast.z"
return 32;
;
}
else {
#line 31 "src/ast.z"
if ((size== IntegerSize_I64)){
#line 31 "src/ast.z"
return 64;
;
}
else {
#line 32 "src/ast.z"
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
#line 41 "src/ast.z"
 u32 _ZN3ast13floating_sizeE(_ZN3ast12FloatingSizeE size) {
#line 42 "src/ast.z"
if ((size== FloatingSize_F32)){
#line 42 "src/ast.z"
return 32;
;
}
else {
#line 43 "src/ast.z"
if ((size== FloatingSize_F64)){
#line 43 "src/ast.z"
return 64;
;
}
else {
#line 44 "src/ast.z"
abort() ;
}
;
}
;
}
#line 461 "src/ast.z"
_ZN3ast4ExprE*  _ZN3ast11create_exprE(_ZN3ast8ExprKindE kind) {
#line 462 "src/ast.z"
_ZN3ast4ExprE*  expr = malloc(sizeof(_ZN3ast4ExprE)) ;
;
#line 463 "src/ast.z"
expr->kind = kind;
;
#line 464 "src/ast.z"
return expr;
;
}
#line 22 "src/parser.z"
 bool _ZN6parser15is_done_parsingE(_ZN6parser14ParsingContextE*  ctx) {
#line 23 "src/parser.z"
return (ctx->num_tokens== ctx->current_token);
;
}
#line 26 "src/parser.z"
 bool _ZN6parser6acceptE(_ZN6parser14ParsingContextE*  ctx, _ZN6tokens9TokenKindE token) {
#line 27 "src/parser.z"
_ZN6tokens5TokenE tok = ctx->tokens[ctx->current_token];
;
#line 28 "src/parser.z"
if ((!_ZN6parser15is_done_parsingE(ctx) && (tok.kind== token))){
#line 29 "src/parser.z"
ctx->current_token = (ctx->current_token+ (( u64)(1)));
;
#line 30 "src/parser.z"
return true;
;
}
;
#line 32 "src/parser.z"
return false;
;
}
#line 35 "src/parser.z"
 bool _ZN6parser10can_acceptE(_ZN6parser14ParsingContextE*  ctx, _ZN6tokens9TokenKindE token) {
#line 36 "src/parser.z"
_ZN6tokens5TokenE tok = ctx->tokens[ctx->current_token];
;
#line 37 "src/parser.z"
if ((!_ZN6parser15is_done_parsingE(ctx) && (tok.kind== token))){
#line 38 "src/parser.z"
return true;
;
}
;
#line 40 "src/parser.z"
return false;
;
}
#line 43 "src/parser.z"
_ZN6tokens5TokenE _ZN6parser10look_aheadE(_ZN6parser14ParsingContextE*  ctx,  u64 offset) {
#line 44 "src/parser.z"
if ((ctx->current_token== ctx->num_tokens)){
#line 45 "src/parser.z"
_ZN6tokens5TokenE eof_tok ;
;
#line 46 "src/parser.z"
eof_tok.kind = _ZN4cstd3EOFE;
;
#line 47 "src/parser.z"
return eof_tok;
;
}
else {
#line 48 "src/parser.z"
return ctx->tokens[(ctx->current_token+ offset)];
;
}
;
}
#line 51 "src/parser.z"
_ZN6tokens5TokenE _ZN6parser7consumeE(_ZN6parser14ParsingContextE*  ctx) {
#line 52 "src/parser.z"
ctx->current_token = (ctx->current_token+ (( u64)(1)));
;
#line 53 "src/parser.z"
return ctx->tokens[(ctx->current_token- (( u64)(1)))];
;
}
#line 56 "src/parser.z"
_ZN6tokens5TokenE _ZN6parser6expectE(_ZN6parser14ParsingContextE*  ctx, _ZN6tokens9TokenKindE kind) {
#line 57 "src/parser.z"
_ZN6tokens5TokenE tok = _ZN6parser7consumeE(ctx) ;
;
#line 58 "src/parser.z"
if ((tok.kind== kind)){
#line 59 "src/parser.z"
return tok;
;
}
else {
#line 61 "src/parser.z"
_ZN5error10emit_errorE(ctx->source_map,tok.span,"Expect failed!") ;
#line 62 "src/parser.z"
abort() ;
}
;
}
#line 66 "src/parser.z"
 u32 _ZN6parser10span_startE(_ZN6parser14ParsingContextE*  ctx) {
#line 67 "src/parser.z"
return ctx->tokens[ctx->current_token].span.from;
;
}
#line 70 "src/parser.z"
 u32 _ZN6parser8span_endE(_ZN6parser14ParsingContextE*  ctx) {
#line 71 "src/parser.z"
return ctx->tokens[(ctx->current_token- (( u64)(1)))].span.to;
;
}
#line 74 "src/parser.z"
_ZN3ast5IdentE _ZN6parser16parse_identifierE(_ZN6parser14ParsingContextE*  ctx) {
#line 76 "src/parser.z"
_ZN3ast5IdentE ident ;
;
#line 77 "src/parser.z"
ident.span.from = _ZN6parser10span_startE(ctx) ;
;
#line 78 "src/parser.z"
_ZN6tokens5TokenE tok = _ZN6parser7consumeE(ctx) ;
;
#line 80 "src/parser.z"
if ((tok.kind!= TokenKind_Identifier)){
#line 80 "src/parser.z"
_ZN5error10emit_errorE(ctx->source_map,tok.span,"Invalid identifier") ;
}
;
#line 82 "src/parser.z"
ident.name = tok.lexeme;
;
#line 83 "src/parser.z"
ident.span.to = _ZN6parser8span_endE(ctx) ;
;
#line 85 "src/parser.z"
return ident;
;
}
#line 88 "src/parser.z"
_ZN3ast4PathE _ZN6parser10parse_pathE(_ZN6parser14ParsingContextE*  ctx) {
#line 89 "src/parser.z"
_ZN3ast4PathE path ;
;
#line 90 "src/parser.z"
path.segments = malloc((sizeof(_ZN3ast5IdentE)* (( u64)(6)))) ;
;
#line 91 "src/parser.z"
path.num_segments = 0;
;
#line 92 "src/parser.z"
path.span.from = _ZN6parser10span_startE(ctx) ;
;
#line 94 "src/parser.z"
while ( true)
{
#line 95 "src/parser.z"
if (_ZN6parser6acceptE(ctx,TokenKind_Star) ){
#line 95 "src/parser.z"
break;
;
}
;
#line 97 "src/parser.z"
path.segments[path.num_segments] = _ZN6parser16parse_identifierE(ctx) ;
;
#line 98 "src/parser.z"
if (((path.segments[path.num_segments].name.x== _ZN9interning6internE(ctx->interner,"self") .x)|| (path.segments[path.num_segments].name.x== _ZN9interning6internE(ctx->interner,"super") .x))){
}
else {
#line 99 "src/parser.z"
path.num_segments = ((( i32)(path.num_segments))+ 1);
;
}
;
#line 101 "src/parser.z"
if (!_ZN6parser6acceptE(ctx,TokenKind_ColonColon) ){
#line 101 "src/parser.z"
break;
;
}
;
}
;
#line 104 "src/parser.z"
path.span.to = _ZN6parser8span_endE(ctx) ;
;
#line 105 "src/parser.z"
return path;
;
}
#line 108 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser15parse_path_exprE(_ZN6parser14ParsingContextE*  ctx) {
#line 109 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_Path) ;
;
#line 110 "src/parser.z"
expr->node.path = _ZN6parser10parse_pathE(ctx) ;
;
#line 111 "src/parser.z"
return expr;
;
}
#line 114 "src/parser.z"
_ZN3ast7PatternE _ZN6parser13parse_patternE(_ZN6parser14ParsingContextE*  ctx) {
#line 115 "src/parser.z"
_ZN3ast7PatternE pat ;
;
#line 116 "src/parser.z"
pat.span.from = _ZN6parser10span_startE(ctx) ;
;
#line 117 "src/parser.z"
pat.ident = _ZN6parser16parse_identifierE(ctx) ;
;
#line 118 "src/parser.z"
pat.span.to = _ZN6parser8span_endE(ctx) ;
;
#line 119 "src/parser.z"
return pat;
;
}
#line 122 "src/parser.z"
_ZN3ast7AstTypeE*  _ZN6parser10parse_typeE(_ZN6parser14ParsingContextE*  ctx) {
#line 123 "src/parser.z"
_ZN3ast15AstTypeKindNodeE node ;
;
#line 124 "src/parser.z"
_ZN3ast11AstTypeKindE kind ;
;
#line 126 "src/parser.z"
_ZN6tokens5TokenE token = _ZN6parser10look_aheadE(ctx,(( u64)(0))) ;
;
#line 127 "src/parser.z"
if ((token.kind== TokenKind_Identifier)){
#line 128 "src/parser.z"
kind = AstTypeKind_Path;
;
#line 129 "src/parser.z"
node.path = _ZN6parser10parse_pathE(ctx) ;
;
}
else {
#line 130 "src/parser.z"
if ((token.kind== TokenKind_Star)){
#line 131 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_Star) ;
#line 132 "src/parser.z"
kind = AstTypeKind_Ptr;
;
#line 133 "src/parser.z"
node.ptr = _ZN6parser10parse_typeE(ctx) ;
;
}
else {
#line 134 "src/parser.z"
if ((token.kind== TokenKind_Ellipsis)){
#line 135 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_Ellipsis) ;
#line 136 "src/parser.z"
kind = AstTypeKind_Variadic;
;
}
else {
#line 138 "src/parser.z"
_ZN5error10emit_errorE(ctx->source_map,token.span,"Expected type") ;
}
;
}
;
}
;
#line 140 "src/parser.z"
_ZN3ast7AstTypeE*  type = malloc(sizeof(_ZN3ast7AstTypeE)) ;
;
#line 141 "src/parser.z"
type->kind = kind;
;
#line 142 "src/parser.z"
type->node = node;
;
#line 144 "src/parser.z"
return type;
;
}
#line 147 "src/parser.z"
_ZN3ast18BinaryOperatorKindE _ZN6parser32convert_token_to_binary_operatorE(_ZN6tokens9TokenKindE tok) {
#line 148 "src/parser.z"
if ((tok== TokenKind_Plus)){
#line 148 "src/parser.z"
return BinaryOperatorKind_Addition;
;
}
else {
#line 149 "src/parser.z"
if ((tok== TokenKind_Minus)){
#line 149 "src/parser.z"
return BinaryOperatorKind_Subtraction;
;
}
else {
#line 150 "src/parser.z"
if ((tok== TokenKind_Star)){
#line 150 "src/parser.z"
return BinaryOperatorKind_Product;
;
}
else {
#line 151 "src/parser.z"
if ((tok== TokenKind_Slash)){
#line 151 "src/parser.z"
return BinaryOperatorKind_Division;
;
}
else {
#line 152 "src/parser.z"
if ((tok== TokenKind_Percent)){
#line 152 "src/parser.z"
return BinaryOperatorKind_Modulus;
;
}
else {
#line 153 "src/parser.z"
if ((tok== TokenKind_Less)){
#line 153 "src/parser.z"
return BinaryOperatorKind_Less;
;
}
else {
#line 154 "src/parser.z"
if ((tok== TokenKind_LessEqual)){
#line 154 "src/parser.z"
return BinaryOperatorKind_LessEq;
;
}
else {
#line 155 "src/parser.z"
if ((tok== TokenKind_Greater)){
#line 155 "src/parser.z"
return BinaryOperatorKind_Greater;
;
}
else {
#line 156 "src/parser.z"
if ((tok== TokenKind_GreaterEqual)){
#line 156 "src/parser.z"
return BinaryOperatorKind_GreaterEq;
;
}
else {
#line 157 "src/parser.z"
if ((tok== TokenKind_EqualEqual)){
#line 157 "src/parser.z"
return BinaryOperatorKind_Equality;
;
}
else {
#line 158 "src/parser.z"
if ((tok== TokenKind_BangEqual)){
#line 158 "src/parser.z"
return BinaryOperatorKind_NotEq;
;
}
else {
#line 159 "src/parser.z"
if ((tok== TokenKind_AndAnd)){
#line 159 "src/parser.z"
return BinaryOperatorKind_And;
;
}
else {
#line 160 "src/parser.z"
if ((tok== TokenKind_OrOr)){
#line 160 "src/parser.z"
return BinaryOperatorKind_Or;
;
}
else {
#line 161 "src/parser.z"
if ((tok== TokenKind_And)){
#line 161 "src/parser.z"
return BinaryOperatorKind_BAnd;
;
}
else {
#line 162 "src/parser.z"
if ((tok== TokenKind_Or)){
#line 162 "src/parser.z"
return BinaryOperatorKind_BOr;
;
}
else {
#line 163 "src/parser.z"
if ((tok== TokenKind_Hat)){
#line 163 "src/parser.z"
return BinaryOperatorKind_Xor;
;
}
else {
#line 164 "src/parser.z"
if ((tok== TokenKind_LessLess)){
#line 164 "src/parser.z"
return BinaryOperatorKind_LeftShift;
;
}
else {
#line 165 "src/parser.z"
if ((tok== TokenKind_GreaterGreater)){
#line 165 "src/parser.z"
return BinaryOperatorKind_RightShift;
;
}
else {
#line 166 "src/parser.z"
return BinaryOperatorKind_Invalid;
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
#line 169 "src/parser.z"
 u32 _ZN6parser30get_binary_operator_precedenceE(_ZN3ast18BinaryOperatorKindE op) {
#line 170 "src/parser.z"
if ((op== BinaryOperatorKind_Product)){
#line 170 "src/parser.z"
return 10;
;
}
else {
#line 171 "src/parser.z"
if ((op== BinaryOperatorKind_Division)){
#line 171 "src/parser.z"
return 10;
;
}
else {
#line 172 "src/parser.z"
if ((op== BinaryOperatorKind_Modulus)){
#line 172 "src/parser.z"
return 10;
;
}
else {
#line 173 "src/parser.z"
if ((op== BinaryOperatorKind_Addition)){
#line 173 "src/parser.z"
return 9;
;
}
else {
#line 174 "src/parser.z"
if ((op== BinaryOperatorKind_Subtraction)){
#line 174 "src/parser.z"
return 9;
;
}
else {
#line 175 "src/parser.z"
if ((op== BinaryOperatorKind_LeftShift)){
#line 175 "src/parser.z"
return 8;
;
}
else {
#line 176 "src/parser.z"
if ((op== BinaryOperatorKind_RightShift)){
#line 176 "src/parser.z"
return 8;
;
}
else {
#line 177 "src/parser.z"
if ((op== BinaryOperatorKind_BAnd)){
#line 177 "src/parser.z"
return 7;
;
}
else {
#line 178 "src/parser.z"
if ((op== BinaryOperatorKind_Xor)){
#line 178 "src/parser.z"
return 6;
;
}
else {
#line 179 "src/parser.z"
if ((op== BinaryOperatorKind_BOr)){
#line 179 "src/parser.z"
return 5;
;
}
else {
#line 180 "src/parser.z"
if ((op== BinaryOperatorKind_Less)){
#line 180 "src/parser.z"
return 4;
;
}
else {
#line 181 "src/parser.z"
if ((op== BinaryOperatorKind_LessEq)){
#line 181 "src/parser.z"
return 4;
;
}
else {
#line 182 "src/parser.z"
if ((op== BinaryOperatorKind_Greater)){
#line 182 "src/parser.z"
return 4;
;
}
else {
#line 183 "src/parser.z"
if ((op== BinaryOperatorKind_GreaterEq)){
#line 183 "src/parser.z"
return 4;
;
}
else {
#line 184 "src/parser.z"
if ((op== BinaryOperatorKind_Equality)){
#line 184 "src/parser.z"
return 4;
;
}
else {
#line 185 "src/parser.z"
if ((op== BinaryOperatorKind_NotEq)){
#line 185 "src/parser.z"
return 4;
;
}
else {
#line 186 "src/parser.z"
if ((op== BinaryOperatorKind_And)){
#line 186 "src/parser.z"
return 3;
;
}
else {
#line 187 "src/parser.z"
if ((op== BinaryOperatorKind_Or)){
#line 187 "src/parser.z"
return 2;
;
}
else {
#line 188 "src/parser.z"
return 0;
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
#line 191 "src/parser.z"
 u32 _ZN6parser22get_current_precedenceE(_ZN6parser14ParsingContextE*  ctx) {
#line 193 "src/parser.z"
if ((ctx->num_tokens<= ctx->current_token)){
#line 194 "src/parser.z"
return 0;
;
}
else {
#line 196 "src/parser.z"
_ZN6tokens5TokenE tok = ctx->tokens[ctx->current_token];
;
#line 197 "src/parser.z"
 u32 op_precedence = _ZN6parser30get_binary_operator_precedenceE(_ZN6parser32convert_token_to_binary_operatorE(tok.kind) ) ;
;
#line 198 "src/parser.z"
if (((( i32)(op_precedence))> 0)){
#line 198 "src/parser.z"
return op_precedence;
;
}
else {
#line 199 "src/parser.z"
if ((tok.kind== TokenKind_Dot)){
#line 199 "src/parser.z"
return 13;
;
}
else {
#line 200 "src/parser.z"
if (((tok.kind== TokenKind_LeftBracket)|| (tok.kind== TokenKind_LeftParen))){
#line 200 "src/parser.z"
return 12;
;
}
else {
#line 201 "src/parser.z"
if ((tok.kind== TokenKind_Equal)){
#line 201 "src/parser.z"
return 1;
;
}
else {
#line 202 "src/parser.z"
return 0;
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
#line 206 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser16parse_expressionE(_ZN6parser14ParsingContextE*  ctx,  u32 precedence) ;
#line 208 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser21parse_integer_literalE(_ZN6parser14ParsingContextE*  ctx) {
#line 210 "src/parser.z"
_ZN6tokens5TokenE tok = _ZN6parser6expectE(ctx,TokenKind_Integer) ;
;
#line 212 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_Literal) ;
;
#line 213 "src/parser.z"
expr->node.lit.kind = LiteralKind_Int;
;
#line 215 "src/parser.z"
_ZN7session7SessionE*  sess = ctx->sess;
;
#line 216 "src/parser.z"
expr->node.lit.value.integer = atol((( char* )(_ZN9interning7get_strE(&sess->interner,tok.lexeme) ))) ;
;
#line 217 "src/parser.z"
return expr;
;
}
#line 220 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser19parse_float_literalE(_ZN6parser14ParsingContextE*  ctx) {
#line 222 "src/parser.z"
_ZN6tokens5TokenE tok = _ZN6parser6expectE(ctx,TokenKind_Float) ;
;
#line 224 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_Literal) ;
;
#line 225 "src/parser.z"
expr->node.lit.kind = LiteralKind_Float;
;
#line 227 "src/parser.z"
_ZN7session7SessionE*  sess = ctx->sess;
;
#line 228 "src/parser.z"
expr->node.lit.value.floating = atof((( char* )(_ZN9interning7get_strE(&sess->interner,tok.lexeme) ))) ;
;
#line 229 "src/parser.z"
return expr;
;
}
#line 232 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser18parse_char_literalE(_ZN6parser14ParsingContextE*  ctx) {
#line 234 "src/parser.z"
_ZN6tokens5TokenE tok = _ZN6parser6expectE(ctx,TokenKind_Char) ;
;
#line 236 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_Literal) ;
;
#line 237 "src/parser.z"
expr->node.lit.kind = LiteralKind_Char;
;
#line 239 "src/parser.z"
_ZN7session7SessionE*  sess = ctx->sess;
;
#line 240 "src/parser.z"
 char*  s = _ZN9interning7get_strE(&sess->interner,tok.lexeme) ;
;
#line 242 "src/parser.z"
 u32 len = strlen((( char* )(s))) ;
;
#line 243 "src/parser.z"
if ((((( i32)(len))== 2)&& (s[0]== '\\'))){
#line 244 "src/parser.z"
 char c ;
;
#line 245 "src/parser.z"
if ((s[1]== 'n')){
#line 245 "src/parser.z"
c = '\n';
;
}
else {
#line 246 "src/parser.z"
if ((s[1]== 't')){
#line 246 "src/parser.z"
c = '\t';
;
}
else {
#line 247 "src/parser.z"
if ((s[1]== 'r')){
#line 247 "src/parser.z"
c = '\r';
;
}
else {
#line 248 "src/parser.z"
if ((s[1]== '\\')){
#line 248 "src/parser.z"
c = '\\';
;
}
else {
#line 249 "src/parser.z"
if ((s[1]== '\'')){
#line 249 "src/parser.z"
c = '\'';
;
}
else {
#line 250 "src/parser.z"
_ZN5error10emit_errorE(ctx->source_map,tok.span,"Unknown escape sequence") ;
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
#line 251 "src/parser.z"
expr->node.lit.value.ch = c;
;
}
else {
#line 252 "src/parser.z"
if (((( i32)(len))== 1)){
#line 253 "src/parser.z"
expr->node.lit.value.ch = s[0];
;
}
else {
#line 255 "src/parser.z"
_ZN5error10emit_errorE(ctx->source_map,tok.span,"Invalid char literal") ;
}
;
}
;
#line 257 "src/parser.z"
return expr;
;
}
#line 260 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser20parse_string_literalE(_ZN6parser14ParsingContextE*  ctx) {
#line 262 "src/parser.z"
_ZN6tokens5TokenE tok = _ZN6parser6expectE(ctx,TokenKind_String) ;
;
#line 264 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_Literal) ;
;
#line 265 "src/parser.z"
expr->node.lit.kind = LiteralKind_Str;
;
#line 267 "src/parser.z"
expr->node.lit.value.str = tok.lexeme;
;
#line 268 "src/parser.z"
return expr;
;
}
#line 271 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser18parse_bool_literalE(_ZN6parser14ParsingContextE*  ctx) {
#line 273 "src/parser.z"
_ZN6tokens5TokenE tok = _ZN6parser7consumeE(ctx) ;
;
#line 275 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_Literal) ;
;
#line 276 "src/parser.z"
expr->node.lit.kind = LiteralKind_Bool;
;
#line 277 "src/parser.z"
expr->node.lit.value.boolean = (tok.kind== TokenKind_True);
;
#line 278 "src/parser.z"
return expr;
;
}
#line 281 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser10parse_callE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ExprE*  left) {
#line 283 "src/parser.z"
_ZN3ast4ExprE*  result = _ZN3ast11create_exprE(ExprKind_Call) ;
;
#line 284 "src/parser.z"
result->node.call.func = left;
;
#line 285 "src/parser.z"
result->node.call.args = malloc((( u64)((8* 16)))) ;
;
#line 286 "src/parser.z"
result->node.call.num_args = 0;
;
#line 288 "src/parser.z"
if (!_ZN6parser6acceptE(ctx,TokenKind_RightParen) ){
#line 289 "src/parser.z"
while ( true)
{
#line 290 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN6parser16parse_expressionE(ctx,(( u32)(0))) ;
;
#line 291 "src/parser.z"
result->node.call.args[result->node.call.num_args] = expr;
;
#line 292 "src/parser.z"
result->node.call.num_args = ((( i32)(result->node.call.num_args))+ 1);
;
#line 293 "src/parser.z"
if (!_ZN6parser6acceptE(ctx,TokenKind_Comma) ){
#line 293 "src/parser.z"
break;
;
}
;
}
;
#line 295 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_RightParen) ;
}
;
#line 298 "src/parser.z"
return result;
;
}
#line 302 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser21parse_prefix_operatorE(_ZN6parser14ParsingContextE*  ctx) {
#line 303 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_Unary) ;
;
#line 305 "src/parser.z"
_ZN6tokens5TokenE tok = _ZN6parser7consumeE(ctx) ;
;
#line 307 "src/parser.z"
if ((tok.kind== TokenKind_Minus)){
#line 307 "src/parser.z"
expr->node.unary.op = UnaryOperatorKind_Negation;
;
}
else {
#line 308 "src/parser.z"
if ((tok.kind== TokenKind_Bang)){
#line 308 "src/parser.z"
expr->node.unary.op = UnaryOperatorKind_Complement;
;
}
else {
#line 309 "src/parser.z"
if ((tok.kind== TokenKind_And)){
#line 309 "src/parser.z"
expr->node.unary.op = UnaryOperatorKind_Refer;
;
}
else {
#line 310 "src/parser.z"
if ((tok.kind== TokenKind_Star)){
#line 310 "src/parser.z"
expr->node.unary.op = UnaryOperatorKind_Deref;
;
}
else {
#line 311 "src/parser.z"
_ZN5error10emit_errorE(ctx->source_map,tok.span,"Invalid prefix operator") ;
}
;
}
;
}
;
}
;
#line 313 "src/parser.z"
expr->node.unary.inner = _ZN6parser16parse_expressionE(ctx,(( u32)(11))) ;
;
#line 315 "src/parser.z"
return expr;
;
}
#line 318 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser21parse_binary_operatorE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ExprE*  left, _ZN3ast18BinaryOperatorKindE operator) {
#line 319 "src/parser.z"
 u32 precedence = _ZN6parser30get_binary_operator_precedenceE(operator) ;
;
#line 320 "src/parser.z"
_ZN3ast4ExprE*  right = _ZN6parser16parse_expressionE(ctx,precedence) ;
;
#line 322 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_Binary) ;
;
#line 323 "src/parser.z"
expr->node.binary.op = operator;
;
#line 324 "src/parser.z"
expr->node.binary.left = left;
;
#line 325 "src/parser.z"
expr->node.binary.right = right;
;
#line 327 "src/parser.z"
return expr;
;
}
#line 330 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser18parse_field_accessE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ExprE*  left) {
#line 331 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_Field) ;
;
#line 332 "src/parser.z"
expr->node.field.ident = _ZN6parser16parse_identifierE(ctx) ;
;
#line 333 "src/parser.z"
expr->node.field.strct = left;
;
#line 335 "src/parser.z"
return expr;
;
}
#line 338 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser14parse_indexingE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ExprE*  left) {
#line 340 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_Indexing) ;
;
#line 341 "src/parser.z"
expr->node.indexing.index = _ZN6parser16parse_expressionE(ctx,(( u32)(0))) ;
;
#line 342 "src/parser.z"
expr->node.indexing.array = left;
;
#line 344 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_RightBracket) ;
#line 346 "src/parser.z"
return expr;
;
}
#line 349 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser16parse_assignmentE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ExprE*  left) {
#line 350 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_Assignment) ;
;
#line 351 "src/parser.z"
expr->node.assignment.left = left;
;
#line 352 "src/parser.z"
expr->node.assignment.right = _ZN6parser16parse_expressionE(ctx,(( u32)(0))) ;
;
#line 354 "src/parser.z"
return expr;
;
}
#line 357 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser20parse_infix_operatorE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ExprE*  left, _ZN6tokens5TokenE tok) {
#line 359 "src/parser.z"
if ((tok.kind== TokenKind_LeftParen)){
#line 359 "src/parser.z"
return _ZN6parser10parse_callE(ctx,left) ;
;
}
;
#line 360 "src/parser.z"
if ((tok.kind== TokenKind_Dot)){
#line 360 "src/parser.z"
return _ZN6parser18parse_field_accessE(ctx,left) ;
;
}
;
#line 361 "src/parser.z"
if ((tok.kind== TokenKind_LeftBracket)){
#line 361 "src/parser.z"
return _ZN6parser14parse_indexingE(ctx,left) ;
;
}
;
#line 362 "src/parser.z"
if ((tok.kind== TokenKind_Equal)){
#line 362 "src/parser.z"
return _ZN6parser16parse_assignmentE(ctx,left) ;
;
}
;
#line 364 "src/parser.z"
_ZN3ast18BinaryOperatorKindE op = _ZN6parser32convert_token_to_binary_operatorE(tok.kind) ;
;
#line 365 "src/parser.z"
if ((op!= BinaryOperatorKind_Invalid)){
#line 366 "src/parser.z"
return _ZN6parser21parse_binary_operatorE(ctx,left,op) ;
;
}
else {
#line 368 "src/parser.z"
_ZN5error10emit_errorE(ctx->source_map,tok.span,"Unsupported infix operator") ;
}
;
#line 369 "src/parser.z"
return _ZN4cstd4nullE;
;
}
#line 372 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser10parse_stmtE(_ZN6parser14ParsingContextE*  ctx) ;
#line 374 "src/parser.z"
_ZN3ast5BlockE*  _ZN6parser11parse_blockE(_ZN6parser14ParsingContextE*  ctx) {
#line 376 "src/parser.z"
_ZN3ast5BlockE*  block = malloc(sizeof(_ZN3ast5BlockE)) ;
;
#line 377 "src/parser.z"
block->exprs = malloc((( u64)((8* 128)))) ;
;
#line 378 "src/parser.z"
block->num_exprs = 0;
;
#line 379 "src/parser.z"
block->span.from = _ZN6parser10span_startE(ctx) ;
;
#line 381 "src/parser.z"
_ZN6tokens5TokenE next = _ZN6parser10look_aheadE(ctx,(( u64)(0))) ;
;
#line 382 "src/parser.z"
if ((next.kind== TokenKind_LeftCurly)){
#line 383 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_LeftCurly) ;
#line 384 "src/parser.z"
 u32 i = 0;
;
#line 385 "src/parser.z"
while ( !_ZN6parser6acceptE(ctx,TokenKind_RightCurly) )
{
#line 386 "src/parser.z"
block->exprs[i] = _ZN6parser10parse_stmtE(ctx) ;
;
#line 387 "src/parser.z"
block->num_exprs = ((( i32)(block->num_exprs))+ 1);
;
#line 388 "src/parser.z"
i = ((( i32)(i))+ 1);
;
}
;
}
else {
#line 391 "src/parser.z"
block->exprs[0] = _ZN6parser10parse_stmtE(ctx) ;
;
#line 392 "src/parser.z"
block->num_exprs = 1;
;
}
;
#line 394 "src/parser.z"
block->span.to = _ZN6parser8span_endE(ctx) ;
;
#line 396 "src/parser.z"
return block;
;
}
#line 399 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser16parse_block_exprE(_ZN6parser14ParsingContextE*  ctx) {
#line 400 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_Block) ;
;
#line 401 "src/parser.z"
expr->node.block = _ZN6parser11parse_blockE(ctx) ;
;
#line 402 "src/parser.z"
return expr;
;
}
#line 405 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser8parse_ifE(_ZN6parser14ParsingContextE*  ctx) {
#line 407 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_If) ;
#line 409 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_Conditional) ;
;
#line 410 "src/parser.z"
expr->node.conditional.condition = _ZN6parser16parse_expressionE(ctx,(( u32)(0))) ;
;
#line 411 "src/parser.z"
expr->node.conditional.then = _ZN6parser16parse_block_exprE(ctx) ;
;
#line 413 "src/parser.z"
if (_ZN6parser6acceptE(ctx,TokenKind_Else) ){
#line 414 "src/parser.z"
expr->node.conditional.otherwise = _ZN6parser16parse_block_exprE(ctx) ;
;
}
else {
#line 416 "src/parser.z"
expr->node.conditional.otherwise = _ZN4cstd4nullE;
;
}
;
#line 419 "src/parser.z"
return expr;
;
}
#line 422 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser11parse_whileE(_ZN6parser14ParsingContextE*  ctx) {
#line 423 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_While) ;
#line 425 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_While) ;
;
#line 426 "src/parser.z"
expr->node.whl.condition = _ZN6parser16parse_expressionE(ctx,(( u32)(0))) ;
;
#line 427 "src/parser.z"
expr->node.whl.body = _ZN6parser16parse_block_exprE(ctx) ;
;
#line 429 "src/parser.z"
return expr;
;
}
#line 432 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser12parse_sizeofE(_ZN6parser14ParsingContextE*  ctx) {
#line 433 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_Sizeof) ;
#line 434 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_LeftParen) ;
#line 436 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_Sizeof) ;
;
#line 437 "src/parser.z"
expr->node._sizeof = _ZN6parser16parse_expressionE(ctx,(( u32)(0))) ;
;
#line 438 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_RightParen) ;
#line 440 "src/parser.z"
return expr;
;
}
#line 443 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser20parse_local_variableE(_ZN6parser14ParsingContextE*  ctx) {
#line 445 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_Local) ;
;
#line 446 "src/parser.z"
expr->node.local.pat = _ZN6parser13parse_patternE(ctx) ;
;
#line 447 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_Colon) ;
#line 449 "src/parser.z"
expr->node.local.ast_ty = _ZN6parser10parse_typeE(ctx) ;
;
#line 451 "src/parser.z"
if (_ZN6parser6acceptE(ctx,TokenKind_Equal) ){
#line 451 "src/parser.z"
expr->node.local.value = _ZN6parser16parse_expressionE(ctx,(( u32)(0))) ;
;
}
else {
#line 452 "src/parser.z"
expr->node.local.value = 0;
;
}
;
#line 454 "src/parser.z"
return expr;
;
}
#line 458 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser18parse_control_flowE(_ZN6parser14ParsingContextE*  ctx) {
#line 459 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_ControlFlow) ;
;
#line 460 "src/parser.z"
expr->node.control_flow_is_continue = _ZN6parser6acceptE(ctx,TokenKind_Continue) ;
;
#line 462 "src/parser.z"
if (!expr->node.control_flow_is_continue){
#line 462 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_Break) ;
}
;
#line 464 "src/parser.z"
return expr;
;
}
#line 467 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser10parse_castE(_ZN6parser14ParsingContextE*  ctx) {
#line 468 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_Cast) ;
#line 469 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_LeftParen) ;
#line 471 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_Cast) ;
;
#line 472 "src/parser.z"
expr->node._cast.inner = _ZN6parser16parse_expressionE(ctx,(( u32)(0))) ;
;
#line 473 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_Comma) ;
#line 474 "src/parser.z"
expr->node._cast.ast_ty = _ZN6parser10parse_typeE(ctx) ;
;
#line 475 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_RightParen) ;
#line 477 "src/parser.z"
return expr;
;
}
#line 480 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser12parse_returnE(_ZN6parser14ParsingContextE*  ctx) {
#line 481 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_Return) ;
#line 482 "src/parser.z"
_ZN3ast4ExprE*  expr = _ZN3ast11create_exprE(ExprKind_Return) ;
;
#line 483 "src/parser.z"
expr->node._return = _ZN6parser16parse_expressionE(ctx,(( u32)(0))) ;
;
#line 485 "src/parser.z"
return expr;
;
}
#line 488 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser16parse_expressionE(_ZN6parser14ParsingContextE*  ctx,  u32 precedence) {
#line 489 "src/parser.z"
_ZN6tokens5TokenE tok = _ZN6parser10look_aheadE(ctx,(( u64)(0))) ;
;
#line 490 "src/parser.z"
_ZN10source_map4SpanE span ;
;
#line 491 "src/parser.z"
span.from = _ZN6parser10span_startE(ctx) ;
;
#line 493 "src/parser.z"
_ZN3ast4ExprE*  left ;
;
#line 495 "src/parser.z"
if ((tok.kind== TokenKind_Integer)){
#line 495 "src/parser.z"
left = _ZN6parser21parse_integer_literalE(ctx) ;
;
}
else {
#line 496 "src/parser.z"
if ((tok.kind== TokenKind_Char)){
#line 496 "src/parser.z"
left = _ZN6parser18parse_char_literalE(ctx) ;
;
}
else {
#line 497 "src/parser.z"
if ((tok.kind== TokenKind_String)){
#line 497 "src/parser.z"
left = _ZN6parser20parse_string_literalE(ctx) ;
;
}
else {
#line 498 "src/parser.z"
if ((tok.kind== TokenKind_Float)){
#line 498 "src/parser.z"
left = _ZN6parser19parse_float_literalE(ctx) ;
;
}
else {
#line 499 "src/parser.z"
if (((tok.kind== TokenKind_False)|| (tok.kind== TokenKind_True))){
#line 499 "src/parser.z"
left = _ZN6parser18parse_bool_literalE(ctx) ;
;
}
else {
#line 500 "src/parser.z"
if (((((tok.kind== TokenKind_Minus)|| (tok.kind== TokenKind_Bang))|| (tok.kind== TokenKind_And))|| (tok.kind== TokenKind_Star))){
#line 501 "src/parser.z"
left = _ZN6parser21parse_prefix_operatorE(ctx) ;
;
}
else {
#line 502 "src/parser.z"
if ((tok.kind== TokenKind_If)){
#line 502 "src/parser.z"
left = _ZN6parser8parse_ifE(ctx) ;
;
}
else {
#line 503 "src/parser.z"
if ((tok.kind== TokenKind_Cast)){
#line 503 "src/parser.z"
left = _ZN6parser10parse_castE(ctx) ;
;
}
else {
#line 504 "src/parser.z"
if ((tok.kind== TokenKind_Sizeof)){
#line 504 "src/parser.z"
left = _ZN6parser12parse_sizeofE(ctx) ;
;
}
else {
#line 505 "src/parser.z"
if ((tok.kind== TokenKind_Identifier)){
#line 505 "src/parser.z"
left = _ZN6parser15parse_path_exprE(ctx) ;
;
}
else {
#line 506 "src/parser.z"
if ((tok.kind== TokenKind_LeftParen)){
#line 507 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_LeftParen) ;
#line 508 "src/parser.z"
left = _ZN6parser16parse_expressionE(ctx,(( u32)(0))) ;
;
#line 509 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_RightParen) ;
}
else {
#line 511 "src/parser.z"
if ((tok.kind== TokenKind_LeftCurly)){
#line 511 "src/parser.z"
left = _ZN6parser16parse_block_exprE(ctx) ;
;
}
else {
#line 512 "src/parser.z"
_ZN5error10emit_errorE(ctx->source_map,tok.span,"Invalid expression prefix") ;
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
#line 514 "src/parser.z"
while ( (precedence< _ZN6parser22get_current_precedenceE(ctx) ))
{
#line 515 "src/parser.z"
_ZN6tokens5TokenE next_tok = _ZN6parser7consumeE(ctx) ;
;
#line 516 "src/parser.z"
left = _ZN6parser20parse_infix_operatorE(ctx,left,next_tok) ;
;
}
;
#line 518 "src/parser.z"
span.to = _ZN6parser8span_endE(ctx) ;
;
#line 519 "src/parser.z"
left->span = span;
;
#line 521 "src/parser.z"
return left;
;
}
#line 524 "src/parser.z"
_ZN3ast4ExprE*  _ZN6parser10parse_stmtE(_ZN6parser14ParsingContextE*  ctx) {
#line 526 "src/parser.z"
_ZN6tokens5TokenE tok = _ZN6parser10look_aheadE(ctx,(( u64)(0))) ;
;
#line 527 "src/parser.z"
_ZN6tokens5TokenE next = _ZN6parser10look_aheadE(ctx,(( u64)(1))) ;
;
#line 528 "src/parser.z"
_ZN10source_map4SpanE span ;
;
#line 529 "src/parser.z"
span.from = _ZN6parser10span_startE(ctx) ;
;
#line 531 "src/parser.z"
_ZN3ast4ExprE*  stmt ;
;
#line 533 "src/parser.z"
if ((tok.kind== TokenKind_While)){
#line 533 "src/parser.z"
stmt = _ZN6parser11parse_whileE(ctx) ;
;
}
else {
#line 534 "src/parser.z"
if (((tok.kind== TokenKind_Continue)|| (tok.kind== TokenKind_Break))){
#line 534 "src/parser.z"
stmt = _ZN6parser18parse_control_flowE(ctx) ;
;
}
else {
#line 535 "src/parser.z"
if ((tok.kind== TokenKind_Return)){
#line 535 "src/parser.z"
stmt = _ZN6parser12parse_returnE(ctx) ;
;
}
else {
#line 536 "src/parser.z"
if ((next.kind== TokenKind_Colon)){
#line 536 "src/parser.z"
stmt = _ZN6parser20parse_local_variableE(ctx) ;
;
}
else {
#line 537 "src/parser.z"
stmt = _ZN6parser16parse_expressionE(ctx,(( u32)(0))) ;
;
}
;
}
;
}
;
}
;
#line 539 "src/parser.z"
span.to = _ZN6parser8span_endE(ctx) ;
;
#line 540 "src/parser.z"
stmt->span = span;
;
#line 542 "src/parser.z"
_ZN6parser6acceptE(ctx,TokenKind_Semicolon) ;
#line 544 "src/parser.z"
return stmt;
;
}
#line 547 "src/parser.z"
_ZN3ast8GenericsE _ZN6parser14parse_genericsE(_ZN6parser14ParsingContextE*  ctx) {
#line 548 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_Less) ;
#line 549 "src/parser.z"
_ZN3ast8GenericsE generics ;
;
#line 550 "src/parser.z"
generics.parameters = malloc((( u64)(((( u64)(4))* sizeof(_ZN3ast12GenericParamE))))) ;
;
#line 551 "src/parser.z"
generics.num_parameters = 0;
;
#line 553 "src/parser.z"
while ( !_ZN6parser6acceptE(ctx,TokenKind_Greater) )
{
#line 554 "src/parser.z"
generics.parameters[generics.num_parameters].ident = _ZN6parser16parse_identifierE(ctx) ;
;
#line 556 "src/parser.z"
_ZN6parser6acceptE(ctx,TokenKind_Comma) ;
#line 557 "src/parser.z"
generics.num_parameters = ((( i32)(generics.num_parameters))+ 1);
;
}
;
#line 559 "src/parser.z"
return generics;
;
}
#line 562 "src/parser.z"
 void _ZN6parser19parse_variable_declE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 564 "src/parser.z"
if (_ZN6parser6acceptE(ctx,TokenKind_Val) ){
#line 564 "src/parser.z"
item->kind = ItemKind_Const;
;
}
else {
#line 565 "src/parser.z"
if (_ZN6parser6acceptE(ctx,TokenKind_Var) ){
#line 565 "src/parser.z"
item->kind = ItemKind_Variable;
;
}
;
}
;
#line 567 "src/parser.z"
item->ident = _ZN6parser16parse_identifierE(ctx) ;
;
#line 568 "src/parser.z"
if (_ZN6parser6acceptE(ctx,TokenKind_ColonColon) ){
#line 568 "src/parser.z"
item->kind = ItemKind_Const;
;
}
else {
#line 569 "src/parser.z"
if (_ZN6parser6acceptE(ctx,TokenKind_Colon) ){
#line 569 "src/parser.z"
item->kind = ItemKind_Variable;
;
}
;
}
;
#line 570 "src/parser.z"
item->node.variable.ast_ty = _ZN6parser10parse_typeE(ctx) ;
;
#line 572 "src/parser.z"
if (_ZN6parser6acceptE(ctx,TokenKind_Equal) ){
#line 572 "src/parser.z"
item->node.variable.body = _ZN6parser16parse_expressionE(ctx,(( u32)(0))) ;
;
}
else {
#line 573 "src/parser.z"
item->node.variable.body = 0;
;
}
;
}
#line 576 "src/parser.z"
 void _ZN6parser19parse_compound_declE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 578 "src/parser.z"
item->ident = _ZN6parser16parse_identifierE(ctx) ;
;
#line 580 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_ColonColon) ;
#line 581 "src/parser.z"
if (_ZN6parser6acceptE(ctx,TokenKind_Struct) ){
#line 581 "src/parser.z"
item->kind = ItemKind_Struct;
;
}
else {
#line 582 "src/parser.z"
if (_ZN6parser6acceptE(ctx,TokenKind_Union) ){
#line 582 "src/parser.z"
item->kind = ItemKind_Union;
;
}
else {
#line 583 "src/parser.z"
abort() ;
}
;
}
;
#line 585 "src/parser.z"
if (_ZN6parser10can_acceptE(ctx,TokenKind_Less) ){
#line 585 "src/parser.z"
item->node.compound.generics = _ZN6parser14parse_genericsE(ctx) ;
;
}
else {
#line 586 "src/parser.z"
item->node.compound.generics.num_parameters = 0;
;
}
;
#line 588 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_LeftCurly) ;
#line 590 "src/parser.z"
item->node.compound.fields = malloc((sizeof(_ZN3ast13CompoundFieldE)* (( u64)(32)))) ;
;
#line 591 "src/parser.z"
item->node.compound.num_fields = 0;
;
#line 593 "src/parser.z"
while ( !_ZN6parser6acceptE(ctx,TokenKind_RightCurly) )
{
#line 594 "src/parser.z"
_ZN6tokens5TokenE token = _ZN6parser7consumeE(ctx) ;
;
#line 595 "src/parser.z"
if ((token.kind!= TokenKind_Identifier)){
#line 595 "src/parser.z"
_ZN5error10emit_errorE(ctx->source_map,token.span,"Expected field identifier") ;
}
;
#line 597 "src/parser.z"
item->node.compound.fields[item->node.compound.num_fields].ident.name = token.lexeme;
;
#line 598 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_Colon) ;
#line 600 "src/parser.z"
_ZN3ast7AstTypeE*  type = _ZN6parser10parse_typeE(ctx) ;
;
#line 601 "src/parser.z"
item->node.compound.fields[item->node.compound.num_fields].ast_ty = type;
;
#line 602 "src/parser.z"
item->node.compound.num_fields = ((( i32)(item->node.compound.num_fields))+ 1);
;
#line 603 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_Comma) ;
}
;
}
#line 608 "src/parser.z"
 void _ZN6parser15parse_enum_declE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 610 "src/parser.z"
item->kind = ItemKind_Enum;
;
#line 611 "src/parser.z"
item->ident = _ZN6parser16parse_identifierE(ctx) ;
;
#line 613 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_ColonColon) ;
#line 614 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_Enum) ;
#line 616 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_LeftCurly) ;
#line 618 "src/parser.z"
item->node._enum.variants = malloc((sizeof(_ZN3ast11EnumVariantE)* (( u64)(128)))) ;
;
#line 619 "src/parser.z"
item->node._enum.num_variants = 0;
;
#line 621 "src/parser.z"
while ( !_ZN6parser6acceptE(ctx,TokenKind_RightCurly) )
{
#line 622 "src/parser.z"
item->node._enum.variants[item->node._enum.num_variants].ident = _ZN6parser16parse_identifierE(ctx) ;
;
#line 623 "src/parser.z"
item->node._enum.variants[item->node._enum.num_variants]._enum = item;
;
#line 624 "src/parser.z"
item->node._enum.num_variants = ((( i32)(item->node._enum.num_variants))+ 1);
;
#line 625 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_Comma) ;
}
;
}
#line 629 "src/parser.z"
_ZN3ast14FunctionHeaderE _ZN6parser21parse_function_headerE(_ZN6parser14ParsingContextE*  ctx) {
#line 630 "src/parser.z"
_ZN3ast14FunctionHeaderE header ;
;
#line 632 "src/parser.z"
header.parameters = malloc((sizeof(_ZN3ast17FunctionParameterE)* (( u64)(16)))) ;
;
#line 633 "src/parser.z"
header.num_parameters = 0;
;
#line 635 "src/parser.z"
if (_ZN6parser10can_acceptE(ctx,TokenKind_Less) ){
#line 635 "src/parser.z"
header.generics = _ZN6parser14parse_genericsE(ctx) ;
;
}
else {
#line 636 "src/parser.z"
header.generics.num_parameters = 0;
;
}
;
#line 638 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_LeftParen) ;
#line 640 "src/parser.z"
while ( !_ZN6parser6acceptE(ctx,TokenKind_RightParen) )
{
#line 642 "src/parser.z"
header.parameters[header.num_parameters].pat = _ZN6parser13parse_patternE(ctx) ;
;
#line 644 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_Colon) ;
#line 645 "src/parser.z"
_ZN3ast7AstTypeE*  type = _ZN6parser10parse_typeE(ctx) ;
;
#line 646 "src/parser.z"
header.parameters[header.num_parameters].ast_ty = type;
;
#line 647 "src/parser.z"
header.num_parameters = ((( i32)(header.num_parameters))+ 1);
;
#line 649 "src/parser.z"
_ZN6parser6acceptE(ctx,TokenKind_Comma) ;
}
;
#line 652 "src/parser.z"
if (_ZN6parser6acceptE(ctx,TokenKind_Arrow) ){
#line 652 "src/parser.z"
header.output_ast_ty = _ZN6parser10parse_typeE(ctx) ;
;
}
else {
#line 655 "src/parser.z"
_ZN3ast7AstTypeE*  output = malloc(sizeof(_ZN3ast7AstTypeE)) ;
;
#line 656 "src/parser.z"
output->kind = AstTypeKind_Void;
;
#line 657 "src/parser.z"
header.output_ast_ty = output;
;
}
;
#line 660 "src/parser.z"
return header;
;
}
#line 663 "src/parser.z"
 void _ZN6parser19parse_function_declE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 665 "src/parser.z"
item->kind = ItemKind_Function;
;
#line 667 "src/parser.z"
item->ident = _ZN6parser16parse_identifierE(ctx) ;
;
#line 669 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_ColonColon) ;
#line 671 "src/parser.z"
_ZN7session7SessionE*  sess = ctx->sess;
;
#line 672 "src/parser.z"
if ((item->ident.name.x== _ZN9interning6internE(&sess->interner,"main") .x)){
#line 672 "src/parser.z"
item->should_mangle = false;
;
}
;
#line 674 "src/parser.z"
item->node.function.header = _ZN6parser21parse_function_headerE(ctx) ;
;
#line 676 "src/parser.z"
if ((_ZN6parser10look_aheadE(ctx,(( u64)(0))) .kind== TokenKind_LeftCurly)){
#line 676 "src/parser.z"
item->node.function.body = _ZN6parser16parse_expressionE(ctx,(( u32)(0))) ;
;
}
else {
#line 677 "src/parser.z"
item->node.function.body = 0;
;
}
;
}
#line 680 "src/parser.z"
 void _ZN6parser9parse_useE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 681 "src/parser.z"
_ZN6parser6expectE(ctx,TokenKind_Use) ;
#line 683 "src/parser.z"
item->kind = ItemKind_Use;
;
#line 684 "src/parser.z"
item->node._use = _ZN6parser10parse_pathE(ctx) ;
;
#line 685 "src/parser.z"
item->ident.name.x = 0;
;
#line 687 "src/parser.z"
_ZN6parser6acceptE(ctx,TokenKind_Semicolon) ;
}
#line 690 "src/parser.z"
 void _ZN6parser10parse_itemE(_ZN6parser14ParsingContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 692 "src/parser.z"
item->span.from = _ZN6parser10span_startE(ctx) ;
;
#line 693 "src/parser.z"
item->should_mangle = !_ZN6parser6acceptE(ctx,TokenKind_Extern) ;
;
#line 695 "src/parser.z"
_ZN6tokens5TokenE tok = _ZN6parser10look_aheadE(ctx,(( u64)(0))) ;
;
#line 696 "src/parser.z"
while ( (tok.kind== TokenKind_Mod))
{
#line 697 "src/parser.z"
_ZN6parser7consumeE(ctx) ;
#line 697 "src/parser.z"
_ZN6parser7consumeE(ctx) ;
#line 697 "src/parser.z"
_ZN6parser7consumeE(ctx) ;
#line 698 "src/parser.z"
tok = _ZN6parser10look_aheadE(ctx,(( u64)(0))) ;
;
}
;
#line 701 "src/parser.z"
if (((tok.kind== TokenKind_Var)|| (tok.kind== TokenKind_Val))){
#line 701 "src/parser.z"
_ZN6parser19parse_variable_declE(ctx,item) ;
}
else {
#line 702 "src/parser.z"
if ((tok.kind== TokenKind_Use)){
#line 702 "src/parser.z"
_ZN6parser9parse_useE(ctx,item) ;
}
else {
#line 703 "src/parser.z"
if ((tok.kind== TokenKind_Identifier)){
#line 704 "src/parser.z"
_ZN6tokens5TokenE next = _ZN6parser10look_aheadE(ctx,(( u64)(2))) ;
;
#line 705 "src/parser.z"
if (((next.kind== TokenKind_Struct)|| (next.kind== TokenKind_Union))){
#line 705 "src/parser.z"
_ZN6parser19parse_compound_declE(ctx,item) ;
}
else {
#line 706 "src/parser.z"
if ((next.kind== TokenKind_Enum)){
#line 706 "src/parser.z"
_ZN6parser15parse_enum_declE(ctx,item) ;
}
else {
#line 707 "src/parser.z"
if ((next.kind== TokenKind_LeftParen)){
#line 707 "src/parser.z"
_ZN6parser19parse_function_declE(ctx,item) ;
}
else {
#line 708 "src/parser.z"
_ZN6parser19parse_variable_declE(ctx,item) ;
}
;
}
;
}
;
}
else {
#line 710 "src/parser.z"
_ZN5error10emit_errorE(ctx->source_map,tok.span,"Unexpected token on top-level") ;
}
;
}
;
}
;
#line 712 "src/parser.z"
_ZN6parser6acceptE(ctx,TokenKind_Semicolon) ;
#line 714 "src/parser.z"
item->span.to = _ZN6parser8span_endE(ctx) ;
;
}
#line 717 "src/parser.z"
_ZN3ast6ModuleE*  _ZN6parser5parseE(_ZN7session7SessionE*  sess, _ZN10source_map10SourceFileE*  source, _ZN9interning3SidE name, _ZN3ast6ModuleE*  parent) {
#line 719 "src/parser.z"
_ZN3ast6ModuleE*  module = malloc(sizeof(_ZN3ast6ModuleE)) ;
;
#line 720 "src/parser.z"
module->items = malloc((sizeof(_ZN3ast4ItemE)* (( u64)(2048)))) ;
;
#line 721 "src/parser.z"
module->num_items = 0;
;
#line 722 "src/parser.z"
module->parent = _ZN4cstd4nullE;
;
#line 724 "src/parser.z"
if ((( bool)(parent))){
#line 724 "src/parser.z"
module->path.num_segments = ((( i32)(parent->path.num_segments))+ 1);
;
}
else {
#line 725 "src/parser.z"
module->path.num_segments = 1;
;
}
;
#line 727 "src/parser.z"
module->path.segments = malloc((sizeof(_ZN3ast5IdentE)* (( u64)(module->path.num_segments)))) ;
;
#line 728 "src/parser.z"
if ((( bool)(parent))){
#line 728 "src/parser.z"
memcpy((( void* )(module->path.segments)),(( void* )(parent->path.segments)),(( u64)(((( u64)(parent->path.num_segments))* sizeof(_ZN3ast5IdentE))))) ;
}
;
#line 729 "src/parser.z"
module->path.segments[((( i32)(module->path.num_segments))- 1)].name = name;
;
#line 731 "src/parser.z"
module->path.binding.node.module = module;
;
#line 733 "src/parser.z"
 u32 num_tokens ;
;
#line 734 "src/parser.z"
_ZN6tokens5TokenE*  tokens = _ZN5lexer3lexE(sess,source,&num_tokens) ;
;
#line 736 "src/parser.z"
_ZN6parser14ParsingContextE ctx ;
;
#line 737 "src/parser.z"
ctx.current_token = 0;
;
#line 738 "src/parser.z"
ctx.tokens = tokens;
;
#line 739 "src/parser.z"
ctx.num_tokens = num_tokens;
;
#line 740 "src/parser.z"
ctx.source_map = &sess->source;
;
#line 741 "src/parser.z"
ctx.interner = &sess->interner;
;
#line 742 "src/parser.z"
ctx.sess = sess;
;
#line 743 "src/parser.z"
ctx.module = module;
;
#line 745 "src/parser.z"
module->span.from = _ZN6parser10span_startE(&ctx) ;
;
#line 747 "src/parser.z"
while ( (!_ZN6parser6acceptE(&ctx,TokenKind_RightCurly) && !_ZN6parser15is_done_parsingE(&ctx) ))
{
#line 748 "src/parser.z"
_ZN6parser10parse_itemE(&ctx,&module->items[module->num_items]) ;
#line 749 "src/parser.z"
module->num_items = ((( i32)(module->num_items))+ 1);
;
}
;
#line 752 "src/parser.z"
module->span.to = _ZN6parser8span_endE(&ctx) ;
;
#line 754 "src/parser.z"
return module;
;
}
#line 64 "src/resolution.z"
 void _ZN10resolution23setup_primitive_ty_sidsE(_ZN9interning8InternerE*  i, _ZN10resolution17PrimitiveTypeSidsE*  p) {
#line 65 "src/resolution.z"
p->_void = _ZN9interning6internE(i,"void") ;
;
#line 66 "src/resolution.z"
p->_constvoid = _ZN9interning6internE(i,"constvoid") ;
;
#line 67 "src/resolution.z"
p->_bool = _ZN9interning6internE(i,"bool") ;
;
#line 68 "src/resolution.z"
p->_char = _ZN9interning6internE(i,"char") ;
;
#line 69 "src/resolution.z"
p->_constchar = _ZN9interning6internE(i,"constchar") ;
;
#line 70 "src/resolution.z"
p->_i8 = _ZN9interning6internE(i,"i8") ;
;
#line 71 "src/resolution.z"
p->_i16 = _ZN9interning6internE(i,"i16") ;
;
#line 72 "src/resolution.z"
p->_i32 = _ZN9interning6internE(i,"i32") ;
;
#line 73 "src/resolution.z"
p->_i64 = _ZN9interning6internE(i,"i64") ;
;
#line 74 "src/resolution.z"
p->_u8 = _ZN9interning6internE(i,"u8") ;
;
#line 75 "src/resolution.z"
p->_u16 = _ZN9interning6internE(i,"u16") ;
;
#line 76 "src/resolution.z"
p->_u32 = _ZN9interning6internE(i,"u32") ;
;
#line 77 "src/resolution.z"
p->_u64 = _ZN9interning6internE(i,"u64") ;
;
#line 78 "src/resolution.z"
p->_f32 = _ZN9interning6internE(i,"f32") ;
;
#line 79 "src/resolution.z"
p->_f64 = _ZN9interning6internE(i,"f64") ;
;
}
#line 82 "src/resolution.z"
 void _ZN10resolution10push_blockE(_ZN10resolution17ResolutionContextE*  ctx) {
#line 83 "src/resolution.z"
ctx->stack_top = ((( i32)(ctx->stack_top))+ 1);
;
#line 84 "src/resolution.z"
_ZN10resolution5ScopeE*  scope = &ctx->scope_stack[ctx->stack_top];
;
#line 86 "src/resolution.z"
scope->symbols = malloc((( u64)((8* 32)))) ;
;
#line 87 "src/resolution.z"
scope->num_symbols = 0;
;
}
#line 90 "src/resolution.z"
 void _ZN10resolution9pop_blockE(_ZN10resolution17ResolutionContextE*  ctx) {
#line 91 "src/resolution.z"
_ZN10resolution5ScopeE*  scope = &ctx->scope_stack[ctx->stack_top];
;
#line 92 "src/resolution.z"
free((( void* )(scope->symbols))) ;
#line 93 "src/resolution.z"
ctx->stack_top = ((( i32)(ctx->stack_top))- 1);
;
}
#line 96 "src/resolution.z"
 void _ZN10resolution14push_parameterE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast5IdentE ident, _ZN3ast17FunctionParameterE*  data) {
#line 97 "src/resolution.z"
_ZN10resolution5ScopeE*  scope = &ctx->scope_stack[ctx->stack_top];
;
#line 98 "src/resolution.z"
_ZN10resolution10SymbolInfoE*  s = &scope->symbols[scope->num_symbols];
;
#line 99 "src/resolution.z"
s->ident = ident;
;
#line 100 "src/resolution.z"
s->kind = SymbolInfoKind_Parameter;
;
#line 101 "src/resolution.z"
s->node.parameter = data;
;
#line 102 "src/resolution.z"
scope->num_symbols = ((( i32)(scope->num_symbols))+ 1);
;
}
#line 105 "src/resolution.z"
 void _ZN10resolution10push_localE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast5IdentE ident, _ZN3ast9LocalDataE*  data) {
#line 106 "src/resolution.z"
_ZN10resolution5ScopeE*  scope = &ctx->scope_stack[ctx->stack_top];
;
#line 107 "src/resolution.z"
_ZN10resolution10SymbolInfoE*  s = &scope->symbols[scope->num_symbols];
;
#line 108 "src/resolution.z"
s->ident = ident;
;
#line 109 "src/resolution.z"
s->kind = SymbolInfoKind_Local;
;
#line 110 "src/resolution.z"
s->node.local = data;
;
#line 111 "src/resolution.z"
scope->num_symbols = ((( i32)(scope->num_symbols))+ 1);
;
}
#line 114 "src/resolution.z"
_ZN3ast4PathE _ZN10resolution6lookupE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast5IdentE ident) {
#line 115 "src/resolution.z"
 i32 i = ctx->stack_top;
;
#line 116 "src/resolution.z"
while ( (i> 0))
{
#line 117 "src/resolution.z"
_ZN10resolution5ScopeE*  scope = &ctx->scope_stack[i];
;
#line 118 "src/resolution.z"
 i32 j = ((( i32)(scope->num_symbols))- 1);
;
#line 119 "src/resolution.z"
while ( (j>= 0))
{
#line 120 "src/resolution.z"
_ZN10resolution10SymbolInfoE symbol = scope->symbols[j];
;
#line 121 "src/resolution.z"
if ((symbol.ident.name.x== ident.name.x)){
#line 122 "src/resolution.z"
_ZN3ast4PathE path ;
;
#line 123 "src/resolution.z"
path.segments = malloc(sizeof(_ZN3ast5IdentE)) ;
;
#line 124 "src/resolution.z"
path.segments[0] = symbol.ident;
;
#line 125 "src/resolution.z"
path.num_segments = 1;
;
#line 126 "src/resolution.z"
if ((symbol.kind== SymbolInfoKind_Local)){
#line 127 "src/resolution.z"
path.binding.kind = BindingKind_Local;
;
#line 128 "src/resolution.z"
path.binding.node.local = symbol.node.local;
;
}
else {
#line 130 "src/resolution.z"
if ((symbol.kind== SymbolInfoKind_Parameter)){
#line 131 "src/resolution.z"
path.binding.kind = BindingKind_Parameter;
;
#line 132 "src/resolution.z"
path.binding.node.parameter = symbol.node.parameter;
;
}
;
}
;
#line 134 "src/resolution.z"
return path;
;
}
;
#line 136 "src/resolution.z"
j = (j- 1);
;
}
;
#line 138 "src/resolution.z"
i = (i- 1);
;
}
;
#line 141 "src/resolution.z"
 u32 idx = _ZN6intmap13intmap_lookupE(ctx->index_lookup,(( u64)(ident.name.x))) ;
;
#line 142 "src/resolution.z"
if (((( i32)(idx))> 0)){
#line 143 "src/resolution.z"
_ZN10resolution10IndexEntryE entry = ctx->index[idx];
;
#line 144 "src/resolution.z"
return entry.path;
;
}
;
#line 147 "src/resolution.z"
_ZN5error10emit_errorE(ctx->source_map,ident.span,"Unable to resolve item") ;
#line 148 "src/resolution.z"
abort() ;
}
#line 151 "src/resolution.z"
 void _ZN10resolution8add_itemE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast6ModuleE*  parent, _ZN3ast4ItemE*  item) {
#line 153 "src/resolution.z"
_ZN10resolution10IndexEntryE*  idx_entry = &ctx->index[ctx->num_indices];
;
#line 156 "src/resolution.z"
idx_entry->path.num_segments = ((( i32)(parent->path.num_segments))+ 1);
;
#line 157 "src/resolution.z"
idx_entry->path.segments = malloc((sizeof(_ZN3ast5IdentE)* (( u64)(idx_entry->path.num_segments)))) ;
;
#line 158 "src/resolution.z"
memcpy((( void* )(idx_entry->path.segments)),(( void* )(parent->path.segments)),(sizeof(_ZN3ast5IdentE)* (( u64)(parent->path.num_segments)))) ;
#line 159 "src/resolution.z"
idx_entry->path.segments[parent->path.num_segments] = item->ident;
;
#line 160 "src/resolution.z"
idx_entry->path.binding.kind = BindingKind_Item;
;
#line 161 "src/resolution.z"
idx_entry->path.binding.node.item = item;
;
#line 163 "src/resolution.z"
_ZN6intmap13intmap_insertE(ctx->index_lookup,(( u64)(item->ident.name.x)),(( u64)(ctx->num_indices))) ;
#line 165 "src/resolution.z"
ctx->num_indices = ((( i32)(ctx->num_indices))+ 1);
;
}
#line 169 "src/resolution.z"
 void _ZN10resolution15import_wildcardE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4PathE path) {
#line 171 "src/resolution.z"
_ZN3ast6ModuleE*  module = path.binding.node.module;
;
#line 173 "src/resolution.z"
 u32 i = 0;
;
#line 174 "src/resolution.z"
while ( (i< module->num_items))
{
#line 175 "src/resolution.z"
_ZN3ast4ItemE*  item = &module->items[i];
;
#line 176 "src/resolution.z"
if ((item->kind!= ItemKind_Use)){
#line 176 "src/resolution.z"
_ZN10resolution8add_itemE(ctx,module,item) ;
}
;
#line 177 "src/resolution.z"
i = ((( i32)(i))+ 1);
;
}
;
}
#line 181 "src/resolution.z"
 void _ZN10resolution12index_moduleE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast6ModuleE*  module) {
#line 183 "src/resolution.z"
 u32 i = 0;
;
#line 184 "src/resolution.z"
while ( (i< module->num_items))
{
#line 185 "src/resolution.z"
_ZN3ast4ItemE*  item = &module->items[i];
;
#line 187 "src/resolution.z"
if ((item->kind== ItemKind_Use)){
#line 187 "src/resolution.z"
_ZN10resolution15import_wildcardE(ctx,item->node._use) ;
}
else {
#line 188 "src/resolution.z"
_ZN10resolution8add_itemE(ctx,module,item) ;
}
;
#line 189 "src/resolution.z"
i = ((( i32)(i))+ 1);
;
}
;
}
#line 193 "src/resolution.z"
 bool _ZN10resolution25check_if_sid_is_primitiveE(_ZN10resolution17ResolutionContextE*  ctx, _ZN9interning3SidE s, _ZN3ast11PrimitiveTyE*  prim) {
#line 195 "src/resolution.z"
_ZN10resolution17PrimitiveTypeSidsE*  p = &ctx->primitive_ty_sids;
;
#line 196 "src/resolution.z"
if ((s.x== p->_void.x)){
#line 196 "src/resolution.z"
prim->kind = PrimitiveTyKind_Void;
;
}
else {
#line 197 "src/resolution.z"
if ((s.x== p->_constvoid.x)){
#line 197 "src/resolution.z"
prim->kind = PrimitiveTyKind_ConstVoid;
;
}
else {
#line 198 "src/resolution.z"
if ((s.x== p->_bool.x)){
#line 198 "src/resolution.z"
prim->kind = PrimitiveTyKind_Bool;
;
}
else {
#line 199 "src/resolution.z"
if ((s.x== p->_char.x)){
#line 199 "src/resolution.z"
prim->kind = PrimitiveTyKind_Char;
;
}
else {
#line 200 "src/resolution.z"
if ((s.x== p->_constchar.x)){
#line 200 "src/resolution.z"
prim->kind = PrimitiveTyKind_ConstChar;
;
}
else {
#line 202 "src/resolution.z"
if ((s.x== p->_i8.x)){
#line 202 "src/resolution.z"
prim->kind = PrimitiveTyKind_Signed;
;
#line 202 "src/resolution.z"
prim->node.integer = IntegerSize_I8;
;
}
else {
#line 203 "src/resolution.z"
if ((s.x== p->_i16.x)){
#line 203 "src/resolution.z"
prim->kind = PrimitiveTyKind_Signed;
;
#line 203 "src/resolution.z"
prim->node.integer = IntegerSize_I16;
;
}
else {
#line 204 "src/resolution.z"
if ((s.x== p->_i32.x)){
#line 204 "src/resolution.z"
prim->kind = PrimitiveTyKind_Signed;
;
#line 204 "src/resolution.z"
prim->node.integer = IntegerSize_I32;
;
}
else {
#line 205 "src/resolution.z"
if ((s.x== p->_i64.x)){
#line 205 "src/resolution.z"
prim->kind = PrimitiveTyKind_Signed;
;
#line 205 "src/resolution.z"
prim->node.integer = IntegerSize_I64;
;
}
else {
#line 207 "src/resolution.z"
if ((s.x== p->_u8.x)){
#line 207 "src/resolution.z"
prim->kind = PrimitiveTyKind_Unsigned;
;
#line 207 "src/resolution.z"
prim->node.integer = IntegerSize_I8;
;
}
else {
#line 208 "src/resolution.z"
if ((s.x== p->_u16.x)){
#line 208 "src/resolution.z"
prim->kind = PrimitiveTyKind_Unsigned;
;
#line 208 "src/resolution.z"
prim->node.integer = IntegerSize_I16;
;
}
else {
#line 209 "src/resolution.z"
if ((s.x== p->_u32.x)){
#line 209 "src/resolution.z"
prim->kind = PrimitiveTyKind_Unsigned;
;
#line 209 "src/resolution.z"
prim->node.integer = IntegerSize_I32;
;
}
else {
#line 210 "src/resolution.z"
if ((s.x== p->_u64.x)){
#line 210 "src/resolution.z"
prim->kind = PrimitiveTyKind_Unsigned;
;
#line 210 "src/resolution.z"
prim->node.integer = IntegerSize_I64;
;
}
else {
#line 212 "src/resolution.z"
if ((s.x== p->_f32.x)){
#line 212 "src/resolution.z"
prim->kind = PrimitiveTyKind_Floating;
;
#line 212 "src/resolution.z"
prim->node.floating = FloatingSize_F32;
;
}
else {
#line 213 "src/resolution.z"
if ((s.x== p->_f64.x)){
#line 213 "src/resolution.z"
prim->kind = PrimitiveTyKind_Floating;
;
#line 213 "src/resolution.z"
prim->node.floating = FloatingSize_F64;
;
}
else {
#line 215 "src/resolution.z"
return false;
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
#line 217 "src/resolution.z"
return true;
;
}
#line 220 "src/resolution.z"
 void _ZN10resolution12resolve_pathE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4PathE*  path) {
#line 221 "src/resolution.z"
_ZN3ast11PrimitiveTyE prim ;
;
#line 223 "src/resolution.z"
if (_ZN10resolution25check_if_sid_is_primitiveE(ctx,path->segments[0].name,&prim) ){
#line 224 "src/resolution.z"
path->binding.kind = BindingKind_PrimitiveType;
;
#line 225 "src/resolution.z"
path->binding.node.primitive = prim;
;
}
else {
#line 227 "src/resolution.z"
if (((( i32)(path->num_segments))> 1)){
#line 228 "src/resolution.z"
_ZN3ast4PathE base_path = _ZN10resolution6lookupE(ctx,path->segments[0]) ;
;
#line 229 "src/resolution.z"
if ((base_path.binding.kind== BindingKind_Item)){
#line 230 "src/resolution.z"
_ZN3ast4ItemE*  item = base_path.binding.node.item;
;
#line 232 "src/resolution.z"
if ((item->kind== ItemKind_Enum)){
#line 234 "src/resolution.z"
_ZN3ast4PathE p ;
;
#line 235 "src/resolution.z"
p.num_segments = ((( i32)(base_path.num_segments))+ 1);
;
#line 236 "src/resolution.z"
p.segments = malloc((sizeof(_ZN3ast5IdentE)* (( u64)(p.num_segments)))) ;
;
#line 237 "src/resolution.z"
memcpy((( void* )(p.segments)),(( void* )(base_path.segments)),(( u64)(((( u64)(base_path.num_segments))* sizeof(_ZN3ast5IdentE))))) ;
#line 240 "src/resolution.z"
 u32 i = 0;
;
#line 241 "src/resolution.z"
_ZN3ast8EnumDataE data = item->node._enum;
;
#line 242 "src/resolution.z"
 bool found = false;
;
#line 243 "src/resolution.z"
while ( (i< data.num_variants))
{
#line 244 "src/resolution.z"
if ((data.variants[i].ident.name.x== path->segments[1].name.x)){
#line 245 "src/resolution.z"
p.segments[base_path.num_segments] = data.variants[i].ident;
;
#line 246 "src/resolution.z"
p.binding.kind = BindingKind_Variant;
;
#line 247 "src/resolution.z"
p.binding.node.variant = &data.variants[i];
;
#line 248 "src/resolution.z"
found = true;
;
#line 249 "src/resolution.z"
break;
;
}
;
#line 251 "src/resolution.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 253 "src/resolution.z"
if (!found){
#line 253 "src/resolution.z"
_ZN5error10emit_errorE(ctx->source_map,path->span,"Enum does not have requested variant") ;
}
;
#line 255 "src/resolution.z"
*path = p;
;
}
else {
#line 257 "src/resolution.z"
abort() ;
}
;
}
else {
#line 259 "src/resolution.z"
abort() ;
}
;
}
else {
#line 261 "src/resolution.z"
if (((( i32)(path->num_segments))== 1)){
#line 262 "src/resolution.z"
*path = _ZN10resolution6lookupE(ctx,path->segments[0]) ;
;
}
;
}
;
}
;
}
#line 266 "src/resolution.z"
 void _ZN10resolution12resolve_typeE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast7AstTypeE*  ty) {
#line 267 "src/resolution.z"
if ((ty->kind== AstTypeKind_Ptr)){
#line 268 "src/resolution.z"
_ZN10resolution12resolve_typeE(ctx,ty->node.ptr) ;
}
else {
#line 270 "src/resolution.z"
if ((ty->kind== AstTypeKind_Path)){
#line 271 "src/resolution.z"
_ZN10resolution12resolve_pathE(ctx,&ty->node.path) ;
}
;
}
;
}
#line 275 "src/resolution.z"
 void _ZN10resolution12resolve_exprE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 276 "src/resolution.z"
 void _ZN10resolution12resolve_itemE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 278 "src/resolution.z"
 void _ZN10resolution13resolve_unaryE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast9UnaryDataE unary) {
#line 279 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,unary.inner) ;
}
#line 282 "src/resolution.z"
 void _ZN10resolution14resolve_binaryE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast10BinaryDataE binary) {
#line 283 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,binary.left) ;
#line 284 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,binary.right) ;
}
#line 287 "src/resolution.z"
 void _ZN10resolution12resolve_callE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast8CallDataE call) {
#line 288 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,call.func) ;
#line 290 "src/resolution.z"
 u32 i = 0;
;
#line 291 "src/resolution.z"
while ( (i< call.num_args))
{
#line 292 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,call.args[i]) ;
#line 293 "src/resolution.z"
i = ((( i32)(i))+ 1);
;
}
;
}
#line 297 "src/resolution.z"
 void _ZN10resolution19resolve_conditionalE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast15ConditionalDataE cond) {
#line 298 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,cond.condition) ;
#line 299 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,cond.then) ;
#line 300 "src/resolution.z"
if ((( bool)(cond.otherwise))){
#line 301 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,cond.otherwise) ;
}
;
}
#line 305 "src/resolution.z"
 void _ZN10resolution13resolve_whileE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast9WhileDataE data) {
#line 306 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,data.condition) ;
#line 307 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,data.body) ;
}
#line 310 "src/resolution.z"
 void _ZN10resolution16resolve_indexingE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast12IndexingDataE idx) {
#line 311 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,idx.array) ;
#line 312 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,idx.index) ;
}
#line 315 "src/resolution.z"
 void _ZN10resolution13resolve_fieldE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast9FieldDataE field) {
#line 316 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,field.strct) ;
}
#line 319 "src/resolution.z"
 void _ZN10resolution18resolve_assignmentE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast14AssignmentDataE assignment) {
#line 320 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,assignment.left) ;
#line 321 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,assignment.right) ;
}
#line 324 "src/resolution.z"
 void _ZN10resolution13resolve_blockE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast5BlockE*  block) {
#line 326 "src/resolution.z"
_ZN10resolution10push_blockE(ctx) ;
#line 327 "src/resolution.z"
 u32 i = 0;
;
#line 328 "src/resolution.z"
while ( (i< block->num_exprs))
{
#line 329 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,block->exprs[i]) ;
#line 330 "src/resolution.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 332 "src/resolution.z"
_ZN10resolution9pop_blockE(ctx) ;
}
#line 335 "src/resolution.z"
 void _ZN10resolution13resolve_localE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast9LocalDataE*  data) {
#line 336 "src/resolution.z"
_ZN10resolution10push_localE(ctx,data->pat.ident,data) ;
#line 337 "src/resolution.z"
_ZN10resolution12resolve_typeE(ctx,data->ast_ty) ;
#line 338 "src/resolution.z"
if ((( bool)(data->value))){
#line 338 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,data->value) ;
}
;
}
#line 341 "src/resolution.z"
 void _ZN10resolution14resolve_sizeofE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4ExprE*  expr) {
#line 342 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,expr) ;
}
#line 345 "src/resolution.z"
 void _ZN10resolution12resolve_castE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast8CastDataE*  data) {
#line 346 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,data->inner) ;
#line 347 "src/resolution.z"
_ZN10resolution12resolve_typeE(ctx,data->ast_ty) ;
}
#line 350 "src/resolution.z"
 void _ZN10resolution12resolve_exprE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4ExprE*  expr) {
#line 351 "src/resolution.z"
if ((expr->kind== ExprKind_Unary)){
#line 351 "src/resolution.z"
_ZN10resolution13resolve_unaryE(ctx,expr->node.unary) ;
}
else {
#line 352 "src/resolution.z"
if ((expr->kind== ExprKind_Binary)){
#line 352 "src/resolution.z"
_ZN10resolution14resolve_binaryE(ctx,expr->node.binary) ;
}
else {
#line 353 "src/resolution.z"
if ((expr->kind== ExprKind_Block)){
#line 353 "src/resolution.z"
_ZN10resolution13resolve_blockE(ctx,expr->node.block) ;
}
else {
#line 354 "src/resolution.z"
if ((expr->kind== ExprKind_Call)){
#line 354 "src/resolution.z"
_ZN10resolution12resolve_callE(ctx,expr->node.call) ;
}
else {
#line 355 "src/resolution.z"
if ((expr->kind== ExprKind_Conditional)){
#line 355 "src/resolution.z"
_ZN10resolution19resolve_conditionalE(ctx,expr->node.conditional) ;
}
else {
#line 356 "src/resolution.z"
if ((expr->kind== ExprKind_While)){
#line 356 "src/resolution.z"
_ZN10resolution13resolve_whileE(ctx,expr->node.whl) ;
}
else {
#line 357 "src/resolution.z"
if ((expr->kind== ExprKind_Indexing)){
#line 357 "src/resolution.z"
_ZN10resolution16resolve_indexingE(ctx,expr->node.indexing) ;
}
else {
#line 358 "src/resolution.z"
if ((expr->kind== ExprKind_Field)){
#line 358 "src/resolution.z"
_ZN10resolution13resolve_fieldE(ctx,expr->node.field) ;
}
else {
#line 359 "src/resolution.z"
if ((expr->kind== ExprKind_Path)){
#line 359 "src/resolution.z"
_ZN10resolution12resolve_pathE(ctx,&expr->node.path) ;
}
else {
#line 360 "src/resolution.z"
if ((expr->kind== ExprKind_Assignment)){
#line 360 "src/resolution.z"
_ZN10resolution18resolve_assignmentE(ctx,expr->node.assignment) ;
}
else {
#line 361 "src/resolution.z"
if ((expr->kind== ExprKind_Local)){
#line 361 "src/resolution.z"
_ZN10resolution13resolve_localE(ctx,&expr->node.local) ;
}
else {
#line 362 "src/resolution.z"
if ((expr->kind== ExprKind_Return)){
#line 362 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,expr->node._return) ;
}
else {
#line 363 "src/resolution.z"
if ((expr->kind== ExprKind_Literal)){
}
else {
#line 364 "src/resolution.z"
if ((expr->kind== ExprKind_ControlFlow)){
}
else {
#line 365 "src/resolution.z"
if ((expr->kind== ExprKind_Sizeof)){
#line 365 "src/resolution.z"
_ZN10resolution14resolve_sizeofE(ctx,expr->node._sizeof) ;
}
else {
#line 366 "src/resolution.z"
if ((expr->kind== ExprKind_Cast)){
#line 366 "src/resolution.z"
_ZN10resolution12resolve_castE(ctx,&expr->node._cast) ;
}
else {
#line 367 "src/resolution.z"
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
#line 370 "src/resolution.z"
 void _ZN10resolution16resolve_functionE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 371 "src/resolution.z"
_ZN3ast12FunctionDataE func = item->node.function;
;
#line 373 "src/resolution.z"
_ZN10resolution12resolve_typeE(ctx,func.header.output_ast_ty) ;
#line 374 "src/resolution.z"
 u32 i = 0;
;
#line 375 "src/resolution.z"
while ( (i< func.header.num_parameters))
{
#line 376 "src/resolution.z"
_ZN3ast17FunctionParameterE*  param = &func.header.parameters[i];
;
#line 377 "src/resolution.z"
_ZN10resolution12resolve_typeE(ctx,param->ast_ty) ;
#line 378 "src/resolution.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 381 "src/resolution.z"
if ((( bool)(func.body))){
#line 382 "src/resolution.z"
_ZN10resolution10push_blockE(ctx) ;
#line 383 "src/resolution.z"
 u32 i = 0;
;
#line 384 "src/resolution.z"
while ( (i< func.header.num_parameters))
{
#line 385 "src/resolution.z"
_ZN3ast17FunctionParameterE*  param = &func.header.parameters[i];
;
#line 386 "src/resolution.z"
_ZN10resolution14push_parameterE(ctx,param->pat.ident,param) ;
#line 388 "src/resolution.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 391 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,item->node.function.body) ;
#line 392 "src/resolution.z"
_ZN10resolution9pop_blockE(ctx) ;
}
;
}
#line 396 "src/resolution.z"
 void _ZN10resolution16resolve_variableE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 397 "src/resolution.z"
_ZN10resolution12resolve_typeE(ctx,item->node.variable.ast_ty) ;
#line 398 "src/resolution.z"
_ZN10resolution10push_blockE(ctx) ;
#line 399 "src/resolution.z"
if ((( bool)(item->node.variable.body))){
#line 400 "src/resolution.z"
_ZN10resolution12resolve_exprE(ctx,item->node.variable.body) ;
}
;
#line 402 "src/resolution.z"
_ZN10resolution9pop_blockE(ctx) ;
}
#line 405 "src/resolution.z"
 void _ZN10resolution16resolve_compoundE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 407 "src/resolution.z"
_ZN3ast12CompoundDataE data = item->node.compound;
;
#line 409 "src/resolution.z"
 u32 i = 0;
;
#line 410 "src/resolution.z"
while ( (i< data.num_fields))
{
#line 411 "src/resolution.z"
_ZN10resolution12resolve_typeE(ctx,data.fields[i].ast_ty) ;
#line 412 "src/resolution.z"
i = ((( i32)(i))+ 1);
;
}
;
}
#line 416 "src/resolution.z"
 void _ZN10resolution12resolve_itemE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 417 "src/resolution.z"
if (((item->kind== ItemKind_Const)|| (item->kind== ItemKind_Variable))){
#line 417 "src/resolution.z"
_ZN10resolution16resolve_variableE(ctx,item) ;
}
;
#line 418 "src/resolution.z"
if ((item->kind== ItemKind_Function)){
#line 418 "src/resolution.z"
_ZN10resolution16resolve_functionE(ctx,item) ;
}
;
#line 419 "src/resolution.z"
if (((item->kind== ItemKind_Struct)|| (item->kind== ItemKind_Union))){
#line 419 "src/resolution.z"
_ZN10resolution16resolve_compoundE(ctx,item) ;
}
;
}
#line 422 "src/resolution.z"
 void _ZN10resolution14resolve_moduleE(_ZN10resolution17ResolutionContextE*  ctx, _ZN3ast6ModuleE*  module) {
#line 424 "src/resolution.z"
 u32 i = 0;
;
#line 425 "src/resolution.z"
while ( (i< module->num_items))
{
#line 426 "src/resolution.z"
_ZN10resolution12resolve_itemE(ctx,&module->items[i]) ;
#line 427 "src/resolution.z"
i = ((( i32)(i))+ 1);
;
}
;
}
#line 431 "src/resolution.z"
 void _ZN10resolution13resolve_namesE(_ZN7session7SessionE*  sess, _ZN3ast6ModuleE*  module) {
#line 432 "src/resolution.z"
_ZN10resolution17ResolutionContextE ctx ;
;
#line 434 "src/resolution.z"
ctx.interner = &sess->interner;
;
#line 435 "src/resolution.z"
_ZN10resolution23setup_primitive_ty_sidsE(ctx.interner,&ctx.primitive_ty_sids) ;
#line 436 "src/resolution.z"
ctx.scope_stack = malloc((sizeof(_ZN10resolution5ScopeE)* (( u64)(128)))) ;
;
#line 437 "src/resolution.z"
ctx.stack_top = 0;
;
#line 438 "src/resolution.z"
ctx.source_map = &sess->source;
;
#line 439 "src/resolution.z"
ctx.index_lookup = _ZN6intmap13intmap_createE((( u64)(2048))) ;
;
#line 440 "src/resolution.z"
ctx.index = malloc((sizeof(_ZN10resolution10IndexEntryE)* (( u64)(2048)))) ;
;
#line 441 "src/resolution.z"
ctx.num_indices = 1;
;
#line 444 "src/resolution.z"
_ZN10resolution12index_moduleE(&ctx,module) ;
#line 445 "src/resolution.z"
_ZN10resolution14resolve_moduleE(&ctx,module) ;
}
#line 39 "src/typecheck.z"
 u64 _ZN9typecheck7hash_tyE(_ZN3ast2TyE*  ty) ;
#line 41 "src/typecheck.z"
 u64 _ZN9typecheck7hash_fnE(_ZN3ast2TyE*  ty) {
#line 43 "src/typecheck.z"
_ZN3ast5FnDefE def = ty->node.function;
;
#line 44 "src/typecheck.z"
 u64 h = _ZN9typecheck7hash_tyE(def.output) ;
;
#line 46 "src/typecheck.z"
 u32 i = 0;
;
#line 47 "src/typecheck.z"
while ( (i< def.num_parameters))
{
#line 48 "src/typecheck.z"
h = (h^ (((_ZN9typecheck7hash_tyE(def.parameters[i]) + (( u64)(2654435769)))+ (h<< (( u64)(6))))+ (h>> (( u64)(2)))));
;
#line 49 "src/typecheck.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 51 "src/typecheck.z"
return h;
;
}
#line 54 "src/typecheck.z"
 u64 _ZN9typecheck9hash_pathE(_ZN3ast4PathE path) {
#line 55 "src/typecheck.z"
 u64 h = path.num_segments;
;
#line 56 "src/typecheck.z"
 u32 i = 0;
;
#line 57 "src/typecheck.z"
while ( (i< path.num_segments))
{
#line 58 "src/typecheck.z"
h = ((h<< (( u64)(8)))| (( u64)(path.segments[i].name.x)));
;
#line 59 "src/typecheck.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 61 "src/typecheck.z"
return h;
;
}
#line 64 "src/typecheck.z"
 u64 _ZN9typecheck7hash_tyE(_ZN3ast2TyE*  ty) {
#line 66 "src/typecheck.z"
 u64 h ;
;
#line 68 "src/typecheck.z"
h = ty->kind;
;
#line 70 "src/typecheck.z"
if (((ty->kind== TyKind_Signed)|| (ty->kind== TyKind_Unsigned))){
#line 70 "src/typecheck.z"
h = (h^ (( u64)(((( i32)(_ZN3ast12integer_sizeE(ty->node.integer) ))<< 4))));
;
}
else {
#line 71 "src/typecheck.z"
if ((ty->kind== TyKind_Floating)){
#line 71 "src/typecheck.z"
h = (h^ (( u64)(((( i32)(_ZN3ast13floating_sizeE(ty->node.floating) ))<< 4))));
;
}
else {
#line 72 "src/typecheck.z"
if (((ty->kind== TyKind_Struct)|| (ty->kind== TyKind_Union))){
#line 72 "src/typecheck.z"
h = (h^ (_ZN9typecheck9hash_pathE(ty->node.compound.path) << (( u64)(4))));
;
}
else {
#line 73 "src/typecheck.z"
if ((ty->kind== TyKind_Enum)){
#line 73 "src/typecheck.z"
h = (h^ (_ZN9typecheck9hash_pathE(ty->node._enum.path) << (( u64)(4))));
;
}
else {
#line 74 "src/typecheck.z"
if ((ty->kind== TyKind_Fn)){
#line 74 "src/typecheck.z"
h = (h^ (_ZN9typecheck7hash_fnE(ty) << (( u64)(4))));
;
}
else {
#line 75 "src/typecheck.z"
if ((ty->kind== TyKind_Ptr)){
#line 75 "src/typecheck.z"
h = (h^ (_ZN9typecheck7hash_tyE(ty->node.ptr) << (( u64)(4))));
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
#line 77 "src/typecheck.z"
return h;
;
}
#line 80 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck9intern_tyE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast2TyE ty) {
#line 81 "src/typecheck.z"
 u64 h = _ZN9typecheck7hash_tyE(&ty) ;
;
#line 82 "src/typecheck.z"
 u32 ty_idx = _ZN6intmap13intmap_lookupE(ctx->types_lookup,h) ;
;
#line 83 "src/typecheck.z"
if (((( i32)(ty_idx))== 0)){
#line 84 "src/typecheck.z"
ty_idx = ctx->next_type_idx;
;
#line 85 "src/typecheck.z"
ctx->next_type_idx = ((( i32)(ctx->next_type_idx))+ 1);
;
#line 86 "src/typecheck.z"
_ZN6intmap13intmap_insertE(ctx->types_lookup,h,(( u64)(ty_idx))) ;
#line 87 "src/typecheck.z"
ctx->types[ty_idx] = ty;
;
}
;
#line 89 "src/typecheck.z"
return &ctx->types[ty_idx];
;
}
#line 92 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck16create_base_typeE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast6TyKindE kind) {
#line 93 "src/typecheck.z"
_ZN3ast2TyE ty ;
;
#line 94 "src/typecheck.z"
ty.kind = kind;
;
#line 95 "src/typecheck.z"
return _ZN9typecheck9intern_tyE(ctx,ty) ;
;
}
#line 98 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck17create_float_typeE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast12FloatingSizeE size) {
#line 99 "src/typecheck.z"
_ZN3ast2TyE ty ;
;
#line 100 "src/typecheck.z"
ty.kind = TyKind_Floating;
;
#line 101 "src/typecheck.z"
ty.node.floating = size;
;
#line 102 "src/typecheck.z"
return _ZN9typecheck9intern_tyE(ctx,ty) ;
;
}
#line 105 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck15create_int_typeE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast6TyKindE kind, _ZN3ast11IntegerSizeE size) {
#line 106 "src/typecheck.z"
_ZN3ast2TyE ty ;
;
#line 107 "src/typecheck.z"
ty.kind = kind;
;
#line 108 "src/typecheck.z"
ty.node.integer = size;
;
#line 109 "src/typecheck.z"
return _ZN9typecheck9intern_tyE(ctx,ty) ;
;
}
#line 112 "src/typecheck.z"
 void _ZN9typecheck19create_common_typesE(_ZN9typecheck11TypeContextE*  ctx) {
#line 113 "src/typecheck.z"
_ZN9typecheck11CommonTypesE*  t = &ctx->common;
;
#line 114 "src/typecheck.z"
t->_void = _ZN9typecheck16create_base_typeE(ctx,TyKind_Void) ;
;
#line 115 "src/typecheck.z"
t->_constvoid = _ZN9typecheck16create_base_typeE(ctx,TyKind_ConstVoid) ;
;
#line 116 "src/typecheck.z"
t->_variadic = _ZN9typecheck16create_base_typeE(ctx,TyKind_Variadic) ;
;
#line 117 "src/typecheck.z"
t->_bool = _ZN9typecheck16create_base_typeE(ctx,TyKind_Bool) ;
;
#line 118 "src/typecheck.z"
t->_char = _ZN9typecheck16create_base_typeE(ctx,TyKind_Char) ;
;
#line 119 "src/typecheck.z"
t->_constchar = _ZN9typecheck16create_base_typeE(ctx,TyKind_ConstChar) ;
;
#line 121 "src/typecheck.z"
t->_i8 = _ZN9typecheck15create_int_typeE(ctx,TyKind_Signed,IntegerSize_I8) ;
;
#line 122 "src/typecheck.z"
t->_i16 = _ZN9typecheck15create_int_typeE(ctx,TyKind_Signed,IntegerSize_I16) ;
;
#line 123 "src/typecheck.z"
t->_i32 = _ZN9typecheck15create_int_typeE(ctx,TyKind_Signed,IntegerSize_I32) ;
;
#line 124 "src/typecheck.z"
t->_i64 = _ZN9typecheck15create_int_typeE(ctx,TyKind_Signed,IntegerSize_I64) ;
;
#line 126 "src/typecheck.z"
t->_u8 = _ZN9typecheck15create_int_typeE(ctx,TyKind_Unsigned,IntegerSize_I8) ;
;
#line 127 "src/typecheck.z"
t->_u16 = _ZN9typecheck15create_int_typeE(ctx,TyKind_Unsigned,IntegerSize_I16) ;
;
#line 128 "src/typecheck.z"
t->_u32 = _ZN9typecheck15create_int_typeE(ctx,TyKind_Unsigned,IntegerSize_I32) ;
;
#line 129 "src/typecheck.z"
t->_u64 = _ZN9typecheck15create_int_typeE(ctx,TyKind_Unsigned,IntegerSize_I64) ;
;
#line 131 "src/typecheck.z"
t->_f32 = _ZN9typecheck17create_float_typeE(ctx,FloatingSize_F32) ;
;
#line 132 "src/typecheck.z"
t->_f64 = _ZN9typecheck17create_float_typeE(ctx,FloatingSize_F64) ;
;
}
#line 135 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck14ast_type_to_tyE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast7AstTypeE*  ast_ty) ;
#line 137 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck15primitive_to_tyE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast11PrimitiveTyE prim) {
#line 138 "src/typecheck.z"
_ZN9typecheck11CommonTypesE*  t = &ctx->common;
;
#line 139 "src/typecheck.z"
if ((prim.kind== PrimitiveTyKind_Void)){
#line 139 "src/typecheck.z"
return t->_void;
;
}
else {
#line 140 "src/typecheck.z"
if ((prim.kind== PrimitiveTyKind_Bool)){
#line 140 "src/typecheck.z"
return t->_bool;
;
}
else {
#line 141 "src/typecheck.z"
if ((prim.kind== PrimitiveTyKind_Char)){
#line 141 "src/typecheck.z"
return t->_char;
;
}
else {
#line 143 "src/typecheck.z"
if ((prim.kind== PrimitiveTyKind_ConstChar)){
#line 143 "src/typecheck.z"
return t->_constchar;
;
}
else {
#line 144 "src/typecheck.z"
if ((prim.kind== PrimitiveTyKind_ConstVoid)){
#line 144 "src/typecheck.z"
return t->_constvoid;
;
}
else {
#line 146 "src/typecheck.z"
if ((prim.kind== PrimitiveTyKind_Signed)){
#line 147 "src/typecheck.z"
if ((prim.node.integer== IntegerSize_I8)){
#line 147 "src/typecheck.z"
return t->_i8;
;
}
else {
#line 148 "src/typecheck.z"
if ((prim.node.integer== IntegerSize_I16)){
#line 148 "src/typecheck.z"
return t->_i16;
;
}
else {
#line 149 "src/typecheck.z"
if ((prim.node.integer== IntegerSize_I32)){
#line 149 "src/typecheck.z"
return t->_i32;
;
}
else {
#line 150 "src/typecheck.z"
if ((prim.node.integer== IntegerSize_I64)){
#line 150 "src/typecheck.z"
return t->_i64;
;
}
else {
#line 151 "src/typecheck.z"
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
else {
#line 153 "src/typecheck.z"
if ((prim.kind== PrimitiveTyKind_Unsigned)){
#line 154 "src/typecheck.z"
if ((prim.node.integer== IntegerSize_I8)){
#line 154 "src/typecheck.z"
return t->_u8;
;
}
else {
#line 155 "src/typecheck.z"
if ((prim.node.integer== IntegerSize_I16)){
#line 155 "src/typecheck.z"
return t->_u16;
;
}
else {
#line 156 "src/typecheck.z"
if ((prim.node.integer== IntegerSize_I32)){
#line 156 "src/typecheck.z"
return t->_u32;
;
}
else {
#line 157 "src/typecheck.z"
if ((prim.node.integer== IntegerSize_I64)){
#line 157 "src/typecheck.z"
return t->_u64;
;
}
else {
#line 158 "src/typecheck.z"
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
else {
#line 160 "src/typecheck.z"
if ((prim.kind== PrimitiveTyKind_Floating)){
#line 161 "src/typecheck.z"
if ((prim.node.floating== FloatingSize_F32)){
#line 161 "src/typecheck.z"
return t->_f32;
;
}
else {
#line 162 "src/typecheck.z"
if ((prim.node.floating== FloatingSize_F64)){
#line 162 "src/typecheck.z"
return t->_f64;
;
}
else {
#line 163 "src/typecheck.z"
abort() ;
}
;
}
;
}
else {
#line 165 "src/typecheck.z"
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
#line 168 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck14ast_path_to_tyE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast7AstTypeE*  ast_ty) {
#line 169 "src/typecheck.z"
_ZN3ast7BindingE binding = ast_ty->node.path.binding;
;
#line 171 "src/typecheck.z"
if ((binding.kind== BindingKind_PrimitiveType)){
#line 172 "src/typecheck.z"
return _ZN9typecheck15primitive_to_tyE(ctx,binding.node.primitive) ;
;
}
else {
#line 174 "src/typecheck.z"
if ((binding.kind== BindingKind_Item)){
#line 175 "src/typecheck.z"
_ZN3ast4ItemE*  item = binding.node.item;
;
#line 176 "src/typecheck.z"
if (((item->kind== ItemKind_Struct)|| (item->kind== ItemKind_Union))){
#line 176 "src/typecheck.z"
return item->node.compound.ty;
;
}
else {
#line 177 "src/typecheck.z"
if ((item->kind== ItemKind_Function)){
#line 177 "src/typecheck.z"
return item->node.function.header.ty;
;
}
else {
#line 178 "src/typecheck.z"
if ((item->kind== ItemKind_Enum)){
#line 178 "src/typecheck.z"
return item->node._enum.ty;
;
}
else {
#line 179 "src/typecheck.z"
return _ZN4cstd4nullE;
;
}
;
}
;
}
;
}
else {
#line 181 "src/typecheck.z"
abort() ;
}
;
}
;
}
#line 184 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck13ast_ptr_to_tyE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast7AstTypeE*  ast_ty) {
#line 185 "src/typecheck.z"
_ZN3ast2TyE ty ;
;
#line 186 "src/typecheck.z"
ty.kind = TyKind_Ptr;
;
#line 187 "src/typecheck.z"
ty.node.ptr = _ZN9typecheck14ast_type_to_tyE(ctx,ast_ty->node.ptr) ;
;
#line 188 "src/typecheck.z"
return _ZN9typecheck9intern_tyE(ctx,ty) ;
;
}
#line 191 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck14ast_type_to_tyE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast7AstTypeE*  ast_ty) {
#line 192 "src/typecheck.z"
if ((ast_ty->kind== AstTypeKind_Void)){
#line 192 "src/typecheck.z"
return ctx->common._void;
;
}
else {
#line 193 "src/typecheck.z"
if ((ast_ty->kind== AstTypeKind_Path)){
#line 193 "src/typecheck.z"
return _ZN9typecheck14ast_path_to_tyE(ctx,ast_ty) ;
;
}
else {
#line 194 "src/typecheck.z"
if ((ast_ty->kind== AstTypeKind_Ptr)){
#line 194 "src/typecheck.z"
return _ZN9typecheck13ast_ptr_to_tyE(ctx,ast_ty) ;
;
}
else {
#line 195 "src/typecheck.z"
if ((ast_ty->kind== AstTypeKind_Variadic)){
#line 195 "src/typecheck.z"
return ctx->common._variadic;
;
}
else {
#line 196 "src/typecheck.z"
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
#line 199 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck17ast_literal_to_tyE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast7LiteralE lit) {
#line 200 "src/typecheck.z"
if ((lit.kind== LiteralKind_Int)){
#line 200 "src/typecheck.z"
return ctx->common._i32;
;
}
else {
#line 201 "src/typecheck.z"
if ((lit.kind== LiteralKind_Float)){
#line 201 "src/typecheck.z"
return ctx->common._f32;
;
}
else {
#line 202 "src/typecheck.z"
if ((lit.kind== LiteralKind_Bool)){
#line 202 "src/typecheck.z"
return ctx->common._bool;
;
}
else {
#line 203 "src/typecheck.z"
if ((lit.kind== LiteralKind_Char)){
#line 203 "src/typecheck.z"
return ctx->common._char;
;
}
else {
#line 204 "src/typecheck.z"
if ((lit.kind== LiteralKind_Str)){
#line 205 "src/typecheck.z"
_ZN3ast2TyE str_ty ;
;
#line 206 "src/typecheck.z"
str_ty.kind = TyKind_Ptr;
;
#line 207 "src/typecheck.z"
str_ty.node.ptr = ctx->common._char;
;
#line 208 "src/typecheck.z"
return _ZN9typecheck9intern_tyE(ctx,str_ty) ;
;
}
else {
#line 210 "src/typecheck.z"
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
#line 213 "src/typecheck.z"
 u32 _ZN9typecheck11coerce_typeE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast2TyE*  from, _ZN3ast2TyE*  to) {
#line 215 "src/typecheck.z"
if ((from== to)){
#line 215 "src/typecheck.z"
return 1;
;
}
else {
#line 216 "src/typecheck.z"
if ((to->kind== TyKind_Variadic)){
#line 216 "src/typecheck.z"
return 1;
;
}
else {
#line 217 "src/typecheck.z"
if (((from->kind== TyKind_Signed)|| (from->kind== TyKind_Unsigned))){
#line 218 "src/typecheck.z"
 u32 from_size = _ZN3ast12integer_sizeE(from->node.integer) ;
;
#line 220 "src/typecheck.z"
if (((to->kind== TyKind_Signed)|| (to->kind== TyKind_Unsigned))){
#line 221 "src/typecheck.z"
 u32 to_size = _ZN3ast12integer_sizeE(to->node.integer) ;
;
#line 222 "src/typecheck.z"
if ((from_size<= to_size)){
#line 222 "src/typecheck.z"
return 2;
;
}
;
}
;
#line 224 "src/typecheck.z"
if ((to->kind== TyKind_Bool)){
#line 224 "src/typecheck.z"
return 2;
;
}
;
#line 226 "src/typecheck.z"
if ((to->kind== TyKind_Ptr)){
#line 226 "src/typecheck.z"
return 2;
;
}
;
}
else {
#line 228 "src/typecheck.z"
if ((from->kind== TyKind_Ptr)){
#line 229 "src/typecheck.z"
_ZN3ast2TyE*  inner_from = from->node.ptr;
;
#line 231 "src/typecheck.z"
if ((to->kind== TyKind_Bool)){
#line 231 "src/typecheck.z"
return 2;
;
}
else {
#line 233 "src/typecheck.z"
if ((to->kind== TyKind_Ptr)){
#line 234 "src/typecheck.z"
_ZN3ast2TyE*  inner_to = to->node.ptr;
;
#line 235 "src/typecheck.z"
if (((inner_from->kind== TyKind_Void)|| (inner_from->kind== TyKind_ConstVoid))){
#line 235 "src/typecheck.z"
return 2;
;
}
;
#line 236 "src/typecheck.z"
if (((inner_to->kind== TyKind_Void)|| (inner_to->kind== TyKind_ConstVoid))){
#line 236 "src/typecheck.z"
return 2;
;
}
;
#line 238 "src/typecheck.z"
if (((inner_from->kind== TyKind_Char)&& (inner_to->kind== TyKind_ConstChar))){
#line 238 "src/typecheck.z"
return 2;
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
#line 241 "src/typecheck.z"
return 0;
;
}
#line 244 "src/typecheck.z"
 void _ZN9typecheck18coerce_binary_exprE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr, _ZN3ast2TyE*  left, _ZN3ast2TyE*  right) {
#line 246 "src/typecheck.z"
 u32 coerce_left = _ZN9typecheck11coerce_typeE(ctx,left,right) ;
;
#line 247 "src/typecheck.z"
 u32 coerce_right = _ZN9typecheck11coerce_typeE(ctx,right,left) ;
;
#line 249 "src/typecheck.z"
if ((((( i32)(coerce_left))== 1)|| ((( i32)(coerce_right))== 1))){
}
else {
#line 250 "src/typecheck.z"
if (((( i32)(coerce_left))== 2)){
#line 251 "src/typecheck.z"
_ZN3ast4ExprE*  cast_expr = _ZN3ast11create_exprE(ExprKind_Cast) ;
;
#line 252 "src/typecheck.z"
cast_expr->node._cast.ty = right;
;
#line 253 "src/typecheck.z"
cast_expr->node._cast.inner = expr->node.binary.left;
;
#line 254 "src/typecheck.z"
expr->node.binary.left = cast_expr;
;
}
else {
#line 256 "src/typecheck.z"
if (((( i32)(coerce_right))== 2)){
#line 257 "src/typecheck.z"
_ZN3ast4ExprE*  cast_expr = _ZN3ast11create_exprE(ExprKind_Cast) ;
;
#line 258 "src/typecheck.z"
cast_expr->node._cast.ty = left;
;
#line 259 "src/typecheck.z"
cast_expr->node._cast.inner = expr->node.binary.right;
;
#line 260 "src/typecheck.z"
expr->node.binary.right = cast_expr;
;
}
else {
#line 262 "src/typecheck.z"
_ZN5error10emit_errorE(ctx->source_map,expr->span,"Cannot coerce type in binary expression") ;
}
;
}
;
}
;
}
#line 265 "src/typecheck.z"
_ZN3ast4ExprE*  _ZN9typecheck16coerce_expr_typeE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr, _ZN3ast2TyE*  from, _ZN3ast2TyE*  to) {
#line 266 "src/typecheck.z"
 u32 can_coerce = _ZN9typecheck11coerce_typeE(ctx,from,to) ;
;
#line 267 "src/typecheck.z"
if (((( i32)(can_coerce))== 1)){
#line 267 "src/typecheck.z"
return expr;
;
}
else {
#line 268 "src/typecheck.z"
if (((( i32)(can_coerce))== 2)){
#line 269 "src/typecheck.z"
_ZN3ast4ExprE*  cast_expr = _ZN3ast11create_exprE(ExprKind_Cast) ;
;
#line 270 "src/typecheck.z"
cast_expr->node._cast.ty = to;
;
#line 271 "src/typecheck.z"
cast_expr->node._cast.inner = expr;
;
#line 272 "src/typecheck.z"
return cast_expr;
;
}
else {
#line 274 "src/typecheck.z"
_ZN5error10emit_errorE(ctx->source_map,expr->span,"Cannot coerce type") ;
}
;
}
;
#line 275 "src/typecheck.z"
abort() ;
}
#line 278 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck10check_exprE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 279 "src/typecheck.z"
 void _ZN9typecheck10check_itemE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 280 "src/typecheck.z"
 void _ZN9typecheck9check_modE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast6ModuleE*  module) ;
#line 282 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck11check_unaryE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) {
#line 283 "src/typecheck.z"
_ZN3ast2TyE*  inner_ty = _ZN9typecheck10check_exprE(ctx,expr->node.unary.inner) ;
;
#line 284 "src/typecheck.z"
_ZN3ast17UnaryOperatorKindE op = expr->node.unary.op;
;
#line 285 "src/typecheck.z"
if ((op== UnaryOperatorKind_Deref)){
#line 286 "src/typecheck.z"
if ((inner_ty->kind== TyKind_Ptr)){
#line 287 "src/typecheck.z"
return inner_ty->node.ptr;
;
}
else {
#line 289 "src/typecheck.z"
_ZN5error10emit_errorE(ctx->source_map,expr->span,"Trying to deref non-pointer") ;
}
;
}
else {
#line 291 "src/typecheck.z"
if ((op== UnaryOperatorKind_Refer)){
#line 292 "src/typecheck.z"
_ZN3ast2TyE ptr_ty ;
;
#line 293 "src/typecheck.z"
ptr_ty.kind = TyKind_Ptr;
;
#line 294 "src/typecheck.z"
ptr_ty.node.ptr = inner_ty;
;
#line 295 "src/typecheck.z"
return _ZN9typecheck9intern_tyE(ctx,ptr_ty) ;
;
}
else {
#line 297 "src/typecheck.z"
if ((op== UnaryOperatorKind_Negation)){
#line 298 "src/typecheck.z"
return inner_ty;
;
}
else {
#line 300 "src/typecheck.z"
if ((op== UnaryOperatorKind_Complement)){
#line 301 "src/typecheck.z"
expr->node.unary.inner = _ZN9typecheck16coerce_expr_typeE(ctx,expr->node.unary.inner,inner_ty,ctx->common._bool) ;
;
#line 302 "src/typecheck.z"
return ctx->common._bool;
;
}
;
}
;
}
;
}
;
#line 304 "src/typecheck.z"
abort() ;
}
#line 307 "src/typecheck.z"
 bool _ZN9typecheck19operator_is_booleanE(_ZN3ast18BinaryOperatorKindE op) {
#line 308 "src/typecheck.z"
return ((((((((op== BinaryOperatorKind_Less)|| (op== BinaryOperatorKind_LessEq))|| (op== BinaryOperatorKind_NotEq))|| (op== BinaryOperatorKind_Greater))|| (op== BinaryOperatorKind_GreaterEq))|| (op== BinaryOperatorKind_Equality))|| (op== BinaryOperatorKind_And))|| (op== BinaryOperatorKind_Or));
;
}
#line 313 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck12check_binaryE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) {
#line 314 "src/typecheck.z"
_ZN3ast18BinaryOperatorKindE op = expr->node.binary.op;
;
#line 315 "src/typecheck.z"
_ZN3ast2TyE*  left = _ZN9typecheck10check_exprE(ctx,expr->node.binary.left) ;
;
#line 316 "src/typecheck.z"
_ZN3ast2TyE*  right = _ZN9typecheck10check_exprE(ctx,expr->node.binary.right) ;
;
#line 318 "src/typecheck.z"
_ZN9typecheck18coerce_binary_exprE(ctx,expr,left,right) ;
#line 320 "src/typecheck.z"
if (_ZN9typecheck19operator_is_booleanE(op) ){
#line 320 "src/typecheck.z"
return ctx->common._bool;
;
}
else {
#line 321 "src/typecheck.z"
return left;
;
}
;
}
#line 324 "src/typecheck.z"
 void _ZN9typecheck11check_blockE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast5BlockE*  block) {
#line 325 "src/typecheck.z"
 u32 i = 0;
;
#line 326 "src/typecheck.z"
while ( (i< block->num_exprs))
{
#line 327 "src/typecheck.z"
_ZN9typecheck10check_exprE(ctx,block->exprs[i]) ;
#line 328 "src/typecheck.z"
i = ((( i32)(i))+ 1);
;
}
;
}
#line 332 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck16check_block_exprE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) {
#line 333 "src/typecheck.z"
_ZN9typecheck11check_blockE(ctx,expr->node.block) ;
#line 334 "src/typecheck.z"
return ctx->common._void;
;
}
#line 337 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck10check_callE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) {
#line 338 "src/typecheck.z"
_ZN3ast8CallDataE call = expr->node.call;
;
#line 339 "src/typecheck.z"
_ZN3ast2TyE*  fn_ty = _ZN9typecheck10check_exprE(ctx,call.func) ;
;
#line 340 "src/typecheck.z"
if ((fn_ty->kind!= TyKind_Fn)){
#line 340 "src/typecheck.z"
_ZN5error12emit_warningE(ctx->source_map,expr->span,"Tried to call non-function") ;
}
;
#line 342 "src/typecheck.z"
_ZN3ast5FnDefE*  fn_def = &fn_ty->node.function;
;
#line 344 "src/typecheck.z"
 bool is_variadic = false;
;
#line 345 "src/typecheck.z"
if (((( i32)(fn_def->num_parameters))> 0)){
#line 346 "src/typecheck.z"
_ZN3ast2TyE*  param_ty = fn_def->parameters[((( i32)(fn_def->num_parameters))- 1)];
;
#line 347 "src/typecheck.z"
is_variadic = (param_ty->kind== TyKind_Variadic);
;
}
;
#line 350 "src/typecheck.z"
if (((call.num_args== fn_def->num_parameters)|| ((call.num_args>= ((( i32)(fn_def->num_parameters))- 1))&& is_variadic))){
#line 351 "src/typecheck.z"
 i32 i = 0;
;
#line 352 "src/typecheck.z"
while ( ((( u32)(i))< call.num_args))
{
#line 353 "src/typecheck.z"
_ZN3ast2TyE*  arg_ty = _ZN9typecheck10check_exprE(ctx,call.args[i]) ;
;
#line 354 "src/typecheck.z"
if (((( u32)(i))< fn_def->num_parameters)){
#line 355 "src/typecheck.z"
call.args[i] = _ZN9typecheck16coerce_expr_typeE(ctx,call.args[i],arg_ty,fn_def->parameters[i]) ;
;
}
;
#line 357 "src/typecheck.z"
i = (i+ 1);
;
}
;
}
else {
#line 360 "src/typecheck.z"
_ZN5error10emit_errorE(ctx->source_map,expr->span,"Called function with incorrect number of arguments") ;
}
;
#line 361 "src/typecheck.z"
return fn_def->output;
;
}
#line 364 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck17check_conditionalE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) {
#line 365 "src/typecheck.z"
_ZN3ast15ConditionalDataE*  data = &expr->node.conditional;
;
#line 367 "src/typecheck.z"
_ZN3ast2TyE*  cond_ty = _ZN9typecheck10check_exprE(ctx,data->condition) ;
;
#line 368 "src/typecheck.z"
data->condition = _ZN9typecheck16coerce_expr_typeE(ctx,data->condition,cond_ty,ctx->common._bool) ;
;
#line 370 "src/typecheck.z"
_ZN9typecheck10check_exprE(ctx,data->then) ;
#line 371 "src/typecheck.z"
if ((( bool)(data->otherwise))){
#line 372 "src/typecheck.z"
_ZN9typecheck10check_exprE(ctx,data->otherwise) ;
}
;
#line 374 "src/typecheck.z"
return ctx->common._void;
;
}
#line 377 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck11check_whileE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) {
#line 378 "src/typecheck.z"
_ZN3ast9WhileDataE data = expr->node.whl;
;
#line 379 "src/typecheck.z"
_ZN3ast4ExprE*  condition = data.condition;
;
#line 380 "src/typecheck.z"
_ZN3ast2TyE*  cond_ty = _ZN9typecheck10check_exprE(ctx,condition) ;
;
#line 381 "src/typecheck.z"
if ((cond_ty->kind!= TyKind_Bool)){
#line 381 "src/typecheck.z"
_ZN5error12emit_warningE(ctx->source_map,condition->span,"Condition must be of type bool") ;
}
;
#line 382 "src/typecheck.z"
_ZN9typecheck10check_exprE(ctx,data.body) ;
#line 383 "src/typecheck.z"
return ctx->common._void;
;
}
#line 386 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck14check_indexingE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) {
#line 387 "src/typecheck.z"
_ZN3ast12IndexingDataE data = expr->node.indexing;
;
#line 388 "src/typecheck.z"
_ZN3ast2TyE*  array_ty = _ZN9typecheck10check_exprE(ctx,data.array) ;
;
#line 389 "src/typecheck.z"
if ((array_ty->kind!= TyKind_Ptr)){
#line 389 "src/typecheck.z"
_ZN5error10emit_errorE(ctx->source_map,expr->span,"Cannot index into non-ptr type") ;
}
;
#line 390 "src/typecheck.z"
_ZN3ast2TyE*  index_ty = _ZN9typecheck10check_exprE(ctx,data.index) ;
;
#line 391 "src/typecheck.z"
if (!((index_ty->kind== TyKind_Signed)|| (index_ty->kind== TyKind_Unsigned))){
#line 392 "src/typecheck.z"
_ZN5error10emit_errorE(ctx->source_map,expr->span,"Only integers are valid indices") ;
}
;
#line 394 "src/typecheck.z"
return array_ty->node.ptr;
;
}
#line 397 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck11check_fieldE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) {
#line 398 "src/typecheck.z"
_ZN3ast9FieldDataE data = expr->node.field;
;
#line 399 "src/typecheck.z"
_ZN3ast2TyE*  compound_ty = _ZN9typecheck10check_exprE(ctx,data.strct) ;
;
#line 401 "src/typecheck.z"
_ZN3ast2TyE*  ptr_inner = compound_ty->node.ptr;
;
#line 402 "src/typecheck.z"
if (((compound_ty->kind== TyKind_Ptr)&& ((ptr_inner->kind== TyKind_Struct)|| (ptr_inner->kind== TyKind_Union)))){
#line 403 "src/typecheck.z"
compound_ty = compound_ty->node.ptr;
;
}
;
#line 406 "src/typecheck.z"
if (((compound_ty->kind!= TyKind_Struct)&& (compound_ty->kind!= TyKind_Union))){
#line 406 "src/typecheck.z"
_ZN5error10emit_errorE(ctx->source_map,expr->span,"Cannot access field of non-compound type") ;
}
;
#line 408 "src/typecheck.z"
_ZN3ast11CompoundDefE compound = compound_ty->node.compound;
;
#line 410 "src/typecheck.z"
 u32 i = 0;
;
#line 411 "src/typecheck.z"
while ( (i< compound.num_fields))
{
#line 412 "src/typecheck.z"
if ((compound.fields[i].name.x== data.ident.name.x)){
#line 413 "src/typecheck.z"
return compound.fields[i].ty;
;
}
;
#line 415 "src/typecheck.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 417 "src/typecheck.z"
_ZN5error12emit_warningE(ctx->source_map,expr->span,"Compound type has no such field") ;
#line 418 "src/typecheck.z"
return _ZN4cstd4nullE;
;
}
#line 421 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck10check_pathE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4PathE*  path) {
#line 422 "src/typecheck.z"
if ((path->binding.kind== BindingKind_Item)){
#line 423 "src/typecheck.z"
_ZN3ast4ItemE*  item = path->binding.node.item;
;
#line 424 "src/typecheck.z"
if (((item->kind== ItemKind_Struct)|| (item->kind== ItemKind_Union))){
#line 425 "src/typecheck.z"
return item->node.compound.ty;
;
}
else {
#line 427 "src/typecheck.z"
if ((item->kind== ItemKind_Enum)){
#line 428 "src/typecheck.z"
return item->node._enum.ty;
;
}
else {
#line 430 "src/typecheck.z"
if ((item->kind== ItemKind_Function)){
#line 431 "src/typecheck.z"
return item->node.function.header.ty;
;
}
else {
#line 433 "src/typecheck.z"
if (((item->kind== ItemKind_Const)|| (item->kind== ItemKind_Variable))){
#line 434 "src/typecheck.z"
return item->node.variable.ty;
;
}
else {
#line 436 "src/typecheck.z"
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
else {
#line 438 "src/typecheck.z"
if ((path->binding.kind== BindingKind_Local)){
#line 439 "src/typecheck.z"
_ZN3ast9LocalDataE*  data = path->binding.node.local;
;
#line 440 "src/typecheck.z"
return data->ty;
;
}
else {
#line 442 "src/typecheck.z"
if ((path->binding.kind== BindingKind_Parameter)){
#line 443 "src/typecheck.z"
_ZN3ast17FunctionParameterE*  param = path->binding.node.parameter;
;
#line 444 "src/typecheck.z"
return param->ty;
;
}
else {
#line 446 "src/typecheck.z"
if ((path->binding.kind== BindingKind_Variant)){
#line 447 "src/typecheck.z"
_ZN3ast11EnumVariantE*  variant = path->binding.node.variant;
;
#line 448 "src/typecheck.z"
_ZN3ast4ItemE*  enum_item = variant->_enum;
;
#line 449 "src/typecheck.z"
return enum_item->node._enum.ty;
;
}
else {
#line 451 "src/typecheck.z"
if ((path->binding.kind== BindingKind_PrimitiveType)){
#line 452 "src/typecheck.z"
return _ZN9typecheck15primitive_to_tyE(ctx,path->binding.node.primitive) ;
;
}
else {
#line 454 "src/typecheck.z"
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
#line 458 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck11check_localE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast9LocalDataE*  data) {
#line 459 "src/typecheck.z"
data->ty = _ZN9typecheck14ast_type_to_tyE(ctx,data->ast_ty) ;
;
#line 460 "src/typecheck.z"
if ((( bool)(data->value))){
#line 460 "src/typecheck.z"
_ZN9typecheck10check_exprE(ctx,data->value) ;
}
;
#line 461 "src/typecheck.z"
return ctx->common._void;
;
}
#line 464 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck16check_assignmentE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast14AssignmentDataE assignment) {
#line 465 "src/typecheck.z"
_ZN9typecheck10check_exprE(ctx,assignment.left) ;
#line 466 "src/typecheck.z"
_ZN9typecheck10check_exprE(ctx,assignment.right) ;
#line 467 "src/typecheck.z"
return ctx->common._void;
;
}
#line 470 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck12check_returnE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) {
#line 471 "src/typecheck.z"
_ZN9typecheck10check_exprE(ctx,expr) ;
#line 472 "src/typecheck.z"
return ctx->common._void;
;
}
#line 475 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck12check_sizeofE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) {
#line 476 "src/typecheck.z"
_ZN9typecheck10check_exprE(ctx,expr) ;
#line 477 "src/typecheck.z"
return ctx->common._u64;
;
}
#line 480 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck10check_castE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast8CastDataE*  data) {
#line 481 "src/typecheck.z"
_ZN9typecheck10check_exprE(ctx,data->inner) ;
#line 482 "src/typecheck.z"
data->ty = _ZN9typecheck14ast_type_to_tyE(ctx,data->ast_ty) ;
;
#line 483 "src/typecheck.z"
return data->ty;
;
}
#line 486 "src/typecheck.z"
_ZN3ast2TyE*  _ZN9typecheck10check_exprE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ExprE*  expr) {
#line 487 "src/typecheck.z"
_ZN3ast2TyE*  result ;
;
#line 488 "src/typecheck.z"
if ((expr->kind== ExprKind_Unary)){
#line 488 "src/typecheck.z"
result = _ZN9typecheck11check_unaryE(ctx,expr) ;
;
}
else {
#line 489 "src/typecheck.z"
if ((expr->kind== ExprKind_Binary)){
#line 489 "src/typecheck.z"
result = _ZN9typecheck12check_binaryE(ctx,expr) ;
;
}
else {
#line 490 "src/typecheck.z"
if ((expr->kind== ExprKind_Block)){
#line 490 "src/typecheck.z"
result = _ZN9typecheck16check_block_exprE(ctx,expr) ;
;
}
else {
#line 491 "src/typecheck.z"
if ((expr->kind== ExprKind_Call)){
#line 491 "src/typecheck.z"
result = _ZN9typecheck10check_callE(ctx,expr) ;
;
}
else {
#line 492 "src/typecheck.z"
if ((expr->kind== ExprKind_Conditional)){
#line 492 "src/typecheck.z"
result = _ZN9typecheck17check_conditionalE(ctx,expr) ;
;
}
else {
#line 493 "src/typecheck.z"
if ((expr->kind== ExprKind_ControlFlow)){
#line 493 "src/typecheck.z"
result = ctx->common._void;
;
}
else {
#line 494 "src/typecheck.z"
if ((expr->kind== ExprKind_While)){
#line 494 "src/typecheck.z"
result = _ZN9typecheck11check_whileE(ctx,expr) ;
;
}
else {
#line 495 "src/typecheck.z"
if ((expr->kind== ExprKind_Indexing)){
#line 495 "src/typecheck.z"
result = _ZN9typecheck14check_indexingE(ctx,expr) ;
;
}
else {
#line 496 "src/typecheck.z"
if ((expr->kind== ExprKind_Field)){
#line 496 "src/typecheck.z"
result = _ZN9typecheck11check_fieldE(ctx,expr) ;
;
}
else {
#line 497 "src/typecheck.z"
if ((expr->kind== ExprKind_Path)){
#line 497 "src/typecheck.z"
result = _ZN9typecheck10check_pathE(ctx,&expr->node.path) ;
;
}
else {
#line 498 "src/typecheck.z"
if ((expr->kind== ExprKind_Literal)){
#line 498 "src/typecheck.z"
result = _ZN9typecheck17ast_literal_to_tyE(ctx,expr->node.lit) ;
;
}
else {
#line 499 "src/typecheck.z"
if ((expr->kind== ExprKind_Assignment)){
#line 499 "src/typecheck.z"
result = _ZN9typecheck16check_assignmentE(ctx,expr->node.assignment) ;
;
}
else {
#line 500 "src/typecheck.z"
if ((expr->kind== ExprKind_Local)){
#line 500 "src/typecheck.z"
result = _ZN9typecheck11check_localE(ctx,&expr->node.local) ;
;
}
else {
#line 501 "src/typecheck.z"
if ((expr->kind== ExprKind_Return)){
#line 501 "src/typecheck.z"
result = _ZN9typecheck12check_returnE(ctx,expr->node._return) ;
;
}
else {
#line 502 "src/typecheck.z"
if ((expr->kind== ExprKind_Sizeof)){
#line 502 "src/typecheck.z"
result = _ZN9typecheck12check_sizeofE(ctx,expr->node._sizeof) ;
;
}
else {
#line 503 "src/typecheck.z"
if ((expr->kind== ExprKind_Cast)){
#line 503 "src/typecheck.z"
result = _ZN9typecheck10check_castE(ctx,&expr->node._cast) ;
;
}
else {
#line 504 "src/typecheck.z"
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
#line 505 "src/typecheck.z"
expr->ty = result;
;
#line 506 "src/typecheck.z"
return result;
;
}
#line 510 "src/typecheck.z"
 void _ZN9typecheck14check_variableE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 511 "src/typecheck.z"
_ZN3ast12VariableDataE*  data = &item->node.variable;
;
#line 512 "src/typecheck.z"
_ZN3ast2TyE*  decl_ty = data->ty;
;
#line 514 "src/typecheck.z"
if ((( bool)(item->node.variable.body))){
#line 515 "src/typecheck.z"
_ZN3ast2TyE*  expr_ty = _ZN9typecheck10check_exprE(ctx,data->body) ;
;
#line 517 "src/typecheck.z"
data->body = _ZN9typecheck16coerce_expr_typeE(ctx,data->body,expr_ty,decl_ty) ;
;
}
;
}
#line 521 "src/typecheck.z"
 void _ZN9typecheck14check_functionE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 523 "src/typecheck.z"
if ((( bool)(item->node.function.body))){
#line 524 "src/typecheck.z"
_ZN9typecheck10check_exprE(ctx,item->node.function.body) ;
}
;
}
#line 528 "src/typecheck.z"
 void _ZN9typecheck10check_itemE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 529 "src/typecheck.z"
if ((item->kind== ItemKind_Enum)){
}
else {
#line 530 "src/typecheck.z"
if (((item->kind== ItemKind_Struct)|| (item->kind== ItemKind_Union))){
}
else {
#line 531 "src/typecheck.z"
if ((item->kind== ItemKind_Use)){
}
else {
#line 532 "src/typecheck.z"
if (((item->kind== ItemKind_Const)|| (item->kind== ItemKind_Variable))){
#line 532 "src/typecheck.z"
_ZN9typecheck14check_variableE(ctx,item) ;
}
else {
#line 533 "src/typecheck.z"
if ((item->kind== ItemKind_Function)){
#line 533 "src/typecheck.z"
_ZN9typecheck14check_functionE(ctx,item) ;
}
else {
#line 534 "src/typecheck.z"
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
#line 537 "src/typecheck.z"
 void _ZN9typecheck9check_modE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast6ModuleE*  module) {
#line 538 "src/typecheck.z"
 u32 i = 0;
;
#line 539 "src/typecheck.z"
while ( (i< module->num_items))
{
#line 540 "src/typecheck.z"
_ZN9typecheck10check_itemE(ctx,&module->items[i]) ;
#line 541 "src/typecheck.z"
i = ((( i32)(i))+ 1);
;
}
;
}
#line 545 "src/typecheck.z"
 void _ZN9typecheck12collect_enumE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 547 "src/typecheck.z"
_ZN3ast2TyE*  ty = item->node._enum.ty;
;
#line 548 "src/typecheck.z"
_ZN3ast7EnumDefE*  def = &ty->node._enum;
;
#line 550 "src/typecheck.z"
def->variants = malloc((sizeof(_ZN9interning3SidE)* (( u64)(item->node._enum.num_variants)))) ;
;
#line 551 "src/typecheck.z"
 u32 i = 0;
;
#line 552 "src/typecheck.z"
while ( (i< item->node._enum.num_variants))
{
#line 553 "src/typecheck.z"
def->variants[i] = item->node._enum.variants[i].ident.name;
;
#line 554 "src/typecheck.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 556 "src/typecheck.z"
def->num_variants = item->node._enum.num_variants;
;
}
#line 559 "src/typecheck.z"
 void _ZN9typecheck16collect_variableE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 560 "src/typecheck.z"
_ZN3ast12VariableDataE*  data = &item->node.variable;
;
#line 561 "src/typecheck.z"
data->ty = _ZN9typecheck14ast_type_to_tyE(ctx,data->ast_ty) ;
;
}
#line 564 "src/typecheck.z"
 void _ZN9typecheck16collect_functionE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 566 "src/typecheck.z"
_ZN3ast14FunctionHeaderE*  header = &item->node.function.header;
;
#line 568 "src/typecheck.z"
_ZN3ast5FnDefE def ;
;
#line 570 "src/typecheck.z"
def.output = _ZN9typecheck14ast_type_to_tyE(ctx,header->output_ast_ty) ;
;
#line 571 "src/typecheck.z"
def.num_parameters = header->num_parameters;
;
#line 572 "src/typecheck.z"
def.parameters = malloc((( u64)(((( u32)(8))* def.num_parameters)))) ;
;
#line 574 "src/typecheck.z"
 u32 i = 0;
;
#line 575 "src/typecheck.z"
while ( (i< def.num_parameters))
{
#line 576 "src/typecheck.z"
_ZN3ast2TyE*  param_ty = _ZN9typecheck14ast_type_to_tyE(ctx,header->parameters[i].ast_ty) ;
;
#line 577 "src/typecheck.z"
def.parameters[i] = param_ty;
;
#line 578 "src/typecheck.z"
header->parameters[i].ty = param_ty;
;
#line 579 "src/typecheck.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 582 "src/typecheck.z"
_ZN3ast2TyE ty ;
;
#line 583 "src/typecheck.z"
ty.kind = TyKind_Fn;
;
#line 584 "src/typecheck.z"
ty.node.function = def;
;
#line 586 "src/typecheck.z"
item->node.function.header.ty = _ZN9typecheck9intern_tyE(ctx,ty) ;
;
}
#line 589 "src/typecheck.z"
 void _ZN9typecheck16collect_compoundE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 590 "src/typecheck.z"
_ZN3ast2TyE*  ty = item->node.compound.ty;
;
#line 591 "src/typecheck.z"
_ZN3ast11CompoundDefE*  def = &ty->node.compound;
;
#line 593 "src/typecheck.z"
if (((( i32)(item->node.compound.num_fields))> 0)){
#line 595 "src/typecheck.z"
def->fields = malloc((sizeof(_ZN3ast8FieldDefE)* (( u64)(item->node.compound.num_fields)))) ;
;
#line 596 "src/typecheck.z"
 u32 i = 0;
;
#line 597 "src/typecheck.z"
while ( (i< item->node.compound.num_fields))
{
#line 598 "src/typecheck.z"
def->fields[i].name = item->node.compound.fields[i].ident.name;
;
#line 599 "src/typecheck.z"
def->fields[i].ty = _ZN9typecheck14ast_type_to_tyE(ctx,item->node.compound.fields[i].ast_ty) ;
;
#line 600 "src/typecheck.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 602 "src/typecheck.z"
def->num_fields = item->node.compound.num_fields;
;
}
;
}
#line 607 "src/typecheck.z"
 void _ZN9typecheck12collect_itemE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 608 "src/typecheck.z"
if ((item->kind== ItemKind_Enum)){
#line 608 "src/typecheck.z"
_ZN9typecheck12collect_enumE(ctx,item) ;
}
else {
#line 609 "src/typecheck.z"
if ((item->kind== ItemKind_Function)){
#line 609 "src/typecheck.z"
_ZN9typecheck16collect_functionE(ctx,item) ;
}
else {
#line 610 "src/typecheck.z"
if (((item->kind== ItemKind_Variable)|| (item->kind== ItemKind_Const))){
#line 610 "src/typecheck.z"
_ZN9typecheck16collect_variableE(ctx,item) ;
}
else {
#line 611 "src/typecheck.z"
if (((item->kind== ItemKind_Struct)|| (item->kind== ItemKind_Union))){
#line 611 "src/typecheck.z"
_ZN9typecheck16collect_compoundE(ctx,item) ;
}
;
}
;
}
;
}
;
}
#line 614 "src/typecheck.z"
 void _ZN9typecheck11collect_modE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast6ModuleE*  module) {
#line 615 "src/typecheck.z"
 u32 i = 0;
;
#line 616 "src/typecheck.z"
while ( (i< module->num_items))
{
#line 617 "src/typecheck.z"
_ZN9typecheck12collect_itemE(ctx,&module->items[i]) ;
#line 618 "src/typecheck.z"
i = ((( i32)(i))+ 1);
;
}
;
}
#line 622 "src/typecheck.z"
 void _ZN9typecheck13collect_namesE(_ZN9typecheck11TypeContextE*  ctx, _ZN3ast6ModuleE*  module) {
#line 623 "src/typecheck.z"
 u32 i = 0;
;
#line 624 "src/typecheck.z"
while ( (i< module->num_items))
{
#line 625 "src/typecheck.z"
_ZN3ast4ItemE*  item = &module->items[i];
;
#line 626 "src/typecheck.z"
if (((item->kind== ItemKind_Struct)|| (item->kind== ItemKind_Union))){
#line 627 "src/typecheck.z"
_ZN3ast11CompoundDefE def ;
;
#line 628 "src/typecheck.z"
def.path.num_segments = ((( i32)(module->path.num_segments))+ 1);
;
#line 629 "src/typecheck.z"
def.path.segments = malloc((sizeof(_ZN3ast5IdentE)* (( u64)(def.path.num_segments)))) ;
;
#line 630 "src/typecheck.z"
def.path.binding.kind = BindingKind_Item;
;
#line 631 "src/typecheck.z"
def.path.binding.node.item = item;
;
#line 632 "src/typecheck.z"
memcpy((( void* )(def.path.segments)),(( void* )(module->path.segments)),(sizeof(_ZN3ast5IdentE)* (( u64)(module->path.num_segments)))) ;
#line 633 "src/typecheck.z"
def.path.segments[module->path.num_segments] = item->ident;
;
#line 635 "src/typecheck.z"
_ZN3ast2TyE ty ;
;
#line 636 "src/typecheck.z"
if ((item->kind== ItemKind_Struct)){
#line 636 "src/typecheck.z"
ty.kind = TyKind_Struct;
;
}
else {
#line 637 "src/typecheck.z"
if ((item->kind== ItemKind_Union)){
#line 637 "src/typecheck.z"
ty.kind = TyKind_Union;
;
}
;
}
;
#line 639 "src/typecheck.z"
ty.node.compound = def;
;
#line 641 "src/typecheck.z"
item->node.compound.ty = _ZN9typecheck9intern_tyE(ctx,ty) ;
;
}
else {
#line 643 "src/typecheck.z"
if ((item->kind== ItemKind_Enum)){
#line 645 "src/typecheck.z"
_ZN3ast7EnumDefE def ;
;
#line 646 "src/typecheck.z"
def.path.num_segments = ((( i32)(module->path.num_segments))+ 1);
;
#line 647 "src/typecheck.z"
def.path.segments = malloc((sizeof(_ZN3ast5IdentE)* (( u64)(def.path.num_segments)))) ;
;
#line 648 "src/typecheck.z"
def.path.binding.kind = BindingKind_Item;
;
#line 649 "src/typecheck.z"
def.path.binding.node.item = item;
;
#line 650 "src/typecheck.z"
memcpy((( void* )(def.path.segments)),(( void* )(module->path.segments)),(sizeof(_ZN3ast5IdentE)* (( u64)(module->path.num_segments)))) ;
#line 651 "src/typecheck.z"
def.path.segments[module->path.num_segments] = item->ident;
;
#line 653 "src/typecheck.z"
_ZN3ast2TyE ty ;
;
#line 654 "src/typecheck.z"
ty.kind = TyKind_Enum;
;
#line 656 "src/typecheck.z"
ty.node._enum = def;
;
#line 658 "src/typecheck.z"
item->node._enum.ty = _ZN9typecheck9intern_tyE(ctx,ty) ;
;
}
;
}
;
#line 660 "src/typecheck.z"
i = ((( i32)(i))+ 1);
;
}
;
}
#line 666 "src/typecheck.z"
 void _ZN9typecheck5checkE(_ZN7session7SessionE*  sess, _ZN3ast6ModuleE*  module) {
#line 668 "src/typecheck.z"
if (!_ZN9typecheck3ctxE.initialized){
#line 669 "src/typecheck.z"
_ZN9typecheck3ctxE.interner = &sess->interner;
;
#line 670 "src/typecheck.z"
_ZN9typecheck3ctxE.source_map = &sess->source;
;
#line 671 "src/typecheck.z"
_ZN9typecheck3ctxE.types_lookup = _ZN6intmap13intmap_createE((( u64)(1024))) ;
;
#line 672 "src/typecheck.z"
_ZN9typecheck3ctxE.types = malloc((sizeof(_ZN3ast2TyE)* (( u64)(1024)))) ;
;
#line 673 "src/typecheck.z"
_ZN9typecheck3ctxE.next_type_idx = 1;
;
#line 674 "src/typecheck.z"
_ZN9typecheck19create_common_typesE(&_ZN9typecheck3ctxE) ;
#line 675 "src/typecheck.z"
_ZN9typecheck3ctxE.initialized = true;
;
}
;
#line 678 "src/typecheck.z"
_ZN9typecheck13collect_namesE(&_ZN9typecheck3ctxE,module) ;
#line 679 "src/typecheck.z"
_ZN9typecheck11collect_modE(&_ZN9typecheck3ctxE,module) ;
#line 680 "src/typecheck.z"
_ZN9typecheck9check_modE(&_ZN9typecheck3ctxE,module) ;
}
#line 17 "src/codegen.z"
 void _ZN7codegen13generate_exprE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ExprE*  expr) ;
#line 18 "src/codegen.z"
 void _ZN7codegen14generate_blockE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast5BlockE*  block) ;
#line 19 "src/codegen.z"
 void _ZN7codegen13generate_itemE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ItemE*  item) ;
#line 21 "src/codegen.z"
 u32 _ZN7codegen11type_is_ptrE(_ZN3ast7AstTypeE*  ty) {
#line 22 "src/codegen.z"
if ((ty->kind== AstTypeKind_Ptr)){
#line 22 "src/codegen.z"
return 1;
;
}
else {
#line 23 "src/codegen.z"
return 0;
;
}
;
}
#line 26 "src/codegen.z"
 void _ZN7codegen16generate_preludeE(_ZN7codegen14CodegenContextE*  ctx) {
#line 27 "src/codegen.z"
fprintf(ctx->out,(( char* )("//Prelude\n"))) ;
#line 28 "src/codegen.z"
fprintf(ctx->out,(( char* )("#include <stdint.h>\n"))) ;
#line 29 "src/codegen.z"
fprintf(ctx->out,(( char* )("#include <stdbool.h>\n"))) ;
#line 30 "src/codegen.z"
fprintf(ctx->out,(( char* )("typedef uint8_t u8;\n"))) ;
#line 31 "src/codegen.z"
fprintf(ctx->out,(( char* )("typedef uint16_t u16;\n"))) ;
#line 32 "src/codegen.z"
fprintf(ctx->out,(( char* )("typedef uint32_t u32;\n"))) ;
#line 33 "src/codegen.z"
fprintf(ctx->out,(( char* )("typedef uint64_t u64;\n"))) ;
#line 34 "src/codegen.z"
fprintf(ctx->out,(( char* )("typedef int8_t i8;\n"))) ;
#line 35 "src/codegen.z"
fprintf(ctx->out,(( char* )("typedef int16_t i16;\n"))) ;
#line 36 "src/codegen.z"
fprintf(ctx->out,(( char* )("typedef int32_t i32;\n"))) ;
#line 37 "src/codegen.z"
fprintf(ctx->out,(( char* )("typedef int64_t i64;\n"))) ;
#line 38 "src/codegen.z"
fprintf(ctx->out,(( char* )("typedef float f32;\n"))) ;
#line 39 "src/codegen.z"
fprintf(ctx->out,(( char* )("typedef double f64;\n"))) ;
#line 40 "src/codegen.z"
fprintf(ctx->out,(( char* )("typedef const char constchar;\n"))) ;
#line 41 "src/codegen.z"
fprintf(ctx->out,(( char* )("typedef const void constvoid;\n"))) ;
}
#line 44 "src/codegen.z"
 void _ZN7codegen12generate_sidE(_ZN7codegen14CodegenContextE*  ctx, _ZN9interning3SidE sid) {
#line 45 "src/codegen.z"
fprintf(ctx->out,(( char* )("%s")),_ZN9interning7get_strE(ctx->interner,sid) ) ;
}
#line 48 "src/codegen.z"
 void _ZN7codegen19generate_identifierE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast5IdentE ident) {
#line 49 "src/codegen.z"
_ZN7codegen12generate_sidE(ctx,ident.name) ;
}
#line 52 "src/codegen.z"
 void _ZN7codegen16generate_patternE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast7PatternE pat) {
#line 53 "src/codegen.z"
_ZN7codegen19generate_identifierE(ctx,pat.ident) ;
}
#line 56 "src/codegen.z"
 void _ZN7codegen11mangle_pathE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4PathE path) {
#line 57 "src/codegen.z"
_ZN3ast4ItemE*  item = path.binding.node.item;
;
#line 58 "src/codegen.z"
if (((path.binding.kind== BindingKind_Item)&& item->should_mangle)){
#line 59 "src/codegen.z"
fprintf(ctx->out,(( char* )("_ZN"))) ;
#line 60 "src/codegen.z"
 u32 i = 0;
;
#line 61 "src/codegen.z"
while ( (i< path.num_segments))
{
#line 62 "src/codegen.z"
 char*  seg = _ZN9interning7get_strE(ctx->interner,path.segments[i].name) ;
;
#line 63 "src/codegen.z"
fprintf(ctx->out,(( char* )("%lu%s")),strlen((( char* )(seg))) ,seg) ;
#line 64 "src/codegen.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 66 "src/codegen.z"
fprintf(ctx->out,(( char* )("E"))) ;
}
else {
#line 67 "src/codegen.z"
if ((path.binding.kind== BindingKind_Variant)){
#line 68 "src/codegen.z"
fprintf(ctx->out,(( char* )("%s_%s")),_ZN9interning7get_strE(ctx->interner,path.segments[((( i32)(path.num_segments))- 2)].name) ,_ZN9interning7get_strE(ctx->interner,path.segments[((( i32)(path.num_segments))- 1)].name) ) ;
}
else {
#line 71 "src/codegen.z"
fprintf(ctx->out,(( char* )("%s")),_ZN9interning7get_strE(ctx->interner,path.segments[((( i32)(path.num_segments))- 1)].name) ) ;
}
;
}
;
}
#line 75 "src/codegen.z"
 void _ZN7codegen21mangle_path_and_identE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4PathE path, _ZN3ast5IdentE ident) {
#line 76 "src/codegen.z"
fprintf(ctx->out,(( char* )(" _ZN"))) ;
#line 77 "src/codegen.z"
 u32 i = 0;
;
#line 78 "src/codegen.z"
while ( (i< path.num_segments))
{
#line 79 "src/codegen.z"
 char*  seg = _ZN9interning7get_strE(ctx->interner,path.segments[i].name) ;
;
#line 80 "src/codegen.z"
fprintf(ctx->out,(( char* )("%lu%s")),strlen((( char* )(seg))) ,seg) ;
#line 81 "src/codegen.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 83 "src/codegen.z"
 char*  name = _ZN9interning7get_strE(ctx->interner,ident.name) ;
;
#line 84 "src/codegen.z"
fprintf(ctx->out,(( char* )("%lu%sE")),strlen((( char* )(name))) ,name) ;
}
#line 87 "src/codegen.z"
 void _ZN7codegen20mangle_function_nameE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast6ModuleE*  module, _ZN3ast5IdentE ident, _ZN3ast14FunctionHeaderE header) {
#line 88 "src/codegen.z"
_ZN7codegen21mangle_path_and_identE(ctx,module->path,ident) ;
}
#line 91 "src/codegen.z"
 void _ZN7codegen11generate_tyE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast2TyE*  ty) {
#line 92 "src/codegen.z"
if (((ty->kind== TyKind_Void)|| (ty->kind== TyKind_ConstVoid))){
#line 92 "src/codegen.z"
fprintf(ctx->out,(( char* )(" void"))) ;
}
else {
#line 93 "src/codegen.z"
if (((ty->kind== TyKind_Char)|| (ty->kind== TyKind_ConstChar))){
#line 93 "src/codegen.z"
fprintf(ctx->out,(( char* )(" char"))) ;
}
else {
#line 94 "src/codegen.z"
if ((ty->kind== TyKind_Bool)){
#line 94 "src/codegen.z"
fprintf(ctx->out,(( char* )(" bool"))) ;
}
else {
#line 95 "src/codegen.z"
if (((ty->kind== TyKind_Signed)|| (ty->kind== TyKind_Unsigned))){
#line 96 "src/codegen.z"
if ((ty->kind== TyKind_Signed)){
#line 97 "src/codegen.z"
fprintf(ctx->out,(( char* )(" i"))) ;
}
else {
#line 98 "src/codegen.z"
if ((ty->kind== TyKind_Unsigned)){
#line 99 "src/codegen.z"
fprintf(ctx->out,(( char* )(" u"))) ;
}
;
}
;
#line 101 "src/codegen.z"
fprintf(ctx->out,(( char* )("%u")),_ZN3ast12integer_sizeE(ty->node.integer) ) ;
}
else {
#line 103 "src/codegen.z"
if ((ty->kind== TyKind_Floating)){
#line 104 "src/codegen.z"
fprintf(ctx->out,(( char* )(" f%u")),_ZN3ast13floating_sizeE(ty->node.floating) ) ;
}
else {
#line 106 "src/codegen.z"
if ((ty->kind== TyKind_Ptr)){
#line 107 "src/codegen.z"
_ZN7codegen11generate_tyE(ctx,ty->node.ptr) ;
#line 108 "src/codegen.z"
fprintf(ctx->out,(( char* )("* "))) ;
}
else {
#line 110 "src/codegen.z"
if (((ty->kind== TyKind_Struct)|| (ty->kind== TyKind_Union))){
#line 111 "src/codegen.z"
_ZN7codegen11mangle_pathE(ctx,ty->node.compound.path) ;
}
else {
#line 113 "src/codegen.z"
if ((ty->kind== TyKind_Enum)){
#line 114 "src/codegen.z"
_ZN7codegen11mangle_pathE(ctx,ty->node._enum.path) ;
}
else {
#line 115 "src/codegen.z"
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
#line 118 "src/codegen.z"
 void _ZN7codegen13generate_charE(_ZN7codegen14CodegenContextE*  ctx,  char c) {
#line 119 "src/codegen.z"
if ((c== '\n')){
#line 119 "src/codegen.z"
fprintf(ctx->out,(( char* )("'\\n'"))) ;
}
else {
#line 120 "src/codegen.z"
if ((c== '\t')){
#line 120 "src/codegen.z"
fprintf(ctx->out,(( char* )("'\\t'"))) ;
}
else {
#line 121 "src/codegen.z"
if ((c== '\r')){
#line 121 "src/codegen.z"
fprintf(ctx->out,(( char* )("'\\r'"))) ;
}
else {
#line 122 "src/codegen.z"
if ((c== '\\')){
#line 122 "src/codegen.z"
fprintf(ctx->out,(( char* )("'\\\\'"))) ;
}
else {
#line 123 "src/codegen.z"
if ((c== '\'')){
#line 123 "src/codegen.z"
fprintf(ctx->out,(( char* )("'\\''"))) ;
}
else {
#line 124 "src/codegen.z"
fprintf(ctx->out,(( char* )("'%c'")),c) ;
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
#line 127 "src/codegen.z"
 void _ZN7codegen16generate_literalE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast7LiteralE lit) {
#line 128 "src/codegen.z"
if ((lit.kind== LiteralKind_Int)){
#line 128 "src/codegen.z"
fprintf(ctx->out,(( char* )("%ld")),lit.value.integer) ;
}
else {
#line 129 "src/codegen.z"
if ((lit.kind== LiteralKind_Float)){
#line 129 "src/codegen.z"
fprintf(ctx->out,(( char* )("%f")),lit.value.floating) ;
}
else {
#line 130 "src/codegen.z"
if ((lit.kind== LiteralKind_Bool)){
#line 130 "src/codegen.z"
if (lit.value.boolean){
#line 130 "src/codegen.z"
fprintf(ctx->out,(( char* )("true"))) ;
}
else {
#line 130 "src/codegen.z"
fprintf(ctx->out,(( char* )("false"))) ;
}
;
}
else {
#line 131 "src/codegen.z"
if ((lit.kind== LiteralKind_Str)){
#line 132 "src/codegen.z"
fprintf(ctx->out,(( char* )("\"%s\"")),_ZN9interning7get_strE(ctx->interner,lit.value.str) ) ;
}
else {
#line 134 "src/codegen.z"
if ((lit.kind== LiteralKind_Char)){
#line 134 "src/codegen.z"
_ZN7codegen13generate_charE(ctx,lit.value.ch) ;
}
else {
#line 135 "src/codegen.z"
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
#line 138 "src/codegen.z"
 void _ZN7codegen14generate_unaryE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast9UnaryDataE unary) {
#line 139 "src/codegen.z"
if ((unary.op== UnaryOperatorKind_Negation)){
#line 139 "src/codegen.z"
fprintf(ctx->out,(( char* )("-"))) ;
}
else {
#line 140 "src/codegen.z"
if ((unary.op== UnaryOperatorKind_Complement)){
#line 140 "src/codegen.z"
fprintf(ctx->out,(( char* )("!"))) ;
}
else {
#line 141 "src/codegen.z"
if ((unary.op== UnaryOperatorKind_Refer)){
#line 141 "src/codegen.z"
fprintf(ctx->out,(( char* )("&"))) ;
}
else {
#line 142 "src/codegen.z"
if ((unary.op== UnaryOperatorKind_Deref)){
#line 142 "src/codegen.z"
fprintf(ctx->out,(( char* )("*"))) ;
}
else {
#line 143 "src/codegen.z"
abort() ;
}
;
}
;
}
;
}
;
#line 145 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,unary.inner) ;
}
#line 148 "src/codegen.z"
 void _ZN7codegen15generate_binaryE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast10BinaryDataE binary) {
#line 149 "src/codegen.z"
fprintf(ctx->out,(( char* )("("))) ;
#line 150 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,binary.left) ;
#line 151 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Addition)){
#line 151 "src/codegen.z"
fprintf(ctx->out,(( char* )("+ "))) ;
}
else {
#line 152 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Subtraction)){
#line 152 "src/codegen.z"
fprintf(ctx->out,(( char* )("- "))) ;
}
else {
#line 153 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Product)){
#line 153 "src/codegen.z"
fprintf(ctx->out,(( char* )("* "))) ;
}
else {
#line 154 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Division)){
#line 154 "src/codegen.z"
fprintf(ctx->out,(( char* )("/ "))) ;
}
else {
#line 155 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Modulus)){
#line 155 "src/codegen.z"
fprintf(ctx->out,(( char* )("%% "))) ;
}
else {
#line 157 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Less)){
#line 157 "src/codegen.z"
fprintf(ctx->out,(( char* )("< "))) ;
}
else {
#line 158 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_LessEq)){
#line 158 "src/codegen.z"
fprintf(ctx->out,(( char* )("<= "))) ;
}
else {
#line 159 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Greater)){
#line 159 "src/codegen.z"
fprintf(ctx->out,(( char* )("> "))) ;
}
else {
#line 160 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_GreaterEq)){
#line 160 "src/codegen.z"
fprintf(ctx->out,(( char* )(">= "))) ;
}
else {
#line 161 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Equality)){
#line 161 "src/codegen.z"
fprintf(ctx->out,(( char* )("== "))) ;
}
else {
#line 162 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_NotEq)){
#line 162 "src/codegen.z"
fprintf(ctx->out,(( char* )("!= "))) ;
}
else {
#line 164 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_BAnd)){
#line 164 "src/codegen.z"
fprintf(ctx->out,(( char* )("& "))) ;
}
else {
#line 165 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_BOr)){
#line 165 "src/codegen.z"
fprintf(ctx->out,(( char* )("| "))) ;
}
else {
#line 166 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Xor)){
#line 166 "src/codegen.z"
fprintf(ctx->out,(( char* )("^ "))) ;
}
else {
#line 167 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_LeftShift)){
#line 167 "src/codegen.z"
fprintf(ctx->out,(( char* )("<< "))) ;
}
else {
#line 168 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_RightShift)){
#line 168 "src/codegen.z"
fprintf(ctx->out,(( char* )(">> "))) ;
}
else {
#line 170 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_And)){
#line 170 "src/codegen.z"
fprintf(ctx->out,(( char* )("&& "))) ;
}
else {
#line 171 "src/codegen.z"
if ((binary.op== BinaryOperatorKind_Or)){
#line 171 "src/codegen.z"
fprintf(ctx->out,(( char* )("|| "))) ;
}
else {
#line 172 "src/codegen.z"
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
#line 173 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,binary.right) ;
#line 174 "src/codegen.z"
fprintf(ctx->out,(( char* )(")"))) ;
}
#line 177 "src/codegen.z"
 void _ZN7codegen13generate_callE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast8CallDataE call) {
#line 178 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,call.func) ;
#line 180 "src/codegen.z"
fprintf(ctx->out,(( char* )("("))) ;
#line 181 "src/codegen.z"
 u32 i = 0;
;
#line 182 "src/codegen.z"
while ( (i< call.num_args))
{
#line 183 "src/codegen.z"
_ZN3ast4ExprE*  arg = call.args[i];
;
#line 184 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,arg) ;
#line 185 "src/codegen.z"
if ((i< ((( i32)(call.num_args))- 1))){
#line 185 "src/codegen.z"
fprintf(ctx->out,(( char* )(","))) ;
}
;
#line 186 "src/codegen.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 188 "src/codegen.z"
fprintf(ctx->out,(( char* )(") "))) ;
}
#line 191 "src/codegen.z"
 void _ZN7codegen20generate_conditionalE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast15ConditionalDataE cond) {
#line 192 "src/codegen.z"
fprintf(ctx->out,(( char* )("if ("))) ;
#line 193 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,cond.condition) ;
#line 194 "src/codegen.z"
fprintf(ctx->out,(( char* )(")"))) ;
#line 195 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,cond.then) ;
#line 196 "src/codegen.z"
if ((( bool)(cond.otherwise))){
#line 197 "src/codegen.z"
fprintf(ctx->out,(( char* )("else "))) ;
#line 198 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,cond.otherwise) ;
}
;
}
#line 202 "src/codegen.z"
 void _ZN7codegen14generate_whileE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast9WhileDataE data) {
#line 203 "src/codegen.z"
fprintf(ctx->out,(( char* )("while ( "))) ;
#line 204 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,data.condition) ;
#line 205 "src/codegen.z"
fprintf(ctx->out,(( char* )(")\n"))) ;
#line 206 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,data.body) ;
}
#line 209 "src/codegen.z"
 void _ZN7codegen17generate_indexingE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast12IndexingDataE idx) {
#line 210 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,idx.array) ;
#line 211 "src/codegen.z"
fprintf(ctx->out,(( char* )("["))) ;
#line 212 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,idx.index) ;
#line 213 "src/codegen.z"
fprintf(ctx->out,(( char* )("]"))) ;
}
#line 216 "src/codegen.z"
 void _ZN7codegen14generate_fieldE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast9FieldDataE field) {
#line 217 "src/codegen.z"
_ZN3ast4ExprE*  strct = field.strct;
;
#line 218 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,strct) ;
#line 220 "src/codegen.z"
 char*  field_name = _ZN9interning7get_strE(ctx->interner,field.ident.name) ;
;
#line 222 "src/codegen.z"
_ZN3ast2TyE*  strct_ty = strct->ty;
;
#line 223 "src/codegen.z"
 bool is_ptr = (strct_ty->kind== TyKind_Ptr);
;
#line 224 "src/codegen.z"
 char*  accessor_str ;
;
#line 226 "src/codegen.z"
if (is_ptr){
#line 226 "src/codegen.z"
accessor_str = "->";
;
}
else {
#line 227 "src/codegen.z"
accessor_str = ".";
;
}
;
#line 228 "src/codegen.z"
fprintf(ctx->out,(( char* )("%s%s")),accessor_str,field_name) ;
}
#line 231 "src/codegen.z"
 void _ZN7codegen15generate_sizeofE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ExprE*  expr) {
#line 232 "src/codegen.z"
fprintf(ctx->out,(( char* )("sizeof("))) ;
#line 233 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,expr) ;
#line 234 "src/codegen.z"
fprintf(ctx->out,(( char* )(")"))) ;
}
#line 237 "src/codegen.z"
 void _ZN7codegen19generate_assignmentE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast14AssignmentDataE assignment) {
#line 238 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,assignment.left) ;
#line 239 "src/codegen.z"
fprintf(ctx->out,(( char* )(" = "))) ;
#line 240 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,assignment.right) ;
#line 241 "src/codegen.z"
fprintf(ctx->out,(( char* )(";\n"))) ;
}
#line 244 "src/codegen.z"
 void _ZN7codegen15generate_returnE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ExprE*  expr) {
#line 245 "src/codegen.z"
fprintf(ctx->out,(( char* )("return "))) ;
#line 246 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,expr) ;
#line 247 "src/codegen.z"
fprintf(ctx->out,(( char* )(";\n"))) ;
}
#line 250 "src/codegen.z"
 void _ZN7codegen21generate_control_flowE(_ZN7codegen14CodegenContextE*  ctx,  bool is_continue) {
#line 251 "src/codegen.z"
if (is_continue){
#line 251 "src/codegen.z"
fprintf(ctx->out,(( char* )("continue;\n"))) ;
}
else {
#line 252 "src/codegen.z"
fprintf(ctx->out,(( char* )("break;\n"))) ;
}
;
}
#line 255 "src/codegen.z"
 void _ZN7codegen14generate_localE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast9LocalDataE data) {
#line 257 "src/codegen.z"
_ZN7codegen11generate_tyE(ctx,data.ty) ;
#line 259 "src/codegen.z"
 char*  var_name = _ZN9interning7get_strE(ctx->interner,data.pat.ident.name) ;
;
#line 261 "src/codegen.z"
fprintf(ctx->out,(( char* )(" %s ")),var_name) ;
#line 262 "src/codegen.z"
if ((( bool)(data.value))){
#line 263 "src/codegen.z"
fprintf(ctx->out,(( char* )("= "))) ;
#line 264 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,data.value) ;
}
;
#line 266 "src/codegen.z"
fprintf(ctx->out,(( char* )(";\n"))) ;
}
#line 269 "src/codegen.z"
 void _ZN7codegen13generate_castE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast8CastDataE data) {
#line 270 "src/codegen.z"
fprintf(ctx->out,(( char* )("(("))) ;
#line 271 "src/codegen.z"
_ZN7codegen11generate_tyE(ctx,data.ty) ;
#line 272 "src/codegen.z"
fprintf(ctx->out,(( char* )(")("))) ;
#line 273 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,data.inner) ;
#line 274 "src/codegen.z"
fprintf(ctx->out,(( char* )("))"))) ;
}
#line 277 "src/codegen.z"
 void _ZN7codegen13generate_exprE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ExprE*  expr) {
#line 278 "src/codegen.z"
if ((expr->kind== ExprKind_Unary)){
#line 278 "src/codegen.z"
_ZN7codegen14generate_unaryE(ctx,expr->node.unary) ;
}
else {
#line 279 "src/codegen.z"
if ((expr->kind== ExprKind_Binary)){
#line 279 "src/codegen.z"
_ZN7codegen15generate_binaryE(ctx,expr->node.binary) ;
}
else {
#line 280 "src/codegen.z"
if ((expr->kind== ExprKind_Block)){
#line 280 "src/codegen.z"
_ZN7codegen14generate_blockE(ctx,expr->node.block) ;
}
else {
#line 281 "src/codegen.z"
if ((expr->kind== ExprKind_Call)){
#line 281 "src/codegen.z"
_ZN7codegen13generate_callE(ctx,expr->node.call) ;
}
else {
#line 282 "src/codegen.z"
if ((expr->kind== ExprKind_Conditional)){
#line 282 "src/codegen.z"
_ZN7codegen20generate_conditionalE(ctx,expr->node.conditional) ;
}
else {
#line 283 "src/codegen.z"
if ((expr->kind== ExprKind_While)){
#line 283 "src/codegen.z"
_ZN7codegen14generate_whileE(ctx,expr->node.whl) ;
}
else {
#line 284 "src/codegen.z"
if ((expr->kind== ExprKind_Indexing)){
#line 284 "src/codegen.z"
_ZN7codegen17generate_indexingE(ctx,expr->node.indexing) ;
}
else {
#line 285 "src/codegen.z"
if ((expr->kind== ExprKind_Field)){
#line 285 "src/codegen.z"
_ZN7codegen14generate_fieldE(ctx,expr->node.field) ;
}
else {
#line 286 "src/codegen.z"
if ((expr->kind== ExprKind_Literal)){
#line 286 "src/codegen.z"
_ZN7codegen16generate_literalE(ctx,expr->node.lit) ;
}
else {
#line 287 "src/codegen.z"
if ((expr->kind== ExprKind_Path)){
#line 287 "src/codegen.z"
_ZN7codegen11mangle_pathE(ctx,expr->node.path) ;
}
else {
#line 288 "src/codegen.z"
if ((expr->kind== ExprKind_Sizeof)){
#line 288 "src/codegen.z"
_ZN7codegen15generate_sizeofE(ctx,expr->node._sizeof) ;
}
else {
#line 289 "src/codegen.z"
if ((expr->kind== ExprKind_Assignment)){
#line 289 "src/codegen.z"
_ZN7codegen19generate_assignmentE(ctx,expr->node.assignment) ;
}
else {
#line 290 "src/codegen.z"
if ((expr->kind== ExprKind_ControlFlow)){
#line 290 "src/codegen.z"
_ZN7codegen21generate_control_flowE(ctx,expr->node.control_flow_is_continue) ;
}
else {
#line 291 "src/codegen.z"
if ((expr->kind== ExprKind_Local)){
#line 291 "src/codegen.z"
_ZN7codegen14generate_localE(ctx,expr->node.local) ;
}
else {
#line 292 "src/codegen.z"
if ((expr->kind== ExprKind_Return)){
#line 292 "src/codegen.z"
_ZN7codegen15generate_returnE(ctx,expr->node._return) ;
}
else {
#line 293 "src/codegen.z"
if ((expr->kind== ExprKind_Cast)){
#line 293 "src/codegen.z"
_ZN7codegen13generate_castE(ctx,expr->node._cast) ;
}
else {
#line 294 "src/codegen.z"
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
#line 297 "src/codegen.z"
 void _ZN7codegen14generate_blockE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast5BlockE*  block) {
#line 298 "src/codegen.z"
fprintf(ctx->out,(( char* )("{\n"))) ;
#line 299 "src/codegen.z"
 u32 i = 0;
;
#line 301 "src/codegen.z"
while ( (i< block->num_exprs))
{
#line 302 "src/codegen.z"
_ZN3ast4ExprE*  expr = block->exprs[i];
;
#line 303 "src/codegen.z"
_ZN10source_map19emit_line_directiveE(ctx->out,ctx->source,expr->span) ;
#line 304 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,expr) ;
#line 305 "src/codegen.z"
fprintf(ctx->out,(( char* )(";\n"))) ;
#line 306 "src/codegen.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 308 "src/codegen.z"
fprintf(ctx->out,(( char* )("}\n"))) ;
}
#line 311 "src/codegen.z"
 void _ZN7codegen17generate_variableE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 313 "src/codegen.z"
_ZN10source_map19emit_line_directiveE(ctx->out,ctx->source,item->span) ;
#line 315 "src/codegen.z"
_ZN7codegen11generate_tyE(ctx,item->node.variable.ty) ;
#line 317 "src/codegen.z"
_ZN3ast6ModuleE*  module = ctx->current_module;
;
#line 319 "src/codegen.z"
_ZN7codegen21mangle_path_and_identE(ctx,module->path,item->ident) ;
#line 320 "src/codegen.z"
if ((( bool)(item->node.variable.body))){
#line 321 "src/codegen.z"
fprintf(ctx->out,(( char* )("= "))) ;
#line 322 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,item->node.variable.body) ;
}
;
#line 324 "src/codegen.z"
fprintf(ctx->out,(( char* )(";\n"))) ;
}
#line 327 "src/codegen.z"
 void _ZN7codegen22generate_function_declE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 328 "src/codegen.z"
_ZN10source_map19emit_line_directiveE(ctx->out,ctx->source,item->span) ;
#line 330 "src/codegen.z"
_ZN3ast12FunctionDataE func = item->node.function;
;
#line 331 "src/codegen.z"
_ZN3ast14FunctionHeaderE header = func.header;
;
#line 333 "src/codegen.z"
_ZN3ast2TyE*  fn_ty = header.ty;
;
#line 334 "src/codegen.z"
_ZN3ast5FnDefE fn_def = fn_ty->node.function;
;
#line 336 "src/codegen.z"
_ZN7codegen11generate_tyE(ctx,fn_def.output) ;
#line 338 "src/codegen.z"
if (item->should_mangle){
#line 338 "src/codegen.z"
_ZN7codegen20mangle_function_nameE(ctx,ctx->current_module,item->ident,header) ;
}
else {
#line 339 "src/codegen.z"
fprintf(ctx->out,(( char* )(" %s")),_ZN9interning7get_strE(ctx->interner,item->ident.name) ) ;
}
;
#line 340 "src/codegen.z"
fprintf(ctx->out,(( char* )("("))) ;
#line 342 "src/codegen.z"
 u32 i = 0;
;
#line 343 "src/codegen.z"
while ( (i< header.num_parameters))
{
#line 344 "src/codegen.z"
_ZN3ast2TyE*  ty = fn_def.parameters[i];
;
#line 345 "src/codegen.z"
if ((ty->kind== TyKind_Variadic)){
#line 346 "src/codegen.z"
fprintf(ctx->out,(( char* )("..."))) ;
#line 347 "src/codegen.z"
break;
;
}
;
#line 350 "src/codegen.z"
_ZN7codegen11generate_tyE(ctx,ty) ;
#line 352 "src/codegen.z"
 char*  param_name = _ZN9interning7get_strE(ctx->interner,header.parameters[i].pat.ident.name) ;
;
#line 353 "src/codegen.z"
fprintf(ctx->out,(( char* )(" %s")),param_name) ;
#line 354 "src/codegen.z"
if ((i< ((( i32)(header.num_parameters))- 1))){
#line 354 "src/codegen.z"
fprintf(ctx->out,(( char* )(", "))) ;
}
;
#line 355 "src/codegen.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 357 "src/codegen.z"
fprintf(ctx->out,(( char* )(") "))) ;
}
#line 360 "src/codegen.z"
 void _ZN7codegen17generate_functionE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 361 "src/codegen.z"
_ZN7codegen22generate_function_declE(ctx,item) ;
#line 362 "src/codegen.z"
if ((( bool)(item->node.function.body))){
#line 362 "src/codegen.z"
_ZN7codegen13generate_exprE(ctx,item->node.function.body) ;
}
else {
#line 363 "src/codegen.z"
fprintf(ctx->out,(( char* )(";\n"))) ;
}
;
}
#line 366 "src/codegen.z"
 void _ZN7codegen13generate_enumE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 368 "src/codegen.z"
 char*  enum_name = _ZN9interning7get_strE(ctx->interner,item->ident.name) ;
;
#line 369 "src/codegen.z"
_ZN3ast6ModuleE*  module = ctx->current_module;
;
#line 371 "src/codegen.z"
_ZN10source_map19emit_line_directiveE(ctx->out,ctx->source,item->span) ;
#line 372 "src/codegen.z"
fprintf(ctx->out,(( char* )("typedef enum"))) ;
#line 373 "src/codegen.z"
_ZN7codegen21mangle_path_and_identE(ctx,module->path,item->ident) ;
#line 374 "src/codegen.z"
fprintf(ctx->out,(( char* )(" {\n"))) ;
#line 375 "src/codegen.z"
 u32 i = 0;
;
#line 377 "src/codegen.z"
_ZN3ast8EnumDataE data = item->node._enum;
;
#line 379 "src/codegen.z"
while ( (i< data.num_variants))
{
#line 380 "src/codegen.z"
 char*  variant_name = _ZN9interning7get_strE(ctx->interner,data.variants[i].ident.name) ;
;
#line 381 "src/codegen.z"
fprintf(ctx->out,(( char* )("%s_%s,\n")),enum_name,variant_name) ;
#line 382 "src/codegen.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 384 "src/codegen.z"
fprintf(ctx->out,(( char* )("}"))) ;
#line 385 "src/codegen.z"
_ZN7codegen21mangle_path_and_identE(ctx,module->path,item->ident) ;
#line 386 "src/codegen.z"
fprintf(ctx->out,(( char* )(";\n\n"))) ;
}
#line 389 "src/codegen.z"
 void _ZN7codegen17generate_compoundE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 391 "src/codegen.z"
 char*  compound_kind ;
;
#line 392 "src/codegen.z"
if ((item->kind== ItemKind_Struct)){
#line 392 "src/codegen.z"
compound_kind = "struct";
;
}
else {
#line 393 "src/codegen.z"
compound_kind = "union";
;
}
;
#line 395 "src/codegen.z"
_ZN3ast12CompoundDataE data = item->node.compound;
;
#line 397 "src/codegen.z"
_ZN3ast6ModuleE*  module = ctx->current_module;
;
#line 399 "src/codegen.z"
_ZN3ast2TyE*  compound_ty = data.ty;
;
#line 400 "src/codegen.z"
_ZN3ast11CompoundDefE*  def = &compound_ty->node.compound;
;
#line 402 "src/codegen.z"
_ZN10source_map19emit_line_directiveE(ctx->out,ctx->source,item->span) ;
#line 403 "src/codegen.z"
if (((( i32)(data.num_fields))> 0)){
#line 404 "src/codegen.z"
fprintf(ctx->out,(( char* )("typedef %s")),compound_kind) ;
#line 405 "src/codegen.z"
_ZN7codegen21mangle_path_and_identE(ctx,module->path,item->ident) ;
#line 406 "src/codegen.z"
fprintf(ctx->out,(( char* )(" {\n"))) ;
#line 407 "src/codegen.z"
 u32 i = 0;
;
#line 408 "src/codegen.z"
while ( (i< data.num_fields))
{
#line 409 "src/codegen.z"
_ZN7codegen11generate_tyE(ctx,def->fields[i].ty) ;
#line 411 "src/codegen.z"
 char*  field_name = _ZN9interning7get_strE(ctx->interner,data.fields[i].ident.name) ;
;
#line 412 "src/codegen.z"
fprintf(ctx->out,(( char* )(" %s;\n")),field_name) ;
#line 413 "src/codegen.z"
i = ((( i32)(i))+ 1);
;
}
;
#line 415 "src/codegen.z"
fprintf(ctx->out,(( char* )("}"))) ;
#line 416 "src/codegen.z"
_ZN7codegen21mangle_path_and_identE(ctx,module->path,item->ident) ;
#line 417 "src/codegen.z"
fprintf(ctx->out,(( char* )(";\n\n"))) ;
}
;
}
#line 421 "src/codegen.z"
 void _ZN7codegen22generate_compound_declE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast4ItemE*  item) {
#line 423 "src/codegen.z"
 char*  compound_kind ;
;
#line 424 "src/codegen.z"
if ((item->kind== ItemKind_Struct)){
#line 424 "src/codegen.z"
compound_kind = "struct";
;
}
else {
#line 425 "src/codegen.z"
compound_kind = "union";
;
}
;
#line 426 "src/codegen.z"
_ZN3ast6ModuleE*  module = ctx->current_module;
;
#line 428 "src/codegen.z"
_ZN10source_map19emit_line_directiveE(ctx->out,ctx->source,item->span) ;
#line 429 "src/codegen.z"
fprintf(ctx->out,(( char* )("typedef %s")),compound_kind) ;
#line 430 "src/codegen.z"
_ZN7codegen21mangle_path_and_identE(ctx,module->path,item->ident) ;
#line 431 "src/codegen.z"
_ZN7codegen21mangle_path_and_identE(ctx,module->path,item->ident) ;
#line 432 "src/codegen.z"
fprintf(ctx->out,(( char* )(";\n\n"))) ;
}
#line 435 "src/codegen.z"
 void _ZN7codegen22generate_mod_type_declE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast6ModuleE*  module) {
#line 436 "src/codegen.z"
ctx->current_module = module;
;
#line 437 "src/codegen.z"
 u32 i = 0;
;
#line 438 "src/codegen.z"
while ( (i< module->num_items))
{
#line 439 "src/codegen.z"
_ZN3ast4ItemE*  item = &module->items[i];
;
#line 440 "src/codegen.z"
if ((item->kind== ItemKind_Enum)){
#line 440 "src/codegen.z"
_ZN7codegen13generate_enumE(ctx,item) ;
}
else {
#line 441 "src/codegen.z"
if (((item->kind== ItemKind_Struct)|| (item->kind== ItemKind_Union))){
#line 441 "src/codegen.z"
_ZN7codegen22generate_compound_declE(ctx,item) ;
}
;
}
;
#line 442 "src/codegen.z"
i = ((( i32)(i))+ 1);
;
}
;
}
#line 446 "src/codegen.z"
 void _ZN7codegen22generate_mod_type_defsE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast6ModuleE*  module) {
#line 447 "src/codegen.z"
ctx->current_module = module;
;
#line 448 "src/codegen.z"
 u32 i = 0;
;
#line 449 "src/codegen.z"
while ( (i< module->num_items))
{
#line 450 "src/codegen.z"
_ZN3ast4ItemE*  item = &module->items[i];
;
#line 451 "src/codegen.z"
if (((item->kind== ItemKind_Const)|| (item->kind== ItemKind_Variable))){
#line 451 "src/codegen.z"
_ZN7codegen17generate_variableE(ctx,item) ;
}
else {
#line 452 "src/codegen.z"
if (((item->kind== ItemKind_Struct)|| (item->kind== ItemKind_Union))){
#line 452 "src/codegen.z"
_ZN7codegen17generate_compoundE(ctx,item) ;
}
;
}
;
#line 453 "src/codegen.z"
i = ((( i32)(i))+ 1);
;
}
;
}
#line 457 "src/codegen.z"
 void _ZN7codegen20generate_mod_fn_declE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast6ModuleE*  module) {
#line 458 "src/codegen.z"
ctx->current_module = module;
;
#line 459 "src/codegen.z"
 u32 i = 0;
;
#line 460 "src/codegen.z"
while ( (i< module->num_items))
{
#line 461 "src/codegen.z"
_ZN3ast4ItemE*  item = &module->items[i];
;
#line 462 "src/codegen.z"
if ((item->kind== ItemKind_Function)){
#line 463 "src/codegen.z"
_ZN7codegen22generate_function_declE(ctx,item) ;
#line 464 "src/codegen.z"
fprintf(ctx->out,(( char* )(";\n"))) ;
}
;
#line 466 "src/codegen.z"
i = ((( i32)(i))+ 1);
;
}
;
}
#line 470 "src/codegen.z"
 void _ZN7codegen22generate_mod_fn_bodiesE(_ZN7codegen14CodegenContextE*  ctx, _ZN3ast6ModuleE*  module) {
#line 471 "src/codegen.z"
ctx->current_module = module;
;
#line 472 "src/codegen.z"
 u32 i = 0;
;
#line 473 "src/codegen.z"
while ( (i< module->num_items))
{
#line 474 "src/codegen.z"
_ZN3ast4ItemE*  item = &module->items[i];
;
#line 475 "src/codegen.z"
if ((item->kind== ItemKind_Function)){
#line 475 "src/codegen.z"
_ZN7codegen17generate_functionE(ctx,item) ;
}
;
#line 476 "src/codegen.z"
i = ((( i32)(i))+ 1);
;
}
;
}
#line 480 "src/codegen.z"
 void _ZN7codegen8generateE(_ZN7session7SessionE*  sess, _ZN3ast13CompileTargetE*  target,  char*  output_file) {
#line 481 "src/codegen.z"
_ZN7codegen14CodegenContextE ctx ;
;
#line 483 "src/codegen.z"
ctx.out = fopen((( char* )(output_file)),(( char* )("w"))) ;
;
#line 484 "src/codegen.z"
ctx.sess = sess;
;
#line 485 "src/codegen.z"
ctx.interner = &sess->interner;
;
#line 486 "src/codegen.z"
ctx.source = &sess->source;
;
#line 488 "src/codegen.z"
_ZN7codegen16generate_preludeE(&ctx) ;
#line 490 "src/codegen.z"
 i32 i = 0;
;
#line 491 "src/codegen.z"
while ( ((( u32)(i))< target->num_modules))
{
#line 492 "src/codegen.z"
_ZN7codegen22generate_mod_type_declE(&ctx,target->modules[i]) ;
#line 493 "src/codegen.z"
i = (i+ 1);
;
}
;
#line 496 "src/codegen.z"
i = 0;
;
#line 497 "src/codegen.z"
while ( ((( u32)(i))< target->num_modules))
{
#line 498 "src/codegen.z"
_ZN7codegen22generate_mod_type_defsE(&ctx,target->modules[i]) ;
#line 499 "src/codegen.z"
i = (i+ 1);
;
}
;
#line 502 "src/codegen.z"
i = 0;
;
#line 503 "src/codegen.z"
while ( ((( u32)(i))< target->num_modules))
{
#line 504 "src/codegen.z"
_ZN7codegen20generate_mod_fn_declE(&ctx,target->modules[i]) ;
#line 505 "src/codegen.z"
i = (i+ 1);
;
}
;
#line 508 "src/codegen.z"
i = 0;
;
#line 509 "src/codegen.z"
while ( ((( u32)(i))< target->num_modules))
{
#line 510 "src/codegen.z"
_ZN7codegen22generate_mod_fn_bodiesE(&ctx,target->modules[i]) ;
#line 511 "src/codegen.z"
i = (i+ 1);
;
}
;
}
