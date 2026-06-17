#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int vida;
    int ataque;
} Unidade;

int main () {
    FILE *arquivo;
    Unidade *esquadrao;
    int n;

    printf("Quantas unidades o esquadrão terá? ");
    scanf("%d", &n);

    esquadrao = (Unidade *)malloc(n * sizeof(Unidade));

    printf("Montagem do Esquadrão:");
    for (int i = 0; i < n; i++) {
        printf("Unidade %d:\n", i + 1);
        printf("Nome: ");
        scanf("%49s", esquadrao[i].nome);
        printf("Vida: ");
        scanf("%d", &esquadrao[i].vida);
        printf("Ataque: ");
        scanf("%d", &esquadrao[i].ataque);
    }

    arquivo = fopen("squad.dat", "wb");
    fwrite(esquadrao, sizeof(Unidade), n, arquivo);
    fclose(arquivo);

    int maiorAtk = esquadrao[0].ataque;
    int indiceMaior = 0;

    for (int i = 1; i < n; i++) {
        if (esquadrao[i].ataque > maiorAtk) {
            maiorAtk = esquadrao[i].ataque;
            indiceMaior = i;
        }
    }

    printf("Relatório da Missão\n");
    printf("Arquivo 'squad.dat' salvo com sucesso com %d unidade(s).\n", n);
    printf("A unidade com o maior poder de ataque é: %s (ATK: %d)\n", esquadrao[indiceMaior].nome, maiorAtk);

    free(esquadrao);
    return 0;
}