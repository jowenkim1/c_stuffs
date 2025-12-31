#ifndef CIRCULAR_LL_H
#define CIRCULAR_LL_H

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
 * - Indices are 0-based; insert allows index == size (append).
 * - out_value must be non-NULL; it is unchanged on failure.
 */

typedef int circular_ll_value_t;

typedef struct CircularLLNode {
  circular_ll_value_t value;
  struct CircularLLNode *next;
} CircularLLNode;

typedef struct {
  CircularLLNode *tail;
  size_t size;
} CircularLL;

void circular_ll_init(CircularLL *list);
void circular_ll_destroy(CircularLL *list);
size_t circular_ll_size(const CircularLL *list);
int circular_ll_is_empty(const CircularLL *list);
int circular_ll_front(const CircularLL *list, circular_ll_value_t *out_value);
int circular_ll_back(const CircularLL *list, circular_ll_value_t *out_value);
int circular_ll_push_front(CircularLL *list, circular_ll_value_t value);
int circular_ll_push_back(CircularLL *list, circular_ll_value_t value);
int circular_ll_pop_front(CircularLL *list, circular_ll_value_t *out_value);
int circular_ll_pop_back(CircularLL *list, circular_ll_value_t *out_value);
int circular_ll_insert_at(CircularLL *list, size_t index, circular_ll_value_t value);
int circular_ll_remove_at(CircularLL *list, size_t index, circular_ll_value_t *out_value);
int circular_ll_get_at(const CircularLL *list, size_t index, circular_ll_value_t *out_value);
int circular_ll_set_at(CircularLL *list, size_t index, circular_ll_value_t value);
void circular_ll_clear(CircularLL *list);

#endif
