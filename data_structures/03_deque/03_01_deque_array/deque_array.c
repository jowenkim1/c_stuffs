#include <assert.h>
#include "deque_array.h"

void deque_array_init(DequeArray *deque)
{
    assert(deque != NULL);
    deque->head = 0;
    deque->tail = 0;
    deque->size = 0;
}
size_t deque_array_size(const DequeArray *deque)
{
    assert(deque != NULL);
    return deque->size;
}
size_t deque_array_capacity(const DequeArray *deque)
{
    assert(deque != NULL);
    return DEQUE_ARRAY_CAPACITY;
}
bool deque_array_is_empty(const DequeArray *deque)
{
    assert(deque != NULL);
    return deque->size == 0;
}
bool deque_array_is_full(const DequeArray *deque)
{
    assert(deque != NULL);
    return deque->size == DEQUE_ARRAY_CAPACITY;
}
bool deque_array_push_front(DequeArray *deque, deque_array_value_t value)
{
    assert(deque != NULL);
    if (deque->size == DEQUE_ARRAY_CAPACITY)
    {
        return false;
    }
    deque->data[deque->head] = value;
    deque->head = (deque->head - 1 + DEQUE_ARRAY_CAPACITY) % DEQUE_ARRAY_CAPACITY;
    deque->size += 1;
    return true;
}
bool deque_array_push_back(DequeArray *deque, deque_array_value_t value)
{
    assert(deque != NULL);
    if (deque->size == DEQUE_ARRAY_CAPACITY)
    {
        return false;
    }
    deque->tail = (deque->tail + 1) % DEQUE_ARRAY_CAPACITY;
    deque->data[deque->tail] = value;
    deque->size += 1;
    return true;
}
bool deque_array_pop_front(DequeArray *deque, deque_array_value_t *out_value)
{
    assert(deque != NULL);
    if (deque->size == 0)
    {
        return false;
    }
    deque->head = (deque->head + 1) % DEQUE_ARRAY_CAPACITY;
    *out_value = deque->data[deque->head];
    deque->size -= 1;
    return true;
}
bool deque_array_pop_back(DequeArray *deque, deque_array_value_t *out_value)
{
    assert(deque != NULL);
    assert(out_value != NULL);
    if (deque->size == 0)
    {
        return false;
    }
    *out_value = deque->data[deque->tail];
    deque->tail = (deque->tail - 1 + DEQUE_ARRAY_CAPACITY) % DEQUE_ARRAY_CAPACITY;
    deque->size -= 1;
    return true;
}
bool deque_array_front(const DequeArray *deque, deque_array_value_t *out_value)
{
    assert(deque != NULL);
    assert(out_value != NULL);
    if (deque->size == 0)
    {
        return false;
    }
    *out_value = deque->data[(deque->head + 1) % DEQUE_ARRAY_CAPACITY];
    return true;
}
bool deque_array_back(const DequeArray *deque, deque_array_value_t *out_value)
{
    assert(deque != NULL);
    assert(out_value != NULL);
    if (deque->size == 0)
    {
        return false;
    }
    *out_value = deque->data[deque->tail];
    return true;
}
void deque_array_clear(DequeArray *deque)
{
    assert(deque != NULL);
    deque->head = 0;
    deque->tail = 0;
    deque->size = 0;
}
