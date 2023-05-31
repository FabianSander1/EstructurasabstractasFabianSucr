import csv
import re
from clases import Empleado


# Función para validar el formato del correo. Retorna True si el correo
# es válido, de lo contrario retorna False.
def correo_valido(correo):
    patron = r"^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$"
    return bool(re.match(patron, correo))


# Función para leer un archivo CSV y devolver una lista de objetos
# Empleado. Si el correo del empleado no es válido, se reemplaza
# por "Correo invalido".
def leer_archivo(nombre_archivo):
    empleados = []
    with open(nombre_archivo, newline='') as archivo:
        reader = csv.reader(archivo)
        next(reader)  # Saltar encabezado
        for row in reader:
            if len(row) == 5:
                nombre, correo, edad, departamento, salario = row
                if not correo_valido(correo):
                    correo = "Correo invalido"
                empleado = Empleado(nombre, correo, int(edad),
                                    departamento, float(salario))
                empleados.append(empleado)
            else:
                print(f"Omitiendo fila con datos incompletos: {row}")
    return empleados


# Función para buscar empleados que pertenecen a un departamento específico.
def buscar_por_departamento(empleados, departamento):
    return [empleado for empleado in empleados
            if empleado.departamento == departamento]


# Función para buscar empleados cuyo salario se encuentra dentro
# de un rango dado.
def buscar_por_salario(empleados, salario_min, salario_max):
    return [empleado for empleado in empleados
            if salario_min <= empleado.salario <= salario_max]
