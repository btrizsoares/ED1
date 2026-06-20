#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int custo_mana;
} Feitico;
typedef struct NoPilha {
    Feitico feitico;
    struct NoPilha* proximo;
} NoPilha;
typedef struct {
    NoPilha* topo;
} Pilha;
void inicializar_pilha(Pilha* p) {
    p->topo = NULL;
}
void empilhar(Pilha* p, const char* nome, int custo_mana) {
    NoPilha* novo_no = (NoPilha*)malloc(sizeof(NoPilha));
    if (novo_no == NULL) {
        printf("Erro: Memória insuficiente para alocar novo comando.\n");
        return;
    }

    strncpy(novo_no->feitico.nome, nome, sizeof(novo_no->feitico.nome) - 1);
    novo_no->feitico.nome[sizeof(novo_no->feitico.nome) - 1] = '\0'; 
    novo_no->feitico.custo_mana = custo_mana;
    novo_no->proximo = p->topo;
    p->topo = novo_no;

    printf("-> Comando '%s' (Mana: %d) adicionado ao topo da pilha!\n", nome, custo_mana);
}

void liberar_pilha(Pilha* p) {
    NoPilha* atual = p->topo;
    NoPilha* proximo_no;

    while (atual != NULL) {
        proximo_no = atual->proximo;
        free(atual);
        atual = proximo_no;
    }
    p->topo = NULL;
}

int main() {
    Pilha comandos_arcanista;
    inicializar_pilha(&comandos_arcanista);
    
    int opcao;
    char nome_feitico[50];
    int custo;

    printf("=== Sistema de Batalha: Arcanista ===\n");

    do {
        printf("\n--- Menu de Comandos ---\n");
        printf("1: Adicionar um novo feitico a pilha de comandos\n");
        printf("2: Finalizar sequencia e sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Digite um numero.\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch(opcao) {
            case 1:
                printf("\nDigite o nome do feitico (sem espacos): ");
                scanf("%49s", nome_feitico); 
                printf("Digite o custo de mana: ");
                scanf("%d", &custo);
                empilhar(&comandos_arcanista, nome_feitico, custo);
                break;
            case 2:
                printf("\nSequencia de comandos finalizada. O Arcanista esta aguardando...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 2);

    liberar_pilha(&comandos_arcanista);
    
    return 0;
}