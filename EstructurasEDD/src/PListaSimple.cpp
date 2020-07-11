#include "PListaSimple.h"
#include <fstream> //para leer o escribir archivos
#include <stdlib.h> //para que los comandos system puedan ejecutarse. como llamar el archivo dot para reportes
#include <string>// strcat
#include <cstring>//size of string
#include <stdio.h> //para scanf
#include <iostream>
#include <clocale>
#include <sstream>
using namespace std;

PListaSimple::PListaSimple()
{
    Inicio=NULL;
}

void PListaSimple::Inser(int v){
    InserAs(v);
}

void PListaSimple::InserPilaCola(int v){
    setlocale(LC_CTYPE,"Spanish");
    if(Inicio==NULL){
        Inicio= new nodL(v);
    }else {
        nodL* aux=Inicio;
        while(aux->getSig()!=NULL){
            aux=aux->getSig();
        }
        aux->setSig(new nodL(v));
    }
}

void PListaSimple::InserDes(int v){
    setlocale(LC_CTYPE,"Spanish");
    if(Inicio==NULL){
        Inicio= new nodL(v);
    }else{
        nodL* aux=Inicio;
        nodL* nuevo=new nodL(v);
        if(aux->getVal()<v){
            nuevo->setSig(aux);
            Inicio=nuevo;
        }else if(aux->getVal()>v){
            while(aux->getSig()!=NULL && aux->getSig()->getVal()>v){
                aux=aux->getSig();
            }
            if(aux->getSig()==NULL){
               aux->setSig(nuevo);
            }else{
                nodL* pos3=aux->getSig();
                aux->setSig(nuevo);
                nuevo->setSig(pos3);
            }
        }else{
            cout<<"Dato repetido "<<endl;
        }
    }
}

void PListaSimple::InserAs(int v){
    setlocale(LC_CTYPE,"Spanish");
    if(Inicio==NULL){
        Inicio= new nodL(v);
    }else{
        nodL* aux=Inicio;
        nodL* nuevo=new nodL(v);
        if(aux->getVal()>v){
            nuevo->setSig(aux);
            Inicio=nuevo;
        }else if(aux->getVal()<v){
            while(aux->getSig()!=NULL && aux->getSig()->getVal()<v){
                aux=aux->getSig();
            }
            if(aux->getSig()==NULL){
               aux->setSig(nuevo);
            }else{
                nodL* pos3=aux->getSig();
                aux->setSig(nuevo);
                nuevo->setSig(pos3);
            }
        }else{
            cout<<"Dato repetido "<<endl;
        }
    }
}

void PListaSimple::Buscar(int v){
    if(Inicio!=NULL){
        nodL* aux=Inicio;
        while(aux->getSig()!=NULL && aux->getVal()!=v){
            aux=aux->getSig();
        }
        if(aux->getVal()==v){
            cout<<"Valor encontrado"<<endl;
        }else{
            cout<<"Valor no exixtente"<<endl;
        }
    }else{
        cout<<"Lista vacia"<<endl;
    }
}


void PListaSimple::Mostrat(){
    if(Inicio!=NULL){
        nodL* aux=Inicio;
        while(aux->getSig()!=NULL){
                cout<<aux->getVal()<<" -> ";
            aux=aux->getSig();
        }
        cout<<aux->getVal()<<endl;
    }else{
        cout<<"No hay datos en la lista"<<endl;
    }
}

void PListaSimple::EliminarLS(int v){
    if(Inicio!=NULL){
        if(v==Inicio->getVal()){
            nodL* aux=Inicio;
            Inicio=Inicio->getSig();
            aux->setSig(NULL);
            delete aux;
        }else{
            nodL* aux=Inicio;
            while(aux->getSig()!=NULL && aux->getSig()->getVal()!=v){
                aux=aux->getSig();
            }
            if(aux->getSig()->getVal()==v){
                nodL* eli=aux->getSig();
                aux->setSig(eli->getSig());
                delete eli;
            }else{
                cout<<"Valor no exixtente"<<endl;
            }
        }
    }else{
        cout<<"Lista vacia"<<endl;
    }
}

void PListaSimple::EliminarPila(){//ELIMINA EL ULTIMO DATO
    nodL* aux=Inicio;
        while(aux->getSig()->getSig()!=NULL){
            aux=aux->getSig();
        }
        nodL* eli=aux->getSig();
        aux->setSig(NULL);
        delete eli;
}

void PListaSimple::EliminarCola(){//ELIMINA EL PRIMER DATO
    nodL* aux=Inicio;
    Inicio=Inicio->getSig();
    aux->setSig(NULL);
    delete aux;
}

void PListaSimple::Reporte(){
    setlocale(LC_CTYPE,"Spanish");
    try{
        ofstream f;
        f.open("ReporteListaSimple.dot");
        f<<"digraph G {" << endl;
                f<<"rankdir = LR;" <<endl;
                f<<"node [shape = rectangle fontname=\"Arial\" fontsize=\"10\"]" <<endl;
                f<<"graph [nodesep = 0.5]" <<endl;
                f<<"label = < <font color='blue'> <font point-size='20'> S I M P L E </font></font>>;"<<endl;
                f<<"labelloc = \"t\";"<<endl;
                f<<" " <<endl;
                f<<" " <<endl;

                nodL *aux = Inicio;
                int c=0;
                int c2=0;
                f<<"Nodo"<<c<<"  [label= \""<<" , "<<aux->getVal()<<"\" ]"<<endl;
                    while(aux->getSig()!=NULL){
                        c2=c+1;
                        f<<"Nodo"<<c<<" ->  Nodo"<<c2<<endl;
                        aux=aux->getSig();
                        c++;
                        f<<"Nodo"<<c<<"  [label= \""<<" , "<<aux->getVal()<<"\" ]"<<endl;                  // }
                    }
                f<<" }" <<endl;
        f.close();
        system("dot -Tpng ReporteListaSimple.dot -o ReporteListaSimple.png");//Convierte el dot en imagen
        system("ReporteListaSimple.png");//Abre la imagen
    }catch(string ios){
        cout<<"No se pudo generar"<<endl;
    }
}

