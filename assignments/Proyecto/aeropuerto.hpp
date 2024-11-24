#ifndef AEROPUERTO_HPP
#define AEROPUERTO_HPP

#include <string>
using namespace std;

class Aeropuerto {
private:
    string clave;
    string nombre;
    string ciudad;
    string pais;

public:
    Aeropuerto(); // Constructor por defecto
    Aeropuerto(string c, string n, string ci, string p); // Constructor con parámetros
    string getClave() const;    // Obtener clave
    string getNombre() const;   // Obtener nombre
    string getCiudad() const;   // Obtener ciudad
    string getPais() const;     // Obtener país
    void setClave(string c);    // Establecer clave
    void setNombre(string n);   // Establecer nombre
    void setCiudad(string ci);  // Establecer ciudad
    void setPais(string p);     // Establecer país
};

#endif // AEROPUERTO_HPP
