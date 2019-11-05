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
typedef struct Scope Scope;
#line 2 "src/resolution.z"
typedef struct Scope {
  IntMap *symbols;
  u32 current_owner;
  u32 next_local;
} Scope;

typedef struct ResolutionContext ResolutionContext;
#line 8 "src/resolution.z"
typedef struct ResolutionContext {
  Scope *scope_stack;
  u32 stack_top;
  CompilationUnit *unit;
  SourceMap *source_map;
  Interner *interner;
} ResolutionContext;

#line 16 "src/resolution.z"
u64 encode_id(NodeId id) {
#line 17 "src/resolution.z"
#line 17 "src/resolution.z"
  u64 owner = id.owner;

#line 18 "src/resolution.z"
#line 18 "src/resolution.z"
  u64 v = ((owner << 32) | id.local);

#line 19 "src/resolution.z"
  return v;
}

#line 22 "src/resolution.z"
NodeId decode_id(u64 v) {
#line 23 "src/resolution.z"
#line 23 "src/resolution.z"
  NodeId id;

#line 24 "src/resolution.z"
  id.owner = (v >> 32);
#line 25 "src/resolution.z"
  id.local = v;
#line 26 "src/resolution.z"
  return id;
}

#line 29 "src/resolution.z"
void push_ident(ResolutionContext *ctx, Ident ident, NodeId id) {
#line 30 "src/resolution.z"
  intmap_insert(ctx->scope_stack[ctx->stack_top].symbols, ident.name.x,
                encode_id(id));
}

#line 33 "src/resolution.z"
bool lookup_ident(ResolutionContext *ctx, Ident ident, NodeId *id) {
#line 34 "src/resolution.z"
#line 34 "src/resolution.z"
  i32 i = ctx->stack_top;

#line 36 "src/resolution.z"
  while ((i >= 0)) {
#line 37 "src/resolution.z"
#line 37 "src/resolution.z"
    u64 v = intmap_lookup(ctx->scope_stack[i].symbols, ident.name.x);

#line 38 "src/resolution.z"
    if ((v > 0)) {
#line 39 "src/resolution.z"
      *id = decode_id(v);
#line 40 "src/resolution.z"
      return true;
    };
#line 42 "src/resolution.z"
    i = (i - 1);
  };
#line 44 "src/resolution.z"
  return false;
}

#line 47 "src/resolution.z"
void push_scope(ResolutionContext *ctx) {
#line 48 "src/resolution.z"
  ctx->stack_top = (ctx->stack_top + 1);
#line 49 "src/resolution.z"
  ctx->scope_stack[ctx->stack_top].current_owner =
      ctx->scope_stack[(ctx->stack_top - 1)].current_owner;
#line 50 "src/resolution.z"
  ctx->scope_stack[ctx->stack_top].next_local = 2;
}

#line 53 "src/resolution.z"
void pop_scope(ResolutionContext *ctx) {
#line 54 "src/resolution.z"
  intmap_reset(ctx->scope_stack[ctx->stack_top].symbols);
#line 55 "src/resolution.z"
  ctx->stack_top = (ctx->stack_top - 1);
}

#line 58 "src/resolution.z"
void scan_item(ResolutionContext *ctx, Item *item) {
#line 59 "src/resolution.z"
  push_ident(ctx, item->ident, item->id);
}

#line 62 "src/resolution.z"
void resolve_path(ResolutionContext *ctx, Path *path) {
#line 63 "src/resolution.z"
#line 63 "src/resolution.z"
  NodeId id;

#line 64 "src/resolution.z"
  if (lookup_ident(ctx, path->segments[0], &id)) {
#line 65 "src/resolution.z"
    path->res.kind = ResKind_Definition;
#line 66 "src/resolution.z"
    path->res.node.def = id;
  } else {
#line 69 "src/resolution.z"
    printf("Failed to resolve %s\n",
           get_str(ctx->interner, path->segments[0].name));
  };
}

#line 73 "src/resolution.z"
void resolve_expr(ResolutionContext *ctx, Expr *expr);

#line 74 "src/resolution.z"
void resolve_block(ResolutionContext *ctx, Block *block);

#line 75 "src/resolution.z"
void resolve_stmt(ResolutionContext *ctx, Stmt *stmt);

#line 76 "src/resolution.z"
void resolve_item(ResolutionContext *ctx, Item *item);

#line 78 "src/resolution.z"
void resolve_unary(ResolutionContext *ctx, UnaryData unary) {
#line 79 "src/resolution.z"
  resolve_expr(ctx, unary.inner);
}

#line 82 "src/resolution.z"
void resolve_binary(ResolutionContext *ctx, BinaryData binary) {
#line 83 "src/resolution.z"
  resolve_expr(ctx, binary.left);
#line 84 "src/resolution.z"
  resolve_expr(ctx, binary.right);
}

#line 87 "src/resolution.z"
void resolve_call(ResolutionContext *ctx, CallData call) {
#line 88 "src/resolution.z"
  resolve_expr(ctx, call.func);
#line 90 "src/resolution.z"
#line 90 "src/resolution.z"
  u32 i = 0;

#line 91 "src/resolution.z"
  while ((i < call.num_args)) {
#line 92 "src/resolution.z"
    resolve_expr(ctx, call.args[i]);
#line 93 "src/resolution.z"
    i = (i + 1);
  };
}

#line 97 "src/resolution.z"
void resolve_conditional(ResolutionContext *ctx, ConditionalData cond) {
#line 98 "src/resolution.z"
  resolve_expr(ctx, cond.condition);
#line 99 "src/resolution.z"
  resolve_expr(ctx, cond.then);
#line 100 "src/resolution.z"
  if (cond.otherwise) {
#line 101 "src/resolution.z"
    resolve_expr(ctx, cond.otherwise);
  };
}

#line 105 "src/resolution.z"
void resolve_while(ResolutionContext *ctx, WhileData data) {
#line 106 "src/resolution.z"
  resolve_expr(ctx, data.condition);
#line 107 "src/resolution.z"
  resolve_expr(ctx, data.body);
}

#line 110 "src/resolution.z"
void resolve_indexing(ResolutionContext *ctx, IndexingData idx) {
#line 111 "src/resolution.z"
  resolve_expr(ctx, idx.array);
#line 112 "src/resolution.z"
  resolve_expr(ctx, idx.index);
}

#line 115 "src/resolution.z"
void resolve_field(ResolutionContext *ctx, FieldData field) {
#line 116 "src/resolution.z"
  resolve_expr(ctx, field.strct);
}

#line 119 "src/resolution.z"
void resolve_expr(ResolutionContext *ctx, Expr *expr) {
#line 120 "src/resolution.z"
  if ((expr->kind == ExprKind_Unary)) {
#line 120 "src/resolution.z"
    resolve_unary(ctx, expr->node.unary);
  } else {
#line 121 "src/resolution.z"
    if ((expr->kind == ExprKind_Binary)) {
#line 121 "src/resolution.z"
      resolve_binary(ctx, expr->node.binary);
    } else {
#line 122 "src/resolution.z"
      if ((expr->kind == ExprKind_Block)) {
#line 122 "src/resolution.z"
        resolve_block(ctx, expr->node.block);
      } else {
#line 123 "src/resolution.z"
        if ((expr->kind == ExprKind_Call)) {
#line 123 "src/resolution.z"
          resolve_call(ctx, expr->node.call);
        } else {
#line 124 "src/resolution.z"
          if ((expr->kind == ExprKind_Conditional)) {
#line 124 "src/resolution.z"
            resolve_conditional(ctx, expr->node.conditional);
          } else {
#line 125 "src/resolution.z"
            if ((expr->kind == ExprKind_While)) {
#line 125 "src/resolution.z"
              resolve_while(ctx, expr->node.whl);
            } else {
#line 126 "src/resolution.z"
              if ((expr->kind == ExprKind_Indexing)) {
#line 126 "src/resolution.z"
                resolve_indexing(ctx, expr->node.indexing);
              } else {
#line 127 "src/resolution.z"
                if ((expr->kind == ExprKind_Field)) {
#line 127 "src/resolution.z"
                  resolve_field(ctx, expr->node.field);
                } else {
#line 128 "src/resolution.z"
                  if ((expr->kind == ExprKind_Path)) {
#line 128 "src/resolution.z"
                    resolve_path(ctx, &expr->node.path);
                  };
                };
              };
            };
          };
        };
      };
    };
  };
}

#line 131 "src/resolution.z"
void resolve_assignment(ResolutionContext *ctx, AssignmentData assignment) {
#line 132 "src/resolution.z"
  resolve_expr(ctx, assignment.left);
#line 133 "src/resolution.z"
  resolve_expr(ctx, assignment.right);
}

#line 136 "src/resolution.z"
void resolve_stmt(ResolutionContext *ctx, Stmt *stmt) {
#line 137 "src/resolution.z"
  if ((stmt->kind == StmtKind_Assignment)) {
#line 137 "src/resolution.z"
    resolve_assignment(ctx, stmt->node.assignment);
  } else {
#line 138 "src/resolution.z"
    if ((stmt->kind == StmtKind_Expr)) {
#line 138 "src/resolution.z"
      resolve_expr(ctx, stmt->node.expr);
    } else {
#line 139 "src/resolution.z"
      if ((stmt->kind == StmtKind_Item)) {
#line 139 "src/resolution.z"
        resolve_item(ctx, unit_get_item(ctx->unit, stmt->node.item));
      } else {
#line 140 "src/resolution.z"
        if ((stmt->kind == StmtKind_Return)) {
#line 140 "src/resolution.z"
          resolve_expr(ctx, stmt->node._return);
        };
      };
    };
  };
}

#line 143 "src/resolution.z"
void resolve_block(ResolutionContext *ctx, Block *block) {
#line 145 "src/resolution.z"
  push_scope(ctx);
#line 146 "src/resolution.z"
#line 146 "src/resolution.z"
  u32 i = 0;

#line 147 "src/resolution.z"
  while ((i < block->num_stmts)) {
#line 148 "src/resolution.z"
#line 148 "src/resolution.z"
    Stmt *stmt = block->stmts[i];

#line 149 "src/resolution.z"
    if ((stmt->kind == StmtKind_Item)) {
#line 150 "src/resolution.z"
#line 150 "src/resolution.z"
      Item *item = unit_get_item(ctx->unit, stmt->node.item);

#line 151 "src/resolution.z"
      push_ident(ctx, item->ident, stmt->node.item);
    };
#line 153 "src/resolution.z"
    i = (i + 1);
  };
#line 156 "src/resolution.z"
  i = 0;
#line 157 "src/resolution.z"
  while ((i < block->num_stmts)) {
#line 158 "src/resolution.z"
    resolve_stmt(ctx, block->stmts[i]);
#line 159 "src/resolution.z"
    i = (i + 1);
  };
#line 161 "src/resolution.z"
  pop_scope(ctx);
}

#line 164 "src/resolution.z"
void resolve_body(ResolutionContext *ctx, Body body) {
#line 165 "src/resolution.z"
  resolve_expr(ctx, body.value);
}

#line 168 "src/resolution.z"
void resolve_function(ResolutionContext *ctx, Item *item) {
#line 169 "src/resolution.z"
#line 169 "src/resolution.z"
  Scope *scope = &ctx->scope_stack[ctx->stack_top];

#line 170 "src/resolution.z"
#line 170 "src/resolution.z"
  FunctionData func = item->node.function;

#line 171 "src/resolution.z"
  if (func.body.local) {
#line 172 "src/resolution.z"
    scope->current_owner = item->id.owner;
#line 173 "src/resolution.z"
    push_scope(ctx);
#line 174 "src/resolution.z"
#line 174 "src/resolution.z"
    u32 i = 0;

#line 175 "src/resolution.z"
    while ((i < func.header.num_parameters)) {
#line 176 "src/resolution.z"
#line 176 "src/resolution.z"
      FunctionParameter *param = &func.header.parameters[i];

#line 177 "src/resolution.z"
      param->id.owner = scope->current_owner;
#line 178 "src/resolution.z"
      param->id.local = scope->next_local;
#line 179 "src/resolution.z"
      scope->next_local = (scope->next_local + 1);
#line 181 "src/resolution.z"
      push_ident(ctx, func.header.parameters[i].ident, param->id);
#line 182 "src/resolution.z"
      i = (i + 1);
    };
#line 185 "src/resolution.z"
    resolve_body(ctx, unit_get_body(ctx->unit, item->node.function.body));
#line 186 "src/resolution.z"
    pop_scope(ctx);
  };
}

#line 190 "src/resolution.z"
void resolve_variable(ResolutionContext *ctx, Item *item) {
#line 191 "src/resolution.z"
#line 191 "src/resolution.z"
  Scope *scope = &ctx->scope_stack[ctx->stack_top];

#line 192 "src/resolution.z"
  if (item->node.variable.body.local) {
#line 193 "src/resolution.z"
    scope->current_owner = item->id.owner;
#line 194 "src/resolution.z"
    resolve_body(ctx, unit_get_body(ctx->unit, item->node.variable.body));
  };
}

#line 198 "src/resolution.z"
void resolve_item(ResolutionContext *ctx, Item *item) {
#line 199 "src/resolution.z"
  if (((item->kind == ItemKind_Const) || (item->kind == ItemKind_Variable))) {
#line 199 "src/resolution.z"
    resolve_variable(ctx, item);
  };
#line 200 "src/resolution.z"
  if ((item->kind == ItemKind_Function)) {
#line 200 "src/resolution.z"
    resolve_function(ctx, item);
  };
}

#line 203 "src/resolution.z"
void resolve(Session *sess, CompilationUnit *unit) {
#line 204 "src/resolution.z"
#line 204 "src/resolution.z"
  ResolutionContext ctx;

#line 206 "src/resolution.z"
  ctx.interner = &sess->interner;
#line 207 "src/resolution.z"
  ctx.unit = unit;
#line 208 "src/resolution.z"
  ctx.scope_stack = malloc((sizeof(Scope) * 128));
#line 209 "src/resolution.z"
  ctx.stack_top = 0;
#line 210 "src/resolution.z"
#line 210 "src/resolution.z"
  u32 i = 0;

#line 211 "src/resolution.z"
  while ((i < 128)) {
#line 212 "src/resolution.z"
    ctx.scope_stack[i].symbols = intmap_create(1024);
#line 213 "src/resolution.z"
    i = (i + 1);
  };
#line 216 "src/resolution.z"
  i = 0;
#line 217 "src/resolution.z"
  while ((i < unit->module.num_items)) {
#line 218 "src/resolution.z"
#line 218 "src/resolution.z"
    Item *item = unit_get_item(unit, unit->module.items[i]);

#line 219 "src/resolution.z"
    scan_item(&ctx, item);
#line 220 "src/resolution.z"
    i = (i + 1);
  };
#line 223 "src/resolution.z"
  i = 0;
#line 224 "src/resolution.z"
  while ((i < unit->module.num_items)) {
#line 225 "src/resolution.z"
#line 225 "src/resolution.z"
    Item *item = unit_get_item(unit, unit->module.items[i]);

#line 226 "src/resolution.z"
    resolve_item(&ctx, item);
#line 227 "src/resolution.z"
    i = (i + 1);
  };
}
