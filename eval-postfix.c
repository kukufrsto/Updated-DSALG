#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "queue.h"

void evaluatePostfix(Queue *postfixQueue) {
    numStack nums;
    initNumStack(&nums);

    while (!isEmptyQueue(postfixQueue)) {
        char *token = dequeue(postfixQueue);

        if (isDigit(token[0])) {
            numPush(&nums, atoi(token));
        } else {
            int n2 = numPop(&nums);
            int n1 = numPop(&nums);
            int result;

            switch (token[0]) {
                case '+':
                    result = n1 + n2;
                    break;
                case '-':
                    result = n1 - n2;
                    break;
                case '*':
                    result = n1 * n2;
                    break;
                case '/':
                    if (n2 == 0) {
                        printf("Division by zero error!\n");
                        return;
                    }
                    result = n1 / n2;
                    break;
                case '%':
                    result = n1 % n2;
                    break;
                case '^':
                    result = 1;
                    for (int i = 0; i < n2; i++) {
                        result *= n1;
                    }
                    break;
                case '>':
                    result = n1 > n2;
                    break;
                case '<':
                    result = n1 < n2;
                    break;
                case ',':
                    result = n1 <= n2;
                    break;
                case '.':
                    result = n1 >= n2;
                    break;
                case ']':
                    result = n1 == n2;
                    break;
                case '&':
                    result = n1 && n2;
                    break;
                case '|':
                    result = n1 || n2;
                    break;
                case '!':
                    result = !n2;
                    numPush(&nums, result);
                    continue;
            }
            numPush(&nums, result);
        }
    }

    if (!isEmptyNum(&nums)) {
        printf("%d\n", numPop(&nums));
    }
}
