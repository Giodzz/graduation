#include <stdio.h>

int main() {

    int qtd_linhas, qtd_colunas, l, c, M, lM, cM, m, lm, cm, t;
    int A[1000][1000];

    scanf("%d %d", &qtd_linhas, &qtd_colunas);

    // preencher a matriz
    for (l=0; l<qtd_linhas; l++) {
        for (c=0; c<qtd_colunas; c++) {
            scanf("%d", &A[l][c]);
        }
    }

    // achar maior elemento
    for (l=0; l<qtd_linhas; l++) {
        for (c=0; c<qtd_colunas; c++) {
            if (c==0 && l==0) {
                M = A[l][c];
                lM = l;
                cM = c;
            }
            if(A[l][c] > M) {
                M = A[l][c];
                lM = l;
                cM = c;
            }
        }
    }

    // achar menor elemento
    for (l=0; l<qtd_linhas; l++) {
        for (c=0; c<qtd_colunas; c++) {
            if (c==0 && l==0) {
                m = A[l][c];
                lm = l;
                cm = c;
            }
            if (A[l][c] < m) {
                m = A[l][c];
                lm = l;
                cm = c;
            }
        }
    }

    // trocá-los de posição
    t = A[lM][cM];
    A[lM][cM] = A[lm][cm];
    A[lm][cm] = t;

    // printar a matriz
    for (l=0; l<qtd_linhas; l++) {
        for (c=0; c<qtd_colunas; c++) {
            printf("%d ", A[l][c]);
        }
        printf("\n");
    }
    return 0;
}