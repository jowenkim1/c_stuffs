#include <assert.h>
#include <stdlib.h>
#include "bst.h"

void bst_init(BST *tree)
{
    if (tree == NULL)
    {
        return;
    }
    tree->root = NULL;
    tree->size = 0;
}

void bst_destroy_node(BSTNode *node)
{
    if (node == NULL)
    {
        return;
    }
    bst_destroy_node(node->left);
    bst_destroy_node(node->right);
    free(node);
}

void bst_destroy(BST *tree)
{
    if (tree == NULL)
    {
        return;
    }
    bst_destroy_node(tree->root);
    tree->root = NULL;
    tree->size = 0;
}

BSTNode *bst_create_node(bst_value_t value)
{
    BSTNode *new = malloc(sizeof(*new));
    if (new == NULL)
    {
        return NULL;
    }
    new->left = NULL;
    new->right = NULL;
    new->value = value;
    return new;
}

bool bst_insert(BST *tree, bst_value_t value)
{
    if (tree == NULL)
    {
        return false;
    }

    if (tree->root == NULL)
    {
        tree->root = bst_create_node(value);
        if (tree->root == NULL)
        {
            return false;
        }
        tree->size += 1;
        return true;
    }

    BSTNode *curr = tree->root;
    BSTNode *parent = NULL;

    while (curr != NULL)
    {
        parent = curr;
        if (value <= curr->value)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    BSTNode *new = bst_create_node(value);
    if (new == NULL){
        return false;
    }
    if (value <= parent->value)
    {
        parent->left = new;
    }
    else
    {
        parent->right = new;
    }
    tree->size += 1;
    return true;
}

bool bst_remove(BST *tree, bst_value_t value)
{
    if (tree == NULL || tree->root == NULL)
    {
        return false;
    }

    BSTNode *curr = tree->root;
    BSTNode *parent = NULL;

    while (curr != NULL)
    {
        if (curr->value == value)
        {
            break;
        }
        parent = curr;
        if (value < curr->value)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }

    if (curr == NULL)
    {
        return false;
    }

    // if 0 or 1 child;
    if (curr->left == NULL || curr->right == NULL)
    {
        BSTNode *child;
        if (curr->left != NULL)
        {
            child = curr->left;
        }
        else
        {
            child = curr->right;
        }

        if (parent == NULL)
        {
            tree->root = child;
        }
        else if (parent->left == curr)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }

        free(curr);
        tree->size -= 1;
        return true;
    }

    BSTNode *succ_parent = curr;
    BSTNode *succ = curr->right;

    // min of right
    while (succ->left != NULL)
    {
        succ_parent = succ;
        succ = succ->left;
    }
    curr->value = succ->value;

    BSTNode *succ_child = succ->right;
    if (succ_parent->left == succ)
    {
        succ_parent->left = succ_child;
    }
    else
    {
        succ_parent->right = succ_child;
    }

    free(succ);
    tree->size -= 1;
    return true;
}

bool bst_find(const BST *tree, bst_value_t value)
{
    if (tree == NULL || tree->root == NULL)
    {
        return false;
    }

    BSTNode *curr = tree->root;
    BSTNode *parent = NULL;

    while (curr != NULL)
    {
        if (curr->value == value)
        {
            return true;
        }
        parent = curr;
        if (value < curr->value)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    return false;
}
bool bst_min(const BST *tree, bst_value_t *out_value)
{
    if (tree == NULL || tree->root == NULL || out_value == NULL)
    {
        return false;
    }

    BSTNode *curr = tree->root;
    while (curr->left != NULL)
    {
        curr = curr->left;
    }
    *out_value = curr->value;
    return true;
}
bool bst_max(const BST *tree, bst_value_t *out_value)
{
    if (tree == NULL || tree->root == NULL || out_value == NULL)
    {
        return false;
    }

    BSTNode *curr = tree->root;
    while (curr->right != NULL)
    {
        curr = curr->right;
    }
    *out_value = curr->value;
    return true;
}

size_t bst_size(const BST *tree)
{
    assert(tree != NULL);
    return tree->size;
}
bool bst_is_empty(const BST *tree)
{
    assert(tree != NULL);
    return tree->size == 0;
}

void bst_inorder_node(BSTNode *node, void (*visit)(bst_value_t))
{
    if (node == NULL)
    {
        return;
    }
    bst_inorder_node(node->left, visit);
    visit(node->value);
    bst_inorder_node(node->right, visit);
}
void bst_inorder(const BST *tree, void (*visit)(bst_value_t))
{
    // l n r
    if (tree == NULL || tree->root == NULL || visit == NULL)
    {
        return;
    }
    bst_inorder_node(tree->root, visit);
}
void bst_preorder_node(BSTNode *node, void (*visit)(bst_value_t))
{
    if (node == NULL)
    {
        return;
    }
    visit(node->value);
    bst_preorder_node(node->left, visit);
    bst_preorder_node(node->right, visit);
}
void bst_preorder(const BST *tree, void (*visit)(bst_value_t))
{
    // n l r
    if (tree == NULL || tree->root == NULL || visit == NULL)
    {
        return;
    }
    bst_preorder_node(tree->root, visit);
}

void bst_postorder_node(BSTNode *node, void (*visit)(bst_value_t))
{
    if (node == NULL)
    {
        return;
    }
    bst_postorder_node(node->left, visit);
    bst_postorder_node(node->right, visit);
    visit(node->value);
}
void bst_postorder(const BST *tree, void (*visit)(bst_value_t))
{
    // l r n
    if (tree == NULL || tree->root == NULL || visit == NULL)
    {
        return;
    }
    bst_postorder_node(tree->root, visit);
}
