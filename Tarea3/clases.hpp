#ifndef CLASES_HPP
#define CLASES_HPP

#include <string>

using namespace std;

/**
 * @class Empleado
 * @brief Clase que representa a un empleado.
 */
class Empleado {
public:
    string nombre;          ///< Nombre del empleado.
    string correo;          ///< Correo electrónico del empleado.
    int edad;               ///< Edad del empleado.
    string departamento;    ///< Departamento del empleado.
    double salario;         ///< Salario del empleado.
};

#endif // CLASES_HPP
