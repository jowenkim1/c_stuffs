#include <stdio.h>

#include "vector.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

int main(void) {
  Vector vec;
  CHECK(vector_init(&vec, VECTOR_DEFAULT_CAPACITY) == DS_OK, "init");

  CHECK(vector_size(&vec) == 0, "init size");
  CHECK(vector_is_empty(&vec) == 1, "init empty");

  vector_value_t value = 0;
  CHECK(vector_pop_back(&vec, &value) == DS_ERR_EMPTY, "pop empty");
  CHECK(vector_front(&vec, &value) == DS_ERR_EMPTY, "front empty");
  CHECK(vector_back(&vec, &value) == DS_ERR_EMPTY, "back empty");
  CHECK(vector_get(&vec, 0, &value) == DS_ERR_INVALID, "get invalid");

  CHECK(vector_push_back(&vec, 5) == DS_OK, "push 5");
  CHECK(vector_push_back(&vec, 6) == DS_OK, "push 6");
  CHECK(vector_push_back(&vec, 7) == DS_OK, "push 7");

  CHECK(vector_front(&vec, &value) == DS_OK && value == 5, "front value");
  CHECK(vector_back(&vec, &value) == DS_OK && value == 7, "back value");

  CHECK(vector_insert(&vec, 1, 42) == DS_OK, "insert");
  CHECK(vector_get(&vec, 1, &value) == DS_OK && value == 42, "get after insert");

  CHECK(vector_pop_back(&vec, &value) == DS_OK, "pop back");
  CHECK(vector_set(&vec, 0, 9) == DS_OK, "set");
  CHECK(vector_get(&vec, 0, &value) == DS_OK && value == 9, "get after set");

  vector_clear(&vec);
  CHECK(vector_is_empty(&vec) == 1, "clear empty");

  vector_destroy(&vec);
  printf("vector ok\n");
  return 0;
}
