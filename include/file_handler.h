#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <stdio.h>
#include "sequence_generator.h" // For SequenceType

// Writes the generated sequence to an input file in the corresponding directory.
void write_input_file(SequenceType type, int size, int* arr);

// Writes the sorted array to an output file in the corresponding directory.
void write_output_file(SequenceType type, int size, int* arr);

// Writes the execution time to a time file in the corresponding directory.
void write_time_file(SequenceType type, int size, double time_taken);

#endif // FILE_HANDLER_H
