#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

//*************************** IMPLEMENTAÇÃO DO TAD ***************************//

typedef struct _doubly_node{
    int val;
    struct _doubly_node *next;
    struct _doubly_node *prev;
} DoublyNode, Node;

typedef struct _doubly_linked_list{
    Node *begin;
    Node *end;
    size_t size;
} DoublyLinkedList, List;

Node *Node_create(int val){
    Node *node = (Node *) calloc(1, sizeof(Node));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;

    return node;
}
List *List_create(){
    List *L = (List *) calloc(1, sizeof(List));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

void List_destroy(List **L_ref){
    List *L = *L_ref;
    Node *p = L->begin;
    Node *aux = p;

    while(p != NULL){
        aux = p;
        p = p->next;
        free(aux);
    }
    free(L);

    *L_ref = NULL;
}

bool List_is_empty(const List *L){
    return L->size == 0; // Se estiver vazia retorna 1 (true)
}


void List_add_first(List *L, int val){
    Node *p = Node_create(val);
    p->next = L->begin; // Não atrapalha caso a lista estiver vazia e é crucial caso ela não esteja

    if(List_is_empty(L)){ // Lista vazia
        L->end = p;
    }
    else{ // Lista não vazia
        L->begin->prev = p; // Essa linha só pode ser executada se L->begin for NÃO NULO, ou seja, se a lista não tiver vazia
    }

    L->begin = p;
    L->size++;
}

void List_add_last(List *L, int val){
    Node *p = Node_create(val);

    // Lista vazia
    if(List_is_empty(L)){
        L->begin = p;
        // L->end = p;
    }
    // Lista possui elementos
    else{
        L->end->next = p; // O próximo nó do nosso nó final antigo será o nosso novo nó
        p->prev = L->end; 
        // L->end = p;
    }

    L->end = p;
    L->size++;
}

void List_print(const List *L){
    Node *p = L->begin;

    printf("L -> ");
    while(p != NULL){
        printf("%d -> ", p->val);
        p = p->next;
    }
    puts("NULL");

    if(L->end == NULL){ // Lista vazia
        printf("L->end = NULL\n");
    }
    else{
        printf("L->end = %d\n", L->end->val);
    }

    printf("Size: %lu\n", L->size);
    puts("");
}

void List_inverted_print(const List *L){
    Node *p = L->end;

    printf("L -> end -> ");
    while(p != NULL){
        printf("%d -> ", p->val);
        p = p->prev;
    }
    puts("NULL");

    if(L->end == NULL){ // Lista vazia
        printf("L->begin = NULL\n");
    }
    else{
        printf("L->begin = %d\n", L->begin->val);
    }

    printf("Size: %lu\n", L->size);
    puts("");
}

void List_remove(List *L, int val){
    if(!List_is_empty(L)){
        Node *p = L->begin;
        if(L->begin->val == val){ // Caso 1: Removendo da cabeça da lista

            L->begin = p->next;

            if(L->end == p){ // Se a lista possuir apenas um elemento 
                // L->begin = NULL; é equivalente a L->begin = p->next;
                L->end = NULL;
            }
            else{ // Lista possui mais de um elemento
                p->next->prev = NULL;
            }
            free(p);
            L->size--;
        }

        else{ // Caso 2: No meio da lista
            p = p->next;

            while(p != NULL){
                if(p->val == val){
                    p->prev->next = p->next;
                    if(p == L->end){ // Caso 3, é o nó final
                        L->end = p->prev;
                        // L->end->next = NULL;
                    }
                    else{ // Caso 2: meio da lista
                        //p->prev->next = p->next;
                        p->next->prev = p->prev;
                    }

                    free(p);
                    p = NULL;
                    L->size--;
                }
                else{
                    p = p->next;
                }
                    
            }
        }
        
    }
}

//*************************** FIM DA IMPLEMENTAÇÃO DO TAD ********************//
