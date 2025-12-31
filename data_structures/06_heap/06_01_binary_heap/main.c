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
  CHECK(heap_init(&heap, 8) == DS_OK, "init");

  heap_value_t value = 0;
  CHECK(heap_peek(&heap, &value) == DS_ERR_EMPTY, "peek empty");
  CHECK(heap_pop(&heap, &value) == DS_ERR_EMPTY, "pop empty");

  CHECK(heap_push(&heap, 3) == DS_OK, "push 3");
  CHECK(heap_push(&heap, 1) == DS_OK, "push 1");
  CHECK(heap_push(&heap, 2) == DS_OK, "push 2");

  CHECK(heap_peek(&heap, &value) == DS_OK && value == 1, "peek min");
  CHECK(heap_pop(&heap, &value) == DS_OK && value == 1, "pop min");

  CHECK(heap_reserve(&heap, 2) == DS_ERR_INVALID, "reserve too small");

  heap_clear(&heap);
  CHECK(heap_is_empty(&heap) == 1, "clear empty");

  heap_destroy(&heap);
  printf("heap ok\n");
  return 0;
}
