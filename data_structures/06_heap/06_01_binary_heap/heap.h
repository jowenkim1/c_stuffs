#ifndef HEAP_H
#define HEAP_H

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
 * - This heap is a min-heap.
 */

typedef int heap_value_t;

typedef struct {
  heap_value_t *data;
  size_t size;
  size_t capacity;
} BinaryHeap;

int heap_init(BinaryHeap *heap, size_t capacity);
void heap_destroy(BinaryHeap *heap);

size_t heap_size(const BinaryHeap *heap);
size_t heap_capacity(const BinaryHeap *heap);
int heap_is_empty(const BinaryHeap *heap);

int heap_peek(const BinaryHeap *heap, heap_value_t *out_value);
int heap_push(BinaryHeap *heap, heap_value_t value);
int heap_pop(BinaryHeap *heap, heap_value_t *out_value);
int heap_reserve(BinaryHeap *heap, size_t new_capacity);
void heap_clear(BinaryHeap *heap);

#endif
