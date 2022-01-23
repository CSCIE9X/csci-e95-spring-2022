#ifndef _TYPE_H
#define _TYPE_H

#include <stdio.h>
#include <stdbool.h>

struct node;

enum type_kind {
  TYPE_BASIC,
  TYPE_VOID,
  TYPE_POINTER,
  TYPE_ARRAY,
  TYPE_FUNCTION,
  TYPE_LABEL
};

enum type_basic_kind {
  TYPE_BASIC_CHAR,
  TYPE_BASIC_SHORT,
  TYPE_BASIC_INT,
  TYPE_BASIC_LONG
};
struct type {
  enum type_kind kind;
  union {
    struct {
      bool is_unsigned;
      enum type_basic_kind datatype;
    } basic;
  } data;
};

struct type *type_basic(bool is_unsigned, enum type_basic_kind datatype);


void type_print(FILE *output, struct type *type);

struct type_context {
    int error_count;
};
void type_ast_traversal(struct type_context *context, struct node * node);

#endif /* _TYPE_H */
