#include <stdio.h>

struct Jogador {
    float pos_x;
    int pontuacao;
    int tem_pulo_duplo;
};

int main () {
    struct Jogador heroi;

    heroi.pos_x = 50.0;
    heroi.pontuacao = 0;
    heroi.tem_pulo_duplo = 0;

    printf("Início da fase! Posição X: %.1f, Pontos: %d, Pulo Duplo: %s\n",
           heroi.pos_x,
           heroi.pontuacao,
           heroi.tem_pulo_duplo ? "Sim" : "Não");

    heroi.pontuacao += 10;
    heroi.tem_pulo_duplo = 1;

    printf("Após coletar itens! Posição X: %.1f, Pontos: %d, Pulo Duplo: %s\n",
           heroi.pos_x,
           heroi.pontuacao,
           heroi.tem_pulo_duplo ? "Sim" : "Não");

    return 0;
}