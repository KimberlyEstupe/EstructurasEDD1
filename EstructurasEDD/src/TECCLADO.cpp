#include "TECCLADO.h"
#include <cstdio>
using namespace std;

void TECCLADO::Ptecla()
{
  //system("cls");
  char *nombre;

  /* Obtiene el codigo de la tecla, hace las veces de la funcion getch() */
  int tecla = ObtenerTecla();
  /* Obtiene el nombre de la tecla */
  ObtenerNombreTecla(nombre, tecla);

  printf("Has presionado la tecla: %s\n", nombre);

  /* Llevar a cabo acciones en funcion de la tecla presionada.
     Si es un caracter alfanumerico, se deben hacer las comparaciones
     como si fuera un caracter.
     Si es una tecla extendida, se deben hacer las comparaciones usando
     las constantes definidas en la bibliotecha "teclado.h" */

  if(tecla=='5')
    printf("Has presionado el numero 5");
  else if(tecla=='C')
    printf("Has presionado la letra C");
  else if(tecla==_F1)
    printf("Has presionado la tecla de funcion F1");
  else if(tecla==_ARR)
    printf("Has presionado la fecla hacia arriba");
  else if(tecla==_ESC)
    printf("Has presionado la tecla ESCAPE");
  /* Ejemplo cuando se trata de una combinacion de teclas, usando las teclas
     de control como: SHIFT, ALT, CTRL.
     En este caso se trata de CTRL+F5
     El codigo de comparacion en este caso es: 0x6200, este codigo puede
     ser obtenido si ejecutas este programa, tal como esta y te fijas en el
     resultado que se muestra en pantalla */
  else if(tecla==0x6200)
    printf("Has presionado la tecla CTRL+F5");
  else if(tecla==0x1900)
    printf("Has presionado la tecla ALT+p");
  else if(tecla==0x2200)
    printf("Has presionado la tecla CTRl+ALT+g");

  /* Uso similar a la funcion getch() */
  ObtenerTecla();
}
