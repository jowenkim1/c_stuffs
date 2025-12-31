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
  CHECK(pq_init(&pq, 8) == DS_OK, "init");

  pq_value_t value = 0;
  CHECK(pq_peek(&pq, &value) == DS_ERR_EMPTY, "peek empty");
  CHECK(pq_pop(&pq, &value) == DS_ERR_EMPTY, "pop empty");

  CHECK(pq_push(&pq, 5) == DS_OK, "push 5");
  CHECK(pq_push(&pq, 9) == DS_OK, "push 9");
  CHECK(pq_push(&pq, 1) == DS_OK, "push 1");

  CHECK(pq_peek(&pq, &value) == DS_OK && value == 1, "peek min");
  CHECK(pq_pop(&pq, &value) == DS_OK && value == 1, "pop min");

  CHECK(pq_reserve(&pq, 2) == DS_ERR_INVALID, "reserve too small");

  pq_clear(&pq);
  CHECK(pq_is_empty(&pq) == 1, "clear empty");

  pq_destroy(&pq);
  printf("pq ok\n");
  return 0;
}
