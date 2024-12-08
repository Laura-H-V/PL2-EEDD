#include "Listaprocesos.h"

// Constructor
Listaprocesos::Listaprocesos() : cabeza(nullptr), cola(nullptr) {}

// Destructor
Listaprocesos::~Listaprocesos() {
    while (!esVacia()) {
        pNodoListaProcesos temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
    cola = nullptr;
}

// Verificar si la lista está vacía
bool Listaprocesos::esVacia() {
    return cabeza == nullptr;  // La lista está vacía si la cabeza es nullptr
}

// Insertar al inicio
void Listaprocesos::insertarInicio(Proceso v) {
    pNodoListaProcesos nuevo = new NodoListaProcesos(v, cabeza, nullptr);
    if (esVacia()) {
        cabeza = cola = nuevo;
    } else {
        cabeza->anterior = nuevo;
        cabeza = nuevo;
    }
}

// Insertar al final
void Listaprocesos::insertarFinal(Proceso v) {
    pNodoListaProcesos nuevo = new NodoListaProcesos(v, nullptr, cola);
    if (esVacia()) {
        cabeza = cola = nuevo;
    } else {
        cola->siguiente = nuevo;
        cola = nuevo;
    }
}

// Insertar en una posición específica
void Listaprocesos::insertarEnPosicion(Proceso v, int pos) {
    if (pos <= 0) {
        insertarInicio(v);
    } else if (pos >= longitud()) {
        insertarFinal(v);
    } else {
        pNodoListaProcesos actual = cabeza;
        for (int i = 0; i < pos - 1 && actual->siguiente != nullptr; i++) {
            actual = actual->siguiente;
        }
        pNodoListaProcesos nuevo = new NodoListaProcesos(v, actual->siguiente, actual);
        actual->siguiente->anterior = nuevo;
        actual->siguiente = nuevo;
    }
}

// Eliminar un proceso de la lista
void Listaprocesos::eliminar(Proceso v) {
    if (esVacia()) return;

    pNodoListaProcesos actual = cabeza;
    while (actual != nullptr && actual->valor.getPID() != v.getPID()) {  // Usar el PID del proceso para compararlos
        actual = actual->siguiente;
    }
    if (actual == nullptr) return;

    if (actual == cabeza) {
        cabeza = cabeza->siguiente;
        if (cabeza != nullptr) cabeza->anterior = nullptr;
    } else if (actual == cola) {
        cola = cola->anterior;
        if (cola != nullptr) cola->siguiente = nullptr;
    } else {
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
    }
    delete actual;
}

// Buscar un proceso por PID
Proceso* Listaprocesos::buscar(int pid) {
    pNodoListaProcesos actual = cabeza;
    while (actual != nullptr) {
        if (actual->valor.getPID() == pid) {  // Compara por PID
            return &actual->valor;  // Devuelve un puntero al proceso encontrado
        }
        actual = actual->siguiente;
    }
    return nullptr;  // Si no se encuentra, devuelve nullptr
}

// Mostrar los procesos de la lista
void Listaprocesos::mostrar() {
    pNodoListaProcesos actual = cabeza;
    while (actual != nullptr) {
        std::cout << "Proceso PID: " << actual->valor.getPID() << std::endl;
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}

// Obtener la longitud de la lista
int Listaprocesos::longitud() {
    int contador = 0;
    pNodoListaProcesos actual = cabeza;
    while (actual != nullptr) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

// Obtener el primer proceso (inicio)
Proceso Listaprocesos::inicio() {
    if (!esVacia() && cabeza != nullptr) {
        Proceso proceso = cabeza->valor;  // Devuelve el proceso en la cabeza
        return proceso;
    }
    return Proceso();  // Retorna un proceso vacío si la lista está vacía
}

// Obtener el último proceso (fin)
Proceso Listaprocesos::fin() {
    if (!esVacia() && cola != nullptr) {
        Proceso proceso = cola->valor;  // Devuelve el proceso en la cola
        return proceso;
    }
    return Proceso();  // Retorna un proceso vacío si la lista está vacía
}

// Obte
