/**
 * @file TramaMap.h
 * @brief Definición de la clase TramaMap para tramas de mapeo
 * @class TramaMap
 * @brief Clase derivada que representa tramas de mapeo (M,N)
 */

#ifndef TRAMAMAP_H
#define TRAMAMAP_H

#include "TramaBase.h"

// Las declaraciones forward ya están en TramaBase.h

/**
 * @class TramaMap
 * @brief Representa una trama de mapeo que contiene un valor de rotación
 */
class TramaMap : public TramaBase {
private:
    int valorRotacion; ///< Valor de rotación para el rotor

public:
    /**
     * @brief Constructor que inicializa la trama con un valor de rotación
     * @param valor Valor de rotación (positivo o negativo)
     */
    TramaMap(int valor);
    
    /**
     * @brief Procesa la trama de mapeo rotando el rotor
     * @param carga No utilizado en esta trama
     * @param rotor Rotor a rotar según el valor especificado
     */
    void procesar(ListaDeCarga* carga, RotorDeMapeo* rotor) override;
};

#endif