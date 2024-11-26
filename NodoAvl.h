#ifndef NODOAVL_h
#define NODOAVL_h
#include <iostream>
#include <stdio.h>

using namespace std;
class NodoAVL{
    friend class AVL;
    public:
        NodoAVL(string name, NodoAVL *izq=NULL, NodoAVL *der=NULL);
        virtual ~NodoAVL();
        void verNombre();//Accede al valor de nombre
    private:
        string nombre;
        NodoAVL *hi,*hd;
};

#endif //NODOAVL_H