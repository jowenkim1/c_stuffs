#ifndef STACK_LL_H
#define STACK_LL_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
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
bool stack_ll_is_empty(const StackLL *stack);
bool stack_ll_push(StackLL *stack, stack_ll_value_t value);
bool stack_ll_pop(StackLL *stack, stack_ll_value_t *out_value);
bool stack_ll_peek(const StackLL *stack, stack_ll_value_t *out_value);
void stack_ll_clear(StackLL *stack);

#endif
