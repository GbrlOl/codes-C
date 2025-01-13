#include <stdio.h>
#include <stdbool.h>

int main()
{
    int entero = 5;           // Se especifica que es un dato de tipo entero
    float decimal = 3.141592; // Se especifica que es un flotante o decimal
    char letra = 'A';         //
    double e = 2.718281828459045;

    printf("Entero: %d\n", entero);
    printf("Decimal: %f\n", decimal);
    printf("Decimal (dos cifras): %.2f\n", decimal);

    printf("Caracter: %c\n", letra);
    printf("Tipo de dato \"Double\": %f\n\n", e);

    // ############################################################################################################
    // ############################################################################################################
    printf("\033[1;32mTipos de datos Booleanos\033[0m\n"); // Para hacer las negritas utilizo el código ANSI

    _Bool esValido = 1;                  // O true si usas <stdbool.h>
    bool esFalso = false;                // Usando stdbool.h
    printf("Es válido: %d\n", esValido); // Imprime 1
    printf("Es falso: %d\n", esFalso);   // Imprime 0

    return 0;
}