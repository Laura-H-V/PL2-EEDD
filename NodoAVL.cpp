#include "NodoAVL.h"

NodoAVL::NodoAVL(string nombre, NodoAVL *izq, NodoAVL *der){
    nombre = nombre;
    hi = izq;
    hd = der;
}

NodoAVL::~NodoAVL(){
    //dtor
}

void NodoAVL::verNombre(){
    cout << nombre << endl;
}

