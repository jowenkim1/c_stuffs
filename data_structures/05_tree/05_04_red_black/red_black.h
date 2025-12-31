#ifndef RED_BLACK_H
#define RED_BLACK_H

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

typedef int red_black_value_t;

typedef enum {
  RED_BLACK_RED = 0,
  RED_BLACK_BLACK = 1
} RedBlackColor;

typedef struct RedBlackNode {
  red_black_value_t value;
  RedBlackColor color;
  struct RedBlackNode *parent;
  struct RedBlackNode *left;
  struct RedBlackNode *right;
} RedBlackNode;

typedef struct {
  RedBlackNode *root;
  size_t size;
} RedBlackTree;

void red_black_init(RedBlackTree *tree);
void red_black_destroy(RedBlackTree *tree);

int red_black_insert(RedBlackTree *tree, red_black_value_t value);
int red_black_remove(RedBlackTree *tree, red_black_value_t value);
int red_black_find(const RedBlackTree *tree, red_black_value_t value);

int red_black_min(const RedBlackTree *tree, red_black_value_t *out_value);
int red_black_max(const RedBlackTree *tree, red_black_value_t *out_value);

size_t red_black_size(const RedBlackTree *tree);
int red_black_is_empty(const RedBlackTree *tree);

void red_black_inorder(const RedBlackTree *tree, void (*visit)(red_black_value_t));
void red_black_preorder(const RedBlackTree *tree, void (*visit)(red_black_value_t));
void red_black_postorder(const RedBlackTree *tree, void (*visit)(red_black_value_t));

#endif
