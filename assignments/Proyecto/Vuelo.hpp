#ifndef VUELO_HPP
#define VUELO_HPP

#include "Hora.hpp"
#include "Aeropuerto.hpp"
#include <string>

class Vuelo {
private:
    std::string ID;
    Aeropuerto destino;
    std::string aerolinea;
    int numPas;
    Hora salidaEstim;
    Hora salidaReal;
    int estatus; // 1: A tiempo, 0: Demorado

public:
    Vuelo(); // Constructor default
    Vuelo(std::string id, Aeropuerto dest, std::string aero, int numP, Hora salida); // Constructor con parámetros
    std::string getID() const;          // Obtener ID
    Aeropuerto getDestino() const;      // Obtener destino
    std::string getAerolinea() const;   // Obtener aerolínea
    int getNumPas() const;              // Obtener número de pasajeros
    Hora getSalidaEstim() const;        // Obtener salida estimada
    Hora getSalidaReal() const;         // Obtener salida real
    int getEstatus() const;             // Obtener estatus
    void setID(std::string id);         // Establecer ID
    void setDestino(Aeropuerto dest);   // Establecer destino
    void setAerolinea(std::string aero); // Establecer aerolínea
    void setNumPas(int numP);           // Establecer número de pasajeros
    void setSalidaEstim(Hora salida);   // Establecer salida estimada
    void setSalidaReal(Hora salida);    // Establecer salida real
    void setEstatus(int est);           // Establecer estatus
    int calculaTiempoRetraso() const;   // Calcular tiempo de retraso
    void imprime() const;               // Imprimir información del vuelo
};

#endif // VUELO_HPP

