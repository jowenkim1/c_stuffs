#include <assert.h>
#include <stdlib.h>
#include "avl.h"

void avl_init(AVLTree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    tree->root = NULL;
    tree->size = 0;
}
void avl_destroy_node(AVLNode *node)
{
    if (node == NULL)
    {
        return;
    }
    avl_destroy_node(node->left);
    avl_destroy_node(node->right);
    free(node);
}

void avl_destroy(AVLTree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    avl_destroy_node(tree->root);
}

AVLNode *create_avl_node(avl_value_t value)
{
    AVLNode *new = malloc(sizeof(*new));
    if (new == NULL)
    {
        return NULL;
    }
    new->height = 0;
    new->value = value;
    new->left = NULL;
    new->right = NULL;
}

int get_height(AVLNode *node)
{
    if (node == NULL)
    {
        return -1;
    }
    return node->height;
}

int get_balance(AVLNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return get_height(node->left) - get_height(node->right);
}

void update_height(AVLNode *node)
{
    int left_h = get_height(node->left);
    int right_h = get_height(node->right);
    if (right_h < left_h)
    {
        node->height = left_h + 1;
    }
    else
    {
        node->height = right_h + 1;
    }
}

AVLNode *rotate_right(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *t2 = x->right;

    x->right = y;
    y->left = t2;

    update_height(y);
    update_height(x);

    return x;
}

AVLNode *rotate_left(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *t2 = y->left;

    y->left = x;
    x->right = t2;

    update_height(x);
    update_height(y);

    return y;
}

AVLNode *avl_insert_node(AVLNode *node, avl_value_t value, bool *success)
{
    if (node == NULL)
    {
        *success = true;
        return create_avl_node(value);
    }

    if (value < node->value)
    {
        node->left = avl_insert_node(node->left, value, success);
    }
    else if (node->value < value)
    {
        node->right = avl_insert_node(node->right, value, success);
    }
    else
    {
        *success = false;
        return node;
    }
    update_height(node);

    int balance = get_balance(node);

    // LL Case
    if (1 < balance && value < node->left->value)
    {
        return rotate_right(node);
    }

    // RR Case
    if (balance < -1 && node->right->value < value)
    {
        return rotate_left(node);
    }

    // LR Case
    if (1 < balance && node->left->value < value)
    {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    // RL Case
    if (balance < -1 && value < node->right->value)
    {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

bool avl_insert(AVLTree *tree, avl_value_t value)
{
    if (tree == NULL)
    {
        return false;
    }
    bool success = false;
    tree->root = avl_insert_node(tree->root, value, &success);

    if (success)
    {
        tree->size += 1;
    }
    return success;
}

AVLNode *get_min_value_node(AVLNode *node) {
    AVLNode *current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

AVLNode *avl_remove_node(AVLNode *root, avl_value_t value, bool *success) {
    if (root == NULL) {
        *success = false;
        return NULL;
    }

    // 1. BST 삭제 수행
    if (value < root->value) {
        root->left = avl_remove_node(root->left, value, success);
    } else if (value > root->value) {
        root->right = avl_remove_node(root->right, value, success);
    } else {
        // 삭제할 노드를 찾은 경우
        *success = true;

        if ((root->left == NULL) || (root->right == NULL)) {
            AVLNode *temp = root->left ? root->left : root->right;

            if (temp == NULL) { // 자식이 없는 경우
                temp = root;
                root = NULL;
            } else { // 자식이 하나인 경우
                *root = *temp; // 구조체 복사
            }
            free(temp);
        } else {
            // 자식이 둘인 경우: In-order Successor를 찾음
            AVLNode *temp = get_min_value_node(root->right);
            root->value = temp->value;
            // 오른쪽 서브트리에서 successor 삭제
            root->right = avl_remove_node(root->right, temp->value, success);
        }
    }

    // 노드가 하나뿐이었다면 바로 반환
    if (root == NULL) return NULL;

    // 2. 높이 업데이트
    update_height(root);

    // 3. 균형 유지 (회전)
    int balance = get_balance(root);

    // LL Case
    if (balance > 1 && get_balance(root->left) >= 0) {
        return rotate_right(root);
    }

    // LR Case
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    // RR Case
    if (balance < -1 && get_balance(root->right) <= 0) {
        return rotate_left(root);
    }

    // RL Case
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}

bool avl_remove(AVLTree *tree, avl_value_t value) {
    if (tree == NULL || tree->root == NULL) return false;

    bool success = false;
    tree->root = avl_remove_node(tree->root, value, &success);

    if (success) {
        tree->size -= 1;
    }
    return success;
}

bool avl_find(const AVLTree *tree, avl_value_t value) {
    if (tree == NULL) {
        return false;
    }

    AVLNode *current = tree->root;
    while (current != NULL) {
        if (value < current->value) {
            current = current->left;
        } else if (value > current->value) {
            current = current->right;
        } else {
            // 값을 찾음
            return true;
        }
    }

    // 끝까지 내려갔는데 못 찾음
    return false;
}

bool avl_min(const AVLTree *tree, avl_value_t *out_value)
{
    if (tree == NULL || tree->root == NULL)
    {
        return false;
    }
    AVLNode *current = tree->root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    *out_value = current;
    return true;
}
bool avl_max(const AVLTree *tree, avl_value_t *out_value)
{
    if (tree == NULL || tree->root == NULL)
    {
        return false;
    }
    AVLNode *current = tree->root;
    while (current->right != NULL)
    {
        current = current->right;
    }
    *out_value = current;
    return true;
}

size_t avl_size(const AVLTree *tree)
{
    assert(tree != NULL);
    return tree->size;
}
bool avl_is_empty(const AVLTree *tree)
{
    assert(tree != NULL);
    return tree->size == 0;
}

void avl_inorder_node(AVLNode *node, void (*visit)(avl_value_t))
{
    if (node == NULL)
    {
        return;
    }
    avl_inorder_node(node->left, visit);
    visit(node->value);
    avl_inorder_node(node->right, visit);
}

void avl_inorder(const AVLTree *tree, void (*visit)(avl_value_t))
{
    // l n r
    if (tree == NULL || visit == NULL)
    {
        return;
    }
    avl_inorder_node(tree->root, visit);
}

void avl_preorder_node(AVLNode *node, void (*visit)(avl_value_t))
{
    if (node == NULL)
    {
        return;
    }
    visit(node->value);
    avl_preorder_node(node->left, visit);
    avl_preorder_node(node->right, visit);
}
void avl_preorder(const AVLTree *tree, void (*visit)(avl_value_t))
{
    if (tree == NULL || visit == NULL)
    {
        return;
    }
    avl_preorder_node(tree->root, visit);
}

void avl_postorder_node(AVLNode *node, void (*visit)(avl_value_t))
{
    if (node == NULL)
    {
        return;
    }
    avl_postorder_node(node->left, visit);
    avl_postorder_node(node->right, visit);
    visit(node->value);
}
void avl_postorder(const AVLTree *tree, void (*visit)(avl_value_t))
{
    if (tree == NULL || visit == NULL)
    {
        return;
    }
    avl_postorder_node(tree->root, visit);
}
