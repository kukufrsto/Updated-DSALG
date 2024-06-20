#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 256

typedef struct {
    char items[MAX][MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q);
int isEmptyQueue(Queue *q);
int isFullQueue(Queue *q);
void enqueue(Queue *q, char *item);
char* dequeue(Queue *q);

#endif
