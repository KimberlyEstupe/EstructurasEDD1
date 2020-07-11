#ifndef LSIMPLE_H
#define LSIMPLE_H
#include <iostream>
#include <clocale>
#include <sstream>
#include <string>
using namespace std;

class nodoL{
private:
    int valor;
    string name;
    nodoL *siguienteL;


    nodoL(int v, string n) {
               valor = v;
               name = n;
               siguienteL=nullptr;
    }
    friend class LSimple;
};

class LSimple
{
    public:

        LSimple();
        void Insera(int v, string n);
        void InsertarPilaCola(int v, string n);
        void InsertaDes(int v, string n);
        void InsertaAs(int v, string n);

        bool Busqueda(string n);
        void ReporteLSimple();
        void MostrarLS();

        void EliminaValLS(int v);
        void EliminarPila();
        void EliminarCola();

    private:
        nodoL* cabezaL;
        nodoL* ultL;
};

#endif // LSIMPLE_H
