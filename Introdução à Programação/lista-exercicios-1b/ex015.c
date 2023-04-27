#include <stdio.h>

int main() {

    int n, n1 = 1, d, soma1, soma2, c = 0;
    scanf("%d", &n);

    while (1) {
        soma1 = soma2 = 0;

        // divisores de n1
        for (d = 1; d <= n1/2; d++) {
            if (n1 % d == 0) soma1 += d;
        }

        for (d = 1; d <= soma1/2; d++) {
            if (soma1 % d == 0) soma2 += d;
        }

        if (soma2 == n1 && soma1 != n1 && n1 < soma1) {
            printf("(%d,%d)\n", n1, soma1);
            c++;
        }

        if (c == n) break;
        n1++;
        
    }

    return 0;
}
