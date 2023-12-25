#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//declaracoes de estruturas usadas para montar o estoque
typedef struct _no {
   double preco;
   int qtd, cat;
   char * nome;
   struct _no * prox;
   struct _no * ant;
} No;

typedef struct _lista { //estrutura da lista que inclui além do nó, o tamanho da tal
   No * inicio, * fim;
   int tamanho;
} Lista;

// declaração de funções que serão utilizadas na main
void menu(void);
Lista * criar_lista_vazia(void);
No * criar_no(double p, int q, int c, char *nome);
void add_no_final(Lista * lista, No * no);
void remover_elemento(Lista * lista, char * nome);
No * buscar(Lista *lista);
void ordenacao_preco(Lista * lista);
void ordena_preco_cres(Lista * lista);
void ordena_preco_dec(Lista * lista);
void add_produto(Lista *lista_geral, Lista * vetor[]);
void imprimir (Lista *lista);
void remover_produto(Lista * lista_geral, Lista * vetor[]);
void valor_da_compra(Lista * lista);
