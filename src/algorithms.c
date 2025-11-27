#include "../include/algorithms.h"
#include <stdlib.h>

void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void shell_sort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high, int pivot_strategy) {
    int pivot_index;
    switch (pivot_strategy) {
        case 1: // Primeiro Elemento
            pivot_index = low;
            break;
        case 2: // Elemento do Meio
            pivot_index = low + (high - low) / 2;
            break;
        case 3: // Elemento Aleatorio
            pivot_index = low + rand() % (high - low + 1);
            break;
        default: // Padrao para o primeiro elemento
            pivot_index = low;
            break;
    }

    swap(&arr[pivot_index], &arr[high]);
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }
    
    void quick_sort(int arr[], int low, int high, int pivot_strategy) {
        if (low < high) {
            int pi = partition(arr, low, high, pivot_strategy);
            quick_sort(arr, low, pi - 1, pivot_strategy);
            quick_sort(arr, pi + 1, high, pivot_strategy);
        }
    }
    
    void minHeapify(int arr[], int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
    
        if (left < n && arr[left] < arr[smallest])
            smallest = left;
    
        if (right < n && arr[right] < arr[smallest])
            smallest = right;
    
        if (smallest != i) {
            swap(&arr[i], &arr[smallest]);
            minHeapify(arr, n, smallest);
        }
    }
    
    void buildMinHeap(int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            minHeapify(arr, n, i);
    }
    
    void heapSort(int arr[], int n) {
        buildMinHeap(arr, n);
        for (int i = n - 1; i > 0; i--) {
            swap(&arr[0], &arr[i]);
            minHeapify(arr, i, 0);
        }
        // The array is now sorted in Descending order.
        // Reverse it to get Ascending order.
        int start = 0;
        int end = n - 1;
        while (start < end) {
            swap(&arr[start], &arr[end]);
            start++;
            end--;
        }
    }
    
    int heapMinimum(int arr[], int n) {
        if (n < 1) return -1; // Error
        return arr[0];
    }
    
    int heapExtractMin(int arr[], int *n) {
        if (*n < 1) return -1; // Error
        int min = arr[0];
        arr[0] = arr[*n - 1];
        (*n)--;
        minHeapify(arr, *n, 0);
        return min;
    }
    
    void heapIncreaseKey(int arr[], int n, int i, int key) {
        if (key < arr[i]) {
            // Error: New key is smaller than current key
            return;
        }
        arr[i] = key;
        minHeapify(arr, n, i);
    }
    
    void minHeapInsert(int arr[], int *n, int key) {
        (*n)++;
        int i = *n - 1;
        arr[i] = key;
    
        // Swim up (Decrease Key logic)
        while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
            swap(&arr[i], &arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    
    void heapsort_min(int arr[], int n) {
        heapSort(arr, n);
    }    