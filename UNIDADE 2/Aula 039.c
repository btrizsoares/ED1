#include <stdio.h>
typedef struct {
    char nome[50];
    float hp;
    float atk;
} inimigo;

int main () {
    inimigo lista[3];
    float nivel_ameaca;

    FILE *file = fopen("inimigos.txt", "r");

    for (int i = 0; i < 3; i++) {
        fscanf(file, "%s %f %f", lista[i].nome, &lista[i].hp, &lista[i].atk);
    }
    for (int i = 0; i < 3; i++) {
        nivel_ameaca = lista[i].hp + lista[i].atk;

        if (nivel_ameaca >= 200) {
            printf("Nome: %s | Ameaca: %.2f\n", lista[i].nome, nivel_ameaca);
        }
    }

    fclose(file);

    return 0;
}