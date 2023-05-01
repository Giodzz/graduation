#include <stdio.h>
void fatiar_string(int n, char * vetor, char * prefixo);

int main() {

   int n_testes, i, n;
   char str[500], p[500];

   scanf("%d%*c", &n_testes);
   for (i=0; i<n_testes; i++) {
      scanf("%d %[^\n]%*c", &n, str);
      fatiar_string(n, str, p);
      printf("%s", p);
      printf("\n");
   }


   return 0;
}

void fatiar_string(int n, char * vetor, char * prefixo) {
   int i;
   for (i=0; i<n; i++) {
      prefixo[i] = vetor[i];
   }
   prefixo[i] = '\0';
}