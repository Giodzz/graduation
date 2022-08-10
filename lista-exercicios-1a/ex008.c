#include <stdio.h>
 
int main() {
    int n, c, d, u;
    scanf("%d", &n);
    c = n / 100;
    d = (n % 100) / 10;
    u = (n % 10);
    printf("%d%d%d\n", u, d, c);
 
    return 0;
}