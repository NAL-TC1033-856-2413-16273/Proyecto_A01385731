#include "Aeropuerto.hpp"
#include <iostream>

Aeropuerto::Aeropuerto() : clave(""), nombre(""), ciudad(""), pais("") {}

Aeropuerto::Aeropuerto(std::string c, std::string n, std::string ci, std::string p)
    : clave(c), nombre(n), ciudad(ci), pais(p) {}

std::string Aeropuerto::getClave() const {
    return clave;
}

std::string Aeropuerto::getNombre() const {
    return nombre;
}

std::string Aeropuerto::getCiudad() const {
    return ciudad;
}

std::string Aeropuerto::getPais() const {
    return pais;
}

void Aeropuerto::setClave(std::string c) {
    clave = c;
}

void Aeropuerto::setNombre(std::string n) {
    nombre = n;
}

void Aeropuerto::setCiudad(std::string ci) {
    ciudad = ci;
}

void Aeropuerto::setPais(std::string p) {
    pais = p;
}

void Aeropuerto::imprime() const {
    std::cout << "Aeropuerto: " << nombre
              << " (" << clave << "), Ciudad: " << ciudad
              << ", País: " << pais << std::endl;
}
