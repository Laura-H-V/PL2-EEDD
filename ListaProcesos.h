#ifndef LISTAPROCESOS_H
#define LISTAPROCESOS_H

#include "NodoListaProcesos.h"
#include "Proceso.h"
#include <iostream>

class ListaProcesos {  
    
private:
    Proceso valor;  
    pNodoListaProcesos cabeza;  
    pNodoListaProcesos cola;  

public:
    ListaProcesos(); // Constructor
    ~ListaProcesos(); // Destructor
    void insertarInicio(Proceso v);  //Insertar izquierda
    void insertarFinal(Proceso v);  //Insertar derecha
    void insertarEnPosicion(Proceso v, int pos);  
    void eliminar(Proceso v);  
    bool esVacia();
    Proceso* buscar(int pid);  
    void mostrar();
    int longitud();
    Proceso inicio();  
    Proceso fin(); 
    pNodoListaProcesos obtenerCabeza() const;  
};

#endif // LISTAPROCESOS_H
