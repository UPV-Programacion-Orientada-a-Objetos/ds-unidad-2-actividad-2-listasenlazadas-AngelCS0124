/**
 * @file TramaBase.h
 * @brief Definición de la clase base abstracta para todas las tramas
 * @class TramaBase
 * @brief Clase base abstracta que define la interfaz para procesar tramas
 */

#ifndef TRAMABASE_H
#define TRAMABASE_H

// Declaraciones forward para evitar dependencias circulares
class ListaDeCarga;
class RotorDeMapeo;

/**
 * @class TramaBase
 * @brief Clase base abstracta para todas las tramas del protocolo PRT-7
 */
class TramaBase {
public:
    /**
     * @brief Procesa la trama usando las estructuras de datos proporcionadas
     * @param carga Puntero a la lista de carga para almacenar datos decodificados
     * @param rotor Puntero al rotor de mapeo para operaciones de cifrado
     */
    virtual void procesar(ListaDeCarga* carga, RotorDeMapeo* rotor) = 0;
    
    /**
     * @brief Destructor virtual para garantizar limpieza adecuada de memoria
     */
    virtual ~TramaBase() {}
};

#endif