#include "LSimple.h"
#include <fstream> //para leer o escribir archivos
#include <stdlib.h> //para que los comandos system puedan ejecutarse. como llamar el archivo dot para reportes
#include <string>// strcat
#include <cstring>//size of string
#include <stdio.h> //para scanf
#include <iostream>
#include <clocale>
#include <sstream>
using namespace std;

LSimple::LSimple()
{
    cabezaL=NULL;
    ultL=NULL;
}

void LSimple::Insera(int v, string n){
    InsertarPilaCola( v,  n);
}

/*void LSimple::InsertarPilaCola(int v, string n){
    setlocale(LC_CTYPE,"Spanish");
    if(cabezaL==NULL){
        cabezaL= new nodoL(v,n);
        ultL = cabezaL;
    }else{
        nodoL* nuevo=new nodoL(v,n);
        ultL->siguienteL=nuevo;
        ultL=nuevo;
    }//else
}//InsertarLS
*/
void LSimple::InsertarPilaCola(int v, string n){
     setlocale(LC_CTYPE,"Spanish");
    if(cabezaL==NULL){
        cabezaL= new nodoL(v,n);
        ultL = cabezaL;
    }else{
        nodoL* aux=cabezaL;
        while(aux->siguienteL!=NULL) {
                aux = aux->siguienteL;
         }
        nodoL* nuevo=new nodoL(v,n);
        aux->siguienteL=nuevo;
        ultL=nuevo;
    }
}

void LSimple::InsertaDes(int v, string n){
    setlocale(LC_CTYPE,"Spanish");
    nodoL* aux;
    aux=cabezaL;
    if(cabezaL==NULL){
        cabezaL= new nodoL(v,n);
    }else{
        if (aux->valor<=v){
                nodoL* n_aux = new nodoL(v,n);
                n_aux->siguienteL=aux;
                cabezaL=n_aux;
        }else{
            while(aux->siguienteL!=NULL && aux->siguienteL->valor>v){
                    aux=aux->siguienteL;
            }
            if(aux->siguienteL==NULL){
                nodoL* n_aux = new nodoL(v,n);
                aux->siguienteL=n_aux;
                ultL=n_aux;}
            else{
                nodoL* n_aux = new nodoL(v,n);
                nodoL* pos3=aux->siguienteL;
                aux->siguienteL=n_aux;
                n_aux->siguienteL=pos3;
            }
        }//else{cout<<"Dato repetido"<<endl;}
    }//else
}


void LSimple::InsertaAs(int v, string n){
    setlocale(LC_CTYPE,"Spanish");
    nodoL* aux;
    aux=cabezaL;
    if(cabezaL==NULL){
        cabezaL= new nodoL(v,n);
    }else{
        if (aux->valor>=v){
                nodoL* n_aux = new nodoL(v,n);
                n_aux->siguienteL=aux;
                cabezaL=n_aux;
        }else{
            while(aux->siguienteL!=NULL && aux->siguienteL->valor<v){
                    aux=aux->siguienteL;
            }
            if(aux->siguienteL==NULL){
                nodoL* n_aux = new nodoL(v,n);
                aux->siguienteL=n_aux;
                ultL=n_aux;}
            else{
                nodoL* n_aux = new nodoL(v,n);
                nodoL* pos3=aux->siguienteL;
                aux->siguienteL=n_aux;
                n_aux->siguienteL=pos3;
            }
        }
    }
}

void LSimple::MostrarLS() {
   setlocale(LC_CTYPE,"Spanish");
   nodoL *aux;
   aux = cabezaL;
   cout <<" "<<endl;
   while(aux->siguienteL!=NULL) {
      cout << aux->valor <<","<< aux->name<< "-> ";
      aux = aux->siguienteL;
   }
   cout << aux->valor <<","<< aux->name<< endl;
}

bool LSimple::Busqueda(string n){
   setlocale(LC_CTYPE,"Spanish");
   bool respuesta=false;
   nodoL* aux;
   aux=cabezaL;
   while(aux->siguienteL!=NULL) {
        if (aux->name==n){
            respuesta=true;
        }
        aux = aux->siguienteL;
   }
   return respuesta;
}

void LSimple::EliminaValLS(int v){
    setlocale(LC_CTYPE,"Spanish");
   if(cabezaL==NULL){
    cout<<"LISTA VACIA"<<endl;
   }else{//https://www.youtube.com/watch?v=ljYbVM6j11s
       nodoL* aux=cabezaL;
       nodoL* ant=NULL;
       while ((aux!=NULL) && (aux->valor!=v)){
            ant=aux;
            aux=aux->siguienteL;
       }
       if(aux==NULL){
            cout<<"Este valor no exite"<<endl;
       }else{
           if(ant==NULL){
            cabezaL=cabezaL->siguienteL;
            aux->siguienteL=NULL;
            delete aux;
           }else if(aux==ultL){
               ant->siguienteL=NULL;
               ultL=ant;
               delete aux;
           }else{
               ant->siguienteL=aux->siguienteL;
               delete aux;
           }
       }
    }
}

void LSimple::EliminarCola(){
    nodoL* aux=cabezaL;
    cabezaL=cabezaL->siguienteL;
    aux->siguienteL=NULL;
    delete aux;
}
void LSimple::EliminarPila(){
    nodoL *aux = cabezaL;
   while(aux->siguienteL!=ultL) {
      aux = aux->siguienteL;
   }
    aux->siguienteL=NULL;
    ultL=aux;

}


void LSimple::ReporteLSimple(){
    setlocale(LC_CTYPE,"Spanish");
    try{
        ofstream f;
        f.open("ReporteListaSimple.dot");
        f<<"digraph G {" << endl;
                f<<"rankdir = LR;" <<endl;
                f<<"node [shape = rectangle]" <<endl;
                f<<"graph [nodesep = 0.5]" <<endl;
                f<<"label = < <font color='pink'> <font point-size='20'> L I S T A    S I M P L E </font></font>>;"<<endl;
                f<<"labelloc = \"t\";"<<endl;
                f<<" " <<endl;

                nodoL *aux = cabezaL;
                int c=0;
                int c2=0;
                f<<"Nodo"<<c<<"  [label= \""<< aux->name<<" , "<<aux->valor<<"\" ]"<<endl;
                    while(aux->siguienteL!=NULL){
                        c2=c+1;
                        f<<"Nodo"<<c<<" ->  Nodo"<<c2<<endl;
                        aux=aux->siguienteL;
                        c++;
                        f<<"Nodo"<<c<<"  [label= \""<< aux->name<<" , "<<aux->valor<<"\" ]"<<endl;                  // }
                    }
                f<<" }" <<endl;
        f.close();
        system("dot -Tpng ReporteListaSimple.dot -o ReporteListaSimple.png");
        system("ReporteListaSimple.png");
    }catch(string ios){
        cout<<"No se pudo generar"<<endl;
    }
}
