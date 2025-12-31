#include <stdio.h>

#include "stack_ll.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

int main(void) {
  StackLL stack;
  stack_ll_init(&stack);

  CHECK(stack_ll_size(&stack) == 0, "init size");
  CHECK(stack_ll_is_empty(&stack) == 1, "init empty");

  stack_ll_value_t value = 0;
  CHECK(stack_ll_pop(&stack, &value) == DS_ERR_EMPTY, "pop empty");
  CHECK(stack_ll_peek(&stack, &value) == DS_ERR_EMPTY, "peek empty");

  CHECK(stack_ll_push(&stack, 10) == DS_OK, "push 10");
  CHECK(stack_ll_push(&stack, 20) == DS_OK, "push 20");
  CHECK(stack_ll_push(&stack, 30) == DS_OK, "push 30");

  CHECK(stack_ll_peek(&stack, &value) == DS_OK && value == 30, "peek value");
  CHECK(stack_ll_pop(&stack, &value) == DS_OK && value == 30, "pop value");

  stack_ll_clear(&stack);
  CHECK(stack_ll_is_empty(&stack) == 1, "clear empty");

  stack_ll_destroy(&stack);
  printf("stack_ll ok\n");
  return 0;
}
