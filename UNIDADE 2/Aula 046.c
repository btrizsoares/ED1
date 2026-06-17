#include <stdio.h>

typedef struct {
    char nome[50];
    int nivel;
    int highScore;
} PlayerProfile;

int main () {
    FILE *arquivo;
    PlayerProfile jogador;

    arquivo = fopen("profiles.dat", "rb");

    printf("Relatório de ranks dos jogadores\n");

    while (fread(&jogador, sizeof(PlayerProfile), 1, arquivo) == 1) {
        printf("Jogador: %s / High Score: %d / Rank: ", jogador.nome, jogador.highScore);

        if (jogador.highScore > 10000) {
            printf("Mestre do Jogo\n");
        } else if (jogador.highScore > 5000) {
            printf("Veterano\n");
        } else {
            printf("Aspirante\n");
        }
    }

    fclose(arquivo);

    return 0;
}