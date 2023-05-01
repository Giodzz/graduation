#include <stdio.h>

int main() {

    int n, l, c;
    int i = 0, contador = 0;
    char borda, fundo;
    char M[99][99];

    scanf("%d %c %c", &n, &borda, &fundo);
    int centro = (n+1)/2 - 1;

    if (n<=99 && n>0 && n%2==1) {
        for (l=0; l<n; l++) {
            for (c=0; c<n; c++) {
                if ((l==0 && c==centro)||(l==n-1 && c==centro)) {
                    printf("%c ", borda);
                } else if((l>0 && c==centro-i) || (l>0 && c==centro+i)) {
                    printf("%c ", borda);
                } else if ((l>0 && c>centro-i) && (l>0 && c<centro+i)) {
                    printf("%c ", fundo);
                } else printf("  ");
            }

            if (i<centro && contador==0) i++;
            else {
                i--;
                contador++;
            }
            printf("\n");
        }
    } else {
        printf("Dimensao invalida!\n");
    }

    return 0;
}