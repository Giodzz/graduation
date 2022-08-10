#include <stdio.h>
void fill_vetor(int * vetor, int tamanho_v);
void ordenar_vetor(int * vetor, int tamanho_v);
double find_mediana(int * vetor, int tamanho_v);

int main() {

    int n_elementos, i, v[1000000];
    double mediana;
    scanf("%d", &n_elementos);

    fill_vetor(v, n_elementos);
    ordenar_vetor(v, n_elementos);
    mediana = find_mediana(v, n_elementos);
    printf("%.2lf\n", mediana);
    
    return 0;
}

void fill_vetor(int * vetor, int tamanho_v) {
    int i;
    for(i=0; i<tamanho_v; i++) {
        scanf("%d", &vetor[i]);
    }
}

void ordenar_vetor(int * vetor, int tamanho_v) {
    int i, pm, t, k; // pm: posição do menor
    for (i=0; i<tamanho_v - 1; i++) {
        pm = i;
        for (k=i+1; k<tamanho_v; k++) {
            if (vetor[k] < vetor[pm]) pm = k;
        }

        t = vetor[i];
        vetor[i] = vetor[pm];
        vetor[pm] = t;
    }
}

double find_mediana(int * vetor, int tamanho_v) {
    int i;
    double mediana;
    if (tamanho_v%2==0) { // é par
        mediana = (vetor[tamanho_v/2] + vetor[tamanho_v/2 - 1])/2.0;
    } else {
        mediana = vetor[tamanho_v/2];
    }

    return mediana;
}