#include <assert.h>
#include <stdlib.h>
#include "doubly_ll.h"

void doubly_ll_init(DoublyLL *list)
{
    assert(list != NULL);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
void doubly_ll_destroy(DoublyLL *list)
{
    assert(list != NULL);
    DoublyLLNode *c = list->head;
    while (c != NULL)
    {
        DoublyLLNode *tmp = c;
        c = c->next;
        free(tmp);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
size_t doubly_ll_size(const DoublyLL *list)
{
    assert(list != NULL);
    return list->size;
}
bool doubly_ll_is_empty(const DoublyLL *list)
{
    assert(list != NULL);
    return list->size == 0;
}
bool doubly_ll_front(const DoublyLL *list, doubly_ll_value_t *out_value)
{
    assert(list != NULL);
    assert(out_value != NULL);
    if (list->size == 0)
    {
        return false;
    }
    *out_value = list->head->value;
    return true;
}
bool doubly_ll_back(const DoublyLL *list, doubly_ll_value_t *out_value)
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
bool doubly_ll_push_front(DoublyLL *list, doubly_ll_value_t value)
{
    assert(list != NULL);
    DoublyLLNode *new = malloc(sizeof(DoublyLLNode));
    if (new == NULL)
    {
        return false;
    }
    new->value = value;
    new->next = list->head;
    new->prev = NULL;

    if (list->size == 0)
    {
        list->head = new;
        list->tail = new;
    }
    else
    {
        list->head->prev = new;
        list->head = new;
    }
    list->size += 1;
    return true;
}
bool doubly_ll_push_back(DoublyLL *list, doubly_ll_value_t value)
{
    assert(list != NULL);
    DoublyLLNode *new = malloc(sizeof(DoublyLLNode));
    if (new == NULL)
    {
        return false;
    }
    new->value = value;
    new->next = NULL;
    new->prev = list->tail;

    if (list->size == 0)
    {
        list->head = new;
        list->tail = new;
    }
    else
    {
        list->tail->next = new;
        list->tail = new;
    }
    list->size += 1;
    return true;
}

bool doubly_ll_pop_front(DoublyLL *list, doubly_ll_value_t *out_value)
{
    assert(list != NULL);
    assert(out_value != NULL);
    if (list->size == 0)
    {
        return false;
    }
    DoublyLLNode *c = list->head;
    *out_value = c->value;
    list->head = c->next;
    free(c);
    if (list->head == NULL)
    {
        list->tail = NULL;
    }
    else
    {
        list->head->prev = NULL;
    }
    list->size -= 1;
    return true;
}
bool doubly_ll_pop_back(DoublyLL *list, doubly_ll_value_t *out_value)
{
    assert(list != NULL);
    assert(out_value != NULL);
    if (list->size == 0)
    {
        return false;
    }
    DoublyLLNode *c = list->tail;
    *out_value = c->value;
    list->tail = c->prev;
    free(c);
    if (list->tail == NULL)
    {
        list->head = NULL;
    }
    else
    {
        list->tail->next = NULL;
    }
    list->size -= 1;
    return true;
}

bool doubly_ll_insert_at(DoublyLL *list, size_t index, doubly_ll_value_t value)
{
    assert(list != NULL);
    if (list->size < index)
    {
        return false;
    }

    if (index == 0)
    {
        return doubly_ll_push_front(list, value);
    }

    if (index == list->size)
    {
        return doubly_ll_push_back(list, value);
    }
    DoublyLLNode *new = malloc(sizeof(DoublyLLNode));
    if (new == NULL)
    {
        return false;
    }
    new->value = value;
    DoublyLLNode *c = list->head;
    for (size_t i = 0; i < index - 1; i++)
    {
        c = c->next;
    }
    DoublyLLNode *next = c->next;
    new->prev = c;
    new->next = next;
    c->next = new;
    next->prev = new;

    list->size += 1;
    return true;
}
bool doubly_ll_remove_at(DoublyLL *list, size_t index, doubly_ll_value_t *out_value)
{
    assert(list != NULL);
    assert(out_value != NULL);
    if (list->size <= index)
    {
        return false;
    }
    if (index == 0)
    {
        return doubly_ll_pop_front(list, out_value);
    }
    if (index == list->size - 1)
    {
        return doubly_ll_pop_back(list, out_value);
    }

    DoublyLLNode *c = list->head;
    for (size_t i = 0; i < index - 1; i++)
    {
        c = c->next;
    }
    DoublyLLNode *tmp = c->next;
    *out_value = tmp->value;
    c->next = tmp->next;
    tmp->next->prev = c;
    free(tmp);
    list->size -= 1;
    return true;
}
bool doubly_ll_get_at(const DoublyLL *list, size_t index, doubly_ll_value_t *out_value)
{
    assert(list != NULL);
    assert(out_value != NULL);
    if (list->size <= index)
    {
        return false;
    }
    DoublyLLNode *c = list->head;
    for (size_t i = 0; i < index; i++)
    {
        c = c->next;
    }
    *out_value = c->value;
    return true;
}
bool doubly_ll_set_at(DoublyLL *list, size_t index, doubly_ll_value_t value)
{
    assert(list != NULL);
    if (list->size <= index)
    {
        return false;
    }
    DoublyLLNode *c = list->head;
    for (size_t i = 0; i < index; i++)
    {
        c = c->next;
    }
    c->value = value;
    return true;
}
void doubly_ll_clear(DoublyLL *list)
{
    doubly_ll_destroy(list);
}
