#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aventureiro {
    int id;
    char nome[50];
    struct Aventureiro* proximo;
} Aventureiro;

void adicionar_aventureiro(Aventureiro** cabeca) {
    Aventureiro* novo_aventureiro = (Aventureiro*) malloc(sizeof(Aventureiro));
    
    if (novo_aventureiro == NULL) {
        printf("Erro fatal: Falha na alocação de memória.\n");
        return;
    }
    printf("\n--- Novo Aventureiro Aproximando-se ---\n");
    printf("Digite o ID do aventureiro: ");
    scanf("%d", &novo_aventureiro->id);
    
    printf("Digite o nome do aventureiro: ");
    scanf(" %49[^\n]", novo_aventureiro->nome); 

    novo_aventureiro->proximo = *cabeca;
    *cabeca = novo_aventureiro;

    printf(">> %s juntou-se ao grupo e assumiu a liderança!\n", novo_aventureiro->nome);
}

void mostrar_grupo(Aventureiro* cabeca) {
    if (cabeca == NULL) {
        printf("\nA sua party está vazia. Recrute alguns heróis!\n");
        return;
    }

    printf("\n====================================\n");
    printf("      FORMAÇÃO ATUAL DO GRUPO\n");
    printf("====================================\n");
    
    Aventureiro* atual = cabeca;
    int posicao = 1;

    while (atual != NULL) {
        if (posicao == 1) {
            printf("[%d] LÍDER -> ID: %d | Nome: %s\n", posicao, atual->id, atual->nome);
        } else {
            printf("[%d]        ID: %d | Nome: %s\n", posicao, atual->id, atual->nome);
        }
        atual = atual->proximo;
        posicao++;
    }
    printf("====================================\n");
}

void liberar_grupo(Aventureiro* cabeca) {
    Aventureiro* atual = cabeca;
    while (atual != NULL) {
        Aventureiro* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

int main() {
    Aventureiro* party = NULL; 
    int opcao;

    do {
        printf("\n[ ACAMPAMENTO BASE ]\n");
        printf("1. Adicionar Aventureiro\n");
        printf("2. Mostrar Grupo\n");
        printf("3. Sair\n");
        printf("Escolha sua ação: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_aventureiro(&party);
                break;
            case 2:
                mostrar_grupo(party);
                break;
            case 3:
                printf("\nEncerrando a sessão e desfazendo o acampamento...\n");
                liberar_grupo(party);
                break;
            default:
                printf("\nAção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}