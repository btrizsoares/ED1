#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, chave;
    int *fragmentos;

    printf("Quantos fragmentos de alma foram coletados? ");
    scanf("%d", &n);
    fragmentos = (int *)malloc(n * sizeof(int));
    if (fragmentos == NULL) {
        printf("Erro: Não foi possível alocar espaço na Bolsa de Runas.\n");
        return 1;
    }
    printf("Insira o nível de poder de cada fragmento:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &fragmentos[i]);
    }
    for (i = 1; i < n; i++) {
        chave = fragmentos[i];
        j = i - 1;
        while (j >= 0 && fragmentos[j] > chave) {
            fragmentos[j + 1] = fragmentos[j];
            j--;
        }
        fragmentos[j + 1] = chave;
    }
    printf("\nBolsa de Runas organizada (Poderes): \n");
    for (i = 0; i < n; i++) {
        printf("%d ", fragmentos[i]);
    }

    printf("\n");
    free(fragmentos);
    return 0;
}