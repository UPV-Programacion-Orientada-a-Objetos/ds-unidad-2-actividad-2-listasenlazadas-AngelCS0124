/**
 * @file Decodificador.cpp
 * @brief Implementación del decodificador principal
 */

#include "../include/Decodificador.h"
#include "../include/TramaLoad.h"
#include "../include/TramaMap.h"
#include "../include/Serial.h"
#include <iostream>
#include <windows.h>

// Función personalizada para calcular longitud de cadena
int miStrlen(const char* str) {
    int len = 0;
    while (str && str[len] != '\0') {
        len++;
    }
    return len;
}

// Función personalizada para convertir string a int
int miAtoi(const char* str) {
    if (!str || str[0] == '\0') return 0;
    
    int resultado = 0;
    int signo = 1;
    int i = 0;
    
    // Manejar signo negativo
    if (str[0] == '-') {
        signo = -1;
        i = 1;
    } else if (str[0] == '+') {
        i = 1;
    }
    
    // Convertir dígitos
    while (str[i] >= '0' && str[i] <= '9') {
        resultado = resultado * 10 + (str[i] - '0');
        i++;
    }
    
    return resultado * signo;
}

Decodificador::Decodificador() {
    std::cout << "Iniciando Decodificador PRT-7..." << std::endl;
}

TramaBase* Decodificador::parsearLinea(const char* linea) {
    if (!linea || miStrlen(linea) < 2) return nullptr;
    
    // Ignorar líneas de control
    if (linea[0] == '-' || (linea[0] == 'F' && linea[1] == 'I' && linea[2] == 'N')) {
        return nullptr;
    }
    
    // Buscar la coma
    int i = 0;
    while (linea[i] != '\0' && linea[i] != ',') {
        i++;
    }
    
    if (linea[i] != ',') return nullptr;
    
    char tipo = linea[0];
    const char* valorStr = &linea[i + 1];
    
    if (tipo == 'L') {
        // Para espacios, tomar el primer carácter después de la coma
        if (miStrlen(valorStr) >= 1) {
            char caracter = valorStr[0];
            // Si es espacio después de la coma, procesar como espacio
            if (caracter == ' ') {
                return new TramaLoad(' ');
            } else {
                return new TramaLoad(caracter);
            }
        }
    } else if (tipo == 'M') {
        int valor = miAtoi(valorStr);
        return new TramaMap(valor);
    }
    
    return nullptr;
}

void Decodificador::procesarTrama(TramaBase* trama) {
    if (trama) {
        trama->procesar(&listaCarga, &rotor);
        delete trama;
    }
}

void Decodificador::procesarDatos(const char** lineas, int numLineas) {
    std::cout << "Procesando " << numLineas << " tramas..." << std::endl << std::endl;
    
    for (int i = 0; i < numLineas; i++) {
        TramaBase* trama = parsearLinea(lineas[i]);
        if (trama) {
            procesarTrama(trama);
        } else {
            std::cout << "Error: Trama mal formada: " << lineas[i] << std::endl;
        }
    }
    
    std::cout << "\n---" << std::endl;
    mostrarMensajeFinal();
}

void Decodificador::iniciarComunicacionSerial(const char* puerto) {
    std::cout << "Conectando a puerto " << puerto << "..." << std::endl;
    
    Serial serial(puerto, 9600);
    
    if (!serial.estaConectado()) {
        std::cout << "ERROR: No se pudo conectar" << std::endl;
        return;
    }
    
    std::cout << "Conexion establecida con " << puerto << std::endl;
    std::cout << "Esperando datos del ESP32..." << std::endl;
    
    int tramasRecibidas = 0;
    int timeout = 0;
    const int MAX_TIMEOUT = 200; // 20 segundos
    
    while (timeout < MAX_TIMEOUT) {
        if (serial.datosDisponibles()) {
            char buffer[256];
            if (serial.leerLinea(buffer, sizeof(buffer))) {
                tramasRecibidas++;
                std::cout << "Trama " << tramasRecibidas << ": '" << buffer << "'" << std::endl;
                timeout = 0;
                
                if (strstr(buffer, "FIN") != nullptr) {
                    std::cout << "Fin de transmision" << std::endl;
                    break;
                }
                
                TramaBase* trama = parsearLinea(buffer);
                if (trama) {
                    procesarTrama(trama);
                } else {
                    std::cout << "❌ Trama no valida ignorada" << std::endl;
                }
            }
        } else {
            timeout++;
            if (timeout % 10 == 0) {
                std::cout << "Esperando... (" << (timeout/10) << "s) - ";
                std::cout << "Presiona RESET del ESP32 si no ves datos!" << std::endl;
            }
            Sleep(100);
        }
    }
    
    std::cout << "\n=== RESUMEN ===" << std::endl;
    std::cout << "Tramas recibidas: " << tramasRecibidas << std::endl;
    
    if (tramasRecibidas == 0) {
        std::cout << "PROBLEMA: No se recibio ninguna trama" << std::endl;
        std::cout << "Soluciones:" << std::endl;
        std::cout << "1. Presiona RESET del ESP32 despues de ejecutar este programa" << std::endl;
        std::cout << "2. Verifica que el codigo del ESP32 tenga Serial.begin(9600)" << std::endl;
        std::cout << "3. Prueba otro cable USB" << std::endl;
    }
    
    std::cout << "\n---" << std::endl;
    mostrarMensajeFinal();
}

void Decodificador::mostrarMensajeFinal() {
    std::cout << "Flujo de datos terminado." << std::endl;
    std::cout << "MENSAJE OCULTO ENSAMBLADO:" << std::endl;
    listaCarga.imprimirMensaje();
    std::cout << "\n---" << std::endl;
    
    // Mostrar también como string simple
    char mensaje[256];
    listaCarga.obtenerMensaje(mensaje, sizeof(mensaje));
    std::cout << "Mensaje: " << mensaje << std::endl;
    std::cout << "---" << std::endl;
    std::cout << "Liberando memoria... Sistema apagado." << std::endl;
}