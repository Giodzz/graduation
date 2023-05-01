#include <stdio.h>

int main() {

    int l, c, soma, i, k, l1, l2;
    int  maior_soma = 0;
    int M[6][6];

    // ler a matriz
    for (l=0; l<6; l++) {
        for (c=0; c<6; c++) {
            scanf("%d", &M[l][c]);
        }
    }

    
    for (i=0; i<4; i++) { // mapulheta passa para a linha de baixo
        l1 = 0;
        l2 = 1;
        
        for (k=0; k<4; k++) { // ampulheta desloca na mesma linha
            soma = 0;

            // leitura de uma ampulheta
            for (l=0; l<3; l++) {
                if (l%2==0) {
                    for (c=l1; c<l1+3; c++) {
                        soma += M[l+i][c]; 
                    }
                } else {
                    soma += M[l+i][l2];
                }
            }
            l1++;
            l2++;
            if (k==0 && i==0) {
                maior_soma = soma;
                continue;
            }
            
            if (soma > maior_soma) {
                maior_soma = soma;
            }
        }
    }

    printf("%d\n", maior_soma);
    return 0;
}