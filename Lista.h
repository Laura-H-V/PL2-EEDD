#ifndef LISTA_H
#define LISTA_H

#include "NodoLista.h"
#include "Proceso.h"
#include <iostream>

class Lista {
private:
    Proceso valor;  
    pNodoLista cabeza;
    pNodoLista cola;

public:
    Lista(); // Constructor
    ~Lista(); // Destructor
    void insertarInicio(Proceso v);  
    void insertarFinal(Proceso v); 
    void insertarEnPosicion(Proceso v, int pos);  
    void eliminar(Proceso v);  
    bool esVacia();
    Proceso* buscar(int id);  
    void mostrar();
    int longitud();
    Proceso inicio();  
    Proceso fin(); 
    pNodoLista obtenerCabeza() const;
};

#endif // LISTA_H