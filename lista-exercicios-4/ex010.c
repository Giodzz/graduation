#include <stdio.h>

int main() {

  int linhas, colunas, l, c;
  int inicio = 0, i = 0, testes=2;
  int M[10][10];

  scanf("%d %d", &linhas, &colunas);
  if (linhas>10 || linhas<1 || colunas>10 || colunas<1) {
    printf("Dimensao invalida\n");
    return 0;
  }

  // ler a matriz
  for (l=0; l<linhas; l++) {
    for (c=0; c<colunas; c++) {
      scanf("%d", &M[l][c]);
    }
  }

  while (linhas-i) {
    for (l=inicio; l<linhas-i; l++) {
      for (c=inicio; c<colunas-i; c++) {
        if (l==inicio) printf("%d ", M[l][c]);
        else if (c==colunas-1-i) printf("%d ", M[l][c]);
      }
    }
    
    
    if(linhas>1 && colunas>1) {
      for (l=linhas-1-i; l>=inicio; l--) {
        for (c=colunas-1-i; c>=inicio; c--) {
          if(l==linhas-1-i && c!=colunas-1-i) printf("%d ", M[l][c]);
          else if(inicio!=colunas-1-i &&c==inicio && l!=inicio) printf("%d ", M[l][c]);
        }
      }
    }

    inicio++;
    i++;
  }

  return 0;
}