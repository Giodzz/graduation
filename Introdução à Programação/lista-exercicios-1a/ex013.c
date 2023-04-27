#include <stdio.h>
#include <math.h>
 
int main() {
 
   int a, b, c;
   double delta, d, x1, x2;
 
   scanf("%d %d %d", &a, &b, &c);
 
   // Calcular raízes
   delta = b*b - 4*a*c;
   d = sqrt(delta);
   x1 = (-b + d) / (2*a);
   x2 = (-b - d) / (2*a);
   if (delta < 0) {
      printf("POSICOES IMAGINARIAS");
      return 0;
   } else {
      printf("POSICOES: X1=%.2lf e X2=%.2lf", x1, x2);
   }
 
   // Se está dentro ou não do polinômio
   if (x1 > 5 || x1 < -5 || x2 > 5 || x2 < -5) {
      printf(" (FORA DO EXPERIMENTO)");
   }
 
   // Fato 1
   if ((a + b + c) % 3 == 0) {
      printf("\nFATO1: DESAPARECIDA");
   }
 
   // Fato 2
   if (c % 2 == 0 && c < (a + b)) {
      printf("\nFATO2: ORIGEM");
   }
 
   return 0;
}
