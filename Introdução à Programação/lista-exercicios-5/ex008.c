#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct {
  int codigo;
  double val_credito;
  char * nome;
} Curso;
 
typedef struct {
  char * nome;
  int codigo;
  int qtd_credito;
} Aluno;
 
int main() {
 
  int qtd_cursos, qtd_alunos, i, k, r;
  double mens;
  char nome[1000];
  Curso * cursos = NULL; // vetor de cursos
  Aluno * alunos = NULL;
 
  // Entrada das informações dos cursos
  scanf("%d", &qtd_cursos);
  cursos = (Curso *) malloc(qtd_cursos*sizeof(Curso));
 
  for (i=0; i<qtd_cursos; i++) {
    scanf("%d\n", &cursos[i].codigo);
    scanf("%lf\n", &cursos[i].val_credito);
    scanf("%[^\n]%*c", &nome);
    cursos[i].nome = (char *) malloc((strlen(nome)+1)*sizeof(char));
    strcpy(cursos[i].nome, nome);
  }
 
  // Entrada das informações dos alunos
  scanf("%d%*c", &qtd_alunos);
  alunos = (Aluno *) malloc(qtd_alunos*sizeof(Aluno));
 
  for (i=0; i<qtd_alunos; i++) {
    scanf("%[^\n]%*c", &nome);
    scanf("%d\n", &alunos[i].codigo);
    scanf("%d\n", &alunos[i].qtd_credito);
    alunos[i].nome = (char *) malloc((strlen(nome)+1)*sizeof(char));
    strcpy(alunos[i].nome, nome);
  }
 
  //Ver de qual curso cada pessoa é e printar as informações
  for (i=0; i<qtd_alunos; i++) {
    for (k=0; k<qtd_cursos; k++) {
      if (alunos[i].codigo == cursos[k].codigo) {
        mens = alunos[i].qtd_credito*cursos[k].val_credito;
        printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %.2lf Mensalidade: %.2lf\n", alunos[i].nome, cursos[k].nome, alunos[i].qtd_credito, cursos[k].val_credito, mens);
      }
    } 
  }
 
  for (i=0; i<qtd_alunos; i++) free(alunos[i].nome);
  for (i=0; i<qtd_cursos; i++) free(cursos[i].nome);
  free(alunos);
  free(cursos);
  return 0;
}