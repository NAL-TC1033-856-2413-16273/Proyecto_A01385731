#pragma once
#include <string>

class Aeropuerto {
private:
    std::string clave;
    std::string nombre;
    std::string ciudad;
    std::string pais;

public:
    Aeropuerto(); 
    Aeropuerto(std::string c, std::string n, std::string ci, std::string p); 
    std::string getClave() const;   
    std::string getNombre() const;   
    std::string getCiudad() const;   
    std::string getPais() const;    
    void setClave(std::string c);    
    void setNombre(std::string n);   
    void setCiudad(std::string ci); 
    void setPais(std::string p); 
    void imprime() const; 
};


