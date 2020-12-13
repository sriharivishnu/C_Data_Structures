#include <stdio.h>
#include <stdlib.h>
#include "dynamic_list.h"

void __resize__(List* list, int new_size) {
    if (new_size < 1) return;
    list->capacity = new_size;
    list->arr = realloc(list->arr, sizeof(int) * new_size);
}

List* create_list() {
    List* list = malloc(sizeof(List));
    list->capacity = 1;
    list->size = 0;
    list->arr = malloc(sizeof(int) * 1);
    return list;
}
void destroy_list(List* list) {
    free(list->arr);
    free(list);
}
void add_val(List* list, int val) {
    if (list->size + 1 > list->capacity) __resize__(list, list->capacity * 2);
    list->arr[list->size] = val;
    list->size += 1;
}
void remove_val(List* list, int val) {
    int toRemove = -1;
    for (int i = 0; i < list->size; i++) {
        if (list->arr[i] == val) {
            toRemove = i; 
            break;
        }
    }
    if (toRemove == -1) return;
    for (int i = toRemove; i < list->size - 1; i++) {
        list->arr[i] = list->arr[i+1];
    }
    list->size -= 1;
    if (list->size <= list->capacity / 2) __resize__(list, list->capacity / 2);
}
int get_size(List* list) {
    return list->size;
}
int get_val(List* list, int index) {
    return list->arr[index];
}

void print_list(List* list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

// int main() {
//     List* list = create_list();
//     for (int i = 0; i < 10; i++) {
//         add_val(list, i);
//         printf("Size: %d  Capacity: %d \n", get_size(list), list->capacity);
//     }
//     print_list(list);
//     for (int i = 0; i < 10; i += 2) {
//         remove_val(list, i);
//         printf("Size: %d  Capacity: %d Removing Value: %d | ", get_size(list), list->capacity, i);
//         print_list(list);
//     }
//     print_list(list);
// }