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
typedef struct CodegenContext CodegenContext;
#line 2 "src/codegen.z"
typedef struct CodegenContext {
  FILE *out;
  StrMap *ident_is_ptr;
  Session *sess;
  CompilationUnit *unit;
  SourceMap *source;
} CodegenContext;

#line 10 "src/codegen.z"
void generate_expr(CodegenContext *ctx, Expr *expr);

#line 11 "src/codegen.z"
void generate_block(CodegenContext *ctx, Block *block);

#line 12 "src/codegen.z"
void generate_stmt(CodegenContext *ctx, Stmt *stmt);

#line 13 "src/codegen.z"
void generate_item(CodegenContext *ctx, Item *item);

#line 15 "src/codegen.z"
bool type_is_ptr(Type *ty) {
#line 16 "src/codegen.z"
  return (ty->kind == TypeKind_Ptr);
}

#line 19 "src/codegen.z"
void generate_prelude(CodegenContext *ctx) {
#line 20 "src/codegen.z"
  fprintf(ctx->out, "//Prelude\n");
#line 21 "src/codegen.z"
  fprintf(ctx->out, "#include <stdint.h>\n");
#line 22 "src/codegen.z"
  fprintf(ctx->out, "#include <stdbool.h>\n");
#line 23 "src/codegen.z"
  fprintf(ctx->out, "#include <stdio.h>\n");
#line 24 "src/codegen.z"
  fprintf(ctx->out, "#include <stdlib.h>\n");
#line 25 "src/codegen.z"
  fprintf(ctx->out, "#include <string.h>\n");
#line 26 "src/codegen.z"
  fprintf(ctx->out, "typedef uint8_t u8;\n");
#line 27 "src/codegen.z"
  fprintf(ctx->out, "typedef uint16_t u16;\n");
#line 28 "src/codegen.z"
  fprintf(ctx->out, "typedef uint32_t u32;\n");
#line 29 "src/codegen.z"
  fprintf(ctx->out, "typedef uint64_t u64;\n");
#line 30 "src/codegen.z"
  fprintf(ctx->out, "typedef int8_t i8;\n");
#line 31 "src/codegen.z"
  fprintf(ctx->out, "typedef int16_t i16;\n");
#line 32 "src/codegen.z"
  fprintf(ctx->out, "typedef int32_t i32;\n");
#line 33 "src/codegen.z"
  fprintf(ctx->out, "typedef int64_t i64;\n");
#line 34 "src/codegen.z"
  fprintf(ctx->out, "typedef float f32;\n");
#line 35 "src/codegen.z"
  fprintf(ctx->out, "typedef double f64;\n");
#line 36 "src/codegen.z"
  fprintf(ctx->out, "#define null 0ul\n");
}

#line 39 "src/codegen.z"
void generate_sid(CodegenContext *ctx, Sid sid) {
#line 40 "src/codegen.z"
#line 40 "src/codegen.z"
  Session *sess = ctx->sess;

#line 41 "src/codegen.z"
  fprintf(ctx->out, "%s", get_str(&sess->interner, sid));
}

#line 44 "src/codegen.z"
void generate_identifier(CodegenContext *ctx, Ident ident) {
#line 45 "src/codegen.z"
  generate_sid(ctx, ident.name);
}

#line 48 "src/codegen.z"
void generate_type(CodegenContext *ctx, Type *ty) {
#line 49 "src/codegen.z"
  if ((ty->kind == TypeKind_Path)) {
#line 49 "src/codegen.z"
    generate_sid(ctx, ty->node.path);
  } else {
#line 50 "src/codegen.z"
    if ((ty->kind == TypeKind_Ptr)) {
#line 51 "src/codegen.z"
      generate_type(ctx, ty->node.ptr);
#line 52 "src/codegen.z"
      fprintf(ctx->out, "* ");
    } else {
#line 54 "src/codegen.z"
      if ((ty->kind == TypeKind_Unit)) {
#line 55 "src/codegen.z"
        fprintf(ctx->out, "void ");
      } else {
#line 57 "src/codegen.z"
        abort();
      };
    };
  };
}

#line 60 "src/codegen.z"
void generate_char(CodegenContext *ctx, char c) {
#line 61 "src/codegen.z"
  if ((c == '\n')) {
#line 61 "src/codegen.z"
    fprintf(ctx->out, "'\\n'");
  } else {
#line 62 "src/codegen.z"
    if ((c == '\t')) {
#line 62 "src/codegen.z"
      fprintf(ctx->out, "'\\t'");
    } else {
#line 63 "src/codegen.z"
      if ((c == '\r')) {
#line 63 "src/codegen.z"
        fprintf(ctx->out, "'\\r'");
      } else {
#line 64 "src/codegen.z"
        if ((c == '\\')) {
#line 64 "src/codegen.z"
          fprintf(ctx->out, "'\\\\'");
        } else {
#line 65 "src/codegen.z"
          if ((c == '\'')) {
#line 65 "src/codegen.z"
            fprintf(ctx->out, "'\\''");
          } else {
#line 66 "src/codegen.z"
            fprintf(ctx->out, "'%c'", c);
          };
        };
      };
    };
  };
}

#line 69 "src/codegen.z"
void generate_literal(CodegenContext *ctx, Literal lit) {
#line 70 "src/codegen.z"
  if ((lit.kind == LiteralKind_Int)) {
#line 70 "src/codegen.z"
    fprintf(ctx->out, "%ld", lit.value.integer);
  } else {
#line 71 "src/codegen.z"
    if ((lit.kind == LiteralKind_Float)) {
#line 71 "src/codegen.z"
      fprintf(ctx->out, "%f", lit.value.floating);
    } else {
#line 72 "src/codegen.z"
      if ((lit.kind == LiteralKind_Bool)) {
#line 72 "src/codegen.z"
        if (lit.value.boolean) {
#line 72 "src/codegen.z"
          fprintf(ctx->out, "true");
        } else {
#line 72 "src/codegen.z"
          fprintf(ctx->out, "false");
        };
      } else {
#line 73 "src/codegen.z"
        if ((lit.kind == LiteralKind_Str)) {
#line 74 "src/codegen.z"
#line 74 "src/codegen.z"
          Session *sess = ctx->sess;

#line 75 "src/codegen.z"
          fprintf(ctx->out, "\"%s\"", get_str(&sess->interner, lit.value.str));
        } else {
#line 77 "src/codegen.z"
          if ((lit.kind == LiteralKind_Char)) {
#line 77 "src/codegen.z"
            generate_char(ctx, lit.value.ch);
          } else {
#line 78 "src/codegen.z"
            abort();
          };
        };
      };
    };
  };
}

#line 81 "src/codegen.z"
void generate_body(CodegenContext *ctx, Body body) {
#line 82 "src/codegen.z"
  generate_expr(ctx, body.value);
}

#line 85 "src/codegen.z"
void generate_unary(CodegenContext *ctx, UnaryData unary) {
#line 86 "src/codegen.z"
  if ((unary.op == UnaryOperatorKind_Negation)) {
#line 86 "src/codegen.z"
    fprintf(ctx->out, "-");
  } else {
#line 87 "src/codegen.z"
    if ((unary.op == UnaryOperatorKind_Complement)) {
#line 87 "src/codegen.z"
      fprintf(ctx->out, "!");
    } else {
#line 88 "src/codegen.z"
      if ((unary.op == UnaryOperatorKind_Refer)) {
#line 88 "src/codegen.z"
        fprintf(ctx->out, "&");
      } else {
#line 89 "src/codegen.z"
        if ((unary.op == UnaryOperatorKind_Deref)) {
#line 89 "src/codegen.z"
          fprintf(ctx->out, "*");
        } else {
#line 90 "src/codegen.z"
          abort();
        };
      };
    };
  };
#line 92 "src/codegen.z"
  generate_expr(ctx, unary.inner);
}

#line 95 "src/codegen.z"
void generate_binary(CodegenContext *ctx, BinaryData binary) {
#line 96 "src/codegen.z"
  fprintf(ctx->out, "(");
#line 97 "src/codegen.z"
  generate_expr(ctx, binary.left);
#line 98 "src/codegen.z"
  if ((binary.op == BinaryOperatorKind_Addition)) {
#line 98 "src/codegen.z"
    fprintf(ctx->out, "+ ");
  } else {
#line 99 "src/codegen.z"
    if ((binary.op == BinaryOperatorKind_Subtraction)) {
#line 99 "src/codegen.z"
      fprintf(ctx->out, "- ");
    } else {
#line 100 "src/codegen.z"
      if ((binary.op == BinaryOperatorKind_Product)) {
#line 100 "src/codegen.z"
        fprintf(ctx->out, "* ");
      } else {
#line 101 "src/codegen.z"
        if ((binary.op == BinaryOperatorKind_Division)) {
#line 101 "src/codegen.z"
          fprintf(ctx->out, "/ ");
        } else {
#line 102 "src/codegen.z"
          if ((binary.op == BinaryOperatorKind_Modulus)) {
#line 102 "src/codegen.z"
            fprintf(ctx->out, "%% ");
          } else {
#line 104 "src/codegen.z"
            if ((binary.op == BinaryOperatorKind_Less)) {
#line 104 "src/codegen.z"
              fprintf(ctx->out, "< ");
            } else {
#line 105 "src/codegen.z"
              if ((binary.op == BinaryOperatorKind_LessEq)) {
#line 105 "src/codegen.z"
                fprintf(ctx->out, "<= ");
              } else {
#line 106 "src/codegen.z"
                if ((binary.op == BinaryOperatorKind_Greater)) {
#line 106 "src/codegen.z"
                  fprintf(ctx->out, "> ");
                } else {
#line 107 "src/codegen.z"
                  if ((binary.op == BinaryOperatorKind_GreaterEq)) {
#line 107 "src/codegen.z"
                    fprintf(ctx->out, ">= ");
                  } else {
#line 108 "src/codegen.z"
                    if ((binary.op == BinaryOperatorKind_Equality)) {
#line 108 "src/codegen.z"
                      fprintf(ctx->out, "== ");
                    } else {
#line 109 "src/codegen.z"
                      if ((binary.op == BinaryOperatorKind_NotEq)) {
#line 109 "src/codegen.z"
                        fprintf(ctx->out, "!= ");
                      } else {
#line 111 "src/codegen.z"
                        if ((binary.op == BinaryOperatorKind_BAnd)) {
#line 111 "src/codegen.z"
                          fprintf(ctx->out, "& ");
                        } else {
#line 112 "src/codegen.z"
                          if ((binary.op == BinaryOperatorKind_BOr)) {
#line 112 "src/codegen.z"
                            fprintf(ctx->out, "| ");
                          } else {
#line 113 "src/codegen.z"
                            if ((binary.op == BinaryOperatorKind_Xor)) {
#line 113 "src/codegen.z"
                              fprintf(ctx->out, "^ ");
                            } else {
#line 114 "src/codegen.z"
                              if ((binary.op == BinaryOperatorKind_LeftShift)) {
#line 114 "src/codegen.z"
                                fprintf(ctx->out, "<< ");
                              } else {
#line 115 "src/codegen.z"
                                if ((binary.op ==
                                     BinaryOperatorKind_RightShift)) {
#line 115 "src/codegen.z"
                                  fprintf(ctx->out, ">> ");
                                } else {
#line 117 "src/codegen.z"
                                  if ((binary.op == BinaryOperatorKind_And)) {
#line 117 "src/codegen.z"
                                    fprintf(ctx->out, "&& ");
                                  } else {
#line 118 "src/codegen.z"
                                    if ((binary.op == BinaryOperatorKind_Or)) {
#line 118 "src/codegen.z"
                                      fprintf(ctx->out, "|| ");
                                    } else {
#line 119 "src/codegen.z"
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
                  };
                };
              };
            };
          };
        };
      };
    };
  };
#line 120 "src/codegen.z"
  generate_expr(ctx, binary.right);
#line 121 "src/codegen.z"
  fprintf(ctx->out, ")");
}

#line 124 "src/codegen.z"
void generate_call(CodegenContext *ctx, CallData call) {
#line 125 "src/codegen.z"
  generate_expr(ctx, call.func);
#line 127 "src/codegen.z"
  fprintf(ctx->out, "(");
#line 128 "src/codegen.z"
#line 128 "src/codegen.z"
  u32 i = 0;

#line 129 "src/codegen.z"
  while ((i < call.num_args)) {
#line 130 "src/codegen.z"
#line 130 "src/codegen.z"
    Expr *arg = call.args[i];

#line 131 "src/codegen.z"
    generate_expr(ctx, arg);
#line 132 "src/codegen.z"
    if ((i < (call.num_args - 1))) {
#line 132 "src/codegen.z"
      fprintf(ctx->out, ",");
    };
#line 133 "src/codegen.z"
    i = (i + 1);
  };
#line 135 "src/codegen.z"
  fprintf(ctx->out, ") ");
}

#line 138 "src/codegen.z"
void generate_conditional(CodegenContext *ctx, ConditionalData cond) {
#line 139 "src/codegen.z"
  fprintf(ctx->out, "if (");
#line 140 "src/codegen.z"
  generate_expr(ctx, cond.condition);
#line 141 "src/codegen.z"
  fprintf(ctx->out, ")");
#line 142 "src/codegen.z"
  generate_expr(ctx, cond.then);
#line 143 "src/codegen.z"
  if (cond.otherwise) {
#line 144 "src/codegen.z"
    fprintf(ctx->out, "else ");
#line 145 "src/codegen.z"
    generate_expr(ctx, cond.otherwise);
  };
}

#line 149 "src/codegen.z"
void generate_while(CodegenContext *ctx, WhileData data) {
#line 150 "src/codegen.z"
  fprintf(ctx->out, "while ( ");
#line 151 "src/codegen.z"
  generate_expr(ctx, data.condition);
#line 152 "src/codegen.z"
  fprintf(ctx->out, ")\n");
#line 153 "src/codegen.z"
  generate_expr(ctx, data.body);
}

#line 156 "src/codegen.z"
void generate_indexing(CodegenContext *ctx, IndexingData idx) {
#line 157 "src/codegen.z"
  generate_expr(ctx, idx.array);
#line 158 "src/codegen.z"
  fprintf(ctx->out, "[");
#line 159 "src/codegen.z"
  generate_expr(ctx, idx.index);
#line 160 "src/codegen.z"
  fprintf(ctx->out, "]");
}

#line 163 "src/codegen.z"
void generate_field(CodegenContext *ctx, FieldData field) {
#line 164 "src/codegen.z"
#line 164 "src/codegen.z"
  Expr *strct = field.strct;

#line 165 "src/codegen.z"
  generate_expr(ctx, strct);
#line 167 "src/codegen.z"
#line 167 "src/codegen.z"
  Session *sess = ctx->sess;

#line 168 "src/codegen.z"
#line 168 "src/codegen.z"
  char *field_name = get_str(&sess->interner, field.ident.name);

#line 170 "src/codegen.z"
#line 170 "src/codegen.z"
  bool is_ptr = false;

#line 171 "src/codegen.z"
#line 171 "src/codegen.z"
  char *accessor_str;

#line 172 "src/codegen.z"
  if ((strct->kind == ExprKind_Path)) {
#line 173 "src/codegen.z"
#line 173 "src/codegen.z"
    char *strct_name =
        get_str(&sess->interner, strct->node.path.segments[0].name);

#line 174 "src/codegen.z"
    is_ptr = strmap_lookup(ctx->ident_is_ptr, strct_name);
  };
#line 177 "src/codegen.z"
  if (is_ptr) {
#line 177 "src/codegen.z"
    accessor_str = "->";
  } else {
#line 178 "src/codegen.z"
    accessor_str = ".";
  };
#line 179 "src/codegen.z"
  fprintf(ctx->out, "%s%s", accessor_str, field_name);
}

#line 182 "src/codegen.z"
void generate_path(CodegenContext *ctx, Path path) {
#line 183 "src/codegen.z"
#line 183 "src/codegen.z"
  u32 i = 0;

#line 184 "src/codegen.z"
  while ((i < path.num_segments)) {
#line 185 "src/codegen.z"
    generate_identifier(ctx, path.segments[i]);
#line 186 "src/codegen.z"
    if ((i < (path.num_segments - 1))) {
#line 186 "src/codegen.z"
      fprintf(ctx->out, "_");
    };
#line 187 "src/codegen.z"
    i = (i + 1);
  };
}

#line 191 "src/codegen.z"
void generate_expr(CodegenContext *ctx, Expr *expr) {
#line 192 "src/codegen.z"
  if ((expr->kind == ExprKind_Unary)) {
#line 192 "src/codegen.z"
    generate_unary(ctx, expr->node.unary);
  } else {
#line 193 "src/codegen.z"
    if ((expr->kind == ExprKind_Binary)) {
#line 193 "src/codegen.z"
      generate_binary(ctx, expr->node.binary);
    } else {
#line 194 "src/codegen.z"
      if ((expr->kind == ExprKind_Block)) {
#line 194 "src/codegen.z"
        generate_block(ctx, expr->node.block);
      } else {
#line 195 "src/codegen.z"
        if ((expr->kind == ExprKind_Call)) {
#line 195 "src/codegen.z"
          generate_call(ctx, expr->node.call);
        } else {
#line 196 "src/codegen.z"
          if ((expr->kind == ExprKind_Conditional)) {
#line 196 "src/codegen.z"
            generate_conditional(ctx, expr->node.conditional);
          } else {
#line 197 "src/codegen.z"
            if ((expr->kind == ExprKind_While)) {
#line 197 "src/codegen.z"
              generate_while(ctx, expr->node.whl);
            } else {
#line 198 "src/codegen.z"
              if ((expr->kind == ExprKind_Indexing)) {
#line 198 "src/codegen.z"
                generate_indexing(ctx, expr->node.indexing);
              } else {
#line 199 "src/codegen.z"
                if ((expr->kind == ExprKind_Field)) {
#line 199 "src/codegen.z"
                  generate_field(ctx, expr->node.field);
                } else {
#line 200 "src/codegen.z"
                  if ((expr->kind == ExprKind_Literal)) {
#line 200 "src/codegen.z"
                    generate_literal(ctx, expr->node.lit);
                  } else {
#line 201 "src/codegen.z"
                    if ((expr->kind == ExprKind_Path)) {
#line 201 "src/codegen.z"
                      generate_path(ctx, expr->node.path);
                    } else {
#line 202 "src/codegen.z"
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
  };
}

#line 205 "src/codegen.z"
void generate_assignment(CodegenContext *ctx, AssignmentData assignment) {
#line 206 "src/codegen.z"
  generate_expr(ctx, assignment.left);
#line 207 "src/codegen.z"
  fprintf(ctx->out, " = ");
#line 208 "src/codegen.z"
  generate_expr(ctx, assignment.right);
#line 209 "src/codegen.z"
  fprintf(ctx->out, ";\n");
}

#line 212 "src/codegen.z"
void generate_return(CodegenContext *ctx, Expr *expr) {
#line 213 "src/codegen.z"
  fprintf(ctx->out, "return ");
#line 214 "src/codegen.z"
  generate_expr(ctx, expr);
#line 215 "src/codegen.z"
  fprintf(ctx->out, ";\n");
}

#line 218 "src/codegen.z"
void generate_stmt(CodegenContext *ctx, Stmt *stmt) {
#line 219 "src/codegen.z"
  emit_line_directive(ctx->out, ctx->source, stmt->span);
#line 220 "src/codegen.z"
  if ((stmt->kind == StmtKind_Assignment)) {
#line 220 "src/codegen.z"
    generate_assignment(ctx, stmt->node.assignment);
  } else {
#line 221 "src/codegen.z"
    if ((stmt->kind == StmtKind_Break)) {
#line 221 "src/codegen.z"
      fprintf(ctx->out, "break;\n");
    } else {
#line 222 "src/codegen.z"
      if ((stmt->kind == StmtKind_Continue)) {
#line 222 "src/codegen.z"
        fprintf(ctx->out, "continue;\n");
      } else {
#line 223 "src/codegen.z"
        if ((stmt->kind == StmtKind_Expr)) {
#line 223 "src/codegen.z"
          generate_expr(ctx, stmt->node.expr);
#line 223 "src/codegen.z"
          fprintf(ctx->out, ";\n");
        } else {
#line 224 "src/codegen.z"
          if ((stmt->kind == StmtKind_Item)) {
#line 224 "src/codegen.z"
            generate_item(ctx, unit_get_item(ctx->unit, stmt->node.item));
          } else {
#line 225 "src/codegen.z"
            if ((stmt->kind == StmtKind_Return)) {
#line 225 "src/codegen.z"
              generate_return(ctx, stmt->node._return);
            } else {
#line 226 "src/codegen.z"
              abort();
            };
          };
        };
      };
    };
  };
}

#line 229 "src/codegen.z"
void generate_block(CodegenContext *ctx, Block *block) {
#line 230 "src/codegen.z"
  fprintf(ctx->out, "{\n");
#line 231 "src/codegen.z"
#line 231 "src/codegen.z"
  u32 i = 0;

#line 233 "src/codegen.z"
  while ((i < block->num_stmts)) {
#line 234 "src/codegen.z"
    generate_stmt(ctx, block->stmts[i]);
#line 235 "src/codegen.z"
    i = (i + 1);
  };
#line 237 "src/codegen.z"
  fprintf(ctx->out, "}\n");
}

#line 240 "src/codegen.z"
void generate_variable(CodegenContext *ctx, Item *item) {
#line 242 "src/codegen.z"
  emit_line_directive(ctx->out, ctx->source, item->span);
#line 244 "src/codegen.z"
  generate_type(ctx, item->node.variable.ty);
#line 246 "src/codegen.z"
#line 246 "src/codegen.z"
  Session *sess = ctx->sess;

#line 247 "src/codegen.z"
#line 247 "src/codegen.z"
  char *var_name = get_str(&sess->interner, item->ident.name);

#line 249 "src/codegen.z"
  strmap_insert(ctx->ident_is_ptr, var_name,
                type_is_ptr(item->node.variable.ty));
#line 250 "src/codegen.z"
  fprintf(ctx->out, " %s ", var_name);
#line 251 "src/codegen.z"
  if (item->node.variable.body.local) {
#line 252 "src/codegen.z"
    fprintf(ctx->out, "= ");
#line 253 "src/codegen.z"
    generate_body(ctx, unit_get_body(ctx->unit, item->node.variable.body));
  };
#line 255 "src/codegen.z"
  fprintf(ctx->out, ";\n");
}

#line 258 "src/codegen.z"
void generate_function(CodegenContext *ctx, Item *item) {
#line 260 "src/codegen.z"
  emit_line_directive(ctx->out, ctx->source, item->span);
#line 262 "src/codegen.z"
#line 262 "src/codegen.z"
  FunctionData func = item->node.function;

#line 263 "src/codegen.z"
#line 263 "src/codegen.z"
  FunctionHeader header = func.header;

#line 264 "src/codegen.z"
  generate_type(ctx, header.output);
#line 266 "src/codegen.z"
#line 266 "src/codegen.z"
  Session *sess = ctx->sess;

#line 267 "src/codegen.z"
#line 267 "src/codegen.z"
  char *func_name = get_str(&sess->interner, item->ident.name);

#line 269 "src/codegen.z"
  fprintf(ctx->out, " %s(", func_name);
#line 271 "src/codegen.z"
#line 271 "src/codegen.z"
  u32 i = 0;

#line 272 "src/codegen.z"
  while ((i < header.num_parameters)) {
#line 273 "src/codegen.z"
    generate_type(ctx, header.parameters[i].ty);
#line 275 "src/codegen.z"
#line 275 "src/codegen.z"
    char *param_name =
        get_str(&sess->interner, header.parameters[i].ident.name);

#line 276 "src/codegen.z"
    strmap_insert(ctx->ident_is_ptr, param_name,
                  type_is_ptr(header.parameters[i].ty));
#line 277 "src/codegen.z"
    fprintf(ctx->out, " %s", param_name);
#line 278 "src/codegen.z"
    if ((i < (header.num_parameters - 1))) {
#line 278 "src/codegen.z"
      fprintf(ctx->out, ", ");
    };
#line 279 "src/codegen.z"
    i = (i + 1);
  };
#line 281 "src/codegen.z"
  fprintf(ctx->out, ") ");
#line 282 "src/codegen.z"
  if (func.body.local) {
#line 282 "src/codegen.z"
    generate_body(ctx, unit_get_body(ctx->unit, func.body));
  } else {
#line 283 "src/codegen.z"
    fprintf(ctx->out, ";\n");
  };
}

#line 286 "src/codegen.z"
void generate_enum(CodegenContext *ctx, Item *item) {
#line 288 "src/codegen.z"
#line 288 "src/codegen.z"
  Session *sess = ctx->sess;

#line 289 "src/codegen.z"
#line 289 "src/codegen.z"
  char *enum_name = get_str(&sess->interner, item->ident.name);

#line 291 "src/codegen.z"
  emit_line_directive(ctx->out, ctx->source, item->span);
#line 292 "src/codegen.z"
  fprintf(ctx->out, "typedef enum %s {\n", enum_name);
#line 293 "src/codegen.z"
#line 293 "src/codegen.z"
  u32 i = 0;

#line 295 "src/codegen.z"
#line 295 "src/codegen.z"
  EnumData data = item->node._enum;

#line 297 "src/codegen.z"
  while ((i < data.num_variants)) {
#line 298 "src/codegen.z"
#line 298 "src/codegen.z"
    char *variant_name = get_str(&sess->interner, data.variants[i].ident.name);

#line 299 "src/codegen.z"
    fprintf(ctx->out, "%s_%s,\n", enum_name, variant_name);
#line 300 "src/codegen.z"
    i = (i + 1);
  };
#line 302 "src/codegen.z"
  fprintf(ctx->out, "} %s;\n\n", enum_name);
}

#line 305 "src/codegen.z"
void generate_compound(CodegenContext *ctx, Item *item) {
#line 307 "src/codegen.z"
#line 307 "src/codegen.z"
  Session *sess = ctx->sess;

#line 308 "src/codegen.z"
#line 308 "src/codegen.z"
  char *compound_name = get_str(&sess->interner, item->ident.name);

#line 310 "src/codegen.z"
#line 310 "src/codegen.z"
  char *compound_kind;

#line 311 "src/codegen.z"
  if ((item->kind == ItemKind_Struct)) {
#line 311 "src/codegen.z"
    compound_kind = "struct";
  } else {
#line 312 "src/codegen.z"
    compound_kind = "union";
  };
#line 314 "src/codegen.z"
#line 314 "src/codegen.z"
  CompoundData data = item->node.compound;

#line 316 "src/codegen.z"
  fprintf(ctx->out, "typedef %s %s %s;\n", compound_kind, compound_name,
          compound_name);
#line 318 "src/codegen.z"
  emit_line_directive(ctx->out, ctx->source, item->span);
#line 319 "src/codegen.z"
  if ((data.num_fields > 0)) {
#line 320 "src/codegen.z"
    fprintf(ctx->out, "typedef %s %s {\n", compound_kind, compound_name);
#line 321 "src/codegen.z"
#line 321 "src/codegen.z"
    u32 i = 0;

#line 322 "src/codegen.z"
    while ((i < data.num_fields)) {
#line 323 "src/codegen.z"
      generate_type(ctx, data.fields[i].ty);
#line 325 "src/codegen.z"
#line 325 "src/codegen.z"
      char *field_name = get_str(&sess->interner, data.fields[i].ident.name);

#line 326 "src/codegen.z"
      fprintf(ctx->out, " %s;\n", field_name);
#line 327 "src/codegen.z"
      i = (i + 1);
    };
#line 329 "src/codegen.z"
    fprintf(ctx->out, "} %s;\n\n", compound_name);
  };
}

#line 333 "src/codegen.z"
void generate_mod(CodegenContext *ctx, Mod *module) {
#line 334 "src/codegen.z"
#line 334 "src/codegen.z"
  u32 i = 0;

#line 335 "src/codegen.z"
  while ((i < module->num_items)) {
#line 336 "src/codegen.z"
#line 336 "src/codegen.z"
    Item *item = unit_get_item(ctx->unit, module->items[i]);

#line 337 "src/codegen.z"
    generate_item(ctx, item);
#line 338 "src/codegen.z"
    i = (i + 1);
  };
}

#line 342 "src/codegen.z"
void generate_item(CodegenContext *ctx, Item *item) {
#line 344 "src/codegen.z"
  if (((item->kind == ItemKind_Const) || (item->kind == ItemKind_Variable))) {
#line 344 "src/codegen.z"
    generate_variable(ctx, item);
  } else {
#line 345 "src/codegen.z"
    if ((item->kind == ItemKind_Enum)) {
#line 345 "src/codegen.z"
      generate_enum(ctx, item);
    } else {
#line 346 "src/codegen.z"
      if ((item->kind == ItemKind_Function)) {
#line 346 "src/codegen.z"
        generate_function(ctx, item);
      } else {
#line 347 "src/codegen.z"
        if (((item->kind == ItemKind_Struct) ||
             (item->kind == ItemKind_Union))) {
#line 347 "src/codegen.z"
          generate_compound(ctx, item);
        } else {
#line 348 "src/codegen.z"
          if ((item->kind == ItemKind_Mod)) {
#line 348 "src/codegen.z"
            generate_mod(ctx, &item->node.module);
          };
        };
      };
    };
  };
#line 349 "src/codegen.z"
  fprintf(ctx->out, "\n");
}

#line 352 "src/codegen.z"
void generate(Session *sess, CompilationUnit unit, char *output_file) {
#line 353 "src/codegen.z"
#line 353 "src/codegen.z"
  CodegenContext ctx;

#line 355 "src/codegen.z"
  ctx.out = fopen(output_file, "w");
#line 356 "src/codegen.z"
  ctx.ident_is_ptr = strmap_create(1024);
#line 357 "src/codegen.z"
  ctx.sess = sess;
#line 358 "src/codegen.z"
  ctx.source = &sess->source;
#line 359 "src/codegen.z"
  ctx.unit = &unit;
#line 361 "src/codegen.z"
  generate_prelude(&ctx);
#line 363 "src/codegen.z"
  generate_mod(&ctx, &unit.module);
}
