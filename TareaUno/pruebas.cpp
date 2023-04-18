#include <iostream>
#include <vector>
#include <string>
#include "pruebas.hpp"

/**
 * @brief Imprime información sobre un campus.
 * @param campus El campus del cual se imprimirá la información
*/

/**
 * @brief Imprime información sobre un campus.
 * @param campus El campus del cual se imprimirá la información.
 */
void imprimirInfoCampus(const Campus& campus) {
    std::cout << "Campus: " << campus.nombre << std::endl;

    for (const Finca& finca : campus.fincas) {
        std::cout << "Finca " << finca.id << std::endl;

        int edificiosAulas = 0;
        int edificiosParqueo = 0;
        for (const Edificio& edificio : finca.edificios) {
            if (edificio.tipo == "Aulas") {
                edificiosAulas++;
            } else if (edificio.tipo == "Parqueo") {
                edificiosParqueo++;
            }
        }

        std::cout << "En la finca " << finca.id << " hay " << edificiosAulas << " edificios de aulas y " << edificiosParqueo << " de parqueos." << std::endl;

        std::cout << "El bus pasa por los edificios:";
        for (const Edificio& edificio : finca.edificios) {
            if (edificio.bus) {
                std::cout << " " << edificio.id;
            }
        }
        std::cout << "." << std::endl;

        for (const Edificio& edificio : finca.edificios) {
            std::cout << "El edificio " << edificio.id << " tiene " << edificio.aulas.size() << " aulas";
            if (edificio.tipo == "Parqueo") {
                std::cout << " y " << edificio.parqueos << " espacios de parqueo";
            }
            std::cout << "." << std::endl;

            for (const Aula& aula : edificio.aulas) {
                std::cout << "El aula " << aula.id << " tiene " << aula.pupitres << " pupitres";
                if (aula.proyector) {
                    std::cout << " y un proyector";
                }
                std::cout << "." << std::endl;
            }

            if (edificio.ascensor) {
                std::cout << "El edificio " << edificio.id << " tiene un ascensor." << std::endl;
            }

            if (edificio.soda) {
                std::cout << "El edificio " << edificio.id << " tiene una soda." << std::endl;
            }
        }
    }
}






