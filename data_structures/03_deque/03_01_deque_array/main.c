#include <stdio.h>

#include "deque_array.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

int main(void) {
  DequeArray deque;
  deque_array_init(&deque);

  CHECK(deque_array_size(&deque) == 0, "init size");
  CHECK(deque_array_is_empty(&deque) == 1, "init empty");
  CHECK(deque_array_capacity(&deque) == DEQUE_ARRAY_CAPACITY, "capacity");

  deque_array_value_t value = 0;
  CHECK(deque_array_pop_front(&deque, &value) == DS_ERR_EMPTY, "pop front empty");
  CHECK(deque_array_pop_back(&deque, &value) == DS_ERR_EMPTY, "pop back empty");
  CHECK(deque_array_front(&deque, &value) == DS_ERR_EMPTY, "front empty");
  CHECK(deque_array_back(&deque, &value) == DS_ERR_EMPTY, "back empty");

  CHECK(deque_array_push_back(&deque, 1) == DS_OK, "push back 1");
  CHECK(deque_array_push_back(&deque, 2) == DS_OK, "push back 2");
  CHECK(deque_array_push_front(&deque, 0) == DS_OK, "push front 0");

  CHECK(deque_array_front(&deque, &value) == DS_OK && value == 0, "front value");
  CHECK(deque_array_back(&deque, &value) == DS_OK && value == 2, "back value");

  CHECK(deque_array_pop_front(&deque, &value) == DS_OK && value == 0, "pop front");
  CHECK(deque_array_pop_back(&deque, &value) == DS_OK && value == 2, "pop back");

  while (deque_array_size(&deque) < DEQUE_ARRAY_CAPACITY) {
    CHECK(deque_array_push_back(&deque, 1) == DS_OK, "fill deque");
  }
  CHECK(deque_array_is_full(&deque) == 1, "is full");
  CHECK(deque_array_push_front(&deque, 9) == DS_ERR_FULL, "push front full");

  deque_array_clear(&deque);
  CHECK(deque_array_is_empty(&deque) == 1, "clear empty");

  printf("deque_array ok\n");
  return 0;
}
