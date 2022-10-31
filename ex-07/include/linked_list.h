#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//*************************** HEADER DO TAD - ESPECIFICAÇÃO ***************************//

#include <stdbool.h>

typedef struct _snode SNode;
typedef struct _linked_list LinkedList;

// Assinatura das Funções do TAD

// Função que cria um nó (aloca) e atribui a ele um valor inteiro, p ex.(val)


LinkedList *LinkedList_create();
LinkedList **LinkedList_vector_create(int k); // Cria um vetor de listas

void LinkedList_read(LinkedList *L);
SNode *SNode_create(int val);
bool LinkedList_is_empty(const LinkedList *L);

// Inserção na cauda (final) da lista
void LinkedList_add_last(LinkedList *L, int val);

// Impressão dos Elementos da Lista
void LinkedList_print(const LinkedList *L);

// Função para deletar a lista
void LinkedList_delete(LinkedList *L);

// Função ordena o vetor de lista
LinkedList **LinkedList_vector_ordenated(LinkedList **L_vec, int k);

// Funções para desalocar a LinkedList
void LinkedList_destroy(LinkedList **L_ref);

//*************************************************************************************//

#endif