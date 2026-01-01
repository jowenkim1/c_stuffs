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
  CHECK(!red_black_min(&tree, &value), "min empty");
  CHECK(!red_black_find(&tree, 1), "find empty");

  CHECK(red_black_insert(&tree, 7), "insert 7");
  CHECK(red_black_insert(&tree, 3), "insert 3");
  CHECK(red_black_insert(&tree, 18), "insert 18");
  CHECK(red_black_insert(&tree, 10), "insert 10");
  CHECK(red_black_insert(&tree, 22), "insert 22");
  CHECK(red_black_insert(&tree, 22), "insert duplicate");

  printf("inorder: ");
  red_black_inorder(&tree, print_value);
  printf("\n");

  CHECK(red_black_min(&tree, &value) && value == 3, "min");
  CHECK(red_black_max(&tree, &value) && value == 22, "max");
  CHECK(red_black_find(&tree, 10), "find 10");
  CHECK(!red_black_find(&tree, 99), "find missing");

  CHECK(!red_black_remove(&tree, 99), "remove missing");
  CHECK(red_black_remove(&tree, 18), "remove 18");

  printf("after remove 18: ");
  red_black_inorder(&tree, print_value);
  printf("\n");

  red_black_destroy(&tree);
  printf("red_black ok\n");
  return 0;
}
