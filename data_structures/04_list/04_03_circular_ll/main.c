#include <stdio.h>

#include "circular_ll.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

int main(void) {
  CircularLL list;
  circular_ll_init(&list);

  CHECK(circular_ll_size(&list) == 0, "init size");
  CHECK(circular_ll_is_empty(&list) == 1, "init empty");

  circular_ll_value_t value = 0;
  CHECK(circular_ll_front(&list, &value) == DS_ERR_EMPTY, "front empty");
  CHECK(circular_ll_back(&list, &value) == DS_ERR_EMPTY, "back empty");
  CHECK(circular_ll_pop_front(&list, &value) == DS_ERR_EMPTY, "pop front empty");
  CHECK(circular_ll_pop_back(&list, &value) == DS_ERR_EMPTY, "pop back empty");
  CHECK(circular_ll_get_at(&list, 0, &value) == DS_ERR_INVALID, "get invalid");

  CHECK(circular_ll_push_back(&list, 1) == DS_OK, "push back 1");
  CHECK(circular_ll_push_back(&list, 2) == DS_OK, "push back 2");
  CHECK(circular_ll_push_front(&list, 0) == DS_OK, "push front 0");
  CHECK(circular_ll_insert_at(&list, 2, 99) == DS_OK, "insert");

  CHECK(circular_ll_front(&list, &value) == DS_OK && value == 0, "front value");
  CHECK(circular_ll_back(&list, &value) == DS_OK && value == 2, "back value");
  CHECK(circular_ll_get_at(&list, 2, &value) == DS_OK && value == 99, "get after insert");

  CHECK(circular_ll_set_at(&list, 1, 7) == DS_OK, "set");
  CHECK(circular_ll_get_at(&list, 1, &value) == DS_OK && value == 7, "get after set");

  CHECK(circular_ll_remove_at(&list, 2, &value) == DS_OK && value == 99, "remove");
  CHECK(circular_ll_pop_front(&list, &value) == DS_OK && value == 0, "pop front");
  CHECK(circular_ll_pop_back(&list, &value) == DS_OK && value == 2, "pop back");

  CHECK(circular_ll_insert_at(&list, 99, 1) == DS_ERR_INVALID, "insert invalid");
  CHECK(circular_ll_remove_at(&list, 99, &value) == DS_ERR_INVALID, "remove invalid");

  circular_ll_clear(&list);
  CHECK(circular_ll_is_empty(&list) == 1, "clear empty");

  circular_ll_destroy(&list);
  printf("circular_ll ok\n");
  return 0;
}
