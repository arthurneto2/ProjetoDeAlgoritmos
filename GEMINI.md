# Projeto de Algoritmos - Insertion Sort

## Visão Geral do Projeto

Este projeto consiste na implementação e análise do algoritmo de ordenação **Insertion Sort**. O objetivo é desenvolver um programa em C ou C++ que ordene diferentes conjuntos de dados (crescente, decrescente e aleatório) e meça o tempo de execução para cada cenário.

Conforme o documento `ANÁLISE_ALGORITIMOS_DE_ORDENAÇÃO.pdf`, o projeto deve:

1.  Implementar o algoritmo Insertion Sort.
2.  Gerar e ler arquivos de entrada com instâncias de diferentes tamanhos (10, 100, 1.000, 10.000, 100.000, 1.000.000) e ordens (crescente, decrescente, aleatório).
3.  Salvar a saída ordenada em arquivos de texto.
4.  Registrar o tempo de execução da ordenação em arquivos de tempo.
5.  Apresentar um menu interativo para o usuário.

## Estrutura de Diretórios

O projeto está organizado da seguinte forma:

```
/home/arthur-n/Documents/ProjetoDeAlgoritmos/
├── app/
├── bin/
├── ArquivosDeEntrada/
│   ├── Crescente/
│   ├── Decrescente/
│   └── Random/
├── ArquivosDeSaida/
│   ├── Crescente/
│   ├── Decrescente/
│   └── Random/
├── ArquivosDeTempo/
│   ├── Crescente/
│   ├── Decrescente/
│   └── Random/
├── include/
├── lib/
├── obj/
├── src/
├── GEMINI.md
└── ANÁLISE_ALGORITIMOS_DE_ORDENAÇÃO.pdf
```

### Descrição dos Diretórios

*   `app/`: Conterá o código principal da aplicação (`main`), responsável pela interação com o usuário (menu) e por orquestrar a execução do algoritmo.
*   `bin/`: Contém o arquivo executável do projeto.
*   `ArquivosDeEntrada/`: Contém os arquivos `.txt` com os dados de entrada para os algoritmos de ordenação. As subpastas `Crescente`, `Decrescente` e `Random` organizam os diferentes tipos de massa de dados.
*   `ArquivosDeSaida/`: Armazena os arquivos `.txt` com os dados ordenados gerados pelos algoritmos.
*   `ArquivosDeTempo/`: Guarda os arquivos `.txt` com o tempo de execução de cada algoritmo para cada conjunto de dados.
*   `include/`: Conterá os arquivos de cabeçalho (`.h`) com as declarações das funções (ex: `insertion_sort()`, funções de manipulação de arquivos).
*   `lib/`: Armazena a biblioteca de objetos (`.a`) gerada a partir dos arquivos de objeto.
*   `obj/`: Armazena os arquivos de objeto (`.o`) compilados a partir do código-fonte.
*   `src/`: Conterá os arquivos de código-fonte (`.c` ou `.cpp`) com a implementação das funções declaradas nos cabeçalhos, incluindo os algoritmos de ordenação e as funções de manipulação de arquivos.
*   `GEMINI.md`: Este arquivo, com a documentação geral do projeto.
*   `ANÁLISE_ALGORITIMOS_DE_ORDENAÇÃO.pdf`: O documento com a especificação do trabalho.