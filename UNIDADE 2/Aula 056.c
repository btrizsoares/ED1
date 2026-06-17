#include <stdio.h>

int ataque_em_cascata(int nivel) {
    if (nivel == 1) {
        return 1;
    }
    else {
        return nivel + ataque_em_cascata(nivel - 1);
    }
}

int main() {
    int nivel_mago;
    int dano_total;

    printf("Digite o nível atual do mago: ");
    scanf("%d", &nivel_mago);

    if (nivel_mago < 1) {
        printf("O nível do mago deve ser 1 ou maior.\n");
    } else {
        dano_total = ataque_em_cascata(nivel_mago);
        printf("O dano total do Ataque em Cascata no nivel %d é: %d\n", nivel_mago, dano_total);
    }

    return 0;
}