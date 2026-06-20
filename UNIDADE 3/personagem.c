#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"

struct personagem {
    char nome[50];
    char classe[50];
    int nivel;
    int hp;
};

Personagem* cria_party(int num_membros) {
    Personagem* party = (Personagem*) malloc(num_membros * sizeof(struct personagem));
    
    if (party == NULL) {
        printf("Erro fatal: Falha na alocação de memória.\n");
        exit(1);
    }
    
    return party;
}

void registra_membros(Personagem* party, int num_membros) {
    for (int i = 0; i < num_membros; i++) {
        printf("\n--- Registro do Membro %d ---\n", i + 1);
        
        printf("Nome: ");
        scanf(" %49[^\n]", party[i].nome); 
        
        printf("Classe: ");
        scanf(" %49[^\n]", party[i].classe);
        
        printf("Nível: ");
        scanf("%d", &party[i].nivel);
        
        printf("HP: ");
        scanf("%d", &party[i].hp);
    }
}

void exibe_relatorio(const Personagem* party, int num_membros) {
    printf("\n====================================\n");
    printf("         RELATÓRIO DA EQUIPE\n");
    printf("====================================\n");
    
    for (int i = 0; i < num_membros; i++) {
        printf("[%d] %s | Classe: %s | Nível: %d | HP: %d\n", 
               i + 1, party[i].nome, party[i].classe, party[i].nivel, party[i].hp);
    }
    
    printf("====================================\n");
}

void libera_party(Personagem* party) {
    free(party);
}