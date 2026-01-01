#include <stdio.h>

#include "array_dynamic.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

int main(void) {
  ArrayDynamic arr;
  CHECK(array_dynamic_init(&arr, ARRAY_DYNAMIC_DEFAULT_CAPACITY), "init");

  CHECK(array_dynamic_size(&arr) == 0, "init size");
  CHECK(array_dynamic_is_empty(&arr) == true, "init empty");

  array_dynamic_value_t value = 0;
  CHECK(!array_dynamic_pop_back(&arr, &value), "pop empty");
  CHECK(!array_dynamic_front(&arr, &value), "front empty");
  CHECK(!array_dynamic_back(&arr, &value), "back empty");
  CHECK(!array_dynamic_get(&arr, 0, &value), "get invalid");

  CHECK(array_dynamic_push_back(&arr, 1), "push 1");
  CHECK(array_dynamic_push_back(&arr, 2), "push 2");
  CHECK(array_dynamic_push_back(&arr, 3), "push 3");

  CHECK(array_dynamic_front(&arr, &value) && value == 1, "front value");
  CHECK(array_dynamic_back(&arr, &value) && value == 3, "back value");

  CHECK(array_dynamic_insert(&arr, 1, 99), "insert");
  CHECK(array_dynamic_get(&arr, 1, &value) && value == 99, "get after insert");

  CHECK(!array_dynamic_reserve(&arr, 2), "reserve too small");
  CHECK(array_dynamic_remove(&arr, 2, &value) && value == 2, "remove valid");

  CHECK(array_dynamic_pop_back(&arr, &value), "pop back");
  CHECK(array_dynamic_set(&arr, 0, 7), "set");
  CHECK(array_dynamic_get(&arr, 0, &value) && value == 7, "get after set");

  array_dynamic_clear(&arr);
  CHECK(array_dynamic_is_empty(&arr) == true, "clear empty");

  array_dynamic_destroy(&arr);
  printf("array_dynamic ok\n");
  return 0;
}
