#include <vector>
#include <string>
#include "clases.hpp"

using namespace std;

/**
 * @brief Valida la entrada utilizando un patrón.
 * @param entrada La cadena de entrada a validar.
 * @param patron El patrón a utilizar para la validación.
 * @return true si la entrada es válida, false en caso contrario.
 */
bool validarEntrada(string entrada, string patron);

/**
 * @brief Lee un archivo y devuelve un vector de objetos Empleado.
 * @param nombreArchivo El nombre del archivo a leer.
 * @return Un vector de objetos Empleado leídos desde el archivo.
 */
vector<Empleado> leerArchivo(string nombreArchivo);

/**
 * @brief Busca empleados por departamento.
 * @param empleados El vector de empleados en el que realizar la búsqueda.
 * @param departamento El departamento por el que filtrar los empleados.
 * @return Un vector de empleados que pertenecen al departamento especificado.
 */
vector<Empleado> buscarPorDepartamento(vector<Empleado> empleados, string departamento);

/**
 * @brief Busca empleados por rango de salario.
 * @param empleados El vector de empleados en el que realizar la búsqueda.
 * @param salarioMinimo El salario mínimo del rango.
 * @param salarioMaximo El salario máximo del rango.
 * @return Un vector de empleados cuyo salario está dentro del rango especificado.
 */
vector<Empleado> buscarPorSalario(vector<Empleado> empleados, double salarioMinimo, double salarioMaximo);
