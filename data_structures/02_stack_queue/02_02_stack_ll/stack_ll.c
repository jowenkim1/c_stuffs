#include <assert.h>
#include <stdlib.h>
#include "stack_ll.h"

void stack_ll_init(StackLL *stack)
{
    if (stack == NULL)
    {
        return;
    }
    stack->top = NULL;
    stack->size = 0;
}
void stack_ll_destroy(StackLL *stack)
{
    if (stack == NULL)
    {
        return;
    }
    StackLLNode *c = stack->top;
    while (c != NULL)
    {
        StackLLNode *tmp = c;
        c = c->next;
        free(tmp);
    }
    stack->top = NULL;
    stack->size = 0;
}
size_t stack_ll_size(const StackLL *stack)
{
    assert(stack != NULL);
    return stack->size;
}
bool stack_ll_is_empty(const StackLL *stack)
{
    assert(stack != NULL);
    return stack->size == 0;
}
bool stack_ll_push(StackLL *stack, stack_ll_value_t value)
{
    assert(stack != NULL);
    StackLLNode *new = malloc(sizeof(StackLLNode));
    if (new == NULL)
    {
        return false;
    }
    new->value = value;
    new->next = stack->top;
    stack->top = new;
    stack->size += 1;
    return true;
}
bool stack_ll_pop(StackLL *stack, stack_ll_value_t *out_value)
{
    assert(stack != NULL);
    assert(out_value != NULL);
    StackLLNode *c = stack->top;
    if (c == NULL)
    {
        return false;
    }

    stack->top = c->next;
    *out_value = c->value;
    free(c);
    stack->size -= 1;
    return true;
}
bool stack_ll_peek(const StackLL *stack, stack_ll_value_t *out_value)
{
    assert(stack != NULL);
    assert(out_value != NULL);
    StackLLNode *c = stack->top;
    if (c == NULL)
    {
        return false;
    }
    else
    {
        *out_value = c->value;
        return true;
    }
}
void stack_ll_clear(StackLL *stack)
{
    assert(stack != NULL);
    StackLLNode *c = stack->top;
    while (c != NULL)
    {
        StackLLNode *tmp = c;
        c = c->next;
        free(tmp);
    }
    stack->top = NULL;
    stack->size = 0;
}