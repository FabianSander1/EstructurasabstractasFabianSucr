import os
from funciones import leer_archivo, buscar_por_departamento, buscar_por_salario


# Función principal del programa
def main():
    # Busca archivo CSV
    ruta_archivo = os.path.join("..", "..", "employees.csv")

    # Leer el archivo y obtener una lista de empleados
    empleados = leer_archivo(ruta_archivo)

    # Bucle principal del programa
    while True:
        print("1. Buscar por departamento")
        print("2. Buscar por rango de salario")
        print("0. Salir del programa")

        # Solicitar al usuario que elija una opción
        opcion = input("Ingrese una opcion: ")

        # Si elige 1, solicitar el nombre del departamento y buscar empleados
        if opcion == '1':
            depto = input("Ingrese el departamento a buscar: ")
            resultados = buscar_por_departamento(empleados, depto)
            for empleado in resultados:
                print(empleado)

        # Si elige 2, solicitar el rango de salario y buscar empleados
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

        # Si elige 0, terminar el programa
        elif opcion == '0':
            print("Saliendo del programa...")
            break

        # Si elige cualquier otra opción, mostrar un error y solicitar de nuevo
        else:
            print("Opción inválida, intente de nuevo")


# Si el archivo se ejecuta, iniciar el programa
if __name__ == "__main__":
    main()
