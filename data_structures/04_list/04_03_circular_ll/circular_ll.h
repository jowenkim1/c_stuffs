#ifndef CIRCULAR_LL_H
#define CIRCULAR_LL_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
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
bool circular_ll_is_empty(const CircularLL *list);
bool circular_ll_front(const CircularLL *list, circular_ll_value_t *out_value);
bool circular_ll_back(const CircularLL *list, circular_ll_value_t *out_value);
bool circular_ll_push_front(CircularLL *list, circular_ll_value_t value);
bool circular_ll_push_back(CircularLL *list, circular_ll_value_t value);
bool circular_ll_pop_front(CircularLL *list, circular_ll_value_t *out_value);
bool circular_ll_pop_back(CircularLL *list, circular_ll_value_t *out_value);
bool circular_ll_insert_at(CircularLL *list, size_t index, circular_ll_value_t value);
bool circular_ll_remove_at(CircularLL *list, size_t index, circular_ll_value_t *out_value);
bool circular_ll_get_at(const CircularLL *list, size_t index, circular_ll_value_t *out_value);
bool circular_ll_set_at(CircularLL *list, size_t index, circular_ll_value_t value);
void circular_ll_clear(CircularLL *list);

#endif
