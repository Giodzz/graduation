#include <stdio.h>
#include <string.h>
void separar_numeros(char * vetor, int tamanho);

int main() {

    int n_testes, i, tamanho;
    int leds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    char v[1000];

    scanf("%d%*c", &n_testes);
    for (i=0; i<n_testes; i++) {
        memset(v, 0, 1000*sizeof(char));
        scanf("%[^\n]%*c", &v);
        tamanho = strlen(v);
        separar_numeros(v, tamanho);
        //contar_leds
    }
    

    return 0;
}

void separar_numeros(char * vetor, int tamanho) {
    int i, * a;
    for (i=0; i<tamanho; i++) {
        printf("%c\n", vetor[i]);
        a = (int)vetor[i];
        printf("%d\n", a);
    }

    for (i=0; i<tamanho; i++) {
        a[i] = (int) a[i];
        printf("%d\n", a[i]);
    }
    
}

/*
int contar_leds() {
    int i;
    for (i=0; i< ; i++) {

    }
}
*/