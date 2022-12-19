#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue {
    int *data;
    int front;
    int rear;
    int size;
} queue;

queue *createQueue(int size);
void deleteQueue(queue *q);
void enqueue(queue *q, int data);
int dequeue(queue *q);
int isEmpty(queue *q);
int isFull(queue *q);
void printQueue(queue *q);

#endif
