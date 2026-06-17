#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particao(int v[], int baixo, int alto) {
    int pivo = v[alto];
    int i = baixo - 1;
    int j;
    for (j = baixo; j < alto; j++) {
        if (v[j] <= pivo) {
            i++;
            trocar(&v[i], &v[j]);
        }
    }
    trocar(&v[i + 1], &v[alto]);
    return i + 1;
}

void quickSort(int v[], int baixo, int alto) {
    if (baixo < alto) {
        int pivo_indice = particao(v, baixo, alto);
        quickSort(v, baixo, pivo_indice - 1);
        quickSort(v, pivo_indice + 1, alto);
    }
}

int main() {
    int n;
    int i;
    printf("Sistema de Matchmaking Competitivo Ativado.\n");
    printf("Informe a quantidade de jogadores aguardando na fila: ");
    scanf("%d", &n);

    int v[n];
    printf("Insira o MMR de cada jogador (separado por espaco ou enter):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    quickSort(v, 0, n - 1);
    printf("Fila de jogadores ordenada por MMR:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}