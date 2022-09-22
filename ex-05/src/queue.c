#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

//*************************** IMPLEMENTAÇÃO DO TAD ***************************//

typedef struct _pessoa{
    char *name;
    int age;
    int priority;
} Pessoa;

typedef struct _queue{
    Pessoa *pessoa;
    int capacity; // Capacidade máxima (nesse caso = 100)
    int size; // Mostra se a fila está vazia
    int begin;
    int end;
} Queue;

Queue *Queue_create(int capacity) {
    Queue *Q = (Queue*) calloc(1, sizeof(Queue));
    Q->data = (int*) calloc(capacity, sizeof(int));
    Q->capacity = capacity;
    Q->size = 0;
    Q->begin = 0;
    Q->end = 0;

    return Q;
}

void Queue_destroy(Queue **Q_ref){
    Queue *Q = *Q_ref;

    free(Q->data);
    free(Q);

    *Q_ref = NULL;
}

bool Queue_is_empty(const Queue *Q){
    return Q->size == 0;
}

bool Queue_is_full(const Queue *Q){
    return Q->size == Q->capacity;
}

int Queue_size(const Queue *Q){
    return Q->size;
}

void Queue_set_priority(){

}

void Queue_enqueue(Queue *Q, int val){
    if(Queue_is_full(Q)){
        fprintf(stderr, "ERRO em 'Queue_enqueue'\n");
        fprintf(stderr, "A fila está cheia\n");
        exit(EXIT_FAILURE);
    }
    // Nessa função é necessário criar condicionais para alocar uma pessoa na fila de acordo com a prioridade que carrega
    
    Q->data[Q->end] = val;
    Q->end = (Q->end + 1) % Q->capacity;
    Q->size++;
}

int Queue_peek(const Queue *Q){
    if(Queue_is_empty(Q)){
        fprintf(stderr, "ERRO em 'Queue_peek'\n");
        fprintf(stderr, "A fila está vazia\n");
        exit(EXIT_FAILURE);
    }

    return Q->data[Q->begin];
}

int Queue_dequeue(Queue *Q){
    if(Queue_is_empty(Q)){
        fprintf(stderr, "ERRO em 'Queue_peek'\n");
        fprintf(stderr, "A fila está vazia\n");
        exit(EXIT_FAILURE);
    }

    int val = Q->data[Q->begin];
    Q->begin = (Q->begin + 1) % Q->capacity;
    Q->size--;

    return val;
}

void Queue_print(const Queue *Q){

}

char *readline(){ // Essa função retorna uma string alocada dinamicamente a cada char
    char *line = NULL;
    char c = '\0';
    int size = 0;

    while ((c = getchar()) == '\n'  || c == '\r');
    if (c != EOF)
        ungetc(c, stdin);

    do{
        c = getchar();
        line = (char *) realloc(line, ++size * sizeof(char));
        line[size - 1] = c;

    }while(c != ' ' && c != '\n' && c != '\r' && c != EOF);

    line[size - 1] = '\0';

    return line;
}

void free_readline(char *line){
    free(line);
}