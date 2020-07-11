#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include <string>
using namespace std;

class nodoAVL{
private:
    string ID;
    string descripcion;
    string nombre;
    bool disponibilidad;
    int fe;
    nodoAVL* Padre;
    nodoAVL* Izq;
    nodoAVL* Der;
    nodoAVL(string id, string name, string descrip){
        ID=id;
        descripcion=descrip;
        fe=0;
        nombre=name;
        disponibilidad=true;
        Padre=nullptr;
        Izq=nullptr;
        Der=nullptr;
    }
    friend class ArbolAVL;
};

class ArbolAVL
{
    public:
        ArbolAVL();
        void Insertar(string id, string name, string descrip);
        bool Busca(string id);
         void Eliminar (string id);
        void RentarAc(string id);
        void ModificaDescripcion(string id, string descripcion);
        void ReporteAVL();
        nodoAVL* ReRaiz();
        void Recorrido();

    private:
        //-----------Insertar------------------------------
        enum {IZQUIERDO, DERECHO};
        void Equilibrar(nodoAVL *nodo, int rama, bool nuevo);
        void SimpleIzquierda(nodoAVL* hoja);
        void SimpleDerecha(nodoAVL* hoja);
        void DobleIzquierda(nodoAVL* hoja);
        void DobleDerecha(nodoAVL* hoja);
        //---------------------------------------
        nodoAVL* BuscarR(string id,nodoAVL* hoja);
        //---------------Recorrido----------------
        void RecorridoInOrden(nodoAVL* nodo);
        void RecorridoPosOrden(nodoAVL* nodo);
        void RecorridoPreOrden(nodoAVL* nodo);
        //*************************************
         void EliminaRecur(nodoAVL* nodo);
        void Unhijo(nodoAVL* anterior, nodoAVL* nuevo);
    //**************************************************
        nodoAVL* IzquierdoDerecho(nodoAVL* nodo);
        nodoAVL* DerechoIzquierdo(nodoAVL* nodo);
        //----------------REPORTES-----------------
        void ReporRecurAVl(nodoAVL* hoja);

        void PreOrden(nodoAVL* hoja);
        void PostOrden(nodoAVL* hoja);
        void InOrden(nodoAVL* hoja);
        //------------------------------
        nodoAVL* Raiz=nullptr;
};

#endif // ARBOLAVL_H
