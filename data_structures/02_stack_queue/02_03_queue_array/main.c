#include <stdio.h>

#include "queue_array.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

int main(void) {
  QueueArray queue;
  queue_array_init(&queue);

  CHECK(queue_array_size(&queue) == 0, "init size");
  CHECK(queue_array_is_empty(&queue) == 1, "init empty");
  CHECK(queue_array_capacity(&queue) == QUEUE_ARRAY_CAPACITY, "capacity");

  queue_array_value_t value = 0;
  CHECK(queue_array_dequeue(&queue, &value) == DS_ERR_EMPTY, "dequeue empty");
  CHECK(queue_array_front(&queue, &value) == DS_ERR_EMPTY, "front empty");
  CHECK(queue_array_back(&queue, &value) == DS_ERR_EMPTY, "back empty");

  CHECK(queue_array_enqueue(&queue, 10) == DS_OK, "enqueue 10");
  CHECK(queue_array_enqueue(&queue, 20) == DS_OK, "enqueue 20");
  CHECK(queue_array_enqueue(&queue, 30) == DS_OK, "enqueue 30");

  CHECK(queue_array_front(&queue, &value) == DS_OK && value == 10, "front value");
  CHECK(queue_array_back(&queue, &value) == DS_OK && value == 30, "back value");

  CHECK(queue_array_dequeue(&queue, &value) == DS_OK && value == 10, "dequeue 10");
  CHECK(queue_array_enqueue(&queue, 40) == DS_OK, "enqueue wrap");
  CHECK(queue_array_back(&queue, &value) == DS_OK && value == 40, "back after wrap");

  while (queue_array_size(&queue) < QUEUE_ARRAY_CAPACITY) {
    CHECK(queue_array_enqueue(&queue, 1) == DS_OK, "fill queue");
  }
  CHECK(queue_array_is_full(&queue) == 1, "is full");
  CHECK(queue_array_enqueue(&queue, 99) == DS_ERR_FULL, "enqueue full");

  queue_array_clear(&queue);
  CHECK(queue_array_is_empty(&queue) == 1, "clear empty");

  printf("queue_array ok\n");
  return 0;
}
