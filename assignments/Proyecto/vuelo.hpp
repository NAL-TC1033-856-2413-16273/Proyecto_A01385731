#ifndef VUELO_HPP
#define VUELO_HPP

#include "hora.hpp"
#include "aeropuerto.hpp"
#include <string>
using namespace std;

class Vuelo {
private:
    string ID;
    Aeropuerto destino;
    string aerolinea;
    int numPas;
    Hora salidaEstim;
    Hora salidaReal;
    int estatus; // 1: A tiempo, 0: Demorado

public:
    Vuelo(); // Constructor por defecto
    Vuelo(string id, Aeropuerto dest, string aero, int numP, Hora salida); // Constructor con parámetros
    string getID() const;          // Obtener ID
    Aeropuerto getDestino() const; // Obtener destino
    string getAerolinea() const;   // Obtener aerolínea
    int getNumPas() const;         // Obtener número de pasajeros
    Hora getSalidaEstim() const;   // Obtener hora de salida estimada
    Hora getSalidaReal() const;    // Obtener hora de salida real
    int getEstatus() const;        // Obtener estatus
    void setID(string id);         // Establecer ID
    void setDestino(Aeropuerto dest);  // Establecer destino
    void setAerolinea(string aero);    // Establecer aerolínea
    void setNumPas(int numP);          // Establecer número de pasajeros
    void setSalidaEstim(Hora salida); // Establecer salida estimada
    void setSalidaReal(Hora salida);  // Establecer salida real
    void setEstatus(int est);         // Establecer estatus
};

#endif // VUELO_HPP
