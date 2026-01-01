#ifndef DEQUE_LL_H
#define DEQUE_LL_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
 * - out_value must be non-NULL; it is unchanged on failure.
 */

typedef int deque_ll_value_t;

typedef struct DequeLLNode {
  deque_ll_value_t value;
  struct DequeLLNode *prev;
  struct DequeLLNode *next;
} DequeLLNode;

typedef struct {
  DequeLLNode *front;
  DequeLLNode *back;
  size_t size;
} DequeLL;

void deque_ll_init(DequeLL *deque);
void deque_ll_destroy(DequeLL *deque);
size_t deque_ll_size(const DequeLL *deque);
bool deque_ll_is_empty(const DequeLL *deque);
bool deque_ll_push_front(DequeLL *deque, deque_ll_value_t value);
bool deque_ll_push_back(DequeLL *deque, deque_ll_value_t value);
bool deque_ll_pop_front(DequeLL *deque, deque_ll_value_t *out_value);
bool deque_ll_pop_back(DequeLL *deque, deque_ll_value_t *out_value);
bool deque_ll_front(const DequeLL *deque, deque_ll_value_t *out_value);
bool deque_ll_back(const DequeLL *deque, deque_ll_value_t *out_value);
void deque_ll_clear(DequeLL *deque);

#endif
