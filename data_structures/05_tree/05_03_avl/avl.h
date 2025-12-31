#ifndef AVL_H
#define AVL_H

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
 * - insert on existing value is a no-op and returns DS_OK.
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

int avl_insert(AVLTree *tree, avl_value_t value);
int avl_remove(AVLTree *tree, avl_value_t value);
int avl_find(const AVLTree *tree, avl_value_t value);

int avl_min(const AVLTree *tree, avl_value_t *out_value);
int avl_max(const AVLTree *tree, avl_value_t *out_value);

size_t avl_size(const AVLTree *tree);
int avl_is_empty(const AVLTree *tree);

void avl_inorder(const AVLTree *tree, void (*visit)(avl_value_t));
void avl_preorder(const AVLTree *tree, void (*visit)(avl_value_t));
void avl_postorder(const AVLTree *tree, void (*visit)(avl_value_t));

#endif
