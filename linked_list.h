#ifndef LINKED_LIST_H
#define LINKED_LIST_H
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode;
typedef struct LinkedList {
    LNode* root;
    int size;
} LinkedList;

LinkedList* create_linked_list();
void destroy_linked_list(LinkedList* list);
int get_list_size(LinkedList* list);
int get_nth_value(LinkedList* list, int n);
void insert_n(LinkedList* list, int n);
void remove_nth(LinkedList* list, int n);
void reverse(LinkedList* list);
void print_list(LinkedList* list);
#endif