#ifndef BINARY_TREE_H
#define BINARY_TREE_H

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

int binary_tree_set_root(BinaryTree *tree, BinaryTreeNode *node);
int binary_tree_insert_left(BinaryTree *tree, BinaryTreeNode *parent, BinaryTreeNode *node);
int binary_tree_insert_right(BinaryTree *tree, BinaryTreeNode *parent, BinaryTreeNode *node);

void binary_tree_preorder(const BinaryTreeNode *node, void (*visit)(binary_tree_value_t));
void binary_tree_inorder(const BinaryTreeNode *node, void (*visit)(binary_tree_value_t));
void binary_tree_postorder(const BinaryTreeNode *node, void (*visit)(binary_tree_value_t));

size_t binary_tree_size(const BinaryTree *tree);
int binary_tree_is_empty(const BinaryTree *tree);

#endif
