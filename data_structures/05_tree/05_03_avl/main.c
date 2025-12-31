#include <stdio.h>

#include "avl.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

static void print_value(avl_value_t value) {
  printf("%d ", value);
}

int main(void) {
  AVLTree tree;
  avl_init(&tree);

  avl_value_t value = 0;
  CHECK(avl_min(&tree, &value) == DS_ERR_EMPTY, "min empty");
  CHECK(avl_find(&tree, 1) == DS_ERR_NOT_FOUND, "find empty");

  CHECK(avl_insert(&tree, 30) == DS_OK, "insert 30");
  CHECK(avl_insert(&tree, 20) == DS_OK, "insert 20");
  CHECK(avl_insert(&tree, 40) == DS_OK, "insert 40");
  CHECK(avl_insert(&tree, 10) == DS_OK, "insert 10");
  CHECK(avl_insert(&tree, 25) == DS_OK, "insert 25");
  CHECK(avl_insert(&tree, 25) == DS_OK, "insert duplicate");

  printf("inorder: ");
  avl_inorder(&tree, print_value);
  printf("\n");

  CHECK(avl_min(&tree, &value) == DS_OK && value == 10, "min");
  CHECK(avl_max(&tree, &value) == DS_OK && value == 40, "max");
  CHECK(avl_find(&tree, 25) == DS_OK, "find 25");
  CHECK(avl_find(&tree, 99) == DS_ERR_NOT_FOUND, "find missing");

  CHECK(avl_remove(&tree, 99) == DS_ERR_NOT_FOUND, "remove missing");
  CHECK(avl_remove(&tree, 20) == DS_OK, "remove 20");

  printf("after remove 20: ");
  avl_inorder(&tree, print_value);
  printf("\n");

  avl_destroy(&tree);
  printf("avl ok\n");
  return 0;
}
