#include <stdio.h>

/**
 * @brief Função que verifica se a matriz é de permutação * 
 * @param matriz: indica a matriz a ser verificada
 * @param n: indica a dimensao da matriz
 * @param soma: parâmetro de saída, que armazenará a soma de toso os n elementos da matriz;
 * @return int: 0 indica que a matriz não é uma permutação, 1 indica que é!
 */

int ehPermutacao(int matriz[500][500], int n, int * soma);

int main() {

  int n, l, c, permutacao; 
  int soma;
  int A[500][500];
  scanf("%d", &n);

  // ler a matriz
  for (l=0; l<n; l++) {
    for (c=0; c<n; c++) {
      scanf("%d", &A[l][c]);
    }
  }

  printf("%d\n", n);
  permutacao = ehPermutacao(A, n, &soma);
  if (permutacao) printf("PERMUTACAO\n");
  else printf("NAO EH PERMUTACAO\n");
  printf("%d\n", soma);

  return 0;
}

int ehPermutacao(int matriz[500][500], int n, int * soma) {
  int l, c;
  int chance = 0, nulos, unicos;
  *soma = 0;
  for (l=0; l<n; l++) {
    nulos = 0;
    unicos = 0;
    for (c=0; c<n; c++) {
      if (matriz[l][c] == 0) nulos++;
      if (matriz[l][c] == 1) unicos++;
      *soma += matriz[l][c];
    }

    if (nulos == n-1 && unicos == 1) chance++; 
  }

  if (chance == n) return 1;
  else return 0;
}