#include <stdio.h>
#include <stdlib.h>
 
typedef struct _imovel {
   int p;
   double c, c_medio;
} Imovel;
 
typedef struct _cidade {
   int soma_p;
   double soma_c, cm_total;
   Imovel * imoveis;
   Imovel * imoveis_agrup;
} Cidade;
 
void ordenar_vetor(Imovel * v, int n);
 
int agrupar_cm(Cidade * a, int n);
 
int main() {
   int i, qtd_imoveis, c = 0, tam;
   Cidade * cidades = NULL;
   
   while (1) {
 
      scanf("%d", &qtd_imoveis);
      if (qtd_imoveis == 0) break;
      cidades = (Cidade *) realloc(cidades, (c+1)*sizeof(Cidade));
      cidades[c].imoveis_agrup = NULL;
      cidades[c].imoveis = NULL;
      cidades[c].imoveis = (Imovel *) calloc(qtd_imoveis, sizeof(Imovel));
 
      cidades[c].soma_p = 0;
      cidades[c].soma_c = 0;
 
      // entrada de infos
      for (i=0; i<qtd_imoveis; i++) {
         scanf("%d %lf", &cidades[c].imoveis[i].p, &cidades[c].imoveis[i].c);
         cidades[c].imoveis[i].c_medio = cidades[c].imoveis[i].c/cidades[c].imoveis[i].p; 
         cidades[c].soma_p += cidades[c].imoveis[i].p;
         cidades[c].soma_c += cidades[c].imoveis[i].c;
      }
      cidades[c].cm_total = cidades[c].soma_c/cidades[c].soma_p;
 
      ordenar_vetor(cidades[c].imoveis, qtd_imoveis);
      tam = agrupar_cm(&(cidades[c]), qtd_imoveis);
 
      printf("Cidade# %d:\n", c+1);
      for (i=0; i<tam; i++) {
         printf("%d-%d ", cidades[c].imoveis_agrup[i].p, (int) (cidades[c].imoveis_agrup[i].c_medio));
      }
      printf("\n");
      printf("Consumo medio: %.2lf m3.\n", cidades[c].cm_total);
 
      free(cidades[c].imoveis);
      free(cidades[c].imoveis_agrup);
      c++;
   }
 
   free(cidades);
 
   return 0;
}
 
void ordenar_vetor(Imovel * v, int n) {
   int i, k, pm;
   Imovel aux;
 
   for (i=0; i<n-1; i++) {
      pm = i;
      for (k=i+1; k<n; k++) {
         if (v[k].c_medio < v[pm].c_medio) {
            pm = k;
         }
      }
 
      aux = v[i];
      v[i] = v[pm];
      v[pm] = aux;
   }
 
}
 
int agrupar_cm(Cidade * a, int n) {
   int i, k, c=0, j=0, soma=0, m=0;
 
   for (i=c; i<n; i+=m) {
      c=i+1;
      if ((int) a->imoveis[i].c_medio == (int) a->imoveis[c].c_medio) {
         while (1) {
            c++;
            if ((int) a->imoveis[i].c_medio != (int) a->imoveis[c].c_medio) break;
         }
        
         soma = 0;
         for(k=0; k<c; k++) { 
            soma += a->imoveis[k].p;
         }
 
         a->imoveis_agrup = (Imovel *) realloc(a->imoveis_agrup, (j+1)*sizeof(Imovel));
         a->imoveis_agrup[j].p = soma;
         a->imoveis_agrup[j].c_medio = a->imoveis[i].c_medio;
         j++;
         m = c;
 
      } else {
        a->imoveis_agrup = (Imovel *) realloc(a->imoveis_agrup, (j+1)*sizeof(Imovel));
        a->imoveis_agrup[j].p = a->imoveis[i].p;
        a->imoveis_agrup[j].c_medio = a->imoveis[i].c_medio;
        j++;
        m=1;
      }
   }
 
   return j;
}