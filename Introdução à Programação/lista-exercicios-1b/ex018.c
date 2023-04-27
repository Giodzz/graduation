#include <stdio.h>

int main() {

    int num = 0, i;
    scanf("%d", &num);
    while (num <= 1) {
        printf("Fatoracao nao e possivel para o numero %d!", num);
        scanf("%d", &num);
    }

    return 0;
}
