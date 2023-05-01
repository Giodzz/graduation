#include <stdio.h>
#include <string.h>
int contar_leds(char * vetor, int tamanho);
 
int main() {
 
    int n_testes, i, tamanho;
    char v[1000];
 
    scanf("%d%*c", &n_testes);
    for (i=0; i<n_testes; i++) {
        memset(v, 0, 1000*sizeof(char)); // zera o vetor
        scanf("%[^\n]%*c", v);
        tamanho = strlen(v);
        contar_leds(v, tamanho);
    }
    
 
    return 0;
}
 
int contar_leds(char * vetor, int tamanho) {
    int i, soma_leds=0;
    int leds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    for (i=0; i<tamanho; i++) {
        soma_leds += leds[vetor[i] - 48];  
    }
    printf("%d leds\n", soma_leds);
    return soma_leds;
}