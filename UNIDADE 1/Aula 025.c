#include <stdio.h>
#include <stdlib.h>

int main () {
    int inimigos;
    int *status_inimigos;

    printf("Digite a quantidade de inimigos da fase:\n");
    scanf("%d", &inimigos);

    status_inimigos = (int *) calloc(inimigos, sizeof(int));

    for (int i = 0; i < inimigos; i++) {
        printf("Inimigo %d Inativo (%d)\n", i + 1, status_inimigos[i]);
    }
    for (int i = 0; i < inimigos; i++) {
        status_inimigos[i] = 1;
    }
    for (int i = 0; i < inimigos; i++) {
        printf("Inimigo %d: Ativo (%d)\n", i + 1, status_inimigos[i]);
    }
    free(status_inimigos);

    return 0;
}