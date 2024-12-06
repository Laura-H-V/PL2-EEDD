#include "Proceso.h"

// Constructor por defecto
Proceso::Proceso() : PID(0), PPID(0), inicio(0), tiempoVida(0), prioridad(0), nucleoAsignado(-1) {}

// Constructor con parámetros
Proceso::Proceso(int pid, int ppid, int ini, int tiempo, int pri, int nucleo) 
    : PID(pid), PPID(ppid), inicio(ini), tiempoVida(tiempo), prioridad(pri), nucleoAsignado(nucleo) {}

// Métodos de acceso
int Proceso::getPID() const { return PID; }
int Proceso::getPPID() const { return PPID; }
int Proceso::getPrioridad() const { return prioridad; }
int Proceso::getTiempoVida() const { return tiempoVida; }
int Proceso::getInicio() const { return inicio; }
int Proceso::getNucleoAsignado() const { return nucleoAsignado; }
int Proceso::getLlegada() const { return llegada; }
void Proceso::setLlegada(int tiempo) { llegada = tiempo; }

// Métodos de modificación
void Proceso::setNucleoAsignado(int nucleo) { nucleoAsignado = nucleo; }
void Proceso::setInicio(int valor) { inicio = valor; }
void Proceso::setTiempoVida(int valor) { tiempoVida = valor; }

// Destructor
Proceso::~Proceso() {}
