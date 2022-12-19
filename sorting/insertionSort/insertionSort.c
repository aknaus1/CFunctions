// Implement Insertion Sort
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "insertionSort.h"

// insert element into sorted array
void insert(int *a, int n, int element) {
    int i = n - 1;
    while (i >= 0 && a[i] > element) {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = element;
}

// insertion sort array
// Runtime: O(n^2)
// Memory: O(1)
void insertionSort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        insert(a, i, a[i]);
    }
}

// sort array of size n
void sort(int *a, int n) {
    insertionSort(a, n);
}