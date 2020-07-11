#include "ArBinario.h"

ArBinario::ArBinario()
{
    Raiz=nullptr;
    padre=nullptr;
    NEncontrado=nullptr;
}
//********************************INSERTAR*******************************
void ArBinario::Insertar(int n){
    NABB* nuevo= new NABB(n);
    padre=nullptr;
    if(Raiz==nullptr){
        Raiz=nuevo;
    }else{
        padre=nullptr;
        NABB* tmp=Raiz;
        while(tmp!=nullptr){
            padre=tmp;
            if(nuevo->num>tmp->num) tmp=tmp->Der;
            else if(nuevo->num<tmp->num)tmp=tmp->Izq;
        }

        nuevo->npadre=padre;
        if(nuevo->num < padre->num) padre->Izq =nuevo;
        else if(nuevo->num > padre->num) padre->Der =nuevo;


    }
}


//********************************RECORRIDOS*******************************
void ArBinario::Recorre(){// Este recorrido muestra los nodos otdenado
    RecorridoPreOrden(Raiz);
    cout<<"NULL"<<endl;
}

void ArBinario::RecorridoInOrden(NABB* hoja){
    if(hoja!=nullptr){
        RecorridoInOrden(hoja->Izq);
        cout<<hoja->num<<" -> ";
        RecorridoInOrden(hoja->Der);
    }
}

void ArBinario::RecorridoPreOrden(NABB* hoja){
    if(hoja!=nullptr){
        cout<<hoja->num<<" -> ";
        RecorridoPreOrden(hoja->Izq);
        RecorridoPreOrden(hoja->Der);
    }
}

void ArBinario::RecorridoPosOrden(NABB* hoja){
    if(hoja!=nullptr){
        RecorridoPosOrden(hoja->Izq);
        RecorridoPosOrden(hoja->Der);
        cout<<hoja->num<<" -> ";
    }
}


//********************************BUSQUEDA*******************************
bool ArBinario::busqueda(int nume){
        NABB* aux=Raiz;
        while(aux!=nullptr && aux->num!=nume){
            padre=aux;
            if(nume<aux->num){
                aux=aux->Izq;
            }else{
                aux=aux->Der;
            }
        }
        if(aux->num==nume){
            NEncontrado=aux;
            return true;
        }
    return false;
}

//********************************ELIMINAR*******************************
void ArBinario::Eliminar(int nume){
    padre=nullptr;
    if(Raiz!=nullptr){
        if(busqueda(nume)){
            EliminaRecur(NEncontrado);
        }
    }else{
        cout<<"El arbol esta vacio"<<endl;
    }
}

void ArBinario::EliminaRecur(NABB* aux){
            if(!aux->Izq && !aux->Der){//Si es hoja
                if(aux->num >= aux->npadre->num ){
                    aux->npadre->Der=nullptr;
                    delete aux;
                    aux=nullptr;
                }else if(aux->num <= aux->npadre->num ){
                    aux->npadre->Izq=nullptr;
                    delete aux;
                    aux=nullptr;
                }
            }else if(aux->Izq && aux->Der){//Tiene 2 hijos
                NABB* reemplazo=IzquierdoDerecho(aux->Der);
                aux->num=reemplazo->num;
               EliminaRecur(reemplazo);
            }else {
                if(aux->Izq  && !aux->Der){//SI SOLO TIENE UN HIJO
                Unhijo(aux, aux->Izq);
                aux->Izq=nullptr;
                aux->Der=nullptr;
                delete aux;
                aux=nullptr;
                }else if(aux->Der  && !aux->Izq){
                    Unhijo(aux, aux->Der);
                    aux->Izq=nullptr;
                    aux->Der=nullptr;
                    delete aux;
                    aux=nullptr;
                }
            }
}

void ArBinario::Unhijo(NABB* antes, NABB* nuevo){//REEMPLAZA EL NODO A ELIMINAR POR EL HIJO
    if(antes->npadre){
        if(antes->num == antes->npadre->Izq->num) antes->npadre->Izq=nuevo;
        else if(antes->num == antes->npadre->Der->num)
            antes->npadre->Der=nuevo;
    }
    if(nuevo)nuevo->npadre=antes->npadre;
}

//********************************Busca el nodo mas grande entre los mas pequeños*******************************
NABB* ArBinario::IzquierdoDerecho(NABB* Naux){
    if(Naux==nullptr) return NULL;
    else if(Naux->Izq) return IzquierdoDerecho(Naux->Izq);
    else return Naux;
}

NABB* ArBinario::DerechoIzquierdo(NABB* Naux){
    if(Naux==nullptr) return NULL;
    else if(Naux->Der) return DerechoIzquierdo(Naux->Der);
    else return Naux;
}

//******************************** REEMPLAZAR*******************************
void ArBinario::reemplazar(int n ,int nvalor){
    if(Raiz!=nullptr){
        if(busqueda(n)){
            NABB* aux=NEncontrado;
            NABB* minimo=IzquierdoDerecho(NEncontrado->Der);
            NABB* maximo=DerechoIzquierdo(NEncontrado->Izq);
            if(aux->num>minimo->num && aux->num < maximo->num){
                aux->num=nvalor;
            }else{
                Eliminar(n);
                Insertar(nvalor);
            }

        }
    }
}
