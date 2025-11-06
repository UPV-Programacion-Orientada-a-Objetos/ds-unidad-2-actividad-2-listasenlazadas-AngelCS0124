/**
 * @file RotorDeMapeo.cpp
 * @brief Implementación del rotor de mapeo
 */

#include "RotorDeMapeo.h"
#include "NodoCircular.h"
#include <iostream>

RotorDeMapeo::RotorDeMapeo() : cabeza(nullptr) {
    // Crear alfabeto A-Z
    for (char c = 'A'; c <= 'Z'; c++) {
        NodoCircular* nuevoNodo = new NodoCircular(c);
        
        if (!cabeza) {
            cabeza = nuevoNodo;
            cabeza->anterior = cabeza;
            cabeza->siguiente = cabeza;
        } else {
            NodoCircular* ultimo = cabeza->anterior;
            ultimo->siguiente = nuevoNodo;
            nuevoNodo->anterior = ultimo;
            nuevoNodo->siguiente = cabeza;
            cabeza->anterior = nuevoNodo;
        }
    }
}

RotorDeMapeo::~RotorDeMapeo() {
    if (!cabeza) return;
    
    NodoCircular* actual = cabeza;
    NodoCircular* inicio = cabeza;
    
    do {
        NodoCircular* temp = actual;
        actual = actual->siguiente;
        delete temp;
    } while (actual != inicio);
}

void RotorDeMapeo::rotar(int n) {
    if (!cabeza) return;
    
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            cabeza = cabeza->siguiente;
        }
    } else if (n < 0) {
        for (int i = 0; i < -n; i++) {
            cabeza = cabeza->anterior;
        }
    }
}

char RotorDeMapeo::getMapeo(char entrada) {
    if (!cabeza) return entrada;
    
    // Caracteres que no son letras se devuelven sin cambios
    if (entrada < 'A' || entrada > 'Z') {
        return entrada;
    }
    
    // Encontrar la posición del carácter de entrada relativa a la cabeza
    NodoCircular* actual = cabeza;
    int posicion = 0;
    
    do {
        if (actual->dato == entrada) {
            break;
        }
        actual = actual->siguiente;
        posicion++;
    } while (actual != cabeza);
    
    // El carácter mapeado es el que está en la posición 'cabeza' 
    // si el carácter de entrada estuviera en esa posición
    NodoCircular* mapeado = cabeza;
    for (int i = 0; i < posicion; i++) {
        mapeado = mapeado->siguiente;
    }
    
    return mapeado->dato;
}

char RotorDeMapeo::getCaracterCabeza() {
    return cabeza ? cabeza->dato : '?';
}