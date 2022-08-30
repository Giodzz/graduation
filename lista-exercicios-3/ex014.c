#include <stdio.h>
#include <string.h>
#define N 128+1
/**
 * @param str vetor de caracteres onde a string lida será gravada
 * @param n quantidade máxima de caracteres a ser lidos
 * @return quantidade de caracteres lidos
 */
int le_string(char * str, int n);
 
/**
 * @param str string de entrada 
 */
void print_codes(char * str);
 
int main() {
 
   char str[N], s[N];
   char c;
   int i;
 
   scanf("%c", &c);
   le_string(str, 3);
   print_codes(str);
   printf("caracter:%c, str:%s\n", c, str);
 
   scanf("%c", &c);
   le_string(str, 5);
   print_codes(str);
   printf("caracter:%c, str:%s\n", c, str);
 
   scanf("%c", &c);
   le_string(str, 5);
   print_codes(str);
   printf("caracter:%c, str:%s\n", c, str);
 
   scanf("%d", &i);
   le_string(str, 3);
   print_codes(str);
   printf("inteiro:%d, str:%s\n", i, str);
 
   //printf("Digite inteiros separados por espaco: ");
   scanf("%d", &i);
   //printf("inteiro:%d\n", i);
   //printf("Le string (15):\n");
   le_string(str, 15);
   print_codes(str);
   printf("inteiro:%d, str:%s\n", i, str);
 
   //printf("Digite uma string sem espacos: ");
   scanf("%s", s);
   //printf("string:%s\n", str);
   //printf("Le string (10):\n");
   le_string(str, 100);
   print_codes(str);
   printf("string:%s, str:%s\n", s, str);
 
   //printf("Digite uma string com espacos: ");
   scanf("%s", s);
   //printf("string:%s\n", str);
   //printf("Le string (20):\n");
   le_string(str, 100);
   print_codes(str);
   printf("string:%s, str:%s\n", s, str);
 
 
   return 0;
}
 
int le_string(char * str, int n) {
   memset(str, 0, 129*sizeof(char));
   int i = 0, contador = 0;
   char c=' ', r;
   scanf("%c", &r);
   if (r != 10) {
      str[i] = r;
      i++;
      contador++;
   }
   while (c != '\n') {
      scanf("%c", &c);
      if (c != 10) {
         str[i] = c;
         i++;
         contador++;
      }
   }
 
   if (n<i) str[n] = '\0';
   else if (n==i) str[n+1] = '\0';
   else str[i] = '\0';
   return contador;
}
 
void print_codes(char * str) {
   int i = 0;
   while (str[i] != '\0') {
      printf("%d", str[i]);
      if (str[i+1] != '\0') printf(",");
      i++;
   }
   printf("\n");
} 