#include "../include/file_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to create the directory for a given file path
static void create_directory_for_path(const char* path) {
    char* path_copy = strdup(path);
    if (path_copy == NULL) {
        perror("strdup");
        return;
    }

    char* last_slash = strrchr(path_copy, '/');
    if (last_slash != NULL) {
        *last_slash = '\0'; // Null-terminate at the last slash to get the directory path
        
        char command[512];
        sprintf(command, "mkdir -p \"%s\"", path_copy);
        system(command);
    }

    free(path_copy);
}

// Helper function to build the file path string for output, time and input files.
static void build_output_file_path(char* path_buffer, const char* algorithm, const char* file_type, SequenceType type, int size) {
    char type_str[20];

    switch (type) {
        case CRESCENTE:
            strcpy(type_str, "crescente");
            break;
        case DECRESCENTE:
            strcpy(type_str, "decrescente");
            break;
        case RANDOM:
            strcpy(type_str, "random");
            break;
    }

    sprintf(path_buffer, "resultados/%s/%s/%s/%s%d.txt", algorithm, file_type, type_str, type_str, size);
}

void write_input_file(const char* algorithm, SequenceType type, int size, int* arr) {
    char path[256];
    build_output_file_path(path, algorithm, "entrada", type, size);
    create_directory_for_path(path);

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

void write_output_file(const char* algorithm, SequenceType type, int size, int* arr) {
    char path[256];
    build_output_file_path(path, algorithm, "saida", type, size);
    create_directory_for_path(path);

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

void write_time_file(const char* algorithm, SequenceType type, int size, double time_taken) {
    char path[256];
    build_output_file_path(path, algorithm, "tempo", type, size);
    create_directory_for_path(path);

    FILE* file = fopen(path, "w");
    if (file == NULL) {
        perror("Error opening time file for writing");
        return;
    }

    fprintf(file, "%f\n", time_taken);

    fclose(file);
}
