#include "aeropuerto.hpp"

// Constructor por defecto
Aeropuerto::Aeropuerto() : clave(""), nombre(""), ciudad(""), pais("") {}

// Constructor con parámetros
Aeropuerto::Aeropuerto(string c, string n, string ci, string p)
    : clave(c), nombre(n), ciudad(ci), pais(p) {}

// Obtener clave
string Aeropuerto::getClave() const {
    return clave;
}

// Obtener nombre
string Aeropuerto::getNombre() const {
    return nombre;
}

// Obtener ciudad
string Aeropuerto::getCiudad() const {
    return ciudad;
}

// Obtener país
string Aeropuerto::getPais() const {
    return pais;
}

// Establecer clave
void Aeropuerto::setClave(string c) {
    clave = c;
}

// Establecer nombre
void Aeropuerto::setNombre(string n) {
    nombre = n;
}

// Establecer ciudad
void Aeropuerto::setCiudad(string ci) {
    ciudad = ci;
}

// Establecer país
void Aeropuerto::setPais(string p) {
    pais = p;
}
