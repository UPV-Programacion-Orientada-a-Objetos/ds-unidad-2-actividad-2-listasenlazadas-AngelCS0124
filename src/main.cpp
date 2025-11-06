/**
 * @file main.cpp
 * @brief Programa principal del Decodificador PRT-7
 * @mainpage Decodificador de Protocolo Industrial PRT-7
 * 
 * Este programa decodifica mensajes ocultos transmitidos mediante el protocolo PRT-7,
 * utilizando listas doblemente enlazadas para almacenamiento y listas circulares para mapeo.
 */

#include "../include/Decodificador.h"
#include <iostream>

/**
 * @brief Función principal del programa
 * @return Código de salida del programa
 */
int main() {
    std::cout << "=== DECODIFICADOR PRT-7 ===" << std::endl;
    
    Decodificador decodificador;

    decodificador.iniciarComunicacionSerial("COM6");
    
    return 0;
}