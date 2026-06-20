#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jogador {
    int matricula;
    char nome[50];
    struct Jogador* proximo;
} Jogador;

void adicionar_inicio(Jogador** cabeca) {
    Jogador* novo_jogador = (Jogador*) malloc(sizeof(Jogador));
    if (novo_jogador == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    printf("\n--- Novo Jogador VIP ---\n");
    printf("Matrícula: ");
    scanf("%d", &novo_jogador->matricula);
    printf("Nome: ");
    scanf(" %49[^\n]", novo_jogador->nome);

    novo_jogador->proximo = *cabeca;
    *cabeca = novo_jogador;

    printf(">> %s entrou no INÍCIO da fila (Prioridade)!\n", novo_jogador->nome);
}

void adicionar_fim(Jogador** cabeca) {
    Jogador* novo_jogador = (Jogador*) malloc(sizeof(Jogador));
    if (novo_jogador == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    printf("\n--- Novo Jogador ---\n");
    printf("Matrícula: ");
    scanf("%d", &novo_jogador->matricula);
    printf("Nome: ");
    scanf(" %49[^\n]", novo_jogador->nome);
    
    novo_jogador->proximo = NULL; 

    if (*cabeca == NULL) {
        *cabeca = novo_jogador;
    } 
    else {
        Jogador* atual = *cabeca;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo_jogador;
    }

    printf(">> %s entrou no FINAL da fila.\n", novo_jogador->nome);
}
void mostrar_fila(Jogador* cabeca) {
    if (cabeca == NULL) {
        printf("\nA fila de matchmaking está vazia no momento.\n");
        return;
    }

    printf("\n====================================\n");
    printf("        FILA DE MATCHMAKING\n");
    printf("====================================\n");
    
    Jogador* atual = cabeca;
    int posicao = 1;
    
    while (atual != NULL) {
        printf("%dº da Fila -> Matrícula: %d | Nome: %s\n", posicao, atual->matricula, atual->nome);
        atual = atual->proximo;
        posicao++;
    }
    printf("====================================\n");
}

void liberar_fila(Jogador* cabeca) {
    Jogador* atual = cabeca;
    while (atual != NULL) {
        Jogador* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

int main() {
    Jogador* fila = NULL;
    int opcao;

    do {
        printf("\n[ SISTEMA DE ARENA ]\n");
        printf("1 - Adicionar jogador no início da fila (Prioridade)\n");
        printf("2 - Adicionar jogador no fim da fila (Padrão)\n");
        printf("3 - Mostrar fila\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_inicio(&fila);
                break;
            case 2:
                adicionar_fim(&fila);
                break;
            case 3:
                mostrar_fila(fila);
                break;
            case 4:
                printf("\nEncerrando o servidor e liberando a memória...\n");
                liberar_fila(fila);
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}