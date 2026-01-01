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
  CHECK(deque_ll_is_empty(&deque) == true, "init empty");

  deque_ll_value_t value = 0;
  CHECK(!deque_ll_pop_front(&deque, &value), "pop front empty");
  CHECK(!deque_ll_pop_back(&deque, &value), "pop back empty");
  CHECK(!deque_ll_front(&deque, &value), "front empty");
  CHECK(!deque_ll_back(&deque, &value), "back empty");

  CHECK(deque_ll_push_back(&deque, 1), "push back 1");
  CHECK(deque_ll_push_back(&deque, 2), "push back 2");
  CHECK(deque_ll_push_front(&deque, 0), "push front 0");

  CHECK(deque_ll_front(&deque, &value) && value == 0, "front value");
  CHECK(deque_ll_back(&deque, &value) && value == 2, "back value");

  CHECK(deque_ll_pop_front(&deque, &value) && value == 0, "pop front");
  CHECK(deque_ll_pop_back(&deque, &value) && value == 2, "pop back");

  deque_ll_clear(&deque);
  CHECK(deque_ll_is_empty(&deque) == true, "clear empty");

  deque_ll_destroy(&deque);
  printf("deque_ll ok\n");
  return 0;
}
