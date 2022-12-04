#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "list.h"

bool empty_list(LIST *li)
{
    assert(li != NULL);
    return (li->start == NULL) ? true : false;
}

LIST *create_list()
{
    LIST *list = (LIST *)malloc(sizeof(LIST));
    if (list != NULL)
    {
        list->start = NULL;
        list->size = 0;
    }
    return list;
}

int size_list(LIST *li)
{
    assert(li != NULL);
    return li->size;
}

int get_item_list(LIST *li, int pos)
{
    assert(li != NULL);
    assert(pos >= 0 && pos <= size_list(li));
    NODELIST *aux = li->start;
    for (int i = 0; i < pos; i++)
    {
        aux = aux->next;
    }
    return aux->info;
}

int remove_item_list(LIST *li, int pos)
{
    assert(li != NULL);
    assert(pos >= 0 && pos <= size_list(li));
    NODELIST *previous = NULL;
    NODELIST *aux = li->start;
    for (int i = 0; i < pos; i++)
    {
        previous = aux;
        aux = aux->next;
    }
    if (previous == NULL)
    {
        li->start = aux->next;
    }
    else
    {
        previous->next = aux->next;
    }
    int element = aux->info;
    li->size--;
    free(aux);
    return element;
}

void insert_item_list(LIST *li, int pos, int item)
{
    assert(li != NULL);
    assert(pos >= 0 && pos <= size_list(li));
    NODELIST *new_node = (NODELIST *)malloc(sizeof(NODELIST));
    new_node->info = item;
    if (pos == 0)
    {
        new_node->next = li->start;
        li->start = new_node;
    }
    else
    {
        NODELIST *aux = li->start;
        for (int i = 0; i < pos - 1; i++)
        {
            aux = aux->next;
        }
        new_node->next = aux->next;
        aux->next = new_node;
    }
    li->size++;
}

void view_list(LIST *li)
{
    assert(li != NULL);
    printf("\n[");
    NODELIST *aux = li->start;
    for (int i = 0; i < size_list(li); i++)
    {
        (i != size_list(li) - 1) ? printf("%d, ", aux->info) : printf("%d", aux->info);
        aux = aux->next;
    }
    printf("]");
}

void free_list_alloc(LIST *li)
{
    do
    {
        remove_item_list(li, 0);
    } while (empty_list(li) == false);
    free(li);
}