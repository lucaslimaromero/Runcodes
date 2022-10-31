#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//*************************** IMPLEMENTAÇÃO DO TAD ***************************//

typedef struct _snode{
    int val;
    struct _snode *next; // Não podemos colocar Node *next, pois o compilador lê de cima para baixo, e ainda não sabe o que é Node
} SNode;

typedef struct _linked_list{
    SNode *begin; // Ponteiro para o primeiro nó
    SNode *end; // Ponteiro para o último nó, utilizado na hora de adicionar na cauda da lista
    int size; // Tamanho da lista
} LinkedList;

LinkedList *LinkedList_create(){ // Alocar dinamicamente a estrutura de linked list para que o atributo begin aponte para NULL
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList)); // Alocando o primeiro Nó (Lista em si)
    L->begin = NULL; // A lista tem apenas um elemente, logo o ponteiro que aponta para o próximo é null
    L->end = NULL;
    L->size = 0;

    return L;
}

LinkedList **LinkedList_vector_create(int k){ // A ideia dessa função é alocar um vetor de ponteiros e posteriormente alocar memória para as 'k' listas
    LinkedList **L_vec = (LinkedList **) calloc(k, sizeof(LinkedList *));

    for(int i = 0; i < k; i++){
        L_vec[i] = LinkedList_create();
    }

    return L_vec;
}

bool LinkedList_repeated_elem(const LinkedList *L, int elem){

    SNode *p = L->begin;

    while(p != NULL){ // Enquanto p estiver apontando para um Nó válido
        if(p->val == elem){
            return 1; // Retorna 1 se achou algum elemento repetido
        }
        p = p->next;
    }
    
    return 0; // Retorna 0 se não achou nenhum elemento repetido
}

void LinkedList_read(LinkedList *L){
    int elem;

    while(1){
        scanf("%d", &elem);
        if(elem == -1){
            break; // return; ?
        }
        else{
            if(LinkedList_repeated_elem(L, elem) == 0){ // Se não existe elemento repetido
                LinkedList_add_last(L, elem);
            }
            else{
                printf("Elemento %d ja existe na fila\n", elem);
            }
        }
    }

    //return;
}

int LinkedList_size(const LinkedList *L){
    return L->size;
}

int LinkedList_begin(const LinkedList *L){
    return L->begin->val;
}

int LinkedList_end(const LinkedList *L){
    return L->end->val;
}

bool LinkedList_is_empty(const LinkedList *L){
    return (L->begin == NULL && L->end == NULL);
}

SNode *SNode_create(int val){ // Aloca um nó dinamicamente e atribui a ele um valor, bem como seta como NULL o ponteiro para o próximo elemento
    SNode *snode = (SNode *) calloc(1, sizeof(SNode));
    snode->val = val;
    snode->next = NULL;

    return snode;
}

void LinkedList_add_last(LinkedList *L, int val){
    SNode *q = SNode_create(val);

    if(LinkedList_is_empty(L)){ // Lista vazia - O primeiro e o último elemento são os mesmos
        L->begin = q;
        L->end = q;
    }
    else{ // Lista não vazia
        L->end->next = q; // Acessando o ponteiro next do último nó e colocando como o novo nó
        L->end = L->end->next; // Estou atualizando o ponteiro que aponta para o final da lista, agora apontando para o último nó recém-adicionado
    }

    L->size++;
}

void LinkedList_print(const LinkedList *L){
    SNode *p = L->begin;

    while(p != NULL){ // Enquanto p estiver apontando para um Nó válido
        printf("%d ", p->val);
        p = p->next;
    } 
}

void LinkedList_destroy(LinkedList **L_ref){
    LinkedList *L = *L_ref;

    SNode *p = L->begin;
    SNode *aux = NULL;

    while(p != NULL){
        aux = p;
        p = p->next;
        free(aux);
    }
    free(L);

    *L_ref = NULL;
}

//****************************************************************************//