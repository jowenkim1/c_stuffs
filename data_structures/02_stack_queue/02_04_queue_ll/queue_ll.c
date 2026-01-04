#include <assert.h>
#include <stdlib.h>
#include "queue_ll.h"

void queue_ll_init(QueueLL *queue)
{
    assert(queue != NULL);
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}
void queue_ll_destroy(QueueLL *queue)
{
    assert(queue != NULL);
    QueueLLNode *c = queue->front;
    while (c != NULL)
    {
        QueueLLNode *tmp = c;
        c = c->next;
        free(tmp);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}
size_t queue_ll_size(const QueueLL *queue)
{
    assert(queue != NULL);
    return queue->size;
}
bool queue_ll_is_empty(const QueueLL *queue)
{
    assert(queue != NULL);
    return queue->size == 0;
}
bool queue_ll_enqueue(QueueLL *queue, queue_ll_value_t value)
{
    assert(queue != NULL);
    QueueLLNode *new = malloc(sizeof(QueueLLNode));
    if (new == NULL)
    {
        return false;
    }
    new->value = value;
    new->next = NULL;
    if (queue->size == 0)
    {
        queue->front = new;
        queue->rear = new;
    }
    else
    {
        queue->rear->next = new;
        queue->rear = new;
    }
    queue->size += 1;
    return true;
}
bool queue_ll_dequeue(QueueLL *queue, queue_ll_value_t *out_value)
{
    assert(queue != NULL);
    assert(out_value != NULL);
    if (queue->size == 0)
    {
        return false;
    }
    QueueLLNode *tmp = queue->front;
    *out_value = tmp->value;
    queue->front = tmp->next;
    queue->size -= 1;
    free(tmp);
    if (queue->size == 0)
    {
        queue->rear = NULL;
    }
    return true;
}
bool queue_ll_front(const QueueLL *queue, queue_ll_value_t *out_value)
{
    assert(queue != NULL);
    assert(out_value != NULL);
    if (queue->size == 0)
    {
        return false;
    }
    *out_value = queue->front->value;
    return true;
}
bool queue_ll_back(const QueueLL *queue, queue_ll_value_t *out_value)
{
    assert(queue != NULL);
    assert(out_value != NULL);
    if (queue->size == 0)
    {
        return false;
    }
    *out_value = queue->rear->value;
    return true;
}
void queue_ll_clear(QueueLL *queue)
{
    assert(queue != NULL);
    QueueLLNode *c = queue->front;
    while (c != NULL)
    {
        QueueLLNode *tmp = c;
        c = c->next;
        free(tmp);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}