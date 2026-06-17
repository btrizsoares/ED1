#include <stdio.h>
int main () {
    int plataformas [5] = {10, 20, 5, 15, 30};
    int *ponteiro_plataforma;
    int altura_total = 0;

    for (int i = 0; i < 5; i++) {
        ponteiro_plataforma = (plataformas + i);
        altura_total += *ponteiro_plataforma;
    }

    printf("Altura total do salto: %d metros!\n", altura_total);

return 0;
}