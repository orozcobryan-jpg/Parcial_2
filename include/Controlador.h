#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Recurso.h"
#include "Mision.h"

class Controlador {
private:
    Recurso** inventarioRecursos;
    int cantRecursos;
    int capRecursos;

    Mision** listaMisiones;
    int cantMisiones;
    int capMisiones;

    void redimensionarRecursos();
    void redimensionarMisiones();
    void cargarDatosPrueba(); 

    // Métodos auxiliares de interfaz
    void mostrarRecursos() const;
    void registrarNuevoRecurso();
    void crearMision();
    void asignarRecursoAMision();
    void ejecutarMision();

public:
    Controlador();
    ~Controlador(); 
    void iniciar(); 
};

#endif