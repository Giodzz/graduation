#include <stdio.h>
void fill_vetor(int * vetor, int tamanho_v);
int contar_elementos_unicos(int * vetor, int tamanho_v);

int main() {

   int n_elementos, i;
   int v[5000];
   scanf("%d", &n_elementos);
   fill_vetor(v, n_elementos);
   printf("%d", contar_elementos_unicos(v, n_elementos));

   return 0;
}

void fill_vetor(int * vetor, int tamanho_v) {
   int i;
   for (i=0; i<tamanho_v; i++) {
      scanf("%d", &vetor[i]);
   }
}

int contar_elementos_unicos(int * vetor, int tamanho_v) {
   int i, k, repeticao;
   int el_unicos = 0;

   for (i=0; i<tamanho_v; i++) {
      repeticao = 0;
      for (k=0; k<tamanho_v; k++) {
         if (vetor[i] == vetor[k] && k!=i) repeticao++;
      }
      if (repeticao == 0) el_unicos++;
   }

   return el_unicos;

}