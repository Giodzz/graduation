#include <stdio.h>
/**
 * Função que calcula o valor de pi usando a série proposta por John Wallis
 * @param n: quantidade de termos da série
 * @return double : o valor aproximado da constante pi
 */
double compute_pi(int n);

int main() {

    int n;
    double pi;
    scanf("%d", &n);
    pi = compute_pi(n);
    printf("%.12lf\n", pi);

    return 0;
}

double compute_pi(int n) {
    double numer = 2, denom = 1, pi = 1;
    int c=0, i;
    if (n!= 0) {
        while (1) { // denominador
            i = 1; 
            while (1) { // numerador
                pi = pi * (numer/denom);
                c++;
                if(c == n) break;
                if (denom == 1) break;
                if (i == 2) break;
                numer += 2;
                i++;
            }
            if(c == n) break;
            denom += 2;
        }
    }
    pi *= 2;
    return pi;
}
