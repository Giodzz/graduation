#include <stdio.h>

int main() {

    
    int N, k, i, j, qtd_finais = 1;
    scanf("%d", &N);

    //qtd_finais = (N*(N-1))/2;
    
    if (N > 1) {
        for (i = 1; i < N; i++) {
            for (j = i + 1; j < N + 1; j++) {
                printf("Final %d: Time%d X Time%d\n", qtd_finais, i, j);
                qtd_finais++;
            }
        }
    } else {
        printf("Campeonato invalido!");
    }
    return 0;
}