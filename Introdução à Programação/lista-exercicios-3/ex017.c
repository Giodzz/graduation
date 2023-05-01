#include <stdio.h>
#include <string.h>
double modulo(double n);
void fill_vetor(double * vetor);

int main() {

   int n, i, c;
   double maior;
   double v_ant[3], v[3], v_lig[3];

   memset(v, 0, 3*sizeof(double));
   memset(v_ant, 0, 3*sizeof(double));
   scanf("%d", &n);
   for (i=0; i<n; i++) {
      fill_vetor(v);
      if (i!=0) {
         maior = 0;
         memset(v_lig, 0, 3*sizeof(double));
         for (c=0; c<3; c++) {
            v_lig[c] = modulo(v_ant[c] - v[c]);
            if (v_lig[c] > maior) maior = v_lig[c];
         }
         printf("%.2lf\n", maior);
      }

      for (c=0; c<3; c++) {
         v_ant[c] = v[c];
      }
   }

   return 0;
}

double modulo(double n) {
   if (n < 0) n = -n;
   return n;
}

void fill_vetor(double * vetor) {
   int i;
   for (i=0; i<3; i++) {
      scanf("%lf", &vetor[i]);
   }
}