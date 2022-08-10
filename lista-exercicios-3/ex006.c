#include <stdio.h>
#include <string.h>
int check_one(char * vetor, int tamanho_v);
int check_two(char * vetor, int tamanho_v);
int check_three(char * vetor, int tamanho_v);

int main() {

    int n_testes, i;
    char word[1000];
    scanf("%d%*c", &n_testes);

    for (i=0; i<n_testes; i++) {
        memset(word, 0, 1000*sizeof(char));
        scanf("%[^\n]%*c", word);
        check_one(word, strlen(word));
        check_two(word, strlen(word));
        check_three(word, strlen(word));
    } 

    return 0;
}

int check_one(char * vetor, int tamanho_v) {
    int i;
    int total_erros = 0;
    char one[4] = {"one"};

    if (tamanho_v == 3) {
        for (i=0; i<tamanho_v; i++) {
            if (vetor[i] != one[i]) total_erros++;
        }

        if (total_erros <= 1) {
            printf("1\n");
            return 1;
        } else return 0;
    } else return 0;
}

int check_two(char * vetor, int tamanho_v) {
    int i;
    int total_erros = 0;
    char two[4] = {"two"};
    
    if (tamanho_v == 3) {
        for (i=0; i<tamanho_v; i++) {
            if (vetor[i] != two[i]) total_erros++;
        }

        if (total_erros <= 1) {
            printf("2\n");
            return 1;
        } else return 0;
    } else return 0;
}

int check_three(char * vetor, int tamanho_v) {
    int i;
    int total_erros = 0;
    char three[6] = {"three"};

    if (tamanho_v == 5) {
        for (i=0; i<tamanho_v; i++) {
            if (vetor[i] != three[i]) total_erros++;
        }

        if (total_erros <= 1) {
            printf("3\n");
            return 1;
        } else return 0;
    } else return 0;

}