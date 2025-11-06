/**
 * @file NodoDoble.h
 * @brief Definición del nodo para listas doblemente enlazadas
 * @class NodoDoble
 * @brief Nodo para listas doblemente enlazadas
 */

#ifndef NODODOBLE_H
#define NODODOBLE_H

/**
 * @class NodoDoble
 * @brief Nodo para listas doblemente enlazadas que almacena un carácter
 */
class NodoDoble {
public:
    char dato;          ///< Carácter almacenado en el nodo
    NodoDoble* anterior; ///< Puntero al nodo anterior
    NodoDoble* siguiente; ///< Puntero al nodo siguiente
    
    /**
     * @brief Constructor que inicializa el nodo con un carácter
     * @param d Carácter a almacenar
     */
    NodoDoble(char d);
};

#endif