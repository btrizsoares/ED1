#include <stdio.h>

typedef struct {
    char nome[50];
    int pontuacao;
} jogador;

int main () {
    int n;

    printf("Informe a quantidade de jogadores: ");
    scanf("%d", &n);

    jogador v[n];
    int indiceVencedor = 0;

    for (int i = 0; i < n; i++) {
        printf("Jogador %d:\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", v[i].nome);

        printf("Pontuacao: ");
        scanf("%d", &v[i].pontuacao);

        if (v[i].pontuacao > v[indiceVencedor].pontuacao) {
            indiceVencedor = i;
        }
    }

    FILE *arquivo;
    arquivo = fopen("highscore.txt", "w");
    fprintf(arquivo, "Nome: %s, Pontuacao: %d\n", v[indiceVencedor].nome, v[indiceVencedor].pontuacao);
    fclose(arquivo);

    printf("Recorde de %s salvo com sucesso em highscore.txt!\n", v[indiceVencedor].nome);

    return 0;
}