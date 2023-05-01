#include <stdio.h>

int main() {

  int linhas = 0, colunas = 0, l, c;
  int A[10][10];

  while (linhas<1 || linhas>10) {
    scanf("%d", &linhas);
  }

  while ( colunas<1 || colunas>10) {
    scanf("%d", &colunas);
  }

  for (l=0; l<linhas; l++) {
    for (c=0; c<colunas; c++) {
      scanf("%d", &A[l][c]);
    }
  }

  for (l=0; l<linhas; l++) {
    printf("linha %d: ", l+1);
    for (c=0; c<colunas; c++) {
      printf("%d", A[l][c]);
      if (c+1<colunas) printf(",");
    }
    printf("\n");
  }

  return 0;
}