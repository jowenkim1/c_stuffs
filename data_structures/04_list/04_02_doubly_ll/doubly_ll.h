#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

#include <stddef.h>

#ifndef DS_STATUS_H
#define DS_STATUS_H
#define DS_OK 0
#define DS_ERR_INVALID -1
#define DS_ERR_EMPTY -2
#define DS_ERR_FULL -3
#define DS_ERR_NOMEM -4
#define DS_ERR_NOT_FOUND -5
#endif

/*
 * ADT conventions:
 * - Status functions return DS_OK on success, negative DS_ERR_* on failure.
 * - Boolean queries return 1 (true), 0 (false), or DS_ERR_INVALID for bad args.
 * - Indices are 0-based; insert allows index == size (append).
 * - out_value must be non-NULL; it is unchanged on failure.
 */

typedef int doubly_ll_value_t;

typedef struct DoublyLLNode {
  doubly_ll_value_t value;
  struct DoublyLLNode *prev;
  struct DoublyLLNode *next;
} DoublyLLNode;

typedef struct {
  DoublyLLNode *head;
  DoublyLLNode *tail;
  size_t size;
} DoublyLL;

void doubly_ll_init(DoublyLL *list);
void doubly_ll_destroy(DoublyLL *list);
size_t doubly_ll_size(const DoublyLL *list);
int doubly_ll_is_empty(const DoublyLL *list);
int doubly_ll_front(const DoublyLL *list, doubly_ll_value_t *out_value);
int doubly_ll_back(const DoublyLL *list, doubly_ll_value_t *out_value);
int doubly_ll_push_front(DoublyLL *list, doubly_ll_value_t value);
int doubly_ll_push_back(DoublyLL *list, doubly_ll_value_t value);
int doubly_ll_pop_front(DoublyLL *list, doubly_ll_value_t *out_value);
int doubly_ll_pop_back(DoublyLL *list, doubly_ll_value_t *out_value);
int doubly_ll_insert_at(DoublyLL *list, size_t index, doubly_ll_value_t value);
int doubly_ll_remove_at(DoublyLL *list, size_t index, doubly_ll_value_t *out_value);
int doubly_ll_get_at(const DoublyLL *list, size_t index, doubly_ll_value_t *out_value);
int doubly_ll_set_at(DoublyLL *list, size_t index, doubly_ll_value_t value);
void doubly_ll_clear(DoublyLL *list);

#endif
