// Implement Merge Sort
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "mergeSort.h"

// merge two sorted arrays
void merge(int *a, int *b, int *c, int n, int m) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n) {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < m) {
        c[k] = b[j];
        j++;
        k++;
    }
}

// merge sort array
// Runtime: O(n log n)
// Memory: O(n)
void mergeSort(int *a, int n) {
    if (n > 1) {
        int *b = (int *)malloc(n / 2 * sizeof(int));
        int *c = (int *)malloc((n - n / 2) * sizeof(int));
        memcpy(b, a, n / 2 * sizeof(int));
        memcpy(c, a + n / 2, (n - n / 2) * sizeof(int));
        mergeSort(b, n / 2);
        mergeSort(c, n - n / 2);
        merge(b, c, a, n / 2, n - n / 2);
        free(b);
        free(c);
    }
}