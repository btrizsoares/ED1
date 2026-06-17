#include <stdio.h>
int main () {
    int mapa_fase1[5][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 2, 0, 1, 1},
    {0, 0, 1, 1, 0, 1, 0, 0},
    {1, 1, 1, 1, 2, 2, 1, 1}
    };

    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 8; j++) {
            if (mapa_fase1[i][j] == 2) {
                printf("Espinho encontrado na linha %d, coluna %d\n", i, j);
            }
        }
    }
    return 0;
}