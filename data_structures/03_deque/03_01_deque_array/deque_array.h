#ifndef DEQUE_ARRAY_H
#define DEQUE_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
 * - out_value must be non-NULL; it is unchanged on failure.
 */

#define DEQUE_ARRAY_CAPACITY 128

typedef int deque_array_value_t;

typedef struct {
  deque_array_value_t data[DEQUE_ARRAY_CAPACITY];
  size_t head;
  size_t tail;
  size_t size;
} DequeArray;

void deque_array_init(DequeArray *deque);
size_t deque_array_size(const DequeArray *deque);
size_t deque_array_capacity(const DequeArray *deque);
bool deque_array_is_empty(const DequeArray *deque);
bool deque_array_is_full(const DequeArray *deque);
bool deque_array_push_front(DequeArray *deque, deque_array_value_t value);
bool deque_array_push_back(DequeArray *deque, deque_array_value_t value);
bool deque_array_pop_front(DequeArray *deque, deque_array_value_t *out_value);
bool deque_array_pop_back(DequeArray *deque, deque_array_value_t *out_value);
bool deque_array_front(const DequeArray *deque, deque_array_value_t *out_value);
bool deque_array_back(const DequeArray *deque, deque_array_value_t *out_value);
void deque_array_clear(DequeArray *deque);

#endif
