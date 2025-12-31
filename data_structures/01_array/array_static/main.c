#include <stdio.h>

#include "array_static.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

int main(void) {
  ArrayStatic arr;
  array_static_init(&arr);

  CHECK(array_static_size(&arr) == 0, "init size");
  CHECK(array_static_is_empty(&arr) == 1, "init empty");
  CHECK(array_static_capacity(&arr) == ARRAY_STATIC_CAPACITY, "capacity");

  array_static_value_t value = 0;
  CHECK(array_static_pop_back(&arr, &value) == DS_ERR_EMPTY, "pop empty");
  CHECK(array_static_front(&arr, &value) == DS_ERR_EMPTY, "front empty");
  CHECK(array_static_back(&arr, &value) == DS_ERR_EMPTY, "back empty");
  CHECK(array_static_get(&arr, 0, &value) == DS_ERR_INVALID, "get invalid");

  CHECK(array_static_push_back(&arr, 10) == DS_OK, "push 10");
  CHECK(array_static_push_back(&arr, 20) == DS_OK, "push 20");
  CHECK(array_static_push_back(&arr, 30) == DS_OK, "push 30");

  CHECK(array_static_front(&arr, &value) == DS_OK && value == 10, "front value");
  CHECK(array_static_back(&arr, &value) == DS_OK && value == 30, "back value");

  CHECK(array_static_insert(&arr, 1, 99) == DS_OK, "insert");
  CHECK(array_static_get(&arr, 1, &value) == DS_OK && value == 99, "get after insert");

  CHECK(array_static_insert(&arr, 99, 1) == DS_ERR_INVALID, "insert invalid");
  CHECK(array_static_remove(&arr, 99, &value) == DS_ERR_INVALID, "remove invalid");

  CHECK(array_static_remove(&arr, 2, &value) == DS_OK && value == 20, "remove valid");
  CHECK(array_static_set(&arr, 0, 7) == DS_OK, "set");
  CHECK(array_static_get(&arr, 0, &value) == DS_OK && value == 7, "get after set");

  while (array_static_size(&arr) < ARRAY_STATIC_CAPACITY) {
    CHECK(array_static_push_back(&arr, 0) == DS_OK, "fill to capacity");
  }
  CHECK(array_static_is_full(&arr) == 1, "is full");
  CHECK(array_static_push_back(&arr, 1) == DS_ERR_FULL, "push full");

  array_static_clear(&arr);
  CHECK(array_static_is_empty(&arr) == 1, "clear empty");

  printf("array_static ok\n");
  return 0;
}
