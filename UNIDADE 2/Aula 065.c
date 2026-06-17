#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int pontuacao;
} Jogador;

int main() {
    int n, i, j;
    Jogador *jogadores;
    Jogador chave;
    printf("Digite a quantidade de jogadores: ");
    scanf("%d", &n);

    jogadores = (Jogador *)malloc(n * sizeof(Jogador));
    if (jogadores == NULL) {
        printf("Erro: Memória insuficiente para carregar os jogadores.\n");
        return 1;
    }

    printf("\nInsira os dados (Nome e Pontuação:\n");
    for (i = 0; i < n; i++) {
        scanf("%49s %d", jogadores[i].nome, &jogadores[i].pontuacao);
    }

    for (i = 1; i < n; i++) {
        chave = jogadores[i];
        j = i - 1;
        while (j >= 0 && jogadores[j].pontuacao < chave.pontuacao) {
            jogadores[j + 1] = jogadores[j];
            j--;
        }
        jogadores[j + 1] = chave;
    }

    printf("\n=== RANKING FINAL ===\n");
    for (i = 0; i < n; i++) {
        printf("%d %s\n", jogadores[i].pontuacao, jogadores[i].nome);
    }

    free(jogadores);
    return 0;
}