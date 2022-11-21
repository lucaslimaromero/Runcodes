#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//*************************** HEADER DO TAD - ESPECIFICAÇÃO ***************************//

typedef struct _node Node; // Definição de um apelido para struct Node
typedef struct _node *ArvBin; // Ponteiro "árvore" (*ArvBin) || ArvBin é um ponteiro para o primeiro nó

// Assinatura e Protótipo das Funções do TAD

// Criação de um nó qualquer
Node *ArvBin_Node_create(int value);

// Criação da árvore: ato de criar a raiz da árvore (nó especial que aponta para o primeiro elemento da árvore)
ArvBin *ArvBin_create(); // Função que retorna um ponteiro/endereço de ArvBin

// Destruição da árvore
// Libera Nós (percorre a árvore e libera a memória de cada um dos nós)
void Node_destroy(Node *node); // Função que recebe um ponteiro que aponta para um nó da árvore
// Libera Árvore (libera a raiz da árvore e chama a função libera nós)
void ArvBin_destroy(ArvBin *raiz); // Função que recebe um ponteiro que aponta para ArvBin

// Informações básicas sobre a árvore
bool ArvBin_is_empty(ArvBin *raiz); // Retorna 1 se a árvore estiver vazia
int ArvBin_height(ArvBin *raiz); // Recebe inicialmente a raiz da árvore a ser analisada, e depois cada nó
int ArvBin_amount_nodes(ArvBin *raiz);

// Percorrendo uma Árvore Binária
// Pré-Ordem: RAIZ - ESQUERDA - DIREITA
void ArvBin_preOrdem(ArvBin *raiz);

// Em-Ordem: ESQUERDA - RAIZ - DIREITA
void ArvBin_emOrdem(ArvBin *raiz);

// Pós-Ordem: ESQUERDA - DIREITA - RAIZ 
void ArvBin_posOrdem(ArvBin *raiz);

// Inserção de um valor na árvore
bool ArvBin_insert(ArvBin *raiz, int value); // Retorna 1 se foi efetuada a operação, e 0 se o elemento já existe ou se não alocou

//*************************************************************************************//

#endif