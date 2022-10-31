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
    LinkedList *L_aux;
    for(int j = 1; j < k; j++){
        for(int i = 0; i < k - 1; i++){
            if(LinkedList_size(L_vec[i]) < LinkedList_size(L_vec[i + 1])){
                L_aux = L_vec[i];
                L_vec[i] = L_vec[i + 1];
                L_vec[i + 1] = L_aux;
            }
            else if(LinkedList_size(L_vec[i]) == LinkedList_size(L_vec[i + 1])){
                if(LinkedList_begin(L_vec[i]) > LinkedList_begin(L_vec[i + 1])){
                    L_aux = L_vec[i];
                    L_vec[i] = L_vec[i + 1];
                    L_vec[i + 1] = L_aux;
                }
                else if(LinkedList_begin(L_vec[i]) == LinkedList_begin(L_vec[i + 1])){
                    if(LinkedList_end(L_vec[i]) > LinkedList_end(L_vec[i + 1])){
                        L_aux = L_vec[i];
                        L_vec[i] = L_vec[i + 1];
                        L_vec[i + 1] = L_aux;
                    }
                }
            }
        }
    }

    printf("Fila Unica:\n");
    for(int i = 0; i < k; i++){
        LinkedList_print(L_vec[i]);
    }

    // Desalocando as Listas

    for(int i = 0; i < k; i++){
        LinkedList_destroy(&L_vec[i]);
    }
    
    return 0;
}