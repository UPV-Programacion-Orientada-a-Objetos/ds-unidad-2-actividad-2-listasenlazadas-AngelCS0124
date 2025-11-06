/**
 * @file Decodificador.h
 * @brief Definición del decodificador principal
 * @class Decodificador
 * @brief Clase principal que coordina el proceso de decodificación
 */

#ifndef DECODIFICADOR_H
#define DECODIFICADOR_H

#include "TramaBase.h"
#include "ListaDeCarga.h"
#include "RotorDeMapeo.h"

/**
 * @class Decodificador
 * @brief Clase principal que gestiona todo el proceso de decodificación
 */
class Decodificador {
    private:
        ListaDeCarga listaCarga;  ///< Lista para almacenar datos decodificados
        RotorDeMapeo rotor;       ///< Rotor para operaciones de mapeo
        
        /**
         * @brief Parsea una línea recibida y crea la trama correspondiente
         * @param linea Línea de texto recibida del puerto serial
         * @return Puntero a la trama creada (nullptr si hay error)
         */
        TramaBase* parsearLinea(const char* linea);
        
        /**
         * @brief Procesa una trama individual
         * @param trama Trama a procesar
         */
        void procesarTrama(TramaBase* trama);

    public:
        /**
         * @brief Constructor del decodificador
         */
        Decodificador();
        
        /**
         * @brief Procesa múltiples líneas de datos (para testing)
         * @param lineas Array de líneas a procesar
         * @param numLineas Número de líneas en el array
         */
        void procesarDatos(const char** lineas, int numLineas);
        
        /**
         * @brief Inicia la comunicación serial y procesa datos en tiempo real
         * @param puerto Nombre del puerto serial (ej: "COM3" o "/dev/ttyUSB0")
         */
        void iniciarComunicacionSerial(const char* puerto);
        
        /**
         * @brief Muestra el mensaje decodificado final
         */
        void mostrarMensajeFinal();
};

#endif