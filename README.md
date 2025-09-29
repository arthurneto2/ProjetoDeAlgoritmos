# Projeto de Algoritmos de Ordenação

## Visão Geral do Projeto

Este projeto consiste na implementação e análise de quatro algoritmos de ordenação: **Bubble Sort**, **Insertion Sort**, **Selection Sort** e **Shell Sort**. O objetivo é desenvolver um programa em C que ordene diferentes conjuntos de dados (crescente, decrescente e aleatório) e meça o tempo de execução para cada cenário.

O projeto deve:

1.  Implementar os algoritmos de ordenação mencionados.
2.  Gerar e ler arquivos de entrada com instâncias de diferentes tamanhos (10, 100, 1.000, 10.000, 100.000, 1.000.000) e ordens (crescente, decrescente, aleatório).
3.  Salvar a saída ordenada em arquivos de texto.
4.  Registrar o tempo de execução da ordenação em arquivos de tempo.
5.  Apresentar um menu interativo para o usuário.

## Fluxo de Dados

O programa gera e lê os dados de entrada da pasta `resultados/[algoritmo]/entrada/`. Para cada algoritmo, existem três subpastas: `crescente`, `decrescente` e `random`, cada uma contendo arquivos de texto com números em diferentes ordens e tamanhos.

Após a execução, o programa gera dois tipos de arquivos de saída dentro da pasta de cada algoritmo:

1.  **Arquivos de Saída Ordenados**: Os dados ordenados são salvos na pasta `resultados/[algoritmo]/saida/`, mantendo a estrutura de subpastas por ordem.
2.  **Arquivos de Tempo de Execução**: O tempo gasto para ordenar cada conjunto de dados é salvo na pasta `resultados/[algoritmo]/tempo/`, também com a mesma estrutura de subpastas.

## Como Executar

Este projeto foi desenvolvido e testado em um ambiente Linux. Para compilar e executar o programa, siga os passos abaixo:

1.  **Compilar o projeto:**

    ```bash
    make all
    ```

    Este comando compilará o código-fonte e criará o executável em `bin/main`.

2.  **Executar o programa:**

    ```bash
    make run
    ```

    ou

    ```bash
    ./bin/main
    ```

    Ao executar, um menu interativo será apresentado para que o usuário possa escolher qual conjunto de dados ordenar.

3.  **Limpar os arquivos gerados:**

    ```bash
    make clean
    ```

    Este comando removerá os arquivos de objeto, a biblioteca e o executável gerados pela compilação.

### Nota para outros Sistemas Operacionais

O `Makefile` e o código-fonte foram escritos para um ambiente Linux. Se você deseja executar este projeto em outro sistema operacional (como Windows ou macOS), pode ser necessário fazer adaptações no `Makefile` e, possivelmente, no código-fonte, especialmente no que diz respeito à manipulação de caminhos de arquivos e à compilação. Para usuários de Windows, uma alternativa é utilizar o WSL (Windows Subsystem for Linux) para compilar e executar o projeto em um ambiente Linux sem a necessidade de uma máquina virtual completa.
