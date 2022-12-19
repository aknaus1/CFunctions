// Generate random numbers and sort them using bubble sort.
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "bubbleSort.h"

// return a random number between 0 and max
int randInt(int max) {
    return rand() % max;
}

// return array of random numbers of size n, each number between 0 and max
int *randArray(int n, int max) {
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = randInt(max);
    }
    return a;
}

// print array of size n
void printArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int main() {
    // get number of elements
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // get max value
    int max;
    printf("Enter the max value: ");
    scanf("%d", &max);

    // seed random number generator
    srand(time(NULL));
    
    // generate array of random numbers
    int *a = randArray(n, max);

    printf("Unsorted array: ");
    printArray(a, n);

    sort(a, n);
    
    printf("\nSorted array: ");
    printArray(a, n);

    printf("\n");

    free(a);
}