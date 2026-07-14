#ifndef RECURSO_H
#define RECURSO_H

#include <string>
#include <iostream>

class Recurso {
protected:
    std::string nombre;
    std::string tipo;

public:
    Recurso(std::string nombre, std::string tipo);
    virtual ~Recurso(); 

    std::string getNombre() const;
    std::string getTipo() const;
    
    virtual void ejecutarAccion() = 0; 
};

#endif