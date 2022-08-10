#include <stdio.h>
 
int main() {
 
    float delta, a, b, c;
    scanf("%f\n", &a);
    scanf("%f\n", &b);
    scanf("%f\n", &c);
 
    delta = (b*b) - (4*a*c);
 
    printf("O VALOR DE DELTA E = %.2f\n", delta);
 
    return 0;
}