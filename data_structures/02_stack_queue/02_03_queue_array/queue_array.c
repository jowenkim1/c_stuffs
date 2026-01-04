#include <assert.h>
#include <stdlib.h>
#include "queue_array.h"

void queue_array_init(QueueArray *queue)
{
    assert(queue != NULL);
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
}
size_t queue_array_size(const QueueArray *queue)
{
    assert(queue != NULL);
    return queue->size;
}
size_t queue_array_capacity(const QueueArray *queue)
{
    assert(queue != NULL);
    return QUEUE_ARRAY_CAPACITY;
}
bool queue_array_is_empty(const QueueArray *queue)
{
    assert(queue != NULL);
    return queue->size == 0;
}
bool queue_array_is_full(const QueueArray *queue)
{
    assert(queue != NULL);
    return queue->size == QUEUE_ARRAY_CAPACITY;
}
bool queue_array_enqueue(QueueArray *queue, queue_array_value_t value)
{
    assert(queue != NULL);
    if (QUEUE_ARRAY_CAPACITY <= queue->size)
    {
        return false;
    }
    queue->data[queue->tail] = value;
    queue->tail = (queue->tail + 1) % QUEUE_ARRAY_CAPACITY;
    queue->size += 1;
    return true;
}

bool queue_array_dequeue(QueueArray *queue, queue_array_value_t *out_value)
{
    assert(queue != NULL);
    assert(out_value != NULL);
    if (queue->size == 0)
    {
        return false;
    }
    *out_value = queue->data[queue->head];
    queue->head = (queue->head + 1) % QUEUE_ARRAY_CAPACITY;
    queue->size -= 1;
    return true;
}

bool queue_array_front(const QueueArray *queue, queue_array_value_t *out_value)
{
    assert(queue != NULL);
    assert(out_value != NULL);
    if (queue->size == 0)
    {
        return false;
    }
    *out_value = queue->data[queue->head];
    return true;
}
bool queue_array_back(const QueueArray *queue, queue_array_value_t *out_value)
{
    assert(queue != NULL);
    assert(out_value != NULL);
    if (queue->size == 0)
    {
        return false;
    }
    *out_value = queue->data[(queue->tail - 1 + QUEUE_ARRAY_CAPACITY) % QUEUE_ARRAY_CAPACITY];
    return true;
}
void queue_array_clear(QueueArray *queue){
    assert(queue != NULL);
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
}
