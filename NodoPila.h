#ifndef NODOPILA_H
#define NODOPILA_H

#include "Proceso.h"

class NodoPila {
private:
    Proceso valor;
    NodoPila *siguiente; // Next
    friend class Pila; // Friend class

public:
    NodoPila(); // Constructor vacío
    NodoPila(Proceso p, NodoPila* sig = nullptr);
    ~NodoPila(); // Destructor
};

typedef NodoPila* pNodoPila; // Pointer to NodoPila

#endif // NODOPILA_H
