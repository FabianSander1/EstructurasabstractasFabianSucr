import csv
from dataclasses import dataclass
import os


@dataclass
class Empleado:
    nombre: str
    correo: str
    edad: int
    departamento: str
    salario: float


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


def main():
    ruta_archivo = os.path.join("..", "..", "employees.csv")
    empleados = leer_archivo(ruta_archivo)

    while True:
        print("1. Buscar por departamento")
        print("2. Buscar por rango de salario")
        print("0. Salir del programa")
        opcion = input("Ingrese una opcion: ")

        if opcion == '1':
            depto = input("Ingrese el departamento a buscar: ")
            resultados = buscar_por_departamento(empleados, depto)
            for empleado in resultados:
                print(empleado)

        elif opcion == '2':
            while True:
                try:
                    salario_min = float(input("Ingrese salario minimo: "))
                    break
                except ValueError:
                    print("Ingrese un número válido para el salario mínimo.")

            while True:
                try:
                    salario_max = float(input("Ingrese salario maximo: "))
                    break
                except ValueError:
                    print("Ingrese un número válido para el salario máximo.")

            resultados = buscar_por_salario(empleados,
                                            salario_min, salario_max)
            for empleado in resultados:
                print(empleado)

        elif opcion == '0':
            print("Saliendo del programa...")
            break

        else:
            print("Opción inválida, intente de nuevo")


if __name__ == "__main__":
    main()



