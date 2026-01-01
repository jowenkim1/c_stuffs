#include <stdio.h>

#include "heap.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

int main(void) {
  BinaryHeap heap;
  CHECK(heap_init(&heap, 8), "init");

  heap_value_t value = 0;
  CHECK(!heap_peek(&heap, &value), "peek empty");
  CHECK(!heap_pop(&heap, &value), "pop empty");

  CHECK(heap_push(&heap, 3), "push 3");
  CHECK(heap_push(&heap, 1), "push 1");
  CHECK(heap_push(&heap, 2), "push 2");

  CHECK(heap_peek(&heap, &value) && value == 1, "peek min");
  CHECK(heap_pop(&heap, &value) && value == 1, "pop min");

  CHECK(!heap_reserve(&heap, 2), "reserve too small");

  heap_clear(&heap);
  CHECK(heap_is_empty(&heap) == true, "clear empty");

  heap_destroy(&heap);
  printf("heap ok\n");
  return 0;
}
