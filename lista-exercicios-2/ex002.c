#include <stdio.h>
/**
 * Calcula o n-ésimo termo da sequência de Fibonacci 
 * @param t1: primeiro termo da sequência
 * @param t2: segundo termo da sequência
 * @param n: a posição do termo da sequência
 * @return int: o valor do n=ésimo termo da sequência
 */
int fibonacci(int t1, int t2, int n);

int main() {

    int t1, t2, n, tn;
    scanf("%d %d %d", &t1, &t2, &n);
    tn = fibonacci(t1, t2, n);
    printf("%d\n", tn);

    return 0;
}

int fibonacci(int t1, int t2, int n) {
    int i, tn;
    int ts1 = t1 + t2, ts2 = t2;
    switch (n) {
        case 1:
            tn = t1;
            break;
        case 2:
            tn = t2;
            break;
        case 3:
            tn = t1 + t2;
            break;
    }
    for (i=4; i<= n; i++) {
        tn = ts1 + ts2;
        ts2 = ts1;
        ts1 = tn;
    }
    return tn;
}