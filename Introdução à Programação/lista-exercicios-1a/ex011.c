#include <stdio.h>
 
int main() {
 
   double a, b, c, d, t;
 
   scanf("%lf%lf", &a, &b);
 
   if (a >= b) {
      t = a;
      a = b;
      b = t;
   }
 
   scanf("%lf", &c);
   t = c;
   if (c <= a) {
      c = b;
      b = a;
      a = t;
   } else if (c <= b) {
      c = b;
      b = t;
   }
 
   scanf("%lf", &d);
   t = d;
   if (d <= a) {
      d = c;
      c = b;
      b = a;
      a = t;
   } else if (d <= b) {
      d = c;
      c = b;
      b = t;
   } else if (d <= c) {
      d = c;
      c = t;
   }
   
   printf("%.2lf, %.2lf, %.2lf, %.2lf", a, b, c, d);
 
   return 0;
}
