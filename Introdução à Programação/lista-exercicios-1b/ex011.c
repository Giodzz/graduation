#include <stdio.h>
 
int main() {
 
   int t, a, b, i, ca, da, ua, cb, db, ub;
   scanf("%d", &t);
 
   for (i = 1; i <= t; i++) {
      scanf("%d%d", &a, &b);
      ca = a / 100;
      da = (a % 100) / 10;
      ua = (a % 10);
 
      cb = b / 100;
      db = (b % 100) / 10;
      ub = (b % 10);
      
      if (ua > ub) { printf("%d%d%d\n", ua, da, ca); }
      else if (ub > ua) { printf("%d%d%d\n", ub, db, cb); }
      else if (da > da) { printf("%d%d%d\n", ua, da, ca); }
      else if (db > da) { printf("%d%d%d\n", ub, db, cb); }
      else if (ca > cb) { printf("%d%d%d\n", ua, da, ca); }
      else if (cb > ca) { printf("%d%d%d\n", ub, db, cb); }
      else { printf("%d%d%d\n", ua, da, ca); }
   }
 
   return 0;
}
