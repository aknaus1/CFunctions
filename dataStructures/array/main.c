// Test array functions
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "array.h"

// return a random number between 0 and max
int randInt(int max) {
    return rand() % max;
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
    int len = 0;
    int *a = createArray(len);
    for (int i = 0; i < n; i++) {
        a = append(a, &len, randInt(max));
    }

    printf("Unsorted array: ");
    printArray(a, len);

    a = insert(a, &len, 0, 100);
    a = insert(a, &len, 5, 60);
    a = insert(a, &len, len-1, 30);
    printArray(a, len);

    a = removeElement(a, &len, 0);
    a = removeElement(a, &len, 5);
    a = removeElement(a, &len, len-1);
    printArray(a, len);
    
    return 0;
}