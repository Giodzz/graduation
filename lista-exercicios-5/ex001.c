#include <stdio.h>
#include <stdlib.h>
 
typedef struct _fracao {
    double n;
    double d;
} Fracao;
 
 
int main() {
 
    int n_testes, qtd_fracoes, i, k, c, e;
    Fracao * fr = NULL; // ponteiro para estrutura
    
    scanf("%d", &n_testes);
 
    for (c=0; c<n_testes; c++) {
        e = 0;
        scanf("%d", &qtd_fracoes);
        //Alocando a memória necessária
        fr = (Fracao *) malloc(qtd_fracoes*sizeof(Fracao));
        for (i=0; i<qtd_fracoes; i++) {
            scanf("%lf/%lf", &fr[i].n, &fr[i].d);
        }
 
        printf("Caso de teste %d\n", c+1);
        for (i=0; i<qtd_fracoes-1; i++) {
            for (k=i+1; k<qtd_fracoes; k++) {
                if ((fr[i].n/fr[i].d) == (fr[k].n/fr[k].d)) {
                    printf("%.0lf/%.0lf equivalente a %.0lf/%.0lf\n", fr[i].n, fr[i].d, fr[k].n, fr[k].d);
                    e++;
                }
            }
        }
 
        if (e==0) printf("Nao ha fracoes equivalentes na sequencia\n");
        
    }
 
    free(fr);
 
    return 0;
}