#include <stdio.h>
#include <string.h>

int ctoi(char num){
    if(isDigit(num)){
        return num - '0';
    }
    return -1;
}

int evaluate(int n1, int n2, char elem){
    int i, result;
    switch(elem){
        case '+':
            return n1 + n2;
            break;
        case '-':
            return n1 - n2;
            break;
        case '*':
            return n1 * n2;
            break;
        case '/':
            return n1 / n2;
            break;
        case '%':
            return n1 % n2;
            break;
        case '>':
            return n1 > n2;
            break;
        case '<':
            return n1 < n2;
            break;
        case ',':
            return n1 <= n2;
            break;
        case '.':
            return n1 >= n2;
            break;
        case ']':
            return n1 == n2;
            break;
        case '&':
            return n1 && n2;
            break;
        case '!':
            return !n2;
            break;
        case '^':
            result = 1;
            for(i = 0; i < n2; i++){
                result*=n1;
            }
            return result;
            break;
    }
}

int output(String256 result)
{
    String256 output[MAX] = {};
    numStack nums;
    int i;
    int n1 = 0;
    int n2 = 0;
    int errorFlag = 0;

    initNumStack(&nums);

    for(i = 0; i < strlen(result); i++)
    {
        if(isDigit(result[i]))
        {
            n1 = 0;
            while(isDigit(result[i]))
            {
                n1 += ctoi(result[i]);
                i++;
                if(isDigit(result[i])){
                    n1*=10;
                }
            }
            i-=1;
            numPush(&nums, n1);
            n1 = 0;
        }else if (result[i] != ' '){
            n2 = numPop(&nums);
            if(!isEmptyNum(&nums))
                n1 = numPop(&nums);
            if(n2 == 0 && result[i] == '/'){
                printf("Division by zero error!");
                errorFlag = 1;
            }else{
                numPush(&nums, evaluate(n1, n2, result[i]));
            }
        }
    }
    
    if(!isEmptyNum(&nums) && !errorFlag){
        printf("%d\n", numPop(&nums));
    }

}

