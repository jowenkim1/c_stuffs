#ifndef QUEUE_LL_H
#define QUEUE_LL_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
 * - out_value must be non-NULL; it is unchanged on failure.
 */

typedef int queue_ll_value_t;

typedef struct QueueLLNode {
  queue_ll_value_t value;
  struct QueueLLNode *next;
} QueueLLNode;

typedef struct {
  QueueLLNode *front;
  QueueLLNode *rear;
  size_t size;
} QueueLL;

void queue_ll_init(QueueLL *queue);
void queue_ll_destroy(QueueLL *queue);
size_t queue_ll_size(const QueueLL *queue);
bool queue_ll_is_empty(const QueueLL *queue);
bool queue_ll_enqueue(QueueLL *queue, queue_ll_value_t value);
bool queue_ll_dequeue(QueueLL *queue, queue_ll_value_t *out_value);
bool queue_ll_front(const QueueLL *queue, queue_ll_value_t *out_value);
bool queue_ll_back(const QueueLL *queue, queue_ll_value_t *out_value);
void queue_ll_clear(QueueLL *queue);

#endif
