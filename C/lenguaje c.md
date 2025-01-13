# **Clase sobre del lenguaje de programación C**

## **Clase 1: Introducción a C**
### **1.1. ¿Qué es C?**
C es un lenguaje de programación de propósito general, eficiente y poderoso, creado por Dennis Ritchie en 1972. Es la base de muchos lenguajes modernos como C++, Java y Python.

**Características principales:**
- Eficiencia y control a nivel de hardware.
- Portabilidad.
- Ideal para sistemas operativos y aplicaciones de alto rendimiento.

**Escritura de código**

Existen distintos enfoques para escribir código.

---


### **1.2. Estructura básica de un programa en C**
Un programa en C tiene la siguiente estructura:

```c
#include <stdio.h> // Biblioteca estándar de entrada/salida

int main() {
    printf("¡Hola, mundo!\n"); // Imprime un mensaje
    return 0; // Indica que el programa terminó correctamente
}
```

**Explicación:**
- `#include <stdio.h>`: Incluye la biblioteca estándar para funciones como `printf`.
- `int main()`: La función principal del programa. El programa comienza aquí.
- `printf`: Función para imprimir texto.
- `return 0`: Indica que el programa finalizó correctamente.

---

### **1.3. Compilación y ejecución**
1. Escribe tu código en un archivo con extensión `.c`, por ejemplo, `programa.c`.
2. Compílalo con un compilador como `gcc`:
   ```bash
   gcc programa.c -o programa
   ```
3. Ejecuta el programa:
   ```bash
   ./programa
   ```

#### **1.3.1 VSCode**

Para ejecutar código C en VSCode debe previamente instalar el compilador y seleccionar el botón que indica `run or debug` o `ctrl + shift + B`.

---


## **1.4. Tipos de datos en C**

En C, los tipos de datos se dividen en tres categorías principales:
1. **Tipos básicos (primitivos)**
2. **Tipos derivados**
3. **Tipos definidos por el usuario**

### **1. Tipos básicos**
Los tipos básicos son los más utilizados para manejar datos primitivos como números, caracteres y booleanos.

| Tipo     | Tamaño (en bytes, aproximado) | Rango                                                                                  | Descripción                                                                 |
|----------|--------------------------------|---------------------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| `char`   | 1                              | `-128 a 127` o `0 a 255` (depende de la implementación, si es signed o unsigned)      | Almacena un solo carácter o un valor entero pequeño. Tiene un tamaño de 1 byte y solo acepta comilla simple '' y no doble comilla. |
| `int`    | 2 o 4                          | Depende de la arquitectura (generalmente, `-32,768 a 32,767` en 2 bytes)              | Entero con signo por defecto. Tiene un tamaño de 4 bytes (depende de la arquitectura).                                            |
| `float`  | 4                              | `~3.4E-38 a 3.4E+38`                                                                 | Números decimales con precisión simple.                                    |
| `double` | 8                              | `~1.7E-308 a 1.7E+308`                                                               | Números decimales con mayor precisión que `float`.                         |
| `_Bool`  | 1                              | `0` o `1`                                                                             | Tipo booleano (disponible desde C99).                                      |

### **Tipos modificadores**
Puedes usar modificadores para alterar el tamaño o el rango de los tipos básicos:

| Modificador       | Ejemplo           | Descripción                           |
|-------------------|-------------------|---------------------------------------|
| `short`           | `short int`       | Entero más pequeño (generalmente 2 bytes). |
| `long`            | `long int`        | Entero más grande (generalmente 8 bytes). |
| `unsigned`        | `unsigned int`    | Solo valores positivos.               |
| `signed`          | `signed int`      | Por defecto, permite valores positivos y negativos. |

**Ejemplo:**
```c
unsigned int positivo = 300; // Solo números positivos.
short int pequeño = -100;    // Entero pequeño con signo.
long int grande = 100000L;   // Entero grande con sufijo L.
```

---

### **2. Tipos derivados**
C incluye tipos basados en los básicos:
1. **Arreglos**: Secuencias de elementos del mismo tipo (`int arr[10];`).
2. **Punteros**: Almacenan direcciones de memoria (`int *ptr;`).
3. **Estructuras**: Colección de tipos heterogéneos (`struct`).
4. **Uniones**: Parecido a estructuras, pero comparten memoria.

---

### **3. Tipos definidos por el usuario**
1. **Enumeraciones (`enum`)**: Tipo especial para definir valores constantes.
   ```c
   enum dias {Lunes, Martes, Miercoles};
   ```
2. **Typedef**: Crea alias para tipos existentes.
   ```c
   typedef unsigned int uint;
   uint numero = 10;
   ```

---

## **Detalles adicionales sobre los tipos básicos**

### **Caracteres (`char`)**
- Un `char` almacena **un solo carácter**.
- Los valores deben estar entre **comillas simples** (`'A'`), no dobles (`"A"` es un `string`).
- Internamente, se representa como un entero en la tabla ASCII.

**Ejemplo:**
```c
#include <stdio.h>
int main() {
    char letra = 'A';  // Correcto
    // char letraInvalida = "A"; // Incorrecto: esto sería un string.
    printf("Carácter: %c, Código ASCII: %d\n", letra, letra);
    return 0;
}
```

---

### **Strings (Cadenas de caracteres)**
C no tiene un tipo de dato específico para strings como otros lenguajes. Los strings se representan como **arreglos de caracteres terminados en un carácter nulo (`\0`)**.

**Ejemplo:**
```c
#include <stdio.h>
int main() {
    char nombre[] = "Juan";  // String terminado en '\0'.
    printf("Nombre: %s\n", nombre);
    return 0;
}
```

**Importante:**
- Los strings usan **dobles comillas** (`"Texto"`), mientras que los caracteres individuales usan **comillas simples** (`'A'`).
- El carácter nulo (`\0`) indica el final del string.

---

### **Booleanos (`_Bool`)**
En C99, se introduce el tipo `_Bool` para representar valores booleanos. Adicionalmente, la biblioteca `<stdbool.h>` define macros (`true` y `false`).

**Ejemplo:**
```c
#include <stdbool.h>
int main() {
    _Bool esCierto = 1;     // Booleano con 1 (true).
    bool esFalso = false;   // Booleano usando <stdbool.h>.
    printf("Es cierto: %d, Es falso: %d\n", esCierto, esFalso);
    return 0;
}
```

---

### **Detalles avanzados**
1. **`void`**: Indica "sin tipo". Se usa principalmente en funciones que no devuelven valor.
   ```c
   void imprimirMensaje() {
       printf("Hola, mundo.\n");
   }
   ```
2. **Rango de los enteros**: Usa `<limits.h>` para obtener el rango exacto.
   ```c
   #include <limits.h>
   printf("Rango de int: %d a %d\n", INT_MIN, INT_MAX);
   ```
3. **Precisión de decimales**: Usa `<float.h>` para obtener la precisión de `float` y `double`.
   ```c
   #include <float.h>
   printf("Máximo de float: %e\n", FLT_MAX);
   ```

---

## **Ejercicio práctico**
1. Crea un programa que:
   - Solicite al usuario un carácter y lo imprima como carácter y como código ASCII.
   - Solicite un string y lo imprima.
   - Solicite un número flotante y lo imprima con 2 y 4 decimales.

**Ejemplo de entrada/salida:**
```
Introduce un carácter: A
Carácter: A, Código ASCII: 65

Introduce un string: Hola
String: Hola

Introduce un número flotante: 3.14159
Número con 2 decimales: 3.14
Número con 4 decimales: 3.1416
```






### **1.4. Variables y tipos de datos**
En C, debes declarar el tipo de dato antes de usar una variable.

**Tipos básicos:**
- `int`: Enteros.
- `float`: Números decimales (precisión simple).
- `double`: Números decimales (mayor precisión).
- `char`: Caracteres.

```c
#include <stdio.h>

int main() {
    int entero = 5;
    float decimal = 3.14;
    char letra = 'A';

    printf("Entero: %d\n", entero);
    printf("Decimal: %.2f\n", decimal);
    printf("Letra: %c\n", letra);

    return 0;
}
```

---

### **Ejercicio 1: Hola, usuario**
Escribe un programa que:
1. Solicite al usuario su nombre.
2. Imprima un saludo personalizado.

**Ejemplo de salida:**
```
¿Cuál es tu nombre? Juan
¡Hola, Juan!
```

---

## **Clase 2: Control de flujo**
### **2.1. Estructuras condicionales**
- **`if`**: Evalúa una condición.
- **`else`**: Bloque alternativo si la condición es falsa.
- **`else if`**: Agrega condiciones adicionales.

```c
#include <stdio.h>

int main() {
    int edad;
    printf("Introduce tu edad: ");
    scanf("%d", &edad);

    if (edad >= 18) {
        printf("Eres mayor de edad.\n");
    } else {
        printf("Eres menor de edad.\n");
    }

    return 0;
}
```

---

### **2.2. Bucles**
- **`for`**: Repite un bloque un número fijo de veces.
- **`while`**: Repite mientras una condición sea verdadera.
- **`do-while`**: Similar a `while`, pero se ejecuta al menos una vez.

```c
#include <stdio.h>

int main() {
    int i;

    printf("Ciclo for:\n");
    for (i = 0; i < 5; i++) {
        printf("Iteración %d\n", i);
    }

    return 0;
}
```

---

### **Ejercicio 2: Números pares**
Escribe un programa que imprima los números pares del 1 al 20 utilizando un bucle `for`.

---

## **Clase 3: Funciones**
### **3.1. Declarar y definir funciones**
Las funciones son bloques de código reutilizables.

```c
#include <stdio.h>

// Declaración
int suma(int a, int b);

int main() {
    int resultado = suma(3, 4);
    printf("La suma es: %d\n", resultado);
    return 0;
}

// Definición
int suma(int a, int b) {
    return a + b;
}
```

---

### **3.2. Paso por valor y por referencia**
Por defecto, C pasa argumentos por valor. Para modificar el valor original, usa punteros.

```c
#include <stdio.h>

void incrementar(int *num) {
    (*num)++;
}

int main() {
    int numero = 10;
    incrementar(&numero);
    printf("El número incrementado es: %d\n", numero);
    return 0;
}
```

---

### **Ejercicio 3: Factorial**
Escribe una función que calcule el factorial de un número usando un bucle.

**Ejemplo:**
```
Factorial de 5: 120
```

---

## **Clase 4: Memoria dinámica**
### **4.1. Uso de `malloc` y `free`**
C permite gestionar la memoria manualmente.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int)); // Reserva memoria
    if (ptr == NULL) {
        printf("Error de memoria.\n");
        return 1;
    }

    *ptr = 42;
    printf("Valor: %d\n", *ptr);

    free(ptr); // Libera la memoria
    return 0;
}
```

---

### **Ejercicio 4: Arreglo dinámico**
Crea un programa que:
1. Solicite al usuario el tamaño de un arreglo.
2. Reserve memoria dinámicamente para el arreglo.
3. Permita llenar el arreglo y mostrar los valores ingresados.

---

## **Clase 5: Archivos**
### **5.1. Leer y escribir en archivos**
```c
#include <stdio.h>

int main() {
    FILE *archivo = fopen("datos.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    fprintf(archivo, "Hola, archivo.\n");
    fclose(archivo);
    return 0;
}
```

---

### **Ejercicio 5: Notas de estudiantes**
Escribe un programa que:
1. Solicite los nombres y notas de 5 estudiantes.
2. Guarde los datos en un archivo.
3. Lea el archivo y muestre la información.

---
