#include <stdio.h>

int main() {

    double n, rk = 0, rant = 1;
    double e, en = 1;
    scanf("%lf%lf", &n, &e);
    while (en > e) {
        rk = (rant + (n/rant)) / (2.0);
        en = n - (rk*rk);
        if (en < 0) en *= -1;
        printf("r: %.9lf, err: %.9lf\n", rk, en);
        rant = rk;
    }
    

    return 0;
}
