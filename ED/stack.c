#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "stack.h"

bool empty_stack(STACK *sk)
{
    assert(sk != NULL);
    return (sk->top == NULL);
}

STACK *create_stack()
{
    STACK *new_stack = (STACK *)malloc(sizeof(STACK));
    if (new_stack != NULL)
    {
        new_stack->top = NULL;
        new_stack->size = 0;
    }
    return new_stack;
}

int top_stack(STACK *sk)
{
    assert(sk != NULL);
    assert(sk->top != NULL);
    struct NodeStack *top = sk->top;
    return top->info;
}

int size_stack(STACK *sk)
{
    assert(sk != NULL);
    return sk->size;
}

int remove_item_stack(STACK *sk)
{
    assert(sk != NULL);
    assert(sk->top != NULL);
    NODESTACK *aux = sk->top;
    int element = aux->info;
    sk->top = aux->next;
    sk->size--;
    return element;
}

void insert_item_stack(STACK *sk, int item)
{
    assert(sk != NULL);
    NODESTACK *new_node = (NODESTACK *)malloc(sizeof(NODESTACK));
    if (new_node != NULL)
    {
        new_node->info = item;
        new_node->next = sk->top;
        sk->top = new_node;
        sk->size++;
    }
}

void free_stack_alloc(STACK *sk)
{
    assert(sk != NULL);
    while (sk != NULL)
    {
        remove_item_stack(sk);
    }
    free(sk);
}

void view_stack(STACK *sk)
{
    assert(sk != NULL);
    printf("\n{");
    NODESTACK *aux = sk->top;
    for (int i = 0; i < size_stack(sk); i++)
    {
        (i != size_stack(sk) - 1) ? printf("%d, ", aux->info) : printf("%d", aux->info);
        aux = aux->next;
    }
    printf("}");
}