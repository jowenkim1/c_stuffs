#include <stdio.h>

#include "queue_ll.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

int main(void) {
  QueueLL queue;
  queue_ll_init(&queue);

  CHECK(queue_ll_size(&queue) == 0, "init size");
  CHECK(queue_ll_is_empty(&queue) == 1, "init empty");

  queue_ll_value_t value = 0;
  CHECK(queue_ll_dequeue(&queue, &value) == DS_ERR_EMPTY, "dequeue empty");
  CHECK(queue_ll_front(&queue, &value) == DS_ERR_EMPTY, "front empty");
  CHECK(queue_ll_back(&queue, &value) == DS_ERR_EMPTY, "back empty");

  CHECK(queue_ll_enqueue(&queue, 11) == DS_OK, "enqueue 11");
  CHECK(queue_ll_enqueue(&queue, 22) == DS_OK, "enqueue 22");
  CHECK(queue_ll_enqueue(&queue, 33) == DS_OK, "enqueue 33");

  CHECK(queue_ll_front(&queue, &value) == DS_OK && value == 11, "front value");
  CHECK(queue_ll_back(&queue, &value) == DS_OK && value == 33, "back value");

  CHECK(queue_ll_dequeue(&queue, &value) == DS_OK && value == 11, "dequeue 11");

  queue_ll_clear(&queue);
  CHECK(queue_ll_is_empty(&queue) == 1, "clear empty");

  queue_ll_destroy(&queue);
  printf("queue_ll ok\n");
  return 0;
}
