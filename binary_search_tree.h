#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
typedef struct BSTNode {
    int data;
    struct BSTNode* left, *right;
} BSTNode;

typedef struct BST {
    int size;
    BSTNode* root;
} BST;

void __destroy_helper__(BSTNode* node);
BSTNode* __get_min__(BSTNode* node);
BSTNode* __get_max__(BSTNode* node);
int __get_depth__(BSTNode* node);
void __inorder__(BSTNode* node);
void __preorder__(BSTNode* node);
void __postorder__(BSTNode* node);
void __print__(BSTNode* node, int level, bool left);

BST* bst_create();
void bst_destroy(BST* tree);
void insert_val(BST* tree, int val);
void remove_val(BST* tree, int val);
int get_size(BST* tree);
bool is_empty(BST* tree);
int get_min(BST* tree);
int get_max(BST* tree);
int max_depth(BST* tree);

void print_inorder(BST* tree);
void print_postorder(BST* tree);
void print_preorder(BST* tree);
void print_pretty(BST* tree);
// void balance(BST tree);
#endif