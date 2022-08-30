#include <stdio.h>
#include <string.h>

void fill_vetor(int * vetor, int tamanho_v);
int freq_ultimo_el(int * vetor, int tamanho_v);
void maior_valor(int * vetor, int tamanho_v, int * mValor_indice);


int main() {

    int n_notas, i, freq;
    int notas[10000];
    int maior[2];
    scanf("%d", &n_notas);

    fill_vetor(notas, n_notas);

    freq = freq_ultimo_el(notas, n_notas);
    printf("Nota %d, %d vezes\n", notas[n_notas-1], freq);

    maior_valor(notas, n_notas, maior);
    printf("Nota %d, indice %d\n", maior[0], maior[1]);

    return 0;
}

void fill_vetor(int * vetor, int tamanho_v) {
    int i;
    for (i=0; i<tamanho_v; i++) {
        scanf("%d", &vetor[i]);
    }
}

int freq_ultimo_el(int * vetor, int tamanho_v) {
    int i;
    int freq = 0;
    int ultimo_el = vetor[tamanho_v-1];
    for (i=0; i<tamanho_v; i++) {
        if (vetor[i] == ultimo_el) freq++;
    }

    return freq;
}

void maior_valor(int * vetor, int tamanho_v, int * mValor_indice) {
    int i, maior = 0;
    memset(mValor_indice, 0, 2*sizeof(int));
    for (i=0; i<tamanho_v; i++) {
        if (vetor[i] > maior) {
            mValor_indice[0] = vetor[i];
            maior = vetor[i];
        }
    }

    for (i=0; i<tamanho_v; i++) {
        if (vetor[i] == maior) {
            mValor_indice[1] = i;
            break;
        }
    }
}