// Implement Quick Sort
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "quickSort.h"

// swap two elements in array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// partition array around pivot
int partition(int *a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

// quick sort array
// Runtime: O(n log n)
// Memory: O(log n)
void quickSort(int *a, int low, int high) {
    if (low < high) {
        int pivot = partition(a, low, high);
        quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
    }
}

// sort array of size n
void sort(int *a, int n) {
    quickSort(a, 0, n - 1);
}