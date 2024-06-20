#include <stdio.h>
#include <string.h>
#include "stack.h"

void initStack(Stack *s){
    s->top = -1;
}

void initNumStack(numStack *s){
    s->top = -1;
}

int isEmptyNum(numStack *s){
    return s->top == -1;
}

int isEmpty(Stack *s){
    return s->top == -1;
}

void numPush(numStack *s, int num){
    if(s->top == MAX - 1){
        printf("Stack overflow\n");
        return;
    }
    s->nums[++(s->top)] = num;
}

void push(Stack *s, char elem){
    if(s->top == MAX - 1){
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = elem;
}

int numPop(numStack *s){
    if (isEmptyNum(s)){
        printf("Stack underflow\n");
        return -1;
    }
    return s->nums[(s->top)--];
}

char pop(Stack *s){
    if (isEmpty(s)){
        printf("Stack underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

char peek(Stack *s){
    if(isEmpty(s)){
        return -1;
    }
    return s->items[s->top];
}

int precedence(char op) {
    switch (op) {
        case '|':
            return 1;
            break;
        case '&':
            return 2;
            break;
        case '=':
        case '~':
        case '<':
        case '>':
        case ',':
        case '.':
            return 3;
            break;
        case '+':
        case '-':
            return 4;
            break;
        case '*':
        case '/':
        case '%':
            return 5;
            break;
        case '!':
            return 6;
            break;
        case '^':
            return 7;
            break;
        default:
            return 0;
    }
}

int isLogicalOperator(char op){
    return op == '|' || op == '&' || op == '=' || op == '<' || op == '>' || op == '!';
}

int isDigit(char elem){
    return elem >= 48 && elem <= 57;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^' || ch == '(' || ch == ')';
}
