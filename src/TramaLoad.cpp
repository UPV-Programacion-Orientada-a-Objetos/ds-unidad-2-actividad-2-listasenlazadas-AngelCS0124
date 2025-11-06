/**
 * @file TramaLoad.cpp
 * @brief Implementación de la clase TramaLoad
 */

#include "TramaLoad.h"
#include "ListaDeCarga.h"
#include "RotorDeMapeo.h"
#include <iostream>

TramaLoad::TramaLoad(char d) : dato(d) {}

void TramaLoad::procesar(ListaDeCarga* carga, RotorDeMapeo* rotor) {
    if (!carga || !rotor) return;
    
    char decodificado = rotor->getMapeo(dato);
    
    std::cout << "Trama recibida: [L," << dato << "] -> Procesando... -> Fragmento '" 
              << dato << "' decodificado como '" << decodificado << "'. ";
    
    carga->insertarAlFinal(decodificado);
    
    std::cout << "Mensaje: ";
    carga->imprimirMensaje();
    std::cout << std::endl;
}