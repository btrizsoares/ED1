#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} Membro;

typedef struct No {
    Membro membro;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

void inserir_fim(Lista *lista, Membro m);
void mostrar_lista(Lista lista);
No* pesquisar(Lista lista, int id);
void alterar_nome(Lista *lista, int id, char novo_nome[]);
void liberar_lista(Lista *lista);

int main() {
    Lista guilda;
    guilda.inicio = NULL;
    int op, id_ref;
    Membro m;
    char novo_nome[100];

    do {
        printf("\n=== Registro Oficial da Guilda ===\n");
        printf("1. Adicionar novo membro\n");
        printf("2. Mostrar registro atual\n");
        printf("3. Alterar nome de um membro\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &op) != 1) {
            while (getchar() != '\n'); 
            continue;
        }
        getchar(); 

        switch(op) {
            case 1:
                printf("\nDigite o ID do membro: ");
                scanf("%d", &m.id);
                getchar(); 
                
                printf("Digite o nome do membro: ");
                fgets(m.nome, 100, stdin);
                m.nome[strcspn(m.nome, "\n")] = '\0';
                
                inserir_fim(&guilda, m);
                break;
                
            case 2:
                mostrar_lista(guilda);
                break;
                
            case 3:
                printf("\nInforme o ID do membro que tera o nome alterado: ");
                scanf("%d", &id_ref);
                getchar(); 
                
                printf("Digite o novo nome: ");
                fgets(novo_nome, 100, stdin);
                novo_nome[strcspn(novo_nome, "\n")] = '\0';
                
                alterar_nome(&guilda, id_ref, novo_nome);
                break;
                
            case 4:
                printf("\nFechando o registro da guilda...\n");
                liberar_lista(&guilda);
                break;
                
            default:
                printf("\nOpcao invalida!\n");
        }
    } while(op != 4);

    return 0;
}

void inserir_fim(Lista *lista, Membro m) {
    No *novo = (No*) malloc(sizeof(No));
    if (!novo) {
        printf(">> Erro de alocacao de memoria!\n");
        return;
    }
    novo->membro = m;
    novo->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No *atual = lista->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    printf(">> Membro '%s' recrutado com sucesso!\n", m.nome);
}

void mostrar_lista(Lista lista) {
    printf("\n--- Membros Ativos da Guilda ---\n");
    if (lista.inicio == NULL) {
        printf("A guilda nao possui membros no momento.\n");
        return;
    }
    No *atual = lista.inicio;
    while (atual != NULL) {
        printf("ID: %d | Nome: %s\n", atual->membro.id, atual->membro.nome);
        atual = atual->prox;
    }
    printf("--------------------------------\n");
}

No* pesquisar(Lista lista, int id) {
    No *atual = lista.inicio;
    while (atual != NULL) {
        if (atual->membro.id == id) {
            return atual; 
        }
        atual = atual->prox;
    }
    return NULL; 
}

void alterar_nome(Lista *lista, int id, char novo_nome[]) {
    No *membro_encontrado = pesquisar(*lista, id);

    if (membro_encontrado != NULL) {
        strcpy(membro_encontrado->membro.nome, novo_nome);
        printf(">> Sucesso: Nome atualizado para '%s'.\n", membro_encontrado->membro.nome);
    } else {
        printf(">> Erro: Membro com ID %d nao foi encontrado no registro.\n", id);
    }
}

void liberar_lista(Lista *lista) {
    No *atual = lista->inicio;
    No *temp;
    while (atual != NULL) {
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lista->inicio = NULL;
}