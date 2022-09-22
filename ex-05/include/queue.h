#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

//*************************** HEADER DO TAD - ESPECIFICAÇÃO ***************************//

// Declaração da struct das Filas Estáticas

typedef struct _pessoa Pessoa;
typedef struct _queue Queue; 

// Assinatura das Funções do TAD

char *readline();
void free_readline(char *line);

Queue *Queue_create(long capacity);
void Queue_destroy(Queue **Q_ref);

bool Queue_is_empty(const Queue *Q);
bool Queue_is_full(const Queue *Q);
int Queue_size(const Queue *Q);

void Queue_enqueue(Queue *Q, int val);
int Queue_peek(const Queue *Q);
int Queue_dequeue(Queue *Q);

void Queue_print(const Queue *Q);

//************************************************************************//

#endif