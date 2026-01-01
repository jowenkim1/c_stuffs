#ifndef ARRAY_STATIC_H
#define ARRAY_STATIC_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
 * - Indices are 0-based; insert allows index == size (append).
 * - out_value must be non-NULL; it is unchanged on failure.
 * - init must be called before use; clear leaves an empty structure.
 */

#define ARRAY_STATIC_CAPACITY 128

typedef int array_static_value_t;

typedef struct {
  array_static_value_t data[ARRAY_STATIC_CAPACITY];
  size_t size;
} ArrayStatic;

void array_static_init(ArrayStatic *arr);
size_t array_static_size(const ArrayStatic *arr);
size_t array_static_capacity(const ArrayStatic *arr);
bool array_static_is_empty(const ArrayStatic *arr);
bool array_static_is_full(const ArrayStatic *arr);
bool array_static_get(const ArrayStatic *arr, size_t index, array_static_value_t *out_value);
bool array_static_set(ArrayStatic *arr, size_t index, array_static_value_t value);
bool array_static_front(const ArrayStatic *arr, array_static_value_t *out_value);
bool array_static_back(const ArrayStatic *arr, array_static_value_t *out_value);
bool array_static_push_back(ArrayStatic *arr, array_static_value_t value);
bool array_static_pop_back(ArrayStatic *arr, array_static_value_t *out_value);
bool array_static_insert(ArrayStatic *arr, size_t index, array_static_value_t value);
bool array_static_remove(ArrayStatic *arr, size_t index, array_static_value_t *out_value);
void array_static_clear(ArrayStatic *arr);

#endif
