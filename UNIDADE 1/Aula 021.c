#include <stdio.h>
#include <stdlib.h>

int main () {
    int *duracao_fumaca;
    duracao_fumaca = (int *) malloc(sizeof(int));

    if (duracao_fumaca == NULL) {
        printf("A memória não foi alocada!\n");
        return 1;
    }

    *duracao_fumaca = 5;
    printf("Bomba de fumaça ativada! Duração: %d segundos.\n",
           *duracao_fumaca);

    free(duracao_fumaca);

    duracao_fumaca = NULL;
    printf("A fumaça se dissipou.\n");

    return 0;
}