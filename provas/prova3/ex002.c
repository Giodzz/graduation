#include <stdio.h>
#define N 1000

int main() {

    int ordem_m, l, c, l1, l2, t, pm; //pm - posição do menor
    int m[N][N];

    scanf("%d", &ordem_m);
    // preencher a matriz;
    for (l=0; l<ordem_m; l++) {
        for (c=0; c<ordem_m; c++) {
            scanf("%d", &m[l][c]);
        }
    }

    // ordenar a matriz
    for (c=0; c<ordem_m; c++) {
        for (l1=0; l1<ordem_m-1; l1++) {
            pm = l1;
            for (l2=l1+1; l2<ordem_m; l2++) {
                if (m[l2][c] < m[pm][c]) pm = l2;
            }

            t = m[l1][c];
            m[l1][c] = m[pm][c];
            m[pm][c] = t;
        }
    }

    // printar a matriz
    for (l=0; l<ordem_m; l++) {
        for (c=0; c<ordem_m; c++) {
            if (c==0) printf("%d", m[l][c]);
            else printf(" %d", m[l][c]);
        }
        printf("\n");
    }

    return 0;
}
