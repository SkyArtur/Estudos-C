#ifndef _LIST_H_
#define _LIST_H_

struct NodeList {
    int info;
    struct NodeList* next;
};

struct SimpleListIntegers {
    struct NodeList* start;
    int size;
};

typedef struct NodeList NODELIST;
typedef struct SimpleListIntegers LIST;

LIST* create_list();
bool empty_list(LIST* li);
int size_list(LIST* li);
int get_item_list(LIST* li, int pos);
int remove_item_list(LIST* li, int pos);

void insert_item_list(LIST* li , int pos, int item);
void view_list(LIST* li);
void free_list_alloc(LIST* li);

#endif