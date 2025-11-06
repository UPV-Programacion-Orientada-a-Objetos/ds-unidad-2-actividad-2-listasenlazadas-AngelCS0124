#ifndef DECODIFICADOR_H
#define DECODIFICADOR_H

#include "TramaBase.h"
#include "ListaDeCarga.h"
#include "RotorDeMapeo.h"

class Decodificador {
    private:
        ListaDeCarga listaCarga;
        RotorDeMapeo rotor; 

        TramaBase* parsearLinea(const char* linea);
        
        void procesarTrama(TramaBase* trama);

    public:
        Decodificador();
        
        void procesarDatos(const char** lineas, int numLineas);

        void iniciarComunicacionSerial(const char* puerto);

        void mostrarMensajeFinal();
};

#endif