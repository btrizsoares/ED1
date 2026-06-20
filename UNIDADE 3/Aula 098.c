#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Membro {
    int id;
    char nome[100];
    int nivel;
} Membro;
typedef struct No {
    Membro dados;
    struct No* prox;
} No;
typedef struct Lista {
    No* inicio;
} Lista;
Lista criar_lista_vazia() {
    Lista l;
    l.inicio = NULL;
    return l;
}

void inserir_fim(Lista* l, Membro m) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro Crítico: Servidor sem memória!\n");
        return;
    }
    novo->dados = m;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        No* atual = l->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}
void mostrar_guilda(Lista l) {
    if (l.inicio == NULL) {
        printf("\n[SISTEMA] A guilda está vazia no momento.\n");
        return;
    }

    printf("\n=== REGISTRO DA GUILDA RECARREGADO ===\n");
    No* atual = l.inicio;
    while (atual != NULL) {
        printf("ID: %04d | Nivel: %2d | Nome: %s\n", 
               atual->dados.id, atual->dados.nivel, atual->dados.nome);
        atual = atual->prox;
    }
    printf("======================================\n");
}
void liberar_lista(Lista* l) {
    No* atual = l->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    l->inicio = NULL;
}
void salvar_guilda_teste() {
    FILE* arquivo = fopen("guild_roster.b", "wb");
    if (arquivo == NULL) {
        printf("[ERRO] Falha ao criar o arquivo de teste.\n");
        return;
    }
    Membro m1 = {1, "Arthur Pendragon", 60};
    Membro m2 = {2, "Merlin Ambrosius", 99};
    Membro m3 = {3, "Lancelot Du Lac", 55};

    fwrite(&m1, sizeof(Membro), 1, arquivo);
    fwrite(&m2, sizeof(Membro), 1, arquivo);
    fwrite(&m3, sizeof(Membro), 1, arquivo);

    fclose(arquivo);
    printf("[SISTEMA] Arquivo 'guild_roster.b' de teste criado e populado!\n");
}
Lista carregar_guilda() {
    Lista nova_lista = criar_lista_vazia();
    FILE* arquivo = fopen("guild_roster.b", "rb");

    if (arquivo == NULL) {
        printf("\n[ALERTA] Arquivo 'guild_roster.b' não encontrado. Iniciando guilda vazia.\n");
        return nova_lista;
    }

    Membro membro_temp;
    
    while (fread(&membro_temp, sizeof(Membro), 1, arquivo) == 1) {
        inserir_fim(&nova_lista, membro_temp);
    }
    fclose(arquivo);
    printf("[SISTEMA] Dados do servidor recarregados com sucesso.\n");
    
    return nova_lista;
}
int main() {
    printf("Iniciando rotina de boot do servidor...\n");
    salvar_guilda_teste();
    Lista minha_guilda = carregar_guilda();
    mostrar_guilda(minha_guilda);
    liberar_lista(&minha_guilda);

    return 0;
}