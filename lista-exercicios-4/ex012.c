#include <stdio.h>
#include <string.h>
#define MAX_WORDS 200
#define MAX_WORD_LEN 64+1
 
int str_split(char * str, char m[][MAX_WORD_LEN], char * sep);
int freq_maior_palavra(char m[][MAX_WORD_LEN], int L);
 
int main() {
 
   char entrada[100000];
   char separadores[1000];
   char m[MAX_WORDS][MAX_WORD_LEN];
 
   scanf("%[^\n]%*c", entrada);
   scanf("%[^\n]%*c", separadores);
   str_split(entrada, m, separadores);
 
 
   return 0;
}
 
int str_split(char * str, char m[][MAX_WORD_LEN], char * sep) {
   int i, k, j, l=0, c=0, pos_s, inicio=0, linha;
   char s, s_ant;
 
   
   for (i=0; i<strlen(str); i++) {
      // caracter sendo analisado = str[i]
      for (k=0; k<strlen(sep); k++) {
         if(str[i] == sep[k]) {
            if(i!=0 && str[i-1] != s && i != strlen(str)-1) {
               l++;
               c=0;
            }
            s = str[i];
            break;
         }
      }
      if(str[i] == s) continue;
      m[l][c] = str[i];
      c++;
   }
 
   for(linha=0; linha<=l; linha++) {
      if(m[linha][0] != '\0') printf("(%d)%s\n", strlen(m[linha]), m[linha]);
   }
 
   printf("%d", freq_maior_palavra(m, l+1));
}
 
int freq_maior_palavra(char m[][MAX_WORD_LEN], int L) {
   int l, maior=0, freq=0;
 
   for (l=0; l<L; l++) {
      if (strlen(m[l]) > maior) maior = strlen(m[l]);
   }
 
   for (l=0; l<L; l++) {
      if(strlen(m[l]) == maior) freq++;
   }
 
   return freq;
}