#include <stdio.h>
#include "combate.h"

int main() {
    int ataque_base_heroi;
    int bonus_espada;
    int vida_inicial_inimigo;

    printf("--- Simulador de Combate RPG ---\n\n");

    printf("Digite o ataque base do herói: ");
    scanf("%d", &ataque_base_heroi);

    printf("Digite o bônus da espada do herói: ");
    scanf("%d", &bonus_espada);

    printf("Digite a vida inicial do inimigo: ");
    scanf("%d", &vida_inicial_inimigo);

    int ataque_total = calcular_ataque_total(ataque_base_heroi, bonus_espada);
    int vida_restante_inimigo = aplicar_dano(vida_inicial_inimigo, ataque_total);

    printf("\n--- Resultados ---\n");
    printf("Poder de ataque total do herói: %d\n", ataque_total);
    printf("Vida restante do inimigo: %d\n", vida_restante_inimigo);

    return 0;
}