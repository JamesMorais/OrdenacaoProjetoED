#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void preencherVetorAleatorio(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % tamanho;
    }
}


void preencherVetorCrescente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i;
    }
}


void preencherVetorDecrescente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}


void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bubbleSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}


void insertionSort(int vetor[], int tamanho) {
    int i, chave, j;
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}


void selectionSort(int vetor[], int tamanho) {
    int i, j, min_idx;
    for (i = 0; i < tamanho - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[min_idx]) {
                min_idx = j;
            }
        }
        trocar(&vetor[i], &vetor[min_idx]);
    }
}


void merge(int vetor[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = vetor[esquerda + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = vetor[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = esquerda;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int vetor[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        mergeSort(vetor, esquerda, meio);
        mergeSort(vetor, meio + 1, direita);
        merge(vetor, esquerda, meio, direita);
    }
}

int main() {
    srand(time(NULL));
    int tamanhos[] = {1000, 5000, 10000, 20000, 30000};
    clock_t tempo_inicio, tempo_fim;
    double tempo_execucao;

    for (int i = 0; i < 5; i++) {
        int tamanho = tamanhos[i];
        int vetor[tamanho];

        // Teste com vetor em ordem crescente
        preencherVetorCrescente(vetor, tamanho);
        tempo_execucao = 0.0;
        for (int j = 0; j < 3; j++) {
            tempo_inicio = clock();
            bubbleSort(vetor, tamanho);
            tempo_fim = clock();
            tempo_execucao += (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
            preencherVetorCrescente(vetor, tamanho); // Restaurar o vetor original
        }
        printf("BubbleSort - Ordem crescente - Tamanho %d: %.6f segundos\n", tamanho, tempo_execucao / 3.0);

        tempo_execucao = 0.0;
        for (int j = 0; j < 3; j++) {
            tempo_inicio = clock();
            insertionSort(vetor, tamanho);
            tempo_fim = clock();
            tempo_execucao += (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
            preencherVetorCrescente(vetor, tamanho);
        }
        printf("InsertionSort - Ordem crescente - Tamanho %d: %.6f segundos\n", tamanho, tempo_execucao / 3.0);

        tempo_execucao = 0.0;
        for (int j = 0; j < 3; j++) {
            tempo_inicio = clock();
            selectionSort(vetor, tamanho);
            tempo_fim = clock();
            tempo_execucao += (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
            preencherVetorCrescente(vetor, tamanho);
        }
        printf("SelectionSort - Ordem crescente - Tamanho %d: %.6f segundos\n", tamanho, tempo_execucao / 3.0);

        tempo_execucao = 0.0;
        for (int j = 0; j < 3; j++) {
            preencherVetorCrescente(vetor, tamanho);
            tempo_inicio = clock();
            mergeSort(vetor, 0, tamanho - 1);
            tempo_fim = clock();
            tempo_execucao += (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
        }
        printf("MergeSort - Ordem crescente - Tamanho %d: %.6f segundos\n", tamanho, tempo_execucao / 3.0);

        // Teste com vetor em ordem decrescente
        preencherVetorDecrescente(vetor, tamanho);
        tempo_execucao = 0.0;
        for (int j = 0; j < 3; j++) {
            tempo_inicio = clock();
            bubbleSort(vetor, tamanho);
            tempo_fim = clock();
            tempo_execucao += (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
            preencherVetorDecrescente(vetor, tamanho);
        }
        printf("BubbleSort - Ordem decrescente - Tamanho %d: %.6f segundos\n", tamanho, tempo_execucao / 3.0);

        tempo_execucao = 0.0;
        for (int j = 0; j < 3; j++) {
            tempo_inicio = clock();
            insertionSort(vetor, tamanho);
            tempo_fim = clock();
            tempo_execucao += (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
            preencherVetorDecrescente(vetor, tamanho);
        }
        printf("InsertionSort - Ordem decrescente - Tamanho %d: %.6f segundos\n", tamanho, tempo_execucao / 3.0);

        tempo_execucao = 0.0;
        for (int j = 0; j < 3; j++) {
            tempo_inicio = clock();
            selectionSort(vetor, tamanho);
            tempo_fim = clock();
            tempo_execucao += (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
            preencherVetorDecrescente(vetor, tamanho);
        }
        printf("SelectionSort - Ordem decrescente - Tamanho %d: %.6f segundos\n", tamanho, tempo_execucao / 3.0);

        tempo_execucao = 0.0;
        for (int j = 0; j < 3; j++) {
            preencherVetorDecrescente(vetor, tamanho);
            tempo_inicio = clock();
            mergeSort(vetor, 0, tamanho - 1);
            tempo_fim = clock();
            tempo_execucao += (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
        }
        printf("MergeSort - Ordem decrescente - Tamanho %d: %.6f segundos\n", tamanho, tempo_execucao / 3.0);

        // Teste com vetor aleatório
        preencherVetorAleatorio(vetor, tamanho);
        tempo_execucao = 0.0;
        for (int j = 0; j < 3; j++) {
            tempo_inicio = clock();
            bubbleSort(vetor, tamanho);
            tempo_fim = clock();
            tempo_execucao += (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
            preencherVetorAleatorio(vetor, tamanho);
        }
        printf("BubbleSort - Vetor aleatorio - Tamanho %d: %.6f segundos\n", tamanho, tempo_execucao / 3.0);

        tempo_execucao = 0.0;
        for (int j = 0; j < 3; j++) {
            tempo_inicio = clock();
            insertionSort(vetor, tamanho);
            tempo_fim = clock();
            tempo_execucao += (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
            preencherVetorAleatorio(vetor, tamanho);
        }
        printf("InsertionSort - Vetor aleatorio - Tamanho %d: %.6f segundos\n", tamanho, tempo_execucao / 3.0);

        tempo_execucao = 0.0;
        for (int j = 0; j < 3; j++) {
            tempo_inicio = clock();
            selectionSort(vetor, tamanho);
            tempo_fim = clock();
            tempo_execucao += (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
            preencherVetorAleatorio(vetor, tamanho);
        }
        printf("SelectionSort - Vetor aleatorio - Tamanho %d: %.6f segundos\n", tamanho, tempo_execucao / 3.0);

        tempo_execucao = 0.0;
        for (int j = 0; j < 3; j++) {
            preencherVetorAleatorio(vetor, tamanho);
            tempo_inicio = clock();
            mergeSort(vetor, 0, tamanho - 1);
            tempo_fim = clock();
            tempo_execucao += (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
        }
        printf("MergeSort - Vetor aleatorio - Tamanho %d: %.6f segundos\n", tamanho, tempo_execucao / 3.0);
    }

    return 0;
}