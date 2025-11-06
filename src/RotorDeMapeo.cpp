/**
 * @file RotorDeMapeo.cpp
 * @brief Implementación del rotor de mapeo
 */

#include "../include/RotorDeMapeo.h"
#include "../include/NodoCircular.h"
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
    if (!cabeza || entrada < 'A' || entrada > 'Z') {
        return entrada;
    }
    
    // Encontrar la posición del carácter de entrada relativo a 'A'
    int posicionEntrada = entrada - 'A';
    
    // Aplicar rotación: el carácter mapeado está desplazado
    // por la posición actual de la cabeza
    NodoCircular* mapeado = cabeza;
    for (int i = 0; i < posicionEntrada; i++) {
        mapeado = mapeado->siguiente;
    }
    
    return mapeado->dato;
}

char RotorDeMapeo::getCaracterCabeza() {
    return cabeza ? cabeza->dato : '?';
}