#include <stdio.h>

int calcularDanoEco(int n) {
    if (n == 1) {
        return 0;
    }
    else if (n == 2) {
        return 1;
    }
    else {
        return calcularDanoEco(n - 1) + calcularDanoEco(n - 2);
    }
}

int main() {
    int N;
    printf("Digite o número do golpe na sequência do Golpe Ecoante: ");
    scanf("%d", &N);

    if (N < 1) {
        printf("O número do golpe deve ser pelo menos 1.\n");
    } else {
        int dano_bonus = calcularDanoEco(N);
        printf("O dano bônus para o golpe %d é: %d\n", N, dano_bonus);
    }
    return 0;
}