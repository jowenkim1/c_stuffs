#include <stdio.h>

#include "red_black.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

static void print_value(red_black_value_t value) {
  printf("%d ", value);
}

int main(void) {
  RedBlackTree tree;
  red_black_init(&tree);

  red_black_value_t value = 0;
  CHECK(red_black_min(&tree, &value) == DS_ERR_EMPTY, "min empty");
  CHECK(red_black_find(&tree, 1) == DS_ERR_NOT_FOUND, "find empty");

  CHECK(red_black_insert(&tree, 7) == DS_OK, "insert 7");
  CHECK(red_black_insert(&tree, 3) == DS_OK, "insert 3");
  CHECK(red_black_insert(&tree, 18) == DS_OK, "insert 18");
  CHECK(red_black_insert(&tree, 10) == DS_OK, "insert 10");
  CHECK(red_black_insert(&tree, 22) == DS_OK, "insert 22");
  CHECK(red_black_insert(&tree, 22) == DS_OK, "insert duplicate");

  printf("inorder: ");
  red_black_inorder(&tree, print_value);
  printf("\n");

  CHECK(red_black_min(&tree, &value) == DS_OK && value == 3, "min");
  CHECK(red_black_max(&tree, &value) == DS_OK && value == 22, "max");
  CHECK(red_black_find(&tree, 10) == DS_OK, "find 10");
  CHECK(red_black_find(&tree, 99) == DS_ERR_NOT_FOUND, "find missing");

  CHECK(red_black_remove(&tree, 99) == DS_ERR_NOT_FOUND, "remove missing");
  CHECK(red_black_remove(&tree, 18) == DS_OK, "remove 18");

  printf("after remove 18: ");
  red_black_inorder(&tree, print_value);
  printf("\n");

  red_black_destroy(&tree);
  printf("red_black ok\n");
  return 0;
}
