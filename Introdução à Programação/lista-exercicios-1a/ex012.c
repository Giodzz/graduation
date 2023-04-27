#include <stdio.h>
 
int main() {
 
   double renda, renda_pcapta;
   int qtd_pessoas, escola, etnia;
   // escola (1 - particular, 2 - pública)
   // etnia (1,2,3 - PPI, 4 - branco)
 
   double referencia = 1.5 * 937.00;
 
   scanf("%lf %d %d %d", &renda, &qtd_pessoas, &escola, &etnia);
   renda_pcapta = renda / qtd_pessoas;
 
   if (escola == 2) {
      if (renda_pcapta <= referencia) {
         if (etnia != 4) {
            printf("ALUNO COTISTA (L2)");
         } else {
            printf("ALUNO COTISTA (L1)");
         }
      } else {
         if (etnia != 4) {
            printf("ALUNO COTISTA (L4)");
         } else {
            printf("ALUNO COTISTA (L3)");
         }
      }
   } else {
      printf("ALUNO NAO COTISTA");
   }
 
   return 0;
}
