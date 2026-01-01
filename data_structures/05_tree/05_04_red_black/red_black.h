#ifndef RED_BLACK_H
#define RED_BLACK_H

#include <stdbool.h>
#include <stddef.h>

/*
 * ADT conventions:
 * - Functions that can fail return bool: true on success, false on failure.
 * - Query functions return bool; false also covers invalid args.
 * - insert on existing value is a no-op and returns true.
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

bool red_black_insert(RedBlackTree *tree, red_black_value_t value);
bool red_black_remove(RedBlackTree *tree, red_black_value_t value);
bool red_black_find(const RedBlackTree *tree, red_black_value_t value);

bool red_black_min(const RedBlackTree *tree, red_black_value_t *out_value);
bool red_black_max(const RedBlackTree *tree, red_black_value_t *out_value);

size_t red_black_size(const RedBlackTree *tree);
bool red_black_is_empty(const RedBlackTree *tree);

void red_black_inorder(const RedBlackTree *tree, void (*visit)(red_black_value_t));
void red_black_preorder(const RedBlackTree *tree, void (*visit)(red_black_value_t));
void red_black_postorder(const RedBlackTree *tree, void (*visit)(red_black_value_t));

#endif
