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
int vazia(Pilha *p) {
    return p->topo == NULL;
}
void empilhar(Pilha* p, const char* nome, int custo_mana) {
    NoPilha* novo_no = (NoPilha*)malloc(sizeof(NoPilha));
    if (novo_no == NULL) {
        printf("Erro: Memoria insuficiente para alocar novo comando.\n");
        return;
    }

    strncpy(novo_no->feitico.nome, nome, sizeof(novo_no->feitico.nome) - 1);
    novo_no->feitico.nome[sizeof(novo_no->feitico.nome) - 1] = '\0';
    novo_no->feitico.custo_mana = custo_mana;

    novo_no->proximo = p->topo;
    p->topo = novo_no;

    printf("-> Comando '%s' (Mana: %d) adicionado ao topo da pilha!\n", nome, custo_mana);
}

Feitico pop(Pilha *p) {
    if (vazia(p)) {
        printf("\n[ERRO] A pilha de comandos esta vazia!\n");
        Feitico erro_feitico;
        strcpy(erro_feitico.nome, "Nenhum");
        erro_feitico.custo_mana = -1; 
        return erro_feitico;
    }

    NoPilha* no_removido = p->topo;
    Feitico feitico_retorno = no_removido->feitico;
    p->topo = p->topo->proximo;
    free(no_removido);

    return feitico_retorno;
}

Feitico top(Pilha *p) {
    if (vazia(p)) {
        printf("\n[ERRO] A pilha de comandos esta vazia! Nao ha feiticos para consultar.\n");
        Feitico erro_feitico;
        strcpy(erro_feitico.nome, "Nenhum");
        erro_feitico.custo_mana = -1; 
        return erro_feitico;
    }

    return p->topo->feitico;
}

void mostrar_pilha(Pilha *p) {
    if (vazia(p)) {
        printf("\nA pilha de comandos esta vazia.\n");
        return;
    }

    printf("\n=== Fila de Execucao do Arcanista ===\n");
    printf("(O topo sera o primeiro a ser executado)\n\n");
    
    NoPilha* atual = p->topo;
    int ordem = 1;

    while (atual != NULL) {
        printf("%dº a executar -> Feitico: %-15s | Custo de Mana: %d\n", 
               ordem, atual->feitico.nome, atual->feitico.custo_mana);
        atual = atual->proximo;
        ordem++;
    }
    printf("=====================================\n");
}

void liberar_pilha(Pilha* p) {
    while (!vazia(p)) {
        pop(p);
    }
}

int main() {
    Pilha comandos_arcanista;
    inicializar_pilha(&comandos_arcanista);
    
    int opcao;
    char nome_feitico[50];
    int custo;
    Feitico lancado;
    Feitico consulta; 

    printf("=== Sistema de Batalha: Arcanista ===\n");

    do {
        printf("\n--- Menu de Comandos ---\n");
        printf("1: Adicionar um novo feitico (Push)\n");
        printf("2: Lancar Proximo Feitico (Pop)\n");
        printf("3: Mostrar Pilha de Comandos\n");
        printf("4: Consultar Proximo Feitico (Top)\n"); 
        printf("5: Verificar Status da Pilha\n");
        printf("6: Finalizar sequencia e sair\n");
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
                lancado = pop(&comandos_arcanista);
                if (lancado.custo_mana != -1) {
                    printf("\n[ACAO] Feitico '%s' lancado com sucesso! (Mana gasta: %d)\n", 
                           lancado.nome, lancado.custo_mana);
                }
                break;
            case 3:
                mostrar_pilha(&comandos_arcanista);
                break;

            case 4:
                consulta = top(&comandos_arcanista);
                if (consulta.custo_mana != -1) {
                    printf("\n[CONSULTA] O proximo feitico pronto para lancamento e '%s' (Custo: %d de Mana).\n", 
                           consulta.nome, consulta.custo_mana);
                }
                break;
            case 5:
                if (vazia(&comandos_arcanista)) {
                    printf("\n[STATUS] A pilha de comandos esta vazia.\n");
                } else {
                    printf("\n[STATUS] A pilha de comandos possui feiticos pendentes.\n");
                }
                break;
            case 6:
                printf("\nEncerrando o simulador. Limpando comandos restantes...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 6);

    liberar_pilha(&comandos_arcanista);
    
    return 0;
}