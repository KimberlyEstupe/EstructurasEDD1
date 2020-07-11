#include "MatizGS.h"
#include <fstream> //para leer o escribir archivos
#include <stdlib.h> //para que los comandos system puedan ejecutarse. como llamar el archivo dot para reportes
#include <sstream>
#include <string>// strcat
#include <cstring>//size of string
#include <stdio.h> //para scanf
#include <iostream>
#include <clocale>
using namespace std;

MatizGS::MatizGS()
{
    InicioM=new NodoM(0,0," ");
}
//-------------------------------Metodod Insertar Ascendentemente-------------------------------
void MatizGS::InsertaM(int x, int y, string dato){
    InCabeceraX(x);
    InCabeceraY(y);
    NodoM* newNodo=new NodoM(x,y,dato);
    InNodoY(newNodo,y);
    InNodoX(newNodo,x);
}

void MatizGS::InCabeceraX(int x){
    setlocale(LC_CTYPE,"Spanish");
    NodoM* aux=InicioM;
    NodoM* nuevo=new NodoM(x,0,"");

    if(aux->getSigM()==NULL){
        InicioM->setSigM(nuevo);
        nuevo->setAntM(InicioM);
    }else{
        while(aux->getSigM()!=NULL && aux->getSigM()->getInX()<=x){
                aux=aux->getSigM();
        }
        if(aux->getInX()==x){
        }else if(aux->getSigM()==NULL){
            aux->setSigM(nuevo);
            nuevo->setAntM(aux);
        }else{
            NodoM* pos3=aux->getSigM();
            nuevo->setAntM(aux);
            nuevo->setSigM(pos3);
            aux->setSigM(nuevo);
            pos3->setAntM(nuevo);
        }
    }
}

void MatizGS::InCabeceraY(int y){
    setlocale(LC_CTYPE,"Spanish");
    NodoM* aux=InicioM;
    NodoM* nuevo=new NodoM(0,y,"");

    if(aux->getAbajoM()==NULL){
        InicioM->setAbajoM(nuevo);
        nuevo->setArribaM(InicioM);
    }else{
        while(aux->getAbajoM()!=NULL && aux->getAbajoM()->getInY()<=y){
                aux=aux->getAbajoM();
        }
         if(aux->getInY()==y){
        }else if(aux->getAbajoM()==NULL){
            aux->setAbajoM(nuevo);
            nuevo->setArribaM(aux);
        }else{
            NodoM* pos3=aux->getAbajoM();
            nuevo->setArribaM(aux);
            nuevo->setAbajoM(pos3);
            aux->setAbajoM(nuevo);
            pos3->setArribaM(nuevo);
        }
    }
}

void MatizGS::InNodoY(NodoM* newN, int y){
    NodoM* aux=InicioM;
    while(aux->getInY()!=y){
        aux=aux->getAbajoM();
    }

    while(aux->getSigM()!=NULL && aux->getSigM()->getInX() < newN->getInX()){
        aux=aux->getSigM();
    }

    if(aux->getSigM()==NULL){
        aux->setSigM(newN);
        newN->setAntM(aux);
    }else{
        NodoM* pos3=aux->getSigM();
        newN->setAntM(aux);
        newN->setSigM(pos3);
        aux->setSigM(newN);
        pos3->setAntM(newN);
    }
}

void MatizGS::InNodoX(NodoM* nuevo, int x){
    NodoM* aux=InicioM;
    while(aux->getInX()!=x){
        aux=aux->getSigM();
    }

    while(aux->getAbajoM()!=NULL && aux->getAbajoM()->getInY()< nuevo->getInY()){
                aux=aux->getAbajoM();
    }
         if(aux->getAbajoM()==NULL){
            aux->setAbajoM(nuevo);
            nuevo->setArribaM(aux);
        }else{
            NodoM* pos3=aux->getAbajoM();
            nuevo->setArribaM(aux);
            nuevo->setAbajoM(pos3);
            aux->setAbajoM(nuevo);
            pos3->setArribaM(nuevo);
        }
}


//-------------------------------Metodod Agregar descendentemente-------------------------------
void MatizGS::AgregarM(int x, int y, string d){
    agCabezaX(x);
    agCabezaY(y);
    NodoM* newNodo=new NodoM(x,y,d);
    AgNodoY(newNodo,y);
    AgNodoX(newNodo,x);
}

void MatizGS::agCabezaX(int x){
    setlocale(LC_CTYPE,"Spanish");
    NodoM* aux=InicioM;
    NodoM* nuevo=new NodoM(x,0,"");

    if(aux->getSigM()==NULL){
        InicioM->setSigM(nuevo);
        nuevo->setAntM(InicioM);
    }else{
        while(aux->getSigM()!=NULL && aux->getSigM()->getInX()>=x){
                aux=aux->getSigM();
        }
        if(aux->getInX()==x){
        }else if(aux->getSigM()==NULL){
            aux->setSigM(nuevo);
            nuevo->setAntM(aux);
        }else{
            NodoM* pos3=aux->getSigM();
            nuevo->setAntM(aux);
            nuevo->setSigM(pos3);
            aux->setSigM(nuevo);
            pos3->setAntM(nuevo);
        }
    }
}

void MatizGS::agCabezaY(int y){
    setlocale(LC_CTYPE,"Spanish");
    NodoM* aux=InicioM;
    NodoM* nuevo=new NodoM(0,y,"");

    if(aux->getAbajoM()==NULL){
        InicioM->setAbajoM(nuevo);
        nuevo->setArribaM(InicioM);
    }else{
        while(aux->getAbajoM()!=NULL && aux->getAbajoM()->getInY()>=y){
                aux=aux->getAbajoM();
        }
         if(aux->getInY()==y){
        }else if(aux->getAbajoM()==NULL){
            aux->setAbajoM(nuevo);
            nuevo->setArribaM(aux);
        }else{
            NodoM* pos3=aux->getAbajoM();
            nuevo->setArribaM(aux);
            nuevo->setAbajoM(pos3);
            aux->setAbajoM(nuevo);
            pos3->setArribaM(nuevo);
        }
    }
}

void MatizGS::AgNodoY(NodoM* newN, int y){

    NodoM* aux=InicioM;
    while(aux->getInY()!=y){
        aux=aux->getAbajoM();
    }

    while(aux->getSigM()!=NULL && aux->getSigM()->getInX() > newN->getInX()){
        aux=aux->getSigM();
    }

    if(aux->getSigM()==NULL){
        aux->setSigM(newN);
        newN->setAntM(aux);
    }else{
        NodoM* pos3=aux->getSigM();
        newN->setAntM(aux);
        newN->setSigM(pos3);
        aux->setSigM(newN);
        pos3->setAntM(newN);
    }
}

void MatizGS::AgNodoX(NodoM* nuevo, int x){
     NodoM* aux=InicioM;
    while(aux->getInX()!=x){
        aux=aux->getSigM();
    }

    while(aux->getAbajoM()!=NULL && aux->getAbajoM()->getInY()> nuevo->getInY()){
                aux=aux->getAbajoM();
    }
         if(aux->getAbajoM()==NULL){
            aux->setAbajoM(nuevo);
            nuevo->setArribaM(aux);
        }else{
            NodoM* pos3=aux->getAbajoM();
            nuevo->setArribaM(aux);
            nuevo->setAbajoM(pos3);
            aux->setAbajoM(nuevo);
            pos3->setArribaM(nuevo);
        }
}

void MatizGS::BusquedaC(string con){
    NodoM* aux=InicioM;
    NodoM* aux2=aux;
    string respuesta="No encontrado";

    while(aux2!=NULL && respuesta!="Encontado"){
        aux2=aux2->getAbajoM(); aux=aux2;
        while(aux2!=NULL && aux->getSigM()!=NULL && aux->getContenido()!=con){
            aux=aux->getSigM();
        }

        if(aux->getContenido()==con){
            respuesta="Encontado";
        }


    }

    cout<<respuesta<<endl;
}

//****************************REPORTE****************

void MatizGS::ReporteM(){
    setlocale(LC_CTYPE,"Spanish");
    try{
        std::ofstream f;
        f.open("ReporteTablero.dot");
        f<<"digraph G {" << endl;
                f<<"  rankdir = Lista;" <<endl;
                f<<"  node [shape = rectangle  fontname=\"Arial\"]" <<endl;
                f<<"  graph [nodesep = 0.5]" <<endl;
                f<<"label = < <font color='#008B8B' point-size='20' fontname=\"Century Gothic\"> M A T R I Z </font>>;"<<endl;
                f<<"labelloc = \"t\";"<<endl;
                f<<" " <<endl;
                f<<" " <<endl;

                //Grafica ejer X
                NodoM *aux = InicioM;
                NodoM *aux2 = InicioM;
                    f<<"  {rank=same "<<endl;
                    f<<"     NodoX"<<aux->getInX()<<"  [label= \""<< aux->getInX()<<"\" , group="<<aux->getInX()<<"]"<<endl;
                    while(aux->getSigM()!=NULL){
                        f<<"     NodoX"<<aux->getInX()<<" ->  NodoX"<<aux->getSigM()->getInX()<<" [dir=both]"<<endl;
                        aux=aux->getSigM();
                        f<<"     NodoX"<<aux->getInX()<<"  [label= \""<< aux->getInX()<<"\" , group="<<aux->getInX()<<"]"<<endl;                  // }
                    }
                    f<<"  }" <<endl;
                    f<<" " <<endl;

                //Grafica Ejer Y
                aux = InicioM;
                f<<"   NodoX"<<aux->getInY()<<" ->  NodoY"<<aux->getAbajoM()->getInY()<<" [dir=both]"<<endl;
                aux=aux->getAbajoM();
                f<<"   NodoY"<<aux->getInY()<<"  [label= \""<< aux->getInY()<<"\" , group=0]"<<endl;
                while(aux->getAbajoM()!=NULL){
                        f<<"   NodoY"<<aux->getInY()<<" ->  NodoY"<<aux->getAbajoM()->getInY()<<" [dir=both]"<<endl;
                        aux=aux->getAbajoM();
                        f<<"   NodoY"<<aux->getInY()<<"  [label= \""<< aux->getInY()<<"\" , group= 0]"<<endl;                  // }
                }
                f<<""<<endl;

                //Insertar Nodos en eje Y
               aux=InicioM->getAbajoM();
               if(aux->getSigM()!=NULL){
                   while(aux!=NULL){
                       aux2=aux->getSigM();
                        f<<"  {rank=same "<<endl;
                       f<<"     NodoY"<<aux->getInY()<<" ->  Nodo"<<aux2->getInX()<<aux2->getInY()<<" [dir=both]"<<endl;
                       f<<"     Nodo"<<aux2->getInX()<<aux2->getInY()<<"  [label= \""<< aux2->getContenido()<<"\" , group="<<aux2->getInX()<<"]"<<endl;
                       while(aux2->getSigM()!=0){
                                f<<"     Nodo"<<aux2->getInX()<<aux2->getInY()<<" ->  Nodo"<<aux2->getSigM()->getInX()<<aux2->getInY()<<" [dir=both]"<<endl;
                                aux2=aux2->getSigM();
                                f<<"     Nodo"<<aux2->getInX()<<aux2->getInY()<<"  [label= \""<< aux2->getContenido()<<"\" , group="<<aux2->getInX()<<"]"<<endl;                  // }
                        }
                        aux=aux->getAbajoM();
                        f<<"  }"<<endl;
                    }
                }
                f<<" " <<endl;

                //Insertar Nodos en eje X
                aux=InicioM->getSigM();
                if(aux->getSigM()!=NULL){
                    while(aux!=NULL){
                        aux2=aux->getAbajoM();
                        f<<"   NodoX"<<aux->getInX()<<" ->  Nodo"<<aux2->getInX()<<aux2->getInY()<<" [dir=both]"<<endl;
                        while(aux2->getAbajoM()!=0){
                                    f<<"   Nodo"<<aux2->getInX()<<aux2->getInY()<<" ->  Nodo"<<aux2->getAbajoM()->getInX()<<aux2->getAbajoM()->getInY()<<" [dir=both]"<<endl;
                                    aux2=aux2->getAbajoM();;                 // }
                        }
                        aux=aux->getSigM();
                    }
                }




                f<<"}" <<endl;
        f.close();
        system("dot -Tpng ReporteTablero.dot -o ReporteTablero.png");
        system("ReporteTablero.png");
    }catch(string ios){
        cout<<"No se pudo generar"<<endl;
        system("ReporteTablero.dot");
    }
}
