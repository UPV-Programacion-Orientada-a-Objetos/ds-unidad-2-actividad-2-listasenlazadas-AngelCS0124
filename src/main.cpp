/**
 * @file main.cpp
 * @brief Programa principal del Decodificador PRT-7
 * @mainpage Decodificador de Protocolo Industrial PRT-7
 * 
 * Este programa decodifica mensajes ocultos transmitidos mediante el protocolo PRT-7,
 * utilizando listas doblemente enlazadas para almacenamiento y listas circulares para mapeo.
 */

#include "Decodificador.h"
#include <iostream>

/**
 * @brief Función principal del programa
 * @return Código de salida del programa
 */
int main() {
    std::cout << "=== DECODIFICADOR PRT-7 ===" << std::endl;
    std::cout << "Sistema de ciberseguridad industrial" << std::endl << std::endl;
    
    Decodificador decodificador;
    
    // Datos de ejemplo del Arduino (simulados)
    const char* tramasEjemplo[] = {
        "L,H",
        "L,O", 
        "L,L",
        "M,2",
        "L,A",
        "L, ",
        "L,W",
        "M,-2",
        "L,O",
        "L,R",
        "L,L",
        "L,D"
    };
    
    int numTramas = sizeof(tramasEjemplo) / sizeof(tramasEjemplo[0]);
    
    // Procesar datos de ejemplo
    decodificador.procesarDatos(tramasEjemplo, numTramas);
    
    // Para usar con puerto serial real, descomentar:
    // decodificador.iniciarComunicacionSerial("COM3");
    
    return 0;
}