#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H
typedef struct List {
    int size, capacity;
    int* arr;
} List;

void __resize__(List* list, int new_size);

List* create_list();
void destroy_list(List* list);
void add_val(List* list, int val);
void remove_val(List* list, int val);
int get_size(List* list);
int get_val(List* list, int index);
void print(List* list);
#endif