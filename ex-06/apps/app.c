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

    for(int i = 0; i < k; i++){
        for(int j = 0; j < k - 1; j++){
            
        }
    }

    printf("Fila Unica:\n");
    for(int i = 0; i < k; i++){
        LinkedList_print(L_vec[i]);
    }

    // Desalocando as Listas

    // for(int i = 0; i < k; i++){
    //     LinkedList_destroy(L_vec[i]);
    // }
    

    return 0;
}