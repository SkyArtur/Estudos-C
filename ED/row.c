#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "row.h"


ROW* create_row() 
{
    ROW* new_row = (ROW*)malloc(sizeof(ROW));
    if (new_row != NULL) {
        new_row->start = NULL;
        new_row->end = NULL;
        new_row->size = 0;
    }
    return new_row;
}

bool empty_row(ROW* rw)
{
    assert(rw != NULL);
    return (rw->start == NULL);
}

int size_row(ROW* rw)
{
    assert(rw != NULL);
    return rw->size;
}

int start_row_item(ROW* rw)
{
    assert(rw != NULL);
    assert(rw->start != NULL);
    return rw->start->info;
}

int remove_item_row(ROW* rw)
{
    assert(rw != NULL);
    assert(rw->start != NULL);
    NODEROW* aux = rw->start;
    int element = aux->info;
    rw->start = aux->next;
    if (rw->start == NULL) {
        rw->end = NULL;
    }
    rw->size--;
    free(aux);
    return element;
}

void free_row_alloc(ROW* rw)
{
    assert(rw != NULL);
    while (rw->start != NULL) {
        remove_item_row(rw);
    }
    free(rw);
}


void insert_item_row(ROW* rw, int item) 
{
    assert(rw != NULL);
    NODEROW* new_node = (NODEROW*) malloc(sizeof(NODEROW));
    if (new_node != NULL) {
        new_node->info = item;
        new_node->next = NULL;
        if (rw->end != NULL) {
            rw->end->next = new_node;
        } else {
            rw->start = new_node;
        }
        rw->end = new_node;
        rw->size++;
    }
}

void view_row(ROW* rw)
{
    assert(rw != NULL);
    printf("\n(");
    NODEROW* aux = rw->start;
    for (int i = 0; i < size_row(rw); i++)
    {
        (i != size_row(rw) - 1) ? printf("%d, ", aux->info) : printf("%d", aux->info);
        aux  = aux->next;
    }
    printf(")");
}
