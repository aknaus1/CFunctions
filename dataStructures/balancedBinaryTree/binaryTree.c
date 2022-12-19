#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

# include "binaryTree.h"

// create a binary tree with root node
NODE *createBinaryTree(int data) {
    NODE *root = (NODE *)malloc(sizeof(NODE));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

// Delete a binary tree
void destroyTree(NODE *root) {
    if (root->left != NULL) {
        destroyTree(root->left);
    }
    if (root->right != NULL) {
        destroyTree(root->right);
    }
    free(root);
}

// Return number of nodes in a binary tree
int numItems(NODE *root) {
    if(root == NULL) {
        return 0;
    }
    int count = 1;
    if (root->left != NULL) {
        count += numItems(root->left);
    }
    if (root->right != NULL) {
        count += numItems(root->right);
    }
    return count;
}

// Find the height of a binary tree
int height(NODE *root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = 0;
    int rightHeight = 0;
    if (root->left != NULL) {
        leftHeight = height(root->left);
    }
    if (root->right != NULL) {
        rightHeight = height(root->right);
    }
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Find the minimum value in a binary tree
int minValue(NODE *root) {
    assert(root != NULL);
    int min = root->data;
    if (root->left != NULL) {
        int leftMin = minValue(root->left);
        min = (min < leftMin) ? min : leftMin;
    }
    if (root->right != NULL) {
        int rightMin = minValue(root->right);
        min = (min < rightMin) ? min : rightMin;
    }
    return min;
}

// Find the maximum value in a binary tree
int maxValue(NODE *root) {
    assert(root != NULL);
    int max = root->data;
    if (root->left != NULL) {
        int leftMax = maxValue(root->left);
        max = (max > leftMax) ? max : leftMax;
    }
    if (root->right != NULL) {
        int rightMax = maxValue(root->right);
        max = (max > rightMax) ? max : rightMax;
    }
    return max;
}

// Find the sum of all values in a binary tree
int sum(NODE *root) {
    assert(root != NULL);
    int this_sum = root->data;
    if (root->left != NULL) {
        this_sum += sum(root->left);
    }
    if (root->right != NULL) {
        this_sum += sum(root->right);
    }
    return this_sum;
}

// Find the average of all values in a binary tree
double average(NODE *root) {
    assert(root != NULL);
    return (double)sum(root) / numItems(root);
}

// Get the balance of a node
int get_balance(NODE *node) {
  if (node == NULL) {
    return 0;
  }
  return height(node->left) - height(node->right);
}

// Rotate a node to the right
NODE *right_rotate(NODE *node) {
  NODE *new_root = node->left;
  NODE *temp = new_root->right;

  new_root->right = node;
  node->left = temp;

  return new_root;
}

// Rotate a node to the left
NODE *left_rotate(NODE *node) {
  NODE *new_root = node->right;
  NODE *temp = new_root->left;

  new_root->left = node;
  node->right = temp;

  return new_root;
}

// Balance a binary tree
NODE* balance(NODE *node) {
  int balance = get_balance(node);

  if (balance > 1 && get_balance(node->left) >= 0) {
    return right_rotate(node);
  }

  if (balance > 1 && get_balance(node->left) < 0) {
    node->left = left_rotate(node->left);
    return right_rotate(node);
  }

  if (balance < -1 && get_balance(node->right) <= 0) {
    return left_rotate(node);
  }

  if (balance < -1 && get_balance(node->right) > 0) {
    node->right = right_rotate(node->right);
    return left_rotate(node);
  }

  return node;
}


// Add item to tree
void addItem(NODE *root, int data) {
    assert(root != NULL);
    if (root->data > data) {
        if (root->left == NULL) {
            NODE *newNode = (NODE *)malloc(sizeof(NODE));
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            root->left = newNode;
        } else {
            addItem(root->left, data);
        }
    } else {
        if (root->right == NULL) {
            NODE *newNode = (NODE *)malloc(sizeof(NODE));
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            root->right = newNode;
        } else {
            addItem(root->right, data);
        }
    }
}

// insert item into tree and balance
NODE* insertItem(NODE *root, int data) {
    addItem(root, data);
    return balance(root);
}

// Remove item from tree
void removeItem(NODE *root, int data) {
    assert(root != NULL);
    if (root->data == data) {
        if (root->left == NULL && root->right == NULL) {
            root->data = '\0';
        } else if (root->left == NULL) {
            NODE *newRoot = root->right;
            root->data = newRoot->data;
            root->left = newRoot->left;
            root->right = newRoot->right;
            free(newRoot);
        } else if (root->right == NULL) {
            NODE *newRoot = root->left;
            root->data = newRoot->data;
            root->left = newRoot->left;
            root->right = newRoot->right;
            free(newRoot);
        } else {
            NODE *newRoot = root->right;
            while (newRoot->left != NULL) {
                newRoot = newRoot->left;
            }
            root->data = newRoot->data;
            removeItem(root->right, newRoot->data);
        }
    } else if (root->data > data) {
        if (root->left != NULL) {
            removeItem(root->left, data);
        }
    } else {
        if (root->right != NULL) {
            removeItem(root->right, data);
        }
    }

    balance(root);
}

// Print tree in order
void printInOrder(NODE *root) {
    assert(root != NULL);
    
    if (root->left != NULL) {
        printInOrder(root->left);
    }
    printf("%d ", root->data);
    if (root->right != NULL) {
        printInOrder(root->right);
    }
}

// Print tree pre order
void printPreOrder(NODE *root) {
    assert(root != NULL);

    printf("%d ", root->data);
    if (root->left != NULL) {
        printPreOrder(root->left);
    }
    if (root->right != NULL) {
        printPreOrder(root->right);
    }
}

// Print tree post order
void printPostOrder(NODE *root) {
    assert(root != NULL);

    if (root->left != NULL) {
        printPostOrder(root->left);
    }
    if (root->right != NULL) {
        printPostOrder(root->right);
    }
    printf("%d ", root->data);
}

// Print tree in level order
void printLevel(NODE *root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

// Print tree in level order
void printLevelOrder(NODE *root) {
    assert(root != NULL);
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
        printf("\n");
    }
}

// Print tree in level order
void printLevelOrderReverse(NODE *root) {
    assert(root != NULL);
    int h = height(root);
    for (int i = h; i >= 1; i--) {
        printLevel(root, i);
        printf("\n");
    }
}