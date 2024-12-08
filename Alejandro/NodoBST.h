#ifndef NODOBST_H
#define NODOBST_H
#include "Proceso.h"
#include "Lista.h"
#include <iostream>
#include <string>

using namespace std;
class NodoBST 
{
    friend class BST;

    private:
        Lista listaProc;
        NodoBST *hi;
        NodoBST *hd;
        int prioridad; 
    public:
        // NodoBST(); no necesario porque el constructor si solo se le pasa una lista de procesos, crea un nodo con prioridad 5 y sin hojas
        NodoBST(ListaProcesos lproc, NodoBST *hIz = nullptr, NodoBST *hDer = nullptr, int prioridad = 5);
        virtual ~NodoBST();

        // no necesario porque tenemos friend class BST
        ListaProcesos get_lista();
        NodoBST* get_izquierdo();
        NodoBST* get_derecho();
        int get_prioridad();

        void set_izquierdo(NodoBST *hIz);
        void set_derecho(NodoBST *hDer);
        void set_prioridad(int prioridad);
        void mostrar();
};
#endif // NODOBST_H