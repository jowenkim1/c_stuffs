#ifndef PQ_H
#define PQ_H

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
 * - push may grow capacity; return DS_ERR_NOMEM on allocation failure.
 * - This priority queue is a min-heap.
 */

typedef int pq_value_t;

typedef struct {
  pq_value_t *data;
  size_t size;
  size_t capacity;
} PriorityQueue;

int pq_init(PriorityQueue *pq, size_t capacity);
void pq_destroy(PriorityQueue *pq);

size_t pq_size(const PriorityQueue *pq);
size_t pq_capacity(const PriorityQueue *pq);
int pq_is_empty(const PriorityQueue *pq);

int pq_peek(const PriorityQueue *pq, pq_value_t *out_value);
int pq_push(PriorityQueue *pq, pq_value_t value);
int pq_pop(PriorityQueue *pq, pq_value_t *out_value);
int pq_reserve(PriorityQueue *pq, size_t new_capacity);
void pq_clear(PriorityQueue *pq);

#endif
