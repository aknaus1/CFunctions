// Test queue functions
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "queue.h"

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
    
    // create queue
    queue *q = createQueue(n);

    // insert random numbers into queue
    for (int i = 0; i < n; i++) {
        int element = randInt(max);
        printf("Enqueueing %d\n", element);
        enqueue(q, element);
    }
    
    printQueue(q);

    // destroy queue
    deleteQueue(q);
    
    return 0;
}
