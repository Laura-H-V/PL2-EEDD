#include <iostream>
#include "Proceso.h"
#include "Planificador.h"

using namespace std;




int main() {
    AVL arbol;
    Planificador planificador;
    int opcion;
    int prioridad;
    do {
        cout << "\nMenu:\n";
        cout << "1. crear pila de procesos\n";
        cout << "2. Mostrar procesos en la pila\n";
        cout << "3. Borrar pila de procesos\n";
        cout << "4. Simular tiempo\n";
        cout << "5. Mostrar los datos en la lista de nucelos\n"; 
        //(id del núcleo, proceso que esta siendo ejecutado, tiempo restante de ejecución, 
        //procesos que están a la espera de ser ejecutados)
        cout << "6. Consultar que nucleo tiene menos procesos y cuál es el más ocupado\n";
        cout << "7. Numero de nucleos de atencion operativos\n";
        cout<< "8. Añadir un proceso directamente al ABBProcesos\n";
        //cout << "8. Ejecutar todos los procesos\n";
        cout<< "9. Mostrar los datos almacenados en el ABBProcesos\n";
        cout<< "10. Mostrar los procesos con la prioridad dada\n";
        cout<< "11. Mostrar todos los niveles de prioridad que han tenido al menos un proceso ejecutado, en orden numérico\n";
        cout<< "12.Calcular y mostrar el nivel de prioridad con el mayor número de procesos y el de menor número  \n";
        cout<< "13. Calcular y mostrar el tiempo promedio de ejecución de los procesos con una prioridad específica \n";
        cout<< "14. Calcular y mostrar el tiempo promedio de ejecución de los procesos en cada nivel de prioridad, recorriendo el árbol en preorden  \n";
        cout << "15. Salir\n";
        cout << "Introduce tu opcion: ";
        cin >> opcion;
        cin >> prioridad;

    switch (opcion) {
        
            case 1:
                planificador.crearPilaProcesos();
                break;
            case 2:
                planificador.mostrarProcesos();
                break;
            case 3:
                planificador.borrarProcesos();
                break;
            case 4:
                int minutos;
                cout << "Ingrese el número de minutos: ";
                cin >> minutos;
                planificador.simularTiempo(minutos);
                break;
            case 5:
                planificador.mostrarLista();
                break;
            case 6: {
                planificador.nucleoMenosOcupado();
                planificador.nucleoMasOcupado();
                break;
            }
            case 7:
                planificador.numeroNucleos();
                break;
            //case 8:
            //    planificador.ejecutarTodosLosProcesos();
            //    break;
            case 8:
                planificador.meterProcesosEnABB();
                break;
            case 9:
                planificador.mostrarABB();
                break;
            case 10:
                int prioridad;
                cout << "Introduce la prioridad a buscar: ";
                cin >> prioridad;
                planificador.buscarProcesos(prioridad);
                break;
            case 11:
                planificador.mostrarNivelesconProcesosEjecutados();
                break;
            case 12:
                arbol.calcularMayorMenorProcesos();
                break;
            case 13:
                int prioridad;
                cout << "Ingrese la prioridad: ";
                cin >> prioridad;
                arbol.tiempoPromedioEjecucion(prioridad);
                break;
            case 14:
                arbol.calcularYMostrarTiempoPromedioPreorden();
                break;
            case 15:
                planificador.borrarProcesos();
                cout << "Saliendo..." << std::endl;
                break;
            default:
                cout << "Opcion invalida, por favor intenta de nuevo." << endl;
        }
    } while (opcion != 15);

    return 0;
}
