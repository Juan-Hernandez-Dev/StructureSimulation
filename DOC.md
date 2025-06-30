# Structure Simulation - Documentación del Proyecto

## Tabla de Contenidos
1. [Descripción General](#descripción-general)
2. [Estructura del Proyecto](#estructura-del-proyecto)
3. [Estructuras de Datos Implementadas](#estructuras-de-datos-implementadas)
   - [Pila (Stack)](#pila-stack)
   - [Cola (Queue)](#queue)
   - [Lista Enlazada (Linked List)](#lista-enlazada-linked-list)
   - [Lista Doblemente Enlazada (Doubly Linked List)](#lista-doblemente-enlazada-doubly-linked-list)
   - [Lista Circular Enlazada (Circular Linked List)](#lista-circular-enlazada-circular-linked-list)
   - [Árbol Binario (Binary Tree)](#árbol-binario-binary-tree)
4. [Funciones de Utilidad](#funciones-de-utilidad)
5. [Compilación y Ejecución](#compilación-y-ejecución)
6. [Uso del Programa](#uso-del-programa)
7. [Ejemplos de Uso](#ejemplos-de-uso)
8. [Dependencias](#dependencias)
9. [Documentación Adicional](#documentación-adicional)

## Descripción General

Structure Simulation es un programa en C++ que implementa varias estructuras de datos fundamentales en informática. El proyecto está diseñado para fines educativos, permitiendo a los usuarios interactuar con diferentes estructuras de datos a través de un menú de consola intuitivo.

## Estructura del Proyecto

```
StructureSimulation/
├── build/                 # Archivos de compilación
├── docs/                  # Documentación generada
├── include/               # Archivos de encabezado
│   └── utils.h            # Utilidades y definiciones
├── src/                   # Código fuente principal
│   ├── main.cpp           # Punto de entrada del programa
│   └── modules/           # Módulos de estructuras de datos
│       ├── stack/         # Implementación de Pila
│       ├── queue/         # Implementación de Cola
│       ├── linked_list/   # Lista Enlazada Simple
│       ├── doubly_linked_list/ # Lista Doblemente Enlazada
│       ├── circular_linked_list/ # Lista Circular Enlazada
│       └── binary_tree/   # Árbol Binario
├── Doxyfile              # Configuración de Doxygen
└── README.md             # Documentación básica
```

## Estructuras de Datos Implementadas

### Pila (Stack)

Una estructura de datos LIFO (Last In, First Out) que permite operaciones de inserción (push) y eliminación (pop) solo en un extremo (tope).

**Operaciones principales:**
- `push(int x)`: Añade un elemento a la pila
- `pop()`: Elimina y devuelve el elemento en el tope
- `peek()`: Devuelve el elemento en el tope sin eliminarlo
- `isEmpty()`: Verifica si la pila está vacía
- `size()`: Devuelve el número de elementos
- `clear()`: Vacía la pila

### Cola (Queue)

Estructura de datos FIFO (First In, First Out) que permite la inserción por un extremo y la eliminación por el otro.

**Operaciones principales:**
- `enqueue(int x)`: Añade un elemento al final de la cola
- `dequeue()`: Elimina y devuelve el elemento al frente
- `front()`: Devuelve el elemento al frente sin eliminarlo
- `isEmpty()`: Verifica si la cola está vacía
- `size()`: Devuelve el número de elementos

### Lista Enlazada (Linked List)

Estructura de datos lineal donde cada elemento (nodo) contiene un valor y un puntero al siguiente nodo.

**Operaciones principales:**
- `insertAtBeginning(int x)`: Inserta al inicio
- `insertAtEnd(int x)`: Inserta al final
- `insertAtPosition(int x, int pos)`: Inserta en posición específica
- `deleteNode(int x)`: Elimina un nodo por valor
- `search(int x)`: Busca un valor
- `display()`: Muestra la lista

### Lista Doblemente Enlazada (Doubly Linked List)

Similar a la lista enlazada simple, pero cada nodo tiene punteros al nodo anterior y siguiente.

**Características adicionales:**
- Permite recorrido en ambas direcciones
- Inserción/eliminación más eficiente en ciertos casos

### Lista Circular Enlazada (Circular Linked List)

Lista enlazada donde el último nodo apunta de nuevo al primer nodo.

**Características:**
- Útil para aplicaciones circulares
- No tiene un final definido

### Árbol Binario (Binary Tree)

Estructura de datos jerárquica donde cada nodo tiene como máximo dos hijos (izquierdo y derecho).

**Operaciones principales:**
- `insert(int x)`: Inserta un valor
- `search(int x)`: Busca un valor
- `inOrder()`, `preOrder()`, `postOrder()`: Recorridos
- `height()`: Altura del árbol
- `countNodes()`: Número de nodos

## Funciones de Utilidad

El archivo `utils.h` proporciona funciones auxiliares:

- `cls()`: Limpia la pantalla de la consola
- `clearBuffer()`: Limpia el búfer de entrada
- Definiciones de colores para la salida en consola:
  - `RESET`, `BOLD`, `RED`, `GREEN`, `YELLOW`, `BLUE`, `MAGENTA`, `CYAN`, `WHITE`

## Compilación y Ejecución

### Requisitos
- Compilador C++ compatible con C++11 o superior
- CMake (opcional, para compilación automatizada)

### Compilación Manual

```bash
g++ -std=c++11 -Iinclude src/main.cpp src/modules/stack/stack.cpp src/modules/queue/queue.cpp src/modules/linked_list/linked_list.cpp src/modules/doubly_linked_list/doubly_linked_list.cpp src/modules/circular_linked_list/circular_linked_list.cpp src/modules/binary_tree/binary_tree.cpp -o structure_simulator
```

### Ejecución

```bash
./structure_simulator
```

## Uso del Programa

1. Al ejecutar el programa, se mostrará un menú principal con las estructuras de datos disponibles.
2. Seleccione una opción ingresando el número correspondiente.
3. Cada estructura de datos tiene su propio submenú con operaciones específicas.
4. Siga las instrucciones en pantalla para realizar operaciones.
5. Puede volver al menú principal o salir del programa según las opciones proporcionadas.

## Ejemplos de Uso

### Ejemplo con Pila (Stack)

1. Seleccione la opción 1 (Stack) en el menú principal.
2. Elija la operación deseada (push, pop, peek, etc.).
3. Siga las indicaciones para ingresar valores.
4. Use la opción de visualización para ver el estado actual de la pila.

### Ejemplo con Árbol Binario

1. Seleccione la opción 6 (Binary Tree) en el menú principal.
2. Inserte varios valores para construir el árbol.
3. Explore las diferentes formas de recorrido (in-order, pre-order, post-order).
4. Busque valores existentes o calcule la altura del árbol.

## Dependencias

- **Sistema Operativo**: Cualquier sistema con soporte para C++11
- **Bibliotecas**: Solo la biblioteca estándar de C++
- **Herramientas de Desarrollo**: Compilador C++ (g++, clang, etc.)

## Documentación Adicional

Para generar documentación detallada del código:

1. Asegúrese de tener Doxygen instalado.
2. Ejecute el siguiente comando en la raíz del proyecto:

```bash
doxygen Doxyfile
```

La documentación se generará en el directorio `docs/html/`. Abra `index.html` en un navegador para verla.
