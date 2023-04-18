#include <iostream>
#include <vector>
#include <string>
#include "pruebas.hpp"
#include "pruebas.cpp"





/**
 * @brief Función principal del programa.
 * @details Crea un campus universitario y lo imprime en pantalla.
 * @return 0 si el programa finaliza correctamente.
 */

int main() {
    Campus campus("Sede Rodrigo Facio");

    // Finca 1
    /**
     * @brief Se inserta la información dentro de los constructores de finca 1, de cada edificio
     * @param Se inserta el tipo de edificio, el ID, la cantidad de pupitres en la clase y los booleanos.
     */ 

    
    Finca finca1(1);
    Edificio edificio1("Aulas", 1, false, false, true);
    edificio1.agregarAula(Aula(1, 30, true));
    edificio1.agregarAula(Aula(2, 40, false));
    edificio1.agregarAula(Aula(3, 20, false));
    finca1.agregarEdificio(edificio1);

    Edificio edificio2("Aulas", 2, false, false, false);
    edificio2.agregarAula(Aula(4, 30, false));
    edificio2.agregarAula(Aula(5, 20, true));
    finca1.agregarEdificio(edificio2);

    Edificio edificio3("Aulas", 3, false, true, true);
    edificio3.agregarAula(Aula(6, 20, false));
    edificio3.agregarAula(Aula(7, 26, false));
    finca1.agregarEdificio(edificio3);

    Edificio edificio4("Aulas", 4, false, true, true);
    edificio4.agregarAula(Aula(8, 50, false));
    finca1.agregarEdificio(edificio4);

    Edificio edificioParqueo1("Parqueo", 5, true, false, false, 700);
    finca1.agregarEdificio(edificioParqueo1);
    /**
     * @brief Se agrega Finca 1 al Campus
     */
    campus.agregarFinca(finca1);

    // Finca 2
    /**
     * @brief Se inserta la información dentro de los constructores de finca 2, de cada edificio
     * @param . inserta el tipo de edificio, el ID, la cantidad de pupitres en la clase y los booleanos.
     */
    Finca finca2(2);
    Edificio edificio5("Aulas", 6, false, false, false);
    edificio5.agregarAula(Aula(9, 20, true));
    edificio5.agregarAula(Aula(10, 45, false));
    edificio5.agregarAula(Aula(11, 30, false));
    finca2.agregarEdificio(edificio5);

    Edificio edificio6("Aulas", 7, true, true, true);
    edificio6.agregarAula(Aula(12, 35, true));
    edificio6.agregarAula(Aula(13, 40, false));
    finca2.agregarEdificio(edificio6);

    Edificio edificio7("Aulas", 8, false, true, true);
    edificio7.agregarAula(Aula(14, 20, true));
    edificio7.agregarAula(Aula(15, 36, false));
    finca2.agregarEdificio(edificio7);
    /**
     * @brief Se agrega Finca 2 al Campus
     */
    campus.agregarFinca(finca2);

    // Finca 3
    /**
     * @brief Se inserta la información dentro de los constructores de finca 3, de cada edificio
     * @param Se inserta el tipo de edificio, el ID, la cantidad de pupitres en la clase y los booleanos.
     */
    Finca finca3(3);
    Edificio edificio8("Aulas", 9, true, true, true);
    edificio8.agregarAula(Aula(16, 20, false));
    edificio8.agregarAula(Aula(17, 10, false));
    finca3.agregarEdificio(edificio8);

    Edificio edificioParqueo2("Parqueo", 10, true, false, true, 300);
    finca3.agregarEdificio(edificioParqueo2);
    /**
     * @brief Se agrega Finca 3 al Campus
     */
    campus.agregarFinca(finca3);
    /**
     * @brief Se imprime la información de ntro del Campus
     */
    imprimirInfoCampus(campus);

    return 0;
    
}

