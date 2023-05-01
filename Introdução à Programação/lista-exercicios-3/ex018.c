#include <stdio.h>
#include <string.h>

int main() {

    int i;
    char str[51], l_ant;

    memset(str, 0, 51*sizeof(char));
    while (scanf("%[^\n]%*c", str) != EOF) { // ate acabar o arquivo
        for (i=0; i<strlen(str); i++) {
            if (i!=0) {
                if (l_ant>='A' && l_ant<='Z') {
                    if (str[i]>='A' && str[i]<='Z') str[i] = str[i] + 32;
                } else if (l_ant>='a' && l_ant<='z') {
                    if (str[i]>='a' && str[i]<='z') str[i] = str[i] - 32;
                }
            } else {
                if (str[i]>='a' && str[i]<='z') str[i] = str[i] - 32;
            }
            
            if (str[i] != ' ') l_ant = str[i];
        }

        printf("%s\n", str);
    }

    return 0;
}