#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct NODE {
    int data;
    struct NODE *left;
    struct NODE *right;
} NODE;

NODE *createBinaryTree(int data);
void destroyTree(NODE *root);

int numItems(NODE *root);
int height(NODE *root);

int minValue(NODE *root);
int maxValue(NODE *root);

int sum(NODE *root);
double average(NODE *root);

int get_balance(NODE *node);
NODE *right_rotate(NODE *node);
NODE *left_rotate(NODE *node);

NODE* balance(NODE *root);
void addItem(NODE *root, int data);
NODE* insertItem(NODE *root, int data);
void removeItem(NODE *root, int data);

void printInOrder(NODE *root);
void printPreOrder(NODE *root);
void printPostOrder(NODE *root);
void printLevelOrder(NODE *root);
void printLevelOrderReverse(NODE *root);
void printLevel(NODE *root, int level);

#endif
