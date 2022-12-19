// Implement Counting Sort
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "countingSort.h"

// count number of occurrences of each element in array
void countElements(int *a, int n, int *count) {
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }
}

// sort array of size n
// Runtime: O(k + n)
// Memory: O(k + n)
void sort(int *a, int n) {
    int *count = calloc(n, sizeof(int));
    countElements(a, n, count);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (count[i] > 0) {
            a[j++] = i;
            count[i]--;
        }
    }
    free(count);
}
