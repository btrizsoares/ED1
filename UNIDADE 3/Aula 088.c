#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int mat;
    char nome[100];
} Estudante;
typedef struct No {
    Estudante dado;
    struct No *prox;
} No;
typedef struct {
    No *inicio;
} Lista;

void menu() {
    printf("\n======== Gerenciador de Party =========\n");
    printf("1 - Adicionar jogador no inicio da party\n");
    printf("2 - Adicionar jogador no fim da party\n");
    printf("5 - Mostrar membros da party\n");
    printf("7 - Remover primeiro jogador da party\n");
    printf("8 - Remover ultimo jogador da party\n");
    printf("9 - Sair\n");
    printf("=======================================\n");
}

void ler(Estudante *e) {
    printf("Digite a matricula: ");
    scanf("%d", &e->mat);
    printf("Digite o nome: ");
    scanf(" %[^\n]s", e->nome);
}

void inserir_inicio(Lista *plista, Estudante dado) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

void inserir_fim(Lista *plista, Estudante dado) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;
    
    if (plista->inicio == NULL) { 
        plista->inicio = novo;
    } else {
        No *pi;
        for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox);
        pi->prox = novo;
    }
}

void mostrar(Lista lista) {
    if (lista.inicio == NULL) {
        printf("A party esta vazia!\n");
        return;
    }
    No *pi;
    printf("\n--- Membros da Party ---\n");
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        printf("Matricula: %d | Nome: %s\n", pi->dado.mat, pi->dado.nome);
    }
    printf("------------------------\n");
}

void deletar_inicio(Lista *plista) {
    if (plista->inicio == NULL) {
        printf("A lista ja esta vazia!\n");
    } else {
        No *pi = plista->inicio;
        plista->inicio = pi->prox;
        free(pi);
        printf("Primeiro jogador removido com sucesso!\n");
    }
}

void deletar_fim(Lista *plista) {
    No *atual = NULL;
    No *anterior = NULL;
    if (plista->inicio == NULL) {
        printf("A party esta vazia! Nao ha jogadores para remover.\n");
        return;
    }
    if (plista->inicio->prox == NULL) {
        free(plista->inicio);
        plista->inicio = NULL; 
        printf("Ultimo jogador removido. A party agora esta vazia!\n");
        return;
    }

    atual = plista->inicio;

    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }
    anterior->prox = NULL;
    
    free(atual);
    printf("Ultimo jogador removido da party com sucesso!\n");
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op;

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1: {
                Estudante e;
                ler(&e);
                inserir_inicio(&lista, e);
                break;
            }
            case 2: {
                Estudante e;
                ler(&e);
                inserir_fim(&lista, e);
                break;
            }
            case 5:
                mostrar(lista);
                break;
            case 7:
                deletar_inicio(&lista);
                break;
            case 8:
                deletar_fim(&lista);
                break;
            case 9:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (op != 9);

    return 0;
}