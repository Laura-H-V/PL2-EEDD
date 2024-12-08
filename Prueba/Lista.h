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
    void insertarInicio(Proceso v);  //Insertar derecha
    void insertarFinal(Proceso v);  //Insertar izquierda
    void insertarEnPosicion(Proceso v, int pos);  
    void eliminar(Proceso v);  
    bool esVacia();
    Proceso* buscar(int pid);  
    void mostrar();
    int longitud();
    Proceso inicio();  
    Proceso fin(); 
    pNodoLista obtenerCabeza() const;
};

#endif // LISTA_H