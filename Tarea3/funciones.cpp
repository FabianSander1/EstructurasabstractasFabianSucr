#include <fstream>
#include <vector>
#include <regex>
#include <sstream>
#include "clases.hpp"
#include "funciones.hpp"

using namespace std;

/**
 * @brief Función para validar una entrada con un patrón dado.
 * @param entrada La entrada a validar.
 * @param patron El patrón de validación.
 * @return true si la entrada es válida, false en caso contrario.
 */
bool validarEntrada(string entrada, string patron) {
    regex reg(patron);
    return regex_match(entrada, reg);
}

/**
 * @brief Función para leer los datos de empleados desde un archivo.
 * @param nombreArchivo El nombre del archivo que contiene los datos.
 * @return Un vector de objetos Empleado con los empleados leídos.
 */
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

/**
 * @brief Función para buscar empleados por departamento.
 * @param empleados El vector de empleados en el que realizar la búsqueda.
 * @param departamento El departamento a buscar.
 * @return Un vector de empleados que pertenecen al departamento buscado.
 */
vector<Empleado> buscarPorDepartamento(vector<Empleado> empleados, string departamento) {
    vector<Empleado> resultado;

    for (const auto& empleado : empleados) {
        if (empleado.departamento == departamento) {
            resultado.push_back(empleado);
        }
    }

    return resultado;
}

/**
 * @brief Función para buscar empleados por rango de salario.
 * @param empleados El vector de empleados en el que realizar la búsqueda.
 * @param salarioMinimo El salario mínimo del rango.
 * @param salarioMaximo El salario máximo del rango.
 * @return Un vector de empleados cuyos salarios están dentro del rango especificado.
 */
vector<Empleado> buscarPorSalario(vector<Empleado> empleados, double salarioMinimo, double salarioMaximo) {
    vector<Empleado> resultado;

    for (const auto& empleado : empleados) {
        if (empleado.salario >= salarioMinimo && empleado.salario <= salarioMaximo) {
            resultado.push_back(empleado);
        }
    }

    return resultado;
}

