#include <stdio.h>

int main() {

    int i, tamanho, n = 0, nant = 0, c = 0, cmaior = 0;
    
    scanf("%d", &tamanho);
    for(i = 1; i <= tamanho; i++) {
        scanf("%d", &n);
        if (n > nant){
            c += 1;
            if (c > cmaior) cmaior = c;
        } else {
            c = 1;
        }
        nant = n;
    }

    printf("O comprimento do segmento crescente maximo e: %d", cmaior);

    return 0;
}