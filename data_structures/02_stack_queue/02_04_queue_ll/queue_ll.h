#ifndef QUEUE_LL_H
#define QUEUE_LL_H

#include <stddef.h>

#ifndef DS_STATUS_H
#define DS_STATUS_H
#define DS_OK 0
#define DS_ERR_INVALID -1
#define DS_ERR_EMPTY -2
#define DS_ERR_FULL -3
#define DS_ERR_NOMEM -4
#define DS_ERR_NOT_FOUND -5
#endif

/*
 * ADT conventions:
 * - Status functions return DS_OK on success, negative DS_ERR_* on failure.
 * - Boolean queries return 1 (true), 0 (false), or DS_ERR_INVALID for bad args.
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
int queue_ll_is_empty(const QueueLL *queue);
int queue_ll_enqueue(QueueLL *queue, queue_ll_value_t value);
int queue_ll_dequeue(QueueLL *queue, queue_ll_value_t *out_value);
int queue_ll_front(const QueueLL *queue, queue_ll_value_t *out_value);
int queue_ll_back(const QueueLL *queue, queue_ll_value_t *out_value);
void queue_ll_clear(QueueLL *queue);

#endif
