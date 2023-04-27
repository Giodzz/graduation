#include <stdio.h>
 
int main() {
 
    int a, b, c, d;
    float det;
    scanf("%d\n%d\n%d\n%d", &a, &b, &c, &d);
 
    det = a*d - b*c;
 
    printf("O VALOR DO DETERMINANTE E = %.2f", det);
    return 0;
}
