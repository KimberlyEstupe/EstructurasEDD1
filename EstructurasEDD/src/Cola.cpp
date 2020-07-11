#include "Cola.h"
#include <fstream> //para leer o escribir archivos
#include <stdlib.h> //para que los comandos system puedan ejecutarse. como llamar el archivo dot para reportes
#include <string>// strcat
#include <cstring>//size of string
#include <stdio.h> //para scanf
#include <iostream>
#include <clocale>
#include <sstream>
using namespace std;

Cola::Cola()
{
    CabezaC=nullptr;
    UltC=nullptr;
}

void Cola::InseCola(int v, string n){
    setlocale(LC_CTYPE,"Spanish");
    if(CabezaC==nullptr){
        CabezaC= new nodoC(v,n);
        UltC = CabezaC;
    }else{
        nodoC* nuevo=new nodoC(v,n);
        UltC->SigC=nuevo;
        UltC=nuevo;
    }
}

void Cola::MostrarCola(){
   setlocale(LC_CTYPE,"Spanish");
   nodoC *aux = CabezaC;
   while(aux->SigC!=nullptr) {
      cout << aux->val <<","<< aux->dato<< "-> ";
      aux = aux->SigC;
   }
}

/*void Cola::EliminaCola(){
    nodoC *aux = CabezaC;
   while(aux->SigC!=UltC) {
      aux = aux->SigC;
   }
    aux->SigC=nullptr;
    UltC=aux;
}*///pila

void Cola::EliminaCola(){
    nodoC *aux = CabezaC;
    CabezaC=CabezaC->SigC;
    aux->SigC=nullptr;
    delete aux;
}

void Cola::ReporteCola(){
     setlocale(LC_CTYPE,"Spanish");
    try{
        ofstream f;
        f.open("ReporteCola.dot");
        f<<"digraph G {" << endl;
                f<<"rankdir = LR;" <<endl;
                f<<"node [shape = rectangle]" <<endl;
                f<<"graph [nodesep = 0.5]" <<endl;

                nodoC *aux = CabezaC;
                int c=0;
                int c2=0;
                f<<"Nodo"<<c<<"  [label= \""<< aux->dato<<" , "<<aux->val<<"\" ]"<<endl;
                    while(aux->SigC!=0){
                        c2=c+1;
                        f<<"Nodo"<<c<<" ->  Nodo"<<c2<<endl;
                        aux=aux->SigC;
                        c++;
                        f<<"Nodo"<<c<<"  [label= \""<< aux->dato<<" , "<<aux->val<<"\" ]"<<endl;                  // }
                    }
                f<<" }" <<endl;
        f.close();
        system("dot -Tpng ReporteCola.dot -o ReporteCola.png");
        system("ReporteCola.png");
    }catch(string ios){
        cout<<"No se pudo generar"<<endl;
    }
}
