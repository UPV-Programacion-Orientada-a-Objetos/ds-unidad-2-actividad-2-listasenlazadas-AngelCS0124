/**
 * @file TramaLoad.h
 * @brief Definición de la clase TramaLoad para tramas de carga
 * @class TramaLoad
 * @brief Clase derivada que representa tramas de carga (L,X)
 */

#ifndef TRAMALOAD_H
#define TRAMALOAD_H

#include "TramaBase.h"

// Las declaraciones forward ya están en TramaBase.h
// Solo necesitamos incluir los headers en el .cpp

/**
 * @class TramaLoad
 * @brief Representa una trama de carga que contiene un carácter a procesar
 */
class TramaLoad : public TramaBase {
    private:
        char dato; ///< Carácter contenido en la trama

    public:
        /**
         * @brief Constructor que inicializa la trama con un carácter
         * @param d Carácter a almacenar en la trama
         */
        TramaLoad(char d);
        
        /**
         * @brief Procesa la trama de carga decodificando el carácter
         * @param carga Lista donde insertar el carácter decodificado
         * @param rotor Rotor usado para el mapeo del carácter
         */
        void procesar(ListaDeCarga* carga, RotorDeMapeo* rotor) override;
};

#endif