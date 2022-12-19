#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// create array of size n
// params: size of array
// return: pointer to array
int *createArray(int n) {
    int *a = malloc(n * sizeof(int));
    assert(a != NULL);
    return a;
}

// free array
// params: pointer to array
void freeArray(int *a) {
    free(a);
}

// append element to array
// params: pointer to array, size of array, element to append
// return: pointer to new array
int *append(int *a, int *n, int element) {
    int *newArray = createArray((*n) + 1);
    for (int i = 0; i < (*n); i++) {
        newArray[i] = a[i];
    }
    newArray[(*n)] = element;
    freeArray(a);
    (*n)++;
    return newArray;
}

// insert element into array
// params: pointer to array, size of array, index to insert element, element to insert
// return: pointer to new array
int *insert(int *a, int *n, int index, int element) {
    int *newArray = createArray((*n) + 1);
    for (int i = 0; i < index; i++) {
        newArray[i] = a[i];
    }
    newArray[index] = element;
    for (int i = index + 1; i < (*n) + 1; i++) {
        newArray[i] = a[i - 1];
    }
    freeArray(a);
    (*n)++;
    return newArray;
}

// remove element from array
// params: pointer to array, size of array, index of element to remove
// return: pointer to new array
int *removeElement(int *a, int *n, int index) {
    int *newArray = createArray((*n) - 1);
    for (int i = 0; i < index; i++) {
        newArray[i] = a[i];
    }
    for (int i = index; i < (*n) - 1; i++) {
        newArray[i] = a[i + 1];
    }
    freeArray(a);
    (*n)--;
    return newArray;
}

// get element from array at index i
// params: pointer to array, size of array, index of element to get
// return: element at index i
int getElement(int *a, int n, int i) {
    return a[i];
}

// set element at index i
// params: pointer to array, size of array, index of element to set, element to set
void setElement(int *a, int n, int i, int element) {
    a[i] = element;
}

// print array
// params: pointer to array, size of array
void printArray(int *a, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("], length %d\n", n);
}
