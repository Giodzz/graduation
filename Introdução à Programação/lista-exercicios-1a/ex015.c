#include <stdio.h>
/*
Estrutura inicial:
ax + by = c
dx + ey = f
*/
 
/*
Isolar x:
x = (c - by) / a
x = (f - ey) / d
*/
 
/*
Igualar equações e resolver y:
(c - by) / a = (f - ey) / d
d*(c - by) = a*(f - ey)
d*c - d*b*y = a*f - a*e*y
a*e*y - d*b*y = a*f - d*c
y*(a*e - d*b) = a*f - d*c
y = (a*f - d*c) / (a*e - d*b)
*/
 
/*
Resolver x:
x = (c - b*y) / a
*/
 
int main() {
 
   double a, b, c, d, e, f, x, y;
 
   scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f);
   y = (a*f - d*c) / (a*e - d*b);
   x = (c - b*y) / a;
 
   printf("O VALOR DE X E = %.2lf\n", x);
   printf("O VALOR DE Y E = %.2lf\n", y);
 
   return 0;
}
