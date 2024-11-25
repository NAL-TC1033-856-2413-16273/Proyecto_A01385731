#ifndef AEROPUERTO_HPP
#define AEROPUERTO_HPP

#include <string>

class Aeropuerto {
private:
    std::string clave;
    std::string nombre;
    std::string ciudad;
    std::string pais;

public:
    Aeropuerto(); // Constructor default
    Aeropuerto(std::string c, std::string n, std::string ci, std::string p); // Constructor con parámetros
    std::string getClave() const;    // Obtener clave
    std::string getNombre() const;   // Obtener nombre
    std::string getCiudad() const;   // Obtener ciudad
    std::string getPais() const;     // Obtener país
    void setClave(std::string c);    // Establecer clave
    void setNombre(std::string n);   // Establecer nombre
    void setCiudad(std::string ci);  // Establecer ciudad
    void setPais(std::string p);     // Establecer país
    void imprime() const;            // Imprimir información del aeropuerto
};

#endif // AEROPUERTO_HPP

