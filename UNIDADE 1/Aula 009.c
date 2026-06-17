#include <stdio.h>

int main () {
    int moedas_coletadas[5];
    int pontuacao_total = 0;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &moedas_coletadas[i]);
    }

    int *ponteiro_moeda;
    ponteiro_moeda = moedas_coletadas;
    int *fim = moedas_coletadas + 5;

    while (ponteiro_moeda < fim) {
        pontuacao_total += *ponteiro_moeda;
        ponteiro_moeda++;
    }

    printf("Pontuação total do nível: %d", pontuacao_total);

    return 0;
}