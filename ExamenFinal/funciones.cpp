#include "calculadora.hpp"
#include <iostream>

// Constructor de la clase Calculadora, inicializa resultado en 0
Calculadora::Calculadora() : resultado(0) {}

// Método para sumar dos números
double Calculadora::sumar(double a, double b) {
    // Almacena el resultado de la suma en la variable privada resultado
    resultado = a + b;
    // Retorna el resultado de la suma
    return resultado;
}

// Método para restar dos números
double Calculadora::restar(double a, double b) {
    // Almacena el resultado de la resta en la variable privada resultado
    resultado = a - b;
    // Retorna el resultado de la resta
    return resultado;
}

// Método para multiplicar dos números
double Calculadora::multiplicar(double a, double b) {
    // Almacena el resultado de la multiplicación en la variable privada resultado
    resultado = a * b;
    // Retorna el resultado de la multiplicación
    return resultado;
}

// Método para dividir dos números
double Calculadora::dividir(double a, double b) {
    // Chequea si el divisor es diferente de cero para evitar división por cero
    if (b != 0) {
        // Almacena el resultado de la división en la variable privada resultado
        resultado = a / b;
        // Retorna el resultado de la división
        return resultado;
    } else {
        // Si el divisor es cero, imprime un mensaje de error
        std::cout << "Error: Division por cero.\n";
        return 0;
    }
}
