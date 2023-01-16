#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void cria_avl(AVL *a) {
    a->raiz = NULL; // cria uma arvore vazia
    return;
}

void destroiSub(No *p) {
    if (p == NULL)
        return;
    destroiSub(p->esq); // destroi subarvore esquerda
    destroiSub(p->dir); // destroi subarvore direita
    free(p); // apaga o raiz da subarvore
    return;
}

void destroy_avl(AVL *a) {
    destroiSub(a->raiz); // inicia recursao
    a->raiz = NULL;
    return;
}

int vazia(AVL a) {
    return a.raiz == NULL;
}

void imprimeSub(No *raiz) {
    if (raiz != NULL) {
        printf("%d(", raiz->info);
        imprimeSub(raiz->esq);
        printf(",");
        imprimeSub(raiz->dir);
        printf(")");
    }
    else {
        printf("null");
    }
}

void imprime(AVL a) {
    imprimeSub(a.raiz);
    printf("\n");
    return;
}

int alturaSub(No *p) {
    int aesq, adir;
    if (p == NULL)
        return 0; // arvore nula
    aesq = alturaSub(p->esq); // altura da subarvore esquerda
    adir = alturaSub(p->dir); // altura da subarvore direita
    return (aesq > adir)? aesq + 1 : adir + 1;
}

int altura(AVL a) {
    return alturaSub(a.raiz); // inicia recursao
}

void posOrdemSub(No *p) {
    /*
        Desenvolva seu código aqui
    */
   if(p == NULL)
        return;
    if(*p != NULL){
        posOrdemSub(&((*p)->esq));
        posOrdemSub(&((*p)->dir));
        printf("%d\n",(*p)->info);
    }
}

void posOrdem(AVL a) {
    posOrdemSub(a.raiz); // inicia recursao
    printf("\n");
    return;
}

int buscaSub(No *p, elem x) {
    /*
        Desenvolva seu código aqui
    */
}

int busca_avl(AVL a, elem x) {
    return buscaSub(a.raiz, x); // inicia recursao
}


// rotacao simples a esquerda
void E(No **p) {
    /*
        Desenvolva seu código aqui
    */
}

// rotacao simples a direita
void D(No **p) {
    /*
        Desenvolva seu código aqui
    */
}

// Rotacao Esquerda Direita
void ED(No **p) {
    E(&((*p)->esq));
    D(p);
    return;
}

// Rotacao Direira Esquerda
void DE(No **p) {
    D(&((*p)->dir));
    E(p);
    return;
}

No *criaNo(elem info, No *esq, No *dir, int fb) {
    No *nova = malloc(sizeof(No));
    if (nova != NULL) {
        nova->info = info;
        nova->esq = esq;
        nova->dir = dir;
        nova->fb = fb;
    }
    return nova;
}

// atualiza fatores de balanceamento apos a rotacao dupla
void atualizaFB(No *p) {
    switch (p->fb) {
        case 1:
            p->dir->fb = 0;
            p->esq->fb = -1;
            break;
        case -1:
            p->dir->fb = 1;
            p->esq->fb = 0;
            break;
        case 0:
            p->dir->fb = 0;
            p->esq->fb = 0;
            break;
    }
    p->fb = 0;
}

int insercaoSub(No **p, elem x, int *cresceu) {
    // p => No **; *p => No *; **p => No
    int retorno;
    if (*p == NULL) {
        *p = criaNo(x, NULL, NULL, 0); // insere
        *cresceu = 1; // subarvore cresceu; era nula e agora tem o raiz
        return *p == NULL; // erro de memoria ou sucesso
    }
    if ((*p)->info == x)
        return 1; // erro, achou
    retorno = insercaoSub((x < (*p)->info) ? &((*p)->esq) : &((*p)->dir), x, cresceu);
    if (!retorno && *cresceu) { // atualiza fator de balanceamento e rebalanceia se necessario
        (*p)->fb += (x < (*p)->info) ? -1 : 1; // atualiza fator de balanceamento
        if ((*p)->fb == 0 || (*p)->fb == 2 || (*p)->fb == -2) {
            *cresceu = 0; // arvore parou de crescer: 0 => melhorou o balanceamento; 2 ou -2 => sera feito o rebalanceamento
            switch ((*p)->fb) {
                case 2: // arvore muito alta a direita
                    if ((*p)->dir->fb == 1) { // mesmo sinal
                        E(p); // rotacao simples a esquerda
                        // atualiza fatores de balanceamento
                        (*p)->fb = 0;
                        (*p)->esq->fb = 0;
                    } else { // sinais opostos
                        DE(p); // rotacao dupla direita-esquerda
                        atualizaFB(*p); // atualiza fatores de balanceamento
                    }
                    break;
                case -2: // arvore muito alta a esquerda
                    if ((*p)->esq->fb == -1) { // mesmo sinal
                        D(p); // rotacao simples a direita
                        // atualiza fatores de balanceamento
                        (*p)->fb = 0;
                        (*p)->dir->fb = 0;
                    } else { // sinais opostos
                        ED(p); // rotacao dupla esquerda-direita
                        atualizaFB(*p); // atualiza fatores de balanceamento
                    }
                    break;
            }
        }
    }
    return retorno;
}

int insercao_avl(AVL *a, elem x) {
    int cresceu;
    return insercaoSub(&(a->raiz), x, &cresceu); // inicia recursao
}

// int remover_sub(No** p, elem x, int *descresceu){
// 	//Busca pelo elemento a ser removido
		
// }

int remover_sub(No **raiz, elem x) {
    if (*raiz == NULL) 
        return 0;
    else if (x < (*raiz)->info)
        return remover_sub(&(*raiz)->esq, x); 
    else if (x > (*raiz)->info)
        return remover_sub(&(*raiz)->dir, x);
    else {
        // Remoção de Folhas
        if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
            free(*raiz);
            *raiz = NULL;
            return 1;
        } // caso tenha um filho só na direira
        else if ((*raiz)->esq == NULL) {
            No *aux = *raiz;
            *raiz = (*raiz)->dir;
            free(aux);
            return 1;
        } // caso tenha um filho só na esquerda
        else if ((*raiz)->dir == NULL) {
            No *aux = *raiz;
            *raiz = (*raiz)->esq;
            free(aux);
            return 1;
        }
        /*	Caso tenha os dois filhos. Pegar o maior do lado esquerdo, ou o menor do lado direito
         	e mover para o lugar do elemento que eu estou buscando remover. */
        else {
            // Nesta caso vou pegar o maior do lado esquerdo.
            No *aux = (*raiz)->esq;

            // Percorro até chegar no maior elemento.
            while (aux->dir != NULL)
                aux = aux->dir;
            
            // Minha raiz que eu quero remover, recebe o novo valor.
            (*raiz)->info = aux->info;

            /*  Chamo recursivamente para a parte esquerda, a partir do nó eu 
                troquei o valor, passando o valor do elemento que eu mandei pro
                nó. Assim, a remoção é feita. */
            return remover_sub(&(*raiz)->esq, aux->info);
            return 1;
        }
    }
}

int remover_avl(AVL *a, elem x){
	return remover_sub(&(a->raiz), x); //inicia recursao
}
