#include <iostream>
#include <vector>
#include <string>

//Se agregó la función principal mani, donde se se agrega toda la info del pdf-
//Como se puede ver se construye cada edificio, aula y edificui de parqueos
//Se les tiene que ingresar la info por numero de aula, nuero de pupitre, booleanos para a soda, bus y para proyector y para ascensor
//Próximamente se va a separar el archivo main a archivos hpp y cpp para ser mas ordenados
//tambien se tiene que docmanetar de manera correcta


class Aula {
public:
    int id;
    int pupitres;
    bool proyector;

    Aula(int id, int pupitres, bool proyector)
        : id(id), pupitres(pupitres), proyector(proyector) {}
};

class Edificio {
public:
    std::string tipo;
    int id;
    bool ascensor;
    bool soda;
    bool bus;
    int parqueos;

    std::vector<Aula> aulas;

    Edificio(std::string tipo, int id, bool ascensor, bool soda, bool bus, int parqueos = 0)
        : tipo(tipo), id(id), ascensor(ascensor), soda(soda), bus(bus), parqueos(parqueos) {}

    void agregarAula(const Aula& aula) {
        aulas.push_back(aula);
    }
};

class Finca {
public:
    int id;
    std::vector<Edificio> edificios;

    Finca(int id) : id(id) {}

    void agregarEdificio(const Edificio& edificio) {
        edificios.push_back(edificio);
    }
};

class Campus {
public:
    std::string nombre;
    std::vector<Finca> fincas;

    Campus(std::string nombre) : nombre(nombre) {}

    void agregarFinca(const Finca& finca) {
        fincas.push_back(finca);
    }
};

void imprimirInfoCampus(const Campus& campus);




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


int main() {
    Campus campus("Sede Rodrigo Facio");

    // Finca 1
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

    campus.agregarFinca(finca1);

    // Finca 2
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

    campus.agregarFinca(finca2);

    // Finca 3
    Finca finca3(3);
    Edificio edificio8("Aulas", 9, true, true, true);
    edificio8.agregarAula(Aula(16, 20, false));
    edificio8.agregarAula(Aula(17, 10, false));
    finca3.agregarEdificio(edificio8);

    Edificio edificioParqueo2("Parqueo", 10, true, false, true, 300);
    finca3.agregarEdificio(edificioParqueo2);

    campus.agregarFinca(finca3);

    imprimirInfoCampus(campus);

    return 0;
    
}
