#include <stdio.h>
#include <string.h>

int main () {
    char inventario[5][20];
    char chave[20];
    int encontrado = 0;

    printf("Digite os 5 itens que estao no seu inventario:\n");

    for (int i = 0; i < 5; i++) {
        printf("Item %d: ", i + 1);
        scanf("%19s", inventario[i]);
    }

    printf("Digite o item necessario:\n");
    scanf("%19s", chave);

    for (int i = 0; i < 5; i++) {
        if (strcmp(inventario[i], chave) == 0) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        printf("Porta aberta!\n");
    } else {
        printf("Voce nao tem o item necessario.\n");
    }

    return 0;
}