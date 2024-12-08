#ifndef NODOLISTA_H
#define NODOLISTA_H

#include "Nucleo.h"

class NodoLista {
private:
    Nucleo valor;
    NodoLista* siguiente; // Puntero al siguiente nodo
    NodoLista* anterior; // Puntero al nodo anterior
    friend class Lista; // La clase Lista puede acceder a los datos privados de NodoLista

public:
    NodoLista(); // Constructor vacío
    NodoLista(Nucleo p, NodoLista* sig = nullptr, NodoLista* ant = nullptr);
    Nucleo& obtenerValor(); // Obtener el valor del nodo
    NodoLista* obtenerSiguiente();
    ~NodoLista(); // Destructor
};

typedef NodoLista* pNodoLista; // Definimos un puntero a NodoLista para facilitar la lectura del código

#endif // NODOLISTA_H