#include <stdio.h>
#define N_MAX 1000
void fill_matriz(int M[][N_MAX], int L, int C);
int freq_maior(int M[][N_MAX], int L, int C, int *maior_);
int freq_menor(int M[][N_MAX], int L, int C, int *menor_);

int main() {
  
  int n_linhas, m_colunas, maior, menor;
  double freq_ma, freq_me;
  int A[1000][1000];

  scanf("%d %d", &n_linhas, &m_colunas);
  fill_matriz(A, n_linhas, m_colunas);


  freq_ma = ((float)freq_maior(A, n_linhas, m_colunas, &maior)/(n_linhas*m_colunas)) * 100;
  freq_me = ((float)freq_menor(A, n_linhas, m_colunas, &menor)/(n_linhas*m_colunas)) * 100;

  printf("%d %.2lf%%\n", menor, freq_me);
  printf("%d %.2lf%%\n", maior, freq_ma);
  return 0;
}

void fill_matriz(int M[][N_MAX], int L, int C) {
  int l, c;
  for (l=0; l<L; l++) {
    for (c=0; c<C; c++) {
      scanf("%d", &M[l][c]);
    }
  }
}

int freq_maior(int M[][N_MAX], int L, int C, int *maior_) {
  int l, c, maior;
  int freq = 0;

  //achar maior
  for (l=0; l<L; l++) {
    for (c=0; c<C; c++) {
      if (l==0 && c==0) {
        maior = M[l][c];
        continue;
      }

      if (M[l][c] > maior) maior = M[l][c];
    }
  }

  // contar frequencia
  for (l=0; l<L; l++) {
    for (c=0; c<C; c++) {
      if (M[l][c] == maior) freq++;
    }
  }
  *maior_ = maior;

  return freq;

}

int freq_menor(int M[][N_MAX], int L, int C, int *menor_) {
  int l, c, menor;
  int freq = 0;

  //achar maior
  for (l=0; l<L; l++) {
    for (c=0; c<C; c++) {
      if (l==0 && c==0) {
        menor = M[l][c];
        continue;
      }

      if (M[l][c] < menor) menor = M[l][c];
    }
  }

  // contar frequencia
  for (l=0; l<L; l++) {
    for (c=0; c<C; c++) {
      if (M[l][c] == menor) freq++;
    }
  }
  *menor_ = menor;

  return freq;
}