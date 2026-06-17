#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int pontos;
} Conquista;

int main () {

    FILE *arquivo;
    Conquista conquista_atual;
    int total_conquistas;
    int total_xp = 0;

    arquivo = fopen("player_log.txt", "r+");

    if (arquivo == NULL) {
        printf("Erro: Arquivo player_log.txt não encontrado\n");
        return 1;
    }

    fscanf(arquivo, "%d", &total_conquistas);

    for (int i = 0; i < total_conquistas; i++) {
        fscanf(arquivo, "%d %d", &conquista_atual.id, &conquista_atual.pontos);

        total_xp += conquista_atual.pontos;
    }
    printf("Total de pontos de experiência ganhos: %d\n", total_xp);

    fseek(arquivo, 0, SEEK_END);

    fprintf(arquivo, "\n--- SESSION CONCLUDED ---");

    fclose(arquivo);
    return 0;
}