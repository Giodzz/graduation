#include <stdio.h>
#include <math.h>
 
int main() {
 
   int n, c1, h;
   double c2;
   scanf("%d", &n);
 
   for (h = 1; h <= n; h++) {
      for(c1 = 1; c1 < h; c1 ++) {
         c2 = sqrt(h*h - c1*c1);
         if (c2 == (int) c2) {
            if (c1 <= c2) {
               printf("hipotenusa = %d, catetos %d e %.0lf\n", h, c1, c2);
            }
         }
      }
   }
   
 
   return 0;
}