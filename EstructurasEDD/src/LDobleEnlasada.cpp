#include "LDobleEnlasada.h"
#include <fstream> //para leer o escribir archivos
#include <stdlib.h> //para que los comandos system puedan ejecutarse. como llamar el archivo dot para reportes
#include <string>// strcat
#include <cstring>//size of string
#include <stdio.h> //para scanf
#include <iostream>
#include <clocale>
#include <sstream>
using namespace std;

LDobleEnlasada::LDobleEnlasada()
{
    cabezaDE=NULL;
    UltiDE=NULL;
}

void LDobleEnlasada::InsertarDE(int v, string n){
    setlocale(LC_CTYPE,"Spanish");
    if(cabezaDE==NULL){
        cabezaDE= new nodoDE(v,n);
        UltiDE = cabezaDE;
    }else{
        nodoDE* nuevo=new nodoDE(v,n);
        UltiDE->sigDE=nuevo;
        nuevo->antDE=UltiDE;
        UltiDE=nuevo;
    }
}



void LDobleEnlasada::InDesDE(int v, string n){
    setlocale(LC_CTYPE,"Spanish");
    nodoDE* aux;
    aux=cabezaDE;
    if(cabezaDE==NULL){
        cabezaDE = new nodoDE(v,n);
        UltiDE=cabezaDE;
    }else{
        if (aux->valor<=v){
                nodoDE* n_aux = new nodoDE(v,n);
                n_aux->sigDE=aux;
                cabezaDE=n_aux;
                aux->antDE=cabezaDE;
        }else{
            while(aux->sigDE!=NULL && aux->sigDE->valor>v){
                    aux=aux->sigDE;
            }
            if(aux->sigDE==NULL){
                nodoDE* n_aux = new nodoDE(v,n);
                aux->sigDE=n_aux;
                n_aux->antDE=aux;
                UltiDE=n_aux;}
            else{
                nodoDE* n_aux = new nodoDE(v,n);
                nodoDE* pos3=aux->sigDE;
                aux->sigDE=n_aux;
                n_aux->sigDE=pos3;
                n_aux->antDE=aux;
                pos3->antDE=n_aux;
            }
        }
    }//else
}


void LDobleEnlasada::InAsDE(int v, string n){
    setlocale(LC_CTYPE,"Spanish");
    nodoDE* aux;
    aux=cabezaDE;
    if(cabezaDE==NULL){
        cabezaDE= new nodoDE(v,n);
    }else{
        if (aux->valor>=v){
                nodoDE* n_aux = new nodoDE(v,n);
                n_aux->sigDE=aux;
                cabezaDE=n_aux;
                aux->antDE=cabezaDE;
        }else{
            while(aux->sigDE!=NULL && aux->sigDE->valor<v){
                    aux=aux->sigDE;
            }
            if(aux->sigDE==NULL){
                nodoDE* n_aux = new nodoDE(v,n);
                aux->sigDE=n_aux;
                n_aux->antDE=aux;
                UltiDE=n_aux;}
            else{
                nodoDE* n_aux = new nodoDE(v,n);
                nodoDE* pos3=aux->sigDE;
                aux->sigDE=n_aux;
                n_aux->sigDE=pos3;
                n_aux->antDE=aux;
                pos3->antDE=n_aux;
            }
        }
    }
}

void LDobleEnlasada::MostrarDE() {
   setlocale(LC_CTYPE,"Spanish");
   nodoDE *aux;
   aux = cabezaDE;
   cout <<" "<<endl;
   while(aux->sigDE!=NULL) {
      cout << aux->valor <<","<< aux->name<< "-> ";
      aux = aux->sigDE;
   }
   cout << aux->valor <<","<< aux->name<< endl;
}

void LDobleEnlasada::BusquedaDE(int v){
   setlocale(LC_CTYPE,"Spanish");
   if(cabezaDE==NULL){
    cout<<"LISTA VACIA"<<endl;
   }else{
       nodoDE* aux=cabezaDE;
       while ((aux!=NULL) && (aux->valor!=v)){
            aux=aux->sigDE;
       }
       if(aux==NULL){
            cout<<"Este valor no exite"<<endl;
       }else{
           cout<<"ENCONTRADO"<<endl;
       }
    }
}

void LDobleEnlasada::EliminaValDE(int v){
    setlocale(LC_CTYPE,"Spanish");
   if(cabezaDE==NULL){
    cout<<"LISTA VACIA"<<endl;
   }else{//https://www.youtube.com/watch?v=ljYbVM6j11s
       nodoDE* aux=cabezaDE;
       nodoDE* ant=NULL;
       while ((aux!=NULL) && (aux->valor!=v)){
            ant=aux;
            aux=aux->sigDE;
       }
       if(aux==NULL){
            cout<<"Este valor no exite"<<endl;
       }else{
           if(ant==NULL){
            cabezaDE=cabezaDE->sigDE;
            delete aux;
           }else if(aux==UltiDE){
               UltiDE->antDE=NULL;
               ant->sigDE=NULL;
               UltiDE=ant;
               delete aux;
           }else{
               ant->sigDE=aux->sigDE;
               delete aux;
           }
       }
    }

}


void LDobleEnlasada::ReporteDE(){
    setlocale(LC_CTYPE,"Spanish");
    try{
        ofstream f;
        f.open("ReporteDoblementeEnlazada.dot");
        f<<"digraph G {" << endl;
                f<<"rankdir = LR;" <<endl;
                f<<"node [shape = rectangle fontname=\"Arial\" fontsize=\"10\"]" <<endl;
                f<<"graph [nodesep = 0.5]" <<endl;
                f<<"label = < <font color='blue'> <font point-size='20'> S I M P L E </font></font>>;"<<endl;
                f<<"labelloc = \"t\";"<<endl;
                f<<" " <<endl;
                f<<" " <<endl;

                nodoDE* aux=cabezaDE;
                int c=0;
                int c2=0;
                f<<"Nodo"<<c<<"   [label= \""<< aux->name<<" , "<<aux->valor<<"\" ]"<<endl;
                    while(aux->sigDE!=NULL){
                        c2=c+1;
                        f<<"Nodo"<<c<<" ->  Nodo"<<c2<<" [dir=both, color=blue]"<<endl;
                        aux=aux->sigDE;
                        c++;
                        f<<"Nodo"<<c<<"   [label= \""<< aux->name<<" , "<<aux->valor<<"\" ]"<<endl;                  // }
                    }
                f<<" }" <<endl;
        f.close();
        system("dot -Tpng ReporteDoblementeEnlazada.dot -o ReporteDoblementeEnlazada.png");//Convierte el dot en imagen
        system("ReporteDoblementeEnlazada.png");//Abre la imagen
    }catch(string ios){
        cout<<"No se pudo generar"<<endl;
    }
}

