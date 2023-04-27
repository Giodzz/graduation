#include <stdio.h>
 
int main() {
 
    int num, dm, um, c, d, u;
 
    scanf("%d", &num);
 
    if (num >= 100000) {
        printf("NUMERO INVALIDO");
    } else if (num >= 10000) {
        dm = num / 10000;
        um = (num % 10000) / 1000;
        c = (num % 1000) / 100;
        d = (num % 100) / 10;
        u = (num % 10);
 
        if (dm == u && um == d) {
            printf("PALINDROMO");
        } else {
            printf("NAO PALINDROMO");
        }
    } else if (num >= 1000) {
        um = num / 1000;
        c = (num % 1000) / 100;
        d = (num % 100) / 10;
        u = (num % 10);
 
        if (um == u && c == d) {
            printf("PALINDROMO");
        } else {
            printf("NAO PALINDROMO");
        }
    } else if (num >= 100) {
        c = num / 100;
        d = (num % 100) / 10;
        u = (num % 10);
 
        if (c == u) {
            printf("PALINDROMO");
        } else {
            printf("NAO PALINDROMO");
        }
    } else if (num >= 10) {
        d = num / 10;
        u = (num % 10);
 
        if (d == u) {
            printf("PALINDROMO");
        } else {
            printf("NAO PALINDROMO");
        }
    } else if (num >= 0) {
        printf("PALINDROMO");
    }
 
    return 0;
}
