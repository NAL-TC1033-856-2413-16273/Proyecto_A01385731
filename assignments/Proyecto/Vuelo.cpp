#include "Vuelo.hpp"
#include <iostream>

// Constructor default
Vuelo::Vuelo() : ID(""), destino(), aerolinea(""), numPas(0), estatus(1) {}

// Constructor con parámetros
Vuelo::Vuelo(std::string id, Aeropuerto dest, std::string aero, int numP, Hora salida)
    : ID(id), destino(dest), aerolinea(aero), numPas(numP), salidaEstim(salida), estatus(1) {}

// Obtener ID
std::string Vuelo::getID() const {
    return ID;
}

// Obtener destino
Aeropuerto Vuelo::getDestino() const {
    return destino;
}

// Obtener aerolínea
std::string Vuelo::getAerolinea() const {
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
void Vuelo::setID(std::string id) {
    ID = id;
}

// Establecer destino
void Vuelo::setDestino(Aeropuerto dest) {
    destino = dest;
}

// Establecer aerolínea
void Vuelo::setAerolinea(std::string aero) {
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

// Calcular tiempo de retraso
int Vuelo::calculaTiempoRetraso() const {
    int horaRetraso = salidaReal.getHora() - salidaEstim.getHora();
    int minRetraso = salidaReal.getMin() - salidaEstim.getMin();
    return (horaRetraso * 60) + minRetraso;
}

// Imprimir información del vuelo
void Vuelo::imprime() const {
    std::cout << "Vuelo ID: " << ID << "\nAerolinea: " << aerolinea
              << "\nPasajeros: " << numPas << "\nEstatus: " 
              << (estatus == 1 ? "A tiempo" : "Demorado") << "\n";
}

