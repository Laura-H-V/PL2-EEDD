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
        cout<< "8. Añadir un proceso directamente al ABBProcesos\n";
        //cout << "8. Ejecutar todos los procesos\n";
        cout<< "9. Mostrar los datos almacenados en el ABBProcesos, ordenados por prioridad.\n";
        cout<< "10. Añadir un proceso directamente al ABBProcesos\n";
        cout<< "11. Mostrar todos los niveles de prioridad que han tenido al menos un proceso ejecutado, en orden numérico\n";
        cout<< "12.Calcular y mostrar el nivel de prioridad con el mayor número de procesos y el de menor número  \n";
        cout<< "13. Calcular y mostrar el tiempo promedio de ejecución de los procesos con una prioridad específica \n";
        cout<< "14. Calcular y mostrar el tiempo promedio de ejecución de los procesos en cada nivel de prioridad, recorriendo el árbol en preorden  \n";
        cout << "15. Salir\n";
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
            //case 8:
            //    planificador.ejecutarTodosLosProcesos();
            //    break;
            case 8:
                int pid, ppid, tiempoInicio, tiempoVida, prioridad;

                // Leer los datos del proceso desde el teclado
                std::cout << "Introduzca el PID del proceso: ";
                std::cin >> pid;

                std::cout << "Introduzca el PPID del proceso: ";
                std::cin >> ppid;

                std::cout << "Introduzca el tiempo de inicio del proceso: ";
                std::cin >> tiempoInicio;

                std::cout << "Introduzca el tiempo de vida del proceso: ";
                std::cin >> tiempoVida;

                std::cout << "Introduzca la prioridad del proceso: ";
                std::cin >> prioridad;
                
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                break;
            case 14:
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
