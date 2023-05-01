#include <stdio.h>
#include <math.h>
int next_power(int n, int p);

int main() {

    int n, p;
    scanf("%d %d", &n, &p);
    next_power(n, p);

    return 0;
}


int next_power(int n, int p) {
    int maior_power = 1, power, base = 1;
    if(p != 0) {
        while (1) {
            power = pow(base, p);
            if (power > maior_power) maior_power = power;
            if (pow(base+1, p) > n) { // maior potencia
                if ((pow(base+1, p) - n) < (n - maior_power)) {
                    maior_power = pow(base+1, p);
                    base++;
                }
                
                break;
            }

            base ++;
        }
    }

    printf("%d -> %d^%d = %d\n", n, base, p, maior_power);
    
    return maior_power;
}
