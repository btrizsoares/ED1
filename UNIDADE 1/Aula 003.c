#include <stdio.h>
int main () {
    float coordenada_x;
    float *ponteiro_x;

    ponteiro_x = &coordenada_x;
    printf("Digite a cordenada do portal: \n");
    scanf("%f", &coordenada_x);

    printf("Posição do portal no eixo X: %f\n", coordenada_x);

    printf("Endereço do portal para teletransporte: %p\n", ponteiro_x);

    return 0;
}