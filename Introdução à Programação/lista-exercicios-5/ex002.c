#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct _produto {
    char * nome;
    double preco;
} Produto;
 
 
typedef struct _lista_compras {
    char * nome;
    int qtd;
} Lc;
 
int main() {
 
    int n_testes, produtos_disp, produtos_comp, i, k, c, erros;
    double total;
    Produto * p = NULL; //vetor de produtos
    Lc * lc = NULL;
    char nome[50];
    scanf("%d", &n_testes);
 
    while (n_testes--) {
        total = 0;
        scanf("%d\n", &produtos_disp);
        p = (Produto *) malloc(produtos_disp*sizeof(Produto));
 
        for (i=0; i<produtos_disp; i++) {
            scanf("%s %lf", nome, &(p[i].preco));
            p[i].nome = (char *) malloc((strlen(nome)+1)*(sizeof(char)));
            strcpy(p[i].nome, nome);
        }
 
        scanf("%d\n", &produtos_comp);
        lc = (Lc *) malloc(produtos_comp*sizeof(Lc));
 
        for (i=0; i<produtos_comp; i++) {
            scanf("%s %d", nome, &(lc[i].qtd));
            lc[i].nome = (char *) malloc((strlen(nome)+1)*sizeof(char));
            strcpy(lc[i].nome, nome);
        }
 
        for (i=0; i<produtos_comp; i++) {
            for (k=0; k<produtos_disp; k++) {
                erros = 0;
                for (c=0; c<strlen(lc[i].nome); c++) {
                    if(lc[i].nome[c] != p[k].nome[c]) erros++;
                }
                if (erros == 0) {
                    total += lc[i].qtd*p[k].preco;
                }
            }
        }
        printf("R$ %.2lf\n", total);
 
        for (i=0; i<produtos_disp; i++) free(p[i].nome);
        for (i=0; i<produtos_comp; i++) free(lc[i].nome);
        free(p);
        free(lc);
    }
 
    return 0;
}