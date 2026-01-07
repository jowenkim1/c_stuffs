#include <assert.h>
#include <stdlib.h>
#include "binary_tree.h"

void binary_tree_init(BinaryTree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    tree->root = NULL;
    tree->size = 0;
}
void binary_tree_destroy(BinaryTree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    binary_tree_destroy_node(tree->root);
    tree->root = NULL;
    tree->size = 0;
}

BinaryTreeNode *binary_tree_create_node(binary_tree_value_t value)
{
    BinaryTreeNode *new = malloc(sizeof(*new));
    if (new == NULL)
    {
        return NULL;
    }
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void binary_tree_destroy_node(BinaryTreeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    binary_tree_destroy_node(node->left);
    binary_tree_destroy_node(node->right);
    free(node);
}

bool binary_tree_set_root(BinaryTree *tree, BinaryTreeNode *node)
{
    if (tree == NULL || node == NULL)
    {
        return false;
    }
    if (tree->root != NULL)
    {
        return false;
    }
    tree->root = node;
    tree->size = 1;
    return true;
}

bool binary_tree_insert_left(BinaryTree *tree, BinaryTreeNode *parent, BinaryTreeNode *node)
{
    if (tree == NULL || parent == NULL || node == NULL)
    {
        return false;
    }
    if (parent->left != NULL)
    {
        return false;
    }
    parent->left = node;
    tree->size += 1;
    return true;
}
bool binary_tree_insert_right(BinaryTree *tree, BinaryTreeNode *parent, BinaryTreeNode *node)
{
    if (tree == NULL || parent == NULL || node == NULL)
    {
        return false;
    }
    if (parent->right != NULL)
    {
        return false;
    }
    parent->right = node;
    tree->size += 1;
    return true;
}

void binary_tree_preorder(const BinaryTreeNode *node, void (*visit)(binary_tree_value_t))
{
    // N -> L -> R 
    if (node == NULL){
        return;
    }
    visit(node->value);
    binary_tree_preorder(node->left, visit);
    binary_tree_preorder(node->right,visit);

}
void binary_tree_inorder(const BinaryTreeNode *node, void (*visit)(binary_tree_value_t))
{
    // L -> N -> R
    if (node == NULL){
        return;
    }
    binary_tree_inorder(node->left, visit);
    visit(node->value);
    binary_tree_inorder(node->right,visit);
}
void binary_tree_postorder(const BinaryTreeNode *node, void (*visit)(binary_tree_value_t))
{
    // L -> R -> N
    if (node == NULL){
        return;
    }
    binary_tree_postorder(node->left, visit);
    binary_tree_postorder(node->right,visit);
    visit(node->value);
}

size_t binary_tree_size(const BinaryTree *tree){
    assert(tree!=NULL);
    return tree->size;
}
bool binary_tree_is_empty(const BinaryTree *tree){
    assert(tree!=NULL);
    return tree->size == 0;
}
