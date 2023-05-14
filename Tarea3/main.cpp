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
