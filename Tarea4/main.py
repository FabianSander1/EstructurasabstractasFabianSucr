import os
from funciones import leer_archivo, buscar_por_departamento, buscar_por_salario


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
