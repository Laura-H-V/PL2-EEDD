#include "AVL2.h"

AVL::AVL(){ // Crea un árbol vacío
//constructor
    Lista listaVacia;
        raiz = new NodoAVL(listaVacia, nullptr, nullptr, 0); // Prioridad = 0 para P0
}

AVL::AVL(NodoAVL *r){
    raiz = r; // La raiz es el primer nodo que se pasa como parámetro
}

AVL::AVL(Lista listaProcesos, NodoAVL *hIz, NodoAVL *hDer, int prioridad){  //constructor que crea árbolBin con dato y dos subárboles
    raiz = new NodoAVL(listaProcesos, hIz, hDer,prioridad); //llamamos al constructor del Nodo y raiz es un puntero al Nodo creado
}

AVL::~AVL(){
    //dtor
}

//ver en orden desde la raíz
void AVL::verInOrden() {
    if (!raiz) {
        cout << "El árbol está vacío" << endl;
        return;
    }
    verInOrden(raiz);
}

void AVL::verInOrden(NodoAVL *arb) {
    if (!arb) return;

    verInOrden(arb->hi); // Recorrer subárbol izquierdo

    if (arb->prioridad != 0) { // Ignorar nodo P0
        cout << "Nodo con prioridad: " << arb->prioridad << endl;
        arb->listaProcesos.mostrar();
    }

    verInOrden(arb->hd); // Recorrer subárbol derecho
}

void AVL::eliminarP0() {
    if (!raiz || raiz->prioridad != 0) return;

    NodoAVL *nuevaRaiz = nullptr;

    // Determinar nueva raíz
    if (raiz->hi) {
        nuevaRaiz = raiz->hi;
        // Insertar subárbol derecho en el nodo más a la derecha del nuevo árbol
        if (raiz->hd) {
            NodoAVL *temp = nuevaRaiz;
            while (temp->hd) temp = temp->hd;
            temp->hd = raiz->hd;
        }
    } else if (raiz->hd) {
        nuevaRaiz = raiz->hd;
    }

    delete raiz; // Liberar memoria del nodo ficticio
    raiz = nuevaRaiz;
}

//ver en orden dependiendo del nodo
/*oid AVL::verInOrden(NodoAVL *arb){  
    if(arb){   //Recorre y muestra el árbol de forma recursiva llamando la hijo izquierdo, luego el nodo (raíz) y luego el hijo derecho
        verInOrden(arb->hi);
        cout << "Nodo con prioridad: " << arb->prioridad << endl;
        cout << "Procesos en la lista:" << endl;
        arb->listaProcesos.mostrar(); 
        verInOrden(arb->hd);
    }
    if (arb != nullptr) {
        // Recorrer subárbol izquierdo
        verInOrden(arb->hi);

        // Imprimir la prioridad del nodo
        //cout << "Nodo con prioridad: " << arb->prioridad << endl;

        // Imprimir los procesos de la lista asociada al nodo
        cout << "Procesos en la lista:" << endl;
        //arb->listaProc.mostrar(); // Acceso directo al miembro listaProc

        // Recorrer subárbol derecho
        verInOrden(arb->hd);
    }
}
*/
void AVL::insertar(Proceso proc) {
    if (!raiz) {
        Lista listaNueva;
        raiz = new NodoAVL(listaNueva, nullptr, nullptr, proc.getPrioridad());
        raiz->listaProcesos.insertarFinal(proc);
        return;
    }

    // Llamar a la sobrecarga recursiva comenzando desde la raíz
    insertar(proc, raiz);
}
 

void AVL::insertar(Proceso proc, NodoAVL *nodo){
    if (proc.getPrioridad() == nodo->prioridad){
        nodo->listaProcesos.insertarFinal(proc);
    } else if (proc.getPrioridad() < nodo->prioridad) {
        if (!nodo->hi) {
            Lista listaNueva;
            nodo->hi = new NodoAVL(listaNueva, nullptr, nullptr, proc.getPrioridad());
        }
        insertar(proc, nodo->hi);
    } else {
        if (!nodo->hd) {
            Lista listaNueva;
            nodo->hd = new NodoAVL(listaNueva, nullptr, nullptr, proc.getPrioridad());
        }
        insertar(proc, nodo->hd);
    }
}
        /*Lista listaNueva;
        nodo = new NodoAVL(listaNueva, NULL, NULL, proc.getPrioridad());
        cout << "Nodo creado con prioridad: " << proc.getPrioridad() << endl;
        nodo->listaProcesos.insertarFinal(proc);
        cout << "Proceso insertado en la lista del nodo con prioridad: " << proc.getPrioridad() << endl;
        return;
    }

    if (proc.getPrioridad() == nodo->prioridad) {
        nodo->listaProcesos.insertarFinal(proc);
        cout << "Proceso insertado en la lista del nodo con prioridad: " << proc.getPrioridad() << endl;
    } else if (proc.getPrioridad() < nodo->prioridad) {
        // Recorrer hacia la izquierda si la prioridad del proceso es menor
        insertar(proc, nodo->hi);
    } else {
        // Recorrer hacia la derecha si la prioridad del proceso es mayor
        insertar(proc, nodo->hd);
    }
}*/

NodoAVL* AVL::get_raiz(){
    return raiz;
}

void AVL::buscar(int prioridad) {
    buscar(prioridad, raiz);
}

void AVL::buscar (int prioridad, NodoAVL *nodo){
    if (nodo == nullptr) {
        cout << "El árbol está vacío o el nodo proporcionado es nulo" << endl;
        return;
    }
    else if (nodo->prioridad == prioridad) {
        cout << "Nodo con prioridad " << prioridad << " encontrado" << endl;
        cout << "Procesos en la lista:" << endl;
        nodo->listaProcesos.mostrar();
    } else if (nodo->prioridad < prioridad) {
        buscar(prioridad, nodo->hd);
    } else {
        buscar(prioridad, nodo->hi);
    }
}

void AVL::mostrarNiveles() {
    mostrarNiveles(raiz);
}


void AVL::mostrarNiveles(NodoAVL *nodo) {
    if (nodo != nullptr && !nodo->listaProcesos.esVacia()) {
        mostrarNiveles(nodo->hi);
        mostrarNiveles(nodo->hd);
        cout << "Prioridad: " << nodo->prioridad << endl;
    }
}

void AVL::mostrarNivelesMayorMenor(){
    mostrarNivelesMayorMenor(raiz);
}

void AVL::mostrarNivelesMayorMenor(NodoAVL* nodo) {
    if (nodo == nullptr) {
        cout << "El arbol esta vacio o el nodo proporcionado es nulo" << endl;
        return;
    }
    else {
        mostrarNivelesMayorMenor(nodo->hd);
        mostrarNivelesMayorMenor(nodo->hi);
        cout << "Prioridad: " << nodo->prioridad << endl;
    }
}

//float AVL::tiempoPromedioProcesos(int prioridad){
 //   tiempoPromedioProcesos(prioridad, raiz);
//}

/*
float AVL::tiempoPromedioProcesos(int prioridad, NodoAVL *nodo){
    if (nodo == nullptr) {
        cout << "El árbol está vacío o el nodo proporcionado es nulo" << endl;
        return 0;
    } 
    if (nodo->prioridad == prioridad){
        float tiempoTotal = 0;
        float cantidadProcesos = nodo->listaProcesos.longitud();
        if (cantidadProcesos == 0) {
            return 0;
        }
        for (int i = 0; i < cantidadProcesos; ++i) {
            Proceso p = nodo->listaProcesos.coger(i);
            tiempoTotal += p.get_tiempo_ejecucion(); // O cambiar a get_tiempo_ejecucion si es correcto
        }
    return tiempoTotal / cantidadProcesos;
    } else if (prioridad < nodo->prioridad) {
        return tiempoPromedioProcesos(prioridad, nodo->hi);
    } else {
        return tiempoPromedioProcesos(prioridad, nodo->hd);
    }
}
*/