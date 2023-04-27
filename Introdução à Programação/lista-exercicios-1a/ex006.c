// compilar: gcc ex006.c -o prog -lm
 
#include <stdio.h>
#include <math.h>
 
int main() {
    float a, b, c, delta, d, x1, x2, menor, maior;
    scanf("%f %f %f", &a, &b, &c);
 
    delta = b*b - 4*a*c;
    d = sqrt(delta);
    x1 = (-b - d) / (2*a);
    x2 = (-b + d) / (2*a);
    
    if (x1 < x2) {
        menor = x1;
        maior = x2;
    } else {
        menor = x2;
        maior = x1;
    }
 
    if (delta == 0) {
        printf("RAIZ UNICA\n");
        printf("X1 = %.2f", x2);
    } else if (delta < 0) {
        printf("RAIZES IMAGINARIAS\n");
    } else if (delta > 0) {
        printf("RAIZES DISTINTAS\n");
        printf("X1 = %.2f\n", menor);
        printf("X2 = %.2f", maior);
    }
 
    return 0;
}
