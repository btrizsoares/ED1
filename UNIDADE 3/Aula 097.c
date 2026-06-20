#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Membro {
    int id;
    char nome[50];
    struct Membro* prox;
} Membro;

typedef struct {
    int id;
    char nome[50];
} DadosMembro;
Membro* adicionar_membro(Membro* lista, int id, char* nome) {
    Membro* novo = (Membro*)malloc(sizeof(Membro));
    if (novo == NULL) {
        printf("Erro: Servidor sem memoria!\n");
        return lista;
    }
    
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if (lista == NULL) {
        return novo;
    }

    Membro* atual = lista;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
    return lista;
}
void listar_membros(Membro* lista) {
    if (lista == NULL) {
        printf("\nA guilda esta vazia no momento.\n");
        return;
    }

    printf("\n--- Membros Ativos da Guilda ---\n");
    Membro* atual = lista;
    while (atual != NULL) {
        printf("ID: %d | Nome: %s\n", atual->id, atual->nome);
        atual = atual->prox;
    }
    printf("--------------------------------\n");
}
void salvar_guild_arquivo(Membro* lista) {
    FILE* arquivo = fopen("guild_roster.bin", "wb");
    if (arquivo == NULL) {
        printf("\n[ERRO CRITICO] Falha ao acessar o disco do servidor!\n");
        return;
    }

    Membro* atual = lista;
    int contador = 0;

    while (atual != NULL) {
        DadosMembro dados_puros;
        dados_puros.id = atual->id;
        strcpy(dados_puros.nome, atual->nome);
        fwrite(&dados_puros, sizeof(DadosMembro), 1, arquivo);
        
        contador++;
        atual = atual->prox;
    }
    fclose(arquivo);
    printf("\n[SISTEMA] Backup concluido! %d membro(s) salvo(s) em 'guild_roster.bin'.\n", contador);
}
void desligar_servidor(Membro* lista) {
    Membro* atual = lista;
    while (atual != NULL) {
        Membro* temp = atual;
        atual = atual->prox;
        free(temp);
    }
}
int main() {
    Membro* roster = NULL;
    int opcao, id;
    char nome[50];

    printf("=== CONSOLE DO SERVIDOR MMORPG ===\n");

    do {
        printf("\n1. Adicionar Membro a Guilda\n");
        printf("2. Listar Membros\n");
        printf("3. Salvar Registro (Backup Binario)\n");
        printf("4. Desligar Servidor (Sair)\n");
        printf("Comando: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                printf("ID do Jogador: ");
                scanf("%d", &id);
                getchar();
                printf("Nome do Jogador: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;
                roster = adicionar_membro(roster, id, nome);
                printf(">> Jogador %s adicionado ao roster.\n", nome);
                break;
            case 2:
                listar_membros(roster);
                break;
            case 3:
                salvar_guild_arquivo(roster);
                break;
            case 4:
                printf("\nDesligando o servidor para manutencao...\n");
                break;
            default:
                printf("\nComando invalido.\n");
        }
    } while (opcao != 4);

    desligar_servidor(roster);
    return 0;
}