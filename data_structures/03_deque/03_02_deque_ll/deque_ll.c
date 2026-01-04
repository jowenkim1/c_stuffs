#include <assert.h>
#include <stdlib.h>
#include "deque_ll.h"

void deque_ll_init(DequeLL *deque)
{
    assert(deque != NULL);
    deque->front = NULL;
    deque->back = NULL;
    deque->size = 0;
}

void deque_ll_destroy(DequeLL *deque)
{
    assert(deque != NULL);
    if (deque->size == 0)
    {
        return;
    }
    DequeLLNode *c = deque->front;
    while (c != NULL)
    {
        DequeLLNode *tmp = c;
        c = c->next;
        free(tmp);
    }
    deque->front = NULL;
    deque->back = NULL;
    deque->size = 0;
}
size_t deque_ll_size(const DequeLL *deque)
{
    assert(deque != NULL);
    return deque->size;
}
bool deque_ll_is_empty(const DequeLL *deque)
{
    assert(deque != NULL);
    return deque->size == 0;
}
bool deque_ll_push_front(DequeLL *deque, deque_ll_value_t value)
{
    assert(deque != NULL);
    DequeLLNode *new = malloc(sizeof(DequeLLNode));
    if (new == NULL)
    {
        return false;
    }
    new->value = value;
    new->prev = NULL;
    new->next = deque->front;

    if (deque->front != NULL)
    {

        deque->front->prev = new;
    }
    else
    {
        deque->back = new;
    }
    deque->front = new;
    deque->size += 1;
    return true;
}
bool deque_ll_push_back(DequeLL *deque, deque_ll_value_t value)
{
    assert(deque != NULL);
    DequeLLNode *new = malloc(sizeof(DequeLLNode));
    if (new == NULL)
    {
        return false;
    }
    new->value = value;
    new->next = NULL;
    new->prev = deque->back;

    if (deque->back != NULL)
    {
        deque->back->next = new;
    }
    else
    {
        deque->front = new;
    }
    deque->back = new;
    deque->size += 1;
    return true;
}
bool deque_ll_pop_front(DequeLL *deque, deque_ll_value_t *out_value)
{
    assert(deque != NULL);
    assert(out_value != NULL);
    if (deque->size == 0)
    {
        return false;
    }
    DequeLLNode *c = deque->front;
    *out_value = c->value;
    deque->front = c->next;
    free(c);
    deque->size -= 1;
    if (deque->size == 0)
    {
        deque->back = NULL;
    }
    else
    {
        deque->front->prev = NULL;
    }
    return true;
}
bool deque_ll_pop_back(DequeLL *deque, deque_ll_value_t *out_value)
{
    assert(deque != NULL);
    assert(out_value != NULL);
    if (deque->size == 0)
    {
        return false;
    }
    DequeLLNode *c = deque->back;
    *out_value = c->value;
    deque->back = c->prev;
    free(c);
    deque->size -= 1;
    if (deque->size == 0)
    {
        deque->front = NULL;
    }
    else
    {
        deque->back->next = NULL;
    }
    return true;
}
bool deque_ll_front(const DequeLL *deque, deque_ll_value_t *out_value)
{
    assert(deque != NULL);
    assert(out_value != NULL);
    if (deque->size == 0)
    {
        return false;
    }
    *out_value = deque->front->value;
    return true;
}
bool deque_ll_back(const DequeLL *deque, deque_ll_value_t *out_value)
{
    assert(deque != NULL);
    assert(out_value != NULL);
    if (deque->size == 0)
    {
        return false;
    }
    *out_value = deque->back->value;
    return true;
}
void deque_ll_clear(DequeLL *deque)
{
    assert(deque != NULL);
    if (deque->size == 0)
    {
        return;
    }
    DequeLLNode *c = deque->front;
    while (c != NULL)
    {
        DequeLLNode *tmp = c;
        c = c->next;
        free(tmp);
    }
    deque->front = NULL;
    deque->back = NULL;
    deque->size = 0;
}
