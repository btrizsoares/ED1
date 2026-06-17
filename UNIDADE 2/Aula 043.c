#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int vida;
    int ataque;
} Inimigo;

int main() {
    FILE *arquivo;
    Inimigo inimigo_atual;
    Inimigo maior_ameaca;

    maior_ameaca.ataque = -1;

    arquivo = fopen("wave_data.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo txt.\n");
        return 1;
    }
    while (fscanf(arquivo, "%s %d %d", &inimigo_atual.nome, &inimigo_atual.vida, &inimigo_atual.ataque) != EOF) {
        if (inimigo_atual.ataque > maior_ameaca.ataque) {
            maior_ameaca = inimigo_atual;
        }
    }

    printf("Maior Ameaça: %s, Vida: %d, Ataque: %d\n", maior_ameaca.nome, maior_ameaca.vida, maior_ameaca.ataque);
    fclose(arquivo);
    return 0;
}