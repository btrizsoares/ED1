#include <stdio.h>

int main() {
    int n;
    printf("Digite a energia inicial do Golem: ");
    if (scanf("%d", &n) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }
    printf("\nIniciando o ritual...\n");
    while (n > 1) {
        printf("Energia atual: %d\n", n);
        n = n / 2;
    }
    printf("Ritual concluido! O Golem atingiu energia %d.\n", n);
    return 0;
}