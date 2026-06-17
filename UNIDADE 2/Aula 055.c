#include <stdio.h>
#include <string.h>

typedef struct {
    int ID;
    char nickname[50];
    int reputacao;
} Jogador;

int BuscaBinaria(int id, Jogador jogadores[], int n) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (jogadores[meio].ID == id) {
            return meio;
        } else if (jogadores[meio].ID < id) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main () {
    int n;
    printf("Digite o número de jogadores a serem cadastrados: ");
    scanf("%d", &n);

    Jogador jogadores[n];

    for (int i = 0; i < n; i++) {
        printf("\n--- Cadastro do Jogador %d ---\n", i + 1);

        printf("ID (insira em ordem crescente): ");
        scanf("%d", &jogadores[i].ID);

        printf("Nickname: ");
        scanf("%49s", jogadores[i].nickname);

        printf("Reputacao inicial: ");
        scanf("%d", &jogadores[i].reputacao);
    }
    int opcao = 0;
    while (opcao != 2) {
        printf("\nMENU\n");
        printf("1 - Adicionar Reputacao\n");
        printf("2 - Sair\n");
        printf("ESCOLHA UMA OPCAO: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int id_pesquisado;
            printf("Digite o ID do jogador a ser modificado: ");
            scanf("%d", &id_pesquisado);

            int indice = BuscaBinaria(id_pesquisado, jogadores, n);

            if (indice != -1) {
                jogadores[indice].reputacao += 100;
                printf("Nickname: %s, Nova Reputação: %d\n", jogadores[indice].nickname, jogadores[indice].reputacao);
            } else {
                printf("Jogador com ID %d não encontrado.\n", id_pesquisado);
            }
        } else if (opcao != 2) {
            printf("Opção inválida, tente novamente.\n");
        }
    }

    printf("\nEncerrando o sistema!\n");

    return 0;
}