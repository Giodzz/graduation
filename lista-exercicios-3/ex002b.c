#include <stdio.h>
void fill_vetor(int * vetor, int tamanho);
int achar_maior_igual(int * vetor, int tamanho_v, int k);

int main() {
    
    int N, v[1000], k;
    
    do {
        printf("Tamanho do vetor: ");
        scanf("%d", &N);
    } while (N <= 0 || N >= 1000);
    
    fill_vetor(v, N);
    
    printf("Elemento de comparação: ");
    scanf("%d", &k);
    printf("%d elementos são maiores que ou iguais a %d\n", achar_maior_igual(v, N, k), k);
    
    return 0;
}

void fill_vetor(int * vetor, int tamanho_v) {
    int i;
    printf("Elementos do vetor:\n");
    for (i=0; i<tamanho_v; i++) {
        scanf("%d", &vetor[i]);
    }
}

int achar_maior_igual(int * vetor, int tamanho_v, int k) {
    int i, maior=0;
    for (i=0; i<tamanho_v; i++) {
        if (k <= vetor[i]) {
            maior++;
        }
    }
    
    return maior;
}