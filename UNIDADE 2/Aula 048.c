#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int vida;
    int ataque;
} Campeao;

int main () {
    FILE *arquivo;
    Campeao esquadrao[3];

    arquivo = fopen("squad.dat", "rb");
    fread(esquadrao, sizeof(Campeao), 3, arquivo);
    fclose(arquivo);

    int maiorVida = esquadrao[0].vida;
    int indiceTanque = 0;

    for (int i = 1; i < 3; i++) {
        if (esquadrao[i].vida > maiorVida) {
            maiorVida = esquadrao[i].vida;
            indiceTanque = i;
        }
    }

    printf("%s: Tanque do esquadrão.\n", esquadrao[indiceTanque].nome);
    return 0;
}