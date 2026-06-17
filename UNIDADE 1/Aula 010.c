#include <stdio.h>

int main () {
    int sala_1[3];
    int sala_2[2];
    int sala_3[4];
    int *ponteiro_salas[3];

    for (int i = 0; i < 3; i++) {
        scanf("%d", &sala_1[i]);
    }
    for (int i = 0; i < 2; i++) {
        scanf("%d", &sala_2[i]);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", &sala_3[i]);
    }

    ponteiro_salas[0] = sala_1;
    ponteiro_salas[1] = sala_2;
    ponteiro_salas[2] = sala_3;

    int tamanhos[3] = {3, 2, 4};

    for (int i = 0; i < 3; i++) {
        printf("Moedas na Sala %d: ", i + 1);
        for (int j = 0; j < tamanhos[i]; j++) {
            printf("%d ", ponteiro_salas[i][j]);
        }
        printf("\n");
    }

    return 0;
}