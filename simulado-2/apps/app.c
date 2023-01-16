#include "tree.h"
#include <stdio.h>

int main(){

    int n;
    ArvBin *raiz = ArvBin_create();

    while(1){
        scanf("%d", &n);
        if(n == -1)
            break;
        else
            ArvBin_insert(raiz, n);
    }

    printf("Numero de nos: %d\n", ArvBin_amount_nodes(raiz));
    printf("Altura da arvore: %d\n", ArvBin_height(raiz));

    printf("Pre-ordem: ");
    ArvBin_preOrdem(raiz);
    printf("\n");

    printf("Em-ordem: ");
    ArvBin_emOrdem(raiz);
    printf("\n");

    printf("Pos-ordem: ");
    ArvBin_posOrdem(raiz);
    printf("\n");

    return 0;
}