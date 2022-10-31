#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

//*************************** HEADER DO TAD - ESPECIFICAÇÃO ***************************//

// Declaração da struct das Filas Estáticas

typedef struct _node Node;
typedef struct _queue Queue; 

// Assinatura das Funções do TAD

int Queue_size(const Queue *Q);
Queue *Queue_create();
void Queue_destroy(Queue **Q_ref);

void Node_add(char *name, int age, int cond, Queue *Q);
void Node_remove(Queue *Q);

bool Queue_is_empty(const Queue *Q);

//************************************************************************//

#endif