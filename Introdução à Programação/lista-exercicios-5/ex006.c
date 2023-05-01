#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct _data {
  int dia, mes, ano;
} Data;
 
typedef struct _aluno {
  int matricula;
  int dia, mes, ano;
  char nome[200];
} Aluno;
 
/**
 * @brief Função que compara datas de nascimeto
 * 
 * @param a1 data de nascimento do aluno 1
 * @param a2 data de nascimetno do aluno 2
 * @return int retorna 1 se a1 for mais novo ou igual ao a2, retorna 0 caso contrário
 */
int ComparaDataNasc(Aluno a1, Aluno a2);

void ordenar_vetor(Aluno * v, int tamanho_v);
 
int main() {
 
  int qtd_alunos, i, k;
  char nome[200];
  Aluno * alunos = NULL; // vetor de alunos
 
  scanf("%d", &qtd_alunos);
  alunos = (Aluno *) malloc(qtd_alunos*sizeof(Aluno));
 
  // Entrada das informações dos alunos
  for (i=0; i<qtd_alunos; i++) {
   scanf("%d %d %d %d %[^\n]", &alunos[i].matricula, &alunos[i].dia, &alunos[i].mes, &alunos[i].ano, alunos[i].nome);
  }
 
  // colocar em ordem decrescente de data (mais novo -> mais velho)
  ordenar_vetor(alunos, qtd_alunos);
 
  for (i=0; i<qtd_alunos; i++) {
    printf("Matric.: %d Nome: %s Data Nasc: %d/%d/%d\n", alunos[i].matricula, alunos[i].nome, alunos[i].dia, alunos[i].mes, alunos[i].ano);
  }
 
  free(alunos);
 
  return 0;
}
 
int ComparaDataNasc(Aluno a1, Aluno a2) {
   if (a1.ano > a2.ano) {
      return 1;
   } else if (a1.ano == a2.ano) {
      if (a1.mes > a2.mes) {
         return 1;
      } else if (a1.mes == a2. mes) {
         if (a1.dia >= a2.dia) {
            return 1;
         } else {
            return 0;
         }
      } else {
         return 0;
      }
   } else {
      return 0;
   }
}
 
void ordenar_vetor(Aluno * v, int tamanho_v) {
  int i, k, pmv;
  Aluno t;
  for (i=0; i<tamanho_v-1; i++) {
    pmv = i;
    for (k=i+1; k<tamanho_v; k++) {
      if (ComparaDataNasc(v[k], v[pmv]) == 1) pmv = k;
    }
 
    t = v[i];
    v[i] = v[pmv];
    v[pmv] = t;
  }
}