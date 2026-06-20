#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nickname[50];
} Jogador;
typedef struct No {
    Jogador dado;
    struct No *prox;
} No;
typedef struct {
    No *inicio;
    No *fim;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void enfileirar(Fila *f, Jogador j) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: Memoria insuficiente!\n");
        return;
    }
    novo->dado = j;
    novo->prox = NULL;
    
    if (f->fim != NULL) {
        f->fim->prox = novo;
    }
    f->fim = novo;
    
    if (f->inicio == NULL) {
        f->inicio = novo;
    }
}

Jogador desenfileirar(Fila *f) {
    Jogador jogadorRemovido;
    jogadorRemovido.id = -1; 
    strcpy(jogadorRemovido.nickname, "");

    if (f->inicio == NULL) {
        return jogadorRemovido; 
    }

    No *temp = f->inicio;
    jogadorRemovido = temp->dado;
    
    f->inicio = f->inicio->prox;
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    free(temp); 
    return jogadorRemovido;
}

Jogador verInicio(Fila *f) {
    Jogador jogadorVazio;
    jogadorVazio.id = -1;
    strcpy(jogadorVazio.nickname, ""); 

    if (f == NULL || f->inicio == NULL) {
        return jogadorVazio;
    }

    return f->inicio->dado;
}
void salvarFila(Fila *f, const char *nomeArquivo) {
    if (f == NULL || f->inicio == NULL) {
        printf("\n>>> Aviso: A fila esta vazia. Nenhum arquivo foi gerado. <<<\n");
        return;
    }

    FILE *arquivo = fopen(nomeArquivo, "wb");
    
    if (arquivo == NULL) {
        printf("\n[ERRO CRITICO] Nao foi possivel criar ou abrir o arquivo '%s'!\n", nomeArquivo);
        return;
    }

    No *atual = f->inicio;
    int jogadoresSalvos = 0;

    while (atual != NULL) {
        fwrite(&(atual->dado), sizeof(Jogador), 1, arquivo);
        atual = atual->prox;
        jogadoresSalvos++;
    }

    fclose(arquivo);
    printf("\n>>> BACKUP CONCLUIDO: %d jogador(es) foram salvos em '%s'! <<<\n", jogadoresSalvos, nomeArquivo);
}

void carregarFila(Fila *f, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf(">>> Nenhum arquivo de backup anterior encontrado. Iniciando com fila vazia. <<<\n");
        return;
    }

    Jogador j;
    int jogadoresCarregados = 0;
    while (fread(&j, sizeof(Jogador), 1, arquivo) == 1) {
        enfileirar(f, j);
        jogadoresCarregados++;
    }

    fclose(arquivo);
    printf(">>> SISTEMA RESTAURADO: %d jogador(es) carregado(s) do backup '%s'! <<<\n", jogadoresCarregados, nomeArquivo);
}

int main() {
    Fila lobbyFila;
    inicializarFila(&lobbyFila);
    
    int opcao;
    const char *nomeArquivoBackup = "matchmaking_queue.bin";
    printf("\n--- INICIALIZANDO SERVIDOR DE MATCHMAKING ---\n");
    carregarFila(&lobbyFila, nomeArquivoBackup);

    do {
        printf("\n=============================\n");
        printf("       LOBBY DO MOBA       \n");
        printf("=============================\n");
        printf("1. Entrar na Fila (Enfileirar)\n");
        printf("2. Iniciar Partida (Desenfileirar)\n");
        printf("3. Ver quem e o proximo da Fila\n");
        printf("4. Salvar Fila em Arquivo (Backup)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) { 
            printf("Entrada invalida! Digite um numero.\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch(opcao) {
            case 1: {
                Jogador novo;
                printf("Digite o ID do jogador: ");
                scanf("%d", &novo.id);
                printf("Digite o Nickname: ");
                scanf("%49s", novo.nickname); 
                enfileirar(&lobbyFila, novo);
                printf(">>> Jogador '%s' adicionado a fila!\n", novo.nickname);
                break;
            }
            case 2: {
                Jogador removido = desenfileirar(&lobbyFila);
                if (removido.id != -1) {
                    printf("\n>>> Partida Iniciada! %s (ID: %d) entrou na partida. <<<\n", removido.nickname, removido.id);
                } else {
                    printf("\n>>> Nao ha ninguem na fila para iniciar a partida. <<<\n");
                }
                break;
            }
            case 3: {
                Jogador proximo = verInicio(&lobbyFila);
                if (proximo.id != -1) {
                    printf("\n>>> O proximo jogador a entrar na partida e: %s (ID: %d) <<<\n", proximo.nickname, proximo.id);
                } else {
                    printf("\n>>> A fila esta vazia no momento. <<<\n");
                }
                break;
            }
            case 4:
                salvarFila(&lobbyFila, nomeArquivoBackup);
                break;
            case 0:
                printf("\nEncerrando o lobby e limpando a memoria...\n");
                while (lobbyFila.inicio != NULL) {
                    desenfileirar(&lobbyFila);
                }
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);
    return 0;
}