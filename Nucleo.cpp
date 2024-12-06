#include <iostream>
#include "Nucleo.h"
#include "Proceso.h"
using namespace std;

Nucleo::Nucleo(int id, const Cola& colaEspera) 
    : nucleoId(id), procesoActual(nullptr), colaEsperaNucleo(colaEspera) {
    libre = true;  // Inicia como libre
} 
Nucleo::Nucleo() 
    : nucleoId(-1), procesoActual(nullptr), colaEsperaNucleo() {
    libre = true;  // Inicia como libre
}

bool Nucleo::estaLibre() {
    return procesoActual == NULL;
}

void Nucleo::asignarProceso(Proceso* proceso) {
    procesoActual = proceso;
}

void Nucleo::liberarProceso() {
    procesoActual = NULL;
}

void Nucleo::mostrarProcesoActual() {
    if (procesoActual != nullptr) {
        cout << "Núcleo " << nucleoId << " ejecuta PID: " << procesoActual->getPID()
             << ", PPID: " << procesoActual->getPPID()
             << ", Tiempo restante: " << procesoActual->getTiempoVida() << endl;
    } else {
        cout << "Núcleo " << nucleoId << " está libre." << endl;
    }
}

Proceso* Nucleo::getProceso() { 
    if (procesoActual != nullptr) {
        return procesoActual; 
    } else {
        return nullptr;
    }
}

int Nucleo::longitudColaEsperaNucleo() {
    return colaEsperaNucleo.get_longitud();
}

int Nucleo::getId() const{
    return nucleoId;
}