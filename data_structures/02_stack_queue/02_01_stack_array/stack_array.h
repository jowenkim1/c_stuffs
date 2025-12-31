#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

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

#define STACK_ARRAY_CAPACITY 128

typedef int stack_array_value_t;

typedef struct {
  stack_array_value_t data[STACK_ARRAY_CAPACITY];
  size_t size;
} StackArray;

void stack_array_init(StackArray *stack);
size_t stack_array_size(const StackArray *stack);
size_t stack_array_capacity(const StackArray *stack);
int stack_array_is_empty(const StackArray *stack);
int stack_array_is_full(const StackArray *stack);
int stack_array_push(StackArray *stack, stack_array_value_t value);
int stack_array_pop(StackArray *stack, stack_array_value_t *out_value);
int stack_array_peek(const StackArray *stack, stack_array_value_t *out_value);
void stack_array_clear(StackArray *stack);

#endif
