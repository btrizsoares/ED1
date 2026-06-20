#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int poder;
} Feitico;
typedef struct No {
    Feitico dado;
    struct No* prox;
} No;
typedef struct {
    No* topo;
} Pilha;

void empilhar(Pilha *p, Feitico f) {
    No *novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    novoNo->dado = f;
    novoNo->prox = p->topo;
    p->topo = novoNo;
}

void inverter_pilha(Pilha *p) {
    No *anterior = NULL;
    No *atual = p->topo;
    No *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox; 
        atual->prox = anterior; 
        anterior = atual;      
        atual = proximo;        
    }
    p->topo = anterior; 
}

void salvar_pilha_em_arquivo(Pilha *p, const char* nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo para escrita.\n");
        return; 
    }

    No *aux = p->topo;
    while (aux != NULL) {
        fwrite(&(aux->dado), sizeof(Feitico), 1, arquivo);
        aux = aux->prox;
    }

    fclose(arquivo);
    printf("Sucesso: Sequencia de feiticos salva no '%s'!\n", nome_arquivo);
}

void carregar_pilha_de_arquivo(Pilha *p, const char* nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    
    if (arquivo == NULL) {
        printf("Nenhum grimorio encontrado, iniciando com uma pilha vazia.\n");
        return; 
    }

    Feitico f;
    while (fread(&f, sizeof(Feitico), 1, arquivo) == 1) {
        empilhar(p, f);
    }

    fclose(arquivo);
    
    inverter_pilha(p);
    printf("Grimorio carregado com sucesso! A magia esta de volta.\n");
}

int main() {
    Pilha minhaPilha;
    minhaPilha.topo = NULL;
    int opcao;

    printf("--- Despertar do Arcanista ---\n");
    carregar_pilha_de_arquivo(&minhaPilha, "grimorio.bin");

    do {
        printf("\n--- Menu do Arcanista ---\n");
        printf("1. Adicionar Feitico\n");
        printf("5. Salvar Sequencia no Grimorio\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Feitico novo;
                printf("Digite o nome do feitico: ");
                getchar(); 
                scanf("%49[^\n]", novo.nome);
                
                printf("Digite o nivel de poder: ");
                scanf("%d", &novo.poder);
                
                empilhar(&minhaPilha, novo);
                printf("Feitico '%s' preparado!\n", novo.nome);
                break;
            }
            case 5:
                salvar_pilha_em_arquivo(&minhaPilha, "grimorio.bin");
                break;
            case 6:
                printf("Fechando o grimorio e encerrando a sessao...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 6);
    No *atual = minhaPilha.topo;
    No *proximo;
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    return 0;
}