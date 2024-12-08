#include "AVL.h"
#include <algorithm>
#include "ListaProcesos.h"
#include "NodoAvl.h"

AVL::AVL(){ // Crea un árbol vacío
//constructor
    ListaProcesos listaVacia;
    raiz = new NodoAVL(listaVacia, nullptr, nullptr, 0); // Prioridad = 0 para P0
}

AVL::AVL(NodoAVL *r){
    raiz = r; // La raiz es el primer nodo que se pasa como parámetro
}

AVL::AVL(ListaProcesos listaProcesos, NodoAVL *hIz, NodoAVL *hDer, int prioridad){  //constructor que crea árbolBin con dato y dos subárboles
    raiz = new NodoAVL(listaProcesos, hIz, hDer, prioridad); //llamamos al constructor del Nodo y raiz es un puntero al Nodo creado
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


void AVL::insertar(Proceso proc) {
    if (!raiz) {
        ListaProcesos listaNueva;
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
            ListaProcesos listaNueva;
            nodo->hi = new NodoAVL(listaNueva, nullptr, nullptr, proc.getPrioridad());
        }
        insertar(proc, nodo->hi);
    } else {
        if (!nodo->hd) {
            ListaProcesos listaNueva;
            nodo->hd = new NodoAVL(listaNueva, nullptr, nullptr, proc.getPrioridad());
        }
        insertar(proc, nodo->hd);
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

        // Recorrer la lista de procesos en este nodo y mostrar el PID y el tiempo de vida
        pNodoListaProcesos actual = nodo->listaProcesos.obtenerCabeza();
        while (actual != nullptr) {
            Proceso p = actual->obtenerValor();
            cout << "  PID: " << p.getPID() << ", Tiempo en sistema: " << p.getTiempoSistema() << " minutos" << endl;
            actual = actual->obtenerSiguiente();
        }

        cout << "--------------------------------------------" << endl;
    }
}


void AVL::mostrarNivelesMayorMenor(){
    mostrarNivelesMayorMenor(raiz);
}

void AVL::mostrarNivelesMayorMenor(NodoAVL* nodo) {
    if (nodo == nullptr) {
        cout << "El árbol está vacío." << endl;
        return;
    }

    // Crear un vector para almacenar los nodos
    std::vector<NodoAVL*> nodos;

    // Llenar el vector con todos los nodos del árbol
    llenarVector(nodo, nodos);

    // Ordenar el vector en orden descendente de prioridad (mayor a menor)
    std::sort(nodos.begin(), nodos.end(), [](NodoAVL* a, NodoAVL* b) {
        return a->prioridad > b->prioridad;  // Orden descendente
    });

    // Mostrar los nodos en orden descendente de prioridad
    for (NodoAVL* nodo : nodos) {
        // Mostrar la prioridad del nodo
        cout << "Prioridad: " << nodo->prioridad << endl;

        // Recorrer la lista de procesos en este nodo y mostrar el PID y el tiempo de vida
        pNodoListaProcesos actual = nodo->listaProcesos.obtenerCabeza();
        while (actual != nullptr) {
            Proceso p = actual->obtenerValor();
            cout << "  PID: " << p.getPID()  << endl;
            actual = actual->obtenerSiguiente();
        }

        cout << "--------------------------------------------" << endl;
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
        pNodoListaProcesos actual = nodo->listaProcesos.obtenerCabeza();  // Obtener la cabeza de la lista
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
    pNodoListaProcesos actual = nodo->listaProcesos.obtenerCabeza();
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

void AVL::calcularMayorMenorProcesos() {
    if (!raiz || (!raiz->hi && !raiz->hd && raiz->listaProcesos.esVacia())) {
        cout << "El árbol no tiene datos relevantes (solo nodo P0 o está vacío)." << endl;
        return;
    }

    // Variables para almacenar resultados
    int prioridadMayor = -1, mayor = -1;
    int prioridadMenor = -1, menor = INT_MAX;

    // Recorrer el árbol y calcular
    calcularMayorMenorProcesos(raiz, prioridadMayor, mayor, prioridadMenor, menor);

    // Mostrar resultados
    cout << "Prioridad con el mayor número de procesos: " << prioridadMayor << " (Cantidad: " << mayor << ")" << endl;
    cout << "Prioridad con el menor número de procesos: " << prioridadMenor << " (Cantidad: " << menor << ")" << endl;
}

void AVL::calcularMayorMenorProcesos(NodoAVL *nodo, int &prioridadMayor, int &mayor, int &prioridadMenor, int &menor) {
    if (!nodo) return;

    // Ignorar nodo P0 si está presente
    if (nodo->prioridad != 0) {
        int cantidadProcesos = nodo->listaProcesos.longitud(); // Obtener la cantidad de procesos en este nodo

        // Actualizar la prioridad con más procesos
        if (cantidadProcesos > mayor) {
            mayor = cantidadProcesos;
            prioridadMayor = nodo->prioridad;
        }

        // Actualizar la prioridad con menos procesos
        if (cantidadProcesos < menor) {
            menor = cantidadProcesos;
            prioridadMenor = nodo->prioridad;
        }
    }

    // Recursión para hijos
    calcularMayorMenorProcesos(nodo->hi, prioridadMayor, mayor, prioridadMenor, menor);
    calcularMayorMenorProcesos(nodo->hd, prioridadMayor, mayor, prioridadMenor, menor);
}

void AVL::calcularYMostrarTiempoPromedioPreorden() {
    if (!raiz) {
        cout << "El árbol está vacío." << endl;
        return;
    }

    // Llamamos a la función recursiva preorden, que recorrerá el árbol en preorden
    preorden(raiz);
}

// Función recursiva que recorre el árbol en preorden
void AVL::preorden(NodoAVL *nodo) {
    if (nodo == nullptr) return;  // Si el nodo es nulo, terminamos

    // En cada nodo, calculamos y mostramos el tiempo promedio de ejecución
    float promedio = tiempoPromedioEjecucion(nodo->prioridad, nodo);  // Usamos la función para calcular el tiempo promedio
    cout << "Prioridad: " << nodo->prioridad << " | Tiempo promedio de ejecución: " << promedio << " minutos." << endl;

    // Recorremos el subárbol izquierdo en preorden
    preorden(nodo->hi);

    // Recorremos el subárbol derecho en preorden
    preorden(nodo->hd);
}


