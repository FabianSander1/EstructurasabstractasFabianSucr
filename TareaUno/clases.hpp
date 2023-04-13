#include <iostream>
#include <string>
#include <vector>

//Aca hago todas mis clases con las que voy a estar trabajando.
//Estoy pensando en hacer listas para poder imprimir toda la info.

class Aulas {
public:
    int id;
    int pupitres;
    bool proyector;
    int piso;
};

class Edificio {
public:
    int num_pisos;
    int num_aulas;
    int num_buses;
};

class EdificioParqueo : public Edificio {
public:
    int num_espacios;
};

class EdificioAulas : public Edificio {
public:
    int num_sodas;
};

class Finca {
public:
    int num_edificios_aulas;
    int num_edificios_parqueo;
};

class Campus {
public:
    int num_fincas;
    std::vector<Finca> fincas;

    void imprimir() {
        std::cout << "Campus:" << std::endl;
        std::cout << "Número de fincas: " << num_fincas << std::endl;
        std::cout << "Fincas:" << std::endl;
        for (int i = 0; i < fincas.size(); i++) {
            std::cout << "  Finca " << i+1 << ":" << std::endl;
            std::cout << "    Edificios de aulas: " << fincas[i].num_edificios_aulas << std::endl;
            std::cout << "    Edificios de parqueo: " << fincas[i].num_edificios_parqueo << std::endl;
        }
    }
};





