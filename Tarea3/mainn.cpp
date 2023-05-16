/// @file
/// @brief Implementación de un programa para buscar empleados

#include <iostream>
#include <limits>
#include <vector>
#include "clases.hpp"
#include "funciones.hpp"

using namespace std;

/**
 * @brief Punto de entrada al programa
 *
 * Este programa permite buscar empleados por departamento o rango de salario.
 *
 * @return 0 al finalizar correctamente.
 */
int main() {
    /// Archivo de datos de los empleados
    string archivo = "Empleados.csv";

    /// Lista de empleados
    vector<Empleado> empleados = leerArchivo(archivo);
    
    /// Opción seleccionada por el usuario
    string input;
    int opcion;
    
    do {
        cout << "1. Buscar por departamento" << endl;
        cout << "2. Buscar por rango de salario" << endl;
        cout << "0. Salir del programa" << endl;
        cout << "Ingrese una opcion: ";
        cin >> input;

        /// Comprobar si la entrada es válida
        if (input.find_first_not_of("0123456789") != string::npos) {
            cout << "Opción inválida, intente de nuevo" << endl;
            continue;
        }
        opcion = stoi(input);

        switch(opcion) {
            case 1: {
                /// Nombre del departamento a buscar
                string departamentoBusqueda;
                cout << "Ingrese el departamento a buscar: ";
                cin.ignore();  
                getline(cin, departamentoBusqueda);                

                /// Resultados de la búsqueda por departamento
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
                break;
            }
            case 2: {
                /// Salario mínimo y máximo a buscar
                double salarioMin, salarioMax;
                
                /// Solicitar y validar el salario mínimo
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

                /// Solicitar y validar el salario máximo
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

                /// Resultados de la búsqueda por rango de salario
                vector<Empleado> resultadoSalario = buscarPorSalario(empleados, salarioMin, salarioMax);

                /// @brief Continuación del case 2
                if (!resultadoSalario.empty()) {
                    cout << "Empleados encontrados en el rango de salario $" << salarioMin << " a $" << salarioMax << ":" << endl;
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
                break;
            }
            case 0: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default: {
                cout << "Opción inválida, intente de nuevo" << endl;
                break;
            }
        }
    } while(opcion != 0);

    /// @return La función main siempre debe retornar un valor. En este caso, se retorna 0 para indicar que el programa ha finalizado correctamente.
    return 0;
}


