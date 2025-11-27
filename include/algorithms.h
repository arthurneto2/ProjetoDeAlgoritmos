#ifndef ALGORITHMS_H
#define ALGORITHMS_H

void insertion_sort(int arr[], int n);
void bubble_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void shell_sort(int arr[], int n);
void merge_sort(int arr[], int l, int r);
void quick_sort(int arr[], int low, int high, int pivot_strategy);
void heapsort_min(int arr[], int n);

// Min-Heap Priority Queue Functions
void minHeapify(int arr[], int n, int i);
void buildMinHeap(int arr[], int n);
void heapSort(int arr[], int n);
int heapMinimum(int arr[], int n);
int heapExtractMin(int arr[], int *n);
void heapIncreaseKey(int arr[], int n, int i, int key);
void minHeapInsert(int arr[], int *n, int key);

#endif // ALGORITHMS_H