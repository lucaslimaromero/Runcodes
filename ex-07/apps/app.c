#include "linked_list.h"
#include <stdio.h>

int main(){
    
    int k; // Número de Filas

    scanf("%d", &k);

    LinkedList **L_vec = LinkedList_vector_create(k); // Criação do vetor de listas

    for(int i = 0; i < k; i++){
        LinkedList_read(L_vec[i]);
    }

    // É necessário criar uma forma de organizar esse vetor de listas conforme a ordem que devem ser printados

    L_vec = LinkedList_vector_ordenated(L_vec, k);

    // Printando a Fila Unica

    printf("Fila Unica:\n");
    for(int i = 0; i < k; i++){
        if(LinkedList_is_empty(L_vec[i]) == 0){ // Se não estiver vazia ele printa a lista
            LinkedList_print(L_vec[i]);
        }
    }

    // Desalocando as Listas

    for(int i = 0; i < k; i++){
        LinkedList_destroy(&L_vec[i]);
    }
    
    return 0;
}