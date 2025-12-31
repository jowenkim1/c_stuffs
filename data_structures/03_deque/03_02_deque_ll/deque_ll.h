#ifndef DEQUE_LL_H
#define DEQUE_LL_H

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
int deque_ll_is_empty(const DequeLL *deque);
int deque_ll_push_front(DequeLL *deque, deque_ll_value_t value);
int deque_ll_push_back(DequeLL *deque, deque_ll_value_t value);
int deque_ll_pop_front(DequeLL *deque, deque_ll_value_t *out_value);
int deque_ll_pop_back(DequeLL *deque, deque_ll_value_t *out_value);
int deque_ll_front(const DequeLL *deque, deque_ll_value_t *out_value);
int deque_ll_back(const DequeLL *deque, deque_ll_value_t *out_value);
void deque_ll_clear(DequeLL *deque);

#endif
