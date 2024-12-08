#include "AVL2.h"
#include <algorithm>

AVL::AVL(){ // Crea un árbol vacío
//constructor
    raiz = NULL;
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
void AVL::verInOrden(){
    if (raiz == nullptr) {
        cout << "El árbol está vacío" << endl;
    } else {
        verInOrden(raiz);
    }
}

//ver en orden dependiendo del nodo
void AVL::verInOrden(NodoAVL *arb){  
    if(arb){   //Recorre y muestra el árbol de forma recursiva llamando la hijo izquierdo, luego el nodo (raíz) y luego el hijo derecho
        verInOrden(arb->hi);
        cout << "Nodo con prioridad: " << arb->prioridad << endl;
        cout << "Procesos en la lista:" << endl;
        arb->listaProcesos.mostrar(); 
        verInOrden(arb->hd);
    }
}

void AVL::insertar(Proceso proc){
    if (raiz == nullptr) {
        // Si el árbol está vacío, inicializa la raíz
        Lista listaNueva;
        raiz = new NodoAVL(listaNueva, nullptr, nullptr, proc.getPrioridad());
        cout << "Nodo raíz creado con prioridad: " << proc.getPrioridad() << endl;
        raiz->listaProcesos.insertarFinal(proc);
    } else {
        // Si no está vacío, llama al método recursivo
        insertar(proc, raiz);
    }
}   

void AVL::insertar(Proceso proc, NodoAVL *nodo){
    if (proc.getPrioridad() == nodo->prioridad) {
        nodo->listaProcesos.insertarFinal(proc);
        cout << "Proceso insertado en la lista del nodo con prioridad: " << proc.getPrioridad() << endl;
    } else if (proc.getPrioridad() < nodo->prioridad) {
        if (nodo->hi == nullptr) {
            Lista listaNueva;
            nodo->hi = new NodoAVL(listaNueva, nullptr, nullptr, proc.getPrioridad());
            cout << "Nodo izquierdo creado con prioridad: " << proc.getPrioridad() << endl;
            nodo->hi->listaProcesos.insertarFinal(proc);
        } else {
            insertar(proc, nodo->hi);
        }
    } else {
        if (nodo->hd == nullptr) {
            Lista listaNueva;
            nodo->hd = new NodoAVL(listaNueva, nullptr, nullptr, proc.getPrioridad());
            cout << "Nodo derecho creado con prioridad: " << proc.getPrioridad() << endl;
            nodo->hd->listaProcesos.insertarFinal(proc);
        } else {
            insertar(proc, nodo->hd);
        }
    }
}

NodoAVL* AVL::getRaiz(){
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

//Al igual que mistrar de mayor a menor pero invirtiendo el orden del vector 
void AVL::mostrarNiveles(NodoAVL *nodo) {
    if (nodo == nullptr) {
        cout << "El árbol está vacío" << endl;
        return;
    }

    // Crear un vector para almacenar los nodos
    std::vector<NodoAVL*> nodos;

    // Llenar el vector con todos los nodos del árbol
    llenarVector(nodo, nodos);

    // Ordenar el vector en orden ascendente de prioridad (de menor a mayor)
    std::sort(nodos.begin(), nodos.end(), [](NodoAVL* a, NodoAVL* b) {
        return a->prioridad < b->prioridad; // Orden ascendente
    });

    // Mostrar los nodos en orden ascendente (menor a mayor)
    for (NodoAVL* nodo : nodos) {
        cout << "Prioridad: " << nodo->prioridad << endl;
    }
}

void AVL::mostrarNivelesMayorMenor(){
    mostrarNivelesMayorMenor(raiz);
}

void AVL::mostrarNivelesMayorMenor(NodoAVL* nodo) {
    if (nodo == nullptr) {
        cout << "El arbol esta vacio" << endl;
        return;
    }

    // Crear un vector para almacenar los nodos
    std::vector<NodoAVL*> nodos;

    // Llenar el vector con todos los nodos del árbol
    llenarVector(nodo, nodos);

    // Ordenar el vector en orden descendente de prioridad
    std::sort(nodos.begin(), nodos.end(), [](NodoAVL* a, NodoAVL* b) {
        return a->prioridad > b->prioridad; // Orden descendente
    });

    // Mostrar los nodos en orden descendente
    for (NodoAVL* nodo : nodos) {
        cout << "Prioridad: " << nodo->prioridad << endl;
    }
}


void AVL::llenarVector(NodoAVL* nodo, std::vector<NodoAVL*>& nodos) {
    if (nodo == nullptr) {
        return;
    }
    else{
        // Recorremos primero el subárbol izquierdo
        llenarVector(nodo->hi, nodos);

        // Agregamos el nodo actual al vector
        nodos.push_back(nodo);

        // Recorremos el subárbol derecho
        llenarVector(nodo->hd, nodos);
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