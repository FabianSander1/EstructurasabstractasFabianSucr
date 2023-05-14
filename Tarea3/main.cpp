#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <sstream>

using namespace std;

class Empleado {
public:
    string nombre;
    string correo;
    int edad;
    string departamento;
    double salario;
};

bool validarEntrada(string entrada, string patron) {
    regex reg(patron);
    return regex_match(entrada, reg);
}

vector<Empleado> leerArchivo(string nombreArchivo) {
    vector<Empleado> empleados;
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        getline(archivo, linea); // Leer la primera línea (encabezado) y descartarla

        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string nombre, correo, departamento;
            int edad;
            double salario;

            getline(ss, nombre, ',');
            getline(ss, correo, ',');
            ss >> edad;
            ss.ignore();
            getline(ss, departamento, ',');
            ss >> salario;

            Empleado empleado;
            empleado.nombre = nombre;
            empleado.correo = correo;
            empleado.edad = edad;
            empleado.departamento = departamento;
            empleado.salario = salario;

            empleados.push_back(empleado);
        }

        archivo.close();
    }

    return empleados;
}

vector<Empleado> buscarPorDepartamento(vector<Empleado> empleados, string departamento) {
    vector<Empleado> resultado;

    for (const auto& empleado : empleados) {
        if (empleado.departamento == departamento) {
            resultado.push_back(empleado);
        }
    }

    return resultado;
}

vector<Empleado> buscarPorSalario(vector<Empleado> empleados, double salarioMinimo, double salarioMaximo) {
    vector<Empleado> resultado;

    for (const auto& empleado : empleados) {
        if (empleado.salario >= salarioMinimo && empleado.salario <= salarioMaximo) {
            resultado.push_back(empleado);
        }
    }

    return resultado;
}

int main() {
    string archivo = "Empleados.txt";
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
            cout << "Error: el salario debe ser un número válido." << endl;
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
            cout << "Error: el salario debe ser un número válido." << endl;
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
