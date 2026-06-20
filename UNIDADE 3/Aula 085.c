#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} Item;

typedef struct No {
    Item dado;
    struct No* proximo;
} No;


void limpar_buffer();
void inserir_inicio(No** cabeca);
void inserir_fim(No** cabeca);
void inserir_apos_id(No** cabeca);
void mostrar_inventario(No* cabeca);
void liberar_lista(No** cabeca);

int main() {
    No* inventario = NULL;
    int opcao = 0;

    do {
        printf("\n===================================\n");
        printf("      INVENTARIO DE MISSAO\n");
        printf("===================================\n");
        printf("1 - Inserir item no inicio\n");
        printf("2 - Inserir item no fim\n");
        printf("3 - Inserir catalisador apos um fragmento\n");
        printf("4 - Mostrar inventario\n");
        printf("5 - Sair\n");
        printf("===================================\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            limpar_buffer();
            printf("Entrada invalida. Tente novamente.\n");
            continue;
        }
        limpar_buffer();

        switch (opcao) {
            case 1:
                inserir_inicio(&inventario);
                break;
            case 2:
                inserir_fim(&inventario);
                break;
            case 3:
                inserir_apos_id(&inventario);
                break;
            case 4:
                mostrar_inventario(inventario);
                break;
            case 5:
                printf("\nEsvaziando o inventario e liberando memoria...\n");
                liberar_lista(&inventario);
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void inserir_inicio(No** cabeca) {
    No* novo_no = NULL;

    novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        return;
    }

    printf("\nDigite o ID do Item: ");
    scanf("%d", &novo_no->dado.id);
    limpar_buffer();

    printf("Digite o nome do Item: ");
    fgets(novo_no->dado.nome, sizeof(novo_no->dado.nome), stdin);
    novo_no->dado.nome[strcspn(novo_no->dado.nome, "\n")] = 0;

    novo_no->proximo = *cabeca;
    *cabeca = novo_no;
    printf("Item inserido no inicio com sucesso!\n");
}

void inserir_fim(No** cabeca) {
    No* novo_no = NULL;
    No* atual = NULL;

    novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        return;
    }

    printf("\nDigite o ID do Item: ");
    scanf("%d", &novo_no->dado.id);
    limpar_buffer();

    printf("Digite o nome do Item: ");
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
    printf("Item inserido no fim com sucesso!\n");
}

void inserir_apos_id(No** cabeca) {
    No* novo_no = NULL;
    No* atual = NULL;
    int id_referencia;

    novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        return;
    }

    printf("\n[Novo Catalisador] Digite o ID: ");
    scanf("%d", &novo_no->dado.id);
    limpar_buffer();

    printf("[Novo Catalisador] Digite o nome: ");
    fgets(novo_no->dado.nome, sizeof(novo_no->dado.nome), stdin);
    novo_no->dado.nome[strcspn(novo_no->dado.nome, "\n")] = 0;

    printf("Digite o ID do Fragmento apos o qual o catalisador sera inserido: ");
    scanf("%d", &id_referencia);
    limpar_buffer();

    atual = *cabeca;
    while (atual != NULL && atual->dado.id != id_referencia) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("\nErro: Fragmento com ID %d nao encontrado.\n", id_referencia);
        printf("A insercao nao foi possivel. O catalisador foi descartado.\n");
        free(novo_no); 
    } else {
        novo_no->proximo = atual->proximo;
        atual->proximo = novo_no;
        printf("\nCatalisador '%s' inserido com sucesso logo apos o ID %d!\n", novo_no->dado.nome, id_referencia);
    }
}

void mostrar_inventario(No* cabeca) {
    No* atual = cabeca;

    if (cabeca == NULL) {
        printf("\nO inventario esta vazio.\n");
        return;
    }

    printf("\n--- Itens no Inventario ---\n");
    while (atual != NULL) {
        printf("ID: %d | Nome: %s\n", atual->dado.id, atual->dado.nome);
        atual = atual->proximo;
    }
    printf("---------------------------\n");
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