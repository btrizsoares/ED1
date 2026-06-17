#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    printf("Digite o número de inimigos do Portal Alfa: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Quantidade inválida.\n");
        return 1;
    }

    int *alfa = (int *)malloc(n * sizeof(int));
    if (alfa == NULL && n > 0) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    if (n > 0) {
        printf("Digite os %d níveis de ameaça do Portal Alfa: \n", n);
        for (int i = 0; i < n; i++) {
            printf("Inimigo %d: ", i + 1);
            scanf("%d", &alfa[i]);
        }
    }

    printf("\nDigite o número de inimigos do Portal Beta: ");
    if (scanf("%d", &m) != 1 || m < 0) {
        printf("Quantidade inválida.\n");
        free(alfa);
        return 1;
    }

    int *beta = (int *)malloc(m * sizeof(int));
    if (beta == NULL && m > 0) {
        printf("Erro de alocação de memória.\n");
        free(alfa);
        return 1;
    }
    if (m > 0) {
        printf("Digite os %d níveis de ameaça do Portal Beta:\n", m);
        for (int i = 0; i < m; i++) {
            printf("Inimigo %d: ", i + 1);
            scanf("%d", &beta[i]);
        }
    }

    int *resultado = (int *)malloc((n + m) * sizeof(int));
    if (resultado == NULL && (n + m) > 0) {
        printf("Erro de alocação de memória.\n");
        free(alfa);
        free(beta);
        return 1;
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < m) {
        if (alfa[i] < beta[j]) {
            resultado[k] = alfa[i];
            i++;
        } else {
            resultado[k] = beta[j];
            j++;
        }
        k++;
    }
    while (i < n) {
        resultado[k] = alfa[i];
        i++;
        k++;
    }

    while (j < m) {
        resultado[k] = beta[j];
        j++;
        k++;
    }
    printf("\nLista unificada de ameaças: \n");
    for (k = 0; k < (n + m); k++) {
        printf("%d ", resultado[k]);
    }
    printf("\n");

    free(alfa);
    free(beta);
    free(resultado);

    return 0;
}