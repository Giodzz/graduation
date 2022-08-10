#include <stdio.h>
#include <string.h>
void criptografar(char * vetor, int tamanho_v, int pos_d, int pos_esq);
void mudar_posicoes_direita(char * vetor, int tamanho_v, int n_posicoes);
void inverter(char * vetor, int tamanho_v);
void mudar_posicoes_esquerda(char * vetor, int tamanho_v, int n_posicoes);



int main() {

    int n_testes, i;
    char string[1000];
    scanf("%d%*c", &n_testes);

    for (i=0; i<n_testes; i++) {
        memset(string, 0, 1000*sizeof(char));
        scanf("%[^\n]%*c", string);
        criptografar(string, strlen(string), 3, 1);
        printf("%s\n", string);
    }

    return 0;
}

void criptografar(char * vetor, int tamanho_v, int pos_dir, int pos_esq) {
    mudar_posicoes_direita(vetor, tamanho_v, pos_dir);
    inverter(vetor, tamanho_v);
    mudar_posicoes_esquerda(vetor, tamanho_v, pos_esq);

}

void mudar_posicoes_direita(char * vetor, int tamanho_v, int n_posicoes) {
    int i;

    for (i=0; i<tamanho_v; i++) {
        if (vetor[i] >= 65 && vetor[i] <= 122) vetor[i] = (char) (vetor[i] + n_posicoes);
    }
}

void inverter(char * vetor, int tamanho_v) {
    int i;
    //char t;
    char array_aux[tamanho_v + 1];
    int c = tamanho_v - 1;
    
    /*
    for (i=0; i<tamanho_v; i++) {
        t = vetor[i];
        vetor[i] = vetor[c];
        vetor[c] = t;
        c--;
    }
    */

    for (i=0; i<tamanho_v; i++) {
        array_aux[i] = vetor[c];
        c--;
    }

    for (i=0; i<tamanho_v; i++) {
        vetor[i] = array_aux[i];
    }

}

void mudar_posicoes_esquerda(char * vetor, int tamanho_v, int n_posicoes) {
    int i;

    for (i=0; i<tamanho_v; i++) {
        if (i >= (strlen(vetor)/2)) vetor[i] = (char) (vetor[i] - n_posicoes);
    }
}