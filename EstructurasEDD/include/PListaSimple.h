#ifndef PLISTASIMPLE_H
#define PLISTASIMPLE_H
#include <iostream>
#include <clocale>
#include <sstream>
#include <string>
using namespace std;


class nodL{
private:
    int val;
    //string key; //para el proyecto (nombre de la imagen)
    //node *matriz; //puntero a la matriz
    nodL *sig;
public:
    nodL(int val){
        this->val = val;
        sig = NULL;
    }
    /*==GETTERS==*/
    int getVal(){
        return this->val;
    }

    nodL* getSig(){
        return this->sig;
    }
    /*==SETTERS==*/
    void setVal(int val){
        this->val = val;
    }

    void setSig(nodL *sig){
        this->sig = sig;
    }
};

class PListaSimple
{
    public:
        PListaSimple();
        void Inser(int v);//Puedo definir cual insercion realizar
        void InserPilaCola(int v);//Inseta normal
        void InserDes(int v);//Inseta descendentemente
        void InserAs(int v);//Inserta Ascendentemente

        void Mostrat();
        void Buscar(int v);
        void Reporte();


        void EliminarLS(int v);//Elimina con busqueda
        void EliminarCola();//Elimina Primer Elemento
        void EliminarPila();//Elimina ultimo elemento

    private:
        nodL* Inicio;
};

#endif // PLISTASIMPLE_H
