#include <assert.h>
#include <stdlib.h>
#include "heap.h"

bool heap_init(BinaryHeap *heap, size_t capacity)
{
    if (heap == NULL)
    {
        return false;
    }
    heap->data = malloc(sizeof(heap_value_t) * capacity);
    if (heap->data == NULL)
    {
        return false;
    }
    heap->capacity = capacity;
    heap->size = 0;
    return true;
}

void heap_destroy(BinaryHeap *heap)
{
    if (heap == NULL)
    {
        return;
    }
    free(heap->data);
    heap->data = NULL;
    heap->capacity = 0;
    heap->size = 0;
}

size_t heap_size(const BinaryHeap *heap)
{
    assert(heap != NULL);
    return heap->size;
}

size_t heap_capacity(const BinaryHeap *heap)
{
    assert(heap != NULL);
    return heap->capacity;
}

bool heap_is_empty(const BinaryHeap *heap)
{
    assert(heap != NULL);
    return heap->size == 0;
}

bool heap_peek(const BinaryHeap *heap, heap_value_t *out_value)
{
    if (heap == NULL || heap->size == 0 || out_value == NULL)
    {
        return false;
    }
    *out_value = heap->data[0];
    return true;
}

bool heap_push(BinaryHeap *heap, heap_value_t value)
{
    if (heap == NULL || heap->size == heap->capacity)
    {
        return false;
    }
    heap->data[heap->size] = value;

    int idx = heap->size;
    while (0 < idx)
    {
        size_t parent = (idx - 1) / 2;
        if (heap->data[parent] <= heap->data[idx])
        {
            break;
        }
        heap_value_t tmp = heap->data[parent];
        heap->data[parent] = heap->data[idx];
        heap->data[idx] = tmp;

        idx = parent;
    }

    heap->size += 1;
    return true;
}
bool heap_pop(BinaryHeap *heap, heap_value_t *out_value)
{
    if (heap == NULL || heap->size == 0 || out_value == NULL)
    {
        return false;
    }
    *out_value = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size -= 1;

    size_t idx = 0;
    while (1)
    {
        size_t left = idx * 2 + 1;
        size_t right = idx * 2 + 2;
        size_t smallest = idx;

        if (left < heap->size &&
            heap->data[left] < heap->data[smallest])
        {
            smallest = left;
        }
        if (right < heap->size &&
            heap->data[right] < heap->data[smallest])
        {
            smallest = right;
        }
        if (smallest == idx)
        {
            break;
        }

        heap_value_t tmp = heap->data[idx];
        heap->data[idx] = heap->data[smallest];
        heap->data[smallest] = tmp;

        idx = smallest;
    }
    return true;
}
bool heap_reserve(BinaryHeap *heap, size_t new_capacity)
{
    if (heap == NULL)
    {
        return false;
    }
    if (new_capacity <= heap->capacity)
    {
        return true;
    }
    heap_value_t *tmp = realloc(heap->data, sizeof(heap_value_t) * new_capacity);
    if (tmp == NULL)
    {
        return false;
    }
    heap->data = tmp;
    heap->capacity = new_capacity;
    return true;
}
void heap_clear(BinaryHeap *heap)
{
    if (heap == NULL)
        return;
    heap->size = 0;
}
