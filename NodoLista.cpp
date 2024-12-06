    #include "NodoLista.h"

    // Constructor por defecto
    NodoLista::NodoLista() : valor(), siguiente(nullptr), anterior(nullptr) {}

    // Constructor con parámetros
    NodoLista::NodoLista(Proceso p, NodoLista* sig, NodoLista* ant) 
        : valor(p), siguiente(sig), anterior(ant) {}

    Proceso& NodoLista::obtenerValor() {
        return valor;  // Devuelve una referencia al atributo valor
    }
    NodoLista* NodoLista::obtenerSiguiente() {
        return siguiente;  // Devuelve el puntero al siguiente nodo
    }

    // Destructor
    NodoLista::~NodoLista() {
        siguiente = nullptr;
        anterior = nullptr;
    }