#include <stdio.h>

struct Heroi {
    int saude;
    int pontuacao;
    int posX;
    int posY;
};

int main() {
    struct Heroi meuHeroi = {100, 0, 0, 0};

    printf("Estado inicial: Saude=%d, Pontuacao=%d, posX=%d, posY=%d\n",
           meuHeroi.saude, meuHeroi.pontuacao, meuHeroi.posX, meuHeroi.posY);

    struct Heroi *ptrHeroi = &meuHeroi;

    ptrHeroi->saude -= 25;
    printf("Saude apos dano: %d\n", ptrHeroi->saude);

    ptrHeroi->pontuacao += 50;
    printf("Pontuacao apos coletar moedas: %d\n", ptrHeroi->pontuacao);

    ptrHeroi->posX += 10;
    ptrHeroi->posY -= 5;
    printf("Nova posicao: posX=%d, posY=%d\n", ptrHeroi->posX, ptrHeroi->posY);

    printf("Estado final: Saude=%d, Pontuacao=%d, posX=%d, posY=%d\n",
           ptrHeroi->saude, ptrHeroi->pontuacao, ptrHeroi->posX, ptrHeroi->posY);

    return 0;
}