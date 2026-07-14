#include "../include/Mision.h"
#include <iostream>

Mision::Mision(std::string nombreMision) : nombreMision(nombreMision), cantRecursos(0), capacidadRecursos(2) {
    recursosAsignados = new Recurso*[capacidadRecursos];
}

Mision::~Mision() {
    
    delete[] recursosAsignados; 
}

void Mision::redimensionarRecursos() {
    capacidadRecursos *= 2;
    Recurso** nuevoArreglo = new Recurso*[capacidadRecursos];
    for (int i = 0; i < cantRecursos; i++) {
        nuevoArreglo[i] = recursosAsignados[i];
    }
    delete[] recursosAsignados;
    recursosAsignados = nuevoArreglo;
}

std::string Mision::getNombreMision() const { return nombreMision; }

int Mision::getCantRecursos() const { return cantRecursos; }

Recurso* Mision::getRecurso(int indice) const {
    if (indice >= 0 && indice < cantRecursos) return recursosAsignados[indice];
    return nullptr;
}

void Mision::asignarRecurso(Recurso* r) {
    if (cantRecursos >= capacidadRecursos) {
        redimensionarRecursos();
    }
    recursosAsignados[cantRecursos++] = r;
}

void Mision::ejecutarMision() {
    std::cout << "\n========================================\n";
    std::cout << "EJECUTANDO Mision: " << nombreMision << "\n";
    std::cout << "========================================\n";
    if (cantRecursos == 0) {
        std::cout << "No hay recursos asignados a esta Mision.\n";
        return;
    }
    for (int i = 0; i < cantRecursos; i++) {
        recursosAsignados[i]->ejecutarAccion(); 
    }
    std::cout << "========================================\n";
}