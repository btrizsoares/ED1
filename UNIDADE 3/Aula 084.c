#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char titulo[100];
    char status[50];
} Missao;

typedef struct No {
    Missao missao;
    struct No* proximo;
} No;

void limpar_buffer();
void adicionar_missao(No** cabeca);
void mostrar_missoes(No* cabeca);
No* pesquisar_missao(No* cabeca, int id);
void liberar_lista(No** cabeca);

int main() {
    No* lista_missoes = NULL;
    int opcao, id_busca;
    No* resultado_busca = NULL;

    do {
        printf("\n===================================\n");
        printf("        DIARIO DE MISSOES\n");
        printf("===================================\n");
        printf("1. Adicionar Missao\n");
        printf("2. Mostrar Missoes\n");
        printf("3. Buscar Missao por ID\n");
        printf("4. Sair\n");
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
                adicionar_missao(&lista_missoes);
                break;
            case 2:
                mostrar_missoes(lista_missoes);
                break;
            case 3:
                printf("\nDigite o ID da missao que deseja buscar: ");
                scanf("%d", &id_busca);
                limpar_buffer();
                
                resultado_busca = pesquisar_missao(lista_missoes, id_busca);
                
                if (resultado_busca != NULL) {
                    printf("\n--- Missao Encontrada ---\n");
                    printf("ID: %d\n", resultado_busca->missao.id);
                    printf("Titulo: %s\n", resultado_busca->missao.titulo);
                    printf("Status: %s\n", resultado_busca->missao.status);
                    printf("-------------------------\n");
                } else {
                    printf("\nMissao nao encontrada!\n");
                }
                break;
            case 4:
                printf("\nEncerrando o diario e liberando memoria...\n");
                liberar_lista(&lista_missoes);
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

void adicionar_missao(No** cabeca) {
    No* novo_no = NULL;
    No* atual = NULL;

    novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        return;
    }

    printf("\nDigite o ID da missao: ");
    scanf("%d", &novo_no->missao.id);
    limpar_buffer();

    printf("Digite o titulo da missao: ");
    fgets(novo_no->missao.titulo, sizeof(novo_no->missao.titulo), stdin);
    novo_no->missao.titulo[strcspn(novo_no->missao.titulo, "\n")] = 0; 

    printf("Digite o status da missao (ex: Ativa, Concluida): ");
    fgets(novo_no->missao.status, sizeof(novo_no->missao.status), stdin);
    novo_no->missao.status[strcspn(novo_no->missao.status, "\n")] = 0;

    novo_no->proximo = NULL;

    if (*cabeca == NULL) {
        *cabeca = novo_no;
    } else {
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo_no;
    }
    printf("Missao adicionada com sucesso!\n");
}

void mostrar_missoes(No* cabeca) {
    if (cabeca == NULL) {
        printf("\nO diario de missoes esta vazio.\n");
        return;
    }

    No* atual = cabeca;
    printf("\n--- Lista de Missoes ---\n");
    while (atual != NULL) {
        printf("ID: %d | Titulo: %s | Status: %s\n", 
               atual->missao.id, 
               atual->missao.titulo, 
               atual->missao.status);
        atual = atual->proximo;
    }
    printf("------------------------\n");
}

No* pesquisar_missao(No* cabeca, int id) {
    No* atual = cabeca;

    while (atual != NULL) {
        if (atual->missao.id == id) {
            return atual;
        }
        atual = atual->proximo;
    }
    
    return NULL; 
}

void liberar_lista(No** cabeca) {
    No* atual = *cabeca;
    No* proximo_no;

    while (atual != NULL) {
        proximo_no = atual->proximo;
        free(atual);
        atual = proximo_no;
    }
    *cabeca = NULL;
}