#include "Planificador.h"
#include "AVL.h"


Planificador::Planificador() {
    // Crear tres núcleos iniciales
    for (int i = 0; i < 3; i++) {
        Cola colaNucleo;                     // Cola vacía para el núcleo
        Nucleo nucleo(i + 1, colaNucleo);   // Crear un núcleo con ID único
        listaNucleos.insertarFinal(nucleo);           // Agregar el núcleo a la lista de núcleos
    }
    tiempoInicio = 0;
}

void Planificador::setTiempoInicio(int tTotal) {
    tiempoInicio = tTotal;
}


void Planificador::asignarProcesoANucleo(Proceso* proceso) {
    pNodoLista actual = listaNucleos.obtenerCabeza(); // Comenzar desde el primer núcleo

    // Buscar un núcleo libre para asignar el proceso
    while (actual != nullptr) {
        Nucleo& nucleo = actual->obtenerValor();

        if (nucleo.estaLibre()) { // Verificar si el núcleo está libre
            nucleo.asignarProceso(proceso); // Asignar el proceso al núcleo
            proceso->setNucleoAsignado(nucleo.getId()); // Registrar el núcleo en el proceso
            std::cout << "Proceso PID " << proceso->getPID()
                      << " asignado al núcleo " << nucleo.getId() << std::endl;

            return; // Terminar la asignación
        }

        actual = actual->obtenerSiguiente();
    }

    // Si no hay núcleos libres, buscar el núcleo con la cola más corta para encolar el proceso
    actual = listaNucleos.obtenerCabeza();
    Nucleo* nucleoConMenorCola = nullptr;
    int menorTamanioCola = INT_MAX;

    while (actual != nullptr) {
        Nucleo& nucleo = actual->obtenerValor();
        int longitudCola = nucleo.longitudColaEsperaNucleo();

        if (longitudCola < menorTamanioCola) {
            menorTamanioCola = longitudCola;
            nucleoConMenorCola = &nucleo;
        }

        actual = actual->obtenerSiguiente();
    }

    if (nucleoConMenorCola != nullptr) {
        nucleoConMenorCola->colaEsperaNucleo.encolar(*proceso, proceso->getPrioridad()); 
        std::cout << "Proceso PID " << proceso->getPID()
                  << " añadido a la cola de espera del núcleo " << nucleoConMenorCola->getId() << std::endl;

        // Verificar si se necesita agregar un nuevo núcleo
        agregarNucleo();
    } else {
        std::cerr << "Error: No se encontró un núcleo adecuado para el proceso PID "
                  << proceso->getPID() << std::endl;
    }
}

void Planificador::liberarNucleo(int idNucleo) {
    pNodoLista actual = listaNucleos.obtenerCabeza(); // Comenzar desde el inicio de la lista

    while (actual != nullptr) {
        Nucleo& nucleo = actual->obtenerValor(); // Obtener referencia al núcleo actual

        if (nucleo.getId() == idNucleo) { // Buscar el núcleo por su ID
            // Liberar el proceso actual del núcleo
            nucleo.liberarProceso();

            std::cout << "Núcleo " << idNucleo << " liberado." << std::endl;

            // Si la cola de espera del núcleo no está vacía
            if (nucleo.longitudColaEsperaNucleo() > 0) {
                Proceso* siguienteProceso = nucleo.getProceso(); // Obtener el siguiente proceso de la cola
                nucleo.asignarProceso(siguienteProceso); // Asignar el proceso al núcleo
                siguienteProceso->setNucleoAsignado(nucleo.getId());

                std::cout << "Proceso PID " << siguienteProceso->getPID()
                          << " asignado al núcleo " << nucleo.getId()
                          << " desde la cola de espera." << std::endl;
            }
            return; // Salir después de procesar el núcleo
        }

        actual = actual->obtenerSiguiente(); // Avanzar al siguiente núcleo
    }

    // Si no se encuentra el núcleo con el ID especificado
    std::cerr << "Error: Núcleo con ID " << idNucleo << " no encontrado." << std::endl;
}


//Funcion 1, crear pila de procesos
void Planificador::crearPilaProcesos() {
    //Proceso(int pid, int ppid, int ini, int tiempo, int pri, int nucleo = -1);
    //Proceso(int pid, int ppid, int ini, int tiempo, int pri, int nucleo = -1);
    Proceso p1=Proceso(1,1, 0, 4, 0);
    Proceso p2=Proceso(2,1, 0, 5, 1);
    Proceso p3=Proceso(3,1, 1, 4, 3);
    Proceso p4=Proceso(4,2, 4, 3, 7);
    Proceso p5=Proceso(5,2, 6, 2, 2);
    Proceso p6=Proceso(6,3, 9, 5, 1);
    Proceso p7=Proceso(7,3, 10, 3, 4);
    Proceso p8=Proceso(8,4, 12, 2, 6);
    Proceso p9=Proceso(9,7, 13, 1, 8);
    Proceso p10=Proceso(10,5, 15, 4, 2);
    Proceso p11=Proceso(11,4, 16, 3, 3);
    Proceso p12=Proceso(12,5, 18, 2, 5);
    Proceso p13=Proceso(13,6, 18, 1, 1);
    Proceso p14=Proceso(14,6, 18, 2, 4);
    Proceso p15=Proceso(15,7, 19, 5, 0);
    Proceso p16=Proceso(16,8, 19, 3, 6);
    Proceso p17=Proceso(17,10, 20, 2, 7);
    Proceso p18=Proceso(18,8, 21, 1, 8);
    Proceso p19=Proceso(19,9, 21, 2, 2);
    Proceso p20=Proceso(20,0, 0, 2, 1);
    Proceso p21=Proceso(21,1, 0, 2, 2);
    Proceso p22=Proceso(22,1, 0, 2, 9);
    Proceso p23=Proceso(23,1, 0, 2, 5);
    Proceso p24=Proceso(24,1, 0, 2, 1);
    Proceso p25=Proceso(25,1, 0, 2, 3);

    p1.setLlegada(0);
    p2.setLlegada(0);
    p3.setLlegada(1);
    p4.setLlegada(4);
    p5.setLlegada(6);
    p6.setLlegada(9);
    p7.setLlegada(10);
    p8.setLlegada(12);
    p9.setLlegada(13);
    p10.setLlegada(15);
    p11.setLlegada(16);
    p12.setLlegada(18);
    p13.setLlegada(18);
    p14.setLlegada(18);
    p15.setLlegada(19);
    p16.setLlegada(19);
    p17.setLlegada(20);
    p18.setLlegada(21);
    p19.setLlegada(21);
    p20.setLlegada(0);
    p21.setLlegada(0);
    p22.setLlegada(0);
    p23.setLlegada(0);
    p24.setLlegada(0);
    p25.setLlegada(0);
    


    pilaProcesos.apilar(p7);
    pilaProcesos.apilar(p11);
    pilaProcesos.apilar(p13);
    pilaProcesos.apilar(p9);
    pilaProcesos.apilar(p18);
    pilaProcesos.apilar(p15);
    pilaProcesos.apilar(p6);
    pilaProcesos.apilar(p17);
    pilaProcesos.apilar(p2);
    pilaProcesos.apilar(p1);
    pilaProcesos.apilar(p12);
    pilaProcesos.apilar(p10);
    pilaProcesos.apilar(p4);
    pilaProcesos.apilar(p8);
    pilaProcesos.apilar(p14);
    pilaProcesos.apilar(p5);
    pilaProcesos.apilar(p16);
    pilaProcesos.apilar(p3);
    pilaProcesos.apilar(p19);
    pilaProcesos.apilar(p20);
    pilaProcesos.apilar(p21);
    pilaProcesos.apilar(p22);
    pilaProcesos.apilar(p23);
    pilaProcesos.apilar(p24);
    pilaProcesos.apilar(p25);

    setNumeroProcesos(pilaProcesos.longitud());
}

//Funcion 2, mostrar procesos en la pila 
void Planificador::mostrarProcesos() {
    Pila pilaTemporal = pilaProcesos;

    if (!pilaTemporal.esVacia()) {
        int n = 0;
        while (!pilaTemporal.esVacia()) {
            Proceso* proceso = pilaTemporal.mostrar();
            if (proceso) {
                std::cout << "---------------------------------------------"  << std::endl;
                std::cout << "Proceso : " << n << std::endl;
                std::cout << "PID: " << proceso->getPID() << std::endl;
                std::cout << "RPID: " << proceso->getPPID() << std::endl;
                std::cout << "Prioridad: " << proceso->getPrioridad() << std::endl;
                std::cout << "Tiempo de vida: " << proceso->getTiempoVida() << std::endl;
                std::cout << "Tiempo de inicio: " << proceso->getInicio() << std::endl;
                std::cout << "---------------------------------------------"  << std::endl;
            }
            pilaTemporal.desapilar();
            n++;
        }
    } else {
        std::cout << "No hay procesos." << std::endl;
    }
}

//Funcion 3, borrar procesos de la pila
void Planificador::borrarProcesos() {
    std::cout << "Borrando pila de procesos..." << std::endl;
    while (!pilaProcesos.esVacia()) {
        pilaProcesos.desapilar();
        std::cout << "Proceso desapilado." << std::endl;
    }
    std::cout << "Pila de procesos borrada." << std::endl;
}

//Funcion 4, simular tiempo   
void Planificador::simularTiempo(int minutosSimular) {
    static int totalTiempoEnSistemaAcumulado = 0;
    static int procesosTerminadosAcumulados = 0;

    int minuto = tiempoInicio;
    int procesosTerminados = 0;

    int totalProcesos = pilaProcesos.longitud();
    numeroProcesos = 0;

    // Asignar los primeros tres procesos a los tres núcleos iniciales
    for (int i = 0; i < 3 && !pilaProcesos.esVacia(); ++i) {
        Proceso* proceso = pilaProcesos.mostrar();
        if (proceso) {
            asignarProcesoANucleo(proceso);
            proceso->setInicio(minuto);
            proceso->setLlegada(minuto);
            pilaProcesos.desapilar();
        }
    }

    // Simular el paso del tiempo minuto a minuto
    for (int i = 0; i < minutosSimular; ++i) {
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "Simulando minuto " << minuto << std::endl;

        bool hayProcesosActivos = false;

        // Procesar eventos en cada núcleo
        pNodoLista actual = listaNucleos.obtenerCabeza();
        while (actual != nullptr) {
            Nucleo& nucleo = actual->obtenerValor();
            Proceso* procesoEnNucleo = nucleo.getProceso();

            if (procesoEnNucleo != nullptr) {
                hayProcesosActivos = true; // Hay al menos un proceso activo

                if (minuto - procesoEnNucleo->getInicio() >= procesoEnNucleo->getTiempoVida()) {
                    int tiempoEnSistema = minuto - procesoEnNucleo->getInicio();
                    int tiempoEnCola = procesoEnNucleo->getInicio();
                    int tiempoTotal = tiempoEnCola + procesoEnNucleo->getTiempoVida();

                    std::cout << "Fin del proceso PID " << procesoEnNucleo->getPID()
                              << " en núcleo " << nucleo.getId()
                              << " después de " << tiempoTotal << " minutos"
                              << "Tiempo en cola: " << tiempoEnCola << " minutos, "
                              << "Tiempo de vida: " << procesoEnNucleo->getTiempoVida() << " minutos, "
                              << "Tiempo total: " << tiempoTotal << " minutos" << std::endl;

                    totalTiempoEnSistemaAcumulado += tiempoTotal;
                    procesosTerminadosAcumulados++;

                    // **Inserción en el ABBProcesos**
                    AVL arbol;
                    arbol.insertar(*procesoEnNucleo); 

                    nucleo.liberarProceso();

                    if (!nucleo.colaEsperaNucleo.es_vacia()) {
                        Proceso nuevoProceso = nucleo.colaEsperaNucleo.desencolar();
                        nucleo.asignarProceso(new Proceso(nuevoProceso));
                        nuevoProceso.setNucleoAsignado(nucleo.getId()); // Asignar núcleo
                        nuevoProceso.setInicio(minuto); // Establecer el inicio del proceso
                        nuevoProceso.setLlegada(minuto); // Guardar el minuto de llegada cuando se asigna
                        std::cout << "Inicio del proceso PID " << nuevoProceso.getPID()
                                  << " en núcleo " << nucleo.getId() << std::endl;
                    }
                }
            }

            actual = actual->obtenerSiguiente();
        }

        // Asignar nuevos procesos a núcleos libres
        while (!pilaProcesos.esVacia()) {
            Proceso* proceso = pilaProcesos.mostrar();
            if (proceso && minuto >= proceso->getInicio()) {
                asignarProcesoANucleo(proceso);
                proceso->setInicio(minuto);
                proceso->setLlegada(minuto);
                pilaProcesos.desapilar();
            } else {
                break;
            }
        }

        // Verificar si se necesita agregar un nuevo núcleo
        agregarNucleo();

        // Imprimir cuando un proceso entra en la cola de espera de un núcleo
        actual = listaNucleos.obtenerCabeza();
        while (actual != nullptr) {
            Nucleo& nucleo = actual->obtenerValor();
            if (!nucleo.colaEsperaNucleo.es_vacia()) {
                Proceso procesoEnCola = nucleo.colaEsperaNucleo.inicio();
                std::cout << "El PID " << procesoEnCola.getPID()
                          << " ha entrado en la cola de espera del núcleo "
                          << nucleo.getId() << " en el minuto " << minuto << std::endl;
            }
            actual = actual->obtenerSiguiente();
        }

        minuto++;

        // Eliminar núcleos vacíos
        eliminarNucleosLibres();

        // Verificar si quedan procesos activos o en espera
        if (!hayProcesosActivos && pilaProcesos.esVacia()) {
            std::cout << "Todos los procesos han terminado." << std::endl;
            break; // Terminar la simulación si no quedan procesos
        }
    }

    tiempoInicio = minuto;

    // Verificar si todos los procesos han terminado
    if (listaNucleos.longitud() == 1) {
        std::cout << "Simulación terminada. Tiempo total: " << minuto << " minutos" << std::endl;
        double media = procesosTerminadosAcumulados > 0
                           ? static_cast<double>(totalTiempoEnSistemaAcumulado) / procesosTerminadosAcumulados
                           : 0;
        std::cout << "Media de tiempo en el sistema: " << media << " minutos" << std::endl;
    }
}



void Planificador::eliminarNucleosLibres() {
    int nucleosLibres = 0;
    pNodoLista actual = listaNucleos.obtenerCabeza();

    // Contar núcleos libres
    while (actual != nullptr) {
        Nucleo& nucleo = actual->obtenerValor();
        if (nucleo.estaLibre() && nucleo.longitudColaEsperaNucleo() == 0) {
            nucleosLibres++;
        }
        actual = actual->obtenerSiguiente();
    }

    // Verificar si hay al menos dos núcleos libres
    if (nucleosLibres < 2) {
        std::cout << "No hay suficientes núcleos libres para eliminar." << std::endl;
        return;
    }

    // Eliminar núcleos libres hasta que quede al menos uno
    actual = listaNucleos.obtenerCabeza();
    while (actual != nullptr && listaNucleos.longitud() > 1) {
        Nucleo& nucleo = actual->obtenerValor();
        if (nucleo.estaLibre() && nucleo.longitudColaEsperaNucleo() == 0) {
            std::cout << "Núcleo " << nucleo.getId() << " eliminado." << std::endl;
            listaNucleos.eliminar(nucleo); // Eliminar el núcleo de la lista
            nucleosLibres--;
            if (nucleosLibres < 2 && listaNucleos.longitud() > 1) {
                actual = listaNucleos.obtenerCabeza(); // Reiniciar la búsqueda desde el principio
            } else {
                break;
            }
        } else {
            actual = actual->obtenerSiguiente();
        }
    }
}

//Funcion 5, mostrar los datos en la lista de núcleos
//(id del núcleo, proceso que esta siendo ejecutado, tiempo restante de ejecución, 
//procesos que están a la espera de ser ejecutados)
void Planificador::mostrarLista() {
    std::cout << "Estado de los núcleos:" << std::endl;

    pNodoLista actual = listaNucleos.obtenerCabeza();  // Comenzar desde el primer nodo de la lista

    while (actual != nullptr) {
        Nucleo& nucleo = actual->obtenerValor();  // Obtener referencia al núcleo actual

        // Mostrar ID del núcleo
        std::cout << "Núcleo " << nucleo.getId() << ":" << std::endl;

        // Mostrar información del proceso actual
        if (nucleo.getProceso() != nullptr) {
            Proceso* procesoActual = nucleo.getProceso();
            std::cout << "  Proceso en ejecución: PID " << procesoActual->getPID()
                      << ", Tiempo vida: " << procesoActual->getTiempoVida() << " ms"
                      << std::endl;
        } else {
            std::cout << "  Proceso en ejecución: Libre" << std::endl;
        }

        // Mostrar información de la cola de espera
        int procesosEnEspera = nucleo.longitudColaEsperaNucleo();
        std::cout << "  Procesos en cola de espera: " << procesosEnEspera << std::endl;

        // Si hay procesos en espera, mostrar sus PIDs
        if (procesosEnEspera > 0) {
            std::cout << "  PIDs en cola: ";

            // Usar el método buscar() para acceder a la cola de espera
            Nucleo* nucleoEncontrado = listaNucleos.buscar(nucleo.getId()); // Buscar el núcleo por su ID

            if (nucleoEncontrado != nullptr) {
                // Copiar la cola de espera usando el constructor de copia de Cola
                Cola copiaCola = nucleoEncontrado->colaEsperaNucleo;  // Copiar la cola de espera del núcleo

                // Mientras la cola no esté vacía, procesamos cada proceso en ella
                while (!copiaCola.es_vacia()) {
                    Proceso proceso = copiaCola.inicio();  // Obtener el primer proceso de la cola
                    copiaCola.desencolar();  // Eliminar ese proceso de la cola

                    // Mostrar el PID del proceso
                    std::cout << proceso.getPID() << " ";
                }

                std::cout << std::endl;  // Nueva línea después de imprimir todos los PIDs

            } else {
                // Si el núcleo no fue encontrado, imprimimos un mensaje de error
                std::cout << "  No se encontró el núcleo en la lista." << std::endl;
        }

        }

        actual = actual->obtenerSiguiente();  // Avanzar al siguiente nodo
    }
}

// Función 6, Consultar que nucleo tiene menos procesos y cuál es el más ocupado
//Nucleo con más procesos en espera
Nucleo Planificador::nucleoMasOcupado() {
    pNodoLista actual = listaNucleos.obtenerCabeza();
    if (actual == nullptr) { // Validación si la lista está vacía
        std::cerr << "Error: Lista de núcleos vacía." << std::endl;
        throw std::runtime_error("Lista de núcleos vacía");
    }

    Nucleo* masOcupado = nullptr;
    int maxLongitud = -1; // Longitud máxima de cola encontrada

    // Primer recorrido: Encontrar la longitud máxima y un núcleo representativo
    while (actual != nullptr) {
        std::cout << "Revisando núcleo: " << actual->obtenerValor().getId() << std::endl;

        int longitudActual = actual->obtenerValor().longitudColaEsperaNucleo();
        if (longitudActual > maxLongitud) {
            // Nuevo máximo encontrado
            masOcupado = &actual->obtenerValor();
            maxLongitud = longitudActual;
        }

        actual = actual->obtenerSiguiente();
    }

    if (maxLongitud == 0) {
        std::cout << "Todos los núcleos tienen sus colas de espera vacías." << std::endl;
        throw std::runtime_error("Todos los núcleos están vacíos.");
    }

    // Segundo recorrido: Listar todos los núcleos empatados
    actual = listaNucleos.obtenerCabeza(); // Reiniciamos para recorrer de nuevo
    std::cout << "Núcleos con " << maxLongitud << " procesos en espera:" << std::endl;

    while (actual != nullptr) {
        if (actual->obtenerValor().longitudColaEsperaNucleo() == maxLongitud) {
            std::cout << "- Núcleo " << actual->obtenerValor().getId() << std::endl;
        }
        actual = actual->obtenerSiguiente();
    }

    return *masOcupado;
}



//Nucleo con menos procesos en espera
Nucleo& Planificador::nucleoMenosOcupado() {
    pNodoLista actual = listaNucleos.obtenerCabeza();
    if (actual == nullptr) { // Validación si la lista está vacía
        std::cerr << "Error: Lista de núcleos vacía." << std::endl;
        throw std::runtime_error("Lista de núcleos vacía");
    }

    Nucleo* menosOcupado = nullptr;
    int minLongitud = INT_MAX; // Inicializar con el valor máximo posible de un entero

    // Primer recorrido: Encontrar la longitud mínima y un núcleo representativo
    while (actual != nullptr) {
        std::cout << "Revisando núcleo: " << actual->obtenerValor().getId() << std::endl;

        int longitudActual = actual->obtenerValor().longitudColaEsperaNucleo();
        if (longitudActual < minLongitud) {
            // Nuevo mínimo encontrado
            menosOcupado = &actual->obtenerValor();
            minLongitud = longitudActual;
        }

        actual = actual->obtenerSiguiente();
    }

    if (menosOcupado == nullptr) {
        std::cerr << "Error: No se encontró núcleo menos ocupado." << std::endl;
        throw std::runtime_error("No se encontró núcleo menos ocupado");
    }

    // Segundo recorrido: Listar todos los núcleos empatados
    actual = listaNucleos.obtenerCabeza(); // Reiniciamos para recorrer de nuevo
    std::cout << "Núcleos con " << minLongitud << " procesos en espera:" << std::endl;

    while (actual != nullptr) {
        if (actual->obtenerValor().longitudColaEsperaNucleo() == minLongitud) {
            std::cout << "- Núcleo " << actual->obtenerValor().getId() << std::endl;
        }
        actual = actual->obtenerSiguiente();
    }

    return *menosOcupado;
}


//Función 7 número de núcleos en la lista
int Planificador::numeroNucleos(){
    std::cout<<listaNucleos.longitud()<<std::endl;
    return listaNucleos.longitud(); // Devuelve el número de núcleos

}


//Funcion 8, ejecutar todos los procesos
void Planificador::ejecutarTodosLosProcesos() {
    int procesosTerminados = 0;
    int minuto = 0;
    int totalTiempoEnSistema = 0;
    int totalProcesos = pilaProcesos.longitud(); // Número total de procesos

    int tiempoInicio = minuto;  // Guardamos el minuto inicial de la simulación

    // Asignar los primeros tres procesos a los núcleos
    for (int i = 0; i < 3 && !pilaProcesos.esVacia(); ++i) {
        Proceso* proceso = pilaProcesos.mostrar();
        if (proceso) {
            asignarProcesoANucleo(proceso);
            proceso->setInicio(minuto); // Establecemos el minuto de inicio del proceso
            pilaProcesos.desapilar();
        }
    }

    

    // Simular el paso del tiempo minuto a minuto
    while (procesosTerminados < totalProcesos) {
        std::cout << "Simulando minuto " << minuto << std::endl;
        mostrarProcesosEnEjecucion();

        // Procesar los núcleos minuto a minuto
        pNodoLista actual = listaNucleos.obtenerCabeza();
        bool hayProcesosActivos = false;

        while (actual != nullptr) {
            Nucleo& nucleo = actual->obtenerValor(); // Usar obtenerValor()
            Proceso* procesoEnNucleo = nucleo.getProceso();
            if (procesoEnNucleo != nullptr) {
                // Comprobar si el proceso ha terminado
                if (minuto - procesoEnNucleo->getInicio() >= procesoEnNucleo->getTiempoVida()) {
                    int tiempoEnSistema = minuto - procesoEnNucleo->getInicio();
                    int tiempoEnCola = procesoEnNucleo->getInicio() - tiempoInicio;
                    int tiempoTotal = tiempoEnCola + procesoEnNucleo->getTiempoVida();
                    std::cout << "Fin del proceso: "
                              << "Minuto: " << minuto << ", "
                              << "PID: " << procesoEnNucleo->getPID() << ", "
                              << "PPID: " << procesoEnNucleo->getPPID() << ", "
                              << "Nucleo: " << nucleo.getId() << ", "
                              << "Estado: Terminado, "
                              << "Tiempo en cola: " << tiempoEnCola << " minutos, "
                              << "Tiempo de vida: " << procesoEnNucleo->getTiempoVida() << " minutos, "
                              << "Tiempo total: " << tiempoTotal << " minutos" << std::endl;
                    totalTiempoEnSistema += tiempoTotal;
                    nucleo.liberarProceso();
                    procesosTerminados++;

                    // Asignar un nuevo proceso del núcleo si hay en la cola de espera
                    if (!nucleo.colaEsperaNucleo.es_vacia()) {
                        Proceso nuevoProceso = nucleo.colaEsperaNucleo.desencolar();
                        Proceso* nuevoProcesoPtr = new Proceso(nuevoProceso);
                        nucleo.asignarProceso(nuevoProcesoPtr);
                        nuevoProcesoPtr->setInicio(minuto);
                        std::cout << "Inicio del proceso: "
                                  << "Minuto: " << minuto << ", "
                                  << "PID: " << nuevoProcesoPtr->getPID() << ", "
                                  << "PPID: " << nuevoProcesoPtr->getPPID() << ", "
                                  << "Nucleo: " << nucleo.getId() << ", "
                                  << "Estado: Ejecutando" << std::endl;
                    }
                }
                hayProcesosActivos = true;
            }
            actual = actual->obtenerSiguiente(); // Avanzar al siguiente nodo
        }

        // Comprobar si hay núcleos vacíos y eliminarlos si hay más de dos libres
        eliminarNucleosLibres();

        minuto++;

        // Verificar si no hay más procesos en ejecución
        if (!hayProcesosActivos) {
            std::cout << "No hay procesos activos en los núcleos. Terminando simulación." << std::endl;
            break;
        }
    }

    // Calcular el tiempo medio que los procesos pasan en el sistema
    double tiempoMedioEnSistema = (double)totalTiempoEnSistema / totalProcesos;
    
    // Mostrar el tiempo medio con 2 decimales usando printf
    printf("Tiempo medio en el sistema: %.2f minutos\n", tiempoMedioEnSistema);
}




//Agregar núcleo si todos los núcleos tienen más de 2 procesos en espera
void Planificador::agregarNucleo() {
    // Verificar si todos los núcleos tienen más de 2 procesos en espera
    bool todosTienenMasDeDos = true;
    pNodoLista actual = listaNucleos.obtenerCabeza();

    while (actual != nullptr) {
        Nucleo& nucleo = actual->obtenerValor();
        if (nucleo.longitudColaEsperaNucleo() <= 2) {
            todosTienenMasDeDos = false;
            break;
        }
        actual = actual->obtenerSiguiente();
    }

    if (todosTienenMasDeDos) {
        // Crear un nuevo núcleo con un ID único
        int nuevoId = listaNucleos.longitud() + 1;
        while (listaNucleos.buscar(nuevoId) != nullptr) {
            nuevoId++;
        }
        Cola nuevaCola;
        Nucleo nuevoNucleo(nuevoId, nuevaCola);
        listaNucleos.insertarFinal(nuevoNucleo);

        std::cout << "Núcleo " << nuevoId << " añadido a la lista." << std::endl;

        // Redistribuir procesos en espera para balancear las colas
        actual = listaNucleos.obtenerCabeza();
        while (actual != nullptr) {
            Nucleo& nucleo = actual->obtenerValor();
            while (nucleo.longitudColaEsperaNucleo() > 2) {
                Proceso procesoSobrante = nucleo.colaEsperaNucleo.desencolar(); // Extraer proceso
                nuevoNucleo.colaEsperaNucleo.encolar(procesoSobrante, procesoSobrante.getPrioridad()); // Mover al nuevo núcleo
                std::cout << "Proceso PID " << procesoSobrante.getPID()
                          << " movido al núcleo " << nuevoId << "." << std::endl;
            }
            actual = actual->obtenerSiguiente();
        }
    } else {
        std::cout << "No es necesario añadir un núcleo. Hay al menos un núcleo con 2 o menos procesos en espera." << std::endl;
    }
}

//Eliminar núcleo si hay al menos 2 núcleos libres
void Planificador::eliminarNucleo() {
    int nucleosLibres = 0;
    pNodoLista actual = listaNucleos.obtenerCabeza();

    // Contar núcleos libres
    while (actual != nullptr) {
        Nucleo& nucleo = actual->obtenerValor();
        if (nucleo.estaLibre() && nucleo.longitudColaEsperaNucleo() == 0) {
            nucleosLibres++;
        }
        actual = actual->obtenerSiguiente();
    }

    // Verificar si hay al menos un núcleo libre
    if (nucleosLibres < 1) {
        std::cout << "No hay suficientes núcleos libres para eliminar." << std::endl;
        return;
    }

    // Eliminar el primer núcleo libre encontrado
    actual = listaNucleos.obtenerCabeza();
    while (actual != nullptr) {
        Nucleo& nucleo = actual->obtenerValor();
        if (nucleo.estaLibre() && nucleo.longitudColaEsperaNucleo() == 0) {
            std::cout << "Núcleo " << nucleo.getId() << " eliminado." << std::endl;
            listaNucleos.eliminar(nucleo); // Eliminar el núcleo de la lista
            return;
        }
        actual = actual->obtenerSiguiente();
    }

    std::cout << "No se encontró ningún núcleo vacío para eliminar." << std::endl;
}

void Planificador::mostrarProcesosEnEjecucion() {
    std::cout << "Procesos en ejecución:" << std::endl;
    pNodoLista actual = listaNucleos.obtenerCabeza();
    while (actual != nullptr) {
        Nucleo& nucleo = actual->obtenerValor();
        Proceso* proceso = nucleo.getProceso();
        if (proceso != nullptr) {
            std::cout << "Núcleo " << nucleo.getId() << " ejecutando proceso PID " << proceso->getPID() << std::endl;
        } else {
            std::cout << "Núcleo " << nucleo.getId() << " está libre." << std::endl;
        }
        actual = actual->obtenerSiguiente();
    }
}

void Planificador::setNumeroProcesos(int numero) {
    numeroProcesos = numero;
}

