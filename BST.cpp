#include "BST.h"
#include <vector>
#include <algorithm>


BST::BST() {
    raiz = nullptr;
}

BST::BST(NodoBST *raiz) {
    this->raiz = raiz;
}

BST::BST(ListaProcesos lproc, NodoBST *hIz, NodoBST *hDer, int prio) {
    try { // try catch para asegurar que la prioridad pasada y la de la lista sean iguales, si la lista es vacíano se compara
        if ((!lproc.es_vacia()) && (prio != lproc.coger(0).get_prioridad())) {
            throw "La prioridad del nodo no coincide con la prioridad de la lista de procesos; no crea Arbol";
        }
    } catch (const char* e) {
        cerr << e << endl;
    }
    raiz = new NodoBST(lproc, hIz, hDer, prio);
}

BST::~BST() {
}

void BST::verInorden() {
    if (raiz == nullptr) {
        cout << "El árbol está vacío" << endl;
    } else {
        verInorden(raiz);
    }
}


void BST::verInorden(NodoBST* nodo) {
    if (nodo != nullptr) {
        // Recorrer subárbol izquierdo
        verInorden(nodo->hi);

        // Imprimir la prioridad del nodo
        cout << "Nodo con prioridad: " << nodo->prioridad << endl;

        // Imprimir los procesos de la lista asociada al nodo
        cout << "Procesos en la lista:" << endl;
        nodo->listaProc.mostrar(); // Acceso directo al miembro listaProc

        // Recorrer subárbol derecho
        verInorden(nodo->hd);
    }
}

// modificar pasar parametros de proceso y arbol
void BST::insertar_arbol(Proceso proc, NodoBST*& nodo) {
    if (nodo == nullptr) {
        // Crear un nuevo nodo si no existe uno con la prioridad
        ListaProcesos nuevaLista;
        nodo = new NodoBST(nuevaLista, nullptr, nullptr, proc.get_prioridad());
        cout << "Nodo creado con prioridad: " << proc.get_prioridad() << endl;
        nodo->listaProc.insertar_proceso(proc);
        cout << "Proceso insertado en la lista del nodo con prioridad: " << proc.get_prioridad() << endl;
        return;
    }

    if (proc.get_prioridad() == nodo->prioridad) {
        // Insertar en la lista si ya existe un nodo con la misma prioridad
        nodo->listaProc.insertar_proceso(proc);
        cout << "Proceso insertado en la lista del nodo con prioridad: " << proc.get_prioridad() << endl;
    } else if (proc.get_prioridad() < nodo->prioridad) {
        // Recorrer hacia la izquierda si la prioridad del proceso es menor
        insertar_arbol(proc, nodo->hi);
    } else {
        // Recorrer hacia la derecha si la prioridad del proceso es mayor
        insertar_arbol(proc, nodo->hd);
    }
}

void BST::insertar(Proceso proc) {
    insertar_arbol(proc, raiz);
}

NodoBST* BST::get_raiz() {
    return raiz;
}

void BST::buscar(int prioridad) {
    buscar(prioridad, raiz);
}

void BST::buscar(int prioridad, NodoBST *nodo) {
    if (nodo == nullptr) {
        cout << "No se ha encontrado un nodo con prioridad " << prioridad << endl;
    } else if (nodo->prioridad == prioridad) {
        cout << "Nodo con prioridad " << prioridad << " encontrado" << endl;
        cout << "Procesos en la lista:" << endl;
        nodo->listaProc.mostrar();
    } else if (nodo->prioridad < prioridad) {
        buscar(prioridad, nodo->hd);
    } else {
        buscar(prioridad, nodo->hi);
    }
}

void BST::mostrarNiveles() {
    mostrarNiveles(raiz);
}

void BST::mostrarNiveles(NodoBST *nodo) {
    if (nodo != nullptr && !nodo->listaProc.es_vacia()) {
        mostrarNiveles(nodo->hi);
        mostrarNiveles(nodo->hd);
        cout << "Prioridad: " << nodo->prioridad << endl;
    }
}

void BST::mostrarNivelesMayorMenor(){
    mostrarNivelesMayorMenor(raiz);
}

void BST::mostrarNivelesMayorMenor(NodoBST* nodo) {
    if (nodo == nullptr) {
        cout << "El arbol esta vacio o el nodo proporcionado es nulo" << endl;
        return;
    }
    std::vector<NodoBST*> nodos;
    llenarVector(nodo, nodos); // Función auxiliar para llenar el vector con nodos del árbol
    sort(nodos.begin(), nodos.end(), [](NodoBST* a, NodoBST* b) {
        return a->listaProc.get_longitud() > b->listaProc.get_longitud();
    });
    for (NodoBST* n : nodos) {
        cout << "Nodo con prioridad: " << n->prioridad 
            << ", Cantidad de procesos: " << n->listaProc.get_longitud() << endl;
    }
}

void BST::llenarVector(NodoBST* nodo, std::vector<NodoBST*>& nodos) { // Función auxiliar para recorrer el árbol y llenar el vector
    if (nodo != nullptr) {
        nodos.push_back(nodo); // Agregar el nodo al vector
        llenarVector(nodo->hi, nodos); // Recorrer el subárbol izquierdo
        llenarVector(nodo->hd, nodos); // Recorrer el subárbol derecho
    }
}

float BST::tiempoPromedioProcesos(int prioridad) {
    return tiempoPromedioProcesos(prioridad, raiz);
}

float BST::tiempoPromedioProcesos(int prioridad, NodoBST* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    if (nodo->prioridad == prioridad) {
        float tiempoTotal = 0;
        float cantidadProcesos = nodo->listaProc.get_longitud();
        if (cantidadProcesos == 0) {
            return 0;
        }
        for (int i = 0; i < cantidadProcesos; ++i) {
            Proceso p = nodo->listaProc.coger(i);
            tiempoTotal += p.get_tiempo_ejecucion(); // O cambiar a get_tiempo_ejecucion si es correcto
        }
    return tiempoTotal / cantidadProcesos;
    } else if (prioridad < nodo->prioridad) {
        return tiempoPromedioProcesos(prioridad, nodo->hi);
    } else {
        return tiempoPromedioProcesos(prioridad, nodo->hd);
    }
}