#include <assert.h>
#include <stdlib.h>
#include "vector.h"

bool vector_init(Vector *vec, size_t capacity)
{
    if (vec == NULL || capacity == 0)
    {
        return false;
    }
    vec->data = malloc(sizeof(vector_value_t) * capacity);
    if (vec->data == NULL)
    {
        return false;
    }
    vec->capacity = capacity;
    vec->size = 0;
    return true;
}
void vector_destroy(Vector *vec)
{
    if (vec == NULL)
    {
        return;
    }
    free(vec->data);
    vec->data = NULL;
    vec->capacity = 0;
    vec->size = 0;
}
size_t vector_size(const Vector *vec)
{
    assert(vec != NULL);
    return vec->size;
}
size_t vector_capacity(const Vector *vec)
{
    assert(vec != NULL);
    return vec->capacity;
}
bool vector_is_empty(const Vector *vec)
{
    assert(vec != NULL);
    return vec->size == 0;
}
bool vector_get(const Vector *vec, size_t index, vector_value_t *out_value)
{
    if (vec == NULL || vec->size <= index || out_value == NULL)
    {
        return false;
    }
    *out_value = vec->data[index];
    return true;
}

bool vector_set(Vector *vec, size_t index, vector_value_t value)
{
    if (vec == NULL || vec->size <= index)
    {
        return false;
    }
    vec->data[index] = value;
    return true;
}
bool vector_front(const Vector *vec, vector_value_t *out_value)
{
    if (vec == NULL || vec->size == 0 || out_value == NULL)
    {
        return false;
    }
    *out_value = vec->data[0];
    return true;
}
bool vector_back(const Vector *vec, vector_value_t *out_value)
{
    if (vec == NULL || vec->size == 0 || out_value == NULL)
    {
        return false;
    }
    *out_value = vec->data[vec->size - 1];
    return true;
}
bool vector_push_back(Vector *vec, vector_value_t value)
{
    if (vec == NULL)
    {
        return false;
    }
    if (vec->size == vec->capacity)
    {
        vector_value_t *p = realloc(vec->data, sizeof(vector_value_t) * vec->capacity * 2);
        if (p == NULL)
        {
            return false;
        }
        vec->data = p;
        vec->capacity *= 2;
    }
    vec->data[vec->size++] = value;
    return true;
}
bool vector_pop_back(Vector *vec, vector_value_t *out_value)
{
    if (vec == NULL || vec->size == 0 || out_value == NULL)
    {
        return false;
    }
    *out_value = vec->data[--vec->size];
    return true;
}
bool vector_insert(Vector *vec, size_t index, vector_value_t value)
{
    if (vec == NULL)
    {
        return false;
    }
    if (vec->size == vec->capacity)
    {
        vector_value_t *p = realloc(vec->data, sizeof(vector_value_t) * vec->capacity * 2);
        if (p == NULL)
        {
            return false;
        }
        vec->data = p;
        vec->capacity *= 2;
    }

    if (vec->size <= index)
    {
        vec->data[vec->size++] = value;
        return true;
    }
    else
    {
        for (size_t i = vec->size; index < i; i--)
        {
            vec->data[i] = vec->data[i - 1];
        }
        vec->data[index] = value;
        vec->size += 1;
        return true;
    }
}
bool vector_remove(Vector *vec, size_t index, vector_value_t *out_value)
{
    if (vec == NULL || vec->size <= index || out_value == NULL)
    {
        return false;
    }
    *out_value = vec->data[index];
    for (size_t i = index; i < vec->size - 1; i++)
    {
        vec->data[i] = vec->data[i + 1];
    }
    vec->size -= 1;
    return true;
}
bool vector_reserve(Vector *vec, size_t new_capacity)
{
    if (vec == NULL || new_capacity <= vec->capacity)
    {
        return false;
    }
    vector_value_t *p = realloc(vec->data, sizeof(vector_value_t) * new_capacity);
    if (p == NULL)
    {
        return false;
    }
    vec->data = p;
    vec->capacity = new_capacity;
    return true;
}
void vector_clear(Vector *vec)
{
    if (vec == NULL)
    {
        return;
    }
    vec->size = 0;
}
