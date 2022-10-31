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

LinkedList **LinkedList_vector_create(int k){ // A ideia dessa função é alocar um vetor de ponteiros e posteriormente alocar memória para as 'k' listas
    LinkedList **L_vec = (LinkedList **) calloc(k, sizeof(LinkedList *));

    for(int i = 0; i < k; i++){
        L_vec[i] = LinkedList_create();
    }

    return L_vec;
}

void LinkedList_read(LinkedList *L){
    int elem;

    while(1){
        scanf("%d", &elem);
        if(elem == -1){
            break;
        }
        else{
            LinkedList_add_last(L, elem);
        }
    }
}

bool LinkedList_is_empty(const LinkedList *L){ // Retorna 1 se estiver vazia e 0 se estiver com elementos
    return (L->size == 0);
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
    // printf("Size: %d ", L->size); // -> Os tamanhos estão sendo contados corretamente
}

void LinkedList_delete(LinkedList *L){
    //LinkedList_destroy(&L);
    //L->begin = L->end = NULL;
    L->size = 0;
}

LinkedList **LinkedList_vector_ordenated(LinkedList **L_vec, int k){

    LinkedList *L_aux;

    for(int j = 1; j <= k; j++){ // Esse primeiro for é responsável por fazer o processo de ordenação 2 a 2 ocorrer k - 1 vezes
        for(int i = 0; i < k - 1; i++){

            if(L_vec[i]->size < L_vec[i + 1]->size){
                L_aux = L_vec[i];
                L_vec[i] = L_vec[i + 1];
                L_vec[i + 1] = L_aux;
            }

            else if(L_vec[i]->size == L_vec[i + 1]->size){
                if(L_vec[i]->begin->val > L_vec[i + 1]->begin->val){
                    L_aux = L_vec[i];
                    L_vec[i] = L_vec[i + 1];
                    L_vec[i + 1] = L_aux;
                }

                else if(L_vec[i]->begin->val == L_vec[i + 1]->begin->val){
                    if(L_vec[i]->end->val > L_vec[i + 1]->end->val){
                        L_aux = L_vec[i];
                        L_vec[i] = L_vec[i + 1];
                        L_vec[i + 1] = L_aux;
                    }

                    else if (L_vec[i]->end->val == L_vec[i + 1]->end->val){ 
                        LinkedList_delete(L_vec[i]);
                        LinkedList_delete(L_vec[i + 1]);
                    }
                }
            }
        }
    }

    return L_vec;
}

//****************************************************************************//