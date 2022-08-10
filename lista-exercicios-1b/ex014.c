#include <stdio.h>

int main() {

    int n, d, soma = 0;
    scanf("%d", &n);

    printf("%d = ", n);
    for (d = 1; d < n; d++) {
        if (n % d == 0) {
            soma += d;
            
            if (d != 1) printf("+ %d ", d);
            else printf("%d ", d);
        }
    }

    
    if(n == soma) printf("= %d (NUMERO PERFEITO)\n", soma);
    else printf("= %d (NUMERO NAO E PERFEITO)\n", soma);
    return 0;
}

