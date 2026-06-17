#include <stdio.h>
#include <stdlib.h>

int main () {
    int n_inimigos;
    int *ponteiro_onda;

    printf("Digite a quantidade de inimigos: ");
    scanf("%d", &n_inimigos);

    ponteiro_onda = (int *) malloc(n_inimigos * sizeof(int));

    if (ponteiro_onda == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (int i = 0; i < n_inimigos; i++) {
        printf("Escreva o ID do inimigo %d: ", i + 1);
        scanf("%d", &ponteiro_onda[i]);
    }

    printf("Onda de inimigos criada com sucesso! IDs: ");
    for (int i = 0; i < n_inimigos; i++) {
        printf("%d ", ponteiro_onda[i]);
    }
    printf("\n");

    free(ponteiro_onda);

    return 0;
}