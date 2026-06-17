#include <stdio.h>
#include <string.h>

struct ItemColetavel {
    char nome[50];
    int valor_pontos;
};

int main() {
    struct ItemColetavel inventario[3];

    for (int i = 0; i < 3; i++) {
        printf("Digite o nome do item %d: ", i + 1);
        scanf("%s", inventario[i].nome);

        printf("Digite o valor em pontos do item %d: ", i + 1);
        scanf("%d", &inventario[i].valor_pontos);
    }

    struct ItemColetavel mais_valioso = inventario[0];

    for (int i = 1; i < 3; i++) {
        if (inventario[i].valor_pontos > mais_valioso.valor_pontos) {
            mais_valioso = inventario[i];
        }
    }

    printf("O item mais valioso coletado foi: %s\n", mais_valioso.nome);

    return 0;
}