#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/sequence_generator.h"

int* generate_sequence(int size, SequenceType type) {
    if (size <= 0) {
        fprintf(stderr, "Error: Array size must be positive.\n");
        return NULL;
    }

    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        perror("Failed to allocate memory for sequence");
        return NULL;
    }

    switch (type) {
        case CRESCENTE:
            for (int i = 0; i < size; i++) {
                arr[i] = i + 1;
            }
            break;
        case DECRESCENTE:
            for (int i = 0; i < size; i++) {
                arr[i] = size - i;
            }
            break;
        case RANDOM:
            srand(time(NULL));
            for (int i = 0; i < size; i++) {
                arr[i] = rand();
            }
            break;
        default:
            fprintf(stderr, "Error: Invalid sequence type provided.\n");
            free(arr);
            return NULL;
    }

    return arr;
}
