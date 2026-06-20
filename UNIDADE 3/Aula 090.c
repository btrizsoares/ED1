#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ward {
    int id;
    char nome[100];
    struct Ward* prox;
} Ward;

void adicionar_ward(Ward** head);
void deletar_apos(Ward** head);
void mostrar_wards(Ward* head);
void liberar_lista(Ward** head);

int main() {
    Ward* head = NULL; 
    int opcao;

    do {
        printf("\n=== Menu de Gerenciamento Arcana ===\n");
        printf("1. Adicionar Ward (ao final da sequencia)\n");
        printf("2. Lancar 'Ward Shatter' (deletar apos um ID)\n");
        printf("3. Mostrar Wards Ativos\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            printf("Entrada invalida.\n");
            continue;
        }

        switch (opcao) {
            case 1:
                adicionar_ward(&head);
                break;
            case 2:
                deletar_apos(&head);
                break;
            case 3:
                mostrar_wards(head);
                break;
            case 4:
                printf("Saindo do sistema arcano. Limpando a memoria...\n");
                liberar_lista(&head);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

void adicionar_ward(Ward** head) {
    Ward* novo_ward = (Ward*)malloc(sizeof(Ward));
    if (novo_ward == NULL) {
        printf("Erro de alocacao de memoria para o novo Ward!\n");
        return;
    }

    printf("Digite o ID do novo Ward: ");
    scanf("%d", &novo_ward->id);
    getchar(); 

    printf("Digite o nome do Ward: ");
    fgets(novo_ward->nome, sizeof(novo_ward->nome), stdin);
    novo_ward->nome[strcspn(novo_ward->nome, "\n")] = '\0';
    
    novo_ward->prox = NULL;

    if (*head == NULL) {
        *head = novo_ward;
    } else {
        Ward* atual = *head;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo_ward;
    }
    printf(">> Ward '%s' (ID: %d) conjurado com sucesso!\n", novo_ward->nome, novo_ward->id);
}
void deletar_apos(Ward** head) {
    if (*head == NULL) {
        printf(">> Falha no feitico: A lista de wards esta vazia. Nao ha defesas ativas.\n");
        return;
    }

    int id_ref;
    printf("Digite o ID do Ward alvo para lancar 'Ward Shatter': ");
    scanf("%d", &id_ref);

    Ward* atual = *head;

    while (atual != NULL && atual->id != id_ref) {
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf(">> Falha no feitico: Ward alvo (ID %d) nao encontrado na sequencia.\n", id_ref);
    } else if (atual->prox == NULL) {
        printf(">> Falha no feitico: O Ward (ID %d) e o ultimo da sequencia. Nao ha barreira apos ele para ser destruida.\n", id_ref);
    } else {
        Ward* ward_destruido = atual->prox;
        atual->prox = ward_destruido->prox;
        
        printf(">> SUCESSO! O feitico 'Ward Shatter' atingiu a sequencia. O Ward '%s' (ID %d) foi destruido.\n", 
               ward_destruido->nome, ward_destruido->id);
        
        free(ward_destruido); 
    }
}
void mostrar_wards(Ward* head) {
    if (head == NULL) {
        printf(">> Nenhum Ward ativo no momento.\n");
        return;
    }

    printf("\n--- Sequencia de Defesa Atual ---\n");
    Ward* atual = head;
    while (atual != NULL) {
        printf("[ID: %d | %s]", atual->id, atual->nome);
        if (atual->prox != NULL) {
            printf(" -> ");
        }
        atual = atual->prox;
    }
    printf("\n---------------------------------\n");
}
void liberar_lista(Ward** head) {
    Ward* atual = *head;
    Ward* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    *head = NULL;
}