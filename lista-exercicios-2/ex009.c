#include <stdio.h>
void converteEmNotasMoedas(int n, int * cem, int * cinq, int * dez, int * um);

int main() {

    int n_reais, notas_100, notas_50, notas_10, notas_1;
    scanf("%d", &n_reais);
    converteEmNotasMoedas(n_reais, &notas_100, &notas_50, &notas_10, &notas_1);
    printf("NOTAS DE 100 = %d\n", notas_100);
    printf("NOTAS DE 50 = %d\n", notas_50);
    printf("NOTAS DE 10 = %d\n", notas_10);
    printf("MOEDAS DE 1 = %d\n", notas_1);


    return 0;
}

void converteEmNotasMoedas(int n, int * cem, int * cinq, int * dez, int * um) {
    *cem = n/100;
    *cinq = (n%100) / 50; 
    *dez = (n%50)/10;
    *um = n%10;
}