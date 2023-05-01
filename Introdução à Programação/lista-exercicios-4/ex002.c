#include <stdio.h>

int main() {

    int n, l, c;
    int M[1000][1000];
    scanf("%d", &n);

    for (l=0; l<n; l++) {
        for (c=0; c<n; c++) {
            scanf("%d", &M[l][c]);
        }
    }

    c=n-1;
    for (l=0; l<n; l++) {
        printf("%d\n", M[l][c]);
        c--;
    }
    

    return 0;
}