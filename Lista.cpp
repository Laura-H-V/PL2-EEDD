#include "Lista.h"

Lista::Lista() : cabeza(nullptr), cola(nullptr) {}

Lista::~Lista() {
    while (!esVacia()) {
        pNodoLista temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
    cola = nullptr;
}

// inserta izquierda
void Lista::insertarInicio(Proceso v) {
    pNodoLista nuevo = new NodoLista(v, cabeza, nullptr);
    if (esVacia()) {
        cabeza = cola = nuevo;
    } else {
        cabeza->anterior = nuevo;
        cabeza = nuevo;
    }
}

// Inserta derecha
void Lista::insertarFinal(Proceso v) {
    pNodoLista nuevo = new NodoLista(v, nullptr, cola);
    if (esVacia()) {
        cabeza = cola = nuevo;
    } else {
        cola->siguiente = nuevo;
        cola = nuevo;
    }
}

// Método insertarEnPosicion
void Lista::insertarEnPosicion(Proceso v, int pos) {
    if (pos <= 0) {
        insertarInicio(v);
    } else if (pos >= longitud()) {
        insertarFinal(v);
    } else {
        pNodoLista actual = cabeza;
        for (int i = 0; i < pos - 1 && actual->siguiente != nullptr; i++) {
            actual = actual->siguiente;
        }
        pNodoLista nuevo = new NodoLista(v, actual->siguiente, actual);
        actual->siguiente->anterior = nuevo;
        actual->siguiente = nuevo;
    }
}

// Método eliminar
void Lista::eliminar(Proceso v) {
    if (esVacia()) return;

    pNodoLista actual = cabeza;
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

// Método buscar
Proceso* Lista::buscar(int id) {
    pNodoLista actual = cabeza;
    while (actual != nullptr) {
        if (actual->valor.getPID() == id) {  // Compara por PID
            return &actual->valor;  // Devuelve un puntero al proceso encontrado
        }
        actual = actual->siguiente;
    }
    return nullptr;  // Si no se encuentra, devuelve nullptr
}

// Método mostrar
void Lista::mostrar() {
    pNodoLista actual = cabeza;
    while (actual != nullptr) {
        std::cout << "Proceso PID: " << actual->valor.getPID() << std::endl;
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}

// Método longitud
int Lista::longitud() {
    int contador = 0;
    pNodoLista actual = cabeza;
    while (actual != nullptr) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

// Método inicio
Proceso Lista::inicio() {
    if (!esVacia() && cabeza != nullptr) {
        Proceso proceso = cabeza->valor;  // Devuelve el proceso en la cabeza
        return proceso;
    }
    return Proceso();  // Retorna un proceso vacío si la lista está vacía
}

// Método fin
Proceso Lista::fin() {
    if (!esVacia() && cola != nullptr) {
        Proceso proceso = cola->valor;  // Devuelve el proceso en la cola
        return proceso;
    }
    return Proceso();  // Retorna un proceso vacío si la lista está vacía
}


pNodoLista Lista::obtenerCabeza() const {
    return cabeza;
}