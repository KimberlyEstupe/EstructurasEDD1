#ifndef COLA_H
#define COLA_H
#include <iostream>
#include <clocale>
#include <sstream>
#include <string>
using namespace std;


class Cola
{
    public:
        struct nodoC{
            int val;
            string dato;
            nodoC *SigC;
            nodoC(int v, string n) {
               val = v;
               dato = n;
            }
        };


        Cola();
        void InseCola(int v, string n);
        bool BusquedaC(int v);
        void ReporteCola();
        void MostrarCola();
        void EliminaCola();

    protected:

    private:
        nodoC* CabezaC;
        nodoC* UltC;
};

#endif // COLA_H
