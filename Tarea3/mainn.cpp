#include <iostream>
#include <limits>
#include <vector>
#include "clases.hpp"
#include "funciones.hpp"

using namespace std;

int main() {
    string archivo = "Empleados.csv";
    vector<Empleado> empleados = leerArchivo(archivo);
    
    string input;
    int opcion;
    do {
        cout << "1. Buscar por departamento" << endl;
        cout << "2. Buscar por rango de salario" << endl;
        cout << "0. Salir del programa" << endl;
        cout << "Ingrese una opcion: ";
        cin >> input;


        if (input.find_first_not_of("0123456789") != string::npos) {
            cout << "Opción inválida, intente de nuevo" << endl;
            continue;
        }
        opcion = stoi(input);

        switch(opcion) {
            case 1: {
                string departamentoBusqueda;
                cout << "Ingrese el departamento a buscar: ";
                cin.ignore();  
                getline(cin, departamentoBusqueda);                

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

    return 0;
}
