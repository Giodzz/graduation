#include <stdio.h>

int main() {

    int n, m, d, impar = 1;
    scanf("%d", &n);

    for (m = 1; m <= n; m++) {
        printf("%d*%d*%d = ", m, m, m);
        for (d = 1; d <= m; d ++) {
            printf("%d", impar);
            impar += 2;
            if (d+1 <= m) printf("+");
            else printf("\n");
        }
    }
    
    return 0;
}