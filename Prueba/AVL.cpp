#include "AVL.h"
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

float AVL::tiempoPromedioEjecucion(int prioridad) {
    return tiempoPromedioEjecucion(prioridad, raiz);
}

float AVL::tiempoPromedioEjecucion(int prioridad, NodoAVL *nodo) {
    if (nodo == nullptr) {
        cout << "El árbol está vacío o el nodo proporcionado es nulo" << endl;
        return 0;
    }

    // Si el nodo actual tiene la prioridad que buscamos
    if (nodo->prioridad == prioridad) {
        float tiempoTotal = 0;
        int cantidadProcesos = nodo->listaProcesos.longitud();  // Obtiene la longitud de la lista de procesos
        if (cantidadProcesos == 0) {
            return 0;  // Si no hay procesos, retorna 0
        }

        // Recorre los nodos de la lista de procesos y acumula los tiempos de ejecución (tiempoVida)
        pNodoLista actual = nodo->listaProcesos.obtenerCabeza();  // Obtener la cabeza de la lista
        while (actual != nullptr) {
            Proceso p = actual->obtenerValor();  // Obtiene el proceso del nodo actual
            tiempoTotal += p.getTiempoVida();  // Suma el tiempo de vida (tiempo de ejecución)
            actual = actual->obtenerSiguiente();  // Avanza al siguiente nodo
        }

        // Devuelve el tiempo promedio de ejecución
        return tiempoTotal / cantidadProcesos;
    } 
    // Si la prioridad es menor que la del nodo actual, busca en el subárbol izquierdo
    else if (prioridad < nodo->prioridad) {
        return tiempoPromedioEjecucion(prioridad, nodo->hi);
    } 
    // Si la prioridad es mayor, busca en el subárbol derecho
    else {
        return tiempoPromedioEjecucion(prioridad, nodo->hd);
    }
}

float AVL::tiempoPromedioTotal() {
    return tiempoPromedioTotal(raiz);
}


float AVL::tiempoPromedioTotal(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return 0;  // Si el árbol está vacío, retornar 0
    }

    float tiempoTotal = sumarTiempos(nodo);
    int cantidadProcesos = contarProcesos(nodo);

    // Retornar el tiempo promedio total
    if (cantidadProcesos > 0) {
        return tiempoTotal / cantidadProcesos;
    }
    return 0;  // Si no hay procesos, retornar 0
}

float AVL::sumarTiempos(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return 0;
    }

    float tiempoTotal = 0;

    // Recorrer los nodos del árbol en orden (inorden)
    // Primero, recorrer el subárbol izquierdo
    tiempoTotal += sumarTiempos(nodo->hi);

    // Ahora procesar el nodo actual
    pNodoLista actual = nodo->listaProcesos.obtenerCabeza();
    while (actual != nullptr) {
        Proceso p = actual->obtenerValor();
        tiempoTotal += p.getTiempoVida();  // Sumar el tiempo de vida del proceso
        actual = actual->obtenerSiguiente();
    }

    // Finalmente, recorrer el subárbol derecho
    tiempoTotal += sumarTiempos(nodo->hd);

    return tiempoTotal;
}

int AVL::contarProcesos(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return 0;
    }

    int cantidad = nodo->listaProcesos.longitud();  // Obtener la longitud de la lista de procesos en el nodo
    return cantidad + contarProcesos(nodo->hi) + contarProcesos(nodo->hd);  // Sumar procesos de subárbol izquierdo y derecho
}