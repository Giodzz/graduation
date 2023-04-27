#include <stdio.h>
 
int main() {
   // a < b, b <c
   int n1, n2, n3, a, b, c;
   char c1, c2, c3;
 
   scanf("%d %d %d\n", &n1, &n2, &n3);
   scanf("%c%c%c", &c1, &c2, &c3);
 
   if (n1 <= n2) {
      a = n1;
      b = n2;
   } else if (n2 <= n1) {
      a = n2;
      b = n1;
   }
 
   if (n3 <= a) {
      c = b;
      b = a;
      a = n3;
   } else if (n3 >= b) {
      c = n3;
   } else {
      c = b;
      b = n3;
   }
 
   if (c1 == 'A' && c2 == 'B')
      printf("%d %d %d", a, b, c);
   else if (c1 == 'A' && c2 == 'C')
      printf("%d %d %d", a, c, b);
   else if (c1 == 'B' && c2 == 'A')
      printf("%d %d %d", b, a, c);
   else if (c1 == 'B' && c2 == 'C')
      printf("%d %d %d", b, c, a);
   else if (c1 == 'C' && c2 == 'A')
      printf("%d %d %d", c, a, b);
   else if (c1 == 'C' && c2 == 'B')
      printf("%d %d %d", c, b, a);
 
   return 0;
}
