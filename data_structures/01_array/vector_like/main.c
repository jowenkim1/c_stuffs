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
  CHECK(vector_init(&vec, VECTOR_DEFAULT_CAPACITY), "init");

  CHECK(vector_size(&vec) == 0, "init size");
  CHECK(vector_is_empty(&vec) == true, "init empty");

  vector_value_t value = 0;
  CHECK(!vector_pop_back(&vec, &value), "pop empty");
  CHECK(!vector_front(&vec, &value), "front empty");
  CHECK(!vector_back(&vec, &value), "back empty");
  CHECK(!vector_get(&vec, 0, &value), "get invalid");

  CHECK(vector_push_back(&vec, 5), "push 5");
  CHECK(vector_push_back(&vec, 6), "push 6");
  CHECK(vector_push_back(&vec, 7), "push 7");

  CHECK(vector_front(&vec, &value) && value == 5, "front value");
  CHECK(vector_back(&vec, &value) && value == 7, "back value");

  CHECK(vector_insert(&vec, 1, 42), "insert");
  CHECK(vector_get(&vec, 1, &value) && value == 42, "get after insert");

  CHECK(vector_pop_back(&vec, &value), "pop back");
  CHECK(vector_set(&vec, 0, 9), "set");
  CHECK(vector_get(&vec, 0, &value) && value == 9, "get after set");

  vector_clear(&vec);
  CHECK(vector_is_empty(&vec) == true, "clear empty");

  vector_destroy(&vec);
  printf("vector ok\n");
  return 0;
}
