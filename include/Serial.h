/**
 * @file Serial.h
 * @brief Utilidades para comunicación serial
 */

#ifndef SERIAL_H
#define SERIAL_H

class Serial {
private:
    void* hSerial;  // Handle del puerto serial
    bool conectado;
    
public:
    Serial(const char* nombrePuerto, int baudRate = 9600);
    ~Serial();
    
    bool leerLinea(char* buffer, int tamano);
    bool escribir(const char* data);
    bool escribirLinea(const char* data);
    bool datosDisponibles();
    void cerrar();
    bool estaConectado() { return conectado; }
};

#endif