#include "JSON.h"
#include <iostream>
#include "json.hpp"
#include <fstream>
//#include <unistd.h>
using namespace std;
using json = nlohmann::json;

JSON::JSON()
{
    //ctor
}

void JSON::PJSON(){
    int dimension;
    json j4;//declaro un objeto de tipo json

    ifstream reader("PruebaJson.json");
    if (reader.fail()){
        cout << "El archivo no existe, verifique que la ruta y el archivo exista." << endl << endl;
    }else{
        reader>>j4;//paso el contenido al reader.
        dimension = j4["dimension"];//leo el dato en la etiqueta "dimension"
        cout<<"\nDimension: "<<dimension<<endl;

        //cout<<"cantidad de listas en casillas: "<<j4.at("casillas").at("dobles").size()<<endl;
        //obtengo el tamaño de la lista con etiqueta "dobles" que esta en la lista con etiqueta "casillas"
        int cant = j4.at("casillas").at("dobles").size();
        for (int i = 0; i < cant; i++){
            json coordenadas1 = j4.at("casillas").at("dobles")[i];//obtengo el arreglo formado por los elementos en la posicion i de la lista dobles
            cout<<coordenadas1["x"]<<","<<coordenadas1["y"]<<endl;//coordenadas1["x"] imprime el dato con etiqueta "x". coordenadas1["y"] dato con etiqueta "y"
            //la linea de arriba es equivalente a
            //cout<<coordenadas1["x"];//lo que esta en la etiqueta x
            //cout<<","<<coordenadas1["y"]<<endl;//lo que esta en la etiqueta y
        }

        /*
        //leo la lista de casillas
        json casillas = j4["casillas"];
        //leo la sublista doble
        json dobles = casillas["dobles"];
        //recorro la lista de dobles
        for (int i = 0; i < dobles.size(); i++){
            json coordenadas1 = dobles[i];
            cout<<coordenadas1["x"]<<","<<coordenadas1["y"]<<endl;
        }*/
    }
    reader.close();
}
