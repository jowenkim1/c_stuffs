#include <assert.h>
#include <stdlib.h>
#include "pq.h"

bool pq_init(PriorityQueue *pq, size_t capacity)
{
    if (pq == NULL || capacity == 0)
    {
        return false;
    }
    pq->data = malloc(sizeof(pq_value_t) * capacity);
    if (pq->data == NULL)
    {
        return false;
    }
    pq->capacity = capacity;
    pq->size = 0;
    return true;
}
void pq_destroy(PriorityQueue *pq)
{
    if (pq == NULL)
    {
        return;
    }
    free(pq->data);
    pq->data = NULL;
    pq->capacity = 0;
    pq->size = 0;
}

size_t pq_size(const PriorityQueue *pq)
{
    assert(pq != NULL);
    return pq->size;
}
size_t pq_capacity(const PriorityQueue *pq)
{
    assert(pq != NULL);
    return pq->capacity;
}
bool pq_is_empty(const PriorityQueue *pq)
{
    assert(pq != NULL);
    return pq->size == 0;
}

bool pq_peek(const PriorityQueue *pq, pq_value_t *out_value)
{
    if (pq == NULL || pq->size == 0 || out_value == NULL)
    {
        return false;
    }
    *out_value = pq->data[0];
    return true;
}

bool pq_push(PriorityQueue *pq, pq_value_t value)
{
    if (pq == NULL)
        return false;

    if (pq->size == pq->capacity)
    {
        size_t new_cap = (pq->capacity == 0) ? 1 : pq->capacity * 2;
        if (!pq_reserve(pq, new_cap))
            return false;
    }

    pq->data[pq->size] = value;

    size_t idx = pq->size;
    while (0 < idx)
    {
        size_t parent_idx = (idx - 1) / 2;
        int parent_value = pq->data[parent_idx];

        if (parent_value <= value)
        {
            break;
        }

        pq->data[idx] = parent_value;
        pq->data[parent_idx] = value;
        idx = parent_idx;
    }
    pq->size += 1;
    return true;
}
bool pq_pop(PriorityQueue *pq, pq_value_t *out_value)
{
    if (pq == NULL || pq->size == 0 || out_value == NULL)
    {
        return false;
    }

    *out_value = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size -= 1;

    size_t idx = 0;
    while (1)
    {
        size_t left_idx = (2 * idx + 1);
        size_t right_idx = (2 * idx + 2);
        size_t smallest_idx = idx;

        if (left_idx < pq->size &&
            pq->data[left_idx] < pq->data[smallest_idx])
        {
            smallest_idx = left_idx;
        }

        if (right_idx < pq->size &&
            pq->data[right_idx] < pq->data[smallest_idx])
        {
            smallest_idx = right_idx;
        }

        if (smallest_idx == idx)
        {
            break;
        }

        pq_value_t tmp = pq->data[idx];
        pq->data[idx] = pq->data[smallest_idx];
        pq->data[smallest_idx] = tmp;

        idx = smallest_idx;
    }
    return true;
}
bool pq_reserve(PriorityQueue *pq, size_t new_capacity)
{
    if (pq == NULL)
    {
        return false;
    }
    if (new_capacity <= pq->capacity)
    {
        return true;
    }
    pq_value_t *tmp = realloc(pq->data, sizeof(pq_value_t) * new_capacity);
    if (tmp == NULL)
    {
        return false;
    }
    pq->data = tmp;
    pq->capacity = new_capacity;
    return true;
}
void pq_clear(PriorityQueue *pq)
{
    if (pq == NULL)
        return;
    pq->size = 0;
}
