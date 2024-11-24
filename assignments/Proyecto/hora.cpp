#include "hora.hpp"

// Constructor por defecto
Hora::Hora() : hora(0), minutos(0) {}

// Constructor con parámetros
Hora::Hora(int h, int m) : hora(h), minutos(m) {}

// Obtener hora
int Hora::getHora() const {
    return hora;
}

// Obtener minutos
int Hora::getMin() const {
    return minutos;
}

// Establecer hora
void Hora::setHora(int h) {
    hora = h;
}

// Establecer minutos
void Hora::setMin(int m) {
    minutos = m;
}
