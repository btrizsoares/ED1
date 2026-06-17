#include <stdio.h>
#include <stdlib.h>

int main () {
    int *mochila;
    mochila = (int *) malloc(3 * sizeof(int));

    printf("Digite os valores dos 3 primeiros itens encontrados.\n");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &mochila[i]);
    }

    printf("Itens na mochila:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", mochila[i]);
    }
    printf("\n");

    mochila = (int *) realloc(mochila, 6 * sizeof(int));

    printf("Digite mais 3 itens:\n");
    for (int i = 3; i < 6; i++) {
        scanf("%d", &mochila[i]);
    }

    printf("Mochila completa:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", mochila[i]);
    }
    printf("\n");

    free(mochila);

    return 0;
}