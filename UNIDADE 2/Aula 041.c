#include <stdio.h>
#include <stdlib.h>

void menu() {
    printf("Digite a opção\n");
    printf("1 - Registrar novo evento\n");
    printf("2 - Sair\n");
}

int main () {

    FILE *arquivo;
    int op;
    char evento[100];

    arquivo = fopen("./game_log.txt", "a");
    menu();
    scanf("%d", &op);

    while(op != 2) {
        if (op == 1){
            printf("Descreva o evento sem espaços: ");
            scanf("%s", evento);
            fprintf(arquivo, "%s\n", evento);

            printf("Evento registrado com sucesso!\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }

        menu();
        scanf("%d", &op);
    }
    printf("Programa finalizado\n");
    fclose(arquivo);

    return 0;
}