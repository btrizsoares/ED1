#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *arquivo = fopen("level_1_map.dat", "r");
    if (arquivo == NULL) {
        printf("ERRO CRÍTICO: Não foi possivel carregar os dados do mapa.\n");
        perror("Detalhes do erro");
        system("pause");
        exit(1);
    }

    fclose(arquivo);
    return 0;
}