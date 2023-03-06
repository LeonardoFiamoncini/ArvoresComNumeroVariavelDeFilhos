#include "arvvar.h"

ArvVar* arvv_cria(char c){
    ArvVar* a = (ArvVar*)malloc(sizeof(ArvVar));
    a->info = c;
    a->prim = NULL;
    a->prox = NULL;
    return a;
}

void arvv_insere(ArvVar* a, ArvVar* sa){
    sa->prox = a->prim;
    a->prim = sa;
}

void arvv_imprime(ArvVar* a){
    printf("<%c", a->info);
    ArvVar *arv = a->prim;
    while (arv != NULL){
        arvv_imprime(arv);
        arv = arv->prox;
    }
    printf(">");
}

int arvv_pertence(ArvVar* a, char c){
    if (a == NULL) return 0;
    return (a->info == c) || (arvv_pertence(a->prim, c)) || (arvv_pertence(a->prox, c));
}

void arvv_libera(ArvVar* a){
    if (a != NULL){
        arvv_libera(a->prim);
        arvv_libera(a->prox);
        free(a);
    } 
}

int arvv_folhas(ArvVar* a){
    if (a == NULL) return 0;
    int folhas = 0;
    ArvVar* arvFilha = a->prim;
    while (arvFilha != NULL){
        ArvVar* arvIrma = arvFilha->prox;
        while (arvIrma != NULL){
            folhas += arvv_folhas(arvIrma);
            arvIrma = arvIrma->prox;
        }
        arvFilha = arvFilha->prim;
    }
    return ++folhas;        
}

int arvv_altura(ArvVar* a){
    int hMax = -1;
    ArvVar *arv = a->prim;
    while (arv != NULL){
        int h = arvv_altura(arv);
        if (h > hMax) hMax = h;
        arv = arv->prox;
    }
    return ++hMax;
}

int arvv_igual(ArvVar* a1, ArvVar* a2){
    if (a1 == a2) return 1;
    else if ((a1 == NULL) != (a2 == NULL)) return 0;
    else if (a1->info != a2->info) return 0;
    else if (!arvv_igual(a1->prim, a2->prim)) return 0;
    else if (!arvv_igual(a1->prox, a2->prox)) return 0;  
    else return 1;
}

ArvVar* arvv_copia(ArvVar* a){
    if (a == NULL) return NULL;
    ArvVar *arv = (ArvVar*)malloc(sizeof(ArvVar));
    arv->info = a->info;
    arv->prim = a->prim;
    arv->prox = a->prox;
    return arv;
}