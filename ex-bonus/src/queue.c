#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _doubly_node{
    char *name;
    int priority;
    struct _doubly_node *next;
    struct _doubly_node *prev;
} DoublyNode, Node;

typedef struct _doubly_linked_list{
    int size;
    Node *begin;
    Node *end;
} DoublyLinkedList, List;

// Criação do Nó - Função chamada por outras que adicionam nós
void *Node_create(char *name, int priority){
    Node *node = (Node *) calloc(1, sizeof(Node));

    node->name = name;
    node->priority = priority;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

// Criação da Lista
List *List_create(){
    List *L = (List *) calloc(1, sizeof(List));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

// Destruição da Lista
void List_destroy(List **L_ref){
    List *L = *L_ref;
    Node *p = L->begin;
    Node *aux = p;

    while(p != NULL){
        aux = p;
        p = p->next;
        free(aux);
    }
    free(L);

    *L_ref = NULL;
}

// Função que retorna 1 se a lista estiver vazia
bool List_is_empty(const List *L){
    return (L->size == 0);
}

// Função que adiciona as pessoas de acordo com a ordem de prioridade
void List_add(List *L, char *name; int priority){
    Node *node = Node_create(name, priority); // Nó a ser inserido

    // Lista Vazia
    if(List_is_empty(L)){
        L->begin = L->end = node;
        L->size++;
    }
    // Lista com elementos
    else{ // Será necessário analisar as prioridades
        Node *p = L->begin; // Ponteiro que guarda no final do while o nó posterior ao nó a ser inserido
        Node *aux = p; // Ponteiro que guarda no final do while o nó anterior ao nó a ser inserido

        while(node->priority > p->priority){
            aux = p;
            p = p->next;
        }

        if(node->priority == p->priority){
            printf("INVALIDO\n");
        }

        else{
            aux->next = node;
            p->prev = node;
            L->size++;
        }
    }
}

// Função que remove a primeira pessoa da fila
void List_remove(List *L){
    Node *p = L->begin;
    if(List_is_empty(L)){
        printf("Fila Vazia\n");
    }
    else{
        L->begin = p->next;

        if(p == L->end){ // Lista com apenas 1 elemento
            L->end = NULL;
        }
        else{
            p->next->prev = NULL;
        }
        
        free(p->name);
        free(p);

        L->size--;
    }
}

// Função que imprime em ordem
void List_print(const List *L){
    Node *p = L->begin;

    if(List_is_empty(L)){
        printf("Lista Vazia\n");
    }
    else{
        while(p != NULL){
            printf("%d - %s; ", p->priority, p->name);
            p = p->next;
        }
    }
    puts("");
}

// Função que imprime invertido
void List_inverted_print(const List *L){
    Node *p = L->end;

    if(List_is_empty(L)){
        printf("Lista Vazia\n");
    }
    else{
        while(p != NULL){
            printf("%d - %s; ", p->priority, p->name);
            p = p->prev;
        }
    }
    puts("");
}

// Função para ler nomes
char *ReadLine(){ // Essa função retorna uma string alocada dinamicamente a cada char
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

    } while(c != ' ' && c != '\n' && c != '\r' && c != EOF);

    line[size - 1] = '\0';

    return line;
}

