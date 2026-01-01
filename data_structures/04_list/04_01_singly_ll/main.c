#include <stdio.h>

#include "singly_ll.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

int main(void) {
  SinglyLL list;
  singly_ll_init(&list);

  CHECK(singly_ll_size(&list) == 0, "init size");
  CHECK(singly_ll_is_empty(&list) == true, "init empty");

  singly_ll_value_t value = 0;
  CHECK(!singly_ll_front(&list, &value), "front empty");
  CHECK(!singly_ll_back(&list, &value), "back empty");
  CHECK(!singly_ll_pop_front(&list, &value), "pop front empty");
  CHECK(!singly_ll_pop_back(&list, &value), "pop back empty");
  CHECK(!singly_ll_get_at(&list, 0, &value), "get invalid");

  CHECK(singly_ll_push_back(&list, 1), "push back 1");
  CHECK(singly_ll_push_back(&list, 2), "push back 2");
  CHECK(singly_ll_push_front(&list, 0), "push front 0");
  CHECK(singly_ll_insert_at(&list, 2, 99), "insert");

  CHECK(singly_ll_front(&list, &value) && value == 0, "front value");
  CHECK(singly_ll_back(&list, &value) && value == 2, "back value");
  CHECK(singly_ll_get_at(&list, 2, &value) && value == 99, "get after insert");

  CHECK(singly_ll_set_at(&list, 1, 7), "set");
  CHECK(singly_ll_get_at(&list, 1, &value) && value == 7, "get after set");

  CHECK(singly_ll_remove_at(&list, 2, &value) && value == 99, "remove");
  CHECK(singly_ll_pop_front(&list, &value) && value == 0, "pop front");
  CHECK(singly_ll_pop_back(&list, &value) && value == 2, "pop back");

  CHECK(!singly_ll_insert_at(&list, 99, 1), "insert invalid");
  CHECK(!singly_ll_remove_at(&list, 99, &value), "remove invalid");

  singly_ll_clear(&list);
  CHECK(singly_ll_is_empty(&list) == true, "clear empty");

  singly_ll_destroy(&list);
  printf("singly_ll ok\n");
  return 0;
}
