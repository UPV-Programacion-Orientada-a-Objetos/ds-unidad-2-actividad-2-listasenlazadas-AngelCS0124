/**
 * @file ListaDeCarga.h
 * @brief Definición de la lista doblemente enlazada para almacenar carga
 * @class ListaDeCarga
 * @brief Lista doblemente enlazada para almacenar caracteres decodificados
 */

#ifndef LISTADECARGA_H
#define LISTADECARGA_H

#include "NodoDoble.h"

/**
 * @class ListaDeCarga
 * @brief Lista doblemente enlazada que almacena el mensaje decodificado
 */
class ListaDeCarga {
    private:
        NodoDoble* cabeza; ///< Puntero al primer nodo de la lista
        NodoDoble* cola;   ///< Puntero al último nodo de la lista

    public:
        /**
         * @brief Constructor que inicializa una lista vacía
         */
        ListaDeCarga();
        
        /**
         * @brief Destructor que libera toda la memoria de la lista
         */
        ~ListaDeCarga();
        
        /**
         * @brief Inserta un carácter al final de la lista
         * @param dato Carácter a insertar
         */
        void insertarAlFinal(char dato);
        
        /**
         * @brief Imprime el mensaje completo almacenado en la lista
         */
        void imprimirMensaje();
        
        /**
         * @brief Obtiene el mensaje completo como una cadena (para testing)
         * @param buffer Buffer donde almacenar el mensaje
         * @param tamaño Tamaño máximo del buffer
         */
        void obtenerMensaje(char* buffer, int tamaño);
};

#endif