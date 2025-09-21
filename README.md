# Projeto de Algoritmos - Insertion Sort

## Visão Geral do Projeto

Este projeto consiste na implementação e análise do algoritmo de ordenação **Insertion Sort**. O objetivo é desenvolver um programa em C que ordene diferentes conjuntos de dados (crescente, decrescente e aleatório) e meça o tempo de execução para cada cenário.

O projeto deve:

1.  Implementar o algoritmo Insertion Sort.
2.  Ler arquivos de entrada com instâncias de diferentes tamanhos (10, 100, 1.000, 10.000, 100.000, 1.000.000) e ordens (crescente, decrescente, aleatório).
3.  Salvar a saída ordenada em arquivos de texto.
4.  Registrar o tempo de execução da ordenação em arquivos de tempo.
5.  Apresentar um menu interativo para o usuário.

## Fluxo de Dados

O programa lê os dados de entrada da pasta `ArquivosDeEntrada/`. Existem três subpastas: `Crescente`, `Decrescente` e `Random`, cada uma contendo arquivos de texto com números em diferentes ordens e tamanhos.

Após a execução, o programa gera dois tipos de arquivos de saída:

1.  **Arquivos de Saída Ordenados**: Os dados ordenados são salvos na pasta `ArquivosDeSaida/`, mantendo a estrutura de subpastas `Crescente`, `Decrescente` e `Random`.
2.  **Arquivos de Tempo de Execução**: O tempo gasto para ordenar cada conjunto de dados é salvo na pasta `ArquivosDeTempo/`, também com a mesma estrutura de subpastas.

## Como Executar

Este projeto utiliza o CMake para gerenciar a compilação. Siga os passos abaixo para compilar e executar o programa.

### Linux

1.  **Compile o projeto:**
    ```bash
    cd build
    cmake ..
    make
    ```

2.  **Execute o programa:**
    O executável será gerado em `build/bin/`.
    ```bash
    ./bin/main
    ```
    ou
    ```bash
    make run
    ```
    Ao executar, um menu interativo será apresentado.

### Windows

1.  **Configure o projeto:**
    Recomenda-se o uso do `git-bash` ou um terminal similar.
    ```bash
    cd build
    cmake ..
    ```

2.  **Compile o projeto:**
    ```bash
    cmake --build .
    ```

3.  **Execute o programa:**
    O executável será gerado em `build/bin/`.
    ```bash
    ./bin/main.exe
    ```
    Ao executar, um menu interativo será apresentado.

### Limpando os arquivos gerados

Para remover os arquivos gerados pela compilação, simplesmente apague o diretório `build`.
