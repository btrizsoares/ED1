#include <stdio.h>
#include "personagem.h"

int main() {
    int num_membros;

    printf("Bem-vindo ao Gerenciador de Roster!\n");
    printf("Quantos membros a sua equipe terá? ");
    scanf("%d", &num_membros);

    if (num_membros <= 0) {
        printf("A equipe precisa ter pelo menos 1 membro.\n");
        return 1;
    }

    Personagem* party = cria_party(num_membros);

    registra_membros(party, num_membros);

    exibe_relatorio(party, num_membros);

    libera_party(party);

    return 0;
}