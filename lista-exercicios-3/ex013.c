// ex013
#include <stdio.h>
#include <string.h>

int main() {
    char str[100000];
    int size;
    int i = 10;
    int f = 12;
    char V[500];

    while (i <= f) {
        sprintf(V, "%d", i);
        strcat(str, V); // pode usar sprintf(&V[2], "%d", 10) -> mostra onde vai começar a printar o valor
        i++;
    }

    size = strlen(str);

    for (i=0; i<size; i++) {
        str[size*2 - 1 - i] = str[i];
    }
    str[size*2] = '\0';

    printf("%s\n", str);
}

void espelhar(char * str) {
    int i;
    int s = strlen(str);

    for (i=0; i<s; i++) {
        str[s*2-1-i] = str[i];
    }

    str[s*2] = '\0';
}

void seq(char * v, int i, int f) {
    int n;
    int p = 0;

    while (i <= f) {
        n = sprintf(&v[p], "%d", 100);
        p+=n;
        i++;
    }
}