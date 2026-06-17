#include <stdio.h>
#include <string.h>

int main () {
    char palavra_secreta[] = "LUX";
    char tentativa_jogador[50];

    printf("Uma voz ancestral ecoa... 'Digite a palavra e passe'\n");
    scanf("%s", tentativa_jogador);

    if (strcmp(tentativa_jogador, palavra_secreta) == 0) {
        printf("A porta mágica... se abre!\n");
    }
    else {
        printf("Nada acontece... Parece que a palavra está incorreta.\n");
    }

    return 0;
}