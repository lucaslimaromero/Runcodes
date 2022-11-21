#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//*************************** HEADER DO TAD - ESPECIFICAÇÃO ***************************//

typedef struct _node Node; // Definição de um apelido para struct Node
typedef struct _node *ArvBin; // Ponteiro "árvore" (*ArvBin) || ArvBin é um ponteiro para o primeiro nó

// Assinatura e Protótipo das Funções do TAD

// Criação de um nó qualquer
Node *ArvBin_Node_create(int value, int s, int t, int c);

// Criação da árvore: ato de criar a raiz da árvore (nó especial que aponta para o primeiro elemento da árvore)
ArvBin *ArvBin_create(); // Função que retorna um ponteiro/endereço de ArvBin

// Destruição da árvore
// Libera Nós (percorre a árvore e libera a memória de cada um dos nós)
void Node_destroy(Node *node); // Função que recebe um ponteiro que aponta para um nó da árvore
// Libera Árvore (libera a raiz da árvore e chama a função libera nós)
void ArvBin_destroy(ArvBin *raiz); // Função que recebe um ponteiro que aponta para ArvBin

// Informações básicas sobre a árvore
bool ArvBin_is_empty(ArvBin *raiz); // Retorna 1 se a árvore estiver vazia
int ArvBin_height(ArvBin *raiz); // Recebe inicialmente a raiz da árvore a ser analisada, e depois cada nó
int ArvBin_amount_nodes(ArvBin *raiz);

// Em-Ordem: ESQUERDA - RAIZ - DIREITA
void ArvBin_emOrdem(ArvBin *raiz);

// Função de Rotação LL
void ArvBin_RotationLL(ArvBin *raiz);

// Função de Rotação RR
void ArvBin_RotationRR(ArvBin *raiz);

// Função de Rotação LR
void ArvBin_RotationLR(ArvBin *raiz);

// Função de Rotação RL
void ArvBin_RotationRL(ArvBin *raiz);

// Inserção de um valor na árvore
bool ArvBin_insert(ArvBin *raiz, int value, int s, int t, int c); // Retorna 1 se foi efetuada a operação, e 0 se o elemento já existe ou se não alocou

//************************************************************************//

// Implementação do TAD

// Implementação do nó 
typedef struct _node{
    int info; // Informação que ele carrega
    int s, t, c;
    int alt; // Altura da sub-árvore, cujo pai é o nó em questão para calcular o fb de cada nó
    struct _node *esq; // Endereço do nó à sua esquerda
    struct _node *dir; // Endereço do nó à sua direita
} Node; // Apelido para o struct _node = Node

Node *ArvBin_Node_create(int value, int s, int t, int c){
    Node *node = (Node*) malloc(sizeof(Node));

    if(node == NULL){ // Verifica se deu certo a alocação
        return NULL;
    }

    node->info = value;
    node->s = s;
    node->t = t;
    node->c = c;
    node->alt = 0;
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
        return 1;
    }
    if(*raiz == NULL){ // Caso a árvore não tenha nenhum nó
        return 1;
    }
    return 0; // Senão, a árvore não está vazia
}

int ArvBin_height(ArvBin *raiz){
    if(ArvBin_is_empty(raiz)){ // Condição de parada
        // Se a árvore estiver vazia, a sua alt é 0
        return 0;
    }

    int left_height = ArvBin_height(&((*raiz)->esq));
    int right_height = ArvBin_height(&((*raiz)->dir));

    // A alt da árvore é dada pela maior quantidade de arestas
    if(left_height > right_height){
        return (left_height + 1);
    }
    else{
        return (right_height + 1);
    }
}

void ArvBin_emOrdem(ArvBin *raiz){
    if(raiz == NULL){ // Se não alocou corretamente, a função para
        return; // Condição de parada
    }
    if(!ArvBin_is_empty(raiz)){ // Se a árvore não estiver vazia
        ArvBin_emOrdem(&((*raiz)->esq)); // ESQUERDA // printf("%d %d %d\n",(*raiz)->s, (*raiz)->t, (*raiz)->c);
        printf("%d %d %d\n", (*raiz)->s, (*raiz)->t, (*raiz)->c); // RAIZ
        ArvBin_emOrdem(&((*raiz)->dir)); // DIREITA
    }
}

// ------------- Funções Auxiliares ------------- //
int alt_node(Node *node){ // Recebe um nó e devolve a alt dele
    if(node == NULL) // Se o nó for nulo (não existir), a alt dele será considerada -1
        return -1;
    else
        return node->alt;
}

int fatorBalanceamento_node(Node *node){ // Quero saber a diferença em módulo das alts dos filhos do nó
    return labs(alt_node(node->esq) - alt_node(node->dir));
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}
// -------------------------------------------- //

// Função de Rotação LL
void ArvBin_RotationLL(ArvBin *raiz){
    Node *node; // Nó auxiliar para guardar o endereço do filho da esquerda
    node = (*raiz)->esq;
    (*raiz)->esq = node->dir;
    node->dir = *raiz;

    // Recalculando as alts
    (*raiz)->alt = maior(alt_node((*raiz)->esq), alt_node((*raiz)->dir)) + 1;
    node->alt = maior(alt_node(node->esq), (*raiz)->alt) + 1;

    *raiz = node;
}

// Função de Rotação RR
void ArvBin_RotationRR(ArvBin *raiz){
    Node *node; // Nó auxiliar para guardar o endereço do filho da direita
    node = (*raiz)->dir;
    (*raiz)->dir = node->esq;
    node->esq = *raiz;

    // Recalculando as alts
    (*raiz)->alt = maior(alt_node((*raiz)->esq), alt_node((*raiz)->dir)) + 1;
    node->alt = maior(alt_node(node->esq), (*raiz)->alt) + 1;

    *raiz = node;
}

void ArvBin_RotationLR(ArvBin *raiz){
    ArvBin_RotationRR(&(*raiz)->esq);
    ArvBin_RotationLL(raiz);
}

void ArvBin_RotationRL(ArvBin *raiz){
    ArvBin_RotationLL(&(*raiz)->dir);
    ArvBin_RotationRR(raiz);
}

bool ArvBin_insert(ArvBin *raiz, int value, int s, int t, int c){ // Sempre a inserção será numa folha
    int res;

    // Árvore vazia ou nó folha
    if(*raiz == NULL){ 
        Node *novo = ArvBin_Node_create(value, s, t, c);
        if(novo == NULL)
            return 0;
        
        *raiz = novo;
        return 1;
    }

    Node *atual = *raiz;
    if(value < atual->info){
        if((res = ArvBin_insert(&(atual->esq), value, s, t, c)) == 1){
            if(fatorBalanceamento_node(atual) >= 2){
                if(value < (*raiz)->esq->info){
                    ArvBin_RotationLL(raiz);
                }
                else{
                    ArvBin_RotationLR(raiz);
                }
            }
        }
    }
    else{
        if(value > atual->info){
            if((res = ArvBin_insert(&(atual->dir), value, s, t, c)) == 1){
                if(fatorBalanceamento_node(atual) >= 2){
                    if((*raiz)->dir->info < value){
                        ArvBin_RotationRR(raiz);
                    }
                    else{
                        ArvBin_RotationRL(raiz);
                    }
                }
            }
        }
        else{
            printf("Valor duplicado!\n");
            return 0;
        }
    }
    atual->alt = maior(alt_node(atual->esq), alt_node(atual->dir)) + 1;

    return res;
}

int main(){

    ArvBin *avl = ArvBin_create();

    int value, s, t, c;
    while (scanf("%d %d %d %d", &value, &s, &t, &c) != EOF){
        ArvBin_insert(avl, value, s, t, c);
    }

    ArvBin_emOrdem(avl);
    printf("%d", ArvBin_height(avl));

    ArvBin_destroy(avl);

    return 0;
    
}