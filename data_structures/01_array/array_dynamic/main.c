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
  CHECK(array_dynamic_init(&arr, ARRAY_DYNAMIC_DEFAULT_CAPACITY) == DS_OK,
        "init");

  CHECK(array_dynamic_size(&arr) == 0, "init size");
  CHECK(array_dynamic_is_empty(&arr) == 1, "init empty");

  array_dynamic_value_t value = 0;
  CHECK(array_dynamic_pop_back(&arr, &value) == DS_ERR_EMPTY, "pop empty");
  CHECK(array_dynamic_front(&arr, &value) == DS_ERR_EMPTY, "front empty");
  CHECK(array_dynamic_back(&arr, &value) == DS_ERR_EMPTY, "back empty");
  CHECK(array_dynamic_get(&arr, 0, &value) == DS_ERR_INVALID, "get invalid");

  CHECK(array_dynamic_push_back(&arr, 1) == DS_OK, "push 1");
  CHECK(array_dynamic_push_back(&arr, 2) == DS_OK, "push 2");
  CHECK(array_dynamic_push_back(&arr, 3) == DS_OK, "push 3");

  CHECK(array_dynamic_front(&arr, &value) == DS_OK && value == 1, "front value");
  CHECK(array_dynamic_back(&arr, &value) == DS_OK && value == 3, "back value");

  CHECK(array_dynamic_insert(&arr, 1, 99) == DS_OK, "insert");
  CHECK(array_dynamic_get(&arr, 1, &value) == DS_OK && value == 99, "get after insert");

  CHECK(array_dynamic_reserve(&arr, 2) == DS_ERR_INVALID, "reserve too small");
  CHECK(array_dynamic_remove(&arr, 2, &value) == DS_OK && value == 2, "remove valid");

  CHECK(array_dynamic_pop_back(&arr, &value) == DS_OK, "pop back");
  CHECK(array_dynamic_set(&arr, 0, 7) == DS_OK, "set");
  CHECK(array_dynamic_get(&arr, 0, &value) == DS_OK && value == 7, "get after set");

  array_dynamic_clear(&arr);
  CHECK(array_dynamic_is_empty(&arr) == 1, "clear empty");

  array_dynamic_destroy(&arr);
  printf("array_dynamic ok\n");
  return 0;
}
