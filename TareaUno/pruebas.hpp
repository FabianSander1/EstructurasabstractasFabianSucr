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
#ifndef AULA_H
#define AULA_H
#ifndef EDIFICIO_H
#define EDIFICIO_H
#ifndef FINCA_H
#define FINCA_H
#ifndef CAMPUS_H
#define CAMPUS_H




/**
 * @brief Clase Aula que representa un aula en el campus.
 */
class Aula {
public:
    int id;
    int pupitres;
    bool proyector;

    /**
     * @brief Constructor de la clase Aula.
     * @param id El identificador del aula.
     * @param pupitres La cantidad de pupitres que tiene el aula.
     * @param proyector Indica si el aula tiene proyector o no.
     */
    Aula(int id, int pupitres, bool proyector)
        : id(id), pupitres(pupitres), proyector(proyector) {}
};

/**
 * @brief Clase Edificio que representa un edificio en el campus.
 */
class Edificio {
public:
    std::string tipo;
    int id;
    bool ascensor;
    bool soda;
    bool bus;
    int parqueos;

    std::vector<Aula> aulas;

    /**
     * @brief Constructor de la clase Edificio.
     * @param tipo El tipo de edificio.
     * @param id El identificador del edificio.
     * @param ascensor Indica si el edificio tiene ascensor o no.
     * @param soda Indica si el edificio tiene una soda o no.
     * @param bus Indica si el edificio está cerca de una parada de autobús o no.
     * @param parqueos La cantidad de parqueos que tiene el edificio (por defecto 0).
     */
    Edificio(std::string tipo, int id, bool ascensor, bool soda, bool bus, int parqueos = 0)
        : tipo(tipo), id(id), ascensor(ascensor), soda(soda), bus(bus), parqueos(parqueos) {}

    /**
     * @brief Agrega un aula al vector de aulas del edificio.
     * @param aula El aula se agregar.
     */
    void agregarAula(const Aula& aula) {
        aulas.push_back(aula);
    }
};

/**
 * @brief Clase Finca que representa una finca en el campus.
 */
class Finca {
public:
    int id;
    std::vector<Edificio> edificios;

    /**
     * @brief Constructor de la clase Finca.
     * @param id El identificador de la finca.
     */
    Finca(int id) : id(id) {}

    /**
     * @brief Agrega un edificio al vector de edificios de la finca.
     * @param edificio El edificio a agregar.
     */
    void agregarEdificio(const Edificio& edificio) {
        edificios.push_back(edificio);
    }
};

/**
 * @brief Clase Campus que representa un campus universitario.
 */
class Campus {
public:
    std::string nombre;
    std::vector<Finca> fincas;

    /**
     * @brief Constructor de la clase Campus.
     * @param nombre El nombre del campus.
     */
    Campus(std::string nombre) : nombre(nombre) {}

    /**
     * @brief Agrega una finca al vector de fincas del campus.
     * @param finca La finca a agregar.
     */
    void agregarFinca(const Finca& finca) {
        fincas.push_back(finca);
    }
};

#endif AULA_H
#endif EDIFICIO_H
#endif FINCA_H
#endif CAMPUS_H
