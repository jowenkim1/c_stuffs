#include <stdio.h>

#include "deque_ll.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

int main(void) {
  DequeLL deque;
  deque_ll_init(&deque);

  CHECK(deque_ll_size(&deque) == 0, "init size");
  CHECK(deque_ll_is_empty(&deque) == 1, "init empty");

  deque_ll_value_t value = 0;
  CHECK(deque_ll_pop_front(&deque, &value) == DS_ERR_EMPTY, "pop front empty");
  CHECK(deque_ll_pop_back(&deque, &value) == DS_ERR_EMPTY, "pop back empty");
  CHECK(deque_ll_front(&deque, &value) == DS_ERR_EMPTY, "front empty");
  CHECK(deque_ll_back(&deque, &value) == DS_ERR_EMPTY, "back empty");

  CHECK(deque_ll_push_back(&deque, 1) == DS_OK, "push back 1");
  CHECK(deque_ll_push_back(&deque, 2) == DS_OK, "push back 2");
  CHECK(deque_ll_push_front(&deque, 0) == DS_OK, "push front 0");

  CHECK(deque_ll_front(&deque, &value) == DS_OK && value == 0, "front value");
  CHECK(deque_ll_back(&deque, &value) == DS_OK && value == 2, "back value");

  CHECK(deque_ll_pop_front(&deque, &value) == DS_OK && value == 0, "pop front");
  CHECK(deque_ll_pop_back(&deque, &value) == DS_OK && value == 2, "pop back");

  deque_ll_clear(&deque);
  CHECK(deque_ll_is_empty(&deque) == 1, "clear empty");

  deque_ll_destroy(&deque);
  printf("deque_ll ok\n");
  return 0;
}
