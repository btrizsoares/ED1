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
void inserir(Fila *f, Jogador j) {
    No *novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    
    novoNo->dados = j;
    novoNo->prox = NULL;

    if (f->inicio == NULL) {
        f->inicio = novoNo;
        f->fim = novoNo;
    } else {
        f->fim->prox = novoNo;
        f->fim = novoNo;
    }
    
    printf("\n[Sistema] Jogador '%s' (ID: %d) entrou na fila.\n", j.nickname, j.id);
}

void mostrar(Fila *f) {
    if (f->inicio == NULL) {
        printf("\nA fila de matchmaking esta vazia.\n");
        return 1;
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
        printf("2. Mostrar Fila\n");
        printf("3. Sair\n");
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
            case 2:
                mostrar(&filaMatchmaking);
                break;
            case 3:
                printf("\nEncerrando o servidor de matchmaking...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 3);

    No *atual = filaMatchmaking.inicio;
    No *proximo;
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    return 0;
}