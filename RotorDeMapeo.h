/**
 * @file RotorDeMapeo.h
 * @brief Definición del rotor de mapeo (lista circular)
 * @class RotorDeMapeo
 * @brief Lista circular doblemente enlazada para operaciones de mapeo
 */

#ifndef ROTORDEMAPEO_H
#define ROTORDEMAPEO_H

#include "NodoCircular.h"

/**
 * @class RotorDeMapeo
 * @brief Lista circular que actúa como disco de cifrado para el protocolo
 */
class RotorDeMapeo {
private:
    NodoCircular* cabeza; ///< Puntero a la posición actual del rotor

public:
    /**
     * @brief Constructor que inicializa el rotor con el alfabeto A-Z
     */
    RotorDeMapeo();
    
    /**
     * @brief Destructor que libera toda la memoria del rotor
     */
    ~RotorDeMapeo();
    
    /**
     * @brief Rota el rotor N posiciones
     * @param n Número de posiciones a rotar (positivo o negativo)
     */
    void rotar(int n);
    
    /**
     * @brief Obtiene el mapeo de un carácter según la rotación actual
     * @param entrada Carácter de entrada a mapear
     * @return Carácter mapeado según la posición del rotor
     */
    char getMapeo(char entrada);
    
    /**
     * @brief Obtiene el carácter actual en la posición cabeza (para debugging)
     * @return Carácter en la posición cabeza
     */
    char getCaracterCabeza();
};

#endif