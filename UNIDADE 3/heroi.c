#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heroi.h"

struct heroi {
    char nome[50];
    int hp;
    int ataque;
};
Heroi* alocar_herois(int quantidade) {
    Heroi* vetor = (Heroi*) malloc(quantidade * sizeof(struct heroi));
    if (vetor == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    return vetor;
}
void ler_herois(Heroi* vetor, int quantidade) {
    for(int i = 0; i < quantidade; i++) {
        printf("\n--- Inserindo dados do Herói %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %49[^\n]", vetor[i].nome); 
        printf("Pontos de Vida (HP): ");
        scanf("%d", &vetor[i].hp);
        printf("Poder de Ataque: ");
        scanf("%d", &vetor[i].ataque);
    }
}
void imprimir_herois(Heroi* vetor, int quantidade) {
    printf("\n====================================\n");
    printf("         ROSTER DA EQUIPE\n");
    printf("====================================\n");
    for(int i = 0; i < quantidade; i++) {
        printf("[%d] %s | HP: %d | ATQ: %d\n", i + 1, vetor[i].nome, vetor[i].hp, vetor[i].ataque);
    }
    printf("====================================\n");
}
void liberar_herois(Heroi* vetor) {
    free(vetor);
}