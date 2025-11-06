/**
 * @file Serial.cpp
 * @brief Implementación de la comunicación serial para Windows
 */

#include "Serial.h"
#include <iostream>
#include <windows.h>

Serial::Serial(const char* nombrePuerto, int baudRate) : hSerial(nullptr), conectado(false) {
    std::cout << "Conectando a " << nombrePuerto << "..." << std::endl;
    
    // Abrir puerto serial
    hSerial = CreateFileA(
        nombrePuerto,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    
    if (hSerial == INVALID_HANDLE_VALUE) {
        std::cout << "ERROR: No se pudo abrir " << nombrePuerto << std::endl;
        return;
    }
    
    // Configurar parámetros del puerto
    DCB dcbSerialParams = {0};
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    
    if (!GetCommState((HANDLE)hSerial, &dcbSerialParams)) {
        std::cout << "ERROR: No se pudo obtener estado del puerto" << std::endl;
        return;
    }
    
    dcbSerialParams.BaudRate = baudRate;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;
    
    if (!SetCommState((HANDLE)hSerial, &dcbSerialParams)) {
        std::cout << "ERROR: No se pudo configurar puerto" << std::endl;
        return;
    }
    
    // Configurar timeouts
    COMMTIMEOUTS timeouts = {0};
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;
    
    if (!SetCommTimeouts((HANDLE)hSerial, &timeouts)) {
        std::cout << "ERROR: No se pudo configurar timeouts" << std::endl;
        return;
    }
    
    conectado = true;
    std::cout << "Conexion establecida con " << nombrePuerto << " a " << baudRate << " baudios" << std::endl;
}

Serial::~Serial() {
    cerrar();
}

bool Serial::leerLinea(char* buffer, int tamano) {
    if (!conectado || !buffer || tamano <= 0) return false;
    
    DWORD bytesLeidos;
    char temp;
    int pos = 0;
    
    while (pos < tamano - 1) {
        if (!ReadFile((HANDLE)hSerial, &temp, 1, &bytesLeidos, NULL)) {
            return false;
        }
        
        if (bytesLeidos > 0) {
            if (temp == '\n' || temp == '\r') {
                if (pos > 0) {  // Tenemos una línea completa
                    buffer[pos] = '\0';
                    return true;
                }
                // Ignorar CR/LF vacíos
            } else {
                buffer[pos++] = temp;
            }
        } else {
            // Timeout
            if (pos > 0) {
                buffer[pos] = '\0';
                return true;
            }
            return false;
        }
    }
    
    buffer[tamano - 1] = '\0';
    return true;
}

bool Serial::escribir(const char* data) {
    if (!conectado) return false;
    
    DWORD bytesEscritos;
    int len = 0;
    while (data[len] != '\0') len++;
    
    return WriteFile((HANDLE)hSerial, data, len, &bytesEscritos, NULL);
}

bool Serial::escribirLinea(const char* data) {
    if (!conectado) return false;
    
    DWORD bytesEscritos;
    int len = 0;
    while (data[len] != '\0') len++;
    
    // Escribir datos + \r\n
    char* buffer = new char[len + 3];
    strcpy(buffer, data);
    buffer[len] = '\r';
    buffer[len + 1] = '\n';
    buffer[len + 2] = '\0';
    
    bool result = WriteFile((HANDLE)hSerial, buffer, len + 2, &bytesEscritos, NULL);
    delete[] buffer;
    return result;
}

bool Serial::datosDisponibles() {
    if (!conectado) return false;
    
    DWORD errors;
    COMSTAT status;
    if (!ClearCommError((HANDLE)hSerial, &errors, &status)) {
        return false;
    }
    
    return (status.cbInQue > 0);
}

void Serial::cerrar() {
    if (hSerial && hSerial != INVALID_HANDLE_VALUE) {
        CloseHandle((HANDLE)hSerial);
        hSerial = nullptr;
    }
    conectado = false;
    std::cout << "Conexion serial cerrada" << std::endl;
}