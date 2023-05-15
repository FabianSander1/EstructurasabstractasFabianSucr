#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <sstream>

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


/*
* Copyright (c) 2023, Fabian Salberto Sander Hangen (@FabianSander1)
*
* Se concede permiso, de forma gratuita, a cualquier persona que obtenga una
* copia de este software y de los archivos de documentación asociados (el "Software"),
* para utilizar el Software sin restricciones, incluyendo, sin limitación,
* los derechos de uso, copia, modificación, fusión, publicación, distribución,
* sublicencia y/o venta de copias del Software, y para permitir que las personas
* a las que se les proporcione el Software hagan lo mismo, con sujeción a las siguientes condiciones:
*
* El aviso de copyright anterior y este aviso de permiso se incluirán en todas
* las copias o partes sustanciales del Software.
*
* EL SOFTWARE SE PROPORCIONA "TAL CUAL", SIN GARANTÍA DE NINGÚN TIPO, EXPRESA O
* IMPLÍCITA, INCLUYENDO, PERO NO LIMITADO A, LAS GARANTÍAS DE COMERCIABILIDAD, 
* APTITUD PARA UN PROPÓSITO PARTICULAR Y NO INFRACCIÓN. EN NINGÚN CASO LOS 
* TITULARES DE LOS DERECHOS DE AUTOR SERÁN RESPONSABLES POR CUALQUIER RECLAMO, 
* DAÑO U OTRA RESPONSABILIDAD, YA SEA EN UNA ACCIÓN CONTRACTUAL, AGRAVIO O 
* CUALQUIER OTRO MOTIVO, DERIVADO DE, DE O EN RELACIÓN CON EL SOFTWARE O EL 
* USO U OTROS NEGOCIOS EN EL SOFTWARE.
*/
