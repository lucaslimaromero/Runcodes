#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

//*************************** IMPLEMENTAÇÃO DO TAD ***************************//

typedef struct _node{
    char *name;
    int age;
    int cond;
    struct _node *next;
}Node;

typedef struct _queue{
    Node *begin;
    Node *end;
    int size;
}Queue;

int Queue_size(const Queue *Q){
    return Q->size;
}

Queue *Queue_create(){

    Queue *Q = (Queue *) calloc(1, sizeof(Queue));
    Q->begin = NULL;
    Q->end = NULL;
    Q->size = 0;

    return Q;
}

bool Queue_is_empty(const Queue *Q){
    return Q->begin == NULL;
}

void Node_add(char *name, int age, int cond, Queue *Q) { // Cria um node e ainda enfileira a pessoa na sua fila de prioridade
    Node *node = (Node*) calloc(1, sizeof(Node));
    
    node->next = NULL;
    node->name = name;
    node->age = age;
    node->cond = cond;

    if(Queue_is_empty(Q)){
        Q->begin = node;
    }
    else{
        Q->end->next = node;
    }
    Q->size++;
    Q->end = node;
    
}

void Node_remove(Queue *Q){
    
    if(!Queue_is_empty(Q)){
        Node *p = Q->begin;
        Q->begin = Q->begin->next;
        Q->size--;
        printf("%s %d %d\n", p->name, p->age, p->cond);
    }
    
}

void Queue_destroy(Queue **Q_ref){
    Queue *Q = *Q_ref;
    Node *p = Q->begin;
    Node *aux = NULL;

    while (p != NULL) {
        aux = p;
        p = p->next;
        free(aux);
    }
    free(Q);

    *Q_ref = NULL;
}