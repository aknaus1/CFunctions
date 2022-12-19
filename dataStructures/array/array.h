#ifndef ARRAY_H
#define ARRAY_H

int *createArray(int n);
void freeArray(int *a);
int *append(int *a, int *n, int element);
int *insert(int *a, int *n, int index, int element);
int *removeElement(int *a, int *n, int index);
int getElement(int *a, int n, int i);
void setElement(int *a, int n, int i, int element);
void printArray(int *a, int n);

#endif
