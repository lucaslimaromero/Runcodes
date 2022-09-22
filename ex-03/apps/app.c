#include "static_stack.h"
#include <stdio.h>

int main(){
    
    Stack *S = StackCreate(10000);
    int value;

    while(true){
        scanf("%d", &value);
        if(value == -1){
            StackPrint(S);
            break;
        }
        else if(value == 0){
            StackPop(S);
        }
        else{
            StackPush(S, value);
        }
    }

    StackDestroy(&S);

    return 0;
}