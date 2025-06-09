@echo off
setlocal

:: Create build directory if it doesn't exist
if not exist build (
    mkdir build
)

:: Compile sources
g++ -c src\cli\menu.cpp -o build\menu.o
g++ -c src\backend\sum\sum.cpp -o build\sum.o
g++ -c src\main.cpp -o build\main.o

:: Link object files
g++ build\main.o build\menu.o build\sum.o -o build\app.exe

:: Check if compilation succeeded
if %errorlevel% neq 0 (
    echo Compilation failed.
    pause
    exit /b
)

:: Run the program
echo Running...
build\app.exe

endlocal
pause
