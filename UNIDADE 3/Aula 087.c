#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} Jogador;

typedef struct No {
    Jogador dado;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
} Lista;

void limpar_buffer();
void inicializar_fila(Lista* fila);
void adicionar_fim(Lista* fila);
void iniciar_partida(Lista* fila);
void mostrar_fila(Lista* fila);
void liberar_fila(Lista* fila);

int main() {
    Lista fila_matchmaking;
    int opcao = 0;

    inicializar_fila(&fila_matchmaking);

    do {
        printf("\n===================================\n");
        printf("      SISTEMA DE MATCHMAKING\n");
        printf("===================================\n");
        printf("1 - Adicionar jogador ao fim da fila\n");
        printf("2 - Iniciar partida (Remover o primeiro)\n");
        printf("3 - Mostrar fila de espera\n");
        printf("4 - Sair\n");
        printf("===================================\n");
        printf("Escolha uma acao: ");
        
        if (scanf("%d", &opcao) != 1) {
            limpar_buffer();
            printf("Entrada invalida. Tente novamente.\n");
            continue;
        }
        limpar_buffer();

        switch (opcao) {
            case 1:
                adicionar_fim(&fila_matchmaking);
                break;
            case 2:
                iniciar_partida(&fila_matchmaking);
                break;
            case 3:
                mostrar_fila(&fila_matchmaking);
                break;
            case 4:
                printf("\nEncerrando o servidor e liberando a memoria...\n");
                liberar_fila(&fila_matchmaking);
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void inicializar_fila(Lista* fila) {
    fila->inicio = NULL;
}
void adicionar_fim(Lista* fila) {
    No* novo_no = NULL;
    No* atual = NULL;

    novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        return;
    }

    printf("\nDigite o ID do Jogador: ");
    scanf("%d", &novo_no->dado.id);
    limpar_buffer();

    printf("Digite o nome do Jogador: ");
    fgets(novo_no->dado.nome, sizeof(novo_no->dado.nome), stdin);
    novo_no->dado.nome[strcspn(novo_no->dado.nome, "\n")] = 0;
    
    novo_no->proximo = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo_no;
    } else {
        atual = fila->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo_no;
    }
    printf("Jogador '%s' entrou na fila de matchmaking!\n", novo_no->dado.nome);
}
void iniciar_partida(Lista* fila) {
    No* jogador_removido = NULL;

    if (fila->inicio == NULL) {
        printf("\nNao ha jogadores na fila.\n");
        return;
    }

    jogador_removido = fila->inicio;

    fila->inicio = jogador_removido->proximo;

    printf("\nPartida iniciada para o jogador: [ID: %d] %s\n", jogador_removido->dado.id, jogador_removido->dado.nome);

    free(jogador_removido);
}

void mostrar_fila(Lista* fila) {
    No* atual = fila->inicio;
    int posicao = 1;

    if (fila->inicio == NULL) {
        printf("\nA fila de matchmaking esta vazia.\n");
        return;
    }

    printf("\n--- Fila de Espera (FIFO) ---\n");
    while (atual != NULL) {
        printf("%dº lugar -> [ID: %d] %s\n", posicao, atual->dado.id, atual->dado.nome);
        atual = atual->proximo;
        posicao++;
    }
    printf("-----------------------------\n");
}
void liberar_fila(Lista* fila) {
    No* atual = fila->inicio;
    No* proximo_no = NULL;

    while (atual != NULL) {
        proximo_no = atual->proximo;
        free(atual);
        atual = proximo_no;
    }
    fila->inicio = NULL;
}