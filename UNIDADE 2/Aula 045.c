#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int nivel;
    float vida;
    float mana;
} Personagem;

void menu() {
    printf("== ESCOLHA UMA OPÇÃO ==\n");
    printf("1 - Criar Novo Personagem\n");
    printf("2 - Sair\n");
}

int main() {
    FILE *arquivo;
    Personagem novopersonagem;
    int opcao;

    arquivo = fopen("savegame.sav", "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de salvamento.\n");
        return 1;
    }

    do {
        menu();
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite o nome do personagem: ");
            scanf("%s", novopersonagem.nome);

            printf("Digite o nível do personagem: ");
            scanf("%d", &novopersonagem.nivel);

            printf("Digite os pontos de vida: ");
            scanf("%f", &novopersonagem.vida);

            printf("Digite os pontos de mana: ");
            scanf("%f", &novopersonagem.mana);

            fwrite(&novopersonagem, sizeof(Personagem), 1, arquivo);

            printf("Personagem '%s' salvo com sucesso no arquivo binário\n", novopersonagem.nome);
        } else if (opcao == 2) {
            printf("Salvando os dados e encerrando o sistema...\n");
        }
    } while (opcao != 2);

    fclose(arquivo);
    return 0;
}