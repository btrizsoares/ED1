#include <stdio.h>

typedef struct {
    int id;
    int pontuacao;
} Jogador;

void trocar(Jogador *a, Jogador *b) {
    Jogador temp = *a;
    *a = *b;
    *b = temp;
}

int particao(Jogador v[], int baixo, int alto) {
    int pivo = v[alto].pontuacao;
    int i = baixo - 1;
    int j;
    for (j = baixo; j < alto; j++) {
        if (v[j].pontuacao >= pivo) {
            i++;
            trocar(&v[i], &v[j]);
        }
    }
    trocar(&v[i + 1], &v[alto]);
    return i + 1;
}

void quickSort(Jogador v[], int baixo, int alto) {
    if (baixo < alto) {
        int pivo_indice = particao(v, baixo, alto);
        quickSort(v, baixo, pivo_indice - 1);
        quickSort(v, pivo_indice + 1, alto);
    }
}

int main() {
    int n;
    int i;
    printf("Sistema de Placar da Arena inicializado.\n");
    printf("Digite o numero de jogadores na partida: ");
    scanf("%d", &n);

    Jogador v[n];
    for (i = 0; i < n; i++) {
        printf("Digite o ID e a pontuacao do jogador %d (separados por espaco): ", i + 1);
        scanf("%d %d", &v[i].id, &v[i].pontuacao);
    }
    quickSort(v, 0, n - 1);
    printf("\n--- PLACAR FINAL ---\n");
    for (i = 0; i < n; i++) {
        printf("Jogador ID: %d | Pontuacao: %d\n", v[i].id, v[i].pontuacao);
    }
    return 0;
}