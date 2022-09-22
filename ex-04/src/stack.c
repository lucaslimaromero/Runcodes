#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//*************************** IMPLEMENTAÇÃO DO TAD ***************************//

typedef struct _stack {
    size_t capacity;
    int *data;
    int top;
}Stack;

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

bool StackisEmpty(const Stack *S){
    return S->top == -1;
}

bool StackisFull(const Stack *S){
    return S->top == (S->capacity - 1);
}

void StackPush(Stack *S, int val){
    if(StackisFull(S)){
        // fprintf(stderr, "ERRO em 'StackPush'\n"); 
        // fprintf(stderr, "A pilha está cheia\n");
        exit(EXIT_FAILURE);
    }

    S->data[++S->top] = val; 
}

void StackSize(const Stack *S){ // 0
    printf("Quantidade de elementos: %d\n", S->top + 1);
}

void StackPeek(const Stack *S){ // 10
    if(StackisEmpty(S)){
        // fprintf(stderr, "ERROR in 'StaticStack_peek'\n");
        // fprintf(stderr, "A pilha está vazia\n");
        exit(EXIT_FAILURE);
    }

    printf("%d\n", S->data[S->top]); // Elemento da pilha (S->data) na posição do topo (S->top)
}

void StackVinte(Stack *S){ // 20
    int soma;
    soma = S->data[S->top] + S->data[S->top - 1];
    S->top = S->top - 2;
    StackPush(S, soma);
}

void StackPrint(const Stack *S){
    puts("");
    if(StackisEmpty(S)){
        printf("Pilha Vazia\n");
    }
    else{
        for(long i = S->top; i >= 0 ; i--){
            printf("%d\n", S->data[i]); 
        }
    }
    
}