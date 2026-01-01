#ifndef BST_H
#define BST_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
 * - insert on existing value is a no-op and returns true.
 */

typedef int bst_value_t;

typedef struct BSTNode {
  bst_value_t value;
  struct BSTNode *left;
  struct BSTNode *right;
} BSTNode;

typedef struct {
  BSTNode *root;
  size_t size;
} BST;

void bst_init(BST *tree);
void bst_destroy(BST *tree);

bool bst_insert(BST *tree, bst_value_t value);
bool bst_remove(BST *tree, bst_value_t value);
bool bst_find(const BST *tree, bst_value_t value);

bool bst_min(const BST *tree, bst_value_t *out_value);
bool bst_max(const BST *tree, bst_value_t *out_value);

size_t bst_size(const BST *tree);
bool bst_is_empty(const BST *tree);

void bst_inorder(const BST *tree, void (*visit)(bst_value_t));
void bst_preorder(const BST *tree, void (*visit)(bst_value_t));
void bst_postorder(const BST *tree, void (*visit)(bst_value_t));

#endif
