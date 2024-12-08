#include "NodoBST.h"
#include "Proceso.h"
#include "Lista.h"
#include <iostream>

using namespace std;

NodoBST::NodoBST(Lista lproc, NodoBST *izq, NodoBST *der, int prio){
    // hacer un try catch para asegurar que la prioridad pasada y la de la lista sean iguales

    listaProc = lproc;
    hi = izq;
    hd = der;
    try { // try catch para asegurar que la prioridad pasada y la de la lista sean iguales, si la lista es vacíano se compara
        if ((!lproc.es_vacia()) && (prio != lproc.coger(0).get_prioridad())) {
            throw "La prioridad del nodo no coincide con la prioridad de la lista de procesos; no crea NodoBST";
        }
    } catch (const char* e) {
        cerr << e << endl;
    }
    prioridad = prio; // = lproc.coger(0).get_prioridad() cuidado al insertar listas vacías ✨Violacion de segmento✨
}

NodoBST::~NodoBST(){
    
}

Lista NodoBST::get_lista(){
    return listaProc;
}

NodoBST* NodoBST::get_izquierdo(){
    return hi;
}

NodoBST* NodoBST::get_derecho(){
    return hd;
}

int NodoBST::get_prioridad(){
    return prioridad;
}

void NodoBST::set_izquierdo(NodoBST *izq){
    hi = izq;
}

void NodoBST::set_derecho(NodoBST *der){
    hd = der;
}

void NodoBST::set_prioridad(int prio){
    prioridad = prio;
}

void NodoBST::mostrar(){
    cout << "Prioridad: " << prioridad << endl;
    listaProc.mostrar();
}