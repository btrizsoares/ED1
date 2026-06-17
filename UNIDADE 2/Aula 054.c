#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
    float forca;
    float agilidade;
    float inteligencia;
} Personagem;

int buscaLinear(Personagem v[], int tamanho, int idProcurado) {
    for (int i = 0; i < tamanho; i++) {
        if (v[i].id == idProcurado) {
            return i;
        }
    }
    return -1;
}

int main () {
    int totalPersonagens;

    printf("Digite o número total de personagens na campanha: ");
    scanf("%d", &totalPersonagens);

    Personagem *personagens = (Personagem *)malloc(totalPersonagens * sizeof(Personagem));
    if (personagens == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    for (int i = 0; i < totalPersonagens; i++) {
        printf("Registrando personagem\n");
        printf("ID (inteiro): ");
        scanf("%d", &personagens[i].id);

        printf("Nome: ");
        scanf("%s", personagens[i].nome);

        printf("Força: ");
        scanf("%f", &personagens[i].forca);

        printf("Agilidade: ");
        scanf("%f", &personagens[i].agilidade);

        printf("Inteligência: ");
        scanf("%f", &personagens[i].inteligencia);
    }
    int opcao;

    do {
        printf("Menu\n");
        printf("1 - Consultar personagens\n");
        printf("2 - Sair\n");
        printf("Escolha uma opção.\n");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int idBusca;
            printf("Digite a ID do personagem que deseja buscar: ");
            scanf("%d", &idBusca);

            int indice = buscaLinear(personagens, totalPersonagens, idBusca);

            if (indice != -1) {
                float media = (personagens[indice].forca + personagens[indice].agilidade + personagens[indice].inteligencia) / 3.0;
                printf("Personagem encontrado!\n");
                printf("Nome: %s\n", personagens[indice].nome);
                printf("Media de Atributos: %.2f\n", media);
            } else {
                printf("\nPersonagem não existe.\n");
            }
        } else if (opcao != 2) {
            printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 2);

    free(personagens);
    printf("Programa encerrado.\n");

    return 0;
}