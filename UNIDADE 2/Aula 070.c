#include <stdio.h>
#include <stdlib.h>

int encontrarMaximo(int arr[], int inicio, int fim) {
    if (inicio == fim) {
        return arr[inicio];
    }
    int meio = (inicio + fim) / 2;
    int maxEsq = encontrarMaximo(arr, inicio, meio);
    int maxDir = encontrarMaximo(arr, meio + 1, fim);

    if (maxEsq > maxDir) {
        return maxEsq;
    } else {
        return maxDir;
    }
}

int main() {
    int n;

    printf("Digite a quantidade de Fragmentos de Alma no inventário: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Quantidade inválida.\n");
        return 1;
    }

    int *fragmentos = (int *)malloc(n * sizeof(int));
    if (fragmentos == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    printf("\nInsira o nível de poder de cada fragmento:\n");
    for (int i = 0; i < n; i++) {
        printf("Fragmento %d: ", i + 1);
        scanf("%d", &fragmentos[i]);
    }

    int maxPoder = encontrarMaximo(fragmentos, 0, n - 1);
    printf("O Fragmento de Alma mais poderoso tem o nível: %d\n", maxPoder);
    free(fragmentos);
    return 0;
}