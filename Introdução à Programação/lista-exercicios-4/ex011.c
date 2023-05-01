#include <stdio.h>
#include <string.h>
#include <math.h>
 
//#define MAX(a, b)  (a)>(b)?(a):(b)
 
void ler_polinomio(int n, double * coef, int * e);
void somar_polinomios(
   int n1, double * coef1, int * e1,
   int n2, double * coef2, int * e2,
   double * coef_r, int * e_r
);
void compara_ordena(double * coef, int * e, int n);
void sub_polinomios(
   int n1, double * coef1, int * e1,
   int n2, double * coef2, int * e2,
   double * coef_r, int * e_r
);
 
 
int main() {
 
   int n_testes, i, k, j, c=1, termos1, termos2, pos, tamanho;
   char sinal;
   double coef1[50], coef2[50];
   int e1[50], e2[50];
   double coef_r[100];
   int e_r[100];
   
   scanf("%d", &n_testes);
 
   for (i=0; i<n_testes; i++) {
      memset(coef1, 0, 50*sizeof(double));
      memset(coef2, 0, 50*sizeof(double));
      memset(coef_r, 0, 100*sizeof(double));
      memset(e1, 0, 50*sizeof(int));
      memset(e2, 0, 50*sizeof(int));
      memset(e_r, 0, 100*sizeof(int));

      scanf("\r\n%c%*c", &sinal);
 
      scanf("%d", &termos1);
      ler_polinomio(termos1, coef1, e1);
 
      scanf("%d", &termos2);
      ler_polinomio(termos2, coef2, e2);
 
      if (sinal == '+') somar_polinomios(termos1, coef1, e1, termos2, coef2, e2, coef_r, e_r);
      else if (sinal == '-') sub_polinomios(termos1, coef1, e1, termos2, coef2, e2, coef_r, e_r);
   }
   return 0;
}
 
void ler_polinomio(int n, double * coef, int * e) {
   int i;
 
   for (i=0; i<n; i++) {
      scanf("%lf %d", &coef[i], &e[i]);
   }
}
 
void somar_polinomios(
   int n1, double * coef1, int * e1,
   int n2, double * coef2, int * e2,
   double * coef_r, int * e_r) {
 
   int cont = 0, adicionou, contem, max;
   int i, j;
    
   for (i=0; i<n1; i++) {
      adicionou = 0;
      for (j=0; j<n2; j++) {
         if (e1[i] == e2[j]) {
            coef_r[cont] = coef1[i] + coef2[j];
            e_r[cont] = e1[i];
            cont++;
            adicionou++;
         }
      }
 
      if (adicionou == 0) {
         coef_r[cont] = coef1[i];
         e_r[cont] = e1[i];
         cont++;
      }
   }  
   max = cont;
 
   for (i=0; i<n2; i++) {
      contem = 0;
      for (j=0; j<max; j++) {
         if (e2[i] == e_r[j]) contem++;
      }
 
      if (contem == 0) {
         e_r[cont] = e2[i];
         coef_r[cont] = coef2[i];
         cont++;
      }
   }
 
   compara_ordena(coef_r, e_r, cont);
 
 
   for (j=0; j<cont; j++) {
      if (e_r[j] != 0 && coef_r[j] != 0) printf("%+.2lfX^%d", coef_r[j], e_r[j]);
      else if (coef_r[j] == 0.00) continue;
      else if (e_r[j] == 0) printf("%+.2lf", coef_r[j]);
   }
   printf("\n");
    
}
 
void sub_polinomios(
   int n1, double * coef1, int * e1,
   int n2, double * coef2, int * e2,
   double * coef_r, int * e_r) {
 
   int cont = 0, adicionou, contem, max;
   int i, j;
    
   for (i=0; i<n1; i++) {
      adicionou = 0;
      for (j=0; j<n2; j++) {
         if (e1[i] == e2[j]) {
            coef_r[cont] = coef1[i] - coef2[j];
            e_r[cont] = e1[i];
            cont++;
            adicionou++;
         }
      }
 
      if (adicionou == 0) {
         coef_r[cont] = coef1[i];
         e_r[cont] = e1[i];
         cont++;
      }
   }  
   max = cont;
 
   for (i=0; i<n2; i++) {
      contem = 0;
      for (j=0; j<max; j++) {
         if (e2[i] == e_r[j]) contem++;
      }
 
      if (contem == 0) {
         e_r[cont] = e2[i];
         coef_r[cont] = -coef2[i];
         cont++;
      }
   }
 
   compara_ordena(coef_r, e_r, cont);
 
 
   for (j=0; j<cont; j++) {
      if (e_r[j] != 0 && coef_r[j] != 0) printf("%+.2lfX^%d", coef_r[j], e_r[j]);
      else if (coef_r[j] == 0.00) continue;
      else if (e_r[j] == 0) printf("%+.2lf", coef_r[j]);
   }
   printf("\n");
    
}
 
 
void compara_ordena(double * coef, int * e, int n) {
   int i, k, t1, pm; // pm posição do maior
   double t2;
   for (i=0; i<n-1; i++) {
      pm = i;
      for (k=i+1; k<n; k++) {
         if (e[k] > e[pm]) pm = k;
      }
 
      t1 = e[i];
      e[i] = e[pm];
      e[pm] = t1;
      t2 = coef[i];
      coef[i] = coef[pm];
      coef[pm] = t2;
   }
}
