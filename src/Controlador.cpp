#include "../include/Controlador.h"
#include "../include/SubclasesRecurso.h"
#include <iostream>
#include <limits>

Controlador::Controlador() : cantRecursos(0), capRecursos(2), cantMisiones(0), capMisiones(2) {
    inventarioRecursos = new Recurso*[capRecursos];
    listaMisiones = new Mision*[capMisiones];
    cargarDatosPrueba(); 
}

Controlador::~Controlador() {
    
    for (int i = 0; i < cantRecursos; i++) {
        delete inventarioRecursos[i]; // Llama al destructor virtual del recurso
    }
    delete[] inventarioRecursos;

    for (int i = 0; i < cantMisiones; i++) {
        delete listaMisiones[i]; // Llama al destructor de la mision
    }
    delete[] listaMisiones;
    std::cout << "\n[Sistema]: Todos los recursos del Heap fueron liberados con éxito.\n";
}

void Controlador::redimensionarRecursos() {
    capRecursos *= 2;
    Recurso** nuevo = new Recurso*[capRecursos];
    for (int i = 0; i < cantRecursos; i++) nuevo[i] = inventarioRecursos[i];
    delete[] inventarioRecursos;
    inventarioRecursos = nuevo;
}

void Controlador::redimensionarMisiones() {
    capMisiones *= 2;
    Mision** nuevo = new Mision*[capMisiones];
    for (int i = 0; i < cantMisiones; i++) nuevo[i] = listaMisiones[i];
    delete[] listaMisiones;
    listaMisiones = nuevo;
}

void Controlador::cargarDatosPrueba() {
    
    listaMisiones[cantMisiones++] = new Mision("Rescate Deslizamiento Siloé");
    redimensionarMisiones();
    listaMisiones[cantMisiones++] = new Mision("Inundación Río Cauca - Juanchito");

    
    inventarioRecursos[cantRecursos++] = new Ambulancia("TXB-432");
    redimensionarRecursos();
    inventarioRecursos[cantRecursos++] = new Ambulancia("OPS-881");
    redimensionarRecursos();
    inventarioRecursos[cantRecursos++] = new Helicoptero("FAC-004");
    redimensionarRecursos();
    inventarioRecursos[cantRecursos++] = new Medico("Dr. Alejandro Restrepo");
    redimensionarRecursos();
    inventarioRecursos[cantRecursos++] = new Medico("Dra. Sofia Valencia");
    redimensionarRecursos();
    inventarioRecursos[cantRecursos++] = new Rescatista("Carlos 'Hierro' Gomez");
    redimensionarRecursos();
    inventarioRecursos[cantRecursos++] = new Rescatista("Diana Cruz");
}

void Controlador::mostrarRecursos() const {
    std::cout << "\n--- INVENTARIO DE RECURSOS DISPONIBLES ---\n";
    for (int i = 0; i < cantRecursos; i++) {
        std::cout << i + 1 << ". [" << inventarioRecursos[i]->getTipo() << "] - " 
                << inventarioRecursos[i]->getNombre() << "\n";
    }
}

void Controlador::registrarNuevoRecurso() {
    std::cout << "\n--- REGISTRAR NUEVO RECURSO ---\n";
    std::cout << "Seleccione Tipo de Recurso:\n";
    std::cout << "1. Medico\n2. Rescatista\n3. Ambulancia\n4. Helicoptero\nSelección: ";
    int op;
    std::cin >> op;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string identificador;
    if (op == 1 || op == 2) {
        std::cout << "Ingrese Nombre Completo: ";
    } else if (op == 3) {
        std::cout << "Ingrese Placa de la Ambulancia: ";
    } else if (op == 4) {
        std::cout << "Ingrese ID de aeronave del Helicoptero: ";
    } else {
        std::cout << "Opcion inválida.\n";
        return;
    }
    std::getline(std::cin, identificador);

    if (cantRecursos >= capRecursos) redimensionarRecursos();

    if (op == 1) inventarioRecursos[cantRecursos++] = new Medico(identificador);
    else if (op == 2) inventarioRecursos[cantRecursos++] = new Rescatista(identificador);
    else if (op == 3) inventarioRecursos[cantRecursos++] = new Ambulancia(identificador);
    else if (op == 4) inventarioRecursos[cantRecursos++] = new Helicoptero(identificador);

    std::cout << "¡Recurso registrado con éxito!\n";
}

void Controlador::crearMision() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n--- CREAR NUEVA MISION ---\n";
    std::cout << "Ingrese nombre de la Mision: ";
    std::string nombre;
    std::getline(std::cin, nombre);

    if (cantMisiones >= capMisiones) redimensionarMisiones();
    listaMisiones[cantMisiones++] = new Mision(nombre);
    std::cout << "Mision \"" << nombre << "\" creada exitosamente.\n";
}

void Controlador::asignarRecursoAMision() {
    if (cantMisiones == 0 || cantRecursos == 0) {
        std::cout << "Debe existir al menos una Mision y un recurso.\n";
        return;
    }

    std::cout << "\n--- SELECCIONAR Mision ---\n";
    for (int i = 0; i < cantMisiones; i++) {
        std::cout << i + 1 << ". " << listaMisiones[i]->getNombreMision() << "\n";
    }
    std::cout << "Seleccione Mision: ";
    int indiceMision;
    std::cin >> indiceMision;
    indiceMision--;

    if (indiceMision < 0 || indiceMision >= cantMisiones) {
        std::cout << "Mision no válida.\n";
        return;
    }

    mostrarRecursos();
    std::cout << "Seleccione Recurso a asignar: ";
    int indiceRecurso;
    std::cin >> indiceRecurso;
    indiceRecurso--;

    if (indiceRecurso < 0 || indiceRecurso >= cantRecursos) {
        std::cout << "Recurso no válido.\n";
        return;
    }

    
    listaMisiones[indiceMision]->asignarRecurso(inventarioRecursos[indiceRecurso]);
    std::cout << "¡Asignación exitosa!\n";
}

void Controlador::ejecutarMision() {
    if (cantMisiones == 0) {
        std::cout << "No hay misiones registradas.\n";
        return;
    }
    std::cout << "\n--- EJECUTAR Mision ---\n";
    for (int i = 0; i < cantMisiones; i++) {
        std::cout << i + 1 << ". " << listaMisiones[i]->getNombreMision() << " (Recursos: " 
                << listaMisiones[i]->getCantRecursos() << ")\n";
    }
    std::cout << "Seleccione Mision a ejecutar: ";
    int op;
    std::cin >> op;
    op--;

    if (op < 0 || op >= cantMisiones) {
        std::cout << "Selección inválida.\n";
        return;
    }
    listaMisiones[op]->ejecutarMision();
}

void Controlador::iniciar() {
    int op = 0;
    do {
        std::cout << "\n==================================================\n";
        std::cout << "   SISTEMA DE Gestion DE MISIONES DE RESCATE      \n";
        std::cout << "==================================================\n";
        std::cout << "1. Ver recursos del sistema\n";
        std::cout << "2. Registrar recurso\n";
        std::cout << "3. Crear Mision\n";
        std::cout << "4. Asignar recurso a Mision\n";
        std::cout << "5. Ejecutar Mision\n";
        std::cout << "6. Salir (Liberar memoria)\n";
        std::cout << "Seleccione Opcion: ";
        std::cin >> op;

        switch (op) {
            case 1: mostrarRecursos(); break;
            case 2: registrarNuevoRecurso(); break;
            case 3: crearMision(); break;
            case 4: asignarRecursoAMision(); break;
            case 5: ejecutarMision(); break;
            case 6: std::cout << "Saliendo del sistema...\n"; break;
            default: std::cout << "Opcion inválida.\n"; break;
        }
    } while (op != 6);
}