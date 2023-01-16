#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main() {
    AVL a;
    cria_avl(&a);

    elem n = 0;
    while(n != -1) {
        scanf("%d", &n);
        if (n != -1)
            insercao_avl(&a, n);
    }

    imprime(a);
    posOrdem(a);
    printf("\n");

    while ((scanf("%d", &n)) != EOF) {
        if(busca_avl(a, n))
            printf("Elemento %d existe na AVL\n", n);
        else
            printf("Elemento %d não existe na AVL\n", n);
    }

    destroy_avl(&a);

    return EXIT_SUCCESS;
}