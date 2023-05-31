from dataclasses import dataclass


@dataclass
class Empleado:
    nombre: str
    correo: str
    edad: int
    departamento: str
    salario: float

