#include <stdio.h>
int main() {
    int pontuacao = 0;
    int *ponteiro_pontuacao;

    ponteiro_pontuacao = &pontuacao;

    printf("Pontuação inicial: %d\n", pontuacao);

    for (int i = 0; i < 3; i++) {
        *ponteiro_pontuacao += 10;
    }

    printf("Pontuação final após coletar 3 moedas: %d\n", *ponteiro_pontuacao);

    return 0;
}