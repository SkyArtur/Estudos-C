#include <stdio.h>
#include <stdbool.h>

#include "list.h"
#include "row.h"
#include "stack.h"

/*
    Testes das funcionalidades da lista.
*/
void test_tamanho_da_lista(LIST *li)
{
    printf("\nTamanho da lista: %d itens", size_list(li));
}

void test_condicao_da_lista(LIST *li)
{
    view_list(li);
    (empty_list(li) == true) ? printf("\nLista vazia!") : printf("\nLista nao esta vazia!");
}

void test_inserir_na_lista(LIST *li, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        insert_item_list(li, i, (3 + i) * qtd);
    }
}

void test_obter_um_item_da_lista(LIST *li, int pos)
{
    printf("\nObtendo o item no indice %d da lista: ", pos);
    printf("%d", get_item_list(li, pos));
    view_list(li);
}

void test_remover_item_da_lista(LIST *li, int pos)
{
    printf("\nRemovendo o item no indice %d da lista: ", pos);
    printf("%d", remove_item_list(li, pos));
    view_list(li);
}

void test_funcionalidades_da_lista()
{
    LIST *li = create_list();
    printf("\n* Testes das Funcionalidades da lista");
    test_condicao_da_lista(li);
    test_tamanho_da_lista(li);
    test_inserir_na_lista(li, 5);
    test_condicao_da_lista(li);
    test_tamanho_da_lista(li);
    test_obter_um_item_da_lista(li, 2);
    test_tamanho_da_lista(li);
    test_remover_item_da_lista(li, 3);
    test_tamanho_da_lista(li);
    free_list_alloc(li);
    printf("\n\n");
}
/*
    Testes das funcionalidades da Fila.
*/
void test_inserir_na_fila(ROW *rw, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        insert_item_row(rw, (i + 1) * qtd);
    }
}

void test_condicao_da_fila(ROW *rw)
{
    view_row(rw);
    (empty_row(rw) == true) ? printf("\nFila vazia!") : printf("\nFila nao esta vazia!");
}

void test_remover_item_da_fila(ROW *rw)
{
    printf("\nRemovendo um item da fila: %d", remove_item_row(rw));
    view_row(rw);
}

void test_tamanho_da_fila(ROW *rw)
{
    printf("\nTamanho da fila: %d", size_row(rw));
}

void test_funcionalidades_da_fila()
{
    ROW *rw = create_row();
    printf("\n* Testes das Funcionalidades da Fila - FIFO - First in - First out");
    test_condicao_da_fila(rw);
    test_inserir_na_fila(rw, 5);
    test_condicao_da_fila(rw);
    test_tamanho_da_fila(rw);
    test_remover_item_da_fila(rw);
    test_tamanho_da_fila(rw);
    free_row_alloc(rw);
    printf("\n\n");
}
/*
    Testes das funcionalidades da Pilha.
*/
void test_inserir_na_pilha(STACK *sk, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        insert_item_stack(sk, (i + 1) * qtd);
    }
}

void test_tamanho_da_pilha(STACK *sk)
{
    printf("\nTamanho da pilha: %d", size_stack(sk));
}

void test_condicao_da_pilha(STACK *sk)
{
    view_stack(sk);
    (empty_stack(sk) == true) ? printf("\nPilha esta vazia!") : printf("\nPilha nao esta vazia!");
}

void test_remover_item_da_pilha(STACK *sk)
{
    printf("\nRemovendo um item da lista: %d", remove_item_stack(sk));
}

void test_funcionalidades_da_pilha()
{
    STACK *sk = create_stack();
    printf("\n* Testes das Funcionalidades da Pilha - LIFO - Last in - First out");
    test_condicao_da_pilha(sk);
    test_tamanho_da_pilha(sk);
    test_inserir_na_pilha(sk, 5);
    test_condicao_da_pilha(sk);
    test_tamanho_da_pilha(sk);
    test_remover_item_da_pilha(sk);
    test_condicao_da_pilha(sk);
    test_tamanho_da_pilha(sk);
    free_stack_alloc(sk);
    printf("\n\n");
}
/*
    Funcao teste.
*/
void test_estruturas()
{
    test_funcionalidades_da_lista();
    test_funcionalidades_da_fila();
    test_funcionalidades_da_pilha();
}
