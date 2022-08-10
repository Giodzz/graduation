// Fatorial

#include <stdio.h>

int main() {

    int n, i;

    unsigned long int fat = 1;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        fat *= i;
    }

    printf("%d! = %lu\n", n, fat);
    return 0;
}