#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Heroi;
typedef struct no {
    Heroi heroi;
    struct no *prox;
} No;
typedef struct {
    No *inicio;
} Lista;

void inicializar_lista(Lista *lista);
void adicionar_heroi(Lista *lista, Heroi h);
void dispensar_heroi(Lista *lista, int id);
void mostrar_guilda(Lista *lista);
void menu();

int main() {
    Lista guilda;
    inicializar_lista(&guilda);
    int opcao, id_heroi;
    Heroi novo_heroi;

    do {
        menu();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nDigite o ID do novo heroi: ");
                scanf("%d", &novo_heroi.id);
                printf("Digite o nome do novo heroi (sem espacos): ");
                scanf("%49s", novo_heroi.nome);
                adicionar_heroi(&guilda, novo_heroi);
                break;
            case 2:
                mostrar_guilda(&guilda);
                break;
            case 3:
                printf("\nDigite o ID do heroi a ser dispensado: ");
                scanf("%d", &id_heroi);
                dispensar_heroi(&guilda, id_heroi);
                printf("\n--- Roster da Guilda Atualizado ---\n");
                mostrar_guilda(&guilda);
                break;
            case 4:
                printf("\nSaindo do gerenciador da guilda...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while(opcao != 4);

    while(guilda.inicio != NULL) {
        No *temp = guilda.inicio;
        guilda.inicio = guilda.inicio->prox;
        free(temp);
    }

    return 0;
}
void inicializar_lista(Lista *lista) {
    lista->inicio = NULL;
}
void adicionar_heroi(Lista *lista, Heroi h) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo) {
        novo->heroi = h;
        novo->prox = NULL;

        if (lista->inicio == NULL) {
            lista->inicio = novo;
        } else {
            No *aux = lista->inicio;
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
        printf("Heroi '%s' recrutado com sucesso!\n", h.nome);
    } else {
        printf("Erro de alocacao de memoria!\n");
    }
}
void mostrar_guilda(Lista *lista) {
    printf("\n--- Roster da Guilda ---\n");
    if (lista->inicio == NULL) {
        printf("A guilda esta vazia.\n");
    } else {
        No *aux = lista->inicio;
        while (aux != NULL) {
            printf("ID: %d, Nome: %s\n", aux->heroi.id, aux->heroi.nome);
            aux = aux->prox;
        }
    }
    printf("------------------------\n");
}
void menu() {
    printf("\nGerenciador de Guilda:\n");
    printf("1. Adicionar Heroi\n");
    printf("2. Mostrar Guilda\n");
    printf("3. Dispensar Heroi por ID\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}
void dispensar_heroi(Lista *lista, int id) {
    No *atual = NULL;
    No *anterior = NULL;
    if (lista->inicio == NULL) {
        printf("\nA guilda esta vazia! Nao ha herois para dispensar.\n");
        return;
    }
    atual = lista->inicio;
    if (atual != NULL && atual->heroi.id == id) {
        lista->inicio = atual->prox; 
        free(atual); 
        printf("\nHeroi com ID %d dispensado com sucesso!\n", id);
        return;
    }
    while (atual != NULL && atual->heroi.id != id) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf("\nErro: Heroi com ID %d nao encontrado nos registros da guilda.\n", id);
        return;
    }
    anterior->prox = atual->prox;
    free(atual);
    printf("\nHeroi com ID %d dispensado com sucesso!\n", id);
}