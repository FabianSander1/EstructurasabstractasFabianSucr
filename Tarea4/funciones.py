import csv
import re
from clases import Empleado


# Funcion que verifica si el nombre contiene dos partes
# y cada una es alfabética
def nombre_valido(nombre):
    partes = nombre.split()
    return len(partes) == 2 and all(parte.isalpha() for parte in partes)


# Funcion que verifica si la edad es un número entero
def edad_valida(edad):
    return edad.isdigit()


# Funcion que verifica si el departamento es alfabético
def departamento_valido(departamento):
    return departamento.isalpha()


# Funcion que verifica si el salario es un número entero o flotante
def salario_valido(salario):
    try:
        float(salario)
        return True
    except ValueError:
        return False


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
        next(reader)
        for row in reader:
            if len(row) == 5:
                nombre, correo, edad, departamento, salario = row
                if not nombre_valido(nombre):
                    nombre = "Nombre invalido"
                if not correo_valido(correo):
                    correo = "Correo invalido"
                if not edad_valida(edad):
                    edad = "Edad invalida"
                else:
                    edad = int(edad)
                if not departamento_valido(departamento):
                    departamento = "Departamento invalido"
                if not salario_valido(salario):
                    salario = "Salario invalido"
                else:
                    salario = float(salario)

                empleado = Empleado(nombre,
                                    correo, edad, departamento, salario)
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
