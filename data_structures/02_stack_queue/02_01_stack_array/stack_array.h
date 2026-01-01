#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
 * - out_value must be non-NULL; it is unchanged on failure.
 */

#define STACK_ARRAY_CAPACITY 128

typedef int stack_array_value_t;

typedef struct {
  stack_array_value_t data[STACK_ARRAY_CAPACITY];
  size_t size;
} StackArray;

void stack_array_init(StackArray *stack);
size_t stack_array_size(const StackArray *stack);
size_t stack_array_capacity(const StackArray *stack);
bool stack_array_is_empty(const StackArray *stack);
bool stack_array_is_full(const StackArray *stack);
bool stack_array_push(StackArray *stack, stack_array_value_t value);
bool stack_array_pop(StackArray *stack, stack_array_value_t *out_value);
bool stack_array_peek(const StackArray *stack, stack_array_value_t *out_value);
void stack_array_clear(StackArray *stack);

#endif
