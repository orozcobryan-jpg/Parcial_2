#include "../include/Recurso.h"

Recurso::Recurso(std::string nombre, std::string tipo) : nombre(nombre), tipo(tipo) {}

Recurso::~Recurso() {}

std::string Recurso::getNombre() const { return nombre; }
std::string Recurso::getTipo() const { return tipo; }