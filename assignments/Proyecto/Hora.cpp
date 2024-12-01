#include "Hora.hpp"
#include <iostream>
#include <iomanip> 


Hora::Hora() : hora(0), minutos(0) {}


Hora::Hora(int h, int m) {
    setHora(h);
    setMin(m);
}


int Hora::getHora() const {
    return hora;
}


int Hora::getMin() const {
    return minutos;
}


void Hora::setHora(int h) {
    if (h >= 0 && h < 24)
        hora = h;
    else
        hora = 0;
}

void Hora::setMin(int m) {
    if (m >= 0 && m < 60)
        minutos = m;
    else
        minutos = 0;
}

void Hora::imprime() const {
    std::cout << std::setfill('0') << std::setw(2) << hora << ":"
              << std::setfill('0') << std::setw(2) << minutos;
}


