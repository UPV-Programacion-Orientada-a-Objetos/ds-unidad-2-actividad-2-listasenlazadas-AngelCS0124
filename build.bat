@echo off
setlocal

echo === Construyendo Decodificador PRT-7 ===

REM Limpiar build anterior
if exist build (
    echo Eliminando build anterior...
    rmdir /s /q build
)

echo Creando directorio build...
mkdir build

cd build

echo Configurando con MinGW...
cmake -G "MinGW Makefiles" ..

if %errorlevel% neq 0 (
    echo ERROR en configuración
    exit /b 1
)

echo Compilando proyecto...
cmake --build . --config Release

if %errorlevel% neq 0 (
    echo ERROR en compilación
    exit /b 1
)

echo === BUILD EXITOSO ===
echo Ejecutable: build\DecodificadorPRT7.exe

cd ..