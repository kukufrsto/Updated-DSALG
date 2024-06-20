#include "queue.h"
#include <string.h>

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmptyQueue(Queue *q) {
    return q->front == -1;
}

int isFullQueue(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

void enqueue(Queue *q, char *item) {
    if (isFullQueue(q)) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmptyQueue(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    strcpy(q->items[q->rear], item);
}

char* dequeue(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue underflow\n");
        return NULL;
    }
    char *item = q->items[q->front];
    if (q->front == q->rear) {
        initQueue(q);
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return item;
}
