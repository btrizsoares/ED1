#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spellbook.h"

Spellbook* create_spellbook() {
    Spellbook* new_book = (Spellbook*)malloc(sizeof(Spellbook));
    if (new_book != NULL) {
        new_book->head = NULL;
    }
    return new_book;
}

void add_spell(Spellbook* book, int id, const char* name, int mana_cost) {
    if (book == NULL) return;

    SpellNode* new_node = (SpellNode*)malloc(sizeof(SpellNode));
    if (new_node == NULL) {
        printf("Erro ao alocar memória para o feitiço!\n");
        return;
    }

    new_node->spell.id = id;
    strncpy(new_node->spell.name, name, sizeof(new_node->spell.name) - 1);
    new_node->spell.name[sizeof(new_node->spell.name) - 1] = '\0'; 
    new_node->spell.mana_cost = mana_cost;
    new_node->next = NULL;

    if (book->head == NULL) {
        book->head = new_node;
    } else {
        SpellNode* current = book->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void display_spellbook(Spellbook* book) {
    if (book == NULL || book->head == NULL) {
        printf("O grimorio esta vazio.\n");
        return;
    }

    printf("\n=== Grimorio do Mago ===\n");
    SpellNode* current = book->head;
    while (current != NULL) {
        printf("ID: %d, Feitico: %s, Custo de Mana: %d\n", 
               current->spell.id, current->spell.name, current->spell.mana_cost);
        current = current->next;
    }
    printf("========================\n\n");
}

void destroy_spellbook(Spellbook* book) {
    if (book == NULL) return;

    SpellNode* current = book->head;
    SpellNode* next_node = NULL;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    free(book);
}