#ifndef CALCULADORA_HPP
#define CALCULADORA_HPP

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
        Calculadora();

        // Método para sumar dos números
        double sumar(double a, double b);

        // Método para restar dos números
        double restar(double a, double b);

        // Método para multiplicar dos números
        double multiplicar(double a, double b);

        // Método para dividir dos números
        double dividir(double a, double b);
};

#endif  // CALCULADORA_HPP
