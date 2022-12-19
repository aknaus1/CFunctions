// Test circular doubly linked list functions
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "circularDoublyLinkedList.h"

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
    
    // create circular doubly linked list
    NODE *head = createEmptyList();

    // insert random numbers into circular doubly linked list
    for (int i = 0; i < n; i++) {
        addLast(head, randInt(max));
    }

    // print circular doubly linked list
    printf("Unsorted: ");
    printList(head);

    // sort circular doubly linked list
    sortList(head);

    // print circular doubly linked list
    printf("Sorted: ");
    printList(head);

    // destroy circular doubly linked list
    destroyList(head);
    
    return 0;
}