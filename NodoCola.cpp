#include "NodoCola.h"

NodoCola::NodoCola(){
    prioridad = 0;
    elemento = Proceso();
    siguiente = NULL;
    //constructor por defecto
    }
    NodoCola::NodoCola(Proceso e, int prioridad, NodoCola*sig )
    {
    elemento = e;
    siguiente = sig;
    this->prioridad = prioridad;
    }
    NodoCola::~NodoCola(){
    //Nothing to do here (destructor)
}