#include <stdio.h>
#include <string.h>

int main () {
    char fase_inicio_luta[] = "Você nunca sairá daqui com vida!";
    char caixa_dialogo[100] = "(Silêncio...)";

    printf("CHEFE antes da luta: %s\n", caixa_dialogo);

    strcpy(caixa_dialogo, fase_inicio_luta);

    printf("CHEFE diz: %s\n", caixa_dialogo);

    return 0;
}