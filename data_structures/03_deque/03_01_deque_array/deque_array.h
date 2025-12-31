#ifndef DEQUE_ARRAY_H
#define DEQUE_ARRAY_H

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
int deque_array_is_empty(const DequeArray *deque);
int deque_array_is_full(const DequeArray *deque);
int deque_array_push_front(DequeArray *deque, deque_array_value_t value);
int deque_array_push_back(DequeArray *deque, deque_array_value_t value);
int deque_array_pop_front(DequeArray *deque, deque_array_value_t *out_value);
int deque_array_pop_back(DequeArray *deque, deque_array_value_t *out_value);
int deque_array_front(const DequeArray *deque, deque_array_value_t *out_value);
int deque_array_back(const DequeArray *deque, deque_array_value_t *out_value);
void deque_array_clear(DequeArray *deque);

#endif
