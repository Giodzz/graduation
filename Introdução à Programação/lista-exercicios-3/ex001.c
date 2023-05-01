#include <stdio.h>
void fill_vetor(int * vetor, int qtd_elementos);
int procurar_no_vetor(int * vetor, int tamanho, int n);

int main() {


    int N, m, num, achei, c;
    int v[100000];
    scanf("%d", &N);
    fill_vetor(v, N);
    scanf("%d", &m);
    for (c=0; c<m; c++) {
        scanf("%d", &num);
        achei = procurar_no_vetor(v, N, num);
        if (achei >= 1) printf("ACHEI\n");
        else printf("NAO ACHEI\n");
    }

    return 0;
}

void fill_vetor(int * vetor, int qtd_elementos) {
    int i;
    for (i=0; i < qtd_elementos; i++) {
        scanf("%d", &vetor[i]);
    }

}

int procurar_no_vetor(int * vetor, int tamanho, int num) {
    int i, achei = 0;
    for (i=0; i<tamanho; i++) {
        if (num == vetor[i]) achei++;
    }
    return achei;
}