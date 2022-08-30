#include <stdio.h>
#include <string.h>
void seq(char * v, char * s, int i, int f);
 
int main() {
 
   int n_testes, c, i, f;
   char str[100000], v[500];
 
   scanf("%d", &n_testes);
   for (c=0; c<n_testes; c++) {
      memset(v, 0, 500*sizeof(char));
      memset(str, 0, 100000*sizeof(char));
      scanf("%d %d", &i, &f);
      seq(v, str, i, f);
      espelhar(str);
      printf("%s\n", str);
 
   }
 
   return 0;
}
 
void espelhar(char * str) {
   int size = strlen(str);
   int i;
 
   for (i=0; i<size; i++) {
      str[size*2-1-i] = str[i];
   }
 
   str[size*2] = '\0';
}
 
void seq(char * v, char * s, int i, int f) {
      
   while (i<=f) {
      sprintf(v, "%d", i);
      strcat(s, v);
      i++;
   }
}