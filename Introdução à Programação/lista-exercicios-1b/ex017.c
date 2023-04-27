#include <stdio.h>
#include <math.h>
double my_factorial(int n);

int main() {

    int N, n;
    double x, e = 0;
    scanf("%lf%d", &x, &N);
    
    for (n = 0; n <= N; n++) {
        e += pow(x, n) / my_factorial(n);
    }
    
    printf("e^%.2lf = %.6lf\n", x, e);

    return 0;
}

double my_factorial(int n) {
    int i, fat = 1;
    for (i = 1; i <= n; i++) {
        fat *= i;
    }

    return fat;
}
