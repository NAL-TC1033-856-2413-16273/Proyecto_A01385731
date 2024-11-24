#include "hora.hpp"
#include "aeropuerto.hpp"
#include "vuelo.hpp"
#include <iostream>
using namespace std;

int main() {
    // Crear un aeropuerto
    Aeropuerto destino("JFK", "John F. Kennedy", "Nueva York", "EE.UU.");
    
    // Crear una hora de salida estimada
    Hora salidaEstim(14, 30);
    
    // Crear un vuelo
    Vuelo vuelo("AB123", destino, "American Airlines", 180, salidaEstim);
    
    // Probar getters básicos
    cout << "ID del vuelo: " << vuelo.getID() << endl;
    cout << "Destino: " << vuelo.getDestino().getNombre() << endl;
    cout << "Hora estimada: " << vuelo.getSalidaEstim().getHora() << ":" << vuelo.getSalidaEstim().getMin() << endl;

    return 0;
}
