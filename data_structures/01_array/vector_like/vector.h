#ifndef VECTOR_H
#define VECTOR_H

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

#define VECTOR_DEFAULT_CAPACITY 8

typedef int vector_value_t;

typedef struct {
  vector_value_t *data;
  size_t size;
  size_t capacity;
} Vector;

bool vector_init(Vector *vec, size_t capacity);
void vector_destroy(Vector *vec);
size_t vector_size(const Vector *vec);
size_t vector_capacity(const Vector *vec);
bool vector_is_empty(const Vector *vec);
bool vector_get(const Vector *vec, size_t index, vector_value_t *out_value);
bool vector_set(Vector *vec, size_t index, vector_value_t value);
bool vector_front(const Vector *vec, vector_value_t *out_value);
bool vector_back(const Vector *vec, vector_value_t *out_value);
bool vector_push_back(Vector *vec, vector_value_t value);
bool vector_pop_back(Vector *vec, vector_value_t *out_value);
bool vector_insert(Vector *vec, size_t index, vector_value_t value);
bool vector_remove(Vector *vec, size_t index, vector_value_t *out_value);
bool vector_reserve(Vector *vec, size_t new_capacity);
void vector_clear(Vector *vec);

#endif
