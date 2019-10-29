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
typedef struct LoweringContext LoweringContext;
typedef struct LoweringContext {
  u32 padding;
} LoweringContext;

Expr *lower_expr(LoweringContext *ctx, AstExpr *ast);

Block *lower_block(LoweringContext *ctx, AstBlock *ast);

Item *lower_item(LoweringContext *ctx, AstItem *ast);

HirId create_id(LoweringContext *ctx) {
  HirId id;

  id.owner = 0;
  id.local = 0;
  return id;
}

Type *lower_type(LoweringContext *ctx, AstType *ast) {
  Type *ty = malloc(sizeof(Type));

  if ((ast->kind == _AstTypeKind_Path)) {
    ty->kind = _TypeKind_Path;
    ty->node.path = ast->node.path;
  } else {
    if ((ast->kind == _AstTypeKind_Ptr)) {
      ty->kind = _TypeKind_Ptr;
      ty->node.ptr = lower_type(ctx, ast->node.ptr);
    } else {
      if ((ast->kind == _AstTypeKind_Unit)) {
        ty->kind = _TypeKind_Unit;
      } else {
        abort();
      };
    };
  };
  return ty;
}

void lower_unary(LoweringContext *ctx, AstExpr *ast, Expr *expr) {
  expr->kind = _ExprKind_Unary;
  expr->node.unary.op = ast->node.unary.operator;
  expr->node.unary.inner = lower_expr(ctx, ast->node.unary.inner);
}

void lower_binary(LoweringContext *ctx, AstExpr *ast, Expr *expr) {
  expr->kind = _ExprKind_Binary;
  expr->node.binary.op = ast->node.binary.operator;
  expr->node.binary.left = lower_expr(ctx, ast->node.binary.left);
  expr->node.binary.right = lower_expr(ctx, ast->node.binary.right);
}

void lower_call(LoweringContext *ctx, AstExpr *ast, Expr *expr) {
  expr->kind = _ExprKind_Call;
  expr->node.call.func = lower_expr(ctx, ast->node.call.func);
  expr->node.call.num_args = ast->node.call.num_args;
  expr->node.call.args = malloc((8 * expr->node.call.num_args));
  u32 i = 0;

  while ((i < expr->node.call.num_args)) {
    expr->node.call.args[i] = lower_expr(ctx, ast->node.call.args[i]);
    i = (i + 1);
  }
}

void lower_conditional(LoweringContext *ctx, AstExpr *ast, Expr *expr) {
  expr->kind = _ExprKind_Conditional;
  expr->node.conditional.condition =
      lower_expr(ctx, ast->node.conditional.condition);
  expr->node.conditional.then = lower_block(ctx, ast->node.conditional.then);
  if (ast->node.conditional.otherwise) {
    expr->node.conditional.otherwise =
        lower_block(ctx, ast->node.conditional.otherwise);
  } else {
    expr->node.conditional.otherwise = null;
  };
}

void lower_field(LoweringContext *ctx, AstExpr *ast, Expr *expr) {
  expr->kind = _ExprKind_Field;
  expr->node.field.strct = lower_expr(ctx, ast->node.field.strct);
  expr->node.field.ident.name = ast->node.field.field_name;
}

void lower_indexing(LoweringContext *ctx, AstExpr *ast, Expr *expr) {
  expr->kind = _ExprKind_Indexing;
  expr->node.indexing.array = lower_expr(ctx, ast->node.index.array);
  expr->node.indexing.index = lower_expr(ctx, ast->node.index.index);
}

void lower_ident(LoweringContext *ctx, AstExpr *ast, Expr *expr) {
  expr->kind = _ExprKind_Identifier;
  expr->node.ident.name = ast->node.identifier;
}

void lower_path(LoweringContext *ctx, AstExpr *ast, Expr *expr) {
  Path path;

  path.num_segments = ast->node.path.num_segments;
  path.segments = malloc((8 * path.num_segments));
  memcpy(path.segments, ast->node.path.segments, (8 * path.num_segments));
  expr->kind = _ExprKind_Path;
  expr->node.path = path;
}

void lower_lit(LoweringContext *ctx, AstExpr *ast, Expr *expr) {
  expr->kind = _ExprKind_Literal;
  expr->node.lit = ast->node.literal;
}

Expr *lower_expr(LoweringContext *ctx, AstExpr *ast) {
  Expr *expr = malloc(sizeof(Expr));

  expr->id = create_id(ctx);
  if ((ast->kind == _AstExprKind_Binary)) {
    lower_binary(ctx, ast, expr);
  } else {
    if ((ast->kind == _AstExprKind_Call)) {
      lower_call(ctx, ast, expr);
    } else {
      if ((ast->kind == _AstExprKind_Conditional)) {
        lower_conditional(ctx, ast, expr);
      } else {
        if ((ast->kind == _AstExprKind_Field)) {
          lower_field(ctx, ast, expr);
        } else {
          if ((ast->kind == _AstExprKind_Indexing)) {
            lower_indexing(ctx, ast, expr);
          } else {
            if ((ast->kind == _AstExprKind_Identifier)) {
              lower_ident(ctx, ast, expr);
            } else {
              if ((ast->kind == _AstExprKind_Path)) {
                lower_path(ctx, ast, expr);
              } else {
                if ((ast->kind == _AstExprKind_Literal)) {
                  lower_lit(ctx, ast, expr);
                } else {
                  if ((ast->kind == _AstExprKind_Unary)) {
                    lower_unary(ctx, ast, expr);
                  } else {
                    abort();
                  };
                };
              };
            };
          };
        };
      };
    };
  };
  return expr;
}

Stmt *lower_stmt(LoweringContext *ctx, AstStmt *ast) {
  Stmt *stmt = malloc(sizeof(Stmt));

  if ((ast->kind == _AstStmtKind_Assignment)) {
    stmt->kind = _StmtKind_Assignment;
    stmt->node.assignment.left = lower_expr(ctx, ast->node.assignment.left);
    stmt->node.assignment.right = lower_expr(ctx, ast->node.assignment.right);
  } else {
    if ((ast->kind == _AstStmtKind_Item)) {
      stmt->kind = _StmtKind_Item;
      stmt->node.item = lower_item(ctx, ast->node.item);
    } else {
      if ((ast->kind == _AstStmtKind_Expr)) {
        stmt->kind = _StmtKind_Expr;
        stmt->node.expr = lower_expr(ctx, ast->node.expr);
      } else {
        if ((ast->kind == _AstStmtKind_Return)) {
          stmt->kind = _StmtKind_Return;
          stmt->node._return = lower_expr(ctx, ast->node._return);
        } else {
          if ((ast->kind == _AstStmtKind_Break)) {
            stmt->kind = _StmtKind_Break;
          } else {
            if ((ast->kind == _AstStmtKind_Continue)) {
              stmt->kind = _StmtKind_Continue;
            } else {
              if ((ast->kind == _AstStmtKind_While)) {
                stmt->kind = _StmtKind_While;
                stmt->node._while.condition =
                    lower_expr(ctx, ast->node._while.condition);
                stmt->node._while.body =
                    lower_block(ctx, ast->node._while.body);
              } else {
                abort();
              };
            };
          };
        };
      };
    };
  };
  return stmt;
}

Block *lower_block(LoweringContext *ctx, AstBlock *ast) {
  Block *block = malloc(sizeof(Block));

  block->id = create_id(ctx);
  block->num_stmts = ast->num_stmts;
  block->stmts = malloc((8 * block->num_stmts));
  u32 i = 0;

  while ((i < block->num_stmts)) {
    block->stmts[i] = lower_stmt(ctx, ast->stmts[i]);
    i = (i + 1);
  }
  return block;
}

void lower_variable(LoweringContext *ctx, AstItem *ast, Item *item) {
  if ((ast->kind == _AstItemKind_Const)) {
    item->kind = _ItemKind_Const;
  } else {
    item->kind = _ItemKind_Variable;
  };
  item->node.variable.ty = lower_type(ctx, ast->node.variable.type);
  if (ast->node.variable.value) {
    item->node.variable.body = lower_expr(ctx, ast->node.variable.value);
  } else {
    item->node.variable.body = null;
  };
}

void lower_function(LoweringContext *ctx, AstItem *ast, Item *item) {
  item->kind = _ItemKind_Function;
  item->node.function.output =
      lower_type(ctx, ast->node.function.signature.output_type);
  item->node.function.num_parameters =
      ast->node.function.signature.num_parameters;
  item->node.function.parameters =
      malloc((sizeof(FunctionParameter) * item->node.function.num_parameters));
  u32 i = 0;

  while ((i < item->node.function.num_parameters)) {
    item->node.function.parameters[i].name.name =
        ast->node.function.signature.parameter_names[i];
    item->node.function.parameters[i].ty =
        lower_type(ctx, ast->node.function.signature.parameter_types[i]);
    i = (i + 1);
  }
  if (ast->node.function.block) {
    item->node.function.body = lower_block(ctx, ast->node.function.block);
  } else {
    item->node.function.body = null;
  };
}

void lower_enum(LoweringContext *ctx, AstItem *ast, Item *item) {
  item->kind = _ItemKind_Enum;
  item->node._enum.num_variants = ast->node._enum.num_fields;
  item->node._enum.variants =
      malloc((sizeof(EnumVariant) * item->node._enum.num_variants));
  u32 i = 0;

  while ((i < item->node._enum.num_variants)) {
    item->node._enum.variants[i].ident.name = ast->node._enum.field_names[i];
    i = (i + 1);
  }
}

void lower_compound(LoweringContext *ctx, AstItem *ast, Item *item) {
  if ((ast->kind == _AstItemKind_Union)) {
    item->kind = _ItemKind_Union;
  } else {
    item->kind = _ItemKind_Struct;
  };
  item->node.compound.num_fields = ast->node.compound_type.num_fields;
  item->node.compound.fields =
      malloc((sizeof(CompoundField) * item->node.compound.num_fields));
  u32 i = 0;

  while ((i < item->node.compound.num_fields)) {
    item->node.compound.fields[i].ident.name =
        ast->node.compound_type.field_names[i];
    item->node.compound.fields[i].ty =
        lower_type(ctx, ast->node.compound_type.field_types[i]);
    i = (i + 1);
  }
}

Item *lower_item(LoweringContext *ctx, AstItem *ast) {
  Item *item = malloc(sizeof(Item));

  item->id = create_id(ctx);
  item->ident.name = ast->name;
  item->vis.kind = _VisibilityKind_Private;
  if (((ast->kind == _AstItemKind_Const) ||
       (ast->kind == _AstItemKind_Variable))) {
    lower_variable(ctx, ast, item);
  } else {
    if ((ast->kind == _AstItemKind_Function)) {
      lower_function(ctx, ast, item);
    } else {
      if ((ast->kind == _AstItemKind_Enum)) {
        lower_enum(ctx, ast, item);
      } else {
        if (((ast->kind == _AstItemKind_Union) ||
             (ast->kind == _AstItemKind_Struct))) {
          lower_compound(ctx, ast, item);
        };
      };
    };
  };
  return item;
}

Item **lower(AstItem **ast_items, u32 num_ast_items, u32 *num_hir_items) {
  LoweringContext ctx;

  Item **items = malloc((8 * num_ast_items));

  u32 i = 0;

  while ((i < num_ast_items)) {
    items[i] = lower_item(&ctx, ast_items[i]);
    i = (i + 1);
  }
  *num_hir_items = num_ast_items;
  return items;
}
