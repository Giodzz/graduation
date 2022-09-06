#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
typedef struct _ponto {
  double u, x, y, z;
} Ponto;
 
/**
 * @brief Calcula a distância entre 2 pontos
 * 
 * @param p1 ponto 1
 * @param p2 ponto 2
 * @return double a distância entre eles
 */
double dist_2p(Ponto p1, Ponto p2);
 
 
int main() {
 
  int qtd_pontos, i;
  double d;
  Ponto * pontos = NULL;
 
  scanf("%d", &qtd_pontos);
  pontos = (Ponto *) malloc(qtd_pontos*sizeof(Ponto));
 
  // Entrada da lista de pontos
  for (i=0; i<qtd_pontos; i++) {
    scanf("%lf %lf %lf %lf", &pontos[i].u, &pontos[i].x, &pontos[i].y, &pontos[i].z);
  }
 
  for (i=0; i<qtd_pontos-1; i++) {
    d = dist_2p(pontos[i], pontos[i+1]);
    printf("%.2lf\n", d);
  }
 
  free(pontos);
  return 0;
}
 
 
double dist_2p(Ponto p1, Ponto p2) {
  double d;
  d = sqrt(pow((p1.u-p2.u), 2) + pow((p1.x-p2.x), 2) + pow((p1.y-p2.y), 2) + pow((p1.z-p2.z), 2));
  return d;
}