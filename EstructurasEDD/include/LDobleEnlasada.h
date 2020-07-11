#ifndef LDOBLEENLASADA_H
#define LDOBLEENLASADA_H
#include <iostream>
#include <clocale>
#include <sstream>
#include <string>
using namespace std;

class nodoDE{
private:
            int valor;
            string name;
            nodoDE *sigDE;
            nodoDE *antDE;
    nodoDE(int v, string n){
               sigDE=nullptr;
               antDE=nullptr;
               valor = v;
               name = n;
    }

   friend class LDobleEnlasada;
};


class LDobleEnlasada
{
public:
    LDobleEnlasada();
    void InsertarDE(int v, string n);

    private:

        void InDesDE(int v, string n);
        void InAsDE(int v, string n);
        void BusquedaDE(int v);
        void ReporteDE();
        void MostrarDE();
        void EliminaValDE(int v);


        nodoDE* cabezaDE;
        nodoDE* UltiDE;

};

#endif // LDOBLEENLASADA_H
