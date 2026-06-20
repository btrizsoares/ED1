#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mercenario {
    char nome[50];
    char classe[30];
    struct Mercenario* proximo;
} Mercenario;

Mercenario* recrutar(Mercenario* lista, char* nome, char* classe) {
    Mercenario* novo = (Mercenario*)malloc(sizeof(Mercenario));
    if (novo == NULL) {
        printf("Falta de ouro (memória) para recrutar mais membros!\n");
        return lista;
    }
    strcpy(novo->nome, nome);
    strcpy(novo->classe, classe);
    novo->proximo = lista;
    
    printf(">> Mercenario %s (%s) recrutado com sucesso!\n", nome, classe);
    return novo;
}
void listar_mercenarios(Mercenario* lista) {
    if (lista == NULL) {
        printf("\nA guilda esta vazia. Precisamos recrutar!\n");
        return;
    }
    
    printf("\n--- Registro de Mercenarios ---\n");
    Mercenario* atual = lista;
    while (atual != NULL) {
        printf("- %s, o %s\n", atual->nome, atual->classe);
        atual = atual->proximo;
    }
    printf("-------------------------------\n");
}

int tamanho(Mercenario* lista) {
    int contador = 0;          
    Mercenario* atual = lista; 
    while (atual != NULL) {
        contador++;       
        atual = atual->proximo; 
    }

    return contador; 
}
int main() {
    Mercenario* guilda = NULL; 
    int opcao;
    char nome[50], classe[30];

    printf("Bem-vindo, Lider da Guilda!\n");

    do {
        printf("\n=== MESA DE COMANDO ===\n");
        printf("1. Recrutar novo mercenario\n");
        printf("2. Listar membros da guilda\n");
        printf("3. Verificar forca total (Tamanho da guilda)\n");
        printf("4. Fechar a taverna (Sair)\n");
        printf("Escolha sua ordem: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                printf("Nome do recruta: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0; 
                
                printf("Classe (ex: Guerreiro, Mago, Ladino): ");
                fgets(classe, 30, stdin);
                classe[strcspn(classe, "\n")] = 0;
                
                guilda = recrutar(guilda, nome, classe);
                break;
            case 2:
                listar_mercenarios(guilda);
                break;
            case 3:
                printf("\n=> A guilda possui atualmente %d mercenario(s) sob seu comando.\n", tamanho(guilda));
                break;
            case 4:
                printf("\nEncerrando as atividades. Que os deuses protejam sua guilda!\n");
                break;
            default:
                printf("\nOrdem invalida, lider! Tente novamente.\n");
        }
    } while (opcao != 4);

    Mercenario* atual = guilda;
    while (atual != NULL) {
        Mercenario* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}