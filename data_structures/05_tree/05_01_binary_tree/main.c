#include <stdio.h>

#include "binary_tree.h"

#define CHECK(cond, msg) \
  do { \
    if (!(cond)) { \
      printf("FAIL: %s\n", msg); \
      return 1; \
    } \
  } while (0)

static void print_value(binary_tree_value_t value) {
  printf("%d ", value);
}

int main(void) {
  BinaryTree tree;
  binary_tree_init(&tree);

  CHECK(binary_tree_set_root(&tree, NULL) == DS_ERR_INVALID, "set root null");

  BinaryTreeNode *n1 = binary_tree_create_node(1);
  BinaryTreeNode *n2 = binary_tree_create_node(2);
  BinaryTreeNode *n3 = binary_tree_create_node(3);
  BinaryTreeNode *n4 = binary_tree_create_node(4);

  CHECK(n1 && n2 && n3 && n4, "node alloc");
  CHECK(binary_tree_set_root(&tree, n1) == DS_OK, "set root");
  CHECK(binary_tree_insert_left(&tree, n1, n2) == DS_OK, "insert left");
  CHECK(binary_tree_insert_right(&tree, n1, n3) == DS_OK, "insert right");
  CHECK(binary_tree_insert_left(&tree, n1, n4) == DS_ERR_INVALID, "insert left occupied");

  CHECK(binary_tree_size(&tree) == 3, "size");

  printf("preorder: ");
  binary_tree_preorder(tree.root, print_value);
  printf("\n");

  binary_tree_destroy(&tree);
  printf("binary_tree ok\n");
  return 0;
}
