#include <assert.h>
#include <stdlib.h>
#include "singly_ll.h"

void singly_ll_init(SinglyLL *list)
{
    assert(list != NULL);
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
void singly_ll_destroy(SinglyLL *list)
{
    assert(list != NULL);
    SinglyLLNode *c = list->head;
    while (c != NULL)
    {
        SinglyLLNode *tmp = c;
        c = c->next;
        free(tmp);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
size_t singly_ll_size(const SinglyLL *list)
{
    assert(list != NULL);
    return list->size;
}
bool singly_ll_is_empty(const SinglyLL *list)
{
    assert(list != NULL);
    return list->size == 0;
}
bool singly_ll_front(const SinglyLL *list, singly_ll_value_t *out_value)
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
bool singly_ll_back(const SinglyLL *list, singly_ll_value_t *out_value)
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
bool singly_ll_push_front(SinglyLL *list, singly_ll_value_t value)
{
    assert(list != NULL);
    SinglyLLNode *new = malloc(sizeof(SinglyLLNode));
    if (new == NULL)
    {
        return false;
    }
    new->value = value;
    if (list->size == 0)
    {
        new->next = NULL;
        list->head = new;
        list->tail = new;
    }
    else
    {
        new->next = list->head;
        list->head = new;
    }
    list->size += 1;
    return true;
}
bool singly_ll_push_back(SinglyLL *list, singly_ll_value_t value)
{
    assert(list != NULL);
    SinglyLLNode *new = malloc(sizeof(SinglyLLNode));
    if (new == NULL)
    {
        return false;
    }
    new->next = NULL;
    new->value = value;
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
bool singly_ll_pop_front(SinglyLL *list, singly_ll_value_t *out_value)
{
    assert(list != NULL);
    assert(out_value != NULL);
    if (list->size == 0)
    {
        return false;
    }
    SinglyLLNode *c = list->head;
    *out_value = c->value;
    list->head = c->next;
    free(c);

    list->size -= 1;
    if (list->size == 0)
    {
        list->tail = NULL;
    }
    return true;
}
bool singly_ll_pop_back(SinglyLL *list, singly_ll_value_t *out_value)
{
    assert(list != NULL);
    assert(out_value != NULL);
    if (list->size == 0)
    {
        return false;
    }
    SinglyLLNode *c = list->head;
    list->size -= 1;
    if (c->next == NULL)
    {
        *out_value = c->value;
        free(c);
        list->head = NULL;
        list->tail = NULL;
        return true;
    }
    else
    {
        while (c->next->next != NULL)
        {
            c = c->next;
        }
        SinglyLLNode *tmp = c->next;
        *out_value = tmp->value;
        free(tmp);
        c->next = NULL;
        list->tail = c;
        return true;
    }
}
bool singly_ll_insert_at(SinglyLL *list, size_t index, singly_ll_value_t value)
{
    assert(list != NULL);
    if (list->size < index)
    {
        return false;
    }

    if (index == 0)
    {
        return singly_ll_push_front(list, value);
    }
    if (index == list->size)
    {
        return singly_ll_push_back(list, value);
    }

    SinglyLLNode *new = malloc(sizeof(SinglyLLNode));
    if (new == NULL)
    {
        return false;
    }
    new->value = value;
    SinglyLLNode *c = list->head;
    for (size_t i = 0; i < index - 1; i++)
    {
        c = c->next;
    }
    new->next = c->next;
    c->next = new;

    list->size += 1;
    return true;
}
bool singly_ll_remove_at(SinglyLL *list, size_t index, singly_ll_value_t *out_value)
{
    assert(list != NULL);
    assert(out_value != NULL);
    if (list->size <= index)
    {
        return false;
    }
    SinglyLLNode *c = list->head;
    if (index == 0)
    {
        list->head = c->next;
        *out_value = c->value;

        if (list->size == 1)
        {
            list->tail = NULL;
        }

        free(c);
    }
    else
    {

        for (size_t i = 0; i < index - 1; i++)
        {
            c = c->next;
        }

        SinglyLLNode *tmp = c->next;
        *out_value = tmp->value;
        c->next = tmp->next;

        if (tmp == list->tail)
        {
            list->tail = c;
        }

        free(tmp);
    }
    list->size -= 1;
    return true;
}
bool singly_ll_get_at(const SinglyLL *list, size_t index, singly_ll_value_t *out_value)
{
    assert(list != NULL);
    assert(out_value != NULL);
    if (list->size <= index)
    {
        return false;
    }
    SinglyLLNode *c = list->head;
    for (size_t i = 0; i < index; i++)
    {
        c = c->next;
    }
    *out_value = c->value;
    return true;
}
bool singly_ll_set_at(SinglyLL *list, size_t index, singly_ll_value_t value)
{
    assert(list != NULL);
    if (list->size <= index)
    {
        return false;
    }
    SinglyLLNode *c = list->head;
    for (size_t i = 0; i < index; i++)
    {
        c = c->next;
    }
    c->value = value;
    return true;
}
void singly_ll_clear(SinglyLL *list)
{
    assert(list != NULL);
    SinglyLLNode *c = list->head;
    while (c != NULL)
    {
        SinglyLLNode *tmp = c;
        c = c->next;
        free(tmp);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
