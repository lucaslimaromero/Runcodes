#include <stdio.h>
#include <stdlib.h>

int *op1;
int *op2;

int somaPA(int a1, int r, int n){
  if(n == 0){
    *op1 *= 2;
    return 0;
  }
  else{
    *op1 += 1;
    return a1 + somaPA(a1 + r, r, n - 1);
  }
}

int somaFormula(int a1, int r, int n){

  int an = a1 + (n - 1) * r; // a1 + n * r + 1 * r => 4 operações 
  *op2 += 4;

  *op2 += 4;
  return n * (a1 + an) / 2; // (n * a1 + n * an) / 2 => 4 operações 
  
}

int main(){

  op1 = malloc(sizeof(int));
  op2 = malloc(sizeof(int));

  *op1 = 0;
  *op2 = 0;
  
  int a1, r, n;

  scanf("%d %d %d", &a1, &r, &n);
  
  printf("%d %d\n", somaPA(a1, r, n), somaFormula(a1, r, n));
  
  double razao = (double) *op1 / *op2;
  
  printf("%d %d %.4lf", *op1, *op2, razao);
  
  return 0;
}