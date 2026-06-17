#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    int hp;
    int ataque;
} Monstro;

int buscaBinariaRecursiva(int id_buscado, Monstro vetor[], int inicio, int fim) {
    if (inicio > fim) {
        return -1;
    }
    int meio = inicio + (fim - inicio) / 2;
    if (vetor[meio].id == id_buscado) {
        return meio;
    }
    else if (id_buscado < vetor[meio].id) {
        return buscaBinariaRecursiva(id_buscado, vetor, inicio, meio - 1);
    }
    else {
        return buscaBinariaRecursiva(id_buscado, vetor, meio + 1, fim);
    }
}
int main() {
    int N;
    printf("Digite a quantidade de monstros a serem catalogados: ");
    scanf("%d", &N);
    Monstro bestiario[N];

    printf("Digite os dados (ID Nome HP Ataque) de cada monstro em ordem crescente de ID:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d %49s %d %d", &bestiario[i].id, bestiario[i].nome, &bestiario[i].hp, &bestiario[i].ataque);
    }

    printf("\n--- Bestiario Pronto! ---\n");

    int id_busca;
    while (1) {
        printf("\nDigite o ID que deseja buscar (ou 0 para fechar): ");
        scanf("%d", &id_busca);

        if (id_busca == 0) {
            printf("Fechando o Bestiario...\n");
            break;
        }
        int indice = buscaBinariaRecursiva(id_busca, bestiario, 0, N - 1);
        if (indice != -1) {
            printf("Monstro Encontrado: %s (ID: %d) - HP: %d, Ataque: %d\n",
                   bestiario[indice].nome,
                   bestiario[indice].id,
                   bestiario[indice].hp,
                   bestiario[indice].ataque);
        } else {
            printf("Monstro com ID %d nao encontrado.\n", id_busca);
        }
    }

    return 0;
}
