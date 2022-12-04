#ifndef _ROW_H_
#define _ROW_H_

struct NodeRow {
    int info;
    struct NodeRow* next;
};

struct Row {
    struct NodeRow* start;
    struct NodeRow* end;
    int size;
};
typedef struct NodeRow NODEROW;
typedef struct Row ROW;

ROW* create_row();
bool empty_row(ROW* rw);
int size_row(ROW* rw);
int start_item_row(ROW* rw);
int remove_item_row(ROW* rw);

void free_row_alloc(ROW* rw);
void insert_item_row(ROW* rw, int item);
void view_row(ROW* rw);

#endif