#ifndef STACK_H
#define STACK_H

//*************************** HEADER DO TAD - ESPECIFICAÇÃO ***************************//

#include <stdbool.h>
#include <stddef.h>

typedef struct _stack Stack;

// Assinatura das Funções do TAD

Stack *StackCreate(size_t capacity); // Função que aloca a memória dinamicamente para a pilha
void StackDestroy(Stack **S_ref); // Função que desaloca a memória dinamicamente da pilha (é necessário enviar o endereço do ponteiro da pilha)

bool StackisEmpty(const Stack *S); // Verifica se a pilha está vazia - Somente leitura
bool StackisFull(const Stack *S); // Verifica se a a pilha está cheia - Somente leitura

void StackPush(Stack *S, int val); // Acrescenta um elemento "val" no topo da pilha
int StackPeek(const Stack *S); // Somente leitura do topo da pilha
void StackPop(Stack *S); // Função para retirar o último elemento da pilha
void StackPrint(const Stack *S);

//************************************************************************//

#endif