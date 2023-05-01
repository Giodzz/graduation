#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _polynomio {
  char * id;      // string com o nome do polinômio
  int k;          // grau do polinômio
  double * coef;  // vetor de coeficientes do polinômio
} Poly;

/**
 * Lê um polinomio, analisa o maior expoente e armazena os coeficientes
 * nos indices de seus expoentes
 * @param p polinomio que será lido
 * @return Poly retorna o polinômio já organizado
 */
Poly poly_read(Poly p);

/**
 * Calcula o oposto de todos os coeficientes (diferentes de zero) de um polinômio
 * @param p polinômio a ser "negado"
 * @return Poly 
 */
Poly poly_neg(Poly p);

/**
 * Soma dois polinômios
 * @param p1 primeiro polinômio da soma
 * @param p2 segundo polinômio da soma
 * @return Poly resultante somado
 */
Poly poly_sum(Poly p1, Poly p2);

/**
 * Printa o polinômio ja formatado 
 * @param p polinômio a ser printado
 */
void poly_print(Poly p);


int main() {

  int qtd_p, qtd_o, i, k, j, o, id1, id2;
  char buffer[200], p1[200], p2[200];
  Poly * p = NULL; // vetor de polinomios
  Poly r, r_neg;

  // leitura dos polinomios
  scanf("%d%*c", &qtd_p);
  p = (Poly *) malloc(qtd_p*sizeof(Poly));
  for (i=0; i<qtd_p; i++) {
    p[i] = poly_read(p[i]);
  }

  // leitura das operações
  scanf("%d%*c", &qtd_o);
  for (j=0; j<qtd_o; j++) {
    
    memset(buffer, 0, 200*sizeof(char));
    memset(p1, 0, 200*sizeof(char));
    memset(p2, 0, 200*sizeof(char));

    scanf("%[^\n]%*c", buffer);

    // separar quem é p1 e p2
    o = 0;
    for (i=0; i<strlen(buffer); i++) {
      if (buffer[i] == '+' || buffer[i] == '-') o = i;
    }

    for (i=0; i<o; i++) strcpy(&p1[i], &buffer[i]);
    p1[i] = '\0';
    k = 0;
    for (i=o+1; i<strlen(buffer); i++) {
      strcpy(&p2[k], &buffer[i]);
      k++;
    }

    // achar os polinomios para a conta
    for (i=0; i<qtd_p; i++) {
      if (strcmp(p1, p[i].id) == 0) id1 = i;
      else if (strcmp(p2, p[i].id) == 0) id2 = i;
    }
    
    // analisar o sinal e printar o resultado
    switch (buffer[o]) {
      case '+':
        r = poly_sum(p[id1], p[id2]);
        poly_print(r);
        break;
      
      case '-':
        r_neg = poly_neg(p[id2]);
        r = poly_sum(p[id1], r_neg);
        poly_print(r);
        break;
    }

  }

  // limpeza das memórias alocadas
  for(i=0; i<qtd_p; i++) {
    free(p[i].id);
    free(p[i].coef);
  }
  free(p);

  return 0;
}

Poly poly_read(Poly p) {
  int i, c, e, me;
  char nome[200], buffer[200];
  p.id = NULL;
  p.coef = NULL;

  scanf("%[^:]%*c %[^\n]%*c", nome, buffer);
  p.id = (char *) malloc((strlen(nome)+1)*sizeof(char));
  strcpy(p.id, nome);

  //armazenar o grau do polinomio
  me = 0;
  for (i=0; i<strlen(buffer); i++) {
    if (buffer[i] == 'x' || buffer[i] == '^') continue;
    if (buffer[i-1] == '^') {
      if (atoi(&(buffer[i])) > me) me = atoi(&(buffer[i]));
    }
  }

  p.k = me;
  p.coef = (double *) calloc((p.k + 1), sizeof(double));

  // armazenar os coeficientes do polinomio
  for (i=0; i<strlen(buffer); i++) {
    if (buffer[i] == 'x' || buffer[i] == '^') continue;
  
    if (buffer[i] == '+' || buffer[i] == '-') {
      c = i;
      while (buffer[c] != '^') c++;
      
      e = atoi(&(buffer[c+1]));
      p.coef[e] = atof(&(buffer[i]));

    } else if (i==0) {
      c = i;
      while (buffer[c] != '^') c++;

      e = atoi(&(buffer[c+1]));
      p.coef[e] = atof(&(buffer[i]));
    }
  }

  return p;
}

Poly poly_neg(Poly p) {
  int i;
  Poly pr;
  pr.k = p.k;
  pr.coef = NULL;
  pr.coef = (double *) realloc(pr.coef, (pr.k+1)*sizeof(double));
  memset(pr.coef, 0, (pr.k+1)*sizeof(double));

  for (i=0; i<=pr.k; i++){
    if (p.coef[i] != 0) pr.coef[i] = -(p.coef[i]);
  }

  return pr;
}

Poly poly_sum(Poly p1, Poly p2) {
  int i;
  int maior = p1.k>p2.k ? p1.k : p2.k;
  int menor = p1.k<p2.k ? p1.k : p2.k;
  Poly pr;
  pr.k = maior;
  pr.coef = NULL;
  pr.coef = (double *) realloc(pr.coef, (pr.k+1)*sizeof(double));
  memset(pr.coef, 0, pr.k*sizeof(double));

  // somar coeficientes de mesmo indice
  for (i=0; i<=menor; i++) {
    pr.coef[i] = p1.coef[i] + p2.coef[i];
  }

  // adicionar os coeficientes dos expoentes não comuns
  for (i=menor+1; i<=maior; i++) {
    if (maior == p1.k) {
      pr.coef[i] = p1.coef[i];
    } else if (maior == p2.k) {
      pr.coef[i] = p2.coef[i];
    }
  }

  return pr;
}

void poly_print(Poly p) {
  int i, c = 0;

  for (i=0; i<=p.k; i++) {
    if (p.coef[i] != 0) {
      if (c == 0) {
        printf("%.2lfx^%d", p.coef[i], i);
        c++;
      } else {
        printf("%+.2lfx^%d", p.coef[i], i);
        c++;
      }
    }
  }

  if (c==0) printf("0x^0");
  printf("\n");
}