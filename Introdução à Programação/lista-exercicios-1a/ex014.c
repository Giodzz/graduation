#include <stdio.h>
 
int main() {
 
   int i;
   // i = 1 -> ordem crescente
   // i = 2 -> ordem decrescente
   // i = 3 -> medio M m
   double a, b, c, t, maior, meio, menor;
   scanf("%d\n%lf\n%lf\n%lf", &i, &a, &b, &c);
 
   // (a < b < c)
   if (a >= b) {
      t = a;
      a = b;
      b = t;
   }
 
   t = c;
   if (c <= a) {
      c = b;
      b = a;
      a = t;
   } else if (c <= b) {
      c = b;
      b = t;
   }
 
   maior = c;
   meio = b;
   menor = a;
 
 
   if (i == 1) { 
      printf("%.2lf %.2lf %.2lf", menor, meio, maior);
   } else if (i == 2) {
      printf("%.2lf %.2lf %.2lf", maior, meio, menor);
   } else if (i == 3) {
      printf("%.2lf %.2lf %.2lf", meio, maior, menor);
   }
 
   return 0;
}
