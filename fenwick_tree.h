#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H
typedef struct BIT_Tree {
    int size;
    int* values, *tree;
} BIT_Tree;

BIT_Tree* create_bit_tree(int* values, int n);
void destroy_bit_tree (BIT_Tree* tree);
void __add__(BIT_Tree* tree, int i, int val);
int __get__(BIT_Tree* tree, int i);
void update(BIT_Tree* tree, int i , int val);
int get_sum(BIT_Tree* tree, int i, int j);
#endif