#include <stdio.h>
 
int main() {
    float f, c, p, mm;
 
    scanf("%f%f", &f, &p);
    
    c = (5 * (f - 32))/9;
    mm = 25.4 * p;
 
    printf("O VALOR EM CELSIUS = %.2f\n", c);
    printf("A QUANTIDADE DE CHUVA E = %.2f", mm);  
 
    return 0;
}