#ifndef BST_H
#define BST_H
#include "NodoBST.h"
#include <vector>

class BST
{
    private:
        NodoBST *raiz;

    public:
        BST();
        BST(NodoBST *raiz);
        BST(ListaProcesos lproc, NodoBST *hIz = NULL, NodoBST *hDer = NULL, int prioridad = 5);
        virtual ~BST();
        void verInorden(); // Muestra el árbol en inorden
        int contarNodos(); // Cuenta los nodos del árbol
        void insertar(Proceso proc); // Inserta un proceso en el árbol
        NodoBST* get_raiz();

        void buscar(int prioridad); // Muestra procesos en el arbol de una prioridad dada
        void buscar(int prioridad, NodoBST *nodo);

        void mostrarNiveles(); // Muestra los niveles del árbol
        void mostrarNiveles(NodoBST *nodo);

        void mostrarNivelesMayorMenor(); // Muestra los niveles del árbol de mayor a menor
        void mostrarNivelesMayorMenor(NodoBST *nodo);

        float tiempoPromedioProcesos(int prioridad); // Devuelve tiempo promedio de ejecución de los procesos de una prioridad dada
        float tiempoPromedioProcesos(int prioridad, NodoBST *nodo);

    protected:
        void verInorden(NodoBST *nodo); 
        void insertar_arbol(Proceso proc, NodoBST *&arb); // Inserta un proceso en el árbol
        void llenarVector(NodoBST* nodo, std::vector<NodoBST*>& nodos); // Recolecta nodos en un vector
};


/*    protected:
        NodoBST* get_raiz();
        void set_raiz(NodoBST*);
        bool buscar(int prioridad, NodoBST*);// Busca un proceso en el árbol
        bool arbolVacio(NodoBST*); // Verifica si el árbol está vacío
        NodoBST* insertarArbol(Proceso, NodoBST*); // Realiza un recorrido postorden del árbol
        void postorden(NodoBST*); // Realiza un recorrido postorden del árbol
        ~BST();*/

#endif // BST_