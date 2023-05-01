#include <stdio.h>
 
int main() {
 
  int l, c, tamanho, i, acertos;
  char entrada[20];
  char paises[24][15] = {
    "brasil",
    "alemanha",
    "austria",
    "coreia",
    "espanha",
    "grecia",
    "estados-unidos",
    "inglaterra",
    "australia",
    "portugal",
    "suecia",
    "turquia",
    "argentina",
    "chile",
    "mexico",
    "antardida",
    "canada",
    "irlanda",
    "belgica",
    "italia",
    "libia",
    "siria",
    "marrocos",
    "japao"
  };
 
  char linguas[24][25] = {
    "Feliz Natal!",
    "Frohliche Weihnachten!",
    "Frohe Weihnacht!",
    "Chuk Sung Tan!",
    "Feliz Navidad!",
    "Kala Christougena!",
    "Merry Christmas!",
    "Merry Christmas!",
    "Merry Christmas!",
    "Feliz Natal!",
    "God Jul!",
    "Mutlu Noeller!",
    "Feliz Navidad!",
    "Feliz Navidad!",
    "Feliz Navidad!",
    "Merry Christmas!",
    "Merry Christmas!",
    "Nollaig Shona Dhuit!",
    "Zalig Kerstfeest!",
    "Buon Natale!",
    "Buon Natale!",
    "Milad Mubarak!",
    "Milad Mubarak!",
    "Merii Kurisumasu!",
  };
 
  while (scanf("%[^\n]%*c", entrada) != EOF) {
    tamanho = strlen(entrada);
 
    for (l=0; l<24; l++) {
      acertos=0;
      for (c=0; c<tamanho; c++) {
        if (paises[l][c] == entrada[c]) acertos++;
      }
 
      if (acertos == tamanho) {
        printf("%s\n", linguas[l]);
        break;
      }
    }
    
    if (acertos < tamanho) printf("-- NOT FOUND --\n");
  }
  return 0;
}