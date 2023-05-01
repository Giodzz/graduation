#include <stdio.h>
void fill_vetor(int * vetor, int tamanho_v);
void ordenar_vetor(int * vetor, int tamanho_v);
void juntar_vetores(int * v1, int * v2, int * v3, int q1, int q2);


int main() {

    int q1, q2, i;
    int v1[500000], v2[500000], v3[1000000];
    scanf("%d%d", &q1, &q2);
    
    
    int q3 = q1+q2;
    fill_vetor(v1, q1);
    fill_vetor(v2, q2);

    juntar_vetores(v1, v2, v3, q1, q2);

    ordenar_vetor(v3, q3);
    for (i=0; i<q3; i++) {
        printf("%d\n", v3[i]);
    }


    return 0;
}

void fill_vetor(int * vetor, int tamanho_v) {
    int i;
    for (i=0; i<tamanho_v; i++) {
        scanf("%d", &vetor[i]);
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


void juntar_vetores(int * v1, int * v2, int * v3, int q1, int q2) {
    int i, k;
    for (i=0; i<q1; i++) {
        v3[i] = v1[i];
    }

    for(i=0; i<q2; i++) {
        v3[q1+i] = v2[i];
    }
}