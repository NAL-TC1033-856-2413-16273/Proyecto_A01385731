#include "vuelo.hpp"

// Constructor por defecto
Vuelo::Vuelo() : ID(""), destino(), aerolinea(""), numPas(0), salidaEstim(), salidaReal(), estatus(1) {}

// Constructor con parámetros
Vuelo::Vuelo(string id, Aeropuerto dest, string aero, int numP, Hora salida)
    : ID(id), destino(dest), aerolinea(aero), numPas(numP), salidaEstim(salida), salidaReal(Hora()), estatus(1) {}

// Obtener ID
string Vuelo::getID() const {
    return ID;
}

// Obtener destino
Aeropuerto Vuelo::getDestino() const {
    return destino;
}

// Obtener aerolínea
string Vuelo::getAerolinea() const {
    return aerolinea;
}

// Obtener número de pasajeros
int Vuelo::getNumPas() const {
    return numPas;
}

// Obtener salida estimada
Hora Vuelo::getSalidaEstim() const {
    return salidaEstim;
}

// Obtener salida real
Hora Vuelo::getSalidaReal() const {
    return salidaReal;
}

// Obtener estatus
int Vuelo::getEstatus() const {
    return estatus;
}

// Establecer ID
void Vuelo::setID(string id) {
    ID = id;
}

// Establecer destino
void Vuelo::setDestino(Aeropuerto dest) {
    destino = dest;
}

// Establecer aerolínea
void Vuelo::setAerolinea(string aero) {
    aerolinea = aero;
}

// Establecer número de pasajeros
void Vuelo::setNumPas(int numP) {
    numPas = numP;
}

// Establecer salida estimada
void Vuelo::setSalidaEstim(Hora salida) {
    salidaEstim = salida;
}

// Establecer salida real
void Vuelo::setSalidaReal(Hora salida) {
    salidaReal = salida;
}

// Establecer estatus
void Vuelo::setEstatus(int est) {
    estatus = est;
}
