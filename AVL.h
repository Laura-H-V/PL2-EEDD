#ifndef AVL_H
#define AVL_H
#include "NodoAVL.h"

class AVL{
    public:
        AVL();
        AVL(NodoAVL *r);
        AVL(string nombre, NodoAVL *hIz=NULL, NodoAVL *hDer=NULL);
        virtual ~AVL();
        void verInOrden(); //Al insertar se hace en orden, ya está ordenado
        void verInOrden(NodoAVL *arb);

        void insertar(string nombre);
        void insertar(string nom, NodoAVL *nodo);
    protected: 
    private:
        NodoAVL *raiz;
};

#endif //AVL_H