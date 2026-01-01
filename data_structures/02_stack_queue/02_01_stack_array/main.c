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
  CHECK(stack_array_is_empty(&stack) == true, "init empty");
  CHECK(stack_array_capacity(&stack) == STACK_ARRAY_CAPACITY, "capacity");

  stack_array_value_t value = 0;
  CHECK(!stack_array_pop(&stack, &value), "pop empty");
  CHECK(!stack_array_peek(&stack, &value), "peek empty");

  CHECK(stack_array_push(&stack, 1), "push 1");
  CHECK(stack_array_push(&stack, 2), "push 2");
  CHECK(stack_array_push(&stack, 3), "push 3");

  CHECK(stack_array_peek(&stack, &value) && value == 3, "peek value");
  CHECK(stack_array_pop(&stack, &value) && value == 3, "pop value");

  while (stack_array_size(&stack) < STACK_ARRAY_CAPACITY) {
    CHECK(stack_array_push(&stack, 0), "fill stack");
  }
  CHECK(stack_array_is_full(&stack) == true, "is full");
  CHECK(!stack_array_push(&stack, 9), "push full");

  stack_array_clear(&stack);
  CHECK(stack_array_is_empty(&stack) == true, "clear empty");

  printf("stack_array ok\n");
  return 0;
}
