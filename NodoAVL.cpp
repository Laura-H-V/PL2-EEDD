#include "NodoAVL.h"
#include "ListaProcesos.h"
#include "Proceso.h"
#include <iostream>
using namespace std;

NodoAVL::NodoAVL(ListaProcesos listaProcesos, NodoAVL *izq, NodoAVL *der, int prioridad){
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

ListaProcesos NodoAVL::getLista(){
    return listaProcesos;
}

NodoAVL* NodoAVL::getIzq(){
    return hi;
}

NodoAVL* NodoAVL::getDerch(){
    return hd;
}

NodoAVL* NodoAVL::getPadre(){
    return padre;
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

void NodoAVL::mostrarPadre() {
    if (padre) {
        cout << "Nodo actual con prioridad: " << prioridad << endl;
        cout << "Padre con prioridad: " << padre->getPrioridad() << endl;

        if (padre->getIzq() == this) {
            cout << "Soy hijo izquierdo." << endl;
        } else if (padre->getDerch() == this) {
            cout << "Soy hijo derecho." << endl;
        }
    } else {
        cout << "Soy la raíz, no tengo padre." << endl;
    }
}

void NodoAVL::setIzq(NodoAVL *izq) {
    hi = izq;
    if (izq != nullptr) {
        izq->padre = this;
    }
}

void NodoAVL::setDerch(NodoAVL *der) {
    hd = der;
    if (der != nullptr) {
        der->padre = this;
    }
}