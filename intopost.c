#include <stdio.h>
#include <string.h>
#include "stack.c"

void intopost(String256 input, String256 result){
    Stack operators;
    int i;
    int x = 0;

    initStack(&operators);

    for(i = 0; i < strlen(input); i++){
        if(isDigit(input[i])){
            while(isDigit(input[i])){
            result[x++] = input[i++];
            }
            result[x++] = ' ';
            i--;
        }else if(input[i] == '('){
            push(&operators, input[i]);
        }else if(input[i] == ')'){
            char elem;
            while((elem = pop(&operators)) != '('){
                result[x++] = elem;
                result[x++] = ' ';
            }
        }else{
            char rep = input[i];
            if(isLogicalOperator(rep) && isLogicalOperator(input[i+1]))
            {
                switch(rep)
                {
                    case '!':
                        rep = '[';
                        break;
                    case '<':
                        rep = ',';
                        break;
                    case '>':
                        rep = '.';
                        break;
                    case '=':
                        rep = ']';
                        break;
                }
                i++;
            }
            while(operators.top != -1 && precedence(rep) <= precedence(operators.items[operators.top])){
                result[x++] = pop(&operators);
                result[x++] = ' ';
            }
            push(&operators, rep);
        }
    }

    while(!isEmpty(&operators)){
        result[x++] = pop(&operators);
        result[x++] = ' ';
    }

    result[x++] = '\0';

    printf("%s\n", result);

}