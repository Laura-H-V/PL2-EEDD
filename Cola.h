#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"

class Cola{

    private:
        NodoCola * primero;
        NodoCola * ultimo;
        int longitud;
    public:
        Cola(); ~Cola();
        void encolar(Proceso elemento, int prioridad);
        Proceso inicio();
        Proceso fin();
        Proceso desencolar();
        int get_longitud();
        bool es_vacia();
        void mostrarCola(); //No es correcto, se implementa para ver que está creada correctamente
        
};
#endif // COLA_H