#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Inimigo {
    int id;
    char tipo[50];
    struct Inimigo* proximo;
} Inimigo;

Inimigo* inserir_fim(Inimigo* lista, int id, char* tipo) {
    Inimigo* novo = (Inimigo*)malloc(sizeof(Inimigo));
    if (novo == NULL) {
        printf("Erro de alocacao! Sistema sobrecarregado.\n");
        return lista;
    }
    novo->id = id;
    strcpy(novo->tipo, tipo);
    novo->proximo = NULL;

    if (lista == NULL) {
        return novo; 
    }

    Inimigo* atual = lista;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    return lista;
}

void liberar_onda(Inimigo* lista) {
    Inimigo* atual = lista;
    while (atual != NULL) {
        Inimigo* temp = atual;
        atual = atual->proximo;
        free(temp); 
    }
}

Inimigo* criar_lista(int n) {
    Inimigo* nova_lista = NULL;
    int id;
    char tipo[50];

    printf("\n--- Lendo Dados da Nova Onda ---\n");
    for (int i = 0; i < n; i++) {
        printf("Inimigo [%d/%d]\n", i + 1, n);
        printf("ID do Alvo: ");
        scanf("%d", &id);
        getchar(); 
        
        printf("Tipo do Inimigo (ex: Orc, Goblin, Boss): ");
        fgets(tipo, 50, stdin);
        tipo[strcspn(tipo, "\n")] = 0; 
        nova_lista = inserir_fim(nova_lista, id, tipo);
    }

    return nova_lista; 
}
void listar_onda(Inimigo* lista) {
    if (lista == NULL) {
        printf("\n[RADAR LIMPO] Nenhum alvo detectado na area.\n");
        return;
    }
    
    printf("\n--- Alvos Ativos (Radar) ---\n");
    Inimigo* atual = lista;
    while (atual != NULL) {
        printf("- ID: %d | Tipo: %s\n", atual->id, atual->tipo);
        atual = atual->proximo;
    }
    printf("----------------------------\n");
}

int main() {
    Inimigo* onda_atual = NULL; 
    int opcao, n;

    printf("Iniciando Sistema de Defesa...\n");

    do {
        printf("\n=== TORRE DE COMANDO ===\n");
        printf("1. Iniciar Nova Onda\n");
        printf("2. Verificar Radar (Listar Alvos)\n");
        printf("3. Desativar Defesas (Sair)\n");
        printf("Selecione um comando: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nAlerta! Nova onda se aproximando.\n");
                printf("Quantos inimigos foram detectados? ");
                scanf("%d", &n);
                liberar_onda(onda_atual); 
                onda_atual = criar_lista(n);
                printf("\n>> Defesas preparadas! Nova onda em andamento.\n");
                break;
            case 2:
                listar_onda(onda_atual);
                break;
            case 3:
                printf("\nDesligando geradores. Boa sorte, comandante!\n");
                break;
            default:
                printf("\nComando nao reconhecido. Digite novamente.\n");
        }
    } while (opcao != 3);
    liberar_onda(onda_atual);

    return 0;
}