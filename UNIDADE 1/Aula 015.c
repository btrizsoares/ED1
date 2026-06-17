#include <stdio.h>
#include <string.h>

int main () {
    char nome_jogador[50];
    char titulo_conquistado[50];

    printf("Digite o nome do seu héroi: \n");
    scanf("%s", nome_jogador);

    printf("Digite o nome do título conquistado: \n");
    scanf("%s", titulo_conquistado);

    strcat(nome_jogador, " ");
    strcat(nome_jogador, titulo_conquistado);

    printf("O herói agora é conhecido como: %s\n", nome_jogador);

    return 0;
}