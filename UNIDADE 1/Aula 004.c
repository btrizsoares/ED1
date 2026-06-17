#include <stdio.h>

void aplicar_powerup_pontuacao_dupla (int *pontuacao) {

    *pontuacao = (*pontuacao) * 2;

}

int main () {
    int pontuacao_jogador = 1500;
    printf("Pontuação antes do power-up: %d\n", pontuacao_jogador);

    aplicar_powerup_pontuacao_dupla(&pontuacao_jogador);

    printf("Pontuação após o power-up: %d\n", pontuacao_jogador);
    
    return 0;
}