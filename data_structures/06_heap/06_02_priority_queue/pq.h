#ifndef PQ_H
#define PQ_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
 * - out_value must be non-NULL; it is unchanged on failure.
 * - push may grow capacity; return false on allocation failure.
 * - This priority queue is a min-heap.
 */

typedef int pq_value_t;

typedef struct {
  pq_value_t *data;
  size_t size;
  size_t capacity;
} PriorityQueue;

bool pq_init(PriorityQueue *pq, size_t capacity);
void pq_destroy(PriorityQueue *pq);

size_t pq_size(const PriorityQueue *pq);
size_t pq_capacity(const PriorityQueue *pq);
bool pq_is_empty(const PriorityQueue *pq);

bool pq_peek(const PriorityQueue *pq, pq_value_t *out_value);
bool pq_push(PriorityQueue *pq, pq_value_t value);
bool pq_pop(PriorityQueue *pq, pq_value_t *out_value);
bool pq_reserve(PriorityQueue *pq, size_t new_capacity);
void pq_clear(PriorityQueue *pq);

#endif
