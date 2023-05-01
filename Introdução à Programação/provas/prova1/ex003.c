// Validar Data

#include <stdio.h>

int main() {

    int dia, mes, ano, dias_mes;

    scanf("%d %d %d", &dia, &mes, &ano);

    
    if (ano >= 1900 && ano <= 2036) {
        // definindo quantidade de dias de cada mês
        switch (mes) {
            case 1:
                dias_mes = 31;
                break;
            
            case 2:
                if (ano%4 == 0) {
                    if (ano%400 == 0) {
                        // ano bissexto (fev 29 dias)
                        dias_mes = 29;
                    } else if (ano%100 == 0) {
                        // não é bissexto (fev 28 dias)
                        dias_mes = 28;
                    }
                } else {
                    dias_mes = 28;
                }
                break;

            case 3:
                dias_mes = 31;
                break;
            
            case 4:
                dias_mes = 30;
                break;

            case 5:
                dias_mes = 31;
                break;
            
            case 6:
                dias_mes = 30;
                break;

            case 7:
                dias_mes = 31;
                break;

            case 8:
                dias_mes = 31;
                break;

            case 9:
                dias_mes = 30;
                break;

            case 10:
                dias_mes = 31;
                break;

            case 11:
                dias_mes = 30;
                break;

            case 12:
                dias_mes = 31;
                break;

            default:
                // mes invalido
                printf("DATA INVALIDA\n");
        }

        if (dia <= dias_mes) {
            printf("%d/%d/%d\n", dia, mes, ano);
        } else {
            printf("DATA INVALIDA\n");
        }

    } else {
        printf("DATA FORA DO INTERVALO ESTIPULADO\n");
    }
    
    

    return 0;
}