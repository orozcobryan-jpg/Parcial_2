#ifndef MISION_H
#define MISION_H

#include <string>
#include "Recurso.h"

class Mision {
private:
    std::string nombreMision;
    Recurso** recursosAsignados; 
    int cantRecursos;
    int capacidadRecursos;

    void redimensionarRecursos(); 

public:
    Mision(std::string nombreMision);
    ~Mision(); // HT02

    std::string getNombreMision() const;
    int getCantRecursos() const;
    Recurso* getRecurso(int indice) const;

    void asignarRecurso(Recurso* r); 
    void ejecutarMision(); 
};

#endif