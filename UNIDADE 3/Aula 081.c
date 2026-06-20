#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} Movimento;

typedef struct no {
    Movimento dados;
    struct no* proximo;
} No;

typedef struct {
    No* inicio;
} Lista;

void inicializar_lista(Lista* lista) {
    lista->inicio = NULL;
}

void inserir_movimento(Lista* lista) {
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro fatal: Falha na alocação de memória.\n");
        return;
    }

    printf("\n--- Registro de Movimento ---\n");
    printf("Digite o ID do golpe: ");
    scanf("%d", &novo_no->dados.id);
    
    printf("Digite o Nome do golpe: ");
    scanf(" %49[^\n]", novo_no->dados.nome); 

    novo_no->proximo = lista->inicio;
    lista->inicio = novo_no;

    printf(">> Movimento '%s' registrado no log de combos!\n", novo_no->dados.nome);
}

void liberar_lista(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    lista->inicio = NULL;
}

int main() {
    Lista log_combo;
    inicializar_lista(&log_combo);
    int opcao;

    printf("=========================================\n");
    printf("       SISTEMA DE LOG DE COMBOS\n");
    printf("=========================================\n");

    do {
        printf("\n[ MENU ]\n");
        printf("1: Inserir novo movimento no início do combo\n");
        printf("2: Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_movimento(&log_combo);
                break;
            case 2:
                printf("\nEncerrando o log e liberando a memória. Fim de jogo!\n");
                liberar_lista(&log_combo);
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 2);

    return 0;
}