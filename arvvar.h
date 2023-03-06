#ifndef _arvvar_h
#define _arvvar_h

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct arvvar {
    char info;
    struct arvvar* prim;
    struct arvvar* prox;
} ArvVar;

ArvVar* arvv_cria(char c);
void arvv_insere(ArvVar* a, ArvVar* sa);
void arvv_imprime(ArvVar* a);
int arvv_pertence(ArvVar* a, char c);
void arvv_libera(ArvVar* a);
int arvv_folhas(ArvVar* a);
int arvv_altura(ArvVar* a);
int arvv_igual(ArvVar* a1, ArvVar* a2);
ArvVar* arvv_copia(ArvVar* a);

#endif