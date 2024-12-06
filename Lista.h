#ifndef LISTA_H
#define LISTA_H

#include "NodoLista.h"
#include "Nucleo.h"
#include "Proceso.h"
#include <iostream>

class Lista {
private:
    Proceso valor;  // Cambiar Nucleo por Proceso
    pNodoLista cabeza;
    pNodoLista cola;

public:
    Lista(); // Constructor
    ~Lista(); // Destructor
    void insertarInicio(Proceso v);  // Cambiar Nucleo por Proceso
    void insertarFinal(Proceso v);  // Cambiar Nucleo por Proceso
    void insertarEnPosicion(Proceso v, int pos);  // Cambiar Nucleo por Proceso
    void eliminar(Proceso v);  // Cambiar Nucleo por Proceso
    bool esVacia();
    Proceso* buscar(int id);  // Cambiar Nucleo* por Proceso*
    void mostrar();
    int longitud();
    Proceso inicio();  // Cambiar Nucleo por Proceso
    Proceso fin();  // Cambiar Nucleo por Proceso
    pNodoLista obtenerCabeza() const;
};

#endif // LISTA_H