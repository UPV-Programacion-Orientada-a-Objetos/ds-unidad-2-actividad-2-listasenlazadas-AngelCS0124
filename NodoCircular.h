/**
 * @file NodoCircular.h
 * @brief Definición del nodo para listas circulares
 * @class NodoCircular
 * @brief Nodo para listas circulares doblemente enlazadas
 */

#ifndef NODOCIRCULAR_H
#define NODOCIRCULAR_H

/**
 * @class NodoCircular
 * @brief Nodo para listas circulares que almacena un carácter
 */
class NodoCircular {
public:
    char dato;            ///< Carácter almacenado en el nodo
    NodoCircular* anterior; ///< Puntero al nodo anterior
    NodoCircular* siguiente; ///< Puntero al nodo siguiente
    
    /**
     * @brief Constructor que inicializa el nodo con un carácter
     * @param d Carácter a almacenar
     */
    NodoCircular(char d);
};

#endif