#include <stdio.h>
#include "spellbook.h"

int main() {
    Spellbook* meu_grimorio = create_spellbook();
    if (meu_grimorio == NULL) {
        printf("Falha ao criar o grimório.\n");
        return 1;
    }

    printf("Adicionando feiticos ao grimorio...\n");
    add_spell(meu_grimorio, 1, "Bola de Fogo", 50);
    add_spell(meu_grimorio, 2, "Escudo de Gelo", 30);
    add_spell(meu_grimorio, 3, "Raio Arcano", 80);
    add_spell(meu_grimorio, 4, "Cura Leve", 25);

    display_spellbook(meu_grimorio);

    destroy_spellbook(meu_grimorio);
    printf("O grimorio foi destruido e a memoria liberada com sucesso.\n");

    return 0;
}