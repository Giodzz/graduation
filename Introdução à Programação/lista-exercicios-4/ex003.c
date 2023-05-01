#include <stdio.h>

int main() {

   int n_testes, n, d, n_fracoes, i, l, k, equivalentes;
   double M[50][2], fracao1, fracao2;
   scanf("%d", &n_testes);

   for (i=1; i<=n_testes; i++) {
      equivalentes = 0;
      scanf("%d", &n_fracoes);

      for (l=0; l<n_fracoes; l++) {
         scanf("%lf/%lf", &M[l][0], &M[l][1]);
      }

      printf("Caso de teste %d\n", i);
      for (l=0; l<n_fracoes-1; l++) {
         for (k=l+1; k<n_fracoes; k++) {
            fracao1 = M[l][0]/M[l][1];
            fracao2 = M[k][0]/M[k][1];
            if (fracao1 == fracao2) {
               printf("%.0lf/%.0lf equivalente a %.0lf/%.0lf\n", M[l][0], M[l][1], M[k][0], M[k][1]);
               equivalentes++;
            } 
         }
      }

      if (equivalentes == 0) printf("Nao ha fracoes equivalentes na sequencia\n");
   }
   

   return 0;
}