#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} Heroi;

typedef struct No {
    Heroi dado;
    struct No* proximo;
} No;

void limpar_buffer();
void adicionar_fim(No** cabeca);
void inserir_antes(No** cabeca);
void mostrar_formacao(No* cabeca);
void liberar_lista(No** cabeca);


int main() {
    No* formacao = NULL;
    int opcao = 0;

    do {
        printf("\n===================================\n");
        printf("       FORMACAO DE BATALHA\n");
        printf("===================================\n");
        printf("1 - Adicionar Heroi no Fim\n");
        printf("2 - Adicionar Guarda-Costas (Inserir Antes do VIP)\n");
        printf("3 - Mostrar Formacao\n");
        printf("4 - Sair\n");
        printf("===================================\n");
        printf("Escolha uma tática: ");
        
        if (scanf("%d", &opcao) != 1) {
            limpar_buffer();
            printf("Entrada invalida. Tente novamente.\n");
            continue;
        }
        limpar_buffer();

        switch (opcao) {
            case 1:
                adicionar_fim(&formacao);
                break;
            case 2:
                inserir_antes(&formacao);
                break;
            case 3:
                mostrar_formacao(formacao);
                break;
            case 4:
                printf("\nDesfazendo a formacao e liberando memoria...\n");
                liberar_lista(&formacao);
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
void adicionar_fim(No** cabeca) {
    No* novo_no = NULL;
    No* atual = NULL;

    novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        return;
    }

    printf("\nDigite o ID do Heroi: ");
    scanf("%d", &novo_no->dado.id);
    limpar_buffer();

    printf("Digite o nome do Heroi: ");
    fgets(novo_no->dado.nome, sizeof(novo_no->dado.nome), stdin);
    novo_no->dado.nome[strcspn(novo_no->dado.nome, "\n")] = 0;
    
    novo_no->proximo = NULL;

    if (*cabeca == NULL) {
        *cabeca = novo_no;
    } else {
        atual = *cabeca;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo_no;
    }
    printf("Heroi posicionado na retaguarda com sucesso!\n");
}

void inserir_antes(No** cabeca) {
    No* novo_no = NULL;
    No* atual = NULL;
    No* anterior = NULL;
    int id_vip = 0;

    novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        return;
    }

    printf("\n[Guarda-Costas] Digite o ID: ");
    scanf("%d", &novo_no->dado.id);
    limpar_buffer();

    printf("[Guarda-Costas] Digite o nome: ");
    fgets(novo_no->dado.nome, sizeof(novo_no->dado.nome), stdin);
    novo_no->dado.nome[strcspn(novo_no->dado.nome, "\n")] = 0;

    printf("Digite o ID do VIP que recebera protecao: ");
    scanf("%d", &id_vip);
    limpar_buffer();

    if (*cabeca == NULL) {
        printf("\nErro: A formacao esta vazia. Nao ha VIP para proteger.\n");
        free(novo_no);
        return;
    }
    if ((*cabeca)->dado.id == id_vip) {
        novo_no->proximo = *cabeca;
        *cabeca = novo_no;
        printf("\nGuarda-Costas '%s' posicionado na linha de frente para proteger o VIP %d!\n", novo_no->dado.nome, id_vip);
        return;
    }

    atual = *cabeca;
    while (atual != NULL && atual->dado.id != id_vip) {
        anterior = atual;  
        atual = atual->proximo; 
    }

    if (atual == NULL) {
        printf("\nErro: VIP com ID %d nao encontrado na formacao.\n", id_vip);
        free(novo_no);
    } else {
        anterior->proximo = novo_no;
        novo_no->proximo = atual;
        printf("\nGuarda-Costas '%s' posicionado com sucesso antes do VIP %d!\n", novo_no->dado.nome, id_vip);
    }
}
void mostrar_formacao(No* cabeca) {
    No* atual = cabeca;
    int posicao = 1;

    if (cabeca == NULL) {
        printf("\nA formacao de batalha esta vazia.\n");
        return;
    }

    printf("\n--- Ordem de Batalha (Frente para Tras) ---\n");
    while (atual != NULL) {
        printf("%d. [ID: %d] %s\n", posicao, atual->dado.id, atual->dado.nome);
        atual = atual->proximo;
        posicao++;
    }
    printf("-------------------------------------------\n");
}
void liberar_lista(No** cabeca) {
    No* atual = *cabeca;
    No* proximo_no = NULL;

    while (atual != NULL) {
        proximo_no = atual->proximo;
        free(atual);
        atual = proximo_no;
    }
    *cabeca = NULL;
}