#include <iostream>
#include <limits>
#include <vector>
#include "clases.hpp"
#include "funciones.hpp"

using namespace std;

/**
 * @brief Función principal.
 */
int main() {
    string archivo = "Empleados.csv";
    vector<Empleado> empleados = leerArchivo(archivo);

    // Ejemplo de búsqueda por departamento

    string departamentoBusqueda;
    while (true) {
        cout << "Ingrese el departamento a buscar: ";
        cin >> departamentoBusqueda;

        if (departamentoBusqueda != "Ventas" && departamentoBusqueda != "Marketing" && departamentoBusqueda != "Finanzas" &&
            departamentoBusqueda != "RecursosHumanos" && departamentoBusqueda != "IT") {
            cout << "Error: el departamento ingresado no es válido." << endl;
        } else {
            break;
        }
    }

    vector<Empleado> resultadoDepartamento = buscarPorDepartamento(empleados, departamentoBusqueda);

    if (!resultadoDepartamento.empty()) {
        cout << "Empleados encontrados en el departamento " << departamentoBusqueda << ":" << endl;
        for (const auto& empleado : resultadoDepartamento) {
            cout << "Nombre: " << empleado.nombre << endl;
            cout << "Correo: " << empleado.correo << endl;
            cout << "Edad: " << empleado.edad << endl;
            cout << "Departamento: " << empleado.departamento << endl;
            cout << "Salario: " << empleado.salario << endl;
            cout << endl;
        }
    } else {
        cout << "No se encontraron empleados en el departamento " << departamentoBusqueda << endl;
    }

    // Ejemplo de búsqueda por rango de salario
    double salarioMin, salarioMax;
    while (true) {
        cout << "Ingrese el salario minimo: ";
        cin >> salarioMin;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: el salario debe ser un numero valido." << endl;
        } else {
            break;
        }
    }

    while (true) {
        cout << "Ingrese el salario maximo: ";
        cin >> salarioMax;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: el salario debe ser un numero valido." << endl;
        } else {
            break;
        }
    }

    vector<Empleado> resultadoSalario = buscarPorSalario(empleados, salarioMin, salarioMax);

    if (!resultadoSalario.empty()) {
        cout << "Empleados encontrados en el rango desalario $" << salarioMin << " a $" << salarioMax << ":" << endl;
        for (const auto& empleado : resultadoSalario) {
            cout << "Nombre: " << empleado.nombre << endl;
            cout << "Correo: " << empleado.correo << endl;
            cout << "Edad: " << empleado.edad << endl;
            cout << "Departamento: " << empleado.departamento << endl;
            cout << "Salario: " << empleado.salario << endl;
            cout << endl;
        }
    } else {
        cout << "No se encontraron empleados en el rango de salario $" << salarioMin << " a $" << salarioMax << endl;
    }

    return 0;
}
