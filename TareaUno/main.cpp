#include <iostream>
#include <vector>
#include <string>

//Me di cuenta de que tengo que hacer primero las clases, en este caso se hicieron las clases Aula, Edificio, Finca y Campus. LE pongo un Hola mundo para ver que complie bien y que corra.
//Mas adelante le voy a hacer la funcuin que imprima la info que le voy a meter en una funion main. MAs adelante subo el archivo hecho a mano. 


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


int main() {
  printf("¡Hola Mundo!");
  return 0;
}
