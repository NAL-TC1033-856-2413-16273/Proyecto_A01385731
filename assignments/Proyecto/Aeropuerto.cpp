#include "Aeropuerto.hpp"
#include <iostream>

// Constructor default
Aeropuerto::Aeropuerto() : clave(""), nombre(""), ciudad(""), pais("") {}

// Constructor con parámetros
Aeropuerto::Aeropuerto(std::string c, std::string n, std::string ci, std::string p)
    : clave(c), nombre(n), ciudad(ci), pais(p) {}

// Obtener clave
std::string Aeropuerto::getClave() const {
    return clave;
}

// Obtener nombre
std::string Aeropuerto::getNombre() const {
    return nombre;
}

// Obtener ciudad
std::string Aeropuerto::getCiudad() const {
    return ciudad;
}

// Obtener país
std::string Aeropuerto::getPais() const {
    return pais;
}

// Establecer clave
void Aeropuerto::setClave(std::string c) {
    clave = c;
}

// Establecer nombre
void Aeropuerto::setNombre(std::string n) {
    nombre = n;
}

// Establecer ciudad
void Aeropuerto::setCiudad(std::string ci) {
    ciudad = ci;
}

// Establecer país
void Aeropuerto::setPais(std::string p) {
    pais = p;
}

// Imprimir información del aeropuerto
void Aeropuerto::imprime() const {
    std::cout << "Aeropuerto: " << nombre
              << " (" << clave << "), Ciudad: " << ciudad
              << ", País: " << pais << std::endl;
}
