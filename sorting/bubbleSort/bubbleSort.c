// Implement Bubble Sort
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "bubbleSort.h"

// swap two elements in array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort array
// Runtime: O(n^2)
// Memory: O(1)
void bubbleSort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

// sort array of size n
void sort(int *a, int n) {
    bubbleSort(a, n);
}