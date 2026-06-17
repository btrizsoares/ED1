#include <stdio.h>
#include <stdlib.h>

void particao(int n, int v[]) {
    int *s = (int *)malloc(n * sizeof(int));
    if (s == NULL) {
        printf("Erro de alocacao no vetor secundario.\n");
        return;
    }
    int pivo = v[n - 1];
    int esq = 0;
    int dir = n - 1;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] <= pivo) {
            s[esq] = v[i];
            esq++;
        } else {
            s[dir] = v[i];
            dir--;
        }
    }
    s[esq] = pivo;
    for (int i = 0; i < n; i++) {
        v[i] = s[i];
    }
    free(s);
}

int main() {
    int n;
    printf("Digite a quantidade de itens no bau: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    int *v = (int *)malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

    printf("\nInsira o nivel de poder de cada item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &v[i]);
    }
    particao(n, v);
    printf("\nLista reorganizada apos a triagem:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    free(v);
    return 0;
}