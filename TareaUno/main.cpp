#include <iostream>
#include <vector>
#include <string>

// Se hizo la funcion que imprime toda la informacion del campus
// Todavia falta insertar toda la info del esquematico del pdf.
// Tengo una idea de que se va a poner dentro de la funcion main. Con diferentes parametros para los pupitres, proyectores, pupitres, booleanos para el bus y para el proyector y ascensor.





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
  printf("¡Hola Mundo!");
  return 0;
}
