#include <stdio.h>
#include <string.h>
#include "intopost.c"
#include "evaluate.c"
#include "queue.c"
#include "eval-postfix.c"

int main() {
    String256 input;
    String256 result;
    Queue postfixQueue;

    // Initialize the queue
    initQueue(&postfixQueue);

    while (1) {
        // Read input
        scanf("%s", input);

        // Check for QUIT command
        if (strcmp(input, "QUIT") == 0) {
            break;
        }

        // Convert infix to postfix
        intopost(input, result);

        // Enqueue the postfix expression into the queue
        char *token = strtok(result, " ");
        while (token != NULL) {
            enqueue(&postfixQueue, token);
            token = strtok(NULL, " ");
        }

        // Print the postfix expression
        printf("%s\n", result);

        // Evaluate the postfix expression
        evaluatePostfix(&postfixQueue);
    }

    return 0;
}
