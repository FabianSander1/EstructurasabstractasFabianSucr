#include <iostream>
#include <vector>
#include <string>

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

