#include <stdio.h>
void fill_vetor(int * vetor, int tamanho_v);
int check_maior(int * vetor, int tamanho_v);
int freq_menor_i(int * vetor, int tamanho_v, int referencia);

int main() {

    int n_elementos, maior;
    int array[10000];

    while (1) {
        scanf("%d", &n_elementos);
        if(n_elementos == 0) break;
        fill_vetor(array, n_elementos);
        maior = check_maior(array, n_elementos);
        freq_menor_i(array, n_elementos, maior);
    }

    return 0;
}

void fill_vetor(int * vetor, int tamanho_v) {
    int i;

    for (i=0; i<tamanho_v; i++) {
        scanf("%d", &vetor[i]);
    }    
}

int check_maior(int * vetor, int tamanho_v) {
    int i, maior = 0;

    for (i=0; i<tamanho_v; i++) {
        if (vetor[i] >= maior) maior = vetor[i];
    }

    return maior;
}

int freq_menor_i(int * vetor, int tamanho_v, int referencia) {
    int i, c, freq;

    for (i=0; i<=referencia; i++) {
        freq = 0;
        for (c=0; c<tamanho_v; c++) {
            if (vetor[c] <= i) freq++;
        }
        printf("(%d) %d\n", i, freq);
    }
}