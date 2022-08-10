#include <stdio.h>
int somaDivisores(int n);

int main() {

    int n, soma, i;
    scanf("%d", &n);
    soma = somaDivisores(n);
    
    printf("%d = ", n);
    for (i = 1; i <= n/2; i++) {
        if (n%i == 0) {
            if (i != 1) printf("+ %d ", i);
            else printf("%d ", i);
        }
        
    }

    printf("= %d ", soma);
    if (soma == n) printf("(NUMERO PERFEITO)\n");
    else printf("(NUMERO NAO E PERFEITO)\n");

    return 0;
}

int somaDivisores(int n) {
    int divisor, soma = 0;
    for (divisor = 1; divisor < n; divisor++) {
        if (n%divisor == 0) soma += divisor;
    }
    return soma;
}