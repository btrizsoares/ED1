#include <stdio.h>

int main () {
    float base;
    float danoarma;
    float buff;
    printf("Informe os valores do personagem (base, dano da arma e buff, respectivamente): ");
    scanf("%f %f %f", &base, &danoarma, &buff);
    float soma = base + danoarma + buff;
    printf("%.2f\n", soma);
    return 0;
}