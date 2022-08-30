#include <stdio.h>
void fill_vetor(int * vetor, int tamanho_v);
void inverter_vetor(int * vetor, int tamanho_v, int * vetor_invertido);
int achar_maior(int * vetor, int tamanho_v);
int achar_menor(int * vetor, int tamamnho_v);
 
int main() {
 
   int n_elementos, i;
   int v[1000], w[1000];
   scanf("%d", &n_elementos);
 
   fill_vetor(v, n_elementos);
   for (i=0; i<n_elementos; i++) {
      if (i==0) printf("%d", v[i]);
      else printf(" %d", v[i]);
   }
   printf("\n");
   inverter_vetor(v, n_elementos, w);
   achar_maior(v, n_elementos);
   achar_menor(w, n_elementos);
 
 
   return 0;
}
 
void fill_vetor(int * vetor, int tamanho_v) {
   int i;
   for (i=0; i<tamanho_v; i++) {
      scanf("%d", &vetor[i]);
   }
}
 
void inverter_vetor(int * vetor, int tamanho_v, int * vetor_invertido) {
   int i;
   int c = tamanho_v - 1;
   for (i=0; i<tamanho_v; i++) {
      vetor_invertido[i] = vetor[c];
      if (i==0) printf("%d", vetor_invertido[i]);
      else printf(" %d", vetor_invertido[i]);
      c--;
   }
   printf("\n");
}
 
int achar_maior(int * vetor, int tamanho_v) {
   int i, maior = 0;
   for (i=0; i<tamanho_v; i++) {
      if (vetor[i] > maior) maior = vetor[i];
   }
   printf("%d\n", maior);
   return maior;
}
 
int achar_menor(int * vetor, int tamanho_v) {
   int i, menor = 0;
   for (i=0; i<tamanho_v; i++) {
      if (vetor[i] < menor || i == 0) menor = vetor[i];
   }
 
   printf("%d\n", menor);
   return menor;
}