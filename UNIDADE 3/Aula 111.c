#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nickname[50];
} Jogador;
typedef struct No {
    Jogador dados;
    struct No *prox;
} No;
typedef struct {
    No *inicio;
    No *fim;
} Fila;

void inicializar_fila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int estaVazia(Fila *f) {
    if (f->inicio == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void inserir(Fila *f, Jogador j) {
    No *novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    
    novoNo->dados = j;
    novoNo->prox = NULL;

    if (estaVazia(f)) { 
        f->inicio = novoNo;
        f->fim = novoNo;
    } else {
        f->fim->prox = novoNo;
        f->fim = novoNo;
    }
    
    printf("\n[Sistema] Jogador '%s' (ID: %d) entrou na fila.\n", j.nickname, j.id);
}

Jogador remover(Fila *f) {
    if (estaVazia(f)) {
        printf("\nAviso: A fila de matchmaking esta vazia. Nao ha ninguem para iniciar a partida.\n");
        Jogador jogadorInvalido = {-1, ""};
        return jogadorInvalido;
    }

    No *noRemovido = f->inicio;
    Jogador dadosRemovidos = noRemovido->dados;

    f->inicio = f->inicio->prox;

    if (estaVazia(f)) {
        f->fim = NULL;
    }

    free(noRemovido);
    return dadosRemovidos;
}

void mostrar(Fila *f) {
    if (estaVazia(f)) {
        printf("\nA fila de matchmaking esta vazia.\n");
        return;
    }

    No *aux = f->inicio;
    int posicao = 1;

    printf("\n--- Fila de Matchmaking Atual ---\n");
    while (aux != NULL) {
        printf("%dº da fila -> ID: %d | Nick: %s\n", posicao, aux->dados.id, aux->dados.nickname);
        aux = aux->prox;
        posicao++;
    }
    printf("---------------------------------\n");
}

int main() {
    Fila filaMatchmaking;
    inicializar_fila(&filaMatchmaking);
    int opcao;

    do {
        printf("\n=== Servidor de Matchmaking ===\n");
        printf("1. Adicionar Jogador na Fila\n");
        printf("2. Remover Jogador da Fila (Iniciar Partida)\n");
        printf("3. Mostrar Fila\n");
        printf("4. Verificar se a Fila esta Vazia\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Jogador novoJogador;
                
                printf("Digite o ID numerico do jogador: ");
                scanf("%d", &novoJogador.id);
                
                printf("Digite o nickname do jogador: ");
                getchar(); 
                scanf("%49[^\n]", novoJogador.nickname);
                
                inserir(&filaMatchmaking, novoJogador);
                break;
            }
            case 2: {
                Jogador jogadorRemovido = remover(&filaMatchmaking);
                
                if (jogadorRemovido.id != -1) {
                    printf("\nO jogador %s (ID: %d) foi removido da fila e entrou em uma partida.\n", 
                           jogadorRemovido.nickname, jogadorRemovido.id);
                }
                break;
            }
            case 3:
                mostrar(&filaMatchmaking);
                break;
            case 4:
                if (estaVazia(&filaMatchmaking) == 1) {
                    printf("\nSIM, a fila esta vazia.\n");
                } else {
                    printf("\nNAO, a fila contem jogadores.\n");
                }
                break;
            case 5:
                printf("\nEncerrando o servidor de matchmaking...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);
    while (!estaVazia(&filaMatchmaking)) {
        remover(&filaMatchmaking);
    }
    return 0;
}