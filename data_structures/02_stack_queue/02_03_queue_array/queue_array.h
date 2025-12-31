#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

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

#define QUEUE_ARRAY_CAPACITY 128

typedef int queue_array_value_t;

typedef struct {
  queue_array_value_t data[QUEUE_ARRAY_CAPACITY];
  size_t head;
  size_t tail;
  size_t size;
} QueueArray;

void queue_array_init(QueueArray *queue);
size_t queue_array_size(const QueueArray *queue);
size_t queue_array_capacity(const QueueArray *queue);
int queue_array_is_empty(const QueueArray *queue);
int queue_array_is_full(const QueueArray *queue);
int queue_array_enqueue(QueueArray *queue, queue_array_value_t value);
int queue_array_dequeue(QueueArray *queue, queue_array_value_t *out_value);
int queue_array_front(const QueueArray *queue, queue_array_value_t *out_value);
int queue_array_back(const QueueArray *queue, queue_array_value_t *out_value);
void queue_array_clear(QueueArray *queue);

#endif
