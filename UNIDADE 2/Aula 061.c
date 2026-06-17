#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Digite a quantidade de jogadores no ranking: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }
    int *scores = (int *)malloc(N * sizeof(int));
    if (scores == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("Digite a pontuacao do jogador %d: ", i + 1);
        scanf("%d", &scores[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < N; j++) {
            if (scores[j] < scores[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = scores[i];
            scores[i] = scores[min_idx];
            scores[min_idx] = temp;
        }
    }
    printf("\nRanking final ordenado (do menor para o maior):\n");
    for (int i = 0; i < N; i++) {
        printf("%d", scores[i]);
        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");
    free(scores);

    return 0;
}