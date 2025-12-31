#ifndef STACK_LL_H
#define STACK_LL_H

#include <stddef.h>

#ifndef DS_STATUS_H
#define DS_STATUS_H
#define DS_OK 0
#define DS_ERR_INVALID -1
#define DS_ERR_EMPTY -2
#define DS_ERR_FULL -3
#define DS_ERR_NOMEM -4
#define DS_ERR_NOT_FOUND -5
#endif

/*
 * ADT conventions:
 * - Status functions return DS_OK on success, negative DS_ERR_* on failure.
 * - Boolean queries return 1 (true), 0 (false), or DS_ERR_INVALID for bad args.
 * - out_value must be non-NULL; it is unchanged on failure.
 */

typedef int stack_ll_value_t;

typedef struct StackLLNode {
  stack_ll_value_t value;
  struct StackLLNode *next;
} StackLLNode;

typedef struct {
  StackLLNode *top;
  size_t size;
} StackLL;

void stack_ll_init(StackLL *stack);
void stack_ll_destroy(StackLL *stack);
size_t stack_ll_size(const StackLL *stack);
int stack_ll_is_empty(const StackLL *stack);
int stack_ll_push(StackLL *stack, stack_ll_value_t value);
int stack_ll_pop(StackLL *stack, stack_ll_value_t *out_value);
int stack_ll_peek(const StackLL *stack, stack_ll_value_t *out_value);
void stack_ll_clear(StackLL *stack);

#endif
