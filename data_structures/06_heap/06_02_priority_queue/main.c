#include <stdio.h>

#include "pq.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

int main(void) {
  PriorityQueue pq;
  CHECK(pq_init(&pq, 8), "init");

  pq_value_t value = 0;
  CHECK(!pq_peek(&pq, &value), "peek empty");
  CHECK(!pq_pop(&pq, &value), "pop empty");

  CHECK(pq_push(&pq, 5), "push 5");
  CHECK(pq_push(&pq, 9), "push 9");
  CHECK(pq_push(&pq, 1), "push 1");

  CHECK(pq_peek(&pq, &value) && value == 1, "peek min");
  CHECK(pq_pop(&pq, &value) && value == 1, "pop min");

  CHECK(!pq_reserve(&pq, 2), "reserve too small");

  pq_clear(&pq);
  CHECK(pq_is_empty(&pq) == true, "clear empty");

  pq_destroy(&pq);
  printf("pq ok\n");
  return 0;
}
