#ifndef HORA_HPP
#define HORA_HPP

class Hora {
private:
    int hora;
    int minutos;

public:
    Hora();                       // Constructor default
    Hora(int h, int m);           // Constructor con parámetros
    int getHora() const;          // Obtener hora
    int getMin() const;           // Obtener minutos
    void setHora(int h);          // Establecer hora (validado)
    void setMin(int m);           // Establecer minutos (validado)
    void imprime() const;         // Imprimir hora en formato 00:00
};

#endif // HORA_HPP


