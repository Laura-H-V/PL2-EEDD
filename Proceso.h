#ifndef PROCESO_H
#define PROCESO_H

class Proceso {
private:
    int PID;
    int PPID; 
    int inicio;
    int tiempoVida;
    int prioridad;
    int tiempoSistema;
    int nucleoAsignado;
    int llegada;


public:
    Proceso(); // Declaración del constructor por defecto
    Proceso(int pid, int ppid, int ini, int tiempo, int pri, int nucleo = -1,int tiempoSistema=0); // Constructor con parámetros

    // Métodos de acceso
    int getPID() const;
    int getPPID() const;
    int getPrioridad() const;
    int getTiempoVida() const;
    int getInicio() const;
    int getNucleoAsignado() const;
    int getLlegada() const;
    void setLlegada(int tiempo) ;


    // Métodos de modificación
    void setNucleoAsignado(int nucleo);
    void setInicio(int valor);
    void setTiempoVida(int valor);
    int getTiempoSistema();
    void setTiempoSistema(int t);

    ~Proceso(); // Destructor
};

#endif // PROCESO_H
