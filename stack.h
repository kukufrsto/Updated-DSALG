#include <stdio.h>
#include <string.h>

#define MAX 100

typedef char String256[257];

typedef struct{
    char items[MAX];
    int top;
}Stack;

typedef struct{
    int nums[MAX];
    int top;
}numStack;
