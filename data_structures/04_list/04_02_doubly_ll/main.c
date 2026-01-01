#include <stdio.h>

#include "doubly_ll.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

int main(void) {
  DoublyLL list;
  doubly_ll_init(&list);

  CHECK(doubly_ll_size(&list) == 0, "init size");
  CHECK(doubly_ll_is_empty(&list) == true, "init empty");

  doubly_ll_value_t value = 0;
  CHECK(!doubly_ll_front(&list, &value), "front empty");
  CHECK(!doubly_ll_back(&list, &value), "back empty");
  CHECK(!doubly_ll_pop_front(&list, &value), "pop front empty");
  CHECK(!doubly_ll_pop_back(&list, &value), "pop back empty");
  CHECK(!doubly_ll_get_at(&list, 0, &value), "get invalid");

  CHECK(doubly_ll_push_back(&list, 1), "push back 1");
  CHECK(doubly_ll_push_back(&list, 2), "push back 2");
  CHECK(doubly_ll_push_front(&list, 0), "push front 0");
  CHECK(doubly_ll_insert_at(&list, 2, 99), "insert");

  CHECK(doubly_ll_front(&list, &value) && value == 0, "front value");
  CHECK(doubly_ll_back(&list, &value) && value == 2, "back value");
  CHECK(doubly_ll_get_at(&list, 2, &value) && value == 99, "get after insert");

  CHECK(doubly_ll_set_at(&list, 1, 7), "set");
  CHECK(doubly_ll_get_at(&list, 1, &value) && value == 7, "get after set");

  CHECK(doubly_ll_remove_at(&list, 2, &value) && value == 99, "remove");
  CHECK(doubly_ll_pop_front(&list, &value) && value == 0, "pop front");
  CHECK(doubly_ll_pop_back(&list, &value) && value == 2, "pop back");

  CHECK(!doubly_ll_insert_at(&list, 99, 1), "insert invalid");
  CHECK(!doubly_ll_remove_at(&list, 99, &value), "remove invalid");

  doubly_ll_clear(&list);
  CHECK(doubly_ll_is_empty(&list) == true, "clear empty");

  doubly_ll_destroy(&list);
  printf("doubly_ll ok\n");
  return 0;
}
