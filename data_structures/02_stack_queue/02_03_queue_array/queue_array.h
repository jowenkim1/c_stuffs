#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
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
bool queue_array_is_empty(const QueueArray *queue);
bool queue_array_is_full(const QueueArray *queue);
bool queue_array_enqueue(QueueArray *queue, queue_array_value_t value);
bool queue_array_dequeue(QueueArray *queue, queue_array_value_t *out_value);
bool queue_array_front(const QueueArray *queue, queue_array_value_t *out_value);
bool queue_array_back(const QueueArray *queue, queue_array_value_t *out_value);
void queue_array_clear(QueueArray *queue);

#endif
