import csv
from clases import Empleado


def leer_archivo(nombre_archivo):
    empleados = []
    with open(nombre_archivo, newline='') as archivo:
        reader = csv.reader(archivo)
        next(reader)  # Saltar encabezado
        for row in reader:
            if len(row) == 5:
                nombre, correo, edad, departamento, salario = row
                empleado = Empleado(nombre, correo, int(edad),
                                    departamento, float(salario))
                empleados.append(empleado)
            else:
                print(f"Omitiendo fila con datos incompletos: {row}")
    return empleados


def buscar_por_departamento(empleados, departamento):
    return [empleado for empleado in empleados
            if empleado.departamento == departamento]


def buscar_por_salario(empleados, salario_min, salario_max):
    return [empleado for empleado in empleados
            if salario_min <= empleado.salario <= salario_max]
