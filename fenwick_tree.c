#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "fenwick_tree.h"

BIT_Tree* create_bit_tree(int* values, int n) {
    BIT_Tree* tree = malloc(sizeof(BIT_Tree));
    tree->size = n;
    tree->tree = malloc((n+1) * sizeof(int));
    tree->values = values;
    for (int i = 0; i < n; i++) __add__(tree, i, values[i]);
    return tree;
}
void destroy_bit_tree (BIT_Tree* tree) {
    free(tree->tree);
    // free(tree->values);
    free(tree);
}
void __add__(BIT_Tree* tree, int i, int val) {
    int index = i + 1;
    while (index < tree->size + 1) {
        tree->tree[index] += val;
        index = index + (index & -index);
    }
}
int __get__(BIT_Tree* tree, int i) {
    int index = i + 1, sum = 0;
    while (index > 0) {
        sum += tree->tree[index];
        index = index - (index & -index);
    }
    return sum;
}
void update(BIT_Tree* tree, int i , int val) {
    __add__(tree, i, -tree->values[i]);
    tree->values[i] = val;
    __add__(tree, i, tree->values[i]);
}
int get_sum(BIT_Tree* tree, int i, int j) {
    return __get__(tree, j) - __get__(tree, i - 1);
}

int main() {
    int arr[] = {1,2,10,3,4,1,5,6,3};
    BIT_Tree* tree = create_bit_tree(arr, 9);
    for (int i = 1; i < 9; i++) {
        printf("%d ", get_sum(tree, 1, i));
    }
    destroy_bit_tree(tree);
}