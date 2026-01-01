#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
 * - out_value must be non-NULL; it is unchanged on failure.
 * - Nodes are owned by the tree after insertion; do not free them manually.
 */

typedef int binary_tree_value_t;

typedef struct BinaryTreeNode {
  binary_tree_value_t value;
  struct BinaryTreeNode *left;
  struct BinaryTreeNode *right;
} BinaryTreeNode;

typedef struct {
  BinaryTreeNode *root;
  size_t size;
} BinaryTree;

void binary_tree_init(BinaryTree *tree);
void binary_tree_destroy(BinaryTree *tree);

BinaryTreeNode *binary_tree_create_node(binary_tree_value_t value);
void binary_tree_destroy_node(BinaryTreeNode *node);

bool binary_tree_set_root(BinaryTree *tree, BinaryTreeNode *node);
bool binary_tree_insert_left(BinaryTree *tree, BinaryTreeNode *parent, BinaryTreeNode *node);
bool binary_tree_insert_right(BinaryTree *tree, BinaryTreeNode *parent, BinaryTreeNode *node);

void binary_tree_preorder(const BinaryTreeNode *node, void (*visit)(binary_tree_value_t));
void binary_tree_inorder(const BinaryTreeNode *node, void (*visit)(binary_tree_value_t));
void binary_tree_postorder(const BinaryTreeNode *node, void (*visit)(binary_tree_value_t));

size_t binary_tree_size(const BinaryTree *tree);
bool binary_tree_is_empty(const BinaryTree *tree);

#endif
