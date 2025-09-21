#include "../include/file_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to build the file path string.
static void build_file_path(char* path_buffer, const char* base_dir, SequenceType type, int size, const char* suffix) {
    char type_str[20];
    char type_folder[20];

    switch (type) {
        case CRESCENTE:
            strcpy(type_str, "crescente");
            strcpy(type_folder, "Crescente");
            break;
        case DECRESCENTE:
            strcpy(type_str, "decrescente");
            strcpy(type_folder, "Decrescente");
            break;
        case RANDOM:
            strcpy(type_str, "random");
            strcpy(type_folder, "Random");
            break;
    }

    sprintf(path_buffer, "%s/%s/%s%s%d.txt", base_dir, type_folder, type_str, suffix, size);
}

void write_input_file(SequenceType type, int size, int* arr) {
    char path[256];
    build_file_path(path, "ArquivosDeEntrada", type, size, "");

    FILE* file = fopen(path, "w");
    if (file == NULL) {
        perror("Error opening input file for writing");
        return;
    }

    fprintf(file, "%d\n", size);
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

void write_output_file(SequenceType type, int size, int* arr) {
    char path[256];
    build_file_path(path, "ArquivosDeSaida", type, size, "_sorted");

    FILE* file = fopen(path, "w");
    if (file == NULL) {
        perror("Error opening output file for writing");
        return;
    }

    fprintf(file, "%d\n", size);
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

void write_time_file(SequenceType type, int size, double time_taken) {
    char path[256];
    build_file_path(path, "ArquivosDeTempo", type, size, "_time");

    FILE* file = fopen(path, "w");
    if (file == NULL) {
        perror("Error opening time file for writing");
        return;
    }

    fprintf(file, "%f\n", time_taken);

    fclose(file);
}
