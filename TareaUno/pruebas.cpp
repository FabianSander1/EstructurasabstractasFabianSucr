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






