#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Monstro {
    int id;               
    char nome[50];        
    struct Monstro* proximo;
} Monstro;
Monstro* adicionarMonstro(Monstro* lista, int id, char* nome) {
    Monstro* novo = (Monstro*)malloc(sizeof(Monstro));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para o monstro!\n");
        return lista;
    }
    
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->proximo = NULL;
    if (lista == NULL) {
        return novo;
    }
    Monstro* atual = lista;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    return lista;
}

void ordenarBestiario(Monstro* lista) {
    int trocou;
    Monstro* atual;
    Monstro* ultimo = NULL; 
    if (lista == NULL || lista->proximo == NULL) {
        return;
    }

    do {
        trocou = 0;
        atual = lista;

        while (atual->proximo != ultimo) {
            if (atual->id > atual->proximo->id) {
                int tempId = atual->id;
                atual->id = atual->proximo->id;
                atual->proximo->id = tempId;
                char tempNome[50];
                strcpy(tempNome, atual->nome);
                strcpy(atual->nome, atual->proximo->nome);
                strcpy(atual->proximo->nome, tempNome);

                trocou = 1; 
            }
            atual = atual->proximo;
        }
        ultimo = atual; 
        
    } while (trocou); 
}

void mostrarBestiario(Monstro* lista) {
    if (lista == NULL) {
        printf("\nO bestiario esta vazio. Explore o mundo para derrotar monstros!\n");
        return;
    }

    printf("\n================ BESTIARIO ================\n");
    Monstro* atual = lista;
    while (atual != NULL) {
        printf("Nivel de Ameaca (ID): %2d | Monstro: %s\n", atual->id, atual->nome);
        atual = atual->proximo;
    }
    printf("===========================================\n");
}

void liberarBestiario(Monstro* lista) {
    Monstro* atual = lista;
    while (atual != NULL) {
        Monstro* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

int main() {
    Monstro* bestiario = NULL; 
    int opcao, nivelAmeaca;
    char nomeMonstro[50];

    do {
        printf("\n--- DIARIO DO AVENTUREIRO ---\n");
        printf("1. Registrar Monstro Derrotado\n");
        printf("2. Ordenar Bestiario (Por Nivel de Ameaca)\n");
        printf("3. Mostrar Bestiario\n");
        printf("4. Guardar Diario (Sair)\n");
        printf("Escolha uma acao: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                printf("\nNome do Monstro: ");
                fgets(nomeMonstro, 50, stdin);
                nomeMonstro[strcspn(nomeMonstro, "\n")] = 0; 

                printf("Nivel de Ameaca (ID numerico): ");
                scanf("%d", &nivelAmeaca);
                getchar(); 

                bestiario = adicionarMonstro(bestiario, nivelAmeaca, nomeMonstro);
                printf(">> %s foi registrado no seu bestiario!\n", nomeMonstro);
                break;

            case 2:
                ordenarBestiario(bestiario);
                printf("\n>> Bestiario ordenado com sucesso pelo Bubble Sort!\n");
                break;

            case 3:
                mostrarBestiario(bestiario);
                break;

            case 4:
                printf("\nFechando diario e salvando progresso. Ate a proxima caçada!\n");
                break;

            default:
                printf("\nAcao invalida! Escolha uma opcao do menu.\n");
        }
    } while (opcao != 4);

    liberarBestiario(bestiario);

    return 0;
}