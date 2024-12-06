#ifndef NODOCOLA_H 
#define NODOCOLA_H
#include <iostream>
#include "Proceso.h"

class NodoCola
{   
    friend class Cola;
    private:
        NodoCola *siguiente; //puntero
        Proceso elemento;
        int prioridad;
    public:
        NodoCola(); //Constructor
        NodoCola(Proceso e, int prioridad, NodoCola*sig = NULL);
        ~NodoCola();
};
#endif // NODOCOLA_H