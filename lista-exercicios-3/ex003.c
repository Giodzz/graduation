#include <stdio.h>
void fill_vetor(int * vetor, int tamanho);
void mostrar_contrario(int * vetor, int tamanho);


int main() {
    
    int n, v[5000];
    
    scanf("%d", &n);
    fill_vetor(v, n);
    mostrar_contrario(v, n);
    
    return 0;
}

void fill_vetor(int * vetor, int tamanho_v) {
    int i;
    for (i=0; i<tamanho_v; i++) {
        scanf("%d", &vetor[i]);
    }
}

void mostrar_contrario(int * vetor, int tamanho) {
    int i;
    for (i=tamanho - 1; i>=0; i--) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}