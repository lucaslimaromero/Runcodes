#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int N; // Número de ações
    char *acao = NULL; // ENTRA ou SAI

    // Criação das 4 filas de prioridade

    Queue *Q1 = Queue_create();
    Queue *Q2 = Queue_create();
    Queue *Q3 = Queue_create();
    Queue *Q4 = Queue_create();

    // O programa recebe o número de ações feitas na fila
    
    scanf("%d", &N);
    //getchar();
    char *readline();

    for(int i = 0; i < N; i++){

        acao = readline();
        if(strcmp(acao, "ENTRA") == 0){
            char *name = NULL;
            int age, cond;
            name = readline();
            scanf("%d", &age);
            scanf("%d", &cond);
            if(age >= 60){
                if(cond == 1){
                    Node_add(name, age, cond, Q1);
                }
                else if(cond == 0) {
                    Node_add(name, age, cond, Q3);
                }
            }
            else{
                if(cond == 1){
                    Node_add(name, age, cond, Q2);
                }
                else if(cond == 0) {
                    Node_add(name, age, cond, Q4);
                }
            }
            //getchar();
            free(acao);
            
        }
        else if(strcmp(acao, "SAI") == 0){
            if(Queue_size(Q1)){
                Node_remove(Q1);
            }
            else if(Queue_size(Q2)){
                Node_remove(Q2);
            }
            else if(Queue_size(Q3)){
                Node_remove(Q3);
            }
            else if(Queue_size(Q4)){
                Node_remove(Q4);
            }
            else{
                printf("FILA VAZIA\n");
            }
            //getchar();
        }
        
    }

    // DESALOCAÇÃO DAS FILAS
    Queue_destroy(&Q1);
    Queue_destroy(&Q2);
    Queue_destroy(&Q3);
    Queue_destroy(&Q4);

    return 0;
}

char *readline(){ // Essa função retorna uma string alocada dinamicamente a cada char
    char *line = NULL;
    char c = '\0';
    int size = 0;

    while ((c = getchar()) == '\n'  || c == '\r');
    if (c != EOF)
        ungetc(c, stdin);

    do{
        c = getchar();
        line = (char *) realloc(line, ++size * sizeof(char));
        line[size - 1] = c;

    }while(c != ' ' && c != '\n' && c != '\r' && c != EOF);

    line[size - 1] = '\0';

    return line;
}