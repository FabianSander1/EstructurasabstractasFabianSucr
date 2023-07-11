#include "calculadora.hpp"
#include <iostream>

// Función main, punto de entrada del programa
int main() {
    // Crea una instancia de la clase Calculadora
    Calculadora calc;

    // Usa los métodos de la clase para realizar operaciones e imprime los resultados
    std::cout << "Suma: " << calc.sumar(7, -3) << "\n";
    std::cout << "Resta: " << calc.restar(2, 3) << "\n";
    std::cout << "Multiplicacion: " << calc.multiplicar(-4, 3) << "\n";
    std::cout << "Division: " << calc.dividir(6, 2) << "\n";

    // Retorna 0 para indicar que el programa terminó correctamente
    return 0;
}
