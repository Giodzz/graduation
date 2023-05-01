#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct {
  char pais[15];
  char msg[25];
} MP;
 
 
int main() {
 
  MP x[24] = {
    {.pais = "brasil", .msg = "Feliz Natal!"},
    {.pais = "alemanha", .msg = "Frohliche Weihnachten!"},
    {.pais = "austria", .msg = "Frohe Weihnacht!"},
    {.pais = "coreia", .msg = "Chuk Sung Tan!"},
    {.pais = "espanha", .msg = "Feliz Navidad!"},
    {.pais = "grecia", .msg = "Kala Christougena!"},
    {.pais = "estados-unidos", .msg = "Merry Christmas!"},
    {.pais = "inglaterra", .msg = "Merry Christmas!"},
    {.pais = "australia", .msg = "Merry Christmas!"},
    {.pais = "portugal", .msg = "Feliz Natal!"},
    {.pais = "suecia", .msg = "God Jul!"},
    {.pais = "turquia", .msg = "Mutlu Noeller"},
    {.pais = "argentina", .msg = "Feliz Navidad!"},
    {.pais = "chile", .msg = "Feliz Navidad!"},
    {.pais = "mexico", .msg = "Feliz Navidad!"},
    {.pais = "antardida", .msg = "Merry Christmas!"},
    {.pais = "canada", .msg = "Merry Christmas!"},
    {.pais = "irlanda", .msg = "Nollaig Shona Dhuit!"},
    {.pais = "belgica", .msg = "Zalig Kerstfeest!"},
    {.pais = "italia", .msg = "Buon Natale!"},
    {.pais = "libia", .msg = "Buon Natale!"},
    {.pais = "siria", .msg = "Milad Mubarak!"},
    {.pais = "marrocos", .msg = "Milad Mubarak!"},
    {.pais = "japao", .msg = "Merii Kurisumasu!"}
  };
  char entrada[25];
  int resultado, i, msg;
 
  while (scanf("%[^\n]%*c", entrada) != EOF) {
    msg = 0;
    for (i=0; i<24; i++) {
      resultado = strcmp(entrada, x[i].pais);
      if (resultado == 0) {
        printf("%s\n", x[i].msg);
        msg++;
      }
    }
    if (msg == 0) printf("-- NOT FOUND --\n");
  }
 
  return 0;
}