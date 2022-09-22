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
void StackPrint(const Stack *S); // Printa os elementos ao desemplihá-los

// Funções específicas:

void StackSize(const Stack *S); // Ao receber 0
void StackPeek(const Stack *S); // Ao receber 10
void StackVinte(Stack *S); // Ao receber 20 -> Retirar os dois elementos do topo, somá-los e colocar na pilha o resultado dessa soma

//************************************************************************//

#endif