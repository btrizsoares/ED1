#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int nivel_ameaca;
} Nave;

void merge(Nave arr[], int esq, int meio, int dir) {
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    Nave *L = (Nave *)malloc(n1 * sizeof(Nave));
    Nave *R = (Nave *)malloc(n2 * sizeof(Nave));

    for (i = 0; i < n1; i++)
        L[i] = arr[esq + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    i = 0;
    j = 0;
    k = esq;

    while (i < n1 && j < n2) {
        if (L[i].nivel_ameaca <= R[j].nivel_ameaca) {
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

void mergeSort(Nave arr[], int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;

        mergeSort(arr, esq, meio);
        mergeSort(arr, meio + 1, dir);

        merge(arr, esq, meio, dir);
    }
}

int main() {
    int n;
    printf("Digite a quantidade de naves inimigas detectadas: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    Nave *naves = (Nave *)malloc(n * sizeof(Nave));
    if (naves == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

    printf("\nInsira os dados das naves inimigas:\n");
    for (int i = 0; i < n; i++) {
        printf("\n--- Nave %d ---\n", i + 1);
        printf("Digite o ID: ");
        scanf("%d", &naves[i].id);
        printf("Digite o nivel de ameaca: ");
        scanf("%d", &naves[i].nivel_ameaca);
    }
    mergeSort(naves, 0, n - 1);

    printf("\nOrdem de prioridade de ataque (IDs): \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", naves[i].id);
    }
    printf("\n");

    free(naves);
    return 0;
}