#include <iostream>
#include "Proceso.h"
#include "Planificador.h"

using namespace std;




int main() {
    Planificador planificador;
    int opcion;
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
        cout << "8. Ejecutar todos los procesos\n";
        cout << "9. Salir\n";
        cout << "Introduce tu opcion: ";
        cin >> opcion;


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
            case 8:
                planificador.ejecutarTodosLosProcesos();
                break;
            case 9:
                planificador.borrarProcesos();
                cout << "Saliendo..." << std::endl;
                break;
            default:
                cout << "Opcion invalida, por favor intenta de nuevo." << endl;
        }
    } while (opcion != 9);

    return 0;
}
