@echo off
echo Compiling project...

if not exist build (
    mkdir build
)

:: Habilitar expansión retardada
setlocal enabledelayedexpansion

:: Incluir main.cpp manualmente
set "files=src/main.cpp"

:: Recorrer todos los .cpp dentro de src/modules/*
for /R src\modules %%f in (*.cpp) do (
    set "files=!files! %%f"
)

:: Compilar
g++ !files! -o build/program.exe

if errorlevel 1 (
    echo Compilation failed
    pause
    exit
)

echo Compilation successful!
echo.
build\program.exe
pause
