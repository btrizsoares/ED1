#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int eliminacoes;
} Jogador;

int main() {
    int n, i, j, max_idx;
    Jogador temp;
    Jogador *jogadores;
    printf("Digite o número de jogadores na partida: ");
    scanf("%d", &n);
    jogadores = (Jogador *)malloc(n * sizeof(Jogador));
    if (jogadores == NULL) {
        printf("Erro: Memória insuficiente.\n");
        return 1;
    }
    printf("\nInsira os dados dos jogadores:\n");
    for (i = 0; i < n; i++) {
        printf("Jogador %d (Nome e Eliminações): ", i + 1);
        scanf("%49s %d", jogadores[i].nome, &jogadores[i].eliminacoes);
    }
    for (i = 0; i < n - 1; i++) {
        max_idx = i;
        for (j = i + 1; j < n; j++) {
            if (jogadores[j].eliminacoes > jogadores[max_idx].eliminacoes) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            temp = jogadores[i];
            jogadores[i] = jogadores[max_idx];
            jogadores[max_idx] = temp;
        }
    }
    printf("\n LEADERBOARD \n");
    for (i = 0; i < n; i++) {
        printf("%d Lugar: %s com %d kills\n", i + 1, jogadores[i].nome, jogadores[i].eliminacoes);
    }
    free(jogadores);
    return 0;
}