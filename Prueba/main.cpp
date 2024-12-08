#include "AVL.h"
#include "Proceso.h"
#include <iostream>
using namespace std;

int main() {
    // Crear una instancia del árbol AVL
    AVL arbol;

    // Crear algunos procesos con formato actualizado
    // Proceso(pid, ppid, tiempo_inicio, tiempo_ejecucion, prioridad, nucleo)
    Proceso p1(1, 0, 0, 10, 1, 0);  // Proceso 1, prioridad 1
    Proceso p2(2, 1, 1, 10, 3, 0); // Proceso 2, prioridad 3
    Proceso p3(3, 1, 2, 7, 1, 0);  // Proceso 3, prioridad 1
    Proceso p4(4, 2, 3, 8, 5, 0);  // Proceso 4, prioridad 5
    Proceso p5(5, 3, 5, 6, 3, 0);  // Proceso 5, prioridad 3

    // Insertar los procesos en el árbol
    arbol.insertar(p1);
    arbol.insertar(p2);
    arbol.insertar(p3);
    arbol.insertar(p4);
    arbol.insertar(p5);

    // Mostrar el árbol en orden
    cout << "\nArbol en in-orden:" << endl;
    arbol.verInOrden();

    // Buscar procesos con una prioridad específica
    int prioridadABuscar = 3;
    cout << "\nBuscando procesos con prioridad " << prioridadABuscar << ":" << endl;
    arbol.buscar(prioridadABuscar);

    // Mostrar el árbol por niveles (de menor a mayor)
    cout << "\nMostrando el árbol por niveles (menor a mayor):" << endl;
    arbol.mostrarNiveles();

    // Mostrar el árbol por niveles (de mayor a menor)
    cout << "\nMostrando el árbol por niveles (mayor a menor):" << endl;
    arbol.mostrarNivelesMayorMenor();

    // Comprobar la función tiempoPromedioEjecucion
    int prioridadParaPromedio = 3;  // Puedes cambiar la prioridad para probar con otras prioridades
    cout << "\nCalculando el tiempo promedio de ejecución para los procesos con prioridad " 
         << prioridadParaPromedio << ":" << endl;
    float tiempoPromedio = arbol.tiempoPromedioEjecucion(prioridadParaPromedio);
    cout << "Tiempo promedio de ejecución para los procesos con prioridad " 
         << prioridadParaPromedio << " es: " << tiempoPromedio << endl;

    // Comprobar la función tiempoPromedioTotal
    cout << "\nCalculando el tiempo promedio de ejecución de todos los procesos en el sistema:" << endl;
    float tiempoPromedioTotal = arbol.tiempoPromedioTotal();
    cout << "Tiempo promedio total de ejecución para todos los procesos es: " 
         << tiempoPromedioTotal << endl;

    // Finalizar
    cout << "\nFin de la prueba del árbol AVL." << endl;
    return 0;
}
