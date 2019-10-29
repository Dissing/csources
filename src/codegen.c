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
typedef struct CodegenContext {
  FILE *out;
  StrMap *ident_is_ptr;
} CodegenContext;

void generate_expr(CodegenContext *ctx, Expr *expr);

void generate_block(CodegenContext *ctx, Block *block);

void generate_stmt(CodegenContext *ctx, Stmt *stmt);

void generate_item(CodegenContext *ctx, Item *item);

bool type_is_ptr(Type *ty) { return (ty->kind == _TypeKind_Ptr); }

void generate_prelude(CodegenContext *ctx) {
  fprintf(ctx->out, "//Prelude\n");
  fprintf(ctx->out, "#include <stdint.h>\n");
  fprintf(ctx->out, "#include <stdbool.h>\n");
  fprintf(ctx->out, "#include <stdio.h>\n");
  fprintf(ctx->out, "#include <stdlib.h>\n");
  fprintf(ctx->out, "#include <string.h>\n");
  fprintf(ctx->out, "typedef uint8_t u8;\n");
  fprintf(ctx->out, "typedef uint16_t u16;\n");
  fprintf(ctx->out, "typedef uint32_t u32;\n");
  fprintf(ctx->out, "typedef uint64_t u64;\n");
  fprintf(ctx->out, "typedef int8_t i8;\n");
  fprintf(ctx->out, "typedef int16_t i16;\n");
  fprintf(ctx->out, "typedef int32_t i32;\n");
  fprintf(ctx->out, "typedef int64_t i64;\n");
  fprintf(ctx->out, "typedef float f32;\n");
  fprintf(ctx->out, "typedef double f64;\n");
  fprintf(ctx->out, "#define null 0ul\n");
}

void generate_type(CodegenContext *ctx, Type *ty) {
  if ((ty->kind == _TypeKind_Path)) {
    fprintf(ctx->out, "%s ", ty->node.path);
  } else {
    if ((ty->kind == _TypeKind_Ptr)) {
      generate_type(ctx, ty->node.ptr);
      fprintf(ctx->out, "* ");
    } else {
      if ((ty->kind == _TypeKind_Unit)) {
        fprintf(ctx->out, "void ");
      } else {
        abort();
      };
    };
  };
}

void generate_char(CodegenContext *ctx, char c) {
  if ((c == '\n')) {
    fprintf(ctx->out, "'\\n'");
  } else {
    if ((c == '\t')) {
      fprintf(ctx->out, "'\\t'");
    } else {
      if ((c == '\r')) {
        fprintf(ctx->out, "'\\r'");
      } else {
        if ((c == '\\')) {
          fprintf(ctx->out, "'\\\\'");
        } else {
          if ((c == '\'')) {
            fprintf(ctx->out, "'\\''");
          } else {
            fprintf(ctx->out, "'%c'", c);
          };
        };
      };
    };
  };
}

void generate_literal(CodegenContext *ctx, Literal lit) {
  if ((lit.kind == _LiteralKind_Int)) {
    fprintf(ctx->out, "%ld", lit.value.integer);
  } else {
    if ((lit.kind == _LiteralKind_Float)) {
      fprintf(ctx->out, "%f", lit.value.floating);
    } else {
      if ((lit.kind == _LiteralKind_Bool)) {
        if (lit.value.boolean) {
          fprintf(ctx->out, "true");
        } else {
          fprintf(ctx->out, "false");
        };
      } else {
        if ((lit.kind == _LiteralKind_Str)) {
          fprintf(ctx->out, "\"%s\"", lit.value.str);
        } else {
          if ((lit.kind == _LiteralKind_Char)) {
            generate_char(ctx, lit.value.ch);
          } else {
            abort();
          };
        };
      };
    };
  };
}

void generate_unary(CodegenContext *ctx, UnaryData unary) {
  if ((unary.op == _UnaryOperatorKind_Negation)) {
    fprintf(ctx->out, "-");
  } else {
    if ((unary.op == _UnaryOperatorKind_Complement)) {
      fprintf(ctx->out, "!");
    } else {
      if ((unary.op == _UnaryOperatorKind_Refer)) {
        fprintf(ctx->out, "&");
      } else {
        if ((unary.op == _UnaryOperatorKind_Deref)) {
          fprintf(ctx->out, "*");
        } else {
          abort();
        };
      };
    };
  };
  generate_expr(ctx, unary.inner);
}

void generate_binary(CodegenContext *ctx, BinaryData binary) {
  fprintf(ctx->out, "(");
  generate_expr(ctx, binary.left);
  if ((binary.op == _BinaryOperatorKind_Addition)) {
    fprintf(ctx->out, "+ ");
  } else {
    if ((binary.op == _BinaryOperatorKind_Subtraction)) {
      fprintf(ctx->out, "- ");
    } else {
      if ((binary.op == _BinaryOperatorKind_Product)) {
        fprintf(ctx->out, "* ");
      } else {
        if ((binary.op == _BinaryOperatorKind_Division)) {
          fprintf(ctx->out, "/ ");
        } else {
          if ((binary.op == _BinaryOperatorKind_Modulus)) {
            fprintf(ctx->out, "%% ");
          } else {
            if ((binary.op == _BinaryOperatorKind_Less)) {
              fprintf(ctx->out, "< ");
            } else {
              if ((binary.op == _BinaryOperatorKind_LessEq)) {
                fprintf(ctx->out, "<= ");
              } else {
                if ((binary.op == _BinaryOperatorKind_Greater)) {
                  fprintf(ctx->out, "> ");
                } else {
                  if ((binary.op == _BinaryOperatorKind_GreaterEq)) {
                    fprintf(ctx->out, ">= ");
                  } else {
                    if ((binary.op == _BinaryOperatorKind_Equality)) {
                      fprintf(ctx->out, "== ");
                    } else {
                      if ((binary.op == _BinaryOperatorKind_NotEq)) {
                        fprintf(ctx->out, "!= ");
                      } else {
                        if ((binary.op == _BinaryOperatorKind_BAnd)) {
                          fprintf(ctx->out, "& ");
                        } else {
                          if ((binary.op == _BinaryOperatorKind_BOr)) {
                            fprintf(ctx->out, "| ");
                          } else {
                            if ((binary.op == _BinaryOperatorKind_Xor)) {
                              fprintf(ctx->out, "^ ");
                            } else {
                              if ((binary.op ==
                                   _BinaryOperatorKind_LeftShift)) {
                                fprintf(ctx->out, "<< ");
                              } else {
                                if ((binary.op ==
                                     _BinaryOperatorKind_RightShift)) {
                                  fprintf(ctx->out, ">> ");
                                } else {
                                  if ((binary.op == _BinaryOperatorKind_And)) {
                                    fprintf(ctx->out, "&& ");
                                  } else {
                                    if ((binary.op == _BinaryOperatorKind_Or)) {
                                      fprintf(ctx->out, "|| ");
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
                  };
                };
              };
            };
          };
        };
      };
    };
  };
  generate_expr(ctx, binary.right);
  fprintf(ctx->out, ")");
}

void generate_call(CodegenContext *ctx, CallData call) {
  generate_expr(ctx, call.func);
  fprintf(ctx->out, "(");
  u32 i = 0;

  while ((i < call.num_args)) {
    Expr *arg = call.args[i];

    generate_expr(ctx, arg);
    if ((i < (call.num_args - 1))) {
      fprintf(ctx->out, ",");
    };
    i = (i + 1);
  }
  fprintf(ctx->out, ") ");
}

void generate_conditional(CodegenContext *ctx, ConditionalData cond) {
  fprintf(ctx->out, "if (");
  generate_expr(ctx, cond.condition);
  fprintf(ctx->out, ")");
  generate_block(ctx, cond.then);
  if (cond.otherwise) {
    fprintf(ctx->out, "else ");
    generate_block(ctx, cond.otherwise);
  };
}

void generate_indexing(CodegenContext *ctx, IndexingData idx) {
  generate_expr(ctx, idx.array);
  fprintf(ctx->out, "[");
  generate_expr(ctx, idx.index);
  fprintf(ctx->out, "]");
}

void generate_field(CodegenContext *ctx, FieldData field) {
  Expr *strct = field.strct;

  generate_expr(ctx, strct);
  bool is_ptr = strmap_lookup(ctx->ident_is_ptr, strct->node.ident.name);

  char *accessor_str;

  if (is_ptr) {
    accessor_str = "->";
  } else {
    accessor_str = ".";
  };
  fprintf(ctx->out, "%s%s", accessor_str, field.ident.name);
}

void generate_path(CodegenContext *ctx, Path path) {
  fprintf(ctx->out, "_");
  u32 i = 0;

  while ((i < path.num_segments)) {
    fprintf(ctx->out, "%s", path.segments[i]);
    if ((i < (path.num_segments - 1))) {
      fprintf(ctx->out, "_");
    };
    i = (i + 1);
  }
}

void generate_expr(CodegenContext *ctx, Expr *expr) {
  if ((expr->kind == _ExprKind_Unary)) {
    generate_unary(ctx, expr->node.unary);
  } else {
    if ((expr->kind == _ExprKind_Binary)) {
      generate_binary(ctx, expr->node.binary);
    } else {
      if ((expr->kind == _ExprKind_Block)) {
        generate_block(ctx, expr->node.block);
      } else {
        if ((expr->kind == _ExprKind_Call)) {
          generate_call(ctx, expr->node.call);
        } else {
          if ((expr->kind == _ExprKind_Conditional)) {
            generate_conditional(ctx, expr->node.conditional);
          } else {
            if ((expr->kind == _ExprKind_Indexing)) {
              generate_indexing(ctx, expr->node.indexing);
            } else {
              if ((expr->kind == _ExprKind_Field)) {
                generate_field(ctx, expr->node.field);
              } else {
                if ((expr->kind == _ExprKind_Literal)) {
                  generate_literal(ctx, expr->node.lit);
                } else {
                  if ((expr->kind == _ExprKind_Identifier)) {
                    fprintf(ctx->out, "%s", expr->node.ident.name);
                  } else {
                    if ((expr->kind == _ExprKind_Path)) {
                      generate_path(ctx, expr->node.path);
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
  };
}

void generate_assignment(CodegenContext *ctx, AssignmentData assignment) {
  generate_expr(ctx, assignment.left);
  fprintf(ctx->out, " = ");
  generate_expr(ctx, assignment.right);
  fprintf(ctx->out, ";\n");
}

void generate_return(CodegenContext *ctx, Expr *expr) {
  fprintf(ctx->out, "return ");
  generate_expr(ctx, expr);
  fprintf(ctx->out, ";\n");
}

void generate_while(CodegenContext *ctx, WhileData *data) {
  fprintf(ctx->out, "while ( ");
  generate_expr(ctx, data->condition);
  fprintf(ctx->out, ")\n");
  generate_block(ctx, data->body);
}

void generate_stmt(CodegenContext *ctx, Stmt *stmt) {
  if ((stmt->kind == _StmtKind_Assignment)) {
    generate_assignment(ctx, stmt->node.assignment);
  } else {
    if ((stmt->kind == _StmtKind_Break)) {
      fprintf(ctx->out, "break;\n");
    } else {
      if ((stmt->kind == _StmtKind_Continue)) {
        fprintf(ctx->out, "continue;\n");
      } else {
        if ((stmt->kind == _StmtKind_Expr)) {
          generate_expr(ctx, stmt->node.expr);
          fprintf(ctx->out, ";\n");
        } else {
          if ((stmt->kind == _StmtKind_Item)) {
            generate_item(ctx, stmt->node.item);
          } else {
            if ((stmt->kind == _StmtKind_Return)) {
              generate_return(ctx, stmt->node._return);
            } else {
              if ((stmt->kind == _StmtKind_While)) {
                generate_while(ctx, &stmt->node._while);
              } else {
                abort();
              };
            };
          };
        };
      };
    };
  };
}

void generate_block(CodegenContext *ctx, Block *block) {
  fprintf(ctx->out, "{\n");
  u32 i = 0;

  while ((i < block->num_stmts)) {
    generate_stmt(ctx, block->stmts[i]);
    i = (i + 1);
  }
  fprintf(ctx->out, "}\n");
}

void generate_variable(CodegenContext *ctx, Item *item) {
  generate_type(ctx, item->node.variable.ty);
  strmap_insert(ctx->ident_is_ptr, item->ident.name,
                type_is_ptr(item->node.variable.ty));
  fprintf(ctx->out, "%s ", item->ident.name);
  if ((item->node.variable.body > 0)) {
    fprintf(ctx->out, "= ");
    generate_expr(ctx, item->node.variable.body);
  };
  fprintf(ctx->out, ";\n");
}

void generate_function(CodegenContext *ctx, Item *item) {
  FunctionData data = item->node.function;

  generate_type(ctx, data.output);
  fprintf(ctx->out, " %s(", item->ident.name);
  u32 i = 0;

  while ((i < data.num_parameters)) {
    generate_type(ctx, data.parameters[i].ty);
    strmap_insert(ctx->ident_is_ptr, data.parameters[i].name.name,
                  type_is_ptr(data.parameters[i].ty));
    fprintf(ctx->out, " %s", data.parameters[i].name.name);
    if ((i < (data.num_parameters - 1))) {
      fprintf(ctx->out, ", ");
    };
    i = (i + 1);
  }
  fprintf(ctx->out, ") ");
  if (data.body) {
    generate_block(ctx, data.body);
  } else {
    fprintf(ctx->out, ";\n");
  };
}

void generate_enum(CodegenContext *ctx, Item *item) {
  fprintf(ctx->out, "typedef enum %s {\n", item->ident.name);
  u32 i = 0;

  EnumData data = item->node._enum;

  while ((i < data.num_variants)) {
    fprintf(ctx->out, "_%s_%s,\n", item->ident.name,
            data.variants[i].ident.name);
    i = (i + 1);
  }
  fprintf(ctx->out, "} %s;\n\n", item->ident.name);
}

void generate_compound(CodegenContext *ctx, Item *item) {
  char *compound_kind;

  if ((item->kind == _ItemKind_Struct)) {
    compound_kind = "struct";
  } else {
    compound_kind = "union";
  };
  CompoundData data = item->node.compound;

  fprintf(ctx->out, "typedef %s %s %s;\n", compound_kind, item->ident.name,
          item->ident.name);
  if ((data.num_fields > 0)) {
    fprintf(ctx->out, "typedef %s %s {\n", compound_kind, item->ident.name);
    u32 i = 0;

    while ((i < data.num_fields)) {
      generate_type(ctx, data.fields[i].ty);
      fprintf(ctx->out, "%s;\n", data.fields[i].ident.name);
      i = (i + 1);
    }
    fprintf(ctx->out, "} %s;\n\n", item->ident.name);
  };
}

void generate_item(CodegenContext *ctx, Item *item) {
  if (((item->kind == _ItemKind_Const) || (item->kind == _ItemKind_Variable))) {
    generate_variable(ctx, item);
  } else {
    if ((item->kind == _ItemKind_Enum)) {
      generate_enum(ctx, item);
    } else {
      if ((item->kind == _ItemKind_Function)) {
        generate_function(ctx, item);
      } else {
        if (((item->kind == _ItemKind_Struct) ||
             (item->kind == _ItemKind_Union))) {
          generate_compound(ctx, item);
        };
      };
    };
  };
  fprintf(ctx->out, "\n");
}

void generate(Item **items, u32 num_items, char *output_file) {
  CodegenContext ctx;

  ctx.out = fopen(output_file, "w");
  ctx.ident_is_ptr = strmap_create(1024);
  generate_prelude(&ctx);
  u32 i = 0;

  while ((i < num_items)) {
    generate_item(&ctx, items[i]);
    i = (i + 1);
  }
}
