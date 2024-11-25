#include "Hora.hpp"
#include <iostream>
#include <iomanip> // Para usar setw y setfill

// Constructor default
Hora::Hora() : hora(0), minutos(0) {}

// Constructor con parámetros (validación incluida)
Hora::Hora(int h, int m) {
    setHora(h);
    setMin(m);
}

// Obtener hora
int Hora::getHora() const {
    return hora;
}

// Obtener minutos
int Hora::getMin() const {
    return minutos;
}

// Establecer hora (validación)
void Hora::setHora(int h) {
    if (h >= 0 && h < 24)
        hora = h;
    else
        hora = 0;
}

// Establecer minutos (validación)
void Hora::setMin(int m) {
    if (m >= 0 && m < 60)
        minutos = m;
    else
        minutos = 0;
}

// Imprimir hora en formato 00:00
void Hora::imprime() const {
    std::cout << std::setfill('0') << std::setw(2) << hora << ":"
              << std::setfill('0') << std::setw(2) << minutos;
}


