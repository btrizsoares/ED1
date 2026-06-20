#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mercenario {
    int id;
    char nome[100];
    struct Mercenario* prox;
} Mercenario;

void contratar_mercenario(Mercenario** head);
void exibir_companhia(Mercenario* head);
void demitir_todos_mercenarios(Mercenario** head);

int main() {
    Mercenario* head = NULL; 
    int opcao;

    do {
        printf("\n=== Companhia de Mercenarios ===\n");
        printf("1. Contratar mercenario\n");
        printf("2. Exibir companhia\n");
        printf("3. Declarar falencia (Demitir todos)\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n'); 
            continue;
        }
        getchar();

        switch (opcao) {
            case 1:
                contratar_mercenario(&head);
                break;
            case 2:
                exibir_companhia(head);
                break;
            case 3:
                demitir_todos_mercenarios(&head);
                if (head == NULL) {
                    printf(">> Confirmacao do sistema: O registro de mercenarios esta completamente vazio.\n");
                }
                break;
            case 4:
                printf("Encerrando o jogo. Garantindo que ninguem ficou para tras...\n");
                demitir_todos_mercenarios(&head);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
void contratar_mercenario(Mercenario** head) {
    Mercenario* novo = (Mercenario*)malloc(sizeof(Mercenario));
    if (novo == NULL) {
        printf(">> Erro: Falta de memoria no sistema (Memory Allocation Failed)!\n");
        return;
    }

    printf("Digite o ID do mercenario: ");
    scanf("%d", &novo->id);
    getchar(); 

    printf("Digite o nome do mercenario: ");
    fgets(novo->nome, sizeof(novo->nome), stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0'; 
    
    novo->prox = NULL;

    if (*head == NULL) {
        *head = novo;
    } else {
        Mercenario* atual = *head;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    printf(">> Mercenario '%s' (ID %d) assinou o contrato!\n", novo->nome, novo->id);
}

void exibir_companhia(Mercenario* head) {
    printf("\n--- Formacao da Companhia ---\n");
    if (head == NULL) {
        printf("A companhia esta vazia. Nao ha ninguem sob o seu comando.\n");
    } else {
        Mercenario* atual = head;
        while (atual != NULL) {
            printf("[ID: %d | Nome: %s]\n", atual->id, atual->nome);
            atual = atual->prox;
        }
    }
    printf("-----------------------------\n");
}
void demitir_todos_mercenarios(Mercenario** head) {
    if (*head == NULL) {
        printf(">> Falencia declarada, mas nao havia mercenarios para demitir.\n");
        return;
    }

    Mercenario* atual = *head;
    Mercenario* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox; 
        free(atual);           
        atual = proximo;      
    }

    *head = NULL; 
    
    printf(">> FALENCIA DECLARADA! Todos os mercenarios foram demitidos e a memoria foi liberada.\n");
}