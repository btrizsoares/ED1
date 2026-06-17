#include <stdio.h>

int main () {
    int balas[2];
    int granadas[2];
    int foguetes[2];
    int *inventario[3];

    for (int i = 0; i < 2; i++) {
        scanf("%d", &balas[i]);
    }
    for (int i = 0; i < 2; i++) {
        scanf("%d", &granadas[i]);
    }
    for (int i = 0; i < 2; i++) {
        scanf("%d", &foguetes[i]);
    }

    inventario[0] = balas;
    inventario[1] = granadas;
    inventario[2] = foguetes;

    printf("Inventario Inicial:\n");
    printf("Balas: %d\n", inventario[0][0]);
    printf("Granadas: %d\n", inventario[1][0]);
    printf("Foguetes: %d\n", inventario[2][0]);

    for (int i = 0; i < 3; i++) {
        (*inventario[i])--;
    }

    printf("\nInventario Apos o Uso:\n");
    printf("Balas: %d\n", inventario[0][0]);
    printf("Granadas: %d\n", inventario[1][0]);
    printf("Foguetes: %d\n", inventario[2][0]);

    return 0;
}