#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
typedef struct {
  double a[4]; // vetor dos a
  double norma;
} Vetor;
 
int main() {
 
  int qtd_vetores, i, k, pm;
  Vetor t;
  double soma;
  Vetor * v = NULL; // meu vetor de vetores
  
  scanf("%d", &qtd_vetores);
  v = (Vetor *) calloc(qtd_vetores, sizeof(Vetor));
 
  // recebendo pontos e calculando norma
  for (i=0; i<qtd_vetores; i++) {
    soma = 0;
    for (k=0; k<4; k++) {
      scanf("%lf", &(v[i].a[k]));
      soma += pow((v[i].a[k]), 2);
    }
    v[i].norma = sqrt(soma);
  }
 
  // ordenar vetor de vetores por norma
  for (i=0; i<qtd_vetores-1; i++) {
    pm = i;
    for (k=i+1; k<qtd_vetores; k++) {
      if(v[k].norma < v[pm].norma) pm = k;
    }
    t = v[i];
    v[i] = v[pm];
    v[pm] = t;
  }
 
  for (i=0; i<qtd_vetores; i++) {
    printf("Vetor: (");
    for (k=0; k<4; k++) {
      printf("%.2lf", v[i].a[k]);
      if (k<3) printf(", ");
    }
    printf(") Norma: %.2lf\n", v[i].norma);
  }
  free(v);
  return 0;
}