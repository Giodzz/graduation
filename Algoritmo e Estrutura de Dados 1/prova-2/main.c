#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char rota; //rota = direita ou esquerda
    char * local; 
    struct no *prox;
    struct no *ant;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int tam;
}Lista;

Lista * criar_lista(void);
void inserir_fim(Lista *lista, char r, char l[]);
void imprimir(Lista *lista);
void escrever_extenso_caixa_alta(char* num_str);

int main(){
    char r, l[4];
    Lista *lista = criar_lista();

    do{
        scanf("(%c, %[^)])%*c", &r, l);
        inserir_fim(lista, r, l);
    }while(l[0] != 'e'); //'e' representa que ela chegou na escola

    imprimir(lista);

    return 0;
}

Lista * criar_lista(void) {
   // criar lista vazia
   Lista * lista = NULL;
   lista = (Lista *) malloc(sizeof(Lista));

   if (lista == NULL) return NULL; // não conseguiu alocar a memória

   lista->inicio = NULL;
   lista->fim = NULL;
   lista->tam = 0;

   return lista;
}

//inserir elemento no fim da lista
void inserir_fim(Lista *lista, char r, char l[]){ //r = rota, l = local
    No * novo = NULL;
    novo = malloc(sizeof(No));
    novo->local = malloc(4*sizeof(char));
    No *aux;

    if(novo){
        // criar novo no
        novo->rota = r;
        strcpy(novo->local, l);
        novo->prox = NULL;

        if(lista->inicio == NULL){ //lista vazia
            lista->inicio = novo;
            novo->ant = NULL;
        }
        else{
            aux = lista->inicio;
            while(aux->prox) //levando o auxiliar para o final da lista
                aux = aux->prox;

            aux->prox = novo;
            novo->ant = aux;
        }
        lista->fim = novo;
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void imprimir(Lista *lista){
    No *no = lista->fim;

    if(no == NULL){
        printf("Lista vazia\n");
        return;
    }
    
    while(no != lista->inicio){ // no->ant != NULL
        if(no->rota == 'd')
            printf("Vire a ESQUERDA na rua ");
        else
            printf("Vire a DIREITA na rua ");
        
        if(no->ant->local[0] == 'r') {
            no->ant->local[0] = 'R';
            printf("%s\n", no->ant->local);
        } else if(no->ant->local[0] == 'p') {
            printf("PRINCIPAL\n");
        } else {
            escrever_extenso_caixa_alta(no->ant->local);
        }        
        no = no->ant;
    }
    if(no->rota == 'd')
        printf("Vire a ESQUERDA na sua CASA\n");
    else
        printf("Vire a DIREITA na sua CASA\n");
}

void escrever_extenso_caixa_alta(char* num_str) {
    int amigo;

    amigo = strlen(num_str);
    if(amigo == 3){ 
        printf("CEM\n");
        return;
    }
    

    int num = atoi(num_str);
    if (num < 0 || num > 100) {
        printf("O numero deve estar entre 0 e 100.\n");
        return;
    }

    char *extenso[] = {"ZERO", "UM", "DOIS", "TRÊS", "QUATRO", "CINCO", "SEIS", "SETE", "OITO", "NOVE", "DEZ", "ONZE", "DOZE", "TREZE", "CATORZE", "QUINZE", "DEZESSESEIS", "DEZESSETE", "DEZOITO", "DEZENOVE"};

    if (num <= 19) {
        printf("%s\n", extenso[num]);
    } else {
        char *dezenas[] = {"VINTE", "TRINTA", "QUARENTA", "CINQUENTA", "SESSENTA", "SETENTA", "OITENTA", "NOVENTA"};
        printf("%s ", dezenas[num / 10 - 2]);
        if (num % 10 != 0) {
            printf("E %s\n", extenso[num % 10]);
        } else {
            printf("\n");
        }
    }
}
