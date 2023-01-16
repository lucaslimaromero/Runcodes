typedef int elem;

typedef struct no {
    elem info;
    struct no *esq, *dir;
    int fb;
} No;

typedef struct {
    No *raiz;
} AVL;

void cria_avl(AVL *a);
void destroy_avl(AVL *a);
int vazia(AVL a);
void imprime(AVL a);
int altura(AVL a);
void posOrdem(AVL a);
int busca_avl(AVL a, elem x);
int insercao_avl(AVL *a, elem x);
int remover_avl(AVL *a, elem x);