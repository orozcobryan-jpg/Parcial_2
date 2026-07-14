#include "../include/SubclasesRecurso.h"
#include <iostream>

// Medico
Medico::Medico(std::string nombre) : Recurso(nombre, "Medico") {}
Medico::~Medico() {}
void Medico::ejecutarAccion() {
    std::cout << "[Medico - " << nombre << "]: Estabilizando signos vitales.\n";
}

// Rescatista
Rescatista::Rescatista(std::string nombre) : Recurso(nombre, "Rescatista") {}
Rescatista::~Rescatista() {}
void Rescatista::ejecutarAccion() {
    std::cout << "[Rescatista - " << nombre << "]: Buscando sobrevivientes en escombros.\n";
}

// Ambulancia
Ambulancia::Ambulancia(std::string placa) : Recurso(placa, "Ambulancia"), placa(placa) {}
Ambulancia::~Ambulancia() {}
void Ambulancia::ejecutarAccion() {
    std::cout << "[Ambulancia - Placa " << placa << "]: Transportando paciente via terrestre.\n";
}

// Helicoptero
Helicoptero::Helicoptero(std::string idAereo) : Recurso(idAereo, "Helicoptero"), idAereo(idAereo) {}
Helicoptero::~Helicoptero() {}
void Helicoptero::ejecutarAccion() {
    std::cout << "[Helicoptero - ID " << idAereo << "]: Realizando extraccion aerea.\n";
}