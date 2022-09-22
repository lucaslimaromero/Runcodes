#include "static_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//*************************** IMPLEMENTAÇÃO DO TAD ***************************//

typedef struct _stack {
    size_t capacity; // Capacidade Máxima da pilha (10.000)
    int *data; // Aponta para os dados da pilha
    int top; // Guarda o índice do topo
} Stack;

Stack *StackCreate(size_t capacity){
    Stack *S = (Stack *) calloc(1, sizeof(Stack)); // Aloca dinamicamente um espaço na memória Heap equivalente ao tamanho de Stack, retornando um ponteiro para essa struct
    S->capacity = capacity; // A capacidade máxima é setada com o valor introduzido
    S->top = -1; // Pilha vazia => topo = -1 (valor inválido)
    S->data = (int *) calloc(S->capacity, sizeof(int)); // Aloca dinamicamente o vetor que armazena os dados da pilha

    return S;
}

void StackDestroy(Stack **S_ref){ // Recebe o endereço de um ponteiro que aponta para uma Struct Pilha
    Stack *S = *S_ref; // O conteúdo de S_ref é o próprio ponteiro S que aponta para a struct

    free(S->data); // Primeiro, desaloca-se o vetor da pilha
    free(S); // Depois desaloca-se o ponteiro para a pilha
    *S_ref = NULL; // O ponteiro que antes apontava para a pilha, agora aponta para um "terra" (NULL)
}

bool StackisFull(const Stack *S){
    return S->top == (S->capacity - 1);
}

void StackPush(Stack *S, int val){
    if(StackisFull(S)){
        // fprintf(stderr, "ERRO em 'StackPush'\n"); // Prints para teste do código
        // fprintf(stderr, "A pilha está cheia\n");
        exit(EXIT_FAILURE);
    }

    S->data[++S->top] = val; 
}

void StackPop(Stack *S){
    S->top--; // O próximo valor digitado em Push sobrescreverá esse lixo de memória de S->data[S->top]
}

void StackPrint(const Stack *S){
    for(long i = S->top; i >= 0 ; i--){
        printf("%c", (char) S->data[i]); // Casting para transformar inteiro em dígito do alfabeto ASCII
    }
}