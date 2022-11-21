#include "tree.h"

//*************************** IMPLEMENTAÇÃO DO TAD ***************************//
// Implementação do nó 

typedef struct _node{
    int info; // Informação que ele carrega
    struct _node *esq; // Endereço do nó à sua esquerda
    struct _node *dir; // Endereço do nó à sua direita
} Node; // Apelido para o struct _node = Node

Node *ArvBin_Node_create(int value){
    Node *node = (Node*) malloc(sizeof(Node));

    if(node == NULL){ // Verifica se deu certo a alocação
        printf("Erro na alocação do nó");
        return NULL;
    }

    node->info = value;
    node->dir = NULL;
    node->esq = NULL;

    return node;
}

ArvBin *ArvBin_create(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if (raiz != NULL){ // Caso a alocação tenha dado certo
        *raiz = NULL; // Estamos colocando o conteúdo desse ponteiro de ponteiro como nulo
    }
    return raiz;
}

void Node_destroy(Node *node){
    if(node == NULL){ // Se o endereço do nó já estiver nulo, pode-se parar a função
        return;
    }
    // Recursão: a função é executada até encontrar um nó NULO, após isso ocorre um desempilhamento dessas funções

    Node_destroy(node->esq);
    Node_destroy(node->dir);

    // O nó só é liberado, caso o nó da da sua esquerda e o da sua direita já tenham sido liberados
    free(node);
    node = NULL;
}

void ArvBin_destroy(ArvBin *raiz){
    if(raiz == NULL){ // Se o endereço raiz for nulo
        return; // A função é parada
    }
    Node_destroy(*raiz); // Envia-se o conteúdo de raiz (endereço de memória de ArvBin, que é o nó inicial da árvore)
    free(raiz); // Libera a raiz
}

bool ArvBin_is_empty(ArvBin *raiz){ // Conteúdo da raiz = endereço de memória para o primeiro nó
    if(raiz == NULL){ // Caso a memória não tenha sido alocada corretamente
        printf("Erro na alocação da memória da raiz");
        return 1;
    }
    if(*raiz == NULL){ // Caso a árvore não tenha nenhum nó
        return 1;
    }
    return 0; // Senão, a árvore não está vazia
}

int ArvBin_height(ArvBin *raiz){
    if(ArvBin_is_empty(raiz)){ // Condição de parada
        // Se a árvore estiver vazia, a sua altura é 0
        return 0;
    }

    int left_height = ArvBin_height(&((*raiz)->esq));
    int right_height = ArvBin_height(&((*raiz)->dir));

    // A altura da árvore é dada pela maior quantidade de arestas
    if(left_height > right_height){
        return (left_height + 1);
    }
    else{
        return (right_height + 1);
    }
}

int ArvBin_amount_nodes(ArvBin *raiz){
    if(ArvBin_is_empty(raiz)){ // Condição de parada
        return 0;
    }
    int left_height = ArvBin_amount_nodes(&((*raiz)->esq));
    int right_height = ArvBin_amount_nodes(&((*raiz)->dir));

    return (left_height + right_height + 1); // + 1 é o pai
}

void ArvBin_preOrdem(ArvBin *raiz){
    if(raiz == NULL){ // Se não alocou corretamente, a função para
        return; // Condição de parada
    }
    if(!ArvBin_is_empty(raiz)){ // Se a árvore não estiver vazia
        printf("%d ", (*raiz)->info); // RAIZ
        ArvBin_preOrdem(&((*raiz)->esq)); // ESQUERDA
        ArvBin_preOrdem(&((*raiz)->dir)); // DIREITA
    }
}

void ArvBin_emOrdem(ArvBin *raiz){
    if(raiz == NULL){ // Se não alocou corretamente, a função para
        return; // Condição de parada
    }
    if(!ArvBin_is_empty(raiz)){ // Se a árvore não estiver vazia
        ArvBin_emOrdem(&((*raiz)->esq)); // ESQUERDA
        printf("%d ", (*raiz)->info); // RAIZ
        ArvBin_emOrdem(&((*raiz)->dir)); // DIREITA
    }
}

void ArvBin_posOrdem(ArvBin *raiz){
    if(raiz == NULL){ // Se não alocou corretamente, a função para
        return; // Condição de parada
    }
    if(!ArvBin_is_empty(raiz)){ // Se a árvore não estiver vazia
        ArvBin_posOrdem(&((*raiz)->esq)); // ESQUERDA
        ArvBin_posOrdem(&((*raiz)->dir)); // DIREITA
        printf("%d ", (*raiz)->info); // RAIZ
    }
}

bool ArvBin_insert(ArvBin *raiz, int value){ // Sempre a inserção será numa folha
    if(raiz == NULL){ // Verifica se há problema na alocação da raiz
        return 0;
    }
    Node *novo = ArvBin_Node_create(value); // Novo nó que eu irei inserir
    
    // Procurar onde esse novo nó deve ser inserido
    if(*raiz == NULL){ // Árvore vazia
        *raiz = novo;
    }
    // Árvore não vazia => procurar onde esse elemento deve ser inserido
    else{
        Node *atual = *raiz;
        Node *anterior = NULL;

        while(atual != NULL){
            anterior = atual;

            if(value == atual->info){
                free(novo); // Preciso desalocar a memória que aloquei, pois o nó de fato não será inserido
                // printf("Elemento ja existe!");
                return 0; // Elemento já existe
            }

            if(value > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }

        if(value > anterior->info)
            anterior->dir = novo;
        else
            anterior->esq = novo;
    }
    return 1;
}
//****************************************************************************//