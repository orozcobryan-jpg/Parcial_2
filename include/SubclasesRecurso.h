#ifndef SUBCLASESRECURSO_H
#define SUBCLASESRECURSO_H

#include "Recurso.h"

// Especializaciones de personal

class Medico : public Recurso {
public:
    Medico(std::string nombre);
    ~Medico() override;
    void ejecutarAccion() override;
};

class Rescatista : public Recurso {
public:
    Rescatista(std::string nombre);
    ~Rescatista() override;
    void ejecutarAccion() override;
};

// Especializaciones de vehículos

class Ambulancia : public Recurso {
private:
    std::string placa;
public:
    Ambulancia(std::string placa);
    ~Ambulancia() override;
    void ejecutarAccion() override;
};

class Helicoptero : public Recurso {
private:
    std::string idAereo;
public:
    Helicoptero(std::string idAereo);
    ~Helicoptero() override;
    void ejecutarAccion() override;
};

#endif