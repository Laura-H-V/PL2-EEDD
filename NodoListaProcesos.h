#ifndef NODOLISTAPROCESOS_H
#define NODOLISTAPROCESOS_H

#include "Proceso.h"

class NodoListaProcesos {  // Cambiado de 'NodoLista' a 'NodoListaProcesos'
private:
    Proceso valor;
    NodoListaProcesos* siguiente;  // Cambiado de 'NodoLista' a 'NodoListaProcesos'
    NodoListaProcesos* anterior;  // Cambiado de 'NodoLista' a 'NodoListaProcesos'
    friend class ListaProcesos; // La clase Listaprocesos puede acceder a los datos privados de NodoListaProcesos

public:
    NodoListaProcesos(); // Constructor vacío
    NodoListaProcesos(Proceso p, NodoListaProcesos* sig = nullptr, NodoListaProcesos* ant = nullptr);  // Cambiado de 'NodoLista' a 'NodoListaProcesos'
    Proceso& obtenerValor(); // Obtener el valor del nodo
    NodoListaProcesos* obtenerSiguiente();  // Cambiado de 'NodoLista' a 'NodoListaProcesos'
    ~NodoListaProcesos(); // Destructor
};

typedef NodoListaProcesos* pNodoListaProcesos;  // Cambiado de 'NodoLista' a 'NodoListaProcesos'

#endif // NODOLISTAPROCESOS_H
