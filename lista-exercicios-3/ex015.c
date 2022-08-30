#include <stdio.h>

int main() {

   int n, k, i, c_alunos_p = 0;
   int alunos_p[1000];

   memset(alunos_p, 1, 1000*sizeof(int));
   scanf("%d %d", &n, &k);
   for (i=0; i<n; i++) {
      scanf("%d", &alunos_p[i]);
      if (alunos_p[i] <= 0) {
         c_alunos_p += 1; 
      }
   }
   
   if (c_alunos_p < k) printf("SIM\n");
   else {
      printf("NAO\n");
      for (i=n; i>=0; i--) {
         if (alunos_p[i] <= 0) printf("%d\n", i+1);
      }
   }

   return 0;
}