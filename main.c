#include "arvvar.c"

int main(void){
  setlocale(LC_ALL, "Portuguese");
  
  ArvVar* a = arvv_cria('a');
  ArvVar* b = arvv_cria('b');
  ArvVar* c = arvv_cria('c');
  ArvVar* d = arvv_cria('d');
  ArvVar* e = arvv_cria('e');
  ArvVar* f = arvv_cria('f');
  ArvVar* g = arvv_cria('g');
  ArvVar* h = arvv_cria('h');
  ArvVar* i = arvv_cria('i');
  ArvVar* j = arvv_cria('j');

  /* monta a hierarquia */
  arvv_insere(c, d);
  arvv_insere(b, e);
  arvv_insere(b, c);
  arvv_insere(i, j);
  arvv_insere(g, i);
  arvv_insere(g, h);
  arvv_insere(a, g);
  arvv_insere(a, f);
  arvv_insere(a, b);

  printf("Qtd folhas - a: %d", arvv_folhas(a));
  printf("\nQtd folhas - b: %d", arvv_folhas(b));
  printf("\nQtd folhas - c: %d", arvv_folhas(c));
  printf("\nQtd folhas - d: %d", arvv_folhas(d));
  printf("\nQtd folhas - e: %d", arvv_folhas(e));
  printf("\nQtd folhas - f: %d", arvv_folhas(f));
  printf("\nQtd folhas - g: %d", arvv_folhas(g));
  printf("\nQtd folhas - h: %d", arvv_folhas(h));
  printf("\nQtd folhas - i: %d", arvv_folhas(i));
  printf("\nQtd folhas - j: %d", arvv_folhas(j));

  printf("\n\nAltura - a: %d", arvv_altura(a));
  printf("\nAltura - b: %d", arvv_altura(b));
  printf("\nAltura - c: %d", arvv_altura(c));
  printf("\nAltura - d: %d", arvv_altura(d));
  printf("\nAltura - e: %d", arvv_altura(e));
  printf("\nAltura - f: %d", arvv_altura(f));
  printf("\nAltura - g: %d", arvv_altura(g));
  printf("\nAltura - h: %d", arvv_altura(h));
  printf("\nAltura - i: %d", arvv_altura(i));
  printf("\nAltura - j: %d", arvv_altura(j));

  printf("\n\n\t\tImpressão\n");
  arvv_imprime(a);

  printf("\n\nChar 'a' pertence à arvore? %d", arvv_pertence(a, 'a'));
  printf("\n\nChar 'z' pertence à arvore? %d", arvv_pertence(a, 'z'));

  ArvVar* a2 = arvv_copia(a);
  printf("\n\n\t\tImpressão da Cópia feita\n");
  arvv_imprime(a2);

  printf("\n\nÁrvore a é igual a árvore a2 (Cópia de árvore a)? %d", arvv_igual(a, a2));
  printf("\n\nÁrvore a é igual a árvore b (Filha de árvore a)? %d\n", arvv_igual(a, b));

  arvv_libera(a);
}

