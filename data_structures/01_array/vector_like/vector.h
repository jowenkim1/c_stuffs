#ifndef VECTOR_H
#define VECTOR_H

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

#define VECTOR_DEFAULT_CAPACITY 8

typedef int vector_value_t;

typedef struct {
  vector_value_t *data;
  size_t size;
  size_t capacity;
} Vector;

int vector_init(Vector *vec, size_t capacity);
void vector_destroy(Vector *vec);
size_t vector_size(const Vector *vec);
size_t vector_capacity(const Vector *vec);
int vector_is_empty(const Vector *vec);
int vector_get(const Vector *vec, size_t index, vector_value_t *out_value);
int vector_set(Vector *vec, size_t index, vector_value_t value);
int vector_front(const Vector *vec, vector_value_t *out_value);
int vector_back(const Vector *vec, vector_value_t *out_value);
int vector_push_back(Vector *vec, vector_value_t value);
int vector_pop_back(Vector *vec, vector_value_t *out_value);
int vector_insert(Vector *vec, size_t index, vector_value_t value);
int vector_remove(Vector *vec, size_t index, vector_value_t *out_value);
int vector_reserve(Vector *vec, size_t new_capacity);
void vector_clear(Vector *vec);

#endif
