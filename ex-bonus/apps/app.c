#include "queue.h"
#include <stdio.h>
#include <string.h>

int main(){
    
    /* Comandos:
    - Inserir !
    - Remover !
    - ImprimirEmOrdem !
    - ImprimirInvetido !
    */

   char *comando;
   List *L = List_create();
   char *name;
   int priority;

   while(scanf("%s", comando) != EOF){
   
    switch (comando)
    {
    case "Inserir":
        scanf("%d", &priority);
        name = ReadLine();
        break;

    case "Remover":
        List_remove(L);
        break;

    case "ImprimirEmOrdem":
        List_print(L);
        break;

    case "ImprimirInvertido":
        List_inverted_print(L);
        break;
    
    default:
        printf("Comando Inválido\n"); ////////////////////// Lembrar de verificar se tem acento no caso de teste
        break;
    }
  }

    List_destroy(L);
    return 0;
}