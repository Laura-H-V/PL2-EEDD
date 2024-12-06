#ifndef PLANIFICADOR_H
#define PLANIFICADOR_H

#include "Pila.h"
#include "Nucleo.h"
#include "Cola.h"
#include "Lista.h"
#include <iostream>


class Planificador {
private:
    Lista listaNucleos;
    Pila pilaProcesos;
    //Cola colaEspera;
    int tiempoInicio;
    int numeroProcesos;
    int TiempoTotalProcesos;
    pNodoLista cabeza;
public:
    Planificador();
    void mostrarColaEspera();
    void crearPilaProcesos();
    void asignarProcesoANucleo(Proceso* proceso);
    void liberarNucleo(int idNucleo);
    void mostrarProcesos();
    void borrarProcesos();
    void mostrarProcesosEnEjecucion();
    void simularTiempo(int minutos);
    void ejecutarTodosLosProcesos();
    void decrementarTiempo();
    void setTiempoInicio(int tTotal);
    void setNumeroProcesos(int num);
    void getNumeroProcesos();

    //Funciones adicionales para implementar la lista de núcleos
    void agregarNucleo(); //Si tiene más de dos procesos en la cola de espera
    void eliminarNucleo(); //Si tiene menos de dos procesos en la cola de espera
    void eliminarNucleosLibres(); //Eliminar núcleos vacíos cuando haya al menos dos núcleos libres
    Nucleo nucleoMasOcupado(); //Con más procesos en espera
    Nucleo& nucleoMenosOcupado(); //Con menos procesos en espera
    int numeroNucleos();
    void mostrarLista();
};

#endif // PLANIFICADOR_H
