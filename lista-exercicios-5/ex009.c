#include <stdio.h>
#include <stdlib.h>
 
typedef struct _fracao {
    double n, d;
} Fracao;
 
int main() {
 
    int qtd_testes, i, k, j, c, f=0;
    Fracao * fracoes = NULL;
    char caracter;
 
    scanf("%d", &qtd_testes);
 
    for (i=0; i<qtd_testes; i++) {
        f = 0;
        c=0;
        while (1) {
            fracoes = (Fracao *) realloc(fracoes, (c+1)*sizeof(Fracao));
            scanf("%lf/%lf%c", &fracoes[c].n, &fracoes[c].d, &caracter);
            if (caracter == '\n') break;
            c++;
        }
 
        printf("Caso de teste %d\n", i+1);
        for (k=0; k<c; k++) {
            for (j=k+1; j<=c; j++) {
                if ((fracoes[k].n/fracoes[k].d) == (fracoes[j].n/fracoes[j].d)) {
                    printf("%.0lf/%.0lf equivalente a %.0lf/%.0lf\n", fracoes[k].n, fracoes[k].d, fracoes[j].n, fracoes[j].d);
                    f++;
                }
            }
        }
 
        if (f == 0) printf("Nao ha fracoes equivalentes na sequencia\n");
    }
 
    return 0;
}