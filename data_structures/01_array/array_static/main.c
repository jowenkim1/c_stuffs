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
  CHECK(array_static_is_empty(&arr) == true, "init empty");
  CHECK(array_static_capacity(&arr) == ARRAY_STATIC_CAPACITY, "capacity");

  array_static_value_t value = 0;
  CHECK(!array_static_pop_back(&arr, &value), "pop empty");
  CHECK(!array_static_front(&arr, &value), "front empty");
  CHECK(!array_static_back(&arr, &value), "back empty");
  CHECK(!array_static_get(&arr, 0, &value), "get invalid");

  CHECK(array_static_push_back(&arr, 10), "push 10");
  CHECK(array_static_push_back(&arr, 20), "push 20");
  CHECK(array_static_push_back(&arr, 30), "push 30");

  CHECK(array_static_front(&arr, &value) && value == 10, "front value");
  CHECK(array_static_back(&arr, &value) && value == 30, "back value");

  CHECK(array_static_insert(&arr, 1, 99), "insert");
  CHECK(array_static_get(&arr, 1, &value) && value == 99, "get after insert");

  CHECK(!array_static_insert(&arr, 99, 1), "insert invalid");
  CHECK(!array_static_remove(&arr, 99, &value), "remove invalid");

  CHECK(array_static_remove(&arr, 2, &value) && value == 20, "remove valid");
  CHECK(array_static_set(&arr, 0, 7), "set");
  CHECK(array_static_get(&arr, 0, &value) && value == 7, "get after set");

  while (array_static_size(&arr) < ARRAY_STATIC_CAPACITY) {
    CHECK(array_static_push_back(&arr, 0), "fill to capacity");
  }
  CHECK(array_static_is_full(&arr) == true, "is full");
  CHECK(!array_static_push_back(&arr, 1), "push full");

  array_static_clear(&arr);
  CHECK(array_static_is_empty(&arr) == true, "clear empty");

  printf("array_static ok\n");
  return 0;
}
