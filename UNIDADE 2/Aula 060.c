#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int hp;
} Monstro;

int main () {
    int n;
    printf("Quantos monstros há na horda? ");
    scanf("%d", &n);

    Monstro *horda = (Monstro *)malloc(n * sizeof(Monstro));
    if (horda == NULL) {
        printf("Erro.");
        return 1;
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("Digite o nome e o HP do monstro %d: ", i + 1);
        scanf("%49s %d", horda[i].nome, &horda[i].hp);
    }

    int indice_alvo = 0;

    for (int i = 1; i < n; i++) {
        if (horda[i].hp < horda[indice_alvo].hp) {
            indice_alvo = i;
        }
    }

    printf("Alvo prioritário: %s (%d HP)\n", horda[indice_alvo].nome, horda[indice_alvo].hp);
    free(horda);
    return 0;
}