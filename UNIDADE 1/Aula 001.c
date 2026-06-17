#include <stdio.h>

int main () {
    int vida_jogador = 100;
    int *ponteiro_vida;

    vida_jogador = 50;

    printf("O jogador sofreu dano! Vida atual: %d\n", vida_jogador);

    ponteiro_vida = &vida_jogador;
    *ponteiro_vida = 100;
    printf("Power up coletado! Vida restaurada: %d\n", vida_jogador);
    
    return 0;
}