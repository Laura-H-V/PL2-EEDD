#ifndef LISTA_H
#define LISTA_H

#include "NodoLista.h"
#include "Nucleo.h"
#include "Proceso.h"
#include <iostream>

class Lista {
private:
    Nucleo valor;
    pNodoLista cabeza; // Puntero al primer nodo de la lista
    pNodoLista cola;   // Puntero al último nodo de la lista

public:

    Lista(); // Constructor
    ~Lista(); // Destructor
    void insertarInicio(Nucleo v); // Inserta al inicio de la lista
    void insertarFinal(Nucleo v); // Inserta al final de la lista
    void insertarEnPosicion(Nucleo v, int pos); // Inserta en una posición específica
    void eliminar(Nucleo v); // Elimina un nodo con un valor específico
    bool esVacia(); // Verifica si la lista está vacía
    Nucleo* buscar(int id); // Busca un proceso en la lista y devuelve un puntero a él
    void mostrar(); // Muestra todos los elementos de la lista
    int longitud(); // Retorna la longitud de la lista
    Nucleo inicio();
    Nucleo fin();
    pNodoLista obtenerCabeza() const; 
    
};

#endif // LISTA_H