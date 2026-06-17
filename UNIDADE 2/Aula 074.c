#include <stdio.h>

void particao(int n, int v[]) {
    int pivo = v[n - 1];
    int i = -1;
    int j;
    int temp;
    for (j = 0; j < n - 1; j++) {
        if (v[j] < pivo) {
            i++;
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    temp = v[i + 1];
    v[i + 1] = v[n - 1];
    v[n - 1] = temp;
}

int main() {
    int n;
    int i;
    printf("Sistema de Triagem da Legiao de Ferro ativado.\n");
    printf("Informe a quantidade de unidades mecha retornando da batalha: ");
    scanf("%d", &n);

    int v[n];
    printf("Informe os pontos de vida (HP) de cada unidade, separados por espaco ou enter:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    particao(n, v);
    printf("Reorganizacao tatica concluida. Nova disposicao de HP:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}