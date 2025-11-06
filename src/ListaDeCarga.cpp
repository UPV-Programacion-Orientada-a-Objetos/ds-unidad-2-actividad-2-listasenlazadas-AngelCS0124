/**
 * @file ListaDeCarga.cpp
 * @brief Implementación de la lista de carga
 */

#include "ListaDeCarga.h"
#include "NodoDoble.h"
#include <iostream>

ListaDeCarga::ListaDeCarga() : cabeza(nullptr), cola(nullptr) {}

ListaDeCarga::~ListaDeCarga() {
    NodoDoble* actual = cabeza;
    while (actual) {
        NodoDoble* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}

void ListaDeCarga::insertarAlFinal(char dato) {
    NodoDoble* nuevoNodo = new NodoDoble(dato);
    
    if (!cabeza) {
        cabeza = cola = nuevoNodo;
    } else {
        cola->siguiente = nuevoNodo;
        nuevoNodo->anterior = cola;
        cola = nuevoNodo;
    }
}

void ListaDeCarga::imprimirMensaje() {
    NodoDoble* actual = cabeza;
    std::cout << "[";
    while (actual) {
        std::cout << actual->dato;
        if (actual->siguiente) {
            std::cout << "][";
        }
        actual = actual->siguiente;
    }
    std::cout << "]";
}

void ListaDeCarga::obtenerMensaje(char* buffer, int tamaño) {
    if (!buffer || tamaño <= 0) return;
    
    NodoDoble* actual = cabeza;
    int pos = 0;
    
    while (actual && pos < tamaño - 1) {
        buffer[pos++] = actual->dato;
        actual = actual->siguiente;
    }
    buffer[pos] = '\0';
}