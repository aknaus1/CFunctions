#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct NODE {
    int data;
    struct NODE *next;
    struct NODE *prev;
} NODE;

// Create a circular doubly linked list
NODE *createEmptyList() {
    NODE *head = (NODE *)malloc(sizeof(NODE));
    head->next = head;
    head->prev = head;
    return head;
}

// Create a circular doubly linked list from an array
NODE *createListFromArray(int* arr, int n) {
    NODE *head = (NODE *)malloc(sizeof(NODE));
    head->next = head;
    head->prev = head;
    NODE *temp = head;
    for (int i = 0; i < n; i++) {
        NODE *newNode = (NODE *)malloc(sizeof(NODE));
        newNode->data = arr[i];
        newNode->next = head;
        newNode->prev = temp;
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

// Delete a circular doubly linked list
void destroyList(NODE *head) {
    NODE *temp = head->next;
    while (temp != head) {
        NODE *temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
    free(head);
}

// Return number of nodes in a circular doubly linked list
int numItems(NODE *head) {
    int count = 0;
    NODE *temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Insert a node at the beginning of a circular doubly linked list
void addFirst(NODE *head, int data) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = head->next;
    newNode->prev = head;
    head->next->prev = newNode;
    head->next = newNode;
}

// Insert a node at the end of a circular doubly linked list
void addLast(NODE *head, int data) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
}

// remove and return the first node of a circular doubly linked list
NODE* removeFirst(NODE *head) {
    assert(head->next != head);

    NODE *temp = head->next;
    head->next = temp->next;
    temp->next->prev = head;

    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

// remove and return the last node of a circular doubly linked list
NODE* removeLast(NODE *head) {
    assert(head->prev != head);

    NODE *temp = head->prev;
    head->prev = temp->prev;
    temp->prev->next = head;

    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

// return the first node of a circular doubly linked list
NODE* getFirst(NODE *head) {
    assert(head->next != head);
    return head->next;
}

// return the last node of a circular doubly linked list
NODE* getLast(NODE *head) {
    assert(head->prev != head);
    return head->prev;
}

// remove item from a circular doubly linked list if it exists
void removeItem(NODE *head, int data) {
    NODE *temp = head->next;
    while (temp != head) {
        if (temp->data == data) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            return;
        }
        temp = temp->next;
    }
}

// return 1 if item exists in a circular doubly linked list, 0 otherwise
int contains(NODE *head, int data) {
    NODE *temp = head->next;
    while (temp != head) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// return contents of a circular doubly linked list as an array
int* getItems(NODE *head) {
    int *arr = (int *)malloc(sizeof(int) * numItems(head));
    NODE *temp = head->next;
    int i = 0;
    while (temp != head) {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    return arr;
}

// print contents of a circular doubly linked list
void printList(NODE *head) {
    NODE *temp = head->next;
    while (temp != head) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// print contents of a circular doubly linked list in reverse
void printListReverse(NODE *head) {
    NODE *temp = head->prev;
    while (temp != head) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

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

// sort a circular doubly linked list
void sortList(NODE *head) {
    int n = numItems(head);
    int *arr = getItems(head);
    mergeSort(arr, n);
    destroyList(head);
    head = createListFromArray(arr, n);
    free(arr);
}