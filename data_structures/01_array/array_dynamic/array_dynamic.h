#ifndef ARRAY_DYNAMIC_H
#define ARRAY_DYNAMIC_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
 * - Indices are 0-based; insert allows index == size (append).
 * - out_value must be non-NULL; it is unchanged on failure.
 * - push/insert may grow capacity; return false on allocation failure.
 */

#define ARRAY_DYNAMIC_DEFAULT_CAPACITY 8

typedef int array_dynamic_value_t;

typedef struct {
  array_dynamic_value_t *data;
  size_t size;
  size_t capacity;
} ArrayDynamic;

bool array_dynamic_init(ArrayDynamic *arr, size_t capacity);
void array_dynamic_destroy(ArrayDynamic *arr);
size_t array_dynamic_size(const ArrayDynamic *arr);
size_t array_dynamic_capacity(const ArrayDynamic *arr);
bool array_dynamic_is_empty(const ArrayDynamic *arr);
bool array_dynamic_get(const ArrayDynamic *arr, size_t index, array_dynamic_value_t *out_value);
bool array_dynamic_set(ArrayDynamic *arr, size_t index, array_dynamic_value_t value);
bool array_dynamic_front(const ArrayDynamic *arr, array_dynamic_value_t *out_value);
bool array_dynamic_back(const ArrayDynamic *arr, array_dynamic_value_t *out_value);
bool array_dynamic_push_back(ArrayDynamic *arr, array_dynamic_value_t value);
bool array_dynamic_pop_back(ArrayDynamic *arr, array_dynamic_value_t *out_value);
bool array_dynamic_insert(ArrayDynamic *arr, size_t index, array_dynamic_value_t value);
bool array_dynamic_remove(ArrayDynamic *arr, size_t index, array_dynamic_value_t *out_value);
bool array_dynamic_reserve(ArrayDynamic *arr, size_t new_capacity);
void array_dynamic_clear(ArrayDynamic *arr);

#endif
