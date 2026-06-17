#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Unidade;

int main() {
    int n;
    printf("Digite o numero de unidades inimigas: ");
    scanf("%d", &n);

    Unidade *unidades = (Unidade *)malloc(n * sizeof(Unidade));
    if (unidades == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Digite as coordenadas x e y da unidade %d: ", i + 1);
        scanf("%d %d", &unidades[i].x, &unidades[i].y);
    }
    float raio_explosao;
    printf("Digite o raio de explosao: ");
    scanf("%f", &raio_explosao);
    int duplas_proximas = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double distancia = sqrt(pow(unidades[j].x - unidades[i].x, 2) + 
                                    pow(unidades[j].y - unidades[i].y, 2));

            if (distancia <= raio_explosao) {
                duplas_proximas++;
            }
        }
    }

    printf("Total de duplas distintas dentro do raio de explosao: %d\n", duplas_proximas);
    free(unidades);
    return 0;
}