#ifndef AVL_H
#define AVL_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
 * - insert on existing value is a no-op and returns true.
 */

typedef int avl_value_t;

typedef struct AVLNode {
  avl_value_t value;
  int height;
  struct AVLNode *left;
  struct AVLNode *right;
} AVLNode;

typedef struct {
  AVLNode *root;
  size_t size;
} AVLTree;

void avl_init(AVLTree *tree);
void avl_destroy(AVLTree *tree);

bool avl_insert(AVLTree *tree, avl_value_t value);
bool avl_remove(AVLTree *tree, avl_value_t value);
bool avl_find(const AVLTree *tree, avl_value_t value);

bool avl_min(const AVLTree *tree, avl_value_t *out_value);
bool avl_max(const AVLTree *tree, avl_value_t *out_value);

size_t avl_size(const AVLTree *tree);
bool avl_is_empty(const AVLTree *tree);

void avl_inorder(const AVLTree *tree, void (*visit)(avl_value_t));
void avl_preorder(const AVLTree *tree, void (*visit)(avl_value_t));
void avl_postorder(const AVLTree *tree, void (*visit)(avl_value_t));

#endif
