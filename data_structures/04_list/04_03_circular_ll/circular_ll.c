#include <assert.h>
#include <stdlib.h>
#include "circular_ll.h"

void circular_ll_init(CircularLL *list)
{
    assert(list != NULL);
    list->tail = NULL;
    list->size = 0;
}
void circular_ll_destroy(CircularLL *list)
{
    assert(list != NULL);
    if (list->size == 0)
    {
        return;
    }
    CircularLLNode *c = list->tail->next;
    while (c != list->tail)
    {
        CircularLLNode *tmp = c;
        c = c->next;
        free(tmp);
    }
    free(list->tail);
    list->tail = NULL;
    list->size = 0;
}
size_t circular_ll_size(const CircularLL *list)
{
    assert(list != NULL);
    return list->size;
}
bool circular_ll_is_empty(const CircularLL *list)
{
    assert(list != NULL);
    return list->size == 0;
}
bool circular_ll_front(const CircularLL *list, circular_ll_value_t *out_value)
{
    assert(list != NULL);
    assert(out_value != NULL);
    if (list->size == 0)
    {
        return false;
    }
    *out_value = list->tail->next->value;
    return true;
}
bool circular_ll_back(const CircularLL *list, circular_ll_value_t *out_value)
{
    assert(list != NULL);
    assert(out_value != NULL);
    if (list->size == 0)
    {
        return false;
    }
    *out_value = list->tail->value;
    return true;
}
bool circular_ll_push_front(CircularLL *list, circular_ll_value_t value)
{
    assert(list != NULL);
    CircularLLNode *new = malloc(sizeof(*new));
    if (new == NULL)
    {
        return false;
    }
    new->value = value;

    if (list->tail == NULL)
    {
        new->next = new;
        list->tail = new;
    }
    else
    {
        new->next = list->tail->next;
        list->tail->next = new;
    }
    list->size += 1;
    return true;
}
bool circular_ll_push_back(CircularLL *list, circular_ll_value_t value)
{
    assert(list != NULL);
    CircularLLNode *new = malloc(sizeof(*new));
    if (new == NULL)
    {
        return false;
    }
    new->value = value;

    if (list->tail == NULL)
    {
        new->next = new;
        list->tail = new;
    }
    else
    {
        new->next = list->tail->next;
        list->tail->next = new;
        list->tail = new;
    }
    list->size += 1;
    return true;
}
bool circular_ll_pop_front(CircularLL *list, circular_ll_value_t *out_value)
{
    assert(list != NULL);
    assert(out_value != NULL);
    if (list->size == 0)
    {
        return false;
    }
    if (list->size == 1)
    {
        *out_value = list->tail->value;
        free(list->tail);
        list->tail = NULL;
    }
    else
    {
        CircularLLNode *tmp = list->tail->next;
        *out_value = tmp->value;
        list->tail->next = tmp->next;
        free(tmp);
    }
    list->size -= 1;
    return true;
}
bool circular_ll_pop_back(CircularLL *list, circular_ll_value_t *out_value)
{
    assert(list != NULL);
    assert(out_value != NULL);
    if (list->size == 0)
    {
        return false;
    }
    if (list->size == 1)
    {
        *out_value = list->tail->value;
        free(list->tail);
        list->tail = NULL;
    }
    else
    {
        CircularLLNode *c = list->tail->next;
        while (c->next != list->tail)
        {
            c = c->next;
        }
        CircularLLNode *t = c->next;
        *out_value = t->value;
        c->next = t->next;
        list->tail = c;
        free(t);
    }
    list->size -= 1;
    return true;
}
bool circular_ll_insert_at(CircularLL *list, size_t index, circular_ll_value_t value)
{
    assert(list != NULL);
    if (list->size < index)
    {
        return false;
    }
    CircularLLNode *new = malloc(sizeof(*new));
    if (new == NULL)
    {
        return false;
    }
    new->value = value;

    if (list->tail == NULL)
    {
        new->next = new;
        list->tail = new;
        list->size = 1;
        return true;
    }

    if (index == 0)
    {
        new->next = list->tail->next;
        list->tail->next = new;
        list->size += 1;
        return true;
    }

    CircularLLNode *prev = list->tail->next;
    for (size_t i = 1; i < index; i++)
    {
        prev = prev->next;
    }
    new->next = prev->next;
    prev->next = new;

    if (index == list->size)
    {
        list->tail = new;
    }
    list->size += 1;
    return true;
}
bool circular_ll_remove_at(CircularLL *list, size_t index, circular_ll_value_t *out_value)
{
    assert(list != NULL);
    assert(out_value != NULL);

    if (list->size == 0)
        return false;
    if (index >= list->size)
        return false;

    // case 1) size == 1 (index must be 0)
    if (list->size == 1)
    {
        *out_value = list->tail->value;
        free(list->tail);
        list->tail = NULL;
        list->size = 0;
        return true;
    }

    // case 2) remove front (index 0)
    if (index == 0)
    {
        CircularLLNode *head = list->tail->next;
        *out_value = head->value;

        list->tail->next = head->next; // skip head
        free(head);

        list->size -= 1;
        return true;
    }

    // case 3) remove middle or back
    CircularLLNode *prev = list->tail->next; // head
    for (size_t i = 1; i < index; i++)
    {
        prev = prev->next;
    }

    CircularLLNode *target = prev->next;
    *out_value = target->value;

    prev->next = target->next;

    // if removing tail, update tail
    if (target == list->tail)
    {
        list->tail = prev;
    }

    free(target);
    list->size -= 1;
    return true;
}

bool circular_ll_get_at(const CircularLL *list, size_t index, circular_ll_value_t *out_value)
{
    assert(list != NULL);
    assert(out_value != NULL);

    if (list->size == 0)
    {
        return false;
    }
    if (index >= list->size)
    {
        return false;
    }

    CircularLLNode *c = list->tail->next; // head
    for (size_t i = 0; i < index; i++)
    {
        c = c->next;
    }
    *out_value = c->value;
    return true;
}
bool circular_ll_set_at(CircularLL *list, size_t index, circular_ll_value_t value){
    assert(list != NULL);

    if (list->size == 0)
    {
        return false;
    }
    if (index >= list->size)
    {
        return false;
    }

    CircularLLNode *c = list->tail->next; // head
    for (size_t i = 0; i < index; i++)
    {
        c = c->next;
    }
    c->value = value;
    return true;
}
void circular_ll_clear(CircularLL *list){
    circular_ll_destroy(list);
}
