cmake_minimum_required(VERSION 3.10)
project(DecodificadorPRT7 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# En Windows, linkear con librerías necesarias
if(WIN32)
    set(WIN32_LIBS kernel32 user32 gdi32 winspool comdlg32 advapi32 shell32 ole32 oleaut32 uuid odbc32 odbccp32)
endif()

include_directories(include)

set(SOURCES
    src/main.cpp
    src/Decodificador.cpp
    src/ListaDeCarga.cpp
    src/NodoCircular.cpp
    src/NodoDoble.cpp
    src/RotorDeMapeo.cpp
    src/Serial.cpp
    src/TramaLoad.cpp
    src/TramaMap.cpp
)

add_executable(DecodificadorPRT7 ${SOURCES})

# En Windows, agregar las librerías
if(WIN32)
    target_link_libraries(DecodificadorPRT7 ${WIN32_LIBS})
endif()