#include <stdio.h>
void fill_vetor(int * vetor);
void verdadeiros_anoes(int * vetor, int * vetor_s);
void ordenar_vetor(int * vetor, int tamanho_v);

int main() {

    int n_testes, i;
    int nove[9], sete[7];
    scanf("%d", &n_testes);

    while (n_testes--) {
        fill_vetor(nove);
        verdadeiros_anoes(nove, sete);
        ordenar_vetor(sete, 7);
        for (i=0; i<7; i++) {
            printf("%d\n", sete[i]);
        }
    }

    return 0;
}

void fill_vetor(int * vetor) {
    int i;
    int soma = 0;
    for (i=0; i<9; i++) {
        scanf("%d", &vetor[i]);
    }
}

void verdadeiros_anoes(int * vetor, int * vetor_s) {
    int i, k, c=0;
    int a1, a2;
    int soma = 0, resto = 0;

    for (i=0; i<9; i++) {
        soma += vetor[i];
    }

    resto = soma-100;
    for (i=0; i<8; i++) {
        for (k=i+1; k<9; k++) {
            if (vetor[i] + vetor[k] == resto) {
                a1 = i;
                a2 = k;
            }
        }
    }

    for (i=0; i<9; i++) {
        if (vetor[i] == vetor[a1] || vetor[i] == vetor[a2]) continue;
        vetor_s[c] = vetor[i];
        c++;
    }
}

void ordenar_vetor(int * vetor, int tamanho_v) {
    int i, k, pm, t;
    for (i=0; i<tamanho_v-1; i++) {
        pm = i;
        for (k=i+1; k<tamanho_v; k++) {
            if (vetor[k] < vetor[pm]) pm = k;
        }

        t = vetor[i];
        vetor[i] = vetor[pm];
        vetor[pm] = t;
    }
}