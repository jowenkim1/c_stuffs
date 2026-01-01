#include <stdio.h>

#include "bst.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

static void print_value(bst_value_t value) {
  printf("%d ", value);
}

int main(void) {
  BST tree;
  bst_init(&tree);

  bst_value_t value = 0;
  CHECK(!bst_min(&tree, &value), "min empty");
  CHECK(!bst_find(&tree, 1), "find empty");

  CHECK(bst_insert(&tree, 5), "insert 5");
  CHECK(bst_insert(&tree, 2), "insert 2");
  CHECK(bst_insert(&tree, 8), "insert 8");
  CHECK(bst_insert(&tree, 1), "insert 1");
  CHECK(bst_insert(&tree, 3), "insert 3");
  CHECK(bst_insert(&tree, 3), "insert duplicate");

  printf("inorder: ");
  bst_inorder(&tree, print_value);
  printf("\n");

  CHECK(bst_min(&tree, &value) && value == 1, "min");
  CHECK(bst_max(&tree, &value) && value == 8, "max");
  CHECK(bst_find(&tree, 2), "find 2");
  CHECK(!bst_find(&tree, 99), "find missing");

  CHECK(!bst_remove(&tree, 99), "remove missing");
  CHECK(bst_remove(&tree, 2), "remove 2");

  printf("after remove 2: ");
  bst_inorder(&tree, print_value);
  printf("\n");

  bst_destroy(&tree);
  printf("bst ok\n");
  return 0;
}
