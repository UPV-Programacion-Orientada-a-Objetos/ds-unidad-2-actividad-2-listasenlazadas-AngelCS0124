/**
 * @file TramaMap.cpp
 * @brief Implementación de la clase TramaMap
 */

#include "TramaMap.h"
#include "RotorDeMapeo.h"
#include <iostream>

TramaMap::TramaMap(int valor) : valorRotacion(valor) {}

void TramaMap::procesar(ListaDeCarga* carga, RotorDeMapeo* rotor) {
    if (!rotor) return;
    
    char cabezaAntes = rotor->getCaracterCabeza();
    rotor->rotar(valorRotacion);
    char cabezaDespues = rotor->getCaracterCabeza();
    
    std::cout << "Trama recibida: [M," << valorRotacion << "] -> Procesando... -> ROTANDO ROTOR " 
              << (valorRotacion > 0 ? "+" : "") << valorRotacion << ". ";
    std::cout << "(Antes '" << cabezaAntes << "' se mapeaba a '" << cabezaAntes 
              << "', ahora a '" << cabezaDespues << "')" << std::endl;
}