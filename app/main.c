#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../include/file_handler.h"
#include "../include/algorithms.h"
#include "../include/sequence_generator.h"

int main() {
    int algorithm_choice;
    char data_type_choice;
    int data_size_choice;

    const char* algorithms[] = {"insertion_sort", "bubble_sort", "selection_sort", "shell_sort"};
    void (*sort_functions[])(int[], int) = {insertion_sort, bubble_sort, selection_sort, shell_sort};

    do {
        printf("\n--- Menu de Algoritmos de Ordenacao ---\n");
        printf("1. Insertion Sort\n");
        printf("2. Bubble Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Shell Sort\n");
        printf("0. Sair\n");
        printf("Escolha um algoritmo: ");
        scanf("%d", &algorithm_choice);

        if (algorithm_choice == 0) {
            printf("Saindo...\n");
            return 0;
        }

        if (algorithm_choice < 1 || algorithm_choice > 4) {
            printf("Escolha invalida. Tente novamente.\n");
            continue;
        }

        printf("\n--- Tipo de Entrada ---\n");
        printf("r. Randomico\n");
        printf("c. Crescente\n");
        printf("d. Decrescente\n");
        printf("Escolha o tipo de entrada: ");
        scanf(" %c", &data_type_choice);

        printf("\n--- Tamanho da Entrada ---\n");
        printf("1. 10\n");
        printf("2. 100\n");
        printf("3. 1.000\n");
        printf("4. 10.000\n");
        printf("5. 100.000\n");
        printf("6. 1.000.000\n");
        printf("Escolha o tamanho da entrada: ");
        scanf("%d", &data_size_choice);

        SequenceType seq_type;
        if (data_type_choice == 'c') {
            seq_type = CRESCENTE;
        } else if (data_type_choice == 'd') {
            seq_type = DECRESCENTE;
        } else if (data_type_choice == 'r') {
            seq_type = RANDOM;
        } else {
            printf("Tipo de entrada invalido.\n");
            continue;
        }

        int size;
        switch (data_size_choice) {
            case 1: size = 10; break;
            case 2: size = 100; break;
            case 3: size = 1000; break;
            case 4: size = 10000; break;
            case 5: size = 100000; break;
            case 6: size = 1000000; break;
            default:
                printf("Tamanho de entrada invalido.\n");
                continue;
        }

        const char* algorithm_name = algorithms[algorithm_choice - 1];
        void (*sort_function)(int[], int) = sort_functions[algorithm_choice - 1];

        printf("\nGerando sequencia de %d numeros...\n", size);
        int* arr = generate_sequence(size, seq_type);
        if (arr == NULL) {
            fprintf(stderr, "Falha ao gerar a sequencia.\n");
            continue;
        }

        printf("Salvando arquivo de entrada...\n");
        write_input_file(algorithm_name, seq_type, size, arr);

        clock_t start, end;
        printf("Ordenando com %s...\n", algorithm_name);
        start = clock();
        sort_function(arr, size);
        end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Ordenacao concluida em %f segundos.\n", time_taken);

        printf("Salvando arquivo de saida...\n");
        write_output_file(algorithm_name, seq_type, size, arr);

        printf("Salvando arquivo de tempo...\n");
        write_time_file(algorithm_name, seq_type, size, time_taken);

        free(arr);
        printf("\nOperacao concluida com sucesso!\n");
    } while (algorithm_choice != 0);

    return 0;
}
