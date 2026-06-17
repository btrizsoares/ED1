#include <stdio.h>

int main() {
    int placar[5] = {120, 125, 130, 142, 150};
    int novo_tempo;
    int i;
    printf("Digite o novo tempo do jogador: ");
    scanf("%d", &novo_tempo);
    if (novo_tempo < placar[4]) {
        i = 3;

        while (i >= 0 && placar[i] > novo_tempo) {
            placar[i + 1] = placar[i];
            i--;
        }

        placar[i + 1] = novo_tempo;
    }

    printf("\n TOP 5 TEMPOS \n");
    for (i = 0; i < 5; i++) {
        printf("%dº Lugar: %d\n", i + 1, placar[i]);
    }

    return 0;
}