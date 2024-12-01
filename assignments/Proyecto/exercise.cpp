#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Hora.hpp"
#include "Aeropuerto.hpp"
#include "Vuelo.hpp"

const int MAX_AEROPUERTOS = 100;
const int MAX_VUELOS = 200;

void cargarAeropuertos(std::vector<Aeropuerto>& aeropuertos, const std::string& filename);
void cargarVuelos(std::vector<Vuelo>& vuelos, const std::vector<Aeropuerto>& aeropuertos, const std::string& filename);
int buscaAeropuerto(const std::string& clave, const std::vector<Aeropuerto>& aeropuertos);
void menu(const std::vector<Aeropuerto>& aeropuertos, std::vector<Vuelo>& vuelos);

void mostrarAeropuertos(const std::vector<Aeropuerto>& aeropuertos);
void mostrarVuelos(const std::vector<Vuelo>& vuelos);
void buscarVuelosPorDestino(const std::vector<Vuelo>& vuelos, const std::string& claveDestino);
void vuelosEnRangoYATiempo(const std::vector<Vuelo>& vuelos, int horaInicio, int horaFin);
void capturarHoraSalidaReal(std::vector<Vuelo>& vuelos, const std::string& idVuelo);

int main() {
    std::vector<Aeropuerto> aeropuertos;
    std::vector<Vuelo> vuelos;

    cargarAeropuertos(aeropuertos, "aeropuertos.txt");
    cargarVuelos(vuelos, aeropuertos, "datosVuelos.txt");

    menu(aeropuertos, vuelos);

    return 0;
}

void cargarAeropuertos(std::vector<Aeropuerto>& aeropuertos, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error al abrir el archivo " << filename << std::endl;
        return;
    }

    std::string clave, nombre, ciudad, pais;
    while (file >> clave >> nombre >> ciudad >> pais) {
        aeropuertos.emplace_back(clave, nombre, ciudad, pais);
    }

    file.close();
}

void cargarVuelos(std::vector<Vuelo>& vuelos, const std::vector<Aeropuerto>& aeropuertos, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error al abrir el archivo " << filename << std::endl;
        return;
    }

    std::string id, claveAeropuerto, aerolinea;
    int numPas, hora, minutos;
    while (file >> id >> claveAeropuerto >> aerolinea >> numPas >> hora >> minutos) {
        int index = buscaAeropuerto(claveAeropuerto, aeropuertos);
        if (index != -1) {
            Hora salidaEstim(hora, minutos);
            vuelos.emplace_back(id, aeropuertos[index], aerolinea, numPas, salidaEstim);
        } else {
            std::cerr << "Aeropuerto con clave " << claveAeropuerto << " no encontrado." << std::endl;
        }
    }

    file.close();
}

int buscaAeropuerto(const std::string& clave, const std::vector<Aeropuerto>& aeropuertos) {
    for (size_t i = 0; i < aeropuertos.size(); ++i) {
        if (aeropuertos[i].getClave() == clave) {
            return i;
        }
    }
    return -1;
}


void menu(const std::vector<Aeropuerto>& aeropuertos, std::vector<Vuelo>& vuelos) {
    int opcion;
    do {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Mostrar Aeropuertos\n";
        std::cout << "2. Mostrar Vuelos\n";
        std::cout << "3. Buscar Vuelos por Destino\n";
        std::cout << "4. Mostrar Vuelos en un Rango de Tiempo\n";
        std::cout << "5. Capturar Hora de Salida Real\n";
        std::cout << "6. Salir\n";
        std::cout << "Elige una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarAeropuertos(aeropuertos);
                break;
            case 2:
                mostrarVuelos(vuelos);
                break;
            case 3: {
                std::string claveDestino;
                std::cout << "Ingresa la clave del destino: ";
                std::cin >> claveDestino;
                buscarVuelosPorDestino(vuelos, claveDestino);
                break;
            }
            case 4: {
                int horaInicio, horaFin;
                std::cout << "Ingresa la hora de inicio (0-23): ";
                std::cin >> horaInicio;
                std::cout << "Ingresa la hora de fin (0-23): ";
                std::cin >> horaFin;
                vuelosEnRangoYATiempo(vuelos, horaInicio, horaFin);
                break;
            }
            case 5: {
                std::string idVuelo;
                int hora, minutos;
                std::cout << "Ingresa el ID del vuelo: ";
                std::cin >> idVuelo;
                std::cout << "Ingresa la hora real de salida (hh mm): ";
                std::cin >> hora >> minutos;
                capturarHoraSalidaReal(vuelos, idVuelo);
                break;
            }
            case 6:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida." << std::endl;
        }
    } while (opcion != 6);
}

void mostrarAeropuertos(const std::vector<Aeropuerto>& aeropuertos) {
    std::cout << "\n--- Lista de Aeropuertos ---\n";
    for (const auto& aeropuerto : aeropuertos) {
        aeropuerto.imprime();
    }
}

void mostrarVuelos(const std::vector<Vuelo>& vuelos) {
    std::cout << "\n--- Lista de Vuelos ---\n";
    for (const auto& vuelo : vuelos) {
        vuelo.imprime();
    }
}

void buscarVuelosPorDestino(const std::vector<Vuelo>& vuelos, const std::string& claveDestino) {
    std::cout << "\n--- Vuelos al destino " << claveDestino << " ---\n";
    for (const auto& vuelo : vuelos) {
        if (vuelo.getDestino().getClave() == claveDestino) {
            vuelo.imprime();
        }
    }
}

void vuelosEnRangoYATiempo(const std::vector<Vuelo>& vuelos, int horaInicio, int horaFin) {
    std::cout << "\n--- Vuelos en rango de tiempo y 'A tiempo' ---\n";
    for (const auto& vuelo : vuelos) {
        int hora = vuelo.getSalidaEstim().getHora();
        if (hora >= horaInicio && hora <= horaFin && vuelo.getEstatus() == 1) {
            vuelo.imprime();
        }
    }
}

void capturarHoraSalidaReal(std::vector<Vuelo>& vuelos, const std::string& idVuelo) {
    for (auto& vuelo : vuelos) {
        if (vuelo.getID() == idVuelo) {
            int hora, minutos;
            std::cout << "Ingresa la hora real de salida (hh mm): ";
            std::cin >> hora >> minutos;
            Hora nuevaHora(hora, minutos);
            vuelo.setSalidaReal(nuevaHora);

            if (nuevaHora.getHora() > vuelo.getSalidaEstim().getHora() || 
                (nuevaHora.getHora() == vuelo.getSalidaEstim().getHora() && nuevaHora.getMin() > vuelo.getSalidaEstim().getMin())) {
                vuelo.setEstatus(0);
                std::cout << "Vuelo demorado. Minutos de retraso: " << vuelo.calculaTiempoRetraso() << std::endl;
            } else {
                vuelo.setEstatus(1);
                std::cout << "Vuelo a tiempo.\n";
            }
            return;
        }
    }
    std::cout << "Vuelo con ID " << idVuelo << " no encontrado.\n";
}
