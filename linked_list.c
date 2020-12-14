#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
LinkedList* create_linked_list() {
    LinkedList* list = malloc(sizeof(LinkedList));
    list->root = NULL;
    list->size = 0;
    return list;
}
void destroy_linked_list(LinkedList* list) {
    LNode* cur = list->root, *next = NULL;
    while (cur) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    free(list);
}
int get_list_size(LinkedList* list) {
    return list ? list->size : -1;
}
int get_nth_value(LinkedList* list, int n) {
    if (n > list->size - 1 || n < 0) return -1;
    LNode* cur = list->root;
    while (n--) {
        cur = cur->next;
    }
    return cur->data;
}
void insert_n(LinkedList* list, int n) {
    list->size += 1;
    LNode* cur = list->root, *prev = NULL;
    while (cur) {
        prev = cur;
        cur = cur->next;
    }
    LNode* toAdd = malloc(sizeof(LNode));
    toAdd->data = n;
    toAdd->next = NULL;
    if (!prev) {
        list->root = toAdd;
    } else {
        prev->next = toAdd;
    }
}
void remove_nth(LinkedList* list, int n) {
    list->size -=1;
    LNode* cur = list->root;
    if (n == 0) {
        list->root = cur->next;
        return;
    }
    for (int i = 0; i < n - 1; i++) cur = cur->next;
    LNode* toRemove = cur->next;
    cur->next = toRemove->next;
    free(toRemove);
}
//.->4->3->2->1->5
void reverse(LinkedList* list) {
    LNode* tail = list->root;
    if (!tail) return;
    while (tail->next) {
        LNode* temp = list->root;
        list->root = tail->next;
        tail->next = list->root->next;
        list->root->next = temp;
    }
}
void print_list(LinkedList* list) {
    LNode* cur = list->root;
    while (cur) {
        printf("%d", cur->data);
        if (cur->next) printf("->");
        cur = cur->next;
    }
    printf("\n");
}
int main() {
    LinkedList* list = create_linked_list();
    insert_n(list, 10);
    insert_n(list, 12);
    insert_n(list, 1);
    insert_n(list, 14);
    insert_n(list, 121);
    reverse(list);
    print_list(list);
}