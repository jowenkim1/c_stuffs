#ifndef BST_H
#define BST_H

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

int bst_insert(BST *tree, bst_value_t value);
int bst_remove(BST *tree, bst_value_t value);
int bst_find(const BST *tree, bst_value_t value);

int bst_min(const BST *tree, bst_value_t *out_value);
int bst_max(const BST *tree, bst_value_t *out_value);

size_t bst_size(const BST *tree);
int bst_is_empty(const BST *tree);

void bst_inorder(const BST *tree, void (*visit)(bst_value_t));
void bst_preorder(const BST *tree, void (*visit)(bst_value_t));
void bst_postorder(const BST *tree, void (*visit)(bst_value_t));

#endif
