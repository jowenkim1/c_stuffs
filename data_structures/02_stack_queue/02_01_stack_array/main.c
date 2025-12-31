#include <stdio.h>

#include "stack_array.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

int main(void) {
  StackArray stack;
  stack_array_init(&stack);

  CHECK(stack_array_size(&stack) == 0, "init size");
  CHECK(stack_array_is_empty(&stack) == 1, "init empty");
  CHECK(stack_array_capacity(&stack) == STACK_ARRAY_CAPACITY, "capacity");

  stack_array_value_t value = 0;
  CHECK(stack_array_pop(&stack, &value) == DS_ERR_EMPTY, "pop empty");
  CHECK(stack_array_peek(&stack, &value) == DS_ERR_EMPTY, "peek empty");

  CHECK(stack_array_push(&stack, 1) == DS_OK, "push 1");
  CHECK(stack_array_push(&stack, 2) == DS_OK, "push 2");
  CHECK(stack_array_push(&stack, 3) == DS_OK, "push 3");

  CHECK(stack_array_peek(&stack, &value) == DS_OK && value == 3, "peek value");
  CHECK(stack_array_pop(&stack, &value) == DS_OK && value == 3, "pop value");

  while (stack_array_size(&stack) < STACK_ARRAY_CAPACITY) {
    CHECK(stack_array_push(&stack, 0) == DS_OK, "fill stack");
  }
  CHECK(stack_array_is_full(&stack) == 1, "is full");
  CHECK(stack_array_push(&stack, 9) == DS_ERR_FULL, "push full");

  stack_array_clear(&stack);
  CHECK(stack_array_is_empty(&stack) == 1, "clear empty");

  printf("stack_array ok\n");
  return 0;
}
