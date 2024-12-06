#ifndef NUCLEO_H
#define NUCLEO_H

#include <iostream>
#include "Proceso.h"
#include "Cola.h"

class Nucleo {
public:
    bool libre;
    int nucleoId;        // Identificador del núcleo
    Proceso* procesoActual; // Proceso en ejecución
    Cola colaEsperaNucleo;

    Nucleo(int id, const Cola& colaEsperaNucelo);
    Nucleo(); 
    bool estaLibre(); // Verifica si el núcleo está libre
    void asignarProceso(Proceso* proceso); // Asigna un proceso al núcleo
    void liberarProceso(); // Libera el núcleo
    void mostrarProcesoActual();
    Proceso* getProceso();
    int longitudColaEsperaNucleo();
    int getId() const;
};

#endif // NUCLEO_H
