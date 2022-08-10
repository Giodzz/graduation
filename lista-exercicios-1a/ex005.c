#include <stdio.h> 
 
 
int main() {
    float n1, n2, n3, maior, menor, meio;
    scanf("%f%f%f", &n1, &n2, &n3);
 
    if (n1 <= n2 && n2 <= n3) {
        maior = n3,
        meio = n2,
        menor = n1;
    } else if (n1 <= n3 && n3 <= n2) {
        maior = n2,
        meio = n3,
        menor = n1;
    } else if (n2 <= n1 && n1 <= n3) {
        maior = n3,
        meio = n1,
        menor = n2;
    } else if (n2 <= n3 && n3 <= n1) {
        maior = n1,
        meio = n3,
        menor = n2;
    } else if (n3 <= n1 && n1 <= n2) {
        maior = n2,
        meio = n1,
        menor = n3;
    } else if (n3 <= n2 && n2 <= n1) {
        maior = n1,
        meio = n2,
        menor = n3;
    }
    printf("%.2f, %.2f, %.2f", menor, meio, maior);
    return 0;
}
 
 
// prof version
// a b c
/*
int main() {
    int a, b, c, t;
    scanf("%d", &a);
    scanf("%d", &b);
 
    if (b < a) {
        t = a;
        a = b;
        b = t;
    }
 
    scanf("%d", &c);
    if (c < a) {
        t = c;
        c = b;
        b = a;
        a = t;
    } else if (c < b) {
        t = c;
        c = b;
        b = t;
    }
 
    printf("%d, %d, %d\n", a, b, c);
}
*/