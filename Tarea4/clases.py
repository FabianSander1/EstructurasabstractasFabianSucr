from dataclasses import dataclass


@dataclass
class Empleado:
    """Clase que representa un empleado en la empresa."""

    nombre: str
    correo: str
    edad: int
    departamento: str
    salario: float
