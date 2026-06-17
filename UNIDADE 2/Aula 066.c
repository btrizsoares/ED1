#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Digite a quantidade de jogadores na partida: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("A quantidade de jogadores deve ser maior que zero.\n");
        return 1;
    }

    int *pontuacoes = (int *)malloc(n * sizeof(int));
    if (pontuacoes == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    printf("\n--- Inserindo Pontuacoes ---\n");
    for (int i = 0; i < n; i++) {
        printf("Digite a pontuacao do jogador %d: ", i + 1);
        scanf("%d", &pontuacoes[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pontuacoes[j] < pontuacoes[j + 1]) {
                int temp = pontuacoes[j];
                pontuacoes[j] = pontuacoes[j + 1];
                pontuacoes[j + 1] = temp;
            }
        }
    }

    printf("\nPlacar Final.\n");
    for (int i = 0; i < n; i++) {
        printf("%d", pontuacoes[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    free(pontuacoes);

    return 0;
}