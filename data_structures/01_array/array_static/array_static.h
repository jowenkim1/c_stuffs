#ifndef ARRAY_STATIC_H
#define ARRAY_STATIC_H

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
int array_static_is_empty(const ArrayStatic *arr);
int array_static_is_full(const ArrayStatic *arr);
int array_static_get(const ArrayStatic *arr, size_t index, array_static_value_t *out_value);
int array_static_set(ArrayStatic *arr, size_t index, array_static_value_t value);
int array_static_front(const ArrayStatic *arr, array_static_value_t *out_value);
int array_static_back(const ArrayStatic *arr, array_static_value_t *out_value);
int array_static_push_back(ArrayStatic *arr, array_static_value_t value);
int array_static_pop_back(ArrayStatic *arr, array_static_value_t *out_value);
int array_static_insert(ArrayStatic *arr, size_t index, array_static_value_t value);
int array_static_remove(ArrayStatic *arr, size_t index, array_static_value_t *out_value);
void array_static_clear(ArrayStatic *arr);

#endif
