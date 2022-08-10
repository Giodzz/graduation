// Somatório Simples

#include <stdio.h>

int main() {
    int k, n;
    double soma;

    scanf("%d", &n);

    if (n > 1) {
        for (k = 1; k <= n; k++) {
            soma += 1.0/k;
        }
        printf("%.6lf", soma);
    } else {
        printf("Numero invalido!");
    }

    
    return 0;
}