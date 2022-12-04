#ifndef _STACK_H_
#define _STACK_H_

struct NodeStack
{
    int info;
    struct NodeStack *next;
};

struct Stack
{
    struct NodeStack *top;
    int size;
};

typedef struct NodeStack NODESTACK;
typedef struct Stack STACK;

STACK* create_stack();
bool empty_stack(STACK* sk);
int top_stack(STACK* sk);
int size_stack(STACK* sk);
int remove_stack(STACK* sk);

void insert_stack(STACK* sk, int item);
void free_stack_alloc(STACK* sk);
void view_stack(STACK* sk);

#endif