#include <assert.h>
#include "stack_array.h"

void stack_array_init(StackArray *stack)
{
    if (stack == NULL)
    {
        return;
    }
    stack->size = 0;
}
size_t stack_array_size(const StackArray *stack)
{
    assert(stack != NULL);
    return stack->size;
}
size_t stack_array_capacity(const StackArray *stack)
{
    assert(stack != NULL);
    return STACK_ARRAY_CAPACITY;
}
bool stack_array_is_empty(const StackArray *stack)
{
    assert(stack != NULL);
    return stack->size == 0;
}
bool stack_array_is_full(const StackArray *stack)
{
    assert(stack != NULL);
    return stack->size == STACK_ARRAY_CAPACITY;
}
bool stack_array_push(StackArray *stack, stack_array_value_t value)
{
    if (stack == NULL || stack->size == STACK_ARRAY_CAPACITY)
    {
        return false;
    }
    stack->data[stack->size++] = value;
    return true;
}
bool stack_array_pop(StackArray *stack, stack_array_value_t *out_value)
{
    if (stack == NULL || stack->size == 0 || out_value == NULL)
    {
        return false;
    }
    *out_value = stack->data[--stack->size];
    return true;
}
bool stack_array_peek(const StackArray *stack, stack_array_value_t *out_value)
{
    if (stack == NULL || stack->size == 0 || out_value == NULL)
    {
        return false;
    }
    *out_value = stack->data[stack->size - 1];
    return true;
}
void stack_array_clear(StackArray *stack)
{
    if (stack == NULL)
    {
        return;
    }
    stack->size = 0;
}
