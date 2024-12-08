#ifndef AVL_H
#define AVL_H
#include "NodoAVL.h"
#include "Lista.h"
#include <vector>


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

        NodoAVL* getRaiz();
        void mostrarNiveles(); // Muestra los niveles del árbol
        void mostrarNiveles(NodoAVL *nodo);

        void mostrarNivelesMayorMenor(); // Muestra los niveles de mayor a menor 
        void mostrarNivelesMayorMenor(NodoAVL *nodo);

        void llenarVector(NodoAVL* nodo, std::vector<NodoAVL*>& nodos); // Guarda los nodos

        float tiempoPromedioEjecucion(int prioridad); // Devuelve tiempo promedio de ejecución de los procesos de una prioridad dada
        float tiempoPromedioEjecucion(int prioridad, NodoAVL *nodo);        
    protected: 
    private:
        NodoAVL *raiz;
};

#endif //AVL_H