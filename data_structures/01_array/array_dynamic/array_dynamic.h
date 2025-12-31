#ifndef ARRAY_DYNAMIC_H
#define ARRAY_DYNAMIC_H

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
 * - push/insert may grow capacity; return DS_ERR_NOMEM on allocation failure.
 */

#define ARRAY_DYNAMIC_DEFAULT_CAPACITY 8

typedef int array_dynamic_value_t;

typedef struct {
  array_dynamic_value_t *data;
  size_t size;
  size_t capacity;
} ArrayDynamic;

int array_dynamic_init(ArrayDynamic *arr, size_t capacity);
void array_dynamic_destroy(ArrayDynamic *arr);
size_t array_dynamic_size(const ArrayDynamic *arr);
size_t array_dynamic_capacity(const ArrayDynamic *arr);
int array_dynamic_is_empty(const ArrayDynamic *arr);
int array_dynamic_get(const ArrayDynamic *arr, size_t index, array_dynamic_value_t *out_value);
int array_dynamic_set(ArrayDynamic *arr, size_t index, array_dynamic_value_t value);
int array_dynamic_front(const ArrayDynamic *arr, array_dynamic_value_t *out_value);
int array_dynamic_back(const ArrayDynamic *arr, array_dynamic_value_t *out_value);
int array_dynamic_push_back(ArrayDynamic *arr, array_dynamic_value_t value);
int array_dynamic_pop_back(ArrayDynamic *arr, array_dynamic_value_t *out_value);
int array_dynamic_insert(ArrayDynamic *arr, size_t index, array_dynamic_value_t value);
int array_dynamic_remove(ArrayDynamic *arr, size_t index, array_dynamic_value_t *out_value);
int array_dynamic_reserve(ArrayDynamic *arr, size_t new_capacity);
void array_dynamic_clear(ArrayDynamic *arr);

#endif
