#include <stdio.h>
#include <math.h>
double my_factorial(int n);

int main() {

    int N, n; 
    double x, cos;
    scanf("%lf%d", &x, &N);

    for(n = 0; n <= N; n++) {
        cos += ((pow(-1, n) * pow(x, (2*n)))) / (my_factorial(2*n));
    }

    printf("cos(%.2lf) = %.6lf\n", x, cos);
    return 0;
}

double my_factorial(int n) {
    int i, fat = 1;
    for (i = 1; i <= n; i++) {
        fat *= i;
    }

    return fat;
}