#ifndef MATIZGS_H
#define MATIZGS_H
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class NodoM{
private:
    int inX;
    int inY;
    string contenido;
    NodoM* sigM;
    NodoM* antM;
    NodoM* abajoM;
    NodoM* arribaM;

public:
    NodoM(int inX,int inY, string contenido){
        this->inX = inX;
        this->inY = inY;
        this->contenido = contenido;
        sigM = NULL;
        antM = NULL;
        abajoM = NULL;
        arribaM = NULL;
    }

    /*==GETTERS==*/
    int getInX(){
        return this->inX;
    }

    int getInY(){
        return this->inY;
    }

    string getContenido(){
        return this->contenido;
    }

    NodoM* getSigM(){
        return this->sigM;
    }

    NodoM* getAntM(){
        return this->antM;
    }

    NodoM* getAbajoM(){
        return this->abajoM;
    }
    NodoM* getArribaM(){
        return this->arribaM;
    }
    /*==SETTERS==*/
    void setInX(int inX){
        this->inX = inX;
    }

    void setInY(int inY){
        this->inY = inY;
    }

    void setContenido(string contenido){
        this->contenido = contenido;
    }

    void setSigM(NodoM *sigM){
        this->sigM = sigM;
    }

    void setAntM(NodoM *antM){
        this->antM = antM;
    }

    void setAbajoM(NodoM *abajoM){
        this->abajoM = abajoM;
    }

    void setArribaM(NodoM *arribaM){
        this->arribaM = arribaM;
    }
};

class MatizGS
{
    public:
        MatizGS();
        //Insertar sera Ascendente
        void InsertaM(int x,int y, string dato);
        void InCabeceraX(int x);
        void InCabeceraY(int y);
        void InNodoY(NodoM *nuevo,int y);
        void InNodoX(NodoM *nuevo,int x);


        //Agregar sera descedente
        void AgNodoX(NodoM *nuevo,int x);
        void AgNodoY(NodoM *nuevo,int y);
        void AgregarM(int x,int y, string dato);
        void agCabezaX(int x);
        void agCabezaY(int y);

        void BusquedaC(string con);
        void BusPos(int x, int y);
        void ReporteM();

    protected:

    private:
        NodoM* InicioM;
};

#endif // MATIZGS_H
