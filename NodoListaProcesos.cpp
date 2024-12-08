    #include "NodoListaProcesos.h"
    
    // Constructor por defecto
    NodoListaProcesos::NodoListaProcesos() : valor(), siguiente(nullptr), anterior(nullptr) {}

    // Constructor con parámetros
    NodoListaProcesos::NodoListaProcesos(Proceso p, NodoListaProcesos* sig, NodoListaProcesos* ant) 
        : valor(p), siguiente(sig), anterior(ant) {}

    Proceso& NodoListaProcesos::obtenerValor() {
        return valor;  // Devuelve una referencia al atributo valor
    }
    NodoListaProcesos* NodoListaProcesos::obtenerSiguiente() {
        return siguiente;  // Devuelve el puntero al siguiente nodo
    }

    // Destructor
    NodoListaProcesos::~NodoListaProcesos() {  
        siguiente = nullptr;
        anterior = nullptr;
    }
