#ifndef SEQUENCE_GENERATOR_H
#define SEQUENCE_GENERATOR_H

#include <stdlib.h> // For size_t

// Enum for sequence types for better code clarity and type safety
typedef enum {
    CRESCENTE,
    DECRESCENTE,
    RANDOM
} SequenceType;

/**
 * @brief Generates a dynamically allocated array of integers.
 *
 * This function creates an array of a given size and fills it with numbers
 * according to the specified sequence type.
 *
 * @param size The number of elements to generate in the array.
 * @param type The ordering of the numbers (CRESCENTE, DECRESCENTE, or RANDOM).
 * @return A pointer to the newly created integer array. The caller is
 *         responsible for freeing this memory using free(). Returns NULL if
 *         memory allocation fails or if the size is not positive.
 */
int *generate_sequence(int size, SequenceType type);
#endif // SEQUENCE_GENERATOR_H
