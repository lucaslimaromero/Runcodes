#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    /* Comandos:
    - Inserir !
    - Remover !
    - ImprimirEmOrdem !
    - ImprimirInvetido !
    */

    char *comando = NULL;
    List *L = List_create();
    char *name;
    int priority;

    while(1){
   
        comando = ReadLine_comando();
        if(strcmp(comando, "Inserir") == 0){
            scanf("%d", &priority);
            getchar();
            name = ReadLine_nomes();
            if(name != NULL){
                List_add(L, name, priority);
            }
        }
        else if(strcmp(comando, "Remover") == 0){
            List_remove(L);
        }
        else if(strcmp(comando, "ImprimirEmOrdem") == 0){
            List_print(L);
        }
        else if(strcmp(comando, "ImprimirInvertido") == 0){
            List_inverted_print(L);
        }
        // Para teste
        else if(strcmp(comando, "x") == 0){
            break;
        }
        else{
            printf("Comando Inválido\n");
        }
    }

    List_destroy(&L);
    
    return 0;
}