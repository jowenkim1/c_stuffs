#ifndef SINGLY_LL_H
#define SINGLY_LL_H

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

typedef int singly_ll_value_t;

typedef struct SinglyLLNode {
  singly_ll_value_t value;
  struct SinglyLLNode *next;
} SinglyLLNode;

typedef struct {
  SinglyLLNode *head;
  SinglyLLNode *tail;
  size_t size;
} SinglyLL;

void singly_ll_init(SinglyLL *list);
void singly_ll_destroy(SinglyLL *list);
size_t singly_ll_size(const SinglyLL *list);
int singly_ll_is_empty(const SinglyLL *list);
int singly_ll_front(const SinglyLL *list, singly_ll_value_t *out_value);
int singly_ll_back(const SinglyLL *list, singly_ll_value_t *out_value);
int singly_ll_push_front(SinglyLL *list, singly_ll_value_t value);
int singly_ll_push_back(SinglyLL *list, singly_ll_value_t value);
int singly_ll_pop_front(SinglyLL *list, singly_ll_value_t *out_value);
int singly_ll_pop_back(SinglyLL *list, singly_ll_value_t *out_value);
int singly_ll_insert_at(SinglyLL *list, size_t index, singly_ll_value_t value);
int singly_ll_remove_at(SinglyLL *list, size_t index, singly_ll_value_t *out_value);
int singly_ll_get_at(const SinglyLL *list, size_t index, singly_ll_value_t *out_value);
int singly_ll_set_at(SinglyLL *list, size_t index, singly_ll_value_t value);
void singly_ll_clear(SinglyLL *list);

#endif
