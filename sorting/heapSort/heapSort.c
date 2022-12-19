// Implement heap Sort
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "heapSort.h"

// swap two elements in array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// heapify subtree rooted at index i
void heapify(int *a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest]) {
        largest = left;
    }
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

// heap sort array
// Runtime: O(n log n)
// Memory: O(1)
void heapSort(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

// sort array of size n
void sort(int *a, int n) {
    heapSort(a, n);
}