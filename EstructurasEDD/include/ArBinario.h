#ifndef ARBINARIO_H
#define ARBINARIO_H
#include <iostream>
#include <string>
using namespace std;

class NABB{
private:
    NABB* Der;
    NABB* Izq;
    NABB* npadre;
    int num;
    NABB(int n){
        num=n;
        Der=nullptr;
        Izq=nullptr;
    }
    friend class ArBinario;
};

class ArBinario
{
    public:
        ArBinario();
        void Insertar(int n);
        void Eliminar(int n);
        bool busqueda(int n);
        void reemplazar(int n, int reemplazo);
        void Recorre();

    protected:

    private:
        void RecorridoInOrden(NABB* nodo);
        void RecorridoPosOrden(NABB* nodo);
        void RecorridoPreOrden(NABB* nodo);

        void EliminaRecur(NABB* nodo);
        void Unhijo(NABB* anterior, NABB* nuevo);

        NABB* IzquierdoDerecho(NABB* nodo);
        NABB* DerechoIzquierdo(NABB* nodo);


        NABB* Raiz;
        NABB* padre;
        NABB* NEncontrado;
};

#endif // ARBINARIO_H
