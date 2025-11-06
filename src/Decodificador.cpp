/**
 * @file DecodificadorPRT7.cpp
 * @brief Implementación del decodificador principal
 */

#include "../include/Decodificador.h"
#include "../include/TramaLoad.h"
#include "../include/TramaMap.h"
#include "../include/Serial.h"
#include <iostream>

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
    if (!linea || miStrlen(linea) < 3) return nullptr;
    
    char tipo = linea[0];
    
    // Verificar formato correcto: "L,X" o "M,N"
    if (linea[1] != ',') return nullptr;
    
    const char* valorStr = &linea[2]; // Saltar "L," o "M,"
    
    if (tipo == 'L') {
        // Trama Load: L,X - tomar primer carácter después de la coma
        if (miStrlen(valorStr) >= 1) {
            return new TramaLoad(valorStr[0]);
        }
    } else if (tipo == 'M') {
        // Trama Map: M,N - convertir el resto a int
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
    
    if (serial.datosDisponibles()) {
        char buffer[256];
        while (serial.leerLinea(buffer, sizeof(buffer))) {
            std::cout << "Linea recibida: " << buffer << std::endl;
            
            TramaBase* trama = parsearLinea(buffer);
            if (trama) {
                procesarTrama(trama);
            }
        }
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