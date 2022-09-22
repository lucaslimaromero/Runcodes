#include "stack.h"
#include <stdio.h>

int main(){
    
    Stack *S = StackCreate(100);
    int value;

    while(true){
        scanf("%d", &value);
        if(value == -1){
            break;
        }
        else if(value == 0){
            StackSize(S);
        }
        else if(value == 10){
            StackPeek(S);
        }
        else if(value == 20){
            StackVinte(S);
        }
        else{
            StackPush(S, value);
        }
    }

    StackPrint(S);
    StackDestroy(&S);

    return 0;
}