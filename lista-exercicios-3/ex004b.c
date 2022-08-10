#include <stdio.h>
#include <string.h>
void separar_numeros(char * vetor, int tamanho);

int main() {

    int n_testes, i, tamanho;
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

int contar_leds(char * vetor, int tamanho) {
    int i, * a, soma_leds=0;
    int leds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    for (i=0; i<tamanho; i++) {
        printf("%c\n", vetor[i]);
        a = (int) vetor[i];
        printf("%c\n", a);
        //soma_leds += leds[*a];  
    }
    //printf("%d", soma_leds);
    return soma_leds;
}

/*
int contar_leds() {
    int i;
    for (i=0; i< ; i++) {

    }
}
*/