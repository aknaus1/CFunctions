// Generate random numbers and sort them using merge sort.
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "binaryTree.h"

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
    
    // Create binary tree with random number as root
    int num = randInt(max);
    NODE *root = createBinaryTree(num);
    
    // insert random numbers into binary tree
    for (int i = 1; i < n; i++) {
        num = randInt(max);
        root = insertItem(root, num);
    }

    // print binary tree in order
    printf("In order: ");
    printInOrder(root);
    printf("\n");

    // // print binary tree pre order
    // printf("Pre order: ");
    // printPreOrder(root);
    // printf("\n");

    // // print binary tree post order
    // printf("Post order: ");
    // printPostOrder(root);
    // printf("\n");

    // // print binary tree level order
    // printf("Level order: ");
    // printLevelOrder(root);
    // printf("\n");

    // // print binary tree level order reverse
    // printf("Level order reverse: ");
    // printLevelOrderReverse(root);
    // printf("\n");

    // destroy binary tree
    destroyTree(root);

    return 0;
}