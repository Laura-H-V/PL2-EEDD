#ifndef AVL_H
#define AVL_H
#include "NodoAVL2.h"
#include "Lista.h"

class AVL{
    public:
        AVL();
        AVL(NodoAVL *r);
        AVL(Lista listaProcesos, NodoAVL *hIz=NULL, NodoAVL *hDer=NULL, int prioridad=5);
        virtual ~AVL();
        void verInOrden(); //Mostrará el hijo izq, la raíz y el hijo derecho
        void verInOrden(NodoAVL *arb);
        int contarNodos(); // Cuenta los nodos del árbol
        void buscar(int prioridad); // Muestra procesos en el arbol de una prioridad dada
        void buscar(int prioridad, NodoAVL *nodo);

        void insertar(Proceso proc);
        void insertar(Proceso proc, NodoAVL *nodo);

        NodoAVL* get_raiz();
        void mostrarNiveles(); // Muestra los niveles del árbol
        void mostrarNiveles(NodoAVL *nodo);

        void mostrarNivelesMayorMenor(); // Muestra los niveles del árbol de mayor a menor
        void mostrarNivelesMayorMenor(NodoAVL *nodo);

        //float tiempoPromedioProcesos(int prioridad); // Devuelve tiempo promedio de ejecución de los procesos de una prioridad dada
        //float tiempoPromedioProcesos(int prioridad, NodoAVL *nodo);        
    protected: 
    private:
        NodoAVL *raiz;
};

#endif //AVL_H