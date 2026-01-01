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
  CHECK(queue_array_is_empty(&queue) == true, "init empty");
  CHECK(queue_array_capacity(&queue) == QUEUE_ARRAY_CAPACITY, "capacity");

  queue_array_value_t value = 0;
  CHECK(!queue_array_dequeue(&queue, &value), "dequeue empty");
  CHECK(!queue_array_front(&queue, &value), "front empty");
  CHECK(!queue_array_back(&queue, &value), "back empty");

  CHECK(queue_array_enqueue(&queue, 10), "enqueue 10");
  CHECK(queue_array_enqueue(&queue, 20), "enqueue 20");
  CHECK(queue_array_enqueue(&queue, 30), "enqueue 30");

  CHECK(queue_array_front(&queue, &value) && value == 10, "front value");
  CHECK(queue_array_back(&queue, &value) && value == 30, "back value");

  CHECK(queue_array_dequeue(&queue, &value) && value == 10, "dequeue 10");
  CHECK(queue_array_enqueue(&queue, 40), "enqueue wrap");
  CHECK(queue_array_back(&queue, &value) && value == 40, "back after wrap");

  while (queue_array_size(&queue) < QUEUE_ARRAY_CAPACITY) {
    CHECK(queue_array_enqueue(&queue, 1), "fill queue");
  }
  CHECK(queue_array_is_full(&queue) == true, "is full");
  CHECK(!queue_array_enqueue(&queue, 99), "enqueue full");

  queue_array_clear(&queue);
  CHECK(queue_array_is_empty(&queue) == true, "clear empty");

  printf("queue_array ok\n");
  return 0;
}
