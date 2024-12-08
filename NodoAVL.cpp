#include "NodoAVL.h"
#include "Lista.h"
#include "Proceso.h"
#include <iostream>
using namespace std;

NodoAVL::NodoAVL(Lista listaProcesos, NodoAVL *izq, NodoAVL *der, int prioridad){
    this->listaProcesos = listaProcesos;
    hi = izq;
    hd = der;
    this -> prioridad = prioridad;
}

NodoAVL::~NodoAVL(){
    //dtor
}

void NodoAVL::verLista(){
    listaProcesos.mostrar();
}

Lista NodoAVL::getLista(){
    return listaProcesos;
}

NodoAVL* NodoAVL::getIzq(){
    return hi;
}

NodoAVL* NodoAVL::getDerch(){
    return hd;
}

int NodoAVL::getPrioridad(){
    return prioridad;
}

void NodoAVL::getIzq(NodoAVL *izq){
    hi = izq;
}

void NodoAVL::getDerch(NodoAVL *der){
    hd = der;
}

void NodoAVL::getPrioridad(int prioridad){
    this -> prioridad = prioridad;
}

void NodoAVL::mostrar(){
    cout << "Prioridad: " << prioridad << endl;
    listaProcesos.mostrar();
}