#include<iostream>

// Definición de la clase Calculadora
class Calculadora {
    // Miembro privado de la clase
    // No puede ser accedido directamente desde fuera de la clase
    // Solo puede ser modificado por los métodos de la clase
    private:
        double resultado;

    // Miembros públicos de la clase, accesibles desde fuera de la clase
    public:
        // Constructor de la clase Calculadora, inicializa resultado en 0
        Calculadora() : resultado(0) {}

        // Método para sumar dos números
        double sumar(double a, double b) {
            // Almacena el resultado de la suma en la variable privada resultado
            resultado = a + b;
            // Retorna el resultado de la suma
            return resultado;
        }

        // Método para restar dos números
        double restar(double a, double b) {
            // Almacena el resultado de la resta en la variable privada resultado
            resultado = a - b;
            // Retorna el resultado de la resta
            return resultado;
        }

        // Método para multiplicar dos números
        double multiplicar(double a, double b) {
            // Almacena el resultado de la multiplicación en la variable privada resultado
            resultado = a * b;
            // Retorna el resultado de la multiplicación
            return resultado;
        }

        // Método para dividir dos números
        double dividir(double a, double b) {
            // Chequea si el divisor es diferente de cero para evitar división por cero
            if(b != 0) {
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
};

// Función main, punto de entrada del programa
int main() {
    // Crea una instancia de la clase Calculadora
    Calculadora calc;

    // Usa los métodos de la clase para realizar operaciones e imprime los resultados
    std::cout << "Suma: " << calc.sumar(6, 3) << "\n";
    std::cout << "Resta: " << calc.restar(6, 3) << "\n";
    std::cout << "Multiplicacion: " << calc.multiplicar(6, 3) << "\n";
    std::cout << "Division: " << calc.dividir(6, 3) << "\n";

    // Retorna 0 para indicar que el programa terminó correctamente
    return 0;
}
