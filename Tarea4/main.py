import csv
from dataclasses import dataclass
from typing import List

@dataclass
class Empleado:
    nombre: str
    correo: str
    edad: int
    departamento: str
    salario: float

def leer_archivo(nombre_archivo: str) -> List[Empleado]:
    empleados = []
    with open(nombre_archivo, newline='') as archivo:
        reader = csv.reader(archivo)
        next(reader)  # Ignorar la primera línea (encabezado)
        for row in reader:
            empleados.append(Empleado(*row))
    return empleados

def buscar_por_departamento(empleados: List[Empleado], departamento: str) -> List[Empleado]:
    return [empleado for empleado in empleados if empleado.departamento == departamento]

def buscar_por_salario(empleados: List[Empleado], salario_minimo: float, salario_maximo: float) -> List[Empleado]:
    return [empleado for empleado in empleados if salario_minimo <= empleado.salario <= salario_maximo]

def imprimir_empleados(empleados: List[Empleado], titulo: str):
    print(titulo)
    for empleado in empleados:
        print(f"Nombre: {empleado.nombre}")
        print(f"Correo: {empleado.correo}")
        print(f"Edad: {empleado.edad}")
        print(f"Departamento: {empleado.departamento}")
        print(f"Salario: {empleado.salario}")
        print()

def main():
    #sigue la implementacion... todavia no hay flake8

    


