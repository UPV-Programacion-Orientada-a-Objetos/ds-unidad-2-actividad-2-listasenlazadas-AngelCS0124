/**
 * @file Serial.h
 * @brief Utilidades para comunicación serial
 * @class Serial
 * @brief Maneja la comunicación con el puerto serial
 */

#ifndef SERIAL_H
#define SERIAL_H

/**
 * @class Serial
 * @brief Clase para manejar la comunicación serial (simulada para ESP32)
 */
class Serial {
private:
    int puerto; ///< Descriptor del puerto serial
    
public:
    /**
     * @brief Constructor que inicializa la comunicación serial
     * @param nombrePuerto Nombre del puerto serial
     * @param baudRate Velocidad en baudios (por defecto 9600)
     */
    Serial(const char* nombrePuerto, int baudRate = 9600);
    
    /**
     * @brief Destructor que cierra la conexión serial
     */
    ~Serial();
    
    /**
     * @brief Lee una línea del puerto serial
     * @param buffer Buffer donde almacenar la línea leída
     * @param tamaño Tamaño máximo del buffer
     * @return true si se leyó una línea, false en caso de error
     */
    bool leerLinea(char* buffer, int tamaño);
    
    /**
     * @brief Verifica si hay datos disponibles para leer
     * @return true si hay datos disponibles
     */
    bool datosDisponibles();
    
    /**
     * @brief Cierra la conexión serial
     */
    void cerrar();
};

#endif