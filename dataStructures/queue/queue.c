#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "queue.h"

// create new array
// params: size of array
// return: pointer to array
int *createArray(int n) {
    int *a = malloc(n * sizeof(int));
    assert(a != NULL);
    return a;
}

// destroy array
// params: pointer to array
void destroy(int *a) {
    free(a);
}

// create new queue
// params: size of queue
// return: pointer to queue
queue *createQueue(int n) {
    queue *q = malloc(sizeof(queue));
    assert(q != NULL);
    q->data = createArray(n);
    q->size = n;
    q->front = 0;
    q->rear = 0;
    return q;
}

// delete queue
// params: pointer to queue
void deleteQueue(queue *q) {
    destroy(q->data);
    free(q);
}

// enqueue element into queue
// params: pointer to queue, element to enqueue
void enqueue(queue *q, int element) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->data[q->rear] = element;
    q->rear = (q->rear + 1) % q->size;
}

// dequeue element from queue
// params: pointer to queue
// return: element dequeued
int dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int element = q->data[q->front];
    q->front = (q->front + 1) % q->size;
    return element;
}

// check if queue is empty
// params: pointer to queue
// return: 1 if empty, 0 otherwise
int isEmpty(queue *q) {
    return q->front == q->rear;
}

// check if queue is full
// params: pointer to queue
// return: 1 if full, 0 otherwise
int isFull(queue *q) {
    return (q->rear + 1) % q->size == q->front;
}

// print queue
// params: pointer to queue
void printQueue(queue *q) {
    printf("Queue: ");
    for (int i = q->front; i != q->rear; i = (i + 1) % q->size) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}