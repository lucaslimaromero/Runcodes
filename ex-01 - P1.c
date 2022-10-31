#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#define N 100

typedef struct _node{
    char val;
    struct _node *next;
} Node;

typedef struct _linked_list{
    Node *begin;
    Node *end;
    int size;
} List;

Node *Node_create(int val){
    Node *node = (Node *) calloc(1, sizeof(Node));
    node->val = val;
    node->next = NULL;

    return node;
}

List *List_create(){
    List *L = (List *) calloc(1, sizeof(List));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;

    return L;
}

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

bool List_is_empty(const List *L){
    return L->size == 0; // Se estiver vazia retorna 1 (true)
}

int List_size(List *L){
  return L->size;
}

void List_add_first(List *L, char d){ 
    Node *p = Node_create(d);
    p->next = L->begin; // O ponteiro do nó adicionado agora aponta para o mesmo lugar que L->begin apontava

    if(List_is_empty(L)){
        L->end = p;
    }
    L->begin = p; // L->begin passa a apontar para o novo Nó
    L->size++;
}

char List_get_val(const List *L, int index){
    if(List_is_empty(L)){
        exit(0);
    }
    else if(index < 0 || index >= L->size){
        printf("\nERRO\n");
        exit(0);
    }
    else{
      Node *p = L->begin;
      for (int i = 0; i < index; i++){
        p = p->next;
      }
        return p->val; // Retorna o valor no index solicitado
    }
} 

int main(void) {

  int v; /* value to add to the corresponding ASCII code */
  int f; /* frequency of character insertion */
  int k; /* counter */
  char p[13]; /* password + '\0'*/
  char c; /* a character to insert */
  char *s, e;

  List *L = List_create();

  if (scanf("%d %d %c %[0-9a-zA-Z ]", &v, &f, &c, p) != 4)
      exit(0);

  s = p;
  while(*s != '\0'){
     /*printf("%c\n", *s);*/
     List_add_first(L, *s);
     s++;
   }

  k = 0;
  while (k <= 12){
    
    e = List_get_val(L, k);
    if (k % f == 0){
      printf("%d", (int) c);
    }

    printf("%d", v + (int) e);
    k++;
   }
   printf("\n");

    List_destroy(&L);
  
  return 0;
}