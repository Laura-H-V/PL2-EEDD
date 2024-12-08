#ifndef NODOAVL_h
#define NODOAVL_h
#include <iostream>
#include <stdio.h>
#include "Proceso.h"
#include "Lista.h"
using namespace std;

class NodoAVL{
    friend class AVL;
    public:
        NodoAVL(Lista listaProc, NodoAVL *izq=NULL, NodoAVL *der=NULL, int prioridad=5);
        virtual ~NodoAVL();
        void verLista();//Accede al valor de nombre

        //Para trabajar con listas
        Lista getLista();
        NodoAVL* getIzq();
        NodoAVL* getDerch();
        int getPrioridad();

        void getIzq(NodoAVL *izq);
        void getDerch(NodoAVL *der);
        void getPrioridad(int prioridad);
        void mostrar();
    private:
        Lista listaProcesos;
        NodoAVL *hi,*hd;
        int prioridad;
};

#endif //NODOAVL_H