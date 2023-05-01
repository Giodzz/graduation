#include <stdio.h>

int main() {

    int a, b, c, d;
    double det;
    
    scanf("%d %d %d %d", &a, &b, &c, &d);
    det = a*d - b*c;

    printf("%.2lf\n", det);
    return 0;
}