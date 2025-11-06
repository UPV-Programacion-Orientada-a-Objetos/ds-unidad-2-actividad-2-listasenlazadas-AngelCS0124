/**
 * @file SerialComms.cpp
 * @brief Implementación de la comunicación serial (versión simulada)
 */

#include "../include/Serial.h"
#include <iostream>

// Versión simulada para ESP32 - en entorno real se implementaría con APIs específicas

Serial::Serial(const char* nombrePuerto, int baudRate) : puerto(-1) {
    std::cout << "SerialComms: Inicializando puerto " << nombrePuerto << " a " << baudRate << " baudios" << std::endl;
    // En implementación real: abrir puerto serial
}

Serial::~Serial() {
    cerrar();
}

bool Serial::leerLinea(char* buffer, int tamaño) {
    // Simulación - en implementación real leería del puerto serial
    // Por ahora devolvemos false para indicar fin de datos
    return false;
}

bool Serial::datosDisponibles() {
    // Simulación - en implementación real verificaría buffer serial
    return false;
}

void Serial::cerrar() {
    if (puerto != -1) {
        std::cout << "SerialComms: Cerrando puerto" << std::endl;
        puerto = -1;
    }
}