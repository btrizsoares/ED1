#ifndef HEROI_H
#define HEROI_H

typedef struct heroi Heroi;

Heroi* alocar_herois(int quantidade);
void ler_herois(Heroi* vetor, int quantidade);
void imprimir_herois(Heroi* vetor, int quantidade);
void liberar_herois(Heroi* vetor); 

#endif