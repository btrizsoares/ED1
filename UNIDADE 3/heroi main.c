#include <stdio.h>
#include "heroi.h"

int main() {
    int quantidade;

    printf("Bem-vindo ao Gerenciador de Roster!\n");
    printf("Quantos heróis farão parte da sua equipe nesta missão? ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Você precisa de pelo menos 1 herói para a missão!\n");
        return 1;
    }

    Heroi* equipe = alocar_herois(quantidade);

    ler_herois(equipe, quantidade);

    imprimir_herois(equipe, quantidade);

    liberar_herois(equipe);

    return 0;
}