#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
 * - out_value must be non-NULL; it is unchanged on failure.
 * - push may grow capacity; return false on allocation failure.
 * - This heap is a min-heap.
 */

typedef int heap_value_t;

typedef struct {
  heap_value_t *data;
  size_t size;
  size_t capacity;
} BinaryHeap;

bool heap_init(BinaryHeap *heap, size_t capacity);
void heap_destroy(BinaryHeap *heap);

size_t heap_size(const BinaryHeap *heap);
size_t heap_capacity(const BinaryHeap *heap);
bool heap_is_empty(const BinaryHeap *heap);

bool heap_peek(const BinaryHeap *heap, heap_value_t *out_value);
bool heap_push(BinaryHeap *heap, heap_value_t value);
bool heap_pop(BinaryHeap *heap, heap_value_t *out_value);
bool heap_reserve(BinaryHeap *heap, size_t new_capacity);
void heap_clear(BinaryHeap *heap);

#endif
