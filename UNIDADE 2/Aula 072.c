#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int posicao;
    char nome[50];
} Piloto;

void intercala(Piloto arr[], int esq, int meio, int dir) {
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    Piloto *L = (Piloto *)malloc(n1 * sizeof(Piloto));
    Piloto *R = (Piloto *)malloc(n2 * sizeof(Piloto));

    for (i = 0; i < n1; i++) {
        L[i] = arr[esq + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = esq;

    while (i < n1 && j < n2) {
        if (L[i].posicao <= R[j].posicao) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(Piloto arr[], int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        mergeSort(arr, esq, meio);
        mergeSort(arr, meio + 1, dir);
        intercala(arr, esq, meio, dir);
    }
}

int main() {
    int n;
    printf("Digite o número de pilotos na corrida: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    Piloto *pilotos = (Piloto *)malloc(n * sizeof(Piloto));
    if (pilotos == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    printf("\nInsira os dados de cada piloto:\n");
    for (int i = 0; i < n; i++) {
        printf("\n--- Piloto %d ---\n", i + 1);
        printf("Posição de chegada: ");
        scanf("%d", &pilotos[i].posicao);
        printf("Nome do piloto: ");
        scanf("%49s", pilotos[i].nome);
    }

    mergeSort(pilotos, 0, n - 1);

    printf("\n========== CLASSIFICAÇÃO FINAL =========\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", pilotos[i].posicao, pilotos[i].nome);
    }

    free(pilotos);
    return 0;
}