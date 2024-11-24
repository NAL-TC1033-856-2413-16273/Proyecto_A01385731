#ifndef HORA_HPP
#define HORA_HPP

class Hora {
private:
    int hora;
    int minutos;

public:
    Hora();                       // Constructor por defecto
    Hora(int h, int m);           // Constructor con parámetros
    int getHora() const;          // Obtener la hora
    int getMin() const;           // Obtener los minutos
    void setHora(int h);          // Establecer la hora
    void setMin(int m);           // Establecer los minutos
};

#endif // HORA_HPP
