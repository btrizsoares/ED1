#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int pontuacao;
} Jogador;

void bubbleSort(Jogador arr[], int n) {
    int i, j;
    Jogador temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].pontuacao < arr[j + 1].pontuacao) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Digite a quantidade de jogadores na partida: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    Jogador *jogadores = (Jogador *)malloc(n * sizeof(Jogador));
    if (jogadores == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

    printf("\nInsira os dados dos jogadores:\n");
    for (int i = 0; i < n; i++) {
        printf("\n--- Jogador %d ---\n", i + 1);

        printf("Digite o ID: ");
        scanf("%d", &jogadores[i].id);

        printf("Digite a pontuacao: ");
        scanf("%d", &jogadores[i].pontuacao);
    }
    bubbleSort(jogadores, n);
    printf("\n========= PLACAR FINAL =========\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", jogadores[i].id, jogadores[i].pontuacao);
    }

    free(jogadores);
    return 0;
}