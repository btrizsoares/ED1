#include <stdio.h>
#include <stdlib.h>

struct Moeda {
    int posicao_x;
    int posicao_y;
    int valor;
};

int main() {
    int quantidade;
    printf("Quantas moedas existem no nivel? ");
    scanf("%d", &quantidade);

    struct Moeda *moedas = (struct Moeda *) malloc(quantidade * sizeof(struct Moeda));

    for (int i = 0; i < quantidade; i++) {
        printf("Moeda %d - posicao x: ", i + 1);
        scanf("%d", &moedas[i].posicao_x);

        printf("Moeda %d - posicao y: ", i + 1);
        scanf("%d", &moedas[i].posicao_y);

        printf("Moeda %d - valor: ", i + 1);
        scanf("%d", &moedas[i].valor);
    }

    int total_pontos = 0;

    for (int i = 0; i < quantidade; i++) {
        total_pontos += moedas[i].valor;
    }

    printf("Pontuacao maxima do nivel: %d\n", total_pontos);

    free(moedas);

    return 0;
}