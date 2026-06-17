#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int resolucao_x;
    int resolucao_y;
    float volume_som;
} Configuracao;

int main () {

    FILE *arquivo;
    Configuracao meujogo;

    arquivo = fopen("config.txt", "r");

    if (arquivo == NULL) {
        printf("Erro: Arquivo config.txt não encontrado.\n");
        return 1;
    }

    fscanf(arquivo, "%d %d %f", &meujogo.resolucao_x, &meujogo.resolucao_y, &meujogo.volume_som);

    printf("Configurações carregadas: \n");
    printf("Resolução: %dx%d\n", meujogo.resolucao_x, meujogo.resolucao_y);
    printf("Volume: %.1f\n", meujogo.volume_som);

    fclose(arquivo);

    return 0;
}