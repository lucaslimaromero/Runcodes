#include <stdio.h>
#include <stdlib.h>

int *op1;
int *op2;

int exponencial(int n, int m){
    /*if(m == 0){
        return 1;
    }*/
    if(m == 1){
        *op1 *= 2;
        return n;
    }
    else{
        *op1 += 1;
        return n * exponencial(n, m - 1);
    }
}

int otimizada(int n, int m){
    if(m % 2 == 0){ // Par
        if(m == 2){
            *op2 += 1;
            *op2 *= 2;
            return n * n;
        }
        else{
            *op2 += 2;
            return (n * n) * otimizada(n * n, m / 2 - 1);
        }
        
    }

    else{ // Ímpar
        if(m == 1){
            *op2 *= 2;
            return n;
        }
        else{
            *op2 += 1;
            return n * otimizada(n, m - 1);
        }
    }
}

int main(){

op1 = malloc(sizeof(int));
op2 = malloc(sizeof(int));

*op1 = 0;
*op2 = 0;

int n, m;
scanf("%d %d", &n, &m);

printf("%d %d\n", exponencial(n, m), otimizada(n, m));

double razao = (double) *op1 / *op2;

printf("%d %d %.3lf", *op1, *op2, razao);

    return 0;
}