#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "binary_search_tree.h"

void __destroy_helper__(BSTNode* node) {
    if (!node) return;
    __destroy_helper__(node->left);
    __destroy_helper__(node->right);
    free(node);
}
BSTNode* __get_min__(BSTNode* node) {
    if (node == NULL) return NULL;
    while (node->left) node = node->left;
    return node;
}
BSTNode* __get_max__(BSTNode* node) {
    if (node == NULL) return NULL;
    while (node->right) node = node->right;
    return node;
}

int __get_depth__(BSTNode* node) {
    if (!node) return 0;
    int left = __get_depth__(node->left);
    int right = __get_depth__(node->right);
    return 1 + (left >= right ? left : right);
}

void __inorder__(BSTNode* node) {
    if (!node) return;
    __inorder__(node->left);
    printf("%d ", node->data);
    __inorder__(node->right);
}
void __preorder__(BSTNode* node) {
    if (!node) return;
    printf("%d ", node->data);
    __preorder__(node->left);
    __preorder__(node->right);
}
void __postorder__(BSTNode* node) {
     if (!node) return;
    __postorder__(node->left);
    __postorder__(node->right);
    printf("%d\n", node->data);
}
void __print__(BSTNode* node, int level, bool left) {
    if (!node) return;
    for (int i = 0; i < level; i++) printf("│    ");
    printf(left ? "├──" : "└──");
    printf("%d\n", node->data);
    __print__(node->left, level + 1, true);
    __print__(node->right, level + 1, false);
}

BST* bst_create() {
    BST* tree = malloc(sizeof(BST));
    tree->size = 0;
    tree->root = NULL;
    return tree;
}
void bst_destroy(BST* tree) {
    __destroy_helper__(tree->root);
    free(tree);
}

void insert_val(BST* tree, int val) {
    BSTNode* cur = tree->root, *prev = NULL;
    while (cur) {
        prev = cur;
        if (val < cur->data) cur = cur->left;
        else if (val > cur->data) cur = cur->right;
        else return;
    }
    tree->size += 1;

    BSTNode* toAdd = malloc(sizeof(BSTNode));
    toAdd->data = val;
    toAdd->left = NULL;
    toAdd->right = NULL;
    if (prev == NULL) {
        tree->root = toAdd;
        return;
    }
    if (val > prev->data) prev->right = toAdd;
    else if (val < prev->data) prev->left = toAdd;
}
void remove_val(BST* tree, int val) {
    BSTNode* cur = tree->root, *prev = NULL;
    while (cur) {
        if (val == cur->data) break;
        prev = cur;
        if (val < cur->data) cur = cur->left;
        else if (val > cur->data) cur = cur->right;
    }
    if (!cur) return;
    else if (!prev) {
        tree->root = NULL;
        free(cur);
        return;
    }
    //Leaf Node
    if (!cur->left && !cur->right) {
        if (prev->left == cur) prev->left = NULL;
        else prev->right = NULL;
        free(cur);
    }
    //Two Children
    else if (cur->left && cur->right) {
        BSTNode* min = cur->right, *min_prev = cur;
        while (min->left) {
            min_prev = min;
            min = min->left;
        }
        cur->data = min->data;
        min_prev->right = NULL;
        free(min);
    }
    //One-Child
    else if (cur->left) {
        if (prev->left == cur) prev->left = cur->left;
        else if (prev->right == cur) prev->right = cur->left;
        free(cur);
    }
    else if (cur->right) {
        if (prev->left == cur) prev->left = cur->right;
        else if (prev->right == cur) prev->right = cur->right;
        free(cur);
    }
    tree->size -= 1;
    
}
int get_size(BST* tree) {
    return tree->size;
}

bool is_empty(BST* tree) {
    return tree->size == 0;
}

int get_min(BST* tree) {
    return __get_min__(tree->root)->data;
}
int get_max(BST* tree) {
    return __get_max__(tree->root)->data;
}

int max_depth(BST* tree) {
    return __get_depth__(tree->root);
}

void print_inorder(BST* tree) {
    __inorder__(tree->root);
    printf("\n");
}
void print_postorder(BST* tree) {
    __postorder__(tree->root);
    printf("\n");
}
void print_preorder(BST* tree) {
    __preorder__(tree->root);
    printf("\n");
}

void print_pretty(BST* tree) {
    __print__(tree->root, 0, false);
}

int main(void) {
    BST* tree = bst_create();
    insert_val(tree, 10);
    insert_val(tree, 8);
    insert_val(tree, 19);
    insert_val(tree, 13);
    insert_val(tree, 7);
    insert_val(tree, 9);
    insert_val(tree, 17);
    insert_val(tree, 25);
    insert_val(tree, 14);
    insert_val(tree, 22);
    insert_val(tree, 18);
    remove_val(tree, 17);
    remove_val(tree, 18);
    insert_val(tree, 27);
    print_pretty(tree);
    bst_destroy(tree);
    return 0;
}
