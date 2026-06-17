#include <stdio.h>

int contarCristaisPositivos(int vetor[], int tamanho, int indice) {
    if (indice == tamanho) {
        return 0;
    }

    if (vetor[indice] > 0) {
        return 1 + contarCristaisPositivos(vetor, tamanho, indice + 1);
    } else {
        return 0 + contarCristaisPositivos(vetor, tamanho, indice + 1);
    }
}

int main () {
    int n;
    printf("Digite a quantidade de cristais no inventário: ");
    scanf("%d", &n);

    int cristais[n];
    printf("Digite os %d níveis de carga:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cristais[i]);
    }
    int total_positivos = contarCristaisPositivos(cristais, n, 0);
    printf("Quantidade de cristais com carga positiva: %d\n", total_positivos);
    return 0;
}