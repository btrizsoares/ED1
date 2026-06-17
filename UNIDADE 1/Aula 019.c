#include <stdio.h>
#include <stdlib.h>

int main () {
    float *ponteiro_altura_salto_duplo = NULL;
    printf("Jogador ainda nao possui Salto Duplo.\n");
    ponteiro_altura_salto_duplo = (float *) malloc(sizeof(float));

    if (ponteiro_altura_salto_duplo == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    *ponteiro_altura_salto_duplo = 15.5;
    printf("Pena Dourada coletada! Altura do Salto Duplo: %.2f\n", 
           *ponteiro_altura_salto_duplo);

    free(ponteiro_altura_salto_duplo); // em um jogo real, liberaria quando nao precisasse mais

    return 0;
}