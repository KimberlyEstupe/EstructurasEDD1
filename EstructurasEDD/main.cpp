#include <iostream>

#include "LSimple.h"
#include "LDobleEnlasada.h"
#include "PListaSimple.h"
#include "MatizGS.h"
#include "ArbolAVL.h"
#include "Cubo.h"

using namespace std;

int main()
{
    //-----Listas normales-----
    LSimple LS;
    LDobleEnlasada DE;
    Cubo cb;
    ArbolAVL AVL;

    //-----Listas con Get y Set-----
    PListaSimple PLS;
    MatizGS MGS;

    AVL.Insertar("50","Maria","MAR");
    AVL.Insertar("22","sharon","sharon");
    AVL.Insertar("80","pedro","pedro");
    AVL.Insertar("15","amelia","amelia");
    AVL.Insertar("27","amelia","amelia");
    AVL.Insertar("60","amelia","amelia");
    AVL.Insertar("90","amelia","amelia");
    AVL.Insertar("10","amelia","amelia");
    AVL.Insertar("20","amelia","amelia");
    AVL.Insertar("38","amelia","amelia");
    AVL.Insertar("68","amelia","amelia");
    AVL.Insertar("83","amelia","amelia");
    AVL.Insertar("53","amelia","amelia");
    AVL.Insertar("96","amelia","amelia");
    AVL.Insertar("44","amelia","amelia");
    AVL.Insertar("8","amelia","amelia");
    AVL.Insertar("52","amelia","amelia");
    AVL.Insertar("5","amelia","amelia");
    AVL.Insertar("58","amelia","amelia");

    AVL.Eliminar("22");
    AVL.Recorrido();
    AVL.ReporteAVL();

    return 0;
}
