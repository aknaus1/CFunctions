#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

typedef struct node NODE;

NODE *createEmptyList();
NODE *createListFromArray(int* arr, int n);
void destroyList(NODE *head);
int numItems(NODE *head);
void addFirst(NODE *head, int data);
void addLast(NODE *head, int data);
NODE* removeFirst(NODE *head);
NODE* removeLast(NODE *head);
NODE* getFirst(NODE *head);
NODE* getLast(NODE *head);
void removeItem(NODE *head, int data);
int contains(NODE *head, int data);
int* getItems(NODE *head);
void printList(NODE *head);
void printListReverse(NODE *head);
void sortList(NODE *head);

void merge(int *a, int *b, int *c, int n, int m);
void mergeSort(int *a, int n);

#endif
