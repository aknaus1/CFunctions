#ifndef QUICKSORT_H
#define QUICKSORT_H

void swap(int *a, int *b);
int partition(int *a, int low, int high);
void quickSort(int *a, int low, int high);
void sort(int *a, int n);

#endif
